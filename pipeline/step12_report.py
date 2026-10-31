"""Build firmware/analysis/summary.md from the generated artifacts."""

import json
import os
import re
from collections import Counter

BASE = 0x08000000

blocks = json.load(open("firmware/rc102_blocks.json", encoding="utf-8"))
vectors = json.load(open("firmware/analysis/vectors.json", encoding="utf-8"))
strings = json.load(open("firmware/analysis/strings.json", encoding="utf-8"))
functions = json.load(open("firmware/analysis/functions.json", encoding="utf-8"))

data = open("firmware/rc102_flash.bin", "rb").read()
size = len(data)
end = BASE + size

stats = json.load(open("firmware/analysis/stats.json", encoding="utf-8"))
ins_count = stats["instructions"]
listing = open("firmware/listing/rc102_flash.s", encoding="utf-8").read().splitlines()

c_text = open("firmware/decompiled/rc102_flash.c", encoding="utf-8").read()
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
    token in s["text"] for token in ("RadiaCode", "rc-10", "STM32", "Version", "CRC", "Phyton"))]

lines = []
add = lines.append
add("# RadiaCode-102 firmware analysis")
add("")
add("Device: RadiaCode-102, serial `RC-102-008228`, BLE `52:43:06:60:20:24`.")
add("")
add("## How the image was obtained")
add("")
add("The device was read over BLE (Nordic UART service `e63215e5-…fb901`, 4-byte little-endian")
add("length prefix + `cmd(u16 LE) + 0x00 + seq`). No write/erase command was used; only reads:")
add("")
add("| BLE command | value |")
add("| --- | --- |")
add("| `0x000A` GET_VERSION | boot `4.0` (Feb 20 2023 15:49:14), firmware `4.14` (Jul 7 2025 11:19:22) |")
add("| `0x000B` GET_SERIAL | `RC-102-008228` |")
add("| `0x0012` FW_IMAGE_GET_INFO | size `130148`, buffer `4096`, date_time `0x5AE7428A`, crc `0x13095ABB` |")
add("| `0x0013` | `19` (block/frame count) |")
add("| `0x0101` | `rc-102.bin`, `RadiaCode RC-102` |")
add("| `0x081C` RD_FLASH area 0/1 | XOR-obfuscated `PublicAPI` struct (Borland LCG), device parameters |")
add("")
add("The device exposes no image-read command (verified by a full `0x0000-0x0FFF` scan, with and")
add("without a `u32` argument), so the image bytes come from the official `rc-102z.bin` shipped in")
add("`https://downloads.radiacode.com/EN/RadiaCode.apk` (`assets/HardSoft/`). Identity with the unit")
add("in hand is proven by three independent matches: file length `130148`, header `date_time`")
add("`0x5AE7428A`, whole-file CRC `0x13095ABB` - all equal to the device's own `0x0012` answer -")
add("plus the in-image vendor-config text (3256 bytes) found byte-identically at `0x0802F9F0`,")
add("matching the device's `VS CONFIGURATION` string. See `firmware/analysis/verification.json`.")
add("")
add("Memory model: the container addresses blocks from `0x08000000`, so the flat image spans")
add("`0x08000000-0x0803CA00`; offsets `0x00000-0xFFFF` stay zero because the bootloader region")
add("(`0x08000000-0x0800FFFF`) is not part of this file. Application base = `0x08010000`.")
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
add("* Payload: LZSS, 2048-byte window pre-filled with `0x20`, initial index `2022`, flag bit 1 =")
add("  literal, 0 = match with 11-bit offset + 4-bit length (+2).")
add("")
add("## Decoded flash image")
add("")
add(f"`firmware/rc102_flash.bin`: {size} bytes (`0x{BASE:08X}`-`0x{end:08X}`), every block CRC verified.")
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
if os.path.exists("firmware/analysis/verification.json"):
    verification = json.load(open("firmware/analysis/verification.json", encoding="utf-8"))
    add("")
    add("Re-read from the unit after decompilation (`verify_match.py`, read-only commands only):")
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
add("## Core (Cortex-M4, ARMv7E-M)")
add("")
add(f"Vector table at `{vectors['vtor']}` ({vectors['count']} entries):")
add("")
add("```")
for row in vectors["entries"][:16]:
    add(f"[{row['index']:2d}] {row['name']:<12} {row['address']}")
add("```")
add("")
add("* Initial SP `0x20000800` (64 KiB SRAM at `0x20000000`), reset handler "
    f"`{[r['address'] for r in vectors['entries'] if r['name'] == 'Reset'][0]}`.")
add("* All IRQ vectors collapse onto a single dispatcher (`0x0803C4D9`), i.e. one common IRQ entry.")
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
if os.path.exists("firmware/analysis/callgraph.json"):
    graph = json.load(open("firmware/analysis/callgraph.json", encoding="utf-8"))
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
if os.path.exists("firmware/analysis/tables.json"):
    tables = json.load(open("firmware/analysis/tables.json", encoding="utf-8"))
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
add("Derived from `firmware/analysis/xrefs.json` (literal pointers into the string table):")
add("")
if os.path.exists("firmware/analysis/xrefs.json"):
    xrefs = json.load(open("firmware/analysis/xrefs.json", encoding="utf-8"))
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
add("firmware/rc102_flash.bin            decoded flat flash image (base 0x08000000)")
add("firmware/rc102_blocks.json          per-block metadata")
add("firmware/listing/rc102_flash.s      annotated Thumb-2 disassembly")
add("firmware/decompiled/rc102_flash.c   Ghidra C decompilation, one block per function")
add("firmware/analysis/vectors.json      interrupt vector table")
add("firmware/analysis/strings.json      strings with addresses")
add("firmware/analysis/functions.json    function index (callers, size, decoded instructions)")
add("firmware/analysis/stats.json        counts for the numbers above")
add("firmware/analysis/xrefs.json        literal-pool cross-references (string -> function)")
add("firmware/analysis/callgraph.json    reachability from each vector handler")
add("firmware/analysis/tables.json       static {id, handler} dispatch tables")
add("firmware/analysis/verification.json device-vs-image byte comparisons")
add("firmware/analysis/device_capture.json  live identity, virtual strings, parameter areas (step 2)")
add("firmware/analysis/container_check.json vendor-file vs device field matches (step 3)")
add("firmware/analysis/vsfr_readout.json    live VSFR values, single-value form (tools)")
add("firmware/analysis/sweep_noarg.json     which command ids answer, no argument")
add("firmware/analysis/sweep_witharg.json   which command ids answer, with a u32 argument")
add("firmware/decompiled/index.json      C file: function -> line range (keys are upper-case hex)")
add("firmware/analysis/summary.md        this file")
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
add("python pipeline/tools/lookup.py 0x080275C4   # ad-hoc query: function + callers + strings")
add("python pipeline/tools/read_vsfrs.py          # live VSFR readout")
add("```")
add("")
add("Naming: the capstone index (`functions.json`, `xrefs.json`) uses `sub_XXXXXXXX`; the Ghidra C")
add("uses `FUN_xxxxxxxx` (lower-case hex), `handler_*` for vector-table entries and")
add("`tbl_<id>_<address>` for handlers found in a static `{id, handler}` table. `0x`-prefixed,")
add("upper-case addresses in `index.json` map a function address to its line range in `rc102_flash.c`.")
add("")

with open("firmware/analysis/summary.md", "w", encoding="utf-8") as fh:
    fh.write("\n".join(lines) + "\n")

print("wrote firmware/analysis/summary.md", len(lines), "lines")
