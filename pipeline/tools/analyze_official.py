"""Cross-check the official firmware file against what the device reports, then decode it."""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import json

import rcfmt

# values reported by the device (commands 0x0012 / 0x0013 / 0x0101)
DEV_SIZE = 130148
DEV_FIELD2 = 4096
DEV_DATE_TIME = 0x5AE7428A
DEV_CRC = 0x13095ABB
DEV_BLOCKS = 19

for name in ("official/rc-102z.bin",):
    data = open(name, "rb").read()
    print(f"== {name}: {len(data)} bytes")
    header = rcfmt.parse_file(data)
    print("   header:", json.dumps(header))
    print("   size matches device:", len(data) == DEV_SIZE)
    print("   date_time matches device:", header["date_time"] == DEV_DATE_TIME)
    whole_crc = rcfmt.calculate_crc(data)
    data_crc = rcfmt.calculate_crc(data[header["header_size"] :])
    print(f"   crc(whole file)={whole_crc:08x} matches device: {whole_crc == DEV_CRC}")
    print(f"   crc(after header)={data_crc:08x} matches device: {data_crc == DEV_CRC}")
    blocks = rcfmt.iter_blocks(data, header["header_size"])
    print("   block count:", len(blocks), "matches device:", len(blocks) == DEV_BLOCKS)
    for index, b in enumerate(blocks):
        print(
            f"   block {index:2d} header_size={b['header_size']} addr={b['addr']:#010x} "
            f"size={b['size']:#07x} aligned={b['aligned']:#07x}"
        )
