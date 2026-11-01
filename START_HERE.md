# Start here: finding the firmware source

There are **three different kinds of C in this repository**. They serve different
purposes, and they are not equally complete.

| What you want | Open this | What you will find |
| --- | --- | --- |
| Read the functions we have named and explained | **[RC-102 readable function index](reconstruction/annotated/README.md)** | 59 reviewed functions with descriptions and direct links into the annotated C |
| Read clean C that actually compiles and has been tested | **[RC-102 core functions](reconstruction/rc102_leaf.c)** | Named structures, comments, transfer-state logic, an accessor path and event-ring routines |
| Read the reconstructed floating-point calculation | **[RC-102 coefficient checks](reconstruction/calibration.c)** | Named coefficients, exact bounds and explanations of floating-point behavior |
| Find files for your model | **[Choose a device](firmware/README.md)** | Each model's raw source, readable-source status and test status |
| Understand the project in detail | [Original project walkthrough](README.md) | Extraction, hardware, protocol, memory layout and research history |

## Preparing for an eventual device update

Use the **[deployment CLI guide](deployment/README.md)** for verified local firmware
archives, image inspection, USB/Bluetooth discovery and blocked preflight reports.
Full device backup, flashing and automatic restore are not available yet.

## Raw C versus readable C versus rebuilt C

**Raw C** is the unedited Ghidra output at
`firmware/<model>/<version>/decompiled.c`. Names such as `FUN_080...`, `param_1`
and `uVar1` are expected there. We keep this as the baseline for comparison.

**Readable C** is a separate, annotated companion. For RC-102 it is currently
[`reconstruction/annotated/rc102.c`](reconstruction/annotated/rc102.c).
It changes reviewed names and adds explanatory comments, while retaining the
original expressions and decompiler warnings. Only 59 of its 999 functions have
reviewed names so far. **Start with its function index above**, rather than
opening the huge file at a random location. It is not a complete source build.

**Rebuilt C** is manually reconstructed, compilable code. The two files linked
above contain the current tested implementations. `rc102_leaf.c` was a technical
filename for small standalone functions; it is the core-function file you want
to read. It is not an alternative full firmware image.

## Specifically for RC-410

**[Open the RC-410 guide](firmware/rc-410/fw4.16/README.md).** Its
[`decompiled.c`](firmware/rc-410/fw4.16/decompiled.c) is still raw.
There is **no reviewed English-named RC-410 source version yet**. The RC-102 names
have not been applied to RC-410, and the RC-102 compiled tests do not validate
RC-410 firmware. Opening RC-410's raw C therefore will still look like gibberish.

## Which folders can I ignore while reading?

| Folder | Purpose | Needed to read the cleaned code? |
| --- | --- | --- |
| `firmware/` | Original images, raw exports and per-device analysis | Use the model guides; the large generated files are reference evidence |
| `reconstruction/` | Readable source, compilable implementations and their tests | **Yes. Start at its [guide](reconstruction/README.md)** |
| `pipeline/` | Programs that extract, decompile and validate firmware | Only if you want to work on the tooling |
| `tests/` | Regression tests for the tooling | Only if you want to inspect the checks |
| `docs/` | Supporting explanations and preserved historical documents | Optional background |

The raw and readable files are intentionally separate. The naming map generates
the readable companion, so it is not a second hand-maintained copy. Existing
paths and linked reference documents are kept in place.
