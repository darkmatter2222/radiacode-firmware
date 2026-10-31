"""Locate the BLE command dispatch table by matching the known command-id sequence."""

import json

BASE = 0x08000000
data = open("firmware/rc102_flash.bin", "rb").read()

known = [0x0005, 0x000A, 0x000B, 0x0012, 0x0013]

words = [int.from_bytes(data[i : i + 4], "little") for i in range(0, len(data) - 4, 4)]

for stride in (1, 2, 3, 4, 6):
    for index in range(len(words) - stride * len(known)):
        ok = all(
            words[index + stride * position] == known[position]
            for position in range(len(known))
        )
        if ok:
            address = BASE + 4 * index
            row = words[index : index + stride * 12]
            print(f"stride {stride} -> table at 0x{address:08X}")
            print("   ", [f"0x{value:08X}" for value in row])
            break

# also dump the two promising tables in raw form
for probe in (0x08036C10, 0x08038CD4):
    off = (probe - BASE) // 4
    print(f"raw at {probe:#010x}:")
    for row in range(0, 6):
        chunk = words[off + row * 6 : off + row * 6 + 6]
        print("   ", " ".join(f"{value:08x}" for value in chunk))
