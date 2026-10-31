# Validation contracts

## What counts as a pass

Container: independent payload CRCs, exact decoded flash, actual re-encryption,
and decode-equivalence of recompression. A compressor need not reproduce vendor
tie-breaking to reproduce the payload.

Instruction comparison: preserve conditions, register/operand order, widths,
flags, writeback and shifts. Only conservative textual equivalences are credited.
Different renderings not understood by the normalizer stay unresolved. Legacy
Ghidra getOpObjects exports are lossy and cannot receive semantic credit.

Function execution: fresh Cortex-M4 instance, bounded instructions, observed
sentinel return, ordered byte writes, explicit stack exclusion and separate MMIO
trace. An instruction limit or unmapped access is not return. The Python serializer
case stops at a substituted call and is labeled partial execution. MMIO is plain
RAM in this harness, so passing MMIO cases cannot certify peripheral behavior.

Compiled candidates: pinned original image, 32-bit ARM target, recorded compiler
flags, original and compiled runs on the same initial state. The seven current
candidates cover three constants, transfer-state comparison, only the 0x502
accessor branch, and event-ring push/pending operations. The ring tests cover all
valid index pairs, full/empty states, wraparound and halfword truncation. Cases are deterministic (seed 0x5243). This is not a complete
source rebuild. The first expanded run found 131 accessor mismatches caused by a
word load where original instructions read a byte; that defect was fixed and
high-byte regression inputs remain in the suite.

Formal properties: unsigned right shifts use LShR for bit-vectors; Mangle cycles
four key words; CRC compares independent byte-fold and serial bit transitions.
Solver timeout/unknown is not success. These are auxiliary format properties, not
proofs relating an original binary to reconstructed C.

## Independence and provenance

`tests/fixtures/phyton_vectors.json` pins upstream commit
3a25cc15bcf692d30487f41e3c61116e1b85c6ec, source URL and SHA-256. Its upstream license
is retained beside it. Tests run without downloads.

Reports record exact container/image hashes, pipeline source fingerprint and
Python tool versions. Text artifacts use LF; manifests hash exact bytes and are
written after other artifacts. Historical device captures are not regenerated or
silently upgraded to fresh evidence.

Full-image SHA-256 gates Python transcription applicability. Sixteen matching
prefix bytes alone are insufficient to establish function/callee identity.

## Negative tests

The suite rejects swapped operands, changed branch conditions, omitted flags or
shifts, budget exhaustion, faults, CRC corruption, disabled encryption, broken
date decoding and failed format vectors. Overlapping-width writes retain correct
order. Printable instruction bytes remain code candidates. Unreferenced bytes
after returns are not automatically declared new functions.

## Incomplete evidence

No acquired bootloader, complete C firmware, validated board simulator, complete
indirect-call graph, hardware equivalence capture or whole-program proof exists.
Confidence reports retain these blockers; the release gate fails closed. It also
checks input provenance and artifact hashes. It deliberately requires a future
reviewed hardware evidence policy rather than accepting a hand-edited PASS flag.

## Floating-point observer regression

Read observers are restricted to MMIO because a global RAM-read hook in Unicorn
2.1.4 changed execution of a conditional VFP load. A pinned original-image
regression covers the failing case. The additional predicate experiment and
the ARM-specific quiet-comparison adapter that resolves the observed FPSCR differences are documented in `reconstruction/CALIBRATION.md`.

## Readable source

Reviewed names and comments live in `reconstruction/annotations/rc102.json`; the
renderer preserves raw operators/control flow and verifies reversible identifier
substitution. Compilable sources use layout assertions and address aliases. The
harness maps a 64 KiB logical SRAM window to exercise globals such as the event
ring at 0x2000f424; that does not establish physical MCU capacity.
