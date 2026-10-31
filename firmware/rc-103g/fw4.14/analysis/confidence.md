# Confidence report - rc-103g/fw4.14

<!-- current-evidence:start -->
## Current evidence: rc-103g/fw4.14

**Firmware equivalence: NOT ESTABLISHED. Release ready: false.**

| Evidence | Result |
| --- | --- |
| Extraction | PASS; 8 payload CRCs verified |
| C export | 999 blocks; 0 failures; 0 truncated; 43 with warnings |
| Python differential | 8/8 cases; not compiled C |
| Decoder comparison | INCONCLUSIVE |
| Auxiliary proofs | 10 proved; not firmware equivalence |
| Hardware comparison | SKIP |

### Current blockers

- Whole application is not reconstructed from source
- Indirect control flow and decompiler warnings require review
- No complete subsystem/interrupt/peripheral equivalence test
- No hardware equivalence evidence or acquired bootloader
<!-- current-evidence:end -->

> **Baseline reference:** the original report and section anchors are retained below.
> Its counts, confidence labels and operational assumptions describe the earlier
> pipeline. The current generated evidence block above and current JSON reports
> supersede those measurements; historical interpretations still require review.

| category | what it means | evidence |
| --- | --- | --- |
| byte_matched | model writes back the vendor bytes | 130444/130444 container bytes, key blocks 8/8, data blocks 8/8, CRC pair 8/8 |
| formally_verified | proved for all inputs by the SMT solver | 10/10 checks (z3 5.3.3) |
| tested | original code vs Python models, offline | functions 8/8 (0 skipped), format vectors 183/183 |
| preserved_unchanged | carried verbatim at the original address | image 248576/248576 bytes, 66570 instructions, 1894 C blocks |

## Unresolved

* **definition of the per-block CRC pair beyond crc1 == crc2** (8) - 30 buffer/variant combinations checked, none matched; only equality is verified
* **own LZSS encoder is not bit-identical with the vendor stream** (8) - 0/8 blocks stream-identical, 5754/31812 tokens identical, 126178 vs 126100 bits
* **capstone vs SLEIGH lines not identical after normalisation** (4) - of 39258 compared: format-only 29744, pc-relative 1952, semantic 4 (agreement 0.9999)
* **lines only one decoder reaches** (28502) - capstone sweeps the whole image, Ghidra stops at data: only-capstone 28502, only-ghidra 1485
* **on-device frame comparison not available offline** (2) - steps 2 and 11 need the unit powered

## Inventory

* `image_bytes`: 248576
* `instructions`: 66570
* `functions`: 1865
* `strings`: 1911
* `tables`: 8
* `orphan_functions`: 1766
* `handlers_recovered`: 90

Evidence files: `firmware/rc-103g/fw4.14/analysis/stats.json`, `firmware/rc-103g/fw4.14/analysis/functions.json`, `firmware/rc-103g/fw4.14/analysis/roundtrip.json`, `firmware/rc-103g/fw4.14/analysis/crosscheck.json`, `firmware/rc-103g/fw4.14/analysis/differential.json`, `firmware/rc-103g/fw4.14/analysis/formal.json`, `firmware/rc-103g/fw4.14/analysis/container_check.json`
