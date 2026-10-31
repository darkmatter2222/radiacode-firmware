# Emulator-only function replacement bridge

`python reconstruction/validate_hybrid.py` compiles the complete transfer-state
leaf at `0x08017eb4`, places the candidate at `0x08070000`, and builds a four-byte
Thumb `B.W` patch at the original entry. The original vendor image is never
modified on disk. The synthetic hybrid exists only in the test process.

The harness tests both direct entry and a compiled synthetic `BL` caller. All
1,424 cases compare return value, non-stack writes, MMIO, stack restoration and
callee-saved integer registers against the original. A deliberately wrong
constant-return replacement must be detected. Four malformed/unreviewed patch
inputs must be rejected.

This validates one replacement mechanism within the bounded emulator. It does
not establish that appended addresses are free on a real board, that every
incoming edge enters the function at its start, or that interrupts, timing,
peripherals and startup behave equivalently. The partial dispatcher path and
floating-point predicate are not eligible. There is no flashable output or
hardware deployment step.

`hybrid_validation.json` records source, harness, compiler, original-image,
candidate and synthetic-image identities plus the exact patch bytes. Full
application linkage and subsystem integration remain work in progress.
