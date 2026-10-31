# Confidence report - rc-410/fw4.16

<!-- current-evidence:start -->
## Current evidence: rc-410/fw4.16

**Firmware equivalence: NOT ESTABLISHED. Release ready: false.**

| Evidence | Result |
| --- | --- |
| Extraction | PASS; 10 payload CRCs verified |
| C export | 1046 blocks; 0 failures; 0 truncated; 47 with warnings |
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
| byte_matched | model writes back the vendor bytes | 140836/140836 container bytes, key blocks 10/10, data blocks 10/10, CRC pair 10/10 |
| formally_verified | proved for all inputs by the SMT solver | 10/10 checks (z3 5.3.3) |
| tested | original code vs Python models, offline | functions 0/0 (8 skipped), format vectors 189/189 |
| preserved_unchanged | carried verbatim at the original address | image 264192/264192 bytes, 72189 instructions, 2123 C blocks |

## Unresolved

* **definition of the per-block CRC pair beyond crc1 == crc2** (10) - 30 buffer/variant combinations checked, none matched; only equality is verified
* **own LZSS encoder is not bit-identical with the vendor stream** (10) - 0/10 blocks stream-identical, 7521/34261 tokens identical, 135505 vs 135452 bits
* **capstone vs SLEIGH lines not identical after normalisation** (161) - of 38477 compared: format-only 29010, pc-relative 1701, semantic 161 (agreement 0.9958)
* **lines only one decoder reaches** (34970) - capstone sweeps the whole image, Ghidra stops at data: only-capstone 34970, only-ghidra 1976
* **on-device frame comparison not available offline** (2) - steps 2 and 11 need the unit powered

## Inventory

* `image_bytes`: 264192
* `instructions`: 72189
* `functions`: 2125
* `strings`: 2205
* `tables`: 8
* `orphan_functions`: 1849
* `handlers_recovered`: 91

Evidence files: `firmware/rc-410/fw4.16/analysis/stats.json`, `firmware/rc-410/fw4.16/analysis/functions.json`, `firmware/rc-410/fw4.16/analysis/roundtrip.json`, `firmware/rc-410/fw4.16/analysis/crosscheck.json`, `firmware/rc-410/fw4.16/analysis/differential.json`, `firmware/rc-410/fw4.16/analysis/formal.json`, `firmware/rc-410/fw4.16/analysis/container_check.json`
