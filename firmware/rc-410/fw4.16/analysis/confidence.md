# Confidence report - rc-410/fw4.16

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
