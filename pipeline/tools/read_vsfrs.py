"""Read the VSFR map from a live unit with the 16/32-bit address form, plus batch shapes.

    python pipeline/tools/read_vsfrs.py

Writes the target's `analysis/vsfr_readout.json`. Every id used here is a read (`0x0824`, `0x082A`); the
session is opened first with `SET_EXCHANGE`, and the wall clock is refreshed with the idempotent
`SET_LOCAL_TIME`, exactly as `step2_probe.py` does.
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import asyncio
import datetime
import json
import struct

import config  # noqa: E402
from protocol import CMD, VS, decode_calib, split  # noqa: E402

from rcble import BleTransport  # noqa: E402

CFG = config.load()
ADDRESS = CFG["ble_address"]
OUT = CFG["vsfr"]

# name -> VSFR address, from the in-image map (§8 of firmware.md)
VSFRS = [
    ("VSFR_DEVICE_CTRL", 0x00000500), ("VSFR_DEVICE_LANG", 0x00000502),
    ("VSFR_DEVICE_ON", 0x00000503), ("VSFR_DEVICE_TIME", 0x00000504),
    ("VSFR_BLE_TX_PWR", 0x00000700), ("VSFR_DISP_CTRL", 0x00000510),
    ("VSFR_DISP_BRT", 0x00000511), ("VSFR_DISP_CONTR", 0x00000512),
    ("VSFR_DISP_OFF_TIME", 0x00000513), ("VSFR_DISP_ON", 0x00000514),
    ("VSFR_DISP_DIR", 0x00000515), ("VSFR_DISP_BACKLT_ON", 0x00000516),
    ("VSFR_SOUND_CTRL", 0x00000520), ("VSFR_SOUND_VOL", 0x00000521),
    ("VSFR_SOUND_ON", 0x00000522), ("VSFR_VIBRO_CTRL", 0x00000530),
    ("VSFR_VIBRO_ON", 0x00000531), ("VSFR_ALARM_MODE", 0x000005E0),
    ("VSFR_MS_RUN", 0x00000603), ("VSFR_PLAY_SIGNAL", 0x000005E1),
    ("VSFR_CHARGER_STATE", 0x0000C200),
    ("RC_VSFR_DR_LEV1_uR_h", 0x00008000), ("RC_VSFR_DR_LEV2_uR_h", 0x00008001),
    ("RC_VSFR_DS_LEV1_100uR", 0x00008002), ("RC_VSFR_DS_LEV2_100uR", 0x00008003),
    ("RC_VSFR_DS_UNITS", 0x00008004), ("RC_VSFR_CPS_FILTER", 0x00008005),
    ("RC_VSFR_DOSE_RESET", 0x00008007), ("RC_VSFR_CR_LEV1_cp10s", 0x00008008),
    ("RC_VSFR_CR_LEV2_cp10s", 0x00008009), ("RC_VSFR_USE_nSv_h", 0x0000800C),
    ("RC_VSFR_CR_UNITS", 0x00008013), ("RC_VSFR_DS_LEV1_uR", 0x00008014),
    ("RC_VSFR_DS_LEV2_uR", 0x00008015), ("RC_VSFR_TEMP_UNITS", 0x00008016),
    ("RC_VSFR_CHN_TO_keV_A0", 0x00008010), ("RC_VSFR_CHN_TO_keV_A1", 0x00008011),
    ("RC_VSFR_CHN_TO_keV_A2", 0x00008012),
    ("RC_VSFR_CPS", 0x00008020), ("RC_VSFR_DR_uR_h", 0x00008021),
    ("RC_VSFR_DS_uR", 0x00008022), ("RC_VSFR_TEMP_degC", 0x00008024),
    ("RC_VSFR_ACC_X", 0x00008025), ("RC_VSFR_ACC_Y", 0x00008026),
    ("RC_VSFR_ACC_Z", 0x00008027), ("RC_VSFR_OPT", 0x00008028),
    ("RC_VSFR_RAW_TEMP_degC", 0x00008033), ("RC_VSFR_TEMP_UP_degC", 0x00008034),
    ("RC_VSFR_TEMP_DN_degC", 0x00008035),
    ("RC_VSFR_VBIAS_mV", 0x0000C000), ("RC_VSFR_COMP_LEV", 0x0000C001),
    ("RC_VSFR_CALIB_MODE", 0x0000C002), ("RC_VSFR_DPOT_RDAC", 0x0000C004),
    ("RC_VSFR_DPOT_RDAC_EEPROM", 0x0000C005), ("RC_VSFR_DPOT_TOLER", 0x0000C006),
    ("VSFR_SYS_MCU_ID0", 0xFFFF0000), ("VSFR_SYS_MCU_ID1", 0xFFFF0001),
    ("VSFR_SYS_MCU_ID2", 0xFFFF0002), ("VSFR_SYS_DEVICE_ID", 0xFFFF0005),
    ("VSFR_SYS_SIGNATURE", 0xFFFF0006), ("VSFR_SYS_RX_SIZE", 0xFFFF0007),
    ("VSFR_SYS_TX_SIZE", 0xFFFF0008), ("VSFR_SYS_BOOT_VERSION", 0xFFFF0009),
    ("VSFR_SYS_TARGET_VERSION", 0xFFFF000A), ("VSFR_SYS_STATUS", 0xFFFF000B),
    ("VSFR_SYS_MCU_VREF", 0xFFFF000C), ("VSFR_SYS_MCU_TEMP", 0xFFFF000D),
]

BATCH_SHAPES = {
    "u32 addr": lambda a: struct.pack("<I", a),
    "u32 addr,u32 count": lambda a: struct.pack("<II", a, 4),
    "u32 count,u32 addr": lambda a: struct.pack("<II", 4, a),
}


async def main():
    if not ADDRESS:
        print("target %s has no live unit (ble_address is null) - nothing to read" % CFG["key"])
        return
    t = BleTransport(ADDRESS)
    await t.open()
    out = {"address": ADDRESS, "taken": datetime.datetime.now().isoformat(timespec="seconds")}
    try:
        await t.execute(0x0007, b"\x01\xff\x12\xff")
        now = datetime.datetime.now()
        try:
            await t.execute(0x0A04, struct.pack("<BBBBBBBB", now.day, now.month, now.year - 2000, 0,
                                                now.second, now.minute, now.hour, 0))
        except Exception:  # noqa: BLE001
            pass
        single, batch = {}, {}
        for name, addr in VSFRS:
            for cmd in (0x0824, 0x082A):
                try:
                    data = await t.execute(cmd, struct.pack("<I", addr))
                except Exception:  # noqa: BLE001
                    continue
                if data and data.hex() != "00000000":
                    rec = {"hex": data.hex()}
                    if len(data) == 4:
                        rec["u32"] = struct.unpack("<I", data)[0]
                        rec["f32"] = struct.unpack("<f", data)[0]
                    single.setdefault(name, {})[CMD[cmd]] = rec
            # the numbered index form of the same id, for comparison
            try:
                data = await t.execute(0x0824, struct.pack("<I", addr & 0xFF))
                if data and data.hex() != "00000000":
                    single.setdefault(name, {})["index-form"] = data.hex()
            except Exception:  # noqa: BLE001
                pass
        for probe in (0x8020, 0x8024, 0x0500, 0xC200):
            for label, make in BATCH_SHAPES.items():
                try:
                    data = await t.execute(0x082A, make(probe))
                except Exception:  # noqa: BLE001
                    continue
                if data:
                    batch["0x%04X %s" % (probe, label)] = data.hex()
        out["single_nonzero"] = single
        out["batch_shapes"] = batch

        # the four data-bearing virtual strings, twice, to see what changes between frames
        snaps = {}
        for label in ("t0", "t1"):
            for vs in (0x0F0, 0x100, 0x200, 0x220, 0x202):
                try:
                    data = await t.execute(0x0826, struct.pack("<I", vs))
                except Exception:  # noqa: BLE001
                    continue
                if len(data) > 8:
                    _, size, body = split(data)
                    snaps.setdefault("0x%03X" % vs, []).append([size, body.hex()])
                if vs == 0x202 and len(data) > 20:
                    snaps.setdefault("0x%03X" % vs, [])
                    snaps["0x%03X" % vs + ":calib"] = decode_calib(data[8:20])
            await asyncio.sleep(1.0)
        out["string_pairs"] = snaps
    finally:
        await t.close()
    os.makedirs(CFG["analysis_dir"], exist_ok=True)
    with open(OUT, "w", encoding="utf-8") as fh:
        json.dump(out, fh, indent=2, ensure_ascii=False)
    print("wrote", OUT, "| nonzero VSFRs:", len(out["single_nonzero"]),
          "| batch shapes:", len(out["batch_shapes"]))


if __name__ == "__main__":
    asyncio.run(main())
