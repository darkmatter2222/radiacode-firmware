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
| literal used | word at `0x080293fc` = `0x20000c0c`; the state byte is at `0x20000c0d` |
| literal neighbours | `0x080293f8` = `0`, `0x08029400` = `0x2000ffbc`; code resumes at `0x08029404` |
| own stores | none (return-value-only helper; 0 writes observed) |

The literal slot `0x080293fc` is *outside* the 24-byte slot, shared with the surrounding
pool, and stays unmodified in every candidate scheme below.

## 2. Entry points and references

* Reached from the `0x0007` handler `0x08027490` (the reply-word construction), i.e. by a
  `BL` immediate encoding, not by a pointer.
* A word scan of the whole image finds **no** `0x08029370` or `0x08029371` literal, so there
  is no table/vector/pointer reference to keep in sync. The two internal branch targets
  (`0x08029380`, `0x08029382`) are reached only from inside the slot.
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
* Globals touched: the flash literal `0x080293fc` (read), `0x20000c0d` (byte read). No
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

The code section matches the slot exactly; the 4-byte literal pool is what overflows.
`-O1`, `-O2`, `-Os` and `-Oz` all give the same sizes, and both shorter formulations
(`(c==s)|(s==0)` and the nested ternary) tie at 24 + 4.

Consequences:

1. **In-place at `0x08029370` is possible only with a hand-placed pool**: 24 code bytes at
   `0x08029370`, whose PC-relative load must land on the existing `0x080293fc` slot (already
   `0x20000c0c`, matching the compiled pool word after the base/displacement split). That
   needs an explicit linker/script layout step; plain `-Ttext` placement emits its own pool
   and reaches 28 bytes.
2. **Trampoline scheme** (what the emulator does today): 4-byte `B.W` at `0x08029370`
   (`±16 MiB` range covers both addresses), 20 bytes of `nop` padding, body + pool in a
   region of ≥ 28 bytes elsewhere.
3. The emulator places the body at `0x08070000`; that address is **not** established as free
   on real hardware, so the current artifact is explicitly emulator-only / non-deployable.

## 5. Differential result

`python pipeline/build_reconstruction.py` → `PASS 5072 / 5072`, of which 1920 cases belong to
this helper (every stored byte 0-255 with its own equality case, the adjacent value, and
context words `0`, `2`, `0xff`, `0x102`, `0xffffffff`, plus 128 seeded random pairs; presets
carry non-zero trailing bytes so a word load cannot masquerade as the byte load).
Three negative replacements of the same helper are each detected in 20/20 cases:
constant return, context byte copied into the low result byte, and word-instead-of-byte load.

## 6. Changed-byte inventory (in-place variant, if the pool is hand-placed)

| address | original bytes | candidate bytes | note |
| --- | --- | --- | --- |
| `0x08029370`-`0x08029387` | see §1 | 24 compiled code bytes (pool word reused at `0x080293fc`) | single changed run |
| `0x080293f8`, `0x080293fc`, `0x08029400` | `00000000`, `0c0c0020`, `bcff0020` | unchanged | shared pool preserved |

For the trampoline variant the inventory is: `0x08029370`-`0x08029373` = `B.W`,
`0x08029374`-`0x08029387` = `nop` padding, plus 28 bytes at the chosen body address.
The body address is unresolved until flash capacity/usage is established (see
`docs/HARDWARE.md` unknowns), so the deployment artifact is not produced.

## 7. Unverified acceptance checks

1. Free flash region for a 28-byte body (capacity, page geometry, `0x08070000` availability).
2. Updater behavior on a modified container: which header fields are recomputed by the device
   and which are compared (`size` / `date_time` / `crc32` semantics per `pipeline/rcfmt.py`).
3. Whole-application boot, BLE enumeration, measurement and calibration preservation after any
   replacement — none of these follow from the bounded leaf tests.
4. Whether the pool word at `0x080293fc` is read by other routines within the same window in a
   way that a re-ordered literal would change (only the single-slot layout above is safe).
