# RadiaCode-110 firmware analysis - `rc-110/fw4.14`

Device: RadiaCode-110, serial `-`, BLE `-`. Bootloader `-`, firmware `4.14`.

Target directory: `firmware/rc-110/fw4.14` - every file below lives inside it. The active target is chosen by
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
| `0x000A` GET_VERSION | boot `-`, firmware `4.14` |
| `0x000B` GET_SERIAL | `-` |
| `0x0012` FW_IMAGE_GET_INFO | size `133312`, buffer `4096`, date_time `0x5AE742EE`, crc `0x23FEA728` |
| `0x0013` | `n/a` (block/frame count) |
| `0x081C` RD_FLASH area 0/1 | XOR-obfuscated `PublicAPI` struct (Borland LCG), device parameters |

Values in that table are the registry's (`pipeline/devices.json`), read from the container
header by step 3; this target has no live unit in `analysis/capture.json`.

The device exposes no image-read command (verified by a full `0x0000-0x0FFF` scan, with and
without a `u32` argument), so the image bytes come from the official `rc-110z.bin` shipped in
`https://downloads.radiacode.com/EN/RadiaCode.apk` (`assets/HardSoft/`). Identity with the unit
in hand is proven by three independent matches: file length `133312`, header `date_time`
`0x5AE742EE`, whole-file CRC `0x23FEA728` - all equal to the device's own `0x0012` answer -
plus the in-image vendor-config text found byte-identically in the image
(see `analysis/verification.json`).

Memory model: the container addresses blocks from `0x08000000`, so the flat image spans
`0x08000000-0x0803D800`; offsets `0x00000-0xFFFF` stay zero because the bootloader region
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

`firmware/rc-110/fw4.14/flash.bin`: 251904 bytes (`0x08000000`-`0x0803D800`), every block CRC verified.

| # | address | decompressed size | crc | instructions |
| --- | --- | --- | --- | --- |
| 0 | `0x08010000` | 0x6d00 (27904) | `057f9850` | 10391 |
| 1 | `0x08016d00` | 0x4800 (18432) | `46eef8d7` | 6776 |
| 2 | `0x0801b500` | 0x4c00 (19456) | `2476fc50` | 7452 |
| 3 | `0x08020100` | 0x5400 (21504) | `95cb959d` | 8235 |
| 4 | `0x08025500` | 0x5900 (22784) | `f502a78b` | 8648 |
| 5 | `0x0802ae00` | 0x6c00 (27648) | `38cb630e` | 9881 |
| 6 | `0x08031a00` | 0x6d00 (27904) | `99d0e3a3` | 9637 |
| 7 | `0x08038700` | 0x4800 (18432) | `9ff38f34` | 6521 |
| 8 | `0x0803cf00` | 0x900 (2304) | `3eca98a4` | 893 |

## Verification against the live device

The offline verification layers (steps 13-17, no unit needed) report five separate categories
for this build in `analysis/confidence.md`; `README.md` §4 explains what each one means.

## Core (Cortex-M4, ARMv7E-M)

Vector table at `0x08010000` (98 entries):

```
[ 0] InitialSP    0x20000800
[ 1] Reset        0x0803C7C9
[ 2] NMI          0x08037049
[ 3] HardFault    0x0803704B
[ 4] MemManage    0x0803704D
[ 5] BusFault     0x0803704F
[ 6] UsageFault   0x08037051
[ 7] Reserved7    0x00000000
[ 8] Reserved8    0x00000000
[ 9] Reserved9    0x00000000
[10] Reserved10   0x00000000
[11] SVCall       0x08037053
[12] DebugMon     0x08037055
[13] Reserved13   0x00000000
[14] PendSV       0x08037057
[15] SysTick      0x08037059
```

* Initial SP `not read`, reset handler `0x0803C7C9`.
* All IRQ vectors collapse onto a single dispatcher (`see analysis/vectors.json`), i.e. one common IRQ entry.

## Decompile statistics

* Thumb-2 instructions decoded (capstone linear sweep): 67,873
* data words emitted as `.word` in the listing: 311, ascii lines: 772, zero fills: 1,194
* function candidates (vector table + `bl` targets + return-follows): 1908
* functions decompiled to C by Ghidra 12.2: 1934 (2 failures)
* ASCII strings harvested: 1980

### Call graph (direct `b`/`bl` edges from each vector handler)


1908 indexed functions, 101 reachable from a
vector handler, 1807 only reachable through tables/indirect calls.

| vector | handler | entry | reachable | depth |
| --- | --- | --- | --- | --- |
| 1 `Reset` | `0x0803C7C9` | `0x0803C7C8` | 33 | 7 |
| 28 `IRQ12_DMA1_CH1` | `0x080370C1` | `0x080370C0` | 25 | 5 |
| 82 `IRQ66_LPTIM3` | `0x08037187` | `0x08037186` | 25 | 5 |
| 6 `UsageFault` | `0x08037051` | `0x08037050` | 20 | 6 |
| 11 `SVCall` | `0x08037053` | `0x08037050` | 20 | 6 |
| 12 `DebugMon` | `0x08037055` | `0x08037050` | 20 | 6 |
| 14 `PendSV` | `0x08037057` | `0x08037050` | 20 | 6 |
| 15 `SysTick` | `0x08037059` | `0x08037050` | 20 | 6 |

### Static `{id, handler}` tables


8 runs of >= 4 `{u32 id, u32 handler}` pairs;
every handler (85) is present in the C output.

* `0x0803785C` - 44 entries, id `0x0`..`0xC18`, handlers `0x08020B84`..`0x08035922`
* `0x08020C90` - 10 entries, id `0x28F`..`0x2666`, handlers `0x08020BBC`..`0x08020BAE`
* `0x08039944` - 10 entries, id `0x1`..`0xB`, handlers `0x08035938`..`0x08035A74`
* `0x080391EC` - 7 entries, id `0x0`..`0x0`, handlers `0x080171F8`..`0x08017636`
* `0x0803A0EC` - 7 entries, id `0x5`..`0x30`, handlers `0x08035560`..`0x080355E2`

### Most-called functions

| address | name | callers |
| --- | --- | --- |
| `0x08018234` | `sub_08018234` | 163 |
| `0x080197C8` | `sub_080197C8` | 110 |
| `0x08018258` | `sub_08018258` | 85 |
| `0x08019780` | `sub_08019780` | 64 |
| `0x08019D62` | `sub_08019D62` | 58 |
| `0x080258D0` | `sub_080258D0` | 51 |
| `0x08020304` | `sub_08020304` | 50 |
| `0x0801FB94` | `sub_0801FB94` | 47 |
| `0x0801827C` | `sub_0801827C` | 45 |
| `0x0802B52C` | `sub_0802B52C` | 42 |
| `0x0802498C` | `sub_0802498C` | 40 |
| `0x08018300` | `sub_08018300` | 39 |
| `0x0802AA70` | `sub_0802AA70` | 37 |
| `0x0802AB2E` | `sub_0802AB2E` | 30 |
| `0x0801D924` | `sub_0801D924` | 29 |

### Functions with literal-pool string references

Derived from `firmware/rc-110/fw4.14/analysis/xrefs.json` (literal pointers into the string table):


| function | referenced strings (first) |
| --- | --- |
| `sub_080366FE` | 15: `@ pG@m` |
| `sub_0802819C` | 5: `Error: S%d Packet or String size corrupted! PacketSize = 0x%` |
| `sub_08035B54` | 5: `BLE: HW error/Timer overrun` |
| `sub_08036A46` | 4: ` pGp` |
| `sub_0803BC1E` | 4: `pGpGb` |
| `handler_reset` | 4: `HIIK / hB` |
| `sub_08035AC4` | 3: `BLE: disconnected by reason 0x%0.2X` |
| `sub_08024AC0` | 2: `%d message(s) lost!` |
| `sub_080292B2` | 2: `[VSFR_DEVICE_CTRL] / Addr=0x00000500 / Virtual=1 / Size=1 / [VSFR_DE` |
| `sub_0802C27C` | 2: `%02d:%02d:%02d` |
| `sub_08037EAC` | 2: `BhJ`pG8` |
| `sub_0803A772` | 2: `pGpGb` |
| `sub_0803B2A0` | 2: ` pG; pG` |
| `sub_0801670C` | 1: `YAX@Y@` |
| `sub_08020C7C` | 1: ``pG1I/KO` |
| `sub_08023320` | 1: `BLE: Connection parameter update error #0x%0.2X! Interval is` |
| `sub_0802750E` | 1: `BLE: error packet received => %0.2X; %0.2X; %0.2X; %0.2X!` |
| `sub_080277CA` | 1: `BhJ`pG8` |

Ghidra left 2 stubs (`0x0802b06c`, `0x0803875a`): data-table slots whose code is only in the listing.

### Notable strings

* `0x0801A1A8` `RadiaCode-110`
* `0x0802771C` `CRC Error: 0x%08X != 0x%08X`
* `0x080306FD` `
DispBacklight=0-9
Language=English
DBLag_ms=180000
FrameTimeStep_us=10000
Ene`

## Artifacts

```
firmware/rc-110/fw4.14/container.bin       vendor container as shipped (rc-110z.bin)
firmware/rc-110/fw4.14/flash.bin           decoded flat flash image (base 0x08000000)
firmware/rc-110/fw4.14/blocks.json         per-block metadata
firmware/rc-110/fw4.14/listing.s           annotated Thumb-2 disassembly
firmware/rc-110/fw4.14/decompiled.c        Ghidra C decompilation, one block per function
firmware/rc-110/fw4.14/index.json          C file: function -> line range (upper-case hex keys)
firmware/rc-110/fw4.14/analysis/vectors.json interrupt vector table
firmware/rc-110/fw4.14/analysis/strings.json strings with addresses
firmware/rc-110/fw4.14/analysis/functions.json function index (callers, size, instructions)
firmware/rc-110/fw4.14/analysis/stats.json counts for the numbers above
firmware/rc-110/fw4.14/analysis/xrefs.json literal-pool cross-references
firmware/rc-110/fw4.14/analysis/callgraph.json reachability from each vector handler
firmware/rc-110/fw4.14/analysis/tables.json static {id, handler} dispatch tables
firmware/rc-110/fw4.14/analysis/verification.json device-vs-image byte comparisons
firmware/rc-110/fw4.14/analysis/capture.json live identity, virtual strings, parameter areas (step 2)
firmware/rc-110/fw4.14/analysis/container_check.json vendor-file vs device field matches (step 3)
firmware/rc-110/fw4.14/analysis/vsfr_readout.json live VSFR values, single-value form (tools)
firmware/rc-110/fw4.14/analysis/sweep_noarg.json which command ids answer, no argument
firmware/rc-110/fw4.14/analysis/sweep_witharg.json which command ids answer, with a u32 argument
firmware/rc-110/fw4.14/analysis/ghidra_listing.json SLEIGH listing + function ranges (step 6, feeds step 14)
firmware/rc-110/fw4.14/analysis/roundtrip.json L1: container re-encoded byte for byte (step 13)
firmware/rc-110/fw4.14/analysis/crosscheck.json L2: capstone vs SLEIGH agreement, four tiers (step 14)
firmware/rc-110/fw4.14/analysis/differential.json L4: Unicorn vs the Python models (step 15)
firmware/rc-110/fw4.14/analysis/formal.json L5: Z3 goals with their verdicts (step 16)
firmware/rc-110/fw4.14/analysis/confidence.json the five verification categories (step 17)
firmware/rc-110/fw4.14/analysis/confidence.md the same, readable form
firmware/rc-110/fw4.14/manifest.json       this build's identity + file checksums
firmware/rc-110/fw4.14/analysis/summary.md this file
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

