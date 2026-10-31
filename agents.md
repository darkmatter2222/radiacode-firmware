# agents.md — working notes for this repo

Status: **complete**. Firmware extracted from a live RadiaCode-102 (read-only) and decompiled to C.
`README.md` = the full narrative (extraction, confidence, hardware, protocol, flows, capability matrix);
`firmware.md` = the firmware reference (§1-§26); `firmware/analysis/summary.md` = generated statistics;
this file = the short notes an agent needs to keep working without re-deriving anything.

## 1. Fixed facts (do not re-derive)

| fact | value |
| --- | --- |
| device | RadiaCode-102, serial `RC-102-008228`, BLE `52:43:06:60:20:24` |
| BLE transport | Nordic UART service `e63215e5-…fb901` (write `…e6`, notify `…e7`); frame = `u32 LE length` + `cmd(u16 LE) + 0x00 + seq` (`pipeline/rcble.py`, `pipeline/rcsession.py`) |
| firmware | v4.14, container `official/rc-102z.bin`, 130148 B, `date_time 0x5AE7428A`, crc32 `0x13095ABB`, `buffer_size 32768` |
| container | `Phyton\0\0`, 8 Mangle/LZSS blocks, header 52 B, every block CRC verified |
| flat image | `firmware/rc102_flash.bin`, 248320 B, `0x08000000`-`0x0803CA00` |
| MCU | STM32L4-class / Cortex-M4F, ARMv7E-M, Thumb-2; app base `0x08010000`, 98 vectors, `InitialSP 0x20000800`, `Reset 0x0803BA71` |
| counts | 66,745 decoded instructions, 69,209 listing lines, 1,867 function candidates, 1,906 strings, 291 `.word` + 736 `ascii` + 1,191 `.fill` + 242 `.byte` items |
| decompilation | `firmware/decompiled/rc102_flash.c`, 1,895 blocks / 70,679 lines (Ghidra 12.2: seeded 1,172, decompiled 1,893, failed 2) |
| callgraph | 90 handlers traced, 99 reachable, 1,768 orphans, deepest 33 functions at depth 7 (`Reset`) |
| tables | 8 static `{id, handler}` runs, largest 44, 85/85 handlers present in the C |
| answering ids | 13 of `0x0000`-`0x0FFF` (`protocol.ANSWERING`); `0x0824` = `RD_VIRT_SFR` takes the VSFR address, `0x0826` = `RD_VIRT_STRING` takes the VS id |
| device params | VS `0x002` = 3,256 B, byte-identical to the in-image blob at `0x0802F9F0` |
| record stream | VS `0x100`: 45-byte + 21-byte records alternating (66-byte frame), `firmware.md` §20 |

Identity of the image with the unit in hand is already proven twice: `analysis/container_check.json`
(size / date_time / crc against `0x0012`) and `analysis/verification.json` (+ the 3,256-byte config text).
Only read commands were ever issued except the two idempotent session writes `0x0007` (sign
`01 FF 12 FF`) and `0x0A04` (wall clock).

## 2. Running the pipeline

```powershell
python pipeline/run.py                     # steps 1-12 in order (device + network needed)
python pipeline/run.py --list              # the step table
python pipeline/run.py --only 1,4,5        # offline: self-test, decode, disassemble
python pipeline/run.py --only 3            # fetch the vendor container + match its fields
python pipeline/run.py --only 2            # live read-only capture   (--sweep adds the id sweep)
python pipeline/run.py --only 6            # Ghidra headless (needs ghidra_12.2_PUBLIC/ + jdk-25.0.5+8/)
python pipeline/run.py --from 7            # index, xrefs, callgraph, tables, verify, report
```

Run everything **from the repo root** (steps open `firmware/...` relative paths). `pipeline/tools/*.py`
each insert their parent directory on `sys.path`, so `import protocol`, `rcble`, `rcsession`, `rcfmt`
work from any cwd.

## 3. Querying the results

```powershell
python pipeline/tools/lookup.py 0x0803BA70   # owning function + C lines + callers + dispatch ids + strings + listing
python pipeline/tools/read_vsfrs.py           # live VSFR readout -> analysis/vsfr_readout.json
python pipeline/tools/probe.py                # single live command, raw hex
python pipeline/tools/debug_graph.py 0x080275C4  # call-graph neighbourhood of one function
```

To read a function's C, use the line range from `firmware/decompiled/index.json` (keys are `0x`-prefixed
upper-case addresses) - the C file is 1.7 MB, do not read it whole.

| need | file | key |
| --- | --- | --- |
| function -> C lines | `firmware/decompiled/index.json` | `functions[].address` / `line` / `end_line` |
| callers, size, instruction count | `firmware/analysis/functions.json` | array of 1,867, `callers` are addresses |
| string -> referencing function | `firmware/analysis/xrefs.json` | literal-pool pointers (87 reached, 38 functions) |
| vector table | `firmware/analysis/vectors.json` | index = vector number |
| reachability from a handler | `firmware/analysis/callgraph.json` | `handler_*` |
| command-id dispatch tables | `firmware/analysis/tables.json` | `tables[].entries[].{id, handler, handler_name}` |
| device-vs-image equality | `firmware/analysis/verification.json` | `checks.*` (all `true`) |
| live identity / strings / areas | `firmware/analysis/device_capture.json` | `identity`, `virtual_strings`, `flash_areas` |
| container-vs-device field matches | `firmware/analysis/container_check.json` | `…_matches_device` flags |
| live VSFR values | `firmware/analysis/vsfr_readout.json` | `single_nonzero`, `batch_shapes` |
| which ids answer | `firmware/analysis/sweep_noarg.json`, `sweep_witharg.json` | keyed by `0x…` id |
| per-block decode metadata | `firmware/rc102_blocks.json` | `blocks[].{address, stored, decompressed, crc}` |
| raw live reply hex (pre-decode evidence) | `firmware/analysis/probe_raw.json`, `probe_shapes.json`, `probe_records.json`, `probe_vsmap.json` | keyed by command/VS id |
| protocol constants in code | `pipeline/protocol.py` | `CMD`, `ANSWERING`, `VS`, `CHANNELS`, decoders |

## 4. Naming conventions (intentionally different per tool)

* `sub_XXXXXXXX` — capstone index (`functions.json`, `xrefs.json`), upper-case hex.
* `FUN_xxxxxxxx` — Ghidra C output, lower-case hex.
* `handler_<n>_<name>` — entries seeded from the vector table (`handler_1_reset`).
* `tbl_<id>_<address>` — handlers reached only from a static `{u32 id, u32 handler}` table.

## 5. Gotchas

* Ghidra 12.2 needs JDK 25+: `step6_decompile.py` sets `JAVA_HOME` from `jdk-*/` next to the repo root;
  the post-script is `pipeline/scripts/DumpC.java` (passed with `-scriptPath pipeline\scripts`).
* Import must use `-loader-baseAddr 0x08000000` with `-processor "ARM:LE:32:v7"`; the C file uses the
  `0x08000000` numbering, image file offsets are `addr - 0x08000000`.
* Offsets `0x00000`-`0xFFFFF` are zero-filled (the bootloader is not in this container) - not missing data.
* The linear sweep prints data as `.word` / `ascii` / `.fill` lines, so short sequences like `00 bf` ->
  `nop` and literal pools decode as odd instructions (`cdp2`, `movs r0, r0`). Trust the mnemonic only
  inside known function ranges.
* Ghidra left 2 stubs at `0x08016cc6` and `0x0802abf8`: data-table slots, code only in the listing.
  Vector IRQ handlers collapse onto few real entries plus the self-loop at `0x0803C4D9`, so per-IRQ bodies
  come from `tables.json`, not from the call graph.
* Container obfuscation: per block `size ^ 0xCE27A932`, `addr ^ 0xB2D5A864`; Mangle is a 48-round Feistel
  over 8-byte LE blocks with 4 round keys; CRC is MPEG-2 (`0x04C11DB7`, no reflection, init `0xFFFFFFFF`,
  4-byte LE chunks); payload is LZSS (2048-byte window pre-filled with `0x20`, initial index 2022).
  All of it lives in `pipeline/rcfmt.py`, checked by `pipeline/step1_validate.py`.
* `RD_FLASH_AREA` (`0x081C`) replies `{u32 status, u32 seed, u32 enc_size, enc[]}` with Borland-LCG XOR
  (`seed*0x015A4E35+1`, keystream `(seed>>16)&0x7FFF`) - `protocol.borland_xor` / `decode_flash_area`.
* No raw memory-read command exists (two full `0x0000`-`0x0FFF` sweeps), so bulk bytes come only from
  `official/*.bin`; the device confirms the `size / date_time / crc32` triple and serves the two small
  XOR-obfuscated areas.
* At idle the measurement/system VSFR block answers the bare `00000000` word (rare-data group, 3-min
  `DBLag_ms`); do not read that as "the sensor is absent".
* `0x082A` (`RD_VIRT_SFR_BATCH`) only answers for the plain `u32` address form; `0x0824` with the 91-entry
  index form returns zeros on this build.

## 6. Landmark addresses (already resolved - do not re-derive)

| address | what |
| --- | --- |
| `0x0803BA70` | reset: SP init -> `0x08038A58` clock init -> `0x0803C458` event pump |
| `0x08038A58` | RCC-style bring-up: oscillator enable (`|= 0xF00000`), PLL word `0x1000`, clock select |
| `0x0803C458` | event pump: spin on `0x0803AEE0` for a message block, then tail-jump to `0x08023F92` (pool `free`) |
| `0x0803C4B2` / `0x0803C4B6`+ | shared IRQ entry and the `movs r1,#irq; b` trampolines |
| `0x0803C4D9` | 4-byte self-loop: idle/trap, target of every unused vector entry |
| `0x0801F464` / `0x0801F474` | `Start Main loop` and the driver-table dispatcher (`flags & 0x7000`, vtable slot `+0x18`) |
| `0x08027D06` | frame validator / item reader (loops `count` times calling `0x080275C4`) |
| `0x080275C4` | per-item accessor: `subs`/`beq` chain over VSFR addresses `0x500`-`0x700`, `0x8000`-`0x8035`, `0xC000`-`0xC200`, `0xFFFF0000`+ |
| `0x08028E40` | serialises the `[DeviceParams]` / `[DataStructure]` / `[VSFR_*]` text |
| `0x0802F9F0` | 3,256-byte `[DeviceParams]`+`[DataStructure]` blob (byte-identical to live VS `0x002`) |
| `0x080306AC` | VSFR map, 67 records, 4,587 bytes |
| `0x08035A64` | 91-entry `{u32 id, u32 getter, u32 setter}` item table, ids `0x00`-`0x5A` |
| `0x08036C10` | 44-pair `{u32 id, u32 handler}` internal registry (not the wire ids) |
| `0x08027DA0`, `0x08028EEC` | the `0xFF12FF01` exchange-sign constant |
| `0x08027294` | `CRC Error: 0x%08X != 0x%08X` |
| `0x08037267`-`0x08037354` | the five `Error: S%d …` framing strings |
| `0x0801F424`, `0x0802ACD8`, `0x0802D748` | CRC-32/MPEG-2 polynomial tables |

## 7. Suggested next steps (nothing pending for the stated goal)

* Name hot functions from the "Most-called" list in `firmware/analysis/summary.md` (`0x08017FA8` has 163
  callers, `0x0801953C` 110).
* Use `tables.json` dispatch ids to map wire ids (`0x0807`, `0x081C`, `0x0A04`) to handler addresses.
* Structure the 448-byte `0x081C` area 1 record against the `PublicAPI`/`VS CONFIGURATION` text; the
  76-byte `0x0F0` record still has 5 unidentified words (`firmware.md` §21).
* Re-run `pipeline/tools/read_vsfrs.py` while a measurement is running (`VSFR_MS_RUN` = 1) to catch the
  `0x8000`-`0x8035` block non-zero and confirm each `DType`/`RType` encoding.
