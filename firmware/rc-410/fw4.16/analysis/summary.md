# RadiaCode-410 firmware analysis - `rc-410/fw4.16`

<!-- current-evidence:start -->
## Current analysis update

| Item | Current result |
| --- | --- |
| Target | `rc-410/fw4.16` |
| Application extraction | PASS |
| Exported C blocks | 1046 |
| Explicit failures / truncated / warnings | 0 / 0 / 47 |
| Complete rebuilt firmware | Not yet established |

The original report below retains its section links and baseline observations.
Current evidence: [confidence.md](confidence.md), [confidence.json](confidence.json),
[recovery_delta.json](recovery_delta.json). Counts measure discovery, not functional coverage.

Regenerate from the repository root with `python pipeline/run.py --all-devices --only 17,12`.
Exit 2 denotes incomplete or inconclusive evidence; it is not a pass.
<!-- current-evidence:end -->

> **Baseline reference:** the original report and section anchors are retained below.
> Its counts, confidence labels and operational assumptions describe the earlier
> pipeline. The current generated evidence block above and current JSON reports
> supersede those measurements; historical interpretations still require review.

Device: RadiaCode-410, serial `-`, BLE `-`. Bootloader `-`, firmware `4.16`.

Target directory: `firmware/rc-410/fw4.16` - every file below lives inside it. The active target is chosen by
`RC_TARGET` or `pipeline/run.py --device`; the registry is `pipeline/devices.json`.

### Registered targets

| target | device | fw | hw | container | bytes | blocks | analyzed |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `rc-102/hw1-fw4.14` | RadiaCode-102 | 4.14 | 1 | `rc-102z.bin` | 130148 | 8 | yes |
| `rc-101/fw4.14` | RadiaCode-101 | 4.14 | - | `rc-101_v01z.bin` | 130388 | 8 | container + decode only |
| `rc-103/fw4.14` | RadiaCode-103 | 4.14 | - | `rc-103z.bin` | 130132 | 8 | container + decode only |
| `rc-103g/fw4.14` | RadiaCode-103G | 4.14 | - | `rc-103gz.bin` | 130444 | 8 | container + decode only |
| `rc-110/fw4.14` | RadiaCode-110 | 4.14 | - | `rc-110z.bin` | 133312 | 9 | container + decode only |
| `rc-410/fw4.16` | RadiaCode-410 | 4.16 | - | `rc-410z.bin` | 140836 | 10 | container + decode only |

## How the image was obtained

The device was read over BLE (Nordic UART service `e63215e5…`, 4-byte little-endian
length prefix + `cmd(u16 LE) + 0x00 + seq`). No write/erase command was used; only reads:

| BLE command | value |
| --- | --- |
| `0x000A` GET_VERSION | boot `-`, firmware `4.16` |
| `0x000B` GET_SERIAL | `-` |
| `0x0012` FW_IMAGE_GET_INFO | size `140836`, buffer `4096`, date_time `0x5CB949E4`, crc `0xC759BFB1` |
| `0x0013` | `n/a` (block/frame count) |
| `0x081C` RD_FLASH area 0/1 | XOR-obfuscated `PublicAPI` struct (Borland LCG), device parameters |

Values in that table are the registry's (`pipeline/devices.json`), read from the container
header by step 3; this target has no live unit in `analysis/capture.json`.

The device exposes no image-read command (verified by a full `0x0000-0x0FFF` scan, with and
without a `u32` argument), so the image bytes come from the official `rc-410z.bin` shipped in
`https://downloads.radiacode.com/EN/RadiaCode.apk` (`assets/HardSoft/`). Identity with the unit
in hand is proven by three independent matches: file length `140836`, header `date_time`
`0x5CB949E4`, whole-file CRC `0xC759BFB1` - all equal to the device's own `0x0012` answer -
plus the in-image vendor-config text found byte-identically in the image
(see `analysis/verification.json`).

Memory model: the container addresses blocks from `0x08000000`, so the flat image spans
`0x08000000-0x08040800`; offsets `0x00000-0xFFFF` stay zero because the bootloader region
`0x08000000-0x0800FFFF` is not part of this file. Application base = `0x08010000`.

## File format (`Phyton\x00\x00` container)

```
header   : marker[8] | u32 header_size | u32 date_time | u32 buffer_size | u8[16] serial
           | u8 version_low | u8 version_high | u32 file_count | u32 fw_header_size
           | u8 compressed | u8 reserved | u32 crc32
blocks[] : u32 header_size | u32 size ^ 0xCE27A932 | u32 addr ^ 0xB2D5A864
           | key_block[512] | data[size aligned to 8]
```

* `key_block` is unmangled with hardcoded key table slot 0 (index at `[0:2]`, 16-byte data key at
  `[2:18]`, CRC pair at `[18:26]`); the key/CRC region is then unmangled a second time with the
  table selected by that index (`0-7` hardcoded, `8-15` zero table, `0xFFFF` device id key).
* The Mangle cipher is a 48-round Feistel network over 8-byte blocks, 4 round keys
  (`key[rnd & 3]`), round function `B' = rnd + key + ((B>>8)^(B<<6)) + B + A`.
* CRC: MPEG-2 polynomial `0x04C11DB7`, no reflection, init `0xFFFFFFFF`, fed in 4-byte LE chunks
  (`rcfmt.calculate_crc`).
* Payload: LZSS, 2048-byte window pre-filled with `0x20`, initial index `2031`, flag bit 1 =
  literal, 0 = match with 11-bit offset + 4-bit length (+2), i.e. match length `2..17`.

## Decoded flash image

`firmware/rc-410/fw4.16/flash.bin`: 264192 bytes (`0x08000000`-`0x08040800`), every block CRC verified.

| # | address | decompressed size | crc | instructions |
| --- | --- | --- | --- | --- |
| 0 | `0x08010000` | 0x3e00 (15872) | `9c689840` | 5776 |
| 1 | `0x08013e00` | 0x5a00 (23040) | `2a972460` | 8678 |
| 2 | `0x08019800` | 0x4400 (17408) | `08eaba8d` | 6579 |
| 3 | `0x0801dc00` | 0x6b00 (27392) | `1da6683c` | 10410 |
| 4 | `0x08024700` | 0x3f00 (16128) | `73d9abee` | 6107 |
| 5 | `0x08028600` | 0x6800 (26624) | `3a90bfaa` | 10079 |
| 6 | `0x0802ee00` | 0x4d00 (19712) | `020e63c1` | 6977 |
| 7 | `0x08033b00` | 0x4600 (17920) | `15bdaa1e` | 5089 |
| 8 | `0x08038100` | 0x3e00 (15872) | `1cc058dd` | 6333 |
| 9 | `0x0803bf00` | 0x4900 (18688) | `bee1d1ec` | 6801 |

## Verification against the live device

The offline verification layers (steps 13-17, no unit needed) report five separate categories
for this build in `analysis/confidence.md`; `README.md` §4 explains what each one means.

## Core (Cortex-M4, ARMv7E-M)

Vector table at `0x08010000` (98 entries):

```
[ 0] InitialSP    0x20000800
[ 1] Reset        0x0803F725
[ 2] NMI          0x0803992D
[ 3] HardFault    0x0803992F
[ 4] MemManage    0x08039931
[ 5] BusFault     0x08039933
[ 6] UsageFault   0x08039935
[ 7] Reserved7    0x00000000
[ 8] Reserved8    0x00000000
[ 9] Reserved9    0x00000000
[10] Reserved10   0x00000000
[11] SVCall       0x08039937
[12] DebugMon     0x08039939
[13] Reserved13   0x00000000
[14] PendSV       0x0803993B
[15] SysTick      0x080401F5
```

* Initial SP `not read`, reset handler `0x0803F725`.
* All IRQ vectors collapse onto a single dispatcher (`see analysis/vectors.json`), i.e. one common IRQ entry.

## Decompile statistics

* Thumb-2 instructions decoded (capstone linear sweep): 72,189
* data words emitted as `.word` in the listing: 385, ascii lines: 833, zero fills: 1,258
* function candidates (vector table + `bl` targets + return-follows): 2125
* functions decompiled to C by Ghidra 12.2: 2123 (2 failures)
* ASCII strings harvested: 2205

### Call graph (direct `b`/`bl` edges from each vector handler)


2125 indexed functions, 276 reachable from a
vector handler, 1849 only reachable through tables/indirect calls.

| vector | handler | entry | reachable | depth |
| --- | --- | --- | --- | --- |
| 1 `Reset` | `0x0803F725` | `0x0803F724` | 139 | 9 |
| 15 `SysTick` | `0x080401F5` | `0x080401F4` | 139 | 10 |
| 16 `IRQ0_WWDG` | `0x080401F5` | `0x080401F4` | 139 | 10 |
| 17 `IRQ1_PVD` | `0x080401F5` | `0x080401F4` | 139 | 10 |
| 18 `IRQ2_TAMP_STAMP` | `0x080401F5` | `0x080401F4` | 139 | 10 |
| 19 `IRQ3_RTC_WKUP` | `0x080401F5` | `0x080401F4` | 139 | 10 |
| 20 `IRQ4_FLASH` | `0x080401F5` | `0x080401F4` | 139 | 10 |
| 21 `IRQ5_RCC` | `0x080401F5` | `0x080401F4` | 139 | 10 |

### Static `{id, handler}` tables


8 runs of >= 4 `{u32 id, u32 handler}` pairs;
every handler (85) is present in the C output.

* `0x0803A33C` - 44 entries, id `0x0`..`0xC18`, handlers `0x08020EF4`..`0x08038746`
* `0x08021000` - 10 entries, id `0x28F`..`0x2666`, handlers `0x08020F2C`..`0x08020F1E`
* `0x0803C6C8` - 10 entries, id `0x1`..`0xB`, handlers `0x0803875C`..`0x08038898`
* `0x0803BE10` - 7 entries, id `0x0`..`0x0`, handlers `0x08016C5A`..`0x08016F8C`
* `0x0803D094` - 7 entries, id `0x5`..`0x30`, handlers `0x08038380`..`0x08038406`

### Most-called functions

| address | name | callers |
| --- | --- | --- |
| `0x080179F8` | `sub_080179F8` | 152 |
| `0x08018B64` | `sub_08018B64` | 113 |
| `0x08017A48` | `sub_08017A48` | 72 |
| `0x08018B1C` | `sub_08018B1C` | 64 |
| `0x080190F8` | `sub_080190F8` | 60 |
| `0x08024BC4` | `sub_08024BC4` | 53 |
| `0x0802078C` | `sub_0802078C` | 49 |
| `0x0801FFD0` | `sub_0801FFD0` | 47 |
| `0x08017A6C` | `sub_08017A6C` | 42 |
| `0x080262D4` | `sub_080262D4` | 42 |
| `0x08024BBC` | `sub_08024BBC` | 41 |
| `0x08017DBE` | `sub_08017DBE` | 36 |
| `0x08026250` | `sub_08026250` | 31 |
| `0x0802B51E` | `sub_0802B51E` | 31 |
| `0x08022A56` | `sub_08022A56` | 25 |

### Functions with literal-pool string references

Derived from `firmware/rc-410/fw4.16/analysis/xrefs.json` (literal pointers into the string table):


| function | referenced strings (first) |
| --- | --- |
| `sub_080388E6` | 17: `xpG@xpG` |
| `sub_08028B8E` | 5: `Error: S%d Packet or String size corrupted! PacketSize = 0x%` |
| `sub_0803D6C6` | 4: `pGpG` |
| `sub_0802640E` | 3: `%d message(s) lost!` |
| `sub_080196DC` | 2: `BLE: disconnected by reason 0x%0.2X` |
| `sub_08020158` | 2: `%02d:%02d:%02d` |
| `sub_08029DBA` | 2: `[VSFR_DEVICE_CTRL] / Addr=0x00000500 / Virtual=1 / Size=1 / [VSFR_DE` |
| `sub_0803A85C` | 2: `BhJ`pG8` |
| `sub_08016558` | 1: `00  ` |
| `sub_08020FEC` | 1: ``pG1I/KO` |
| `sub_08024ACC` | 1: ` BLE: Connection parameter update error #0x%0.2X! Interval i` |
| `sub_080274B0` | 1: ` 9h!` |
| `sub_08027F7E` | 1: `BLE: error packet received => %0.2X; %0.2X; %0.2X; %0.2X!` |
| `sub_0802821E` | 1: `BhJ`pG8` |
| `sub_0803A15C` | 1: ` pG0` |
| `sub_0803E140` | 1: ` pG; pG` |
| `sub_0803EBF8` | 1: `apGp` |
| `handler_reset` | 1: `sB`pG8` |

Ghidra left 2 stubs (`0x08016ba0`, `0x0803b986`): data-table slots whose code is only in the listing.

### Notable strings

* `0x080197E4` `RadiaCode Zero`
* `0x08028170` `CRC Error: 0x%08X != 0x%08X`
* `0x08032A23` `
DispBacklight=0-9
Language=English
DBLag_ms=180000
FrameTimeStep_us=10000
Ene`

## Artifacts

```
firmware/rc-410/fw4.16/container.bin       vendor container as shipped (rc-410z.bin)
firmware/rc-410/fw4.16/flash.bin           decoded flat flash image (base 0x08000000)
firmware/rc-410/fw4.16/blocks.json         per-block metadata
firmware/rc-410/fw4.16/listing.s           annotated Thumb-2 disassembly
firmware/rc-410/fw4.16/decompiled.c        Ghidra C decompilation, one block per function
firmware/rc-410/fw4.16/index.json          C file: function -> line range (upper-case hex keys)
firmware/rc-410/fw4.16/analysis/vectors.json interrupt vector table
firmware/rc-410/fw4.16/analysis/strings.json strings with addresses
firmware/rc-410/fw4.16/analysis/functions.json function index (callers, size, instructions)
firmware/rc-410/fw4.16/analysis/stats.json counts for the numbers above
firmware/rc-410/fw4.16/analysis/xrefs.json literal-pool cross-references
firmware/rc-410/fw4.16/analysis/callgraph.json reachability from each vector handler
firmware/rc-410/fw4.16/analysis/tables.json static {id, handler} dispatch tables
firmware/rc-410/fw4.16/analysis/verification.json device-vs-image byte comparisons
firmware/rc-410/fw4.16/analysis/capture.json live identity, virtual strings, parameter areas (step 2)
firmware/rc-410/fw4.16/analysis/container_check.json vendor-file vs device field matches (step 3)
firmware/rc-410/fw4.16/analysis/vsfr_readout.json live VSFR values, single-value form (tools)
firmware/rc-410/fw4.16/analysis/sweep_noarg.json which command ids answer, no argument
firmware/rc-410/fw4.16/analysis/sweep_witharg.json which command ids answer, with a u32 argument
firmware/rc-410/fw4.16/analysis/ghidra_listing.json SLEIGH listing + function ranges (step 6, feeds step 14)
firmware/rc-410/fw4.16/analysis/roundtrip.json L1: container re-encoded byte for byte (step 13)
firmware/rc-410/fw4.16/analysis/crosscheck.json L2: capstone vs SLEIGH agreement, four tiers (step 14)
firmware/rc-410/fw4.16/analysis/differential.json L4: Unicorn vs the Python models (step 15)
firmware/rc-410/fw4.16/analysis/formal.json L5: Z3 goals with their verdicts (step 16)
firmware/rc-410/fw4.16/analysis/confidence.json the five verification categories (step 17)
firmware/rc-410/fw4.16/analysis/confidence.md the same, readable form
firmware/rc-410/fw4.16/manifest.json       this build's identity + file checksums
firmware/rc-410/fw4.16/analysis/summary.md this file
```

## Reproduce

```powershell
python pipeline/run.py                    # every step, in order
python pipeline/run.py --list             # the step table
python pipeline/run.py --only 1,4,5       # offline: self-test, decode, disassemble
python pipeline/run.py --only 3           # fetch + match the vendor container
python pipeline/run.py --only 2           # live read-only capture (BLE)
python pipeline/run.py --only 6           # Ghidra headless decompilation
python pipeline/run.py --from 7           # index, xrefs, callgraph, tables, verify, report
python pipeline/run.py --only 13,14,15,16,17   # the offline verification layers only
python pipeline/tools/lookup.py 0x080275C4   # ad-hoc query: function + callers + strings
python pipeline/tools/read_vsfrs.py          # live VSFR readout
```

Naming: the capstone index (`functions.json`, `xrefs.json`) uses `sub_XXXXXXXX`; the Ghidra C
uses `FUN_xxxxxxxx` (lower-case hex), `handler_*` for vector-table entries and
`tbl_<id>_<address>` for handlers found in a static `{id, handler}` table. `0x`-prefixed,
upper-case addresses in `index.json` map a function address to its line range in `decompiled.c`.
