"""Reachability from each interrupt vector handler, built from the caller lists.

Reads firmware/analysis/{vectors,functions}.json (produced by disassemble.py) and writes
firmware/analysis/callgraph.json:

  entries      : per vector handler -> reachable function count + BFS depth histogram
  orphans      : functions not reachable from any handler
  shared_core  : functions reachable from every handler that has any reachable code
"""

import bisect
import json
import re
from collections import defaultdict, deque

vectors = json.load(open("firmware/analysis/vectors.json", encoding="utf-8"))
functions = json.load(open("firmware/analysis/functions.json", encoding="utf-8"))

starts = [int(item["address"], 16) for item in functions]
names = {int(item["address"], 16): item["name"] for item in functions}

listing_line = re.compile(
    r"^([0-9a-f]{8})\s+(?:[0-9a-f]{2}\s+)+\s*([a-z][\w.]*)(?:\s+#0x([0-9a-f]+))?"
)

callees = defaultdict(set)


def owner(addr):
    index = bisect.bisect_right(starts, addr) - 1
    return starts[index] if index >= 0 else None


# direct edges straight from the listing: b / bl / b.w / bl.n ...
for line in open("firmware/listing/rc102_flash.s", encoding="utf-8"):
    match = listing_line.match(line)
    if not match:
        continue
    address, mnemonic, hex_target = int(match.group(1), 16), match.group(2), match.group(3)
    if hex_target is None:
        continue
    if mnemonic.split(".")[0] not in ("b", "bl"):
        continue
    container = owner(address)
    target = owner(int(hex_target, 16) & ~1)
    if container is not None and target is not None and target != container:
        callees[container].add(target)

# supplement with the recorded bl caller lists
for item in functions:
    target = int(item["address"], 16)
    for caller in item["callers"]:
        container = owner(int(caller, 16))
        if container is not None and container != target:
            callees[container].add(target)


def reachable_from(entry, limit=5000):
    entry &= ~1
    if entry not in names:
        container = owner(entry)
        if container is None:
            return {}, []
        entry = container
    seen = {entry}
    frontier = deque([(entry, 0)])
    depths = defaultdict(int)
    while frontier and len(seen) < limit:
        node, depth = frontier.popleft()
        depths[depth] += 1
        for child in callees.get(node, ()):
            if child not in seen:
                seen.add(child)
                frontier.append((child, depth + 1))
    return seen, depths


handler_entries = []
for row in vectors["entries"][1:]:
    target = int(row["address"], 16)
    if not target & 1:
        continue
    container = owner(target & ~1)
    if container is None:
        continue
    reached, depths = reachable_from(container)
    handler_entries.append(
        {
            "index": row["index"],
            "name": row["name"],
            "address": row["address"],
            "entry": f"0x{container:08X}",
            "reachable": len(reached),
            "max_depth": max(depths) if depths else 0,
            "set": sorted(reached),
        }
    )

all_reached = set()
for entry in handler_entries:
    all_reached.update(entry["set"])
orphans = [f"0x{addr:08X}" for addr in starts if addr not in all_reached]

common = None
for entry in handler_entries:
    if entry["reachable"] < 2:
        continue
    current = set(entry["set"])
    common = current if common is None else common & current
shared_core = [f"0x{addr:08X}" for addr in sorted(common or ())][:40]

for entry in handler_entries:
    entry["sample"] = [f"0x{addr:08X} ({names[addr]})" for addr in entry["set"][:8]]
    del entry["set"]

payload = {
    "note": "reachability over direct call edges (bl targets) from each vector handler",
    "total_functions": len(starts),
    "handlers": handler_entries,
    "reachable_total": len(all_reached),
    "orphans": orphans[:60],
    "orphan_count": len(orphans),
    "shared_core": shared_core,
}
with open("firmware/analysis/callgraph.json", "w", encoding="utf-8") as fh:
    json.dump(payload, fh, indent=2)

print(
    json.dumps(
        {
            "handlers traced": len(handler_entries),
            "reachable": len(all_reached),
            "orphans": len(orphans),
            "shared core": len(shared_core),
        }
    )
)
for entry in sorted(handler_entries, key=lambda item: -item["reachable"])[:10]:
    print(
        f"[{entry['index']:3d}] {entry['name']:<14} {entry['address']} entry={entry['entry']} "
        f"reachable={entry['reachable']:4d} depth={entry['max_depth']}"
    )
