# Combined replacement experiment

`python reconstruction/validate_combined.py` compiles the recovered state helper
and cleanup chain into one emulator image. A linker script places the helper at
0x08070000 and cleanup at 0x08070100, with assertions against section overlap.
Four-byte unconditional branches replace the original entries at 0x08029370 and
0x08029086. Both original prefixes contain complete instructions.

The original handler at 0x08027490 runs with both replacements active. The test
matrix has 3,200 cases: list shapes from empty through five nodes, target absent
or at each position, four state-word patterns, four stored-state values, five
contexts, and valid/invalid handshake words. Tests compare return, register ABI,
stack restoration, non-stack memory writes and absence of MMIO. The reply word
has an independent expected-value calculation. Execution traces must show the
replacement functions visited exactly on the relevant handler paths.

Each replacement also has a deliberately broken variant, tested through the
original handler. A passing report requires detection of both variants.

Another 1,280 calls run as 256 persistent sequences of contexts 2,2,1,0,255.
Request cursors are reset between calls, but list and cleanup state survive.
This exercises repeated removal and subsequent commands. Non-stack SRAM contents
are compared after every call, in addition to effects and ABI checks.

`combined_validation.json` records source and harness hashes, compiler settings,
linker layout, patch bytes, compiled bytes, complete changed ranges and results.
The appended range includes zero-filled space. This is not a deployable image:
physical flash capacity and allocation are still unknown.

## Incoming-edge audit

`python reconstruction/audit_patch_edges.py` decodes at every halfword in the
pinned image and scans for literal pointer values at every byte offset. It
collects external direct-branch candidates into the complete original routine
ranges and distinguishes entries from interiors and overwritten bytes.
This is deliberately conservative: data and overlapping instruction decodes can
produce false candidates. The current report finds the expected calls at
0x080274dc and 0x080274f6 and no literal-pointer candidates.

The audit always returns INCONCLUSIVE (exit 2). It does not resolve computed
indirect branches, prove every byte is code or data, or exclude runtime-created
pointers. An empty interior candidate list does not authorize a device patch.
Neither this experiment nor the audit establishes interrupt safety, boot behavior,
peripheral timing, calibration preservation, a recovery route or full firmware
source reconstruction.
