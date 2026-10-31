"""Inspect per-block plaintexts of the decoded image."""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import json
import struct

import rcfmt

BASE = 0x08010000
meta = json.load(open("firmware/rc102_blocks.json", encoding="utf-8"))
data = open("firmware/rc102_flash.bin", "rb").read()

for record in meta["blocks"]:
    offset = int(record["offset"], 16)
    size = record["plain_size"]
    chunk = data[offset : offset + size]
    first_nonzero = next((i for i, b in enumerate(chunk) if b), None)
    print(
        f"block {record['index']} addr={record['addr']} size={size:#x} "
        f"first_nonzero_at={None if first_nonzero is None else hex(offset + first_nonzero)}"
    )
    if first_nonzero is not None:
        start = offset + first_nonzero
        print("   ", data[start : start + 48].hex(" ") if hasattr(bytes, "hex") else "")

# global: first non-zero byte in whole image
idx = next((i for i, b in enumerate(data) if b), None)
print("first non-zero byte in image at offset", hex(idx), "->", hex(BASE + idx))
print(data[idx : idx + 64].hex())

# vector table hunt (4-byte aligned words)
found = []
for off in range(0, len(data) - 40, 4):
    sp = struct.unpack_from("<I", data, off)[0]
    if not (0x2000_0000 <= sp <= 0x2020_0000):
        continue
    good = sum(
        1
        for i in range(1, 10)
        if off + 4 * i <= len(data)
        and (lambda w: (w & 1) and BASE <= w < BASE + len(data))(struct.unpack_from("<I", data, off + 4 * i)[0])
    )
    if good >= 6:
        found.append((hex(BASE + off), hex(sp), good))
print("vector candidates:", found[:15])
