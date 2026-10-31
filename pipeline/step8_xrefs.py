"""Cross-reference literal pools: which function loads which string / calls which function.

Reads firmware/rc102_flash.bin plus the JSON indexes produced by disassemble.py and writes
firmware/analysis/xrefs.json:

  string_refs   : per string -> referencing addresses + owning functions
  function_info : per function -> strings and callees reachable through its literal pool
"""

import bisect
import json
import os

BASE = 0x08000000

data = open("firmware/rc102_flash.bin", "rb").read()
size = len(data)
end = BASE + size

strings = json.load(open("firmware/analysis/strings.json", encoding="utf-8"))
functions = json.load(open("firmware/analysis/functions.json", encoding="utf-8"))

starts = [int(item["address"], 16) for item in functions]
name_by_addr = {int(item["address"], 16): item["name"] for item in functions}

string_ranges = [(int(item["address"], 16), int(item["address"], 16) + item["length"], item["text"]) for item in strings]
string_ranges.sort()
range_starts = [item[0] for item in string_ranges]


def owner(addr):
    """Function that contains this address (nearest preceding known start)."""
    index = bisect.bisect_right(starts, addr) - 1
    return name_by_addr[starts[index]] if index >= 0 else None


def find_string(value):
    position = bisect.bisect_right(range_starts, value) - 1
    if position >= 0 and string_ranges[position][0] <= value <= string_ranges[position][1]:
        return string_ranges[position]
    return None


string_refs = {}
function_strings = {}

for offset in range(0, size - 4, 4):
    value = int.from_bytes(data[offset : offset + 4], "little")
    hit = find_string(value)
    if hit is None:
        continue
    string_address, _, text = hit
    referrer = BASE + offset
    container = owner(referrer)
    string_refs.setdefault(
        f"0x{string_address:08X}", {"text": text, "referenced_by": []}
    )["referenced_by"].append(
        {"at": f"0x{referrer:08X}", "in": container}
    )
    if container:
        function_strings.setdefault(container, [])
        if text not in function_strings[container]:
            function_strings[container].append(text)

output = {
    "generated_from": "firmware/rc102_flash.bin + firmware/analysis/{strings,functions}.json",
    "literal_pool_string_count": len(string_refs),
    "functions_with_strings": len(function_strings),
    "string_refs": string_refs,
    "function_strings": dict(
        sorted(function_strings.items(), key=lambda kv: -len(kv[1]))
    ),
}
os.makedirs("firmware/analysis", exist_ok=True)
with open("firmware/analysis/xrefs.json", "w", encoding="utf-8") as fh:
    json.dump(output, fh, indent=2)

print(
    json.dumps(
        {
            "strings reached by a literal": output["literal_pool_string_count"],
            "functions with string refs": output["functions_with_strings"],
        }
    )
)
