"""Explicit live capture (--live). Session setup and clock writes change device state.

Unknown command sweeps require --unsafe-command-sweep. They are not read-only.
Raw area reply bytes are preserved beside decoded interpretations.
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import asyncio
import datetime
import json
import struct

import config
from protocol import (ANSWERING, CMD, SIGN, VS, decode_calib, decode_flash_area,
                      decode_image_info, decode_signature, decode_versions, serial_from_address,
                      split)

from rcble import BleTransport

CFG = config.load()
VS_IDS = [0x002, 0x003, 0x008, 0x00D, 0x00F, 0x0F0, 0x100, 0x101, 0x200, 0x202, 0x203,
          0x205, 0x206, 0x207, 0x208, 0x220]


async def cmd(t, cid, args=b"", tries=2):
    for attempt in range(tries):
        try:
            return await t.execute(cid, args)
        except Exception:  # noqa: BLE001
            await asyncio.sleep(0.05)
    return None


async def capture(sweep=False):
    address = CFG["ble_address"]
    t = BleTransport(address)
    await t.open()
    out = {"target": CFG["key"], "address": address,
           "taken": datetime.datetime.now().isoformat(timespec="seconds")}
    try:
        out["SET_EXCHANGE"] = (await cmd(t, 0x0007, SIGN)).hex()
        now = datetime.datetime.now()
        await cmd(t, 0x0A04, struct.pack("<BBBBBBBB", now.day, now.month, now.year - 2000, 0,
                                        now.second, now.minute, now.hour, 0))

        # 1. identity
        identity = {}
        for cid in (0x0005, 0x000A, 0x000B, 0x0012, 0x0101, 0x0807):
            data = await cmd(t, cid)
            if data is None:
                continue
            rec = {"hex": data.hex(), "len": len(data)}
            if cid == 0x000A:
                rec["decoded"] = decode_versions(data)
            elif cid == 0x0012:
                rec["decoded"] = decode_image_info(data)
            elif cid == 0x0013:
                rec["decoded"] = {"frames": struct.unpack("<I", data)[0]}
            elif cid == 0x0101:
                rec["decoded"] = decode_signature(data)
            identity[CMD[cid]] = rec
        identity["BLE_NAME_FROM_ADDRESS"] = serial_from_address(address)
        out["identity"] = identity

        # 2. virtual strings (the only bulk data channel): envelope + decoded body
        strings = {}
        for vs in VS_IDS:
            data = await cmd(t, 0x0826, struct.pack("<I", vs))
            if not data or len(data) < 8:
                continue
            version, size, body = split(data)
            rec = {"name": VS.get(vs, "?"), "version": version, "size": size,
                   "body_bytes": len(body), "hex": body.hex()}
            if vs in (0x200, 0x202, 0x205):
                try:
                    rec["calib"] = decode_calib(body[-12:] if vs == 0x200 else body)
                except Exception:  # noqa: BLE001
                    pass
            if vs in (0x002, 0x008, 0x00F):
                rec["text"] = body.split(b"\x00")[0].decode("cp1251", "replace")
            strings["0x%03X" % vs] = rec
        out["virtual_strings"] = strings

        # 3. numbered register space (index space of the 91-entry table @ 0x08035A64)
        regs = {}
        for i in range(0x5B):
            data = await cmd(t, 0x0824, struct.pack("<I", i), tries=1)
            if data and data.hex() != "00000000":
                regs["0x%02X" % i] = data.hex()
        out["numeric_registers_nonzero"] = regs

        # 4. parameter areas (XOR-obfuscated, seeded)
        areas = {}
        for area in range(0, 4):
            data = await cmd(t, 0x081C, struct.pack("<I", area))
            if data:
                areas[str(area)] = dict(decode_flash_area(data), raw_payload_hex=data.hex())
        out["flash_areas"] = areas

        # 5. optional: whole command-id space, twice - no argument and with a u32 argument
        if sweep:
            for name, args in (("noarg", b""), ("witharg", struct.pack("<I", 0))):
                found = {}
                for cid in range(0x1000):
                    if cid in (0x0007, 0x0A04):
                        continue
                    data = await cmd(t, cid, args, tries=1)
                    if data:
                        found["0x%04X" % cid] = {"len": len(data), "hex": data.hex()[:160]}
                out["command_sweep_" + name] = found
            with open(CFG["sweep_noarg"], "w", encoding="utf-8", newline="
") as fh:
                json.dump(out["command_sweep_noarg"], fh, indent=2)
            with open(CFG["sweep_witharg"], "w", encoding="utf-8", newline="
") as fh:
                json.dump(out["command_sweep_witharg"], fh, indent=2)
    finally:
        await t.close()
    return out


def main():
    if "--live" not in sys.argv:
        print("SKIP: live device access requires --live")
        return 2
    if "--sweep" in sys.argv and "--unsafe-command-sweep" not in sys.argv:
        raise ValueError("Unknown command sweeps may mutate device state; use --unsafe-command-sweep explicitly")
    if not CFG["ble_address"]:
        print("target %s has no live unit (ble_address is null) - nothing to capture" % CFG["key"])
        return 2
    os.makedirs(CFG["analysis_dir"], exist_ok=True)
    data = asyncio.run(capture(sweep="--unsafe-command-sweep" in sys.argv))
    with open(CFG["capture"], "w", encoding="utf-8", newline="
") as fh:
        json.dump(data, fh, indent=2, ensure_ascii=False)
    print(json.dumps({
        "written": CFG["capture"],
        "identity": sorted(data.get("identity", {})),
        "virtual_strings": len(data.get("virtual_strings", {})),
        "nonzero_registers": len(data.get("numeric_registers_nonzero", {})),
        "areas": sorted(data.get("flash_areas", {})),
        "sweep": (len(data["command_sweep_noarg"]) if "command_sweep_noarg" in data else "cached"),
        "expected_answering_ids": [hex(c) for c in ANSWERING],
    }, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
