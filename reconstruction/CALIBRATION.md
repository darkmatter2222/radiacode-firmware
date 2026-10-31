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

The checked contract covers return value, writes, MMIO, stack restoration,
callee-saved integer registers and the full FPSCR register. All 10,947 cases now
match, including FPSCR. This remains bounded testing, not an exhaustive proof.

The first C candidate passed return/memory checks but differed in exception flags
in 1,513 cases: GCC emitted VCMPE where the original uses quiet VCMP. The current
candidate preserves VCMP and reads FPSCR through a small explicit ARM adapter,
then evaluates the original condition bits in C. It is intentionally ARM-specific.
The previous mismatch counts remain here as the reason for that adapter; current
results and source/compiler identities are in `calibration_validation.json`.
This predicate is still excluded from the separate one-leaf hybrid experiment.

The first run also exposed a harness observer defect with Unicorn 2.1.4:
global memory-read hooks caused incorrect execution through a conditional VFP
load/IT sequence. For input words `00000000 7f7fffff 80000001`, the hooked run
returned the input pointer, whereas execution without the RAM-read hook returned
zero. The decoded branch targets the zero assignment. The normal harness now
observes reads only in MMIO ranges, and the failing input is a regression test.
Writes and instruction tracing remain active. This is a local reproducible
observation, not a claim that every Unicorn IT/VFP behavior has been verified.
