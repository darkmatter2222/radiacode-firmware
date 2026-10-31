# Confidence report - rc-110/fw4.14

| category | what it means | evidence |
| --- | --- | --- |
| byte_matched | model writes back the vendor bytes | 133312/133312 container bytes, key blocks 9/9, data blocks 9/9, CRC pair 9/9 |
| formally_verified | proved for all inputs by the SMT solver | 10/10 checks (z3 5.3.3) |
| tested | original code vs Python models, offline | functions 0/0 (8 skipped), format vectors 186/186 |
| preserved_unchanged | carried verbatim at the original address | image 251904/251904 bytes, 67873 instructions, 1934 C blocks |

## Unresolved

* **definition of the per-block CRC pair beyond crc1 == crc2** (9) - 30 buffer/variant combinations checked, none matched; only equality is verified
* **own LZSS encoder is not bit-identical with the vendor stream** (9) - 0/9 blocks stream-identical, 7297/32384 tokens identical, 128512 vs 128425 bits
* **capstone vs SLEIGH lines not identical after normalisation** (4) - of 39619 compared: format-only 30011, pc-relative 1967, semantic 4 (agreement 0.9999)
* **lines only one decoder reaches** (29448) - capstone sweeps the whole image, Ghidra stops at data: only-capstone 29448, only-ghidra 1528
* **on-device frame comparison not available offline** (2) - steps 2 and 11 need the unit powered

## Inventory

* `image_bytes`: 251904
* `instructions`: 67873
* `functions`: 1908
* `strings`: 1980
* `tables`: 8
* `orphan_functions`: 1807
* `handlers_recovered`: 90

Evidence files: `firmware/rc-110/fw4.14/analysis/stats.json`, `firmware/rc-110/fw4.14/analysis/functions.json`, `firmware/rc-110/fw4.14/analysis/roundtrip.json`, `firmware/rc-110/fw4.14/analysis/crosscheck.json`, `firmware/rc-110/fw4.14/analysis/differential.json`, `firmware/rc-110/fw4.14/analysis/formal.json`, `firmware/rc-110/fw4.14/analysis/container_check.json`
