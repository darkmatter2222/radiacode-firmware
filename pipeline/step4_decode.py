"""Decode the container of the active target into a flat flash binary + per-block metadata."""

import json
import os

import config
import rcfmt

CFG = config.load()
SRC = CFG["container"]
OUT_DIR = CFG["dir"]
BASE = int(CFG["mcu"]["base"], 16)

os.makedirs(OUT_DIR, exist_ok=True)
data = open(SRC, "rb").read()
print("target:", CFG["key"], "| device:", CFG["device"], "| fw", CFG["fw"], "| hw", CFG["hw"])

header = rcfmt.parse_file(data)
whole_crc = rcfmt.calculate_crc(data)
print("file:", SRC, "len", len(data), "crc", f"{whole_crc:08x}")
print("header:", json.dumps(header))

blocks = rcfmt.iter_blocks(data, header["header_size"])
compressed = header["compressed"] > 0
image = bytearray()
records = []
for index, block in enumerate(blocks):
    plain, crc1 = rcfmt.decrypt_block(block["raw"], block["size"], compressed, outer_offset=0)
    plain_len = len(plain)
    if compressed:
        plain = rcfmt.lzss_decompress(plain)
    ok = rcfmt.calculate_crc(plain) == crc1
    offset = block["addr"] - BASE
    end = offset + len(plain)
    if len(image) < end:
        image.extend(bytes(end - len(image)))
    image[offset:end] = plain
    records.append(
        {
            "index": index,
            "addr": f"0x{block['addr']:08x}",
            "offset": f"0x{offset:x}",
            "stored_size": block["size"],
            "aligned_size": block["aligned"],
            "plain_size": len(plain),
            "crc": f"{crc1:08x}",
            "crc_ok": ok,
        }
    )
    print(
        f"block {index}: addr=0x{block['addr']:08x} stored=0x{block['size']:x} "
        f"decrypted={plain_len} decompressed={len(plain)} crc={crc1:08x} ok={ok}"
    )

image_path = CFG["flash"]
with open(image_path, "wb") as fh:
    fh.write(image)
with open(CFG["blocks"], "w", encoding="utf-8") as fh:
    json.dump({"header": header, "whole_file_crc": f"{whole_crc:08x}", "blocks": records}, fh, indent=2)

print("flash image:", image_path, len(image), "bytes")
gaps = []
for record in records[1:]:
    prev = records[records.index(record) - 1]
    prev_end = int(prev["addr"], 16) + int(prev["plain_size"])
    if int(record["addr"], 16) != prev_end:
        gaps.append((prev["addr"], prev_end, record["addr"]))
print("gaps between blocks:", gaps)
