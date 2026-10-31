"""Tiny query helper for the decompiled RadiaCode-102 firmware.

Usage:
    python lookup.py 0x080349A6 [0x08010188 ...]

Prints, per address: the owning function (name + line range in the C file), its callers/callees,
any string it references, and the raw disassembly around it.
"""

import bisect
import json
import sys

IMAGE_BASE = 0x08000000

_INDEX = json.load(open("firmware/decompiled/index.json", encoding="utf-8"))
_FUNCTIONS = json.load(open("firmware/analysis/functions.json", encoding="utf-8"))
_XREFS = json.load(open("firmware/analysis/xrefs.json", encoding="utf-8"))
_TABLES = json.load(open("firmware/analysis/tables.json", encoding="utf-8"))

_C_LINES = open("firmware/decompiled/rc102_flash.c", encoding="utf-8").read().splitlines()
_LISTING = open("firmware/listing/rc102_flash.s", encoding="utf-8").read().splitlines()
_IMAGE = open("firmware/rc102_flash.bin", "rb").read()

_starts = [int(item["address"], 16) for item in _INDEX["functions"]]
_by_address = {item["address"]: item for item in _INDEX["functions"]}
_function_by_address = {int(item["address"], 16): item for item in _FUNCTIONS}
_strings = {int(item["address"], 16): item["text"] for item in json.load(open("firmware/analysis/strings.json", encoding="utf-8"))}
_table_ids = {}
for _table in _TABLES["tables"]:
    for _entry in _table["entries"]:
        _table_ids.setdefault(int(_entry["handler"], 16), []).append(_entry["id"])

_listing_starts = [
    int(line[:8], 16)
    for line in _LISTING
    if len(line) >= 8 and all(char in "0123456789abcdef" for char in line[:8])
]


def owner(address):
    index = bisect.bisect_right(_starts, address) - 1
    return _INDEX["functions"][index] if index >= 0 else None


def describe(address):
    function = owner(address)
    print(f"== 0x{address:08X} (image offset 0x{address - IMAGE_BASE:x})")
    if function is None:
        print("   no decompiled function covers this address")
    else:
        print(f"   function {function['name']}  ->  rc102_flash.c lines {function['line']}-{function['end_line']}")
        indexed = _function_by_address.get(int(function["address"], 16))
        if indexed:
            print(f"   size 0x{indexed['size']:x}, decoded instructions {indexed['instructions_decoded']}, "
                  f"callers {len(indexed['callers'])}")
            if indexed["callers"]:
                print("   callers: " + ", ".join(indexed["callers"][:8]))
        if function["address"] in _table_ids or (function and function["name"].startswith("tbl_")):
            ids = _table_ids.get(int(function["address"], 16), [])
            if ids:
                print("   dispatch ids: " + ", ".join(ids))
    nearby = [text for addr, text in _strings.items() if abs(addr - address) <= 12]
    if nearby:
        print("   string here: " + " | ".join(item.replace("\n", "\\n")[:70] for item in nearby[:2]))
    position = bisect.bisect_right(_listing_starts, address) - 1
    if position >= 0:
        for line in _LISTING[position : position + 6]:
            print("   " + line)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python lookup.py 0x080349A6 [...]")
    for argument in sys.argv[1:]:
        describe(int(argument, 16))
        print()
