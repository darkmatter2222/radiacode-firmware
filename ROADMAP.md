# Reconstruction milestones

The requested end state is a complete buildable application with justified
behavioral equivalence. It has not been achieved. Repository validation and
firmware-release approval are distinct.

| Phase | Implemented evidence | Remaining work |
| --- | --- | --- |
| 1. Trustworthy validators | Real re-encryption; completion checks; isolated execution; ordered writes; fixed dates/shifts; negative tests; explicit incomplete status | Expand mutation corpus and independent oracles |
| 2. Fresh Ghidra recovery | Explicit Thumb context, RAM/MMIO mapping, seeded disassembly, all-six regeneration | Review indirect branches, function boundaries, types and remaining warnings |
| 3. Auditable coverage | Reachability-based instruction addresses, unknown bytes, unresolved transfers, warning inventory | Confirm every application region and indirect edge; current candidate map is incomplete |
| 4. Buildable source | Eight compiled candidates / 5,072 differential cases including four negative controls for the `0x08029370` helper; one FP predicate / 10,947 bounded comparisons including full FPSCR | Reconstruct the remaining application, globals, ABI, startup, linker layout |
| 5. Hybrid bridge | All-six byte-preserving assembler/linker baseline; transfer-state bridge / 1,424 cases; session-state bridge / 4,352 direct and original-handler cases | Whole-application replacement/linkage, interior-edge review and subsystem integration; no flashable hybrid released |
| 6. Behavioral tests | Deterministic boundaries and random cases; original ARM vs compiled ARM | Measurement, spectrum, calibration, persistence, timing, alarms, parsers and whole-system coverage |
| 7. Board/hardware validation | Explicit missing-evidence gate; raw capture retention | Exact MCU/board model, peripheral semantics, interrupt/DMA tests and physical original/rebuilt comparisons |
| 8. Formal equivalence | Corrected auxiliary-model bit-vector properties | Original-vs-compiled semantic proofs with explicit memory/ABI/FP assumptions |

Naming progress: 59 reference functions and 112 parameters/locals have reviewed
semantic names, with reversible annotated output and a full export inventory.
See [the naming guide](reconstruction/annotations/README.md).

## Next concrete units

1. Review every `review_required` entry in each confidence report; investigate lost
   candidate addresses in `recovery_delta.json` rather than treating a lower count as success.
2. Extend reviewed ARM candidates to the actual measurement/calibration path, with
   NaN, infinity, rounding, signed-zero and overflow cases where relevant.
3. Resolve callback/jump-table targets into the control-flow inventory.
4. Build a validated replacement/linkage mechanism before any whole-image claim.
5. Obtain hardware access and a repeatable sensor-input/replay setup. Bind captures
   to exact original and rebuilt image hashes. No physical tests ran in this workspace.

## Merge/release condition

The full user-requested completion condition is not met while these items remain.
Merge tested repository increments independently of firmware certification, as
requested by the owner. Do not describe those merges as certification of all
firmware behavior. `pipeline/release_gate.py` returns 2 until
that evidence exists. A green repository test suite does not override this gate.

Latest integration: [session helper](reconstruction/INTEGRATION.md#8-implemented-emulator-only-integration). The context-2 cleanup path now executes without stubs; no physical flash allocation is established. See [cleanup recovery](reconstruction/CLEANUP.md).

Combined replacement milestone: [both helpers through the original handler](reconstruction/COMBINED.md), with 3,200 independent cases and 1,280 persistent-sequence calls. Conservative incoming-edge audit remains INCONCLUSIVE.

Full command-chain milestone: [compiled handshake handler](reconstruction/HANDSHAKE.md) and both recovered callees pass 3,200 comparisons plus 1,280 persistent calls. Dispatcher integration, hardware layout and recovery remain unresolved.
