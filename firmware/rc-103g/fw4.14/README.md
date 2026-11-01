# RC-103G fw4.14: where to find the code

**The `decompiled.c` in this directory is the raw export. Generic names are expected.**

## Readable source

**No reviewed English-named source or compiled reconstruction is available for this build yet.**
The raw export has 999 function blocks. The naming work completed for RC-102
has not been transferred to this model. Its tests do not validate this build.

You can read the [raw export](decompiled.c), or view the
[RC-102 readable-source example](../../../reconstruction/annotated/README.md)
to see the intended format. That example is for a different target.

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
