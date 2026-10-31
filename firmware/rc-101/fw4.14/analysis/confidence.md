# Confidence report - rc-101/fw4.14

<!-- current-evidence:start -->
## Current evidence: rc-101/fw4.14

**Firmware equivalence: NOT ESTABLISHED. Release ready: false.**

| Evidence | Result |
| --- | --- |
| Extraction | PASS; 8 payload CRCs verified |
| C export | 922 blocks; 0 failures; 0 truncated; 40 with warnings |
| Python differential | 0/0 cases; not compiled C |
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
| byte_matched | model writes back the vendor bytes | 130388/130388 container bytes, key blocks 8/8, data blocks 8/8, CRC pair 8/8 |
| formally_verified | proved for all inputs by the SMT solver | 10/10 checks (z3 5.3.3) |
| tested | original code vs Python models, offline | functions 0/0 (8 skipped), format vectors 183/183 |
| preserved_unchanged | carried verbatim at the original address | image 249344/249344 bytes, 67163 instructions, 1832 C blocks |

## Unresolved

* **definition of the per-block CRC pair beyond crc1 == crc2** (8) - 30 buffer/variant combinations checked, none matched; only equality is verified
* **own LZSS encoder is not bit-identical with the vendor stream** (8) - 0/8 blocks stream-identical, 6109/32026 tokens identical, 126119 vs 126083 bits
* **capstone vs SLEIGH lines not identical after normalisation** (4) - of 37891 compared: format-only 28622, pc-relative 1822, semantic 4 (agreement 0.9999)
* **lines only one decoder reaches** (30552) - capstone sweeps the whole image, Ghidra stops at data: only-capstone 30552, only-ghidra 1447
* **on-device frame comparison not available offline** (2) - steps 2 and 11 need the unit powered

## Inventory

* `image_bytes`: 249344
* `instructions`: 67163
* `functions`: 1802
* `strings`: 1893
* `tables`: 6
* `orphan_functions`: 1687
* `handlers_recovered`: 90

Evidence files: `firmware/rc-101/fw4.14/analysis/stats.json`, `firmware/rc-101/fw4.14/analysis/functions.json`, `firmware/rc-101/fw4.14/analysis/roundtrip.json`, `firmware/rc-101/fw4.14/analysis/crosscheck.json`, `firmware/rc-101/fw4.14/analysis/differential.json`, `firmware/rc-101/fw4.14/analysis/formal.json`, `firmware/rc-101/fw4.14/analysis/container_check.json`
