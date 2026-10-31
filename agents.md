# agents.md — working notes for this repo

Status: **complete** for `rc-102/hw1-fw4.14` (the reference build), container + decode + disassembly
for the other five registered builds. `README.md` = the full narrative (extraction, confidence,
hardware, protocol, flows, capability matrix, target registry); `firmware.md` = the firmware reference
(§1-§27, the last section being the five verification layers); `firmware/<target>/analysis/summary.md` = generated statistics per build; this file = the
short notes an agent needs to keep working without re-deriving anything.

## 1. Layout and targets

One directory per build: `firmware/<model>/<hw+fw version>/`, e.g. `firmware/rc-102/hw1-fw4.14/`.
The registry `pipeline/devices.json` is the single source of truth; `pipeline/config.py` turns the
active key into every path, so no step or tool contains a literal path. Active target = `--device` /
`--all-devices` on `run.py`, else `RC_TARGET`, else the registry's `default`.

```
firmware/rc-102/hw1-fw4.14/
├── rc-102z.bin          vendor container, exactly as shipped in the APK
├── flash.bin            decoded flat image, base 0x08000000
├── blocks.json          per-block address / stored / decompressed / crc
├── listing.s            capstone Thumb-2 listing
├── decompiled.c         Ghidra C, one /* ===== FUN_… @ addr ===== */ block per function
├── index.json           function -> line range inside decompiled.c
├── manifest.json        identity + sha256 of the six files above (step 12)
├── ghidra_proj/         Ghidra cache (gitignored)
└── analysis/            stats, vectors, strings, functions, xrefs, callgraph, tables,
                         capture, container_check, verification, vsfr_readout,
                         roundtrip, crosscheck, differential, formal, confidence,
                         sweep_{noarg,witharg}, probe_*.json, summary.md
```

| target | device | fw | state |
| --- | --- | --- | --- |
| `rc-102/hw1-fw4.14` | RadiaCode-102 (hw 1) | 4.14 | full: steps 1-17 (2 and 11 need the unit powered), the reference build |
| `rc-101/fw4.14` | RadiaCode-101 | 4.14 | steps 1-17, no live unit (2 and 11 self-skip) |
| `rc-103/fw4.14` | RadiaCode-103 | 4.14 | same |
| `rc-103g/fw4.14` | RadiaCode-103G | 4.14 | same |
| `rc-110/fw4.14` | RadiaCode-110 | 4.14 | same |
| `rc-410/fw4.16` | RadiaCode-410 | 4.16 | same |

## 2. Fixed facts for `rc-102/hw1-fw4.14` (do not re-derive)

| fact | value |
| --- | --- |
| device | RadiaCode-102, serial `RC-102-008228`, BLE `52:43:06:60:20:24`, hw `1`, boot `4.0` |
| BLE transport | Nordic UART service `e63215e5-…fb901` (write `…e6`, notify `…e7`); frame = `u32 LE length` + `cmd(u16 LE) + 0x00 + seq` (`pipeline/rcble.py`, `pipeline/rcsession.py`) |
| firmware | v4.14, container `rc-102z.bin` (in the target dir), 130148 B, `date_time 0x5AE7428A` (MS-DOS packed → 2025-07-07 08:20:20), crc32 `0x13095ABB`, `buffer_size 32768` |
| container | `Phyton\0\0`, 8 Mangle/LZSS blocks, header 52 B, every block CRC verified |
| flat image | `flash.bin`, 248320 B, `0x08000000`-`0x0803CA00` |
| MCU | STM32L4-class / Cortex-M4F, ARMv7E-M, Thumb-2; app base `0x08010000`, 98 vectors, `InitialSP 0x20000800`, `Reset 0x0803BA71` |
| counts | 66,745 decoded instructions, 69,209 listing lines, 1,867 function candidates, 1,906 strings, 291 `.word` + 736 `ascii` + 1,191 `.fill` + 242 `.byte` items |
| decompilation | `decompiled.c`, 1,895 blocks / 70,677 lines (Ghidra 12.2: seeded 1,172, decompiled 1,893, failed 2) |
| callgraph | 90 handlers traced, 99 reachable, 1,768 orphans, deepest 33 functions at depth 7 (`Reset`) |
| tables | 8 static `{id, handler}` runs, largest 44, 85/85 handlers present in the C |
| answering ids | 13 of `0x0000`-`0x0FFF` (`protocol.ANSWERING`); `0x0824` = `RD_VIRT_SFR` takes the VSFR address, `0x0826` = `RD_VIRT_STRING` takes the VS id |
| device params | VS `0x002` = 3,256 B, byte-identical to the in-image blob at `0x0802F9F0` |
| record stream | VS `0x100`: 45-byte + 21-byte records alternating (66-byte frame), `firmware.md` §20 |

Identity of the image with the unit in hand is already proven twice: `analysis/container_check.json`
(size / date_time / crc against `0x0012`, plus the registry cross-check) and
`analysis/verification.json` (+ the 3,256-byte config text, 12/12 checks `true`). Only read commands
were ever issued except the two idempotent session writes `0x0007` (sign `01 FF 12 FF`) and `0x0A04`
(wall clock).

Per-target numbers live in each `analysis/stats.json` (instructions, functions, strings, listing
lines) and `manifest.json` (identity + checksums); the cross-target table is §3.1 of `README.md`.

## 3. Running the pipeline

```powershell
python pipeline/run.py                          # steps 1-17 for the default target
python pipeline/run.py --list                   # targets + step table
python pipeline/run.py --all-devices            # every registered build
python pipeline/run.py --device rc-110/fw4.14   # one build
python pipeline/run.py --only 1,4,5             # offline: self-test, decode, disassemble
python pipeline/run.py --only 3                 # fetch containers + match their fields
python pipeline/run.py --only 2                 # live read-only capture (--sweep adds the id sweep)
python pipeline/run.py --only 6                 # Ghidra headless (needs ghidra_12.2_PUBLIC/ + jdk-25.0.5+8/)
python pipeline/run.py --from 7                 # index, xrefs, callgraph, tables, verify, report
python pipeline/run.py --only 13,14,15,16,17    # the verification layers only (all offline)
```

Run from the repo root (steps open paths relative to it); `run.py` chdirs there itself and passes the
target to each step through `RC_TARGET`. `pipeline/tools/*.py` insert `pipeline/` on `sys.path`, so
`import config`, `protocol`, `rcble`, `rcsession`, `rcfmt` work from any cwd; select the build they read
with the environment variable - `$env:RC_TARGET='rc-410/fw4.16'` in PowerShell, `RC_TARGET=rc-410/fw4.16`
in bash - or use `run.py --device <key>`, which works in every shell.

Steps 13-17 are the verification layers, and they run without the unit:

| layer | step | helper | needs | note |
| --- | --- | --- | --- | --- |
| L1 container byte-exactness | 13 | `rcfmt.reencode_file` | - | `recompress=False` isolates header + crypto + layout; `True` also exercises `rcfmt.lzss_compress` |
| L2 cross-decoder agreement | 14 | - | `analysis/ghidra_listing.json` (step 6) | skips itself (exit 0) when that file is absent |
| L4 differential execution | 15 | `emulate.py` (Unicorn) + `models.py` | flash image | one case per transcribed routine, gated by a 16-byte signature |
| L5 formal checks | 16 | `models.py` | `z3-solver` | bit-vector goals only, side-effect-free routines only |
| roll-up | 17 | - | the JSON files above | five categories, `analysis/confidence.{json,md}` |

## 4. Querying the results

```powershell
python pipeline/tools/lookup.py 0x0803BA70        # default target: function + C lines + callers + strings
$env:RC_TARGET='rc-410/fw4.16'; python pipeline/tools/lookup.py 0x08010188   # another build
python pipeline/tools/read_vsfrs.py               # live VSFR readout -> analysis/vsfr_readout.json
python pipeline/tools/analyze_official.py         # every registered container, one JSON line each
python pipeline/tools/probe.py                    # single live command, raw hex
python pipeline/tools/debug_graph.py              # call-graph neighbourhood of the reset handler
```

To read a function's C, use the line range from `index.json` (keys are `0x`-prefixed upper-case
addresses) - `decompiled.c` is ~1.7 MB, do not read it whole.

Paths below are relative to the target directory (`firmware/<model>/<hw+fw>/`):

| need | file | key |
| --- | --- | --- |
| function -> C lines | `index.json` | `functions[].address` / `line` / `end_line` |
| callers, size, instruction count | `analysis/functions.json` | array of 1,867, `callers` are addresses |
| string -> referencing function | `analysis/xrefs.json` | literal-pool pointers (87 reached, 38 functions) |
| vector table | `analysis/vectors.json` | index = vector number |
| reachability from a handler | `analysis/callgraph.json` | `handler_*` |
| command-id dispatch tables | `analysis/tables.json` | `tables[].entries[].{id, handler, handler_name}` |
| device-vs-image equality | `analysis/verification.json` | `checks.*` (all `true`), `c_coverage` |
| live identity / strings / areas | `analysis/capture.json` | `identity`, `virtual_strings`, `flash_areas` |
| container-vs-device field matches | `analysis/container_check.json` | `…_matches_device` flags |
| L1 re-encode byte-exactness | `analysis/roundtrip.json` | `carried.{byte_identical,bytes_matched,header_crc32_match}`, `carried.blocks_*`, `lzss.{decode_identical,stream_identical,tokens_identical}`, `byte_exact` |
| L2 per-instruction agreement | `analysis/crosscheck.json` | `tiers.{identical,format_only,pc_relative,semantic}`, `agreement`, `only_capstone`, `only_ghidra`, `examples.semantic[]` |
| L4 native-vs-Python execution | `analysis/differential.json` | `cases[].{name,addr,instructions,native_r0,model_r0,r0_match,writes_native,writes_model,write_bytes_match}`, `format[].{model,vectors,passed}` |
| L5 proofs | `analysis/formal.json` | `checks[].{check,status,premises}`, `proved` / `counterexamples` / `unknown` |
| the five-category roll-up | `analysis/confidence.json` (+ `.md`) | `categories.{byte_matched,formally_verified,tested,preserved_unchanged}`, `unresolved[]` |
| live VSFR values | `analysis/vsfr_readout.json` | `single_nonzero`, `batch_shapes` |
| which ids answer | `analysis/sweep_noarg.json`, `sweep_witharg.json` | keyed by `0x…` id |
| per-block decode metadata | `blocks.json` | `blocks[].{addr, stored_size, plain_size, crc}` |
| this build's identity + checksums | `manifest.json` | `target`, `mcu`, `expected`, `files.*` |
| raw live reply hex (pre-decode evidence) | `analysis/probe_raw.json`, `probe_shapes.json`, `probe_records.json`, `probe_vsmap.json` | keyed by command/VS id |
| registry / constants in code | `pipeline/devices.json`, `pipeline/protocol.py` | targets; `CMD`, `ANSWERING`, `VS`, decoders |

## 5. Naming conventions (intentionally different per tool)

* `sub_XXXXXXXX` — capstone index (`analysis/functions.json`, `xrefs.json`), upper-case hex.
* `FUN_xxxxxxxx` — Ghidra C output, lower-case hex.
* `handler_<n>_<name>` — entries seeded from the vector table (`handler_1_reset`).
* `tbl_<id>_<address>` — handlers reached only from a static `{u32 id, u32 handler}` table.

## 6. Gotchas

* Ghidra 12.2 needs JDK 25+: `step6_decompile.py` sets `JAVA_HOME` from `jdk-*/` next to the repo root;
  the post-script is `pipeline/scripts/DumpC.java`, passed with `-scriptPath pipeline\scripts` and one
  script argument - the target directory - which is where it writes `decompiled.c`.
* Import must use `-loader-baseAddr 0x08000000` with `-processor "ARM:LE:32:v7"` and `-overwrite`
  (re-importing into an existing per-target project); the C file uses the `0x08000000` numbering,
  image file offsets are `addr - 0x08000000`.
* Offsets `0x00000`-`0xFFFFF` are zero-filled (the bootloader is not in this container) - not missing data.
* The linear sweep prints data as `.word` / `ascii` / `.fill` lines, so short sequences like `00 bf` ->
  `nop` and literal pools decode as odd instructions (`cdp2`, `movs r0, r0`). Trust the mnemonic only
  inside known function ranges.
* Ghidra left 2 stubs at `0x08016cc6` and `0x0802abf8`: data-table slots, code only in the listing.
  Vector IRQ handlers collapse onto few real entries plus the self-loop at `0x0803C4D9`, so per-IRQ
  bodies come from `tables.json`, not from the call graph.
* Container obfuscation: per block `size ^ 0xCE27A932`, `addr ^ 0xB2D5A864`; Mangle is a 48-round Feistel
  over 8-byte LE blocks with 4 round keys; CRC is the STM32 hardware-CRC semantics (32-bit LE words,
  MSB-first, poly `0x04C11DB7`, init `0xFFFFFFFF`, no final XOR, a trailing partial word zero-padded),
  which is the MPEG-2 table in the image; payload is LZSS (2048-byte window pre-filled with `0x20`).
  All of it lives in `pipeline/rcfmt.py`, checked by `pipeline/step1_validate.py`. The constants are
  `WINDOW_SIZE 2048` (`OFFSET_BITS 11`), `WINDOW_INITIAL_INDEX 2031` (`2048-0x10-1`), `WINDOW_FILL 0x20`,
  match length `2..17` (`MAX_UNCODED 2`, `LENGTH_BITS 4`), MSB-first bit order; the slot of output index
  `k` is `(2031 + k) mod 2048`.
* `date_time` is MS-DOS packed (`((year-1980)<<9)|month<<5|day` high half, `hour<<11|min<<5|sec/2`
  low half), **not** a Unix epoch - `rcfmt._decode_datetime`.
* `RD_FLASH_AREA` (`0x081C`) replies `{u32 status, u32 seed, u32 enc_size, enc[]}` with Borland-LCG XOR
  (`seed*0x015A4E35+1`, keystream the low 8 bits of `seed>>16`, one continuous state: size word first,
  payload after) - `protocol.borland_xor` / `decode_flash_area`.
* No raw memory-read command exists (two full `0x0000`-`0x0FFF` sweeps), so bulk bytes come only from
  the vendor containers; the device confirms the `size / date_time / crc32` triple and serves the two
  small XOR-obfuscated areas.
* At idle the measurement/system VSFR block answers the bare `00000000` word (rare-data group, 3-min
  `DBLag_ms`); do not read that as "the sensor is absent".
* `0x082A` (`RD_VIRT_SFR_BATCH`) only answers for the plain `u32` address form; `0x0824` with the 91-entry
  index form returns zeros on this build.
* Steps 2 and 11 exit `0` when the target has no `ble_address`, and steps 7/10/12 tolerate a missing
  `decompiled.c`, so partially processed targets stay coherent — a non-zero exit is a real failure.
* Verification layers: `emulate.py` maps one power-of-two block per region (Unicorn rejects overlapping
  or non-power-of-two maps) - a single `0x10000` block at `0x1FFF0000` covers the VSFR area - and its
  `on_read_unmapped` hook must `return True`, otherwise the fetch of the sentinel LR is reported as a fault.
* In the differential harness a preset must go in through `Mem.poke()` (not recorded); `Mem.write()` is
  what the comparison treats as a memory effect. Both sides exclude `emulate.STACK_RANGE`
  (`0x20007000`-`0x20008000`), the slots the ABI owns.
* Function cases only run when the 16 bytes at the routine address equal `models.SIGNATURES`, so a build
  whose code moved prints `0/0` cases (rc-101, rc-110, rc-410 today) - that is the honest answer, not a skip.
* z3 5.3.3: the unsigned ops are `UREM`/`UDIV` (no `Urem`), `Expr` has no `is_value`, and `<=` on a
  `BitVec` is the *signed* comparison - use `z3.ULE` for sizes and offsets.
* The Borland keystream byte is 8 bits wide (`(seed >> 16) & 0xFF`); step 15 proves it by decoding the
  captured `0x081C` replies both ways and requiring the 8-bit form to leave more `0x00`/`0xFF` padding.
* Step 14 self-skips (exit `0`) without `analysis/ghidra_listing.json`. To regenerate that file alone:
  `analyzeHeadless <ghidra_proj> RC102 -process flash.bin -noanalysis -scriptPath pipeline\scripts -postScript DumpListing.java <target_dir>`.
* `config.load()` carries no `expected.end`; step 17 reads the image end from `analysis/stats.json`.
* With the unit powered off, `--all-devices` ends `15/17` for `rc-102` (steps 2 and 11 exit `1` on
  `BleakDeviceNotFoundError`) and `17/17` for the five targets whose `ble_address` is `null`. The
  artifacts of the last live capture stay on disk, so the offline layers are unaffected.

## 7. Landmark addresses for `rc-102/hw1-fw4.14` (already resolved - do not re-derive)

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

Those addresses are per build; the registry's `landmarks` block carries the ones the steps quote, so a
new target either fills them in or leaves the block empty (the reports then print `n/a`).

## 8. Suggested next steps

* Name hot functions from the "Most-called" list in each `analysis/summary.md` (`0x08017FA8` has 163
  callers, `0x0801953C` 110).
* Use `analysis/tables.json` dispatch ids to map wire ids (`0x0807`, `0x081C`, `0x0A04`) to handler addresses.
* Structure the 448-byte `0x081C` area 1 record against the `PublicAPI`/`VS CONFIGURATION` text; the
  76-byte `0x0F0` record still has 5 unidentified words (`firmware.md` §21).
* Re-run `pipeline/tools/read_vsfrs.py` while a measurement is running (`VSFR_MS_RUN` = 1) to catch the
  `0x8000`-`0x8035` block non-zero and confirm each `DType`/`RType` encoding.
* Diff two builds (e.g. `rc-102/hw1-fw4.14` vs `rc-410/fw4.16`) by comparing their `listing.s` /
  `analysis/strings.json`: the model-specific strings and table sizes are the interesting deltas.
