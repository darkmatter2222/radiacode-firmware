"""Tiny query helper for the decompiled firmware of the active target.

Usage:
    python pipeline/tools/lookup.py 0x080349A6 [0x08010188 ...]
    RC_TARGET=rc-110/fw4.14 python pipeline/tools/lookup.py 0x08010188

Prints, per address: the owning function (name + line range in the C file), its callers/callees,
any string it references, and the raw disassembly around it.
"""

import bisect
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import config

CFG = config.load()
IMAGE_BASE = int(CFG["mcu"]["base"], 16)

_INDEX = json.load(open(CFG["index"], encoding="utf-8"))
_FUNCTIONS = json.load(open(CFG["functions"], encoding="utf-8"))
_XREFS = json.load(open(CFG["xrefs"], encoding="utf-8"))
_TABLES = json.load(open(CFG["tables"], encoding="utf-8"))

_C_LINES = open(CFG["c"], encoding="utf-8").read().splitlines()
_LISTING = open(CFG["listing"], encoding="utf-8").read().splitlines()
_IMAGE = open(CFG["flash"], "rb").read()

_starts = [int(item["address"], 16) for item in _INDEX["functions"]]
_by_address = {item["address"]: item for item in _INDEX["functions"]}
_function_by_address = {int(item["address"], 16): item for item in _FUNCTIONS}
_strings = {int(item["address"], 16): item["text"] for item in json.load(open(CFG["strings"], encoding="utf-8"))}
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
        print(f"   function {function['name']}  ->  decompiled.c lines {function['line']}-{function['end_line']}")
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
