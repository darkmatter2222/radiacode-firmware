# Compiled handshake handler

`rc102_handshake.c` reconstructs the full handler body at 0x08027490 for the
pinned RC-102 image. It advances the input cursor, validates the signature,
writes either an error word or the response header and metadata, obtains the
session-state reply, and implements the context-1 and context-2 state changes.
It calls the recovered C state helper and cleanup implementation. No call in
this tested chain is stubbed or redirected to the original implementation.

The original prologue saves incoming r3; every epilogue pops that saved word
into r0. The C interface explicitly accepts a fourth argument and returns it.
This preserves observed machine behavior and does not assign a semantic status
meaning to the value. The wider dispatcher's calling convention remains to be
reviewed.

## Validation

Run `python reconstruction/validate_handshake.py` with `ARM_GCC` available.
The linker puts the two callees at 0x08070000 and 0x08070100 and the handler at
0x08070200, with section-size assertions. A four-byte branch replaces the
original handler entry. Original helper entries remain unchanged and are not
used on the tested compiled paths.

The report records 3,200 comparisons covering valid/invalid signature paths,
five contexts, four stored states, list configurations, state-word patterns,
metadata underflow/overflow and nonzero incoming r3. Independent checks cover
response constants, metadata packing, session reply, cursor advances, r0 and
conditional activation-byte writes. Original-versus-compiled comparisons also
check final non-stack writes, stack restoration, saved registers and absence
of MMIO. Mutants of the handler and each callee must all be detected.

A further 1,280 calls preserve state between repeated commands, comparing all
non-stack SRAM after each call. The report includes source hashes, compiler and
linker settings, compiled bytes, patch bytes and full changed ranges.

Contracts require valid disjoint buffers with enough response capacity,
acyclic writable list nodes and no concurrent mutation. Invalid pointers,
overlapping buffers, interrupts and physical behavior are not established.

## Expanded edge audit

The audit now includes the full handler range. Two literal values reference
its Thumb entry: at 0x08027350 and 0x080378a4. These are candidates for subsequent
dispatch-table review, not proof of all callers.

It also reports a possible interior branch from 0x08027428 to 0x080274a2.
Decoding from 0x08027426 shows a four-byte `b.w 0x0802bbdc`; the candidate at
0x08027428 is the second half of that instruction in this decode. It remains
in the conservative report because excluding alternate entry points requires
control-flow evidence. The candidate does not target the four overwritten
entry bytes. The original interior body is retained by this experiment.

The edge audit remains INCONCLUSIVE, and the image is emulator-only. This is
one recovered command chain, not a complete firmware source rebuild or a
hardware deployment approval.
