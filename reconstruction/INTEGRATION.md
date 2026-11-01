# In-place integration assessment: the `0x08029370` replacement

Reference build `rc-102/hw1-fw4.14` (`flash.bin`, image hash
`23c31b7dabc59fe35a698cbd4f690498ded9bbb9f6590f3f2ea72ae5cfd157f6`). All numbers below come
from the regenerated analysis files and from `reconstruction/validation.json`.

## 1. Original boundaries and bytes

| item | value |
| --- | --- |
| entry (Thumb) | `0x08029371` (`0x08029370` even half, bit0 set by callers) |
| range | `0x08029370`-`0x08029387`, 24 bytes |
| bytes | `22 49 49 7b 88 42 03 d0 48 1e 80 41 c0 0f 00 e0 01 20 40 ea 01 20 70 47` |
| last instruction | `0x08029386 bx lr` (2 bytes, ends the slot at `0x08029388`) |
| literal used | word at `0x080293fc` = `0x20000c0c`; the state byte is at `0x20000c19` |
| literal neighbours | `0x080293f8` = `0`, `0x08029400` = `0x2000ffbc`; code resumes at `0x08029404` |
| own stores | none (return-value-only helper; 0 writes observed) |

The literal slot `0x080293fc` is *outside* the 24-byte slot, shared with the surrounding
pool, and stays unmodified in every candidate scheme below.

## 2. Entry points and references

* Reached from the `0x0007` handler `0x08027490` (the reply-word construction), i.e. by a
  `BL` immediate encoding, not by a pointer.
* A word scan of the whole image finds **no** `0x08029370` or `0x08029371` literal, but this does not exclude computed pointers or external jumps into the body. The
  observed internal branch targets are `0x08029380` and `0x08029382`; complete
  incoming-edge coverage remains unproven.
* In the reachability-based listing (`listing.s`) the range is printed as
  `.byte … ; unclassified`, and the covering record in `analysis/functions.json` is
  `sub_08029360` (152 bytes, `boundary_status: candidate; body may share tails`) whose
  instruction list skips `0x08029370`-`0x080293dc`. The function therefore has *no*
  reachable instruction record from the seeded walk; the reviewed body comes from the Ghidra
  export (`decompiled.c` block `FUN_08029370`) plus the emulator probe below. This gap is
  unresolved in the coverage layer and is listed as such.
* Provenance of the effective address: presetting `0x080293fc` = `0x2000e000` (byte `0xa1` at
  `0x2000e00d`) and `0x08029400` = `0x2000e100` (byte `0xa2` at `0x2000e10d`) makes the
  original return `0xa100`, i.e. the pointer is read from `0x080293fc`, not `0x08029400`.

## 3. Calling convention and assumptions

* Integer ABI: argument in `r0`, result in `r0`, `bx lr` return. Every case checks
  `sp` restoration, callee-saved `r4`-`r11` preservation, non-stack write map and MMIO trace.
* Globals touched: the flash literal `0x080293fc` (read), `0x20000c19` (byte read). No
  peripheral access, so no interrupt-timing assumption is exercised; the byte is loaded
  `volatile` because other code writes that block (the `0x0007` handler stores `1` into
  `0x2000082d`).
* Concurrency: the routine itself is a straight-line leaf; no lock is observed and none is
  assumed. Interrupt preemption between its two loads is *not* modelled.

## 4. Compiled artifact and size fit

Compiler: `arm-none-eabi-gcc` 13.2.1 (Arm GNU Toolchain 13.2.Rel1, Build arm-13.7);
flags recorded in `reconstruction/validation.json` (`-mcpu=cortex-m4 -mthumb
-mfloat-abi=soft -O2 -ffreestanding -fno-builtin -fno-unwind-tables
-fno-asynchronous-unwind-tables -nostdlib` plus link flags).

| quantity | bytes |
| --- | --- |
| original slot | 24 |
| compiled code (direct-address form) | 24 |
| compiled literal pool word | 4 |
| compiled total | 28 |
| compiled code (via-literal form) | 28 (+4 pool = 32) |

The table above records the earlier compiler experiment, not an implemented
patch. The current C uses the via-literal form. Compiler output and placement
must be measured again for each toolchain; a direct-address formulation is not
the current candidate. No linker script for pool reuse has been validated.

A trampoline is a possible future approach, but this helper is currently executed
at its separately linked symbol, not through a patched original call site.
The existing hybrid experiment covers a different helper. The emulator allocation
at `0x08070000` does not establish free physical flash. No deployable replacement
is produced.

## 5. Differential result

`python pipeline/build_reconstruction.py` → `PASS 5072 / 5072`, of which 1920 cases belong to
this helper (every stored byte 0-255 with its own equality case, the adjacent value, and
context words `0`, `2`, `0xff`, `0x102`, `0xffffffff`, plus 128 seeded random pairs; presets
carry non-zero trailing bytes so a word load cannot masquerade as the byte load).
Four negative replacements must each produce at least one mismatch: constant
`1`, constant `0x201`, context copied into the low result byte, and word-wide load.
Exact detection counts are recorded in `validation.json`, not assumed to be 20/20.
Both original and compiled outputs are also checked against the independent
formula `state * 256 + int(state == 0 or context == state)`.

The earlier report at commit `c9e9948` initialized `0x20000c0d` instead of
`0x20000c19`. Its 1,920 helper cases left the real state at zero and did not
establish the claimed state coverage. The corrected harness asserts the original
literal and records its own SHA-256. A regression reproduces the wrong-address
false pass explicitly.

## 6. Changed-byte inventory

No integrated image exists for this helper, so there is no final changed-byte
inventory. Before integration, produce the actual linked bytes, enumerate every
changed range and shared literal, and check branch targets and physical capacity.
The original 24-byte body and surrounding literal pool remain unchanged here.

## 7. Unverified acceptance checks

1. Free flash region sized for the actual linked code and pool (capacity, page geometry, `0x08070000` availability).
2. Updater behavior on a modified container: which header fields are recomputed by the device
   and which are compared (`size` / `date_time` / `crc32` semantics per `pipeline/rcfmt.py`).
3. Whole-application boot, BLE enumeration, measurement and calibration preservation after any
   replacement — none of these follow from the bounded leaf tests.
4. Whether the pool word at `0x080293fc` is read by other routines within the same window in a
   way that a re-ordered literal would change (only the single-slot layout above is safe).
