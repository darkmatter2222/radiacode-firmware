# RadiaCode-103G firmware analysis - `rc-103g/fw4.14`

Device: RadiaCode-103G, serial `-`, BLE `-`. Bootloader `-`, firmware `4.14`.

Target directory: `firmware/rc-103g/fw4.14` - every file below lives inside it. The active target is chosen by
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
| `0x0012` FW_IMAGE_GET_INFO | size `130444`, buffer `4096`, date_time `0x5AE742CF`, crc `0x1EB48B8A` |
| `0x0013` | `n/a` (block/frame count) |
| `0x081C` RD_FLASH area 0/1 | XOR-obfuscated `PublicAPI` struct (Borland LCG), device parameters |

Values in that table are the registry's (`pipeline/devices.json`), read from the container
header by step 3; this target has no live unit in `analysis/capture.json`.

The device exposes no image-read command (verified by a full `0x0000-0x0FFF` scan, with and
without a `u32` argument), so the image bytes come from the official `rc-103gz.bin` shipped in
`https://downloads.radiacode.com/EN/RadiaCode.apk` (`assets/HardSoft/`). Identity with the unit
in hand is proven by three independent matches: file length `130444`, header `date_time`
`0x5AE742CF`, whole-file CRC `0x1EB48B8A` - all equal to the device's own `0x0012` answer -
plus the in-image vendor-config text found byte-identically in the image
(see `analysis/verification.json`).

Memory model: the container addresses blocks from `0x08000000`, so the flat image spans
`0x08000000-0x0803CB00`; offsets `0x00000-0xFFFF` stay zero because the bootloader region
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
* Payload: LZSS, 2048-byte window pre-filled with `0x20`, initial index `2022`, flag bit 1 =
  literal, 0 = match with 11-bit offset + 4-bit length (+2).

## Decoded flash image

`firmware/rc-103g/fw4.14/flash.bin`: 248576 bytes (`0x08000000`-`0x0803CB00`), every block CRC verified.

| # | address | decompressed size | crc | instructions |
| --- | --- | --- | --- | --- |
| 0 | `0x08010000` | 0x7a00 (31232) | `20822ccf` | 11599 |
| 1 | `0x08017a00` | 0x5000 (20480) | `58005c1e` | 7737 |
| 2 | `0x0801ca00` | 0x5200 (20992) | `4251759c` | 8025 |
| 3 | `0x08021c00` | 0x4400 (17408) | `a07ada62` | 6623 |
| 4 | `0x08026000` | 0x7c00 (31744) | `1e9fcc2c` | 12086 |
| 5 | `0x0802dc00` | 0x4b00 (19200) | `7df44513` | 5306 |
| 6 | `0x08032700` | 0x6b00 (27392) | `4beb9581` | 10562 |
| 7 | `0x08039200` | 0x3900 (14592) | `2b5d80a9` | 5168 |

## Verification against the live device

## Core (Cortex-M4, ARMv7E-M)

Vector table at `0x08010000` (98 entries):

```
[ 0] InitialSP    0x20000800
[ 1] Reset        0x0803BA89
[ 2] NMI          0x080363FD
[ 3] HardFault    0x080363FF
[ 4] MemManage    0x08036401
[ 5] BusFault     0x08036403
[ 6] UsageFault   0x08036405
[ 7] Reserved7    0x00000000
[ 8] Reserved8    0x00000000
[ 9] Reserved9    0x00000000
[10] Reserved10   0x00000000
[11] SVCall       0x08036407
[12] DebugMon     0x08036409
[13] Reserved13   0x00000000
[14] PendSV       0x0803640B
[15] SysTick      0x0803640D
```

* Initial SP `not read`, reset handler `0x0803BA89`.
* All IRQ vectors collapse onto a single dispatcher (`see analysis/vectors.json`), i.e. one common IRQ entry.

## Decompile statistics

* Thumb-2 instructions decoded (capstone linear sweep): 66,570
* data words emitted as `.word` in the listing: 290, ascii lines: 740, zero fills: 1,190
* function candidates (vector table + `bl` targets + return-follows): 1865
* functions decompiled to C by Ghidra 12.2: 1894 (2 failures)
* ASCII strings harvested: 1911

### Call graph (direct `b`/`bl` edges from each vector handler)


1865 indexed functions, 99 reachable from a
vector handler, 1766 only reachable through tables/indirect calls.

| vector | handler | entry | reachable | depth |
| --- | --- | --- | --- | --- |
| 16 `IRQ0_WWDG` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 17 `IRQ1_PVD` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 18 `IRQ2_TAMP_STAMP` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 19 `IRQ3_RTC_WKUP` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 20 `IRQ4_FLASH` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 21 `IRQ5_RCC` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 22 `IRQ6_EXTI0` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |
| 29 `IRQ13_DMA1_CH2` | `0x0803C4F1` | `0x0803C4F0` | 34 | 8 |

### Static `{id, handler}` tables


8 runs of >= 4 `{u32 id, u32 handler}` pairs;
every handler (85) is present in the C output.

* `0x08036C10` - 44 entries, id `0x0`..`0xC18`, handlers `0x0802090C`..`0x08034CD6`
* `0x08020A18` - 10 entries, id `0x28F`..`0x2666`, handlers `0x08020944`..`0x08020936`
* `0x08038CEC` - 10 entries, id `0x1`..`0xB`, handlers `0x08034CEC`..`0x08034E28`
* `0x080384AC` - 7 entries, id `0x0`..`0x0`, handlers `0x080170B4`..`0x080174F2`
* `0x08039454` - 7 entries, id `0x5`..`0x30`, handlers `0x08034914`..`0x08034996`

### Most-called functions

| address | name | callers |
| --- | --- | --- |
| `0x08017FA8` | `sub_08017FA8` | 163 |
| `0x0801953C` | `sub_0801953C` | 110 |
| `0x08017FCC` | `sub_08017FCC` | 85 |
| `0x080194F4` | `sub_080194F4` | 63 |
| `0x08019AD6` | `sub_08019AD6` | 58 |
| `0x08025448` | `sub_08025448` | 51 |
| `0x0802008C` | `sub_0802008C` | 50 |
| `0x0801F920` | `sub_0801F920` | 46 |
| `0x08017FF0` | `sub_08017FF0` | 45 |
| `0x0802B0B8` | `sub_0802B0B8` | 42 |
| `0x08018074` | `sub_08018074` | 39 |
| `0x08024504` | `sub_08024504` | 39 |
| `0x0801D694` | `sub_0801D694` | 29 |
| `0x080183A2` | `sub_080183A2` | 28 |
| `0x0802D368` | `sub_0802D368` | 25 |

### Functions with literal-pool string references

Derived from `firmware/rc-103g/fw4.14/analysis/xrefs.json` (literal pointers into the string table):


| function | referenced strings (first) |
| --- | --- |
| `sub_08035AB6` | 12: `@ pG@m` |
| `sub_08027D06` | 5: `Error: S%d Packet or String size corrupted! PacketSize = 0x%` |
| `sub_08034F08` | 5: `BLE: HW error/Timer overrun` |
| `sub_08035D8E` | 4: ` pGA` |
| `sub_0803AF16` | 4: `pGpGb` |
| `sub_08034E78` | 3: `BLE: disconnected by reason 0x%0.2X` |
| `handler_reset` | 3: `HIIK / hB` |
| `sub_08028E40` | 2: `[VSFR_DEVICE_CTRL] / Addr=0x00000500 / Virtual=1 / Size=1 / [VSFR_DE` |
| `sub_0802BD18` | 2: `%02d:%02d:%02d` |
| `sub_08037278` | 2: `BhJ`pG8` |
| `sub_08039A3E` | 2: `pGpGb` |
| `sub_0803A598` | 2: ` pG; pG` |
| `sub_080165D8` | 1: ` pG@!` |
| `sub_08020A04` | 1: ``pG1I/KO` |
| `sub_08022E98` | 1: `BLE: Connection parameter update error #0x%0.2X! Interval is` |
| `sub_08024638` | 1: `%d message(s) lost!` |
| `sub_08024736` | 1: `%d, ` |
| `sub_08027086` | 1: `BLE: error packet received => %0.2X; %0.2X; %0.2X; %0.2X!` |

Ghidra left 2 stubs (`0x08016cc6`, `0x0802abf8`): data-table slots whose code is only in the listing.

### Notable strings

* `0x08019F1C` `RadiaCode-103G`
* `0x08027294` `CRC Error: 0x%08X != 0x%08X`
* `0x0802FB09` `
DispBacklight=0-9
Language=English
DBLag_ms=180000
FrameTimeStep_us=10000
Ene`

## Artifacts

```
firmware/rc-103g/fw4.14/container.bin      vendor container as shipped (rc-103gz.bin)
firmware/rc-103g/fw4.14/flash.bin          decoded flat flash image (base 0x08000000)
firmware/rc-103g/fw4.14/blocks.json        per-block metadata
firmware/rc-103g/fw4.14/listing.s          annotated Thumb-2 disassembly
firmware/rc-103g/fw4.14/decompiled.c       Ghidra C decompilation, one block per function
firmware/rc-103g/fw4.14/index.json         C file: function -> line range (upper-case hex keys)
firmware/rc-103g/fw4.14/analysis/vectors.json interrupt vector table
firmware/rc-103g/fw4.14/analysis/strings.json strings with addresses
firmware/rc-103g/fw4.14/analysis/functions.json function index (callers, size, instructions)
firmware/rc-103g/fw4.14/analysis/stats.json counts for the numbers above
firmware/rc-103g/fw4.14/analysis/xrefs.json literal-pool cross-references
firmware/rc-103g/fw4.14/analysis/callgraph.json reachability from each vector handler
firmware/rc-103g/fw4.14/analysis/tables.json static {id, handler} dispatch tables
firmware/rc-103g/fw4.14/analysis/verification.json device-vs-image byte comparisons
firmware/rc-103g/fw4.14/analysis/capture.json live identity, virtual strings, parameter areas (step 2)
firmware/rc-103g/fw4.14/analysis/container_check.json vendor-file vs device field matches (step 3)
firmware/rc-103g/fw4.14/analysis/vsfr_readout.json live VSFR values, single-value form (tools)
firmware/rc-103g/fw4.14/analysis/sweep_noarg.json which command ids answer, no argument
firmware/rc-103g/fw4.14/analysis/sweep_witharg.json which command ids answer, with a u32 argument
firmware/rc-103g/fw4.14/manifest.json      this build's identity + file checksums
firmware/rc-103g/fw4.14/analysis/summary.md this file
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
python pipeline/tools/lookup.py 0x080275C4   # ad-hoc query: function + callers + strings
python pipeline/tools/read_vsfrs.py          # live VSFR readout
```

Naming: the capstone index (`functions.json`, `xrefs.json`) uses `sub_XXXXXXXX`; the Ghidra C
uses `FUN_xxxxxxxx` (lower-case hex), `handler_*` for vector-table entries and
`tbl_<id>_<address>` for handlers found in a static `{id, handler}` table. `0x`-prefixed,
upper-case addresses in `index.json` map a function address to its line range in `decompiled.c`.

