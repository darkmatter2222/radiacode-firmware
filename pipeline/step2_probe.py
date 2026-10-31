"""Step 2 — read-only capture from a live RadiaCode-102 over BLE.

Writes `firmware/analysis/device_capture.json`: identity, decoded measurements, the virtual-string
map, the numbered register space, the two parameter areas, and (optionally) the full command sweep.
Every command issued here is a read; the only writes are the `SET_EXCHANGE` sign and the idempotent
wall-clock `SET_LOCAL_TIME`, both required before the device answers anything.

    python pipeline/step2_probe.py            # fast capture (~30 s)
    python pipeline/step2_probe.py --sweep    # + full 0x0000-0x0FFF id sweep (~14 min, cached)
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import asyncio
import datetime
import json
import struct

from protocol import (ANSWERING, CMD, SIGN, VS, decode_calib, decode_flash_area,
                      decode_image_info, decode_signature, decode_versions, serial_from_address,
                      split)

from rcble import BleTransport

OUT = "firmware/analysis/device_capture.json"
ADDRESS = "52:43:06:60:20:24"
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
    t = BleTransport(ADDRESS)
    await t.open()
    out = {"address": ADDRESS, "taken": datetime.datetime.now().isoformat(timespec="seconds")}
    try:
        out["SET_EXCHANGE"] = (await cmd(t, 0x0007, SIGN)).hex()
        now = datetime.datetime.now()
        await cmd(t, 0x0A04, struct.pack("<BBBBBBBB", now.day, now.month, now.year - 2000, 0,
                                        now.second, now.minute, now.hour, 0))

        # 1. identity
        identity = {}
        for cid in (0x0005, 0x000A, 0x000B, 0x0012, 0x0013, 0x0101, 0x0807):
            data = await cmd(t, cid)
            if data is None:
                continue
            rec = {"hex": data.hex(), "len": len(data)}
            if cid == 0x000A:
                rec["decoded"] = decode_versions(data)
            elif cid == 0x0012:
                rec["decoded"] = decode_image_info(data)
            elif cid == 0x0101:
                rec["decoded"] = decode_signature(data)
            identity[CMD[cid]] = rec
        identity["BLE_NAME_FROM_ADDRESS"] = serial_from_address(ADDRESS)
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
                areas[str(area)] = decode_flash_area(data)
        out["flash_areas"] = areas

        # 5. optional: whole command-id space
        if sweep:
            found = {}
            for cid in range(0x1000):
                if cid in (0x0007, 0x0A04):
                    continue
                data = await cmd(t, cid, tries=1)
                if data:
                    found["0x%04X" % cid] = {"len": len(data), "hex": data.hex()[:160]}
            out["command_sweep"] = found
    finally:
        await t.close()
    return out


def main():
    os.makedirs("firmware/analysis", exist_ok=True)
    data = asyncio.run(capture(sweep="--sweep" in sys.argv))
    with open(OUT, "w", encoding="utf-8") as fh:
        json.dump(data, fh, indent=2, ensure_ascii=False)
    print(json.dumps({
        "written": OUT,
        "identity": sorted(data.get("identity", {})),
        "virtual_strings": len(data.get("virtual_strings", {})),
        "nonzero_registers": len(data.get("numeric_registers_nonzero", {})),
        "areas": sorted(data.get("flash_areas", {})),
        "sweep": len(data.get("command_sweep", {})) if "command_sweep" in data else "cached",
        "expected_answering_ids": [hex(c) for c in ANSWERING],
    }, indent=2))


if __name__ == "__main__":
    main()
