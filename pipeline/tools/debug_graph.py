"""Diagnostic for the call-graph pass."""

import bisect
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import config

CFG = config.load()
functions = json.load(open(CFG["functions"], encoding="utf-8"))
starts = [int(item["address"], 16) for item in functions]


def owner(addr):
    index = bisect.bisect_right(starts, addr) - 1
    return starts[index] if index >= 0 else None


print("starts near 0x0803BA70:", [hex(a) for a in starts if 0x0803B900 <= a <= 0x0803BB00][:10])
print("owner(0x0803BA70) =", hex(owner(0x0803BA70)))

pattern = re.compile(r"^([0-9a-f]{8})\s+(?:[0-9a-f]{2}\s+)+\s*([a-z][\w.]*)(?:\s+#0x([0-9a-f]+))?")
decoded = 0
branch = 0
by_owner = {}
for line in open(CFG["listing"], encoding="utf-8"):
    match = pattern.match(line)
    if not match:
        continue
    decoded += 1
    mnemonic, target = match.group(2), match.group(3)
    if mnemonic.split(".")[0] not in ("b", "bl") or target is None:
        continue
    branch += 1
    container = owner(int(match.group(1), 16))
    by_owner.setdefault(container, 0)
    by_owner[container] += 1
print("listing instruction lines matched:", decoded, "branch lines:", branch)

reset = int(CFG["mcu"]["reset"], 16) if CFG["mcu"]["reset"] else 0x0803BA71
for probe in (reset, 0x08010188):
    print(f"edges from 0x{probe:08X}:", by_owner.get(probe))

window = [
    line.rstrip()
    for line in open(CFG["listing"], encoding="utf-8")
    if line.startswith(("%08x" % (reset & ~0xF))[:7], ("%08x" % ((reset & ~0xF) + 16))[:7])
]
print("reset handler listing:")
for line in window[:14]:
    print("   ", line)
