# Confidence report - rc-103/fw4.14

| category | what it means | evidence |
| --- | --- | --- |
| byte_matched | model writes back the vendor bytes | 130132/130132 container bytes, key blocks 8/8, data blocks 8/8, CRC pair 8/8 |
| formally_verified | proved for all inputs by the SMT solver | 10/10 checks (z3 5.3.3) |
| tested | original code vs Python models, offline | functions 8/8 (0 skipped), format vectors 183/183 |
| preserved_unchanged | carried verbatim at the original address | image 248320/248320 bytes, 66745 instructions, 1895 C blocks |

## Unresolved

* **definition of the per-block CRC pair beyond crc1 == crc2** (8) - 30 buffer/variant combinations checked, none matched; only equality is verified
* **own LZSS encoder is not bit-identical with the vendor stream** (8) - 0/8 blocks stream-identical, 8136/31799 tokens identical, 125860 vs 125783 bits
* **capstone vs SLEIGH lines not identical after normalisation** (4) - of 39260 compared: format-only 29746, pc-relative 1952, semantic 4 (agreement 0.9999)
* **lines only one decoder reaches** (28676) - capstone sweeps the whole image, Ghidra stops at data: only-capstone 28676, only-ghidra 1483
* **on-device frame comparison not available offline** (2) - steps 2 and 11 need the unit powered

## Inventory

* `image_bytes`: 248320
* `instructions`: 66745
* `functions`: 1867
* `strings`: 1906
* `tables`: 8
* `orphan_functions`: 1768
* `handlers_recovered`: 90

Evidence files: `firmware/rc-103/fw4.14/analysis/stats.json`, `firmware/rc-103/fw4.14/analysis/functions.json`, `firmware/rc-103/fw4.14/analysis/roundtrip.json`, `firmware/rc-103/fw4.14/analysis/crosscheck.json`, `firmware/rc-103/fw4.14/analysis/differential.json`, `firmware/rc-103/fw4.14/analysis/formal.json`, `firmware/rc-103/fw4.14/analysis/container_check.json`
