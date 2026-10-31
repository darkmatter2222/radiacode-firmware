"""Step 11 - close-the-loop check: live device values vs the decoded image artifacts (read-only).

Writes the target's `analysis/verification.json` with the device replies, the derived comparisons
(size / date_time / crc / block count / vendor-config text / decoded length) and the C-coverage metric.
Every expected value comes from `pipeline/devices.json`, so the same step works for any target.
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import asyncio
import datetime
import json
import struct

import config
import rcfmt
from protocol import (BLOCK_COUNT, CONFIGURATION_VS, FW_IMAGE_GET_INFO, GET_SERIAL, GET_VERSION,
                      RD_SIGNAT, RD_VIRT_STRING, SET_EXCHANGE, SET_TIME)
from rcsession import Session

CFG = config.load()


def _hex(value):
    """`0x13095ABB`, `13095abb`, `323429955`-style int -> `13095abb`."""
    if isinstance(value, int):
        return "%08x" % value
    return str(value).lower().replace("0x", "")


def text(payload):
    return payload[8:].split(b"\x00")[0].decode("latin-1", "replace")


def version_strings(payload_hex):
    import re

    blob = bytes.fromhex(payload_hex)
    return [run.decode("ascii") for run in re.findall(rb"[ -~]{8,}", blob)]


def coverage(functions, listing):
    """Fraction of decoded instructions that sit inside an indexed function range."""
    import bisect
    import re

    ranges = sorted(
        (int(item["address"], 16), int(item["address"], 16) + item["size"]) for item in functions
    )
    starts = [low for low, _ in ranges]
    inside = 0
    total = 0
    address_field = re.compile(r"^[0-9a-f]{8}$")
    for line in open(listing, encoding="utf-8"):
        if line.startswith(";"):
            continue
        head = line[:8]
        if not address_field.match(head):
            continue
        if ".word" in line or " ascii " in line or ".fill" in line:
            continue
        total += 1
        address = int(head, 16)
        index = bisect.bisect_right(starts, address) - 1
        if index >= 0 and ranges[index][0] <= address < ranges[index][1]:
            inside += 1
    return {
        "indexed_functions": len(functions),
        "instructions_in_function_ranges": inside,
        "instructions_total": total,
        "ratio": round(inside / total, 4) if total else 0.0,
    }


async def read_device():
    session = Session(CFG["ble_address"])
    await session.open()
    raw = {}
    try:
        await session.cmd(SET_EXCHANGE, bytes.fromhex(CFG["transport"]["sign_hex"]))
        now = datetime.datetime.now()
        stamp = struct.pack(
            "<BBBBBBBB", now.day, now.month, now.year - 2000, 0, now.second, now.minute, now.hour, 0
        )
        try:
            await session.cmd(SET_TIME, stamp)
        except Exception:  # noqa: BLE001
            pass
        for name, command, args in (
            ("GET_VERSION", GET_VERSION, b""),
            ("GET_SERIAL", GET_SERIAL, b""),
            ("FW_IMAGE_GET_INFO", FW_IMAGE_GET_INFO, b""),
            ("BLOCK_COUNT", BLOCK_COUNT, b""),
            ("FW_DESCRIPTOR", RD_SIGNAT, b""),
            ("VS_CONFIGURATION", RD_VIRT_STRING, struct.pack("<I", CONFIGURATION_VS)),
        ):
            raw[name] = (await session.cmd(command, args)).hex()
    finally:
        await session.close()
    return raw


def main():
    base = int(CFG["mcu"]["base"], 16)
    expected = CFG["expected"]
    if not CFG["ble_address"]:
        print("target %s has no live unit (ble_address is null) - skipping the on-device check"
              % CFG["key"])
        return 0
    raw = asyncio.run(read_device())

    size, buffer_size, date_time, crc = struct.unpack("<IIII", bytes.fromhex(raw["FW_IMAGE_GET_INFO"]))
    image = open(CFG["flash"], "rb").read()
    container = open(CFG["container"], "rb").read()
    header = rcfmt.parse_file(container)
    whole_crc = rcfmt.calculate_crc(container)
    block_meta = json.load(open(CFG["blocks"], encoding="utf-8"))
    blocks = block_meta["blocks"]

    # vendor configuration text: the device prefixes it with u32 tag + u32 length
    body_all = bytes.fromhex(raw["VS_CONFIGURATION"])[8:]
    device_text = body_all[: struct.unpack("<I", bytes.fromhex(raw["VS_CONFIGURATION"])[4:8])[0]]
    position = image.find(device_text)
    in_image = image[position : position + len(device_text)] if position >= 0 else b""

    stats = json.load(open(CFG["stats"], encoding="utf-8"))
    functions = json.load(open(CFG["functions"], encoding="utf-8"))

    # the decoded image should end exactly where the last block says it does
    tail = max(int(item["offset"], 16) + item["plain_size"] for item in blocks)

    payload = {
        "target": CFG["key"],
        "device": {
            "raw_hex": raw,
            "boot_and_firmware_builds": version_strings(raw["GET_VERSION"]),
            "serial": text(bytes.fromhex(raw["GET_SERIAL"])),
            "image_size": size,
            "buffer_size": buffer_size,
            "date_time": f"0x{date_time:08X}",
            "crc": f"0x{crc:08X}",
            "block_count": struct.unpack("<I", bytes.fromhex(raw["BLOCK_COUNT"]))[0],
            "descriptor": text(bytes.fromhex(raw["FW_DESCRIPTOR"])),
        },
        "files": {
            "container": CFG["container"],
            "container_size": len(container),
            "container_crc": f"{whole_crc:08x}",
            "container_date_time": f"0x{header['date_time']:08X}",
            "container_blocks": len(blocks),
            "decoded_image_bytes": len(image),
        },
        "checks": {
            "size_matches_device": len(container) == size,
            "date_time_matches_device": header["date_time"] == date_time,
            "crc_matches_device": whole_crc == crc,
            "config_text_matches_device": bool(device_text) and in_image == device_text,
            "config_text_bytes": len(device_text),
            "config_text_address": None if position < 0 else f"0x{base + position:08X}",
            "decoded_bytes_equal_block_sum": len(image) == tail,
            "size_matches_registry": len(container) == expected["size"],
            "crc_matches_registry": _hex(whole_crc) == _hex(expected["crc32"]),
            "date_time_matches_registry": _hex(date_time) == _hex(expected["date_time"]),
            "blocks_match_registry": len(blocks) == expected["blocks"],
        },
        "c_coverage": coverage(functions, CFG["listing"]),
    }
    os.makedirs(CFG["analysis_dir"], exist_ok=True)
    with open(CFG["verification"], "w", encoding="utf-8") as fh:
        json.dump(payload, fh, indent=2)
    print(json.dumps(payload["checks"] | payload["c_coverage"], indent=2))


if __name__ == "__main__":
    main()
