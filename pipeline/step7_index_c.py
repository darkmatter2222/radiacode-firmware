"""Index the Ghidra C output so the multi-megabyte file can be navigated by address.

Writes the target's `index.json`: one entry per decompiled function with the line range inside
the target's `decompiled.c`, plus a flat address -> line map.
"""

import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config

CFG = config.load()
C_FILE = CFG["c"]
OUT = CFG["index"]

banner = re.compile(r"^/\* ===== (\S+) @ (\w+) ===== \*/$")

if not os.path.exists(C_FILE):
    print("no %s yet - run step 6 first" % C_FILE)
    raise SystemExit(0)

lines = open(C_FILE, encoding="utf-8").read().splitlines()

entries = []
for position, line in enumerate(lines, start=1):
    match = banner.match(line)
    if match:
        entries.append({"name": match.group(1), "address": f"0x{int(match.group(2), 16):08X}", "line": position})

for index, entry in enumerate(entries):
    entry["end_line"] = entries[index + 1]["line"] - 1 if index + 1 < len(entries) else len(lines)

payload = {
    "source": C_FILE,
    "function_count": len(entries),
    "functions": entries,
    "line_by_address": {entry["address"]: [entry["line"], entry["end_line"]] for entry in entries},
}
with open(OUT, "w", encoding="utf-8", newline="
") as fh:
    json.dump(payload, fh, indent=2)

print(json.dumps({"functions": len(entries), "lines": len(lines)}))
