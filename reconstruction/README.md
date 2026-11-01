# Readable and rebuilt firmware source

**Start with the code, not the test reports:**

1. **[Named-function index](annotated/README.md)**: descriptions and direct links
   to the 59 reviewed RC-102 functions in the readable export.
2. **[Core functions](rc102_leaf.c)**: clean, compilable C with named structures,
   transfer-state logic, an accessor path and event-ring operations.
3. **[Coefficient checks](calibration.c)**: clean, compilable floating-point code,
   including the original NaN and status-flag behavior.

These are all for **RC-102 hardware 1, firmware 4.14**. They are not a complete
recompiled firmware and do not apply automatically to another model.

## What the other files mean

| File or folder | Plain-English explanation |
| --- | --- |
| [`annotated/rc102.c`](annotated/rc102.c) | Full readable companion to the raw export; most functions still have unresolved names |
| [`annotated/index.json`](annotated/index.json) | Machine-readable address/name/line lookup, including unresolved functions |
| [`annotations/`](annotations/README.md) | Reviewed naming decisions and evidence; edit these to improve the readable export |
| `render_annotations.py` | Regenerates the readable file and checks that renaming preserves the raw expressions |
| `rc102_leaf.c` | The core-function source above; “leaf” was the original technical filename |
| `validation.json` | Results from compiling and comparing the core functions with original ARM code |
| [`CALIBRATION.md`](CALIBRATION.md) | Explanation of the floating-point reconstruction |
| `validate_calibration.py`, `calibration_validation.json` | Its test runner and recorded results |
| [`HYBRID.md`](HYBRID.md) | Explanation of replacing one original function inside an emulator |
| `validate_hybrid.py`, `hybrid_validation.json` | Replacement experiment runner/results; not an uploader or flashable firmware |
| `render_navigation.py` | Maintains the model guides and makes missing readable-source coverage explicit |

## Raw source is still available

The untouched RC-102 export is
[`firmware/rc-102/hw1-fw4.14/decompiled.c`](../firmware/rc-102/hw1-fw4.14/decompiled.c).
For another model, use [Choose a device](../firmware/README.md).
The raw export is expected to have generic Ghidra names; the reviewed index is
where to find meaningful names without searching a large file at random.
