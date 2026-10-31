"""Quick structural inspection of the decoded flash image."""

import struct

BASE = 0x08010000
data = open("firmware/rc102_flash.bin", "rb").read()
print("size", len(data), hex(len(data)), "end", hex(BASE + len(data)))
print("first 64 bytes:", data[:64].hex())

# candidate vector tables: SP value in SRAM (0x20000000..0x2003FFFF) then odd code pointers
cands = []
for off in range(0, len(data) - 40, 4):
    sp = struct.unpack_from("<I", data, off)[0]
    if not (0x2000_0000 <= sp <= 0x2010_0000):
        continue
    ok = 0
    for i in range(1, 10):
        if off + 4 * i > len(data):
            break
        word = struct.unpack_from("<I", data, off + 4 * i)[0]
        if word & 1 and BASE <= word < BASE + len(data):
            ok += 1
    if ok >= 7:
        cands.append((off, sp, ok))
print("vector-table candidates:", [(hex(o + BASE), hex(s), n) for o, s, n in cands[:12]])

# entropy-ish view: count of zero runs
zeros = data.count(b"\x00\x00\x00\x00")
print("4-byte zero words:", zeros)
