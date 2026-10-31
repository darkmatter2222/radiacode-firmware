"""Print candidate vector tables and their entries."""

import struct

BASE = 0x08010000
data = open("firmware/rc102_flash.bin", "rb").read()


def words(off, count):
    return [struct.unpack_from("<I", data, off + 4 * i)[0] for i in range(count)]


for candidate in (0x10000, 0x20000, 0x30000, 0x38000):
    print(f"--- offset 0x{candidate:x} (addr 0x{BASE + candidate:08x})")
    for row in range(0, 24, 4):
        vals = words(candidate + 4 * row, 4)
        print(f"  {BASE + candidate + 4 * row:08x}: " + " ".join(f"{v:08x}" for v in vals))

# score every 4-byte aligned offset by consecutive plausible pointers
best = []
for off in range(0, len(data) - 4, 4):
    w0 = struct.unpack_from("<I", data, off)[0]
    if not (0x2000_0000 <= w0 <= 0x2010_0000):
        continue
    n = 0
    i = 1
    while off + 4 * i < len(data):
        w = struct.unpack_from("<I", data, off + 4 * i)[0]
        if (w & 1) and BASE <= (w & ~1) < BASE + len(data):
            n += 1
            i += 1
        else:
            break
    best.append((n, off))
best.sort(reverse=True)
print("best tables:", [(n, f"0x{BASE + o:08x}") for n, o in best[:8]])
