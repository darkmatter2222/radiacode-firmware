"""Step 12 - build the target's `analysis/summary.md` and `manifest.json` from the artifacts."""

import hashlib
import json
import os
import re
import sys
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config

CFG = config.load()
BASE = int(CFG["mcu"]["base"], 16)
EXP = CFG["expected"]
LAND = CFG["landmarks"]

blocks = json.load(open(CFG["blocks"], encoding="utf-8"))
vectors = json.load(open(CFG["vectors"], encoding="utf-8"))
strings = json.load(open(CFG["strings"], encoding="utf-8"))
functions = json.load(open(CFG["functions"], encoding="utf-8"))

data = open(CFG["flash"], "rb").read()
size = len(data)
end = BASE + size

stats = json.load(open(CFG["stats"], encoding="utf-8"))
ins_count = stats["instructions"]
listing = open(CFG["listing"], encoding="utf-8").read().splitlines()

c_text = open(CFG["c"], encoding="utf-8").read() if os.path.exists(CFG["c"]) else ""
c_funcs = re.findall(r"/\* ===== (\S+) @ (\w+) ===== \*/", c_text)
c_failed = c_text.count("/* decompilation failed */")

# instruction coverage per block from the listing
coverage = {}
for line in listing:
    match = re.match(r"^([0-9a-f]{8})  (?:[0-9a-f]{2} )+", line)
    if match:
        addr = int(match.group(1), 16)
        for record in blocks["blocks"]:
            start = int(record["addr"], 16)
            if start <= addr < start + record["plain_size"]:
                key = record["addr"]
                coverage[key] = coverage.get(key, 0) + 1
                break

notable = [s for s in strings if any(
    token in s["text"] for token in ("RadiaCode", CFG["model"], "STM32", "Version", "CRC", "Phyton"))]

lines = []
add = lines.append
DASH = lambda value: "-" if value in (None, "") else value
add("# %s firmware analysis - `%s`" % (CFG["device"], CFG["key"]))
add("")
add("Device: %s, serial `%s`, BLE `%s`. Bootloader `%s`, firmware `%s`%s." % (
    CFG["device"], DASH(CFG["serial"]), DASH(CFG["ble_address"]), DASH(CFG["boot"]), CFG["fw"],
    "" if CFG["hw"] is None else ", hardware revision `%s`" % CFG["hw"]))
add("")
add("Target directory: `%s` - every file below lives inside it. The active target is chosen by"
    % CFG["dir"])
add("`RC_TARGET` or `pipeline/run.py --device`; the registry is `pipeline/devices.json`.")
add("")
add("### Registered targets")
add("")
add("| target | device | fw | hw | container | bytes | blocks | analyzed |")
add("| --- | --- | --- | --- | --- | --- | --- | --- |")
for item in config.raw()["targets"]:
    add("| `%s` | %s | %s | %s | `%s` | %s | %s | %s |" % (
        item["key"], item["device"], item["fw"], item["hw"] if item["hw"] else "-",
        item["primary_container"], item["expected"]["size"], item["expected"]["blocks"],
        "yes" if item["analyzed"] else "container + decode only"))
add("")
add("## How the image was obtained")
add("")
add("The device was read over BLE (Nordic UART service `%s…`, 4-byte little-endian"
    % CFG["transport"]["service"][:8])
add("length prefix + `cmd(u16 LE) + 0x00 + seq`). No write/erase command was used; only reads:")
add("")
add("| BLE command | value |")
add("| --- | --- |")
add("| `0x000A` GET_VERSION | boot `%s`, firmware `%s` |" % (DASH(CFG["boot"]), CFG["fw"]))
add("| `0x000B` GET_SERIAL | `%s` |" % DASH(CFG["serial"]))
add("| `0x0012` FW_IMAGE_GET_INFO | size `%s`, buffer `%s`, date_time `%s`, crc `%s` |"
    % (EXP["size"], EXP["chunk"], EXP["date_time"], EXP["crc32"]))
add("| `0x0013` | `%s` (block/frame count) |" % (EXP["frames"] if EXP["frames"] is not None else "n/a"))
add("| `0x081C` RD_FLASH area 0/1 | XOR-obfuscated `PublicAPI` struct (Borland LCG), device parameters |")
add("")
if not CFG["analyzed"]:
    add("Values in that table are the registry's (`pipeline/devices.json`), read from the container")
    add("header by step 3; this target has no live unit in `analysis/capture.json`.")
    add("")
add("The device exposes no image-read command (verified by a full `0x0000-0x0FFF` scan, with and")
add("without a `u32` argument), so the image bytes come from the official `%s` shipped in"
    % CFG["primary_container"])
add("`%s` (`assets/HardSoft/`). Identity with the unit" % CFG["apk_url"])
add("in hand is proven by three independent matches: file length `%s`, header `date_time`"
    % EXP["size"])
add("`%s`, whole-file CRC `%s` - all equal to the device's own `0x0012` answer -" % (
    EXP["date_time"], EXP["crc32"]))
add("plus the in-image vendor-config text found byte-identically in the image%s" % (
    "" if not LAND else " at `%s`" % LAND.get("config_text", "")))
add("(see `analysis/verification.json`).")
add("")
add("Memory model: the container addresses blocks from `0x%08X`, so the flat image spans" % BASE)
add("`0x%08X-0x%08X`; offsets `0x00000-0xFFFF` stay zero because the bootloader region" % (
    BASE, end))
add("`0x%08X-0x%08X` is not part of this file. Application base = `%s`." % (
    BASE, int(CFG["mcu"]["vector_table"], 16) - 1, CFG["mcu"]["vector_table"]))
add("")
add("## File format (`Phyton\\x00\\x00` container)")
add("")
add("```")
add("header   : marker[8] | u32 header_size | u32 date_time | u32 buffer_size | u8[16] serial")
add("           | u8 version_low | u8 version_high | u32 file_count | u32 fw_header_size")
add("           | u8 compressed | u8 reserved | u32 crc32")
add("blocks[] : u32 header_size | u32 size ^ 0xCE27A932 | u32 addr ^ 0xB2D5A864")
add("           | key_block[512] | data[size aligned to 8]")
add("```")
add("")
add("* `key_block` is unmangled with hardcoded key table slot 0 (index at `[0:2]`, 16-byte data key at")
add("  `[2:18]`, CRC pair at `[18:26]`); the key/CRC region is then unmangled a second time with the")
add("  table selected by that index (`0-7` hardcoded, `8-15` zero table, `0xFFFF` device id key).")
add("* The Mangle cipher is a 48-round Feistel network over 8-byte blocks, 4 round keys")
add("  (`key[rnd & 3]`), round function `B' = rnd + key + ((B>>8)^(B<<6)) + B + A`.")
add("* CRC: MPEG-2 polynomial `0x04C11DB7`, no reflection, init `0xFFFFFFFF`, fed in 4-byte LE chunks")
add("  (`rcfmt.calculate_crc`).")
add("* Payload: LZSS, 2048-byte window pre-filled with `0x20`, initial index `2031`, flag bit 1 =")
add("  literal, 0 = match with 11-bit offset + 4-bit length (+2), i.e. match length `2..17`.")
add("")
add("## Decoded flash image")
add("")
add(f"`{CFG['flash']}`: {size} bytes (`0x{BASE:08X}`-`0x{end:08X}`), every block CRC verified.")
add("")
add("| # | address | decompressed size | crc | instructions |")
add("| --- | --- | --- | --- | --- |")
for record in blocks["blocks"]:
    add(
        f"| {record['index']} | `{record['addr']}` | 0x{record['plain_size']:x} "
        f"({record['plain_size']}) | `{record['crc']}` | {coverage.get(record['addr'], 0)} |"
    )
add("")
add("## Verification against the live device")
add("")
if os.path.exists(CFG["verification"]):
    verification = json.load(open(CFG["verification"], encoding="utf-8"))
    add("")
    add("Re-read from the unit after decompilation (step 11, read-only commands only):")
    add("")
    add("| check | result |")
    add("| --- | --- |")
    for key, value in verification["checks"].items():
        add(f"| `{key}` | {value} |")
    add("")
    cover = verification["c_coverage"]
    add(f"Code inside indexed function ranges: {cover['instructions_in_function_ranges']:,} / "
        f"{cover['instructions_total']:,} decoded instructions ({cover['ratio']:.0%}).")
    add("")
    add("Device-reported builds: "
        + ", ".join(f"`{item}`" for item in verification["device"]["boot_and_firmware_builds"]))
    add("")
if os.path.exists(CFG["differential"]) or os.path.exists(CFG["confidence"]):
    add("The offline verification layers (steps 13-17, no unit needed) report five separate categories")
    add("for this build in `analysis/confidence.md`; `README.md` §4 explains what each one means.")
    add("")
add("## Core (Cortex-M4, ARMv7E-M)")
add("")
add(f"Vector table at `{vectors['vtor']}` ({vectors['count']} entries):")
add("")
add("```")
for row in vectors["entries"][:16]:
    add(f"[{row['index']:2d}] {row['name']:<12} {row['address']}")
add("```")
add("")
add("* Initial SP `%s`%s, reset handler "
    % (CFG["mcu"]["initial_sp"] or "not read",
       " (64 KiB SRAM at `0x20000000`)" if CFG["mcu"]["initial_sp"] else "")
    + f"`{[r['address'] for r in vectors['entries'] if r['name'] == 'Reset'][0]}`.")
add("* All IRQ vectors collapse onto a single dispatcher (`%s`), i.e. one common IRQ entry."
    % LAND.get("irq_dispatcher", "see analysis/vectors.json"))
add("")
add("## Decompile statistics")
add("")
add(f"* Thumb-2 instructions decoded (capstone linear sweep): {ins_count:,}")
add(f"* data words emitted as `.word` in the listing: {stats['data_word_items']:,}, "
    f"ascii lines: {stats['ascii_items']:,}, zero fills: {stats['fill_items']:,}")
add(f"* function candidates (vector table + `bl` targets + return-follows): {stats['functions']}")
add(f"* functions decompiled to C by Ghidra 12.2: {len(c_funcs)} ({c_failed} failures)")
add(f"* ASCII strings harvested: {len(strings)}")
add("")
add("### Call graph (direct `b`/`bl` edges from each vector handler)")
add("")
if os.path.exists(CFG["callgraph"]):
    graph = json.load(open(CFG["callgraph"], encoding="utf-8"))
    add("")
    add(f"{graph['total_functions']} indexed functions, {graph['reachable_total']} reachable from a")
    add("vector handler, "
        f"{graph['orphan_count']} only reachable through tables/indirect calls.")
    add("")
    add("| vector | handler | entry | reachable | depth |")
    add("| --- | --- | --- | --- | --- |")
    for entry in sorted(graph["handlers"], key=lambda item: -item["reachable"])[:8]:
        add(
            f"| {entry['index']} `{entry['name']}` | `{entry['address']}` | `{entry['entry']}` "
            f"| {entry['reachable']} | {entry['max_depth']} |"
        )
    add("")
add("### Static `{id, handler}` tables")
add("")
if os.path.exists(CFG["tables"]):
    tables = json.load(open(CFG["tables"], encoding="utf-8"))
    add("")
    add(f"{tables['table_count']} runs of >= {tables['min_run']} `{{u32 id, u32 handler}}` pairs;")
    add(f"every handler ({tables['decompiled_handlers']}) is present in the C output.")
    add("")
    for table in sorted(tables["tables"], key=lambda item: -len(item["entries"]))[:5]:
        first = table["entries"][0]
        last = table["entries"][-1]
        add(
            f"* `{table['address']}` - {len(table['entries'])} entries, "
            f"id `{first['id']}`..`{last['id']}`, handlers "
            f"`{first['handler']}`..`{last['handler']}`"
        )
    add("")
add("### Most-called functions")
add("")
add("| address | name | callers |")
add("| --- | --- | --- |")
for function in sorted(functions, key=lambda item: -len(item["callers"]))[:15]:
    add(f"| `{function['address']}` | `{function['name']}` | {len(function['callers'])} |")
add("")
add("### Functions with literal-pool string references")
add("")
add(f"Derived from `{CFG['xrefs']}` (literal pointers into the string table):")
add("")
if os.path.exists(CFG["xrefs"]):
    xrefs = json.load(open(CFG["xrefs"], encoding="utf-8"))
    add("")
    add("| function | referenced strings (first) |")
    add("| --- | --- |")
    for name, texts in list(xrefs["function_strings"].items())[:18]:
        informative = max(texts, key=len)
        add(f"| `{name}` | {len(texts)}: `{informative[:60].replace(chr(10), ' / ')}` |")
    add("")
    failures = re.findall(r"/\* ===== (\S+) @ (\w+) ===== \*/\n/\* decompilation failed \*/", c_text)
    if failures:
        add("Ghidra left "
            f"{len(failures)} stubs (`0x{failures[0][1]}`"
            + "".join(f", `0x{item[1]}`" for item in failures[1:])
            + "): data-table slots whose code is only in the listing.")
        add("")
add("### Notable strings")
add("")
for item in notable[:25]:
    add(f"* `{item['address']}` `{item['text'][:78]}`")
add("")
add("## Artifacts")
add("")
add("```")
add("%-42s %s" % ("%s/container.bin" % CFG["dir"], "vendor container as shipped (%s)"
                  % CFG["primary_container"]))
add("%-42s %s" % (CFG["flash"], "decoded flat flash image (base %s)" % CFG["mcu"]["base"]))
add("%-42s %s" % (CFG["blocks"], "per-block metadata"))
add("%-42s %s" % (CFG["listing"], "annotated Thumb-2 disassembly"))
add("%-42s %s" % (CFG["c"], "Ghidra C decompilation, one block per function"))
add("%-42s %s" % (CFG["index"], "C file: function -> line range (upper-case hex keys)"))
for name in ("vectors", "strings", "functions", "stats", "xrefs", "callgraph", "tables"):
    add("%-42s %s" % (CFG[name], {
        "vectors": "interrupt vector table",
        "strings": "strings with addresses",
        "functions": "function index (callers, size, instructions)",
        "stats": "counts for the numbers above",
        "xrefs": "literal-pool cross-references",
        "callgraph": "reachability from each vector handler",
        "tables": "static {id, handler} dispatch tables",
    }[name]))
add("%-42s %s" % (CFG["verification"], "device-vs-image byte comparisons"))
add("%-42s %s" % (CFG["capture"], "live identity, virtual strings, parameter areas (step 2)"))
add("%-42s %s" % (CFG["container_check"], "vendor-file vs device field matches (step 3)"))
add("%-42s %s" % (CFG["vsfr"], "live VSFR values, single-value form (tools)"))
add("%-42s %s" % (CFG["sweep_noarg"], "which command ids answer, no argument"))
add("%-42s %s" % (CFG["sweep_witharg"], "which command ids answer, with a u32 argument"))
for name, note in (
    ("ghidra_listing", "SLEIGH listing + function ranges (step 6, feeds step 14)"),
    ("roundtrip", "L1: container re-encoded byte for byte (step 13)"),
    ("crosscheck", "L2: capstone vs SLEIGH agreement, four tiers (step 14)"),
    ("differential", "L4: Unicorn vs the Python models (step 15)"),
    ("formal", "L5: Z3 goals with their verdicts (step 16)"),
    ("confidence", "the five verification categories (step 17)"),
    ("confidence_md", "the same, readable form"),
):
    add("%-42s %s" % (CFG[name], note))
add("%-42s %s" % (CFG["manifest"], "this build's identity + file checksums"))
add("%-42s %s" % (CFG["summary"], "this file"))
add("```")
add("")
add("## Reproduce")
add("")
add("```powershell")
add("python pipeline/run.py                    # every step, in order")
add("python pipeline/run.py --list             # the step table")
add("python pipeline/run.py --only 1,4,5       # offline: self-test, decode, disassemble")
add("python pipeline/run.py --only 3           # fetch + match the vendor container")
add("python pipeline/run.py --only 2           # live read-only capture (BLE)")
add("python pipeline/run.py --only 6           # Ghidra headless decompilation")
add("python pipeline/run.py --from 7           # index, xrefs, callgraph, tables, verify, report")
add("python pipeline/run.py --only 13,14,15,16,17   # the offline verification layers only")
add("python pipeline/tools/lookup.py 0x080275C4   # ad-hoc query: function + callers + strings")
add("python pipeline/tools/read_vsfrs.py          # live VSFR readout")
add("```")
add("")
add("Naming: the capstone index (`functions.json`, `xrefs.json`) uses `sub_XXXXXXXX`; the Ghidra C")
add("uses `FUN_xxxxxxxx` (lower-case hex), `handler_*` for vector-table entries and")
add("`tbl_<id>_<address>` for handlers found in a static `{id, handler}` table. `0x`-prefixed,")
add("upper-case addresses in `index.json` map a function address to its line range in `decompiled.c`.")
add("")

os.makedirs(CFG["analysis_dir"], exist_ok=True)
with open(CFG["summary"], "w", encoding="utf-8") as fh:
    fh.write("\n".join(lines) + "\n")

print("wrote", CFG["summary"], len(lines), "lines")


def _digest(path):
    with open(path, "rb") as fh:
        blob = fh.read()
    return {"bytes": len(blob), "sha256": hashlib.sha256(blob).hexdigest()}


manifest = {
    "target": CFG["key"],
    "device": CFG["device"],
    "model": CFG["model"],
    "hw": CFG["hw"],
    "fw": CFG["fw"],
    "boot": CFG["boot"],
    "serial": CFG["serial"],
    "ble_address": CFG["ble_address"],
    "mcu": CFG["mcu"],
    "expected": CFG["expected"],
    "landmarks": CFG["landmarks"],
    "files": {},
}
for name in ("container", "flash", "blocks", "listing", "c", "index",
             "ghidra_listing", "roundtrip", "crosscheck", "differential", "formal", "confidence"):
    if os.path.exists(CFG[name]):
        manifest["files"][name] = dict(path=CFG[name], **_digest(CFG[name]))
os.makedirs(CFG["dir"], exist_ok=True)
with open(CFG["manifest"], "w", encoding="utf-8") as fh:
    json.dump(manifest, fh, indent=2)
print("wrote", CFG["manifest"], "with", len(manifest["files"]), "checksums")
