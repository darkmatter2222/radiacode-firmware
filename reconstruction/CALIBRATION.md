# Floating-point predicate at 0x0802abf8

This is a bounded reconstruction experiment for the reference rc-102 image,
not a full calibration subsystem or a replacement suitable for flashing.

`calibration.c` follows the decoded Thumb/VFP branch predicates. The constants
are exact binary32 values from the original literal pool. It deliberately uses
unordered-aware rejection tests: the original accepts some NaN inputs, while
the readable Ghidra conjunction rejects them. The negative transcription and
counterexamples are retained to make this distinction testable.

Run `python reconstruction/validate_calibration.py` with the ARM toolchain used
by `pipeline/build_reconstruction.py`. CI runs it too. The 10,947 cases include
signed zero, subnormal numbers, infinities, quiet/signaling NaNs, threshold
neighbors, deterministic random encodings and samples under all four rounding
modes, flush-to-zero and default-NaN settings. This is sampling, not an exhaustive
proof over the 96-bit input space or every FPSCR configuration.

The checked contract covers return value, writes, MMIO, stack restoration and
callee-saved integer registers. It does **not** cover floating-point exception
flags: 1,513 tested executions differed in those flags. GCC emits VCMPE where
the original uses VCMP. That is a material remaining difference, so this
candidate is excluded from any replacement experiment until resolved.

The first run also exposed a harness observer defect with Unicorn 2.1.4:
global memory-read hooks caused incorrect execution through a conditional VFP
load/IT sequence. For input words `00000000 7f7fffff 80000001`, the hooked run
returned the input pointer, whereas execution without the RAM-read hook returned
zero. The decoded branch targets the zero assignment. The normal harness now
observes reads only in MMIO ranges, and the failing input is a regression test.
Writes and instruction tracing remain active. This is a local reproducible
observation, not a claim that every Unicorn IT/VFP behavior has been verified.
