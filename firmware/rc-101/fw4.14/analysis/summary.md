# RadiaCode-101 firmware analysis - `rc-101/fw4.14`

Device: RadiaCode-101, serial `-`, BLE `-`. Bootloader `-`, firmware `4.14`.

Target directory: `firmware/rc-101/fw4.14` - every file below lives inside it. The active target is chosen by
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
| `0x0012` FW_IMAGE_GET_INFO | size `130388`, buffer `4096`, date_time `0x5AE74263`, crc `0x0921BCFB` |
| `0x0013` | `n/a` (block/frame count) |
| `0x081C` RD_FLASH area 0/1 | XOR-obfuscated `PublicAPI` struct (Borland LCG), device parameters |

Values in that table are the registry's (`pipeline/devices.json`), read from the container
header by step 3; this target has no live unit in `analysis/capture.json`.

The device exposes no image-read command (verified by a full `0x0000-0x0FFF` scan, with and
without a `u32` argument), so the image bytes come from the official `rc-101_v01z.bin` shipped in
`https://downloads.radiacode.com/EN/RadiaCode.apk` (`assets/HardSoft/`). Identity with the unit
in hand is proven by three independent matches: file length `130388`, header `date_time`
`0x5AE74263`, whole-file CRC `0x0921BCFB` - all equal to the device's own `0x0012` answer -
plus the in-image vendor-config text found byte-identically in the image
(see `analysis/verification.json`).

Memory model: the container addresses blocks from `0x08000000`, so the flat image spans
`0x08000000-0x0803CE00`; offsets `0x00000-0xFFFF` stay zero because the bootloader region
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

`firmware/rc-101/fw4.14/flash.bin`: 249344 bytes (`0x08000000`-`0x0803CE00`), every block CRC verified.

| # | address | decompressed size | crc | instructions |
| --- | --- | --- | --- | --- |
| 0 | `0x08010000` | 0x4100 (16640) | `6bd819e4` | 6201 |
| 1 | `0x08014100` | 0x4100 (16640) | `f2f5cfb2` | 6183 |
| 2 | `0x08018200` | 0x4500 (17664) | `f0e5c748` | 6694 |
| 3 | `0x0801c700` | 0x6900 (26880) | `a0a2a02b` | 10191 |
| 4 | `0x08023000` | 0x6700 (26368) | `d9522c48` | 10143 |
| 5 | `0x08029700` | 0x7300 (29440) | `aeca6964` | 10183 |
| 6 | `0x08030a00` | 0x7b00 (31488) | `98ce6c46` | 11203 |
| 7 | `0x08038500` | 0x4900 (18688) | `41377b5a` | 6926 |

## Verification against the live device

## Core (Cortex-M4, ARMv7E-M)

Vector table at `0x08010000` (98 entries):

```
[ 0] InitialSP    0x20000800
[ 1] Reset        0x0803BB55
[ 2] NMI          0x08035B89
[ 3] HardFault    0x08035B8B
[ 4] MemManage    0x08035B8D
[ 5] BusFault     0x08035B8F
[ 6] UsageFault   0x08035B91
[ 7] Reserved7    0x00000000
[ 8] Reserved8    0x00000000
[ 9] Reserved9    0x00000000
[10] Reserved10   0x00000000
[11] SVCall       0x08035B93
[12] DebugMon     0x08035B95
[13] Reserved13   0x00000000
[14] PendSV       0x08035B97
[15] SysTick      0x08035B99
```

* Initial SP `not read`, reset handler `0x0803BB55`.
* All IRQ vectors collapse onto a single dispatcher (`see analysis/vectors.json`), i.e. one common IRQ entry.

## Decompile statistics

* Thumb-2 instructions decoded (capstone linear sweep): 67,163
* data words emitted as `.word` in the listing: 323, ascii lines: 733, zero fills: 1,280
* function candidates (vector table + `bl` targets + return-follows): 1802
* functions decompiled to C by Ghidra 12.2: 1832 (15 failures)
* ASCII strings harvested: 1893

### Call graph (direct `b`/`bl` edges from each vector handler)


1802 indexed functions, 115 reachable from a
vector handler, 1687 only reachable through tables/indirect calls.

| vector | handler | entry | reachable | depth |
| --- | --- | --- | --- | --- |
| 28 `IRQ12_DMA1_CH1` | `0x08035C01` | `0x08035C00` | 45 | 5 |
| 82 `IRQ66_LPTIM3` | `0x08035CAB` | `0x08035CAA` | 45 | 5 |
| 16 `IRQ0_WWDG` | `0x0803C851` | `0x0803C850` | 34 | 8 |
| 17 `IRQ1_PVD` | `0x0803C851` | `0x0803C850` | 34 | 8 |
| 18 `IRQ2_TAMP_STAMP` | `0x0803C851` | `0x0803C850` | 34 | 8 |
| 19 `IRQ3_RTC_WKUP` | `0x0803C851` | `0x0803C850` | 34 | 8 |
| 20 `IRQ4_FLASH` | `0x0803C851` | `0x0803C850` | 34 | 8 |
| 21 `IRQ5_RCC` | `0x0803C851` | `0x0803C850` | 34 | 8 |

### Static `{id, handler}` tables


6 runs of >= 4 `{u32 id, u32 handler}` pairs;
every handler (32) is present in the C output.

* `0x080205D8` - 10 entries, id `0x28F`..`0x2666`, handlers `0x08020504`..`0x080204F6`
* `0x080229DC` - 7 entries, id `0x2172`..`0x0`, handlers `0x080227E6`..`0x08022860`
* `0x08037C68` - 7 entries, id `0x0`..`0x0`, handlers `0x0801702E`..`0x0801741A`
* `0x080393EC` - 6 entries, id `0x1`..`0xC16`, handlers `0x080369E8`..`0x08036A46`
* `0x08037C28` - 5 entries, id `0xA4`..`0xA3D`, handlers `0x0801709C`..`0x080171EC`

### Most-called functions

| address | name | callers |
| --- | --- | --- |
| `0x08017EEC` | `sub_08017EEC` | 164 |
| `0x08019358` | `sub_08019358` | 108 |
| `0x08017F10` | `sub_08017F10` | 87 |
| `0x08019310` | `sub_08019310` | 62 |
| `0x080198F2` | `sub_080198F2` | 57 |
| `0x0801B458` | `sub_0801B458` | 51 |
| `0x0801FC4C` | `sub_0801FC4C` | 50 |
| `0x0801F4E0` | `sub_0801F4E0` | 46 |
| `0x08017F34` | `sub_08017F34` | 45 |
| `0x08023F94` | `sub_08023F94` | 40 |
| `0x08017FB8` | `sub_08017FB8` | 39 |
| `0x0802ABB0` | `sub_0802ABB0` | 36 |
| `0x0802D3D4` | `sub_0802D3D4` | 31 |
| `0x080182E6` | `sub_080182E6` | 28 |
| `0x0801D4F8` | `sub_0801D4F8` | 26 |

### Functions with literal-pool string references

Derived from `firmware/rc-101/fw4.14/analysis/xrefs.json` (literal pointers into the string table):


| function | referenced strings (first) |
| --- | --- |
| `sub_08034D76` | 14: `@ pG@m` |
| `sub_0802792E` | 5: `Error: S%d Packet or String size corrupted! PacketSize = 0x%` |
| `sub_08036B34` | 5: `BLE: HW error/Timer overrun` |
| `sub_0803503A` | 4: ` pGp` |
| `sub_0803AF02` | 4: `pGpGb` |
| `handler_reset` | 4: `HIIK / hB` |
| `sub_08036AA4` | 3: `BLE: disconnected by reason 0x%0.2X` |
| `sub_080240C8` | 2: `%d message(s) lost!` |
| `sub_08028A06` | 2: `[VSFR_DEVICE_CTRL] / Addr=0x00000500 / Virtual=1 / Size=1 / [VSFR_DE` |
| `sub_0802B810` | 2: `%02d:%02d:%02d` |
| `sub_0802F1C4` | 2: `xpG@xpG` |
| `sub_08034F6E` | 2: ` pGA` |
| `sub_08036CDA` | 2: `BhJ`pG8` |
| `sub_0803701A` | 2: ` pG0` |
| `sub_080395F6` | 2: `pGpGb` |
| `sub_0803A310` | 2: ` pG; pG` |
| `sub_080205C4` | 1: ``pG1I/KO` |
| `sub_08022928` | 1: `BLE: Connection parameter update error #0x%0.2X! Interval is` |

Ghidra left 15 stubs (`0x0802a6f0`, `0x08034cf2`, `0x08034cfe`, `0x08034d0a`, `0x08034d16`, `0x08034d22`, `0x08034d2e`, `0x08034d3a`, `0x08034d46`, `0x08034d52`, `0x08034d5e`, `0x08034d6a`, `0x08034d76`, `0x08034f56`, `0x08034f62`): data-table slots whose code is only in the listing.

### Notable strings

* `0x08019D3C` `RadiaCode-101`
* `0x08026F18` `CRC Error: 0x%08X != 0x%08X`
* `0x0802F5C7` `
DBLag_ms=180000
FrameTimeStep_us=10000
EnergyCompensation=1
SpecFormatVersion`

## Artifacts

```
firmware/rc-101/fw4.14/container.bin       vendor container as shipped (rc-101_v01z.bin)
firmware/rc-101/fw4.14/flash.bin           decoded flat flash image (base 0x08000000)
firmware/rc-101/fw4.14/blocks.json         per-block metadata
firmware/rc-101/fw4.14/listing.s           annotated Thumb-2 disassembly
firmware/rc-101/fw4.14/decompiled.c        Ghidra C decompilation, one block per function
firmware/rc-101/fw4.14/index.json          C file: function -> line range (upper-case hex keys)
firmware/rc-101/fw4.14/analysis/vectors.json interrupt vector table
firmware/rc-101/fw4.14/analysis/strings.json strings with addresses
firmware/rc-101/fw4.14/analysis/functions.json function index (callers, size, instructions)
firmware/rc-101/fw4.14/analysis/stats.json counts for the numbers above
firmware/rc-101/fw4.14/analysis/xrefs.json literal-pool cross-references
firmware/rc-101/fw4.14/analysis/callgraph.json reachability from each vector handler
firmware/rc-101/fw4.14/analysis/tables.json static {id, handler} dispatch tables
firmware/rc-101/fw4.14/analysis/verification.json device-vs-image byte comparisons
firmware/rc-101/fw4.14/analysis/capture.json live identity, virtual strings, parameter areas (step 2)
firmware/rc-101/fw4.14/analysis/container_check.json vendor-file vs device field matches (step 3)
firmware/rc-101/fw4.14/analysis/vsfr_readout.json live VSFR values, single-value form (tools)
firmware/rc-101/fw4.14/analysis/sweep_noarg.json which command ids answer, no argument
firmware/rc-101/fw4.14/analysis/sweep_witharg.json which command ids answer, with a u32 argument
firmware/rc-101/fw4.14/manifest.json       this build's identity + file checksums
firmware/rc-101/fw4.14/analysis/summary.md this file
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

