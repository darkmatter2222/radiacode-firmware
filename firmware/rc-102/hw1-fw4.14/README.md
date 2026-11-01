# RC-102 hw1-fw4.14: where to find the code

**The `decompiled.c` in this directory is the raw export. Generic names are expected.**

## Readable source

**[Open the named-function index](../../../reconstruction/annotated/README.md)** first.
It links directly to the 59 reviewed functions out of 999 export blocks.

| Version of the code | Open | Meaning |
| --- | --- | --- |
| Raw | [decompiled.c](decompiled.c) | Original Ghidra output, unchanged |
| Readable companion | [rc102.c](../../../reconstruction/annotated/rc102.c) | Reviewed names/comments; remaining names unresolved |
| Compilable core | [Core functions](../../../reconstruction/rc102_leaf.c) | Tested small reconstructed routines with named fields |
| Compilable floating point | [Coefficient checks](../../../reconstruction/calibration.c) | Tested bounds calculation and FPSCR behavior |

## Files in this directory

| File or folder | What it is |
| --- | --- |
| `*.bin` | Vendor package(s) and decoded application image; not editable source |
| [decompiled.c](decompiled.c) | Raw pseudocode with Ghidra-generated names |
| [listing.s](listing.s) | ARM instruction listing |
| [index.json](index.json) | Raw function-address and line lookup |
| [analysis/summary.md](analysis/summary.md) | Existing analysis narrative and current update |
| [analysis/confidence.md](analysis/confidence.md) | What has been checked and what remains unresolved |

[Choose another device](../../README.md) · [Start here](../../../START_HERE.md)
