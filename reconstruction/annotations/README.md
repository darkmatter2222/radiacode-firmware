# Naming and documenting recovered source

Start with the [readable reference index](../annotated/README.md). Its 59 reviewed
functions cover event queues, transfer state, shared flags, scheduling wrappers,
bound-value caching, startup helpers and the floating-point bounds predicate.
The index links directly to the generated, commented C. The repository-wide
inventory is [targets.json](../annotated/targets.json).

`rc102.json` is the maintained naming record. Each entry preserves the original
address/name, the exact raw block hash, scoped parameter/local renames, an observed
behavior summary, evidence category and limitations. Seven global names describe
pointer/constant literals rather than pretending those flash literals are SRAM
objects. The whole record is bound to the reference image and raw export hashes.

Names are not recovered original vendor symbols. They are our reviewed names:

- Instruction-derived names describe concrete operations, widths and offsets.
- Caller/dataflow interpretations state their uncertainty explicitly.
- Compiled differential evidence is identified where it actually exists.
- `unresolved_*` names retain uncertain incoming-register/signature artifacts.
- Generic names remain when the evidence does not justify a useful interpretation.

Run `python reconstruction/render_annotations.py` after editing the naming map.
It changes identifier tokens only, leaving strings, comments, types, constants,
operators and control flow untouched. Each block must invert exactly to the raw
export. Colliding names, changed source/image hashes and missing locals fail.
This check protects against accidental edits; it does not prove the original
pseudocode is correct. The known NaN/type defect at 0x0802abf8 remains labeled in
the annotated export, with the tested implementation in `../calibration.c`.

Compile-worthy cleanup belongs in `../rc102_leaf.c` or a similarly scoped source
module, with original-vs-compiled tests. These files use named fields, offset
assertions, typed values and original-address compatibility aliases. Never add
bounds checks, reorder volatile accesses or simplify signed/FP comparisons merely
because they look cleaner: those are behavior changes that require evidence.

The present semantic naming pass covers 59 of 999 reference export blocks, with
112 parameter/local renames. The other model builds have been inventoried but do
not inherit these names automatically. Remaining work includes larger handlers,
callers, types, indirect edges and cross-build mapping. No complete naming or
whole-firmware equivalence claim is made.
