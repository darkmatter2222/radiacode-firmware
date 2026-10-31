"""Extract pointer-table structures ({id, handler} pairs) from the decoded image.

The firmware dispatches most work through static tables of `{u32 id, u32 handler}` pairs (command
ids, virtual-string ids, SFR descriptors).  This step finds those runs and writes the target's
`analysis/tables.json`.
"""

import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config

CFG = config.load()
BASE = int(CFG["mcu"]["base"], 16)

data = open(CFG["flash"], "rb").read()
size = len(data)
end = BASE + size

functions = json.load(open(CFG["functions"], encoding="utf-8"))
names = {int(item["address"], 16): item["name"] for item in functions}
starts = set(names)

MIN_RUN = 4


def word(off):
    return int.from_bytes(data[off : off + 4], "little")


def entry(off):
    """Return (id, handler) when this offset holds a plausible table pair."""
    ident = word(off)
    pointer = word(off + 4)
    if ident > 0x4000:
        return None
    if not pointer & 1:
        return None
    target = pointer & ~1
    if not BASE <= target < end:
        return None
    return ident, target


tables = []
off = 0
while off + 8 <= size:
    first = entry(off)
    if first is None:
        off += 4
        continue
    run = [first]
    cursor = off + 8
    while cursor + 8 <= size:
        nxt = entry(cursor)
        if nxt is None:
            break
        # ids should stay in ascending order inside one table
        if nxt[0] < run[-1][0] and nxt[0] != 0:
            break
        run.append(nxt)
        cursor += 8
    if len(run) >= MIN_RUN:
        tables.append(
            {
                "address": f"0x{BASE + off:08X}",
                "entries": [
                    {
                        "id": f"0x{ident:X}",
                        "handler": f"0x{target:08X}",
                        "handler_name": names.get(target, "unindexed"),
                    }
                    for ident, target in run
                ],
            }
        )
    off = cursor if cursor > off else off + 4

decompiled_addresses = set(
    item["address"].upper() for item in json.load(open(CFG["index"], encoding="utf-8"))["functions"]
) if os.path.exists(CFG["index"]) else set()
decompiled = len(
    {
        e["handler"].upper()
        for table in tables
        for e in table["entries"]
        if e["handler"].upper() in decompiled_addresses
    }
)

payload = {
    "table_count": len(tables),
    "min_run": MIN_RUN,
    "decompiled_handlers": decompiled,
    "tables": tables,
}
os.makedirs(CFG["analysis_dir"], exist_ok=True)
with open(CFG["tables"], "w", encoding="utf-8") as fh:
    json.dump(payload, fh, indent=2)

print(
    json.dumps(
        {
            "tables": len(tables),
            "largest": max((len(t["entries"]) for t in tables), default=0),
            "handlers present in the C": f"{decompiled}/{len({e['handler'] for t in tables for e in t['entries']})}",
        }
    )
)
