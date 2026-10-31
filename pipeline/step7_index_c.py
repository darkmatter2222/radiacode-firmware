"""Index the Ghidra C output so the 1.4 MB file can be navigated by address.

Writes firmware/decompiled/index.json: one entry per decompiled function with the line range
inside firmware/decompiled/rc102_flash.c, plus a flat address -> line map.
"""

import json
import re

C_FILE = "firmware/decompiled/rc102_flash.c"
OUT = "firmware/decompiled/index.json"

banner = re.compile(r"^/\* ===== (\S+) @ (\w+) ===== \*/$")

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
with open(OUT, "w", encoding="utf-8") as fh:
    json.dump(payload, fh, indent=2)

print(json.dumps({"functions": len(entries), "lines": len(lines)}))
