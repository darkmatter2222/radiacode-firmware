# Reproducing firmware analysis and validation

Vendor application containers for six RadiaCode builds, reproducible decoding,
Thumb disassembly, Ghidra exports, and bounded reconstruction experiments.

**Full firmware equivalence is not established. These C exports are not a
complete buildable replacement firmware. No generated replacement was flashed.**
The bootloader is absent; the first 64 KiB of the flat images are synthetic
address-preserving padding. Preserve the vendor containers as immutable inputs.

## Current evidence

- All six decoded images reproduce the checked-in bytes; 51 payload-block CRCs pass.
- The container carried-stream round trip now really decrypts and re-encrypts
  the key and payload blocks. It does not compile recovered application source.
- Fresh Ghidra analysis sets Thumb context before analysis, maps SRAM/MMIO, and
  disassembles seeded entries. Warnings and unresolved control flow remain tracked.
- Five ARM-compiled reference-build candidates (one is a single dispatcher path)
  are tested on 1,360 deterministic cases. See `reconstruction/validation.json`.
- A separate floating-point predicate experiment passes 10,947 return/memory/ABI
  comparisons but still differs in FPSCR exception flags. See
  [reconstruction/CALIBRATION.md](../reconstruction/CALIBRATION.md).
- An assembler/linker baseline preserves all six original images exactly. This
  earns no source-recovery credit and is not a newly reconstructed firmware.
- Z3 checks auxiliary format properties. They are not proofs of firmware equivalence.
- Device captures are historical observations. No fresh hardware equivalence test
  has been performed. Reports mark unavailable raw-ciphertext tests as SKIP.

The authoritative per-target status is `firmware/<target>/analysis/confidence.json`.
`release_ready` remains false. See [ROADMAP.md](../ROADMAP.md) for unfinished work and
[docs/VALIDATION.md](VALIDATION.md) for contracts and limitations.

## Reproduce offline

Python 3.12 and the pinned packages:

```sh
python -m pip install -r requirements.txt
python -m unittest discover -s tests -v
python pipeline/run.py --all-devices --only 1,13,14,15,16,17,12
python pipeline/release_gate.py
```

Exit codes: **0** selected work passed/completed, **1** failure, **2** inconclusive
or unavailable evidence. A report-generation exit 0 is not a firmware certification.
The decoder comparison and release gate currently return 2 intentionally.

`run.py` defaults to offline steps. Live steps require explicit `--live`; unknown
command sweeps additionally require `--unsafe-command-sweep` because commands can
change device state. Session setup/clock writes are not read-only. The staging
command `0x0013` is no longer sent by default capture/verification.

## Fresh decompilation

Use Ghidra 12.2 and JDK 25. Set `GHIDRA_HOME` and `JAVA_HOME` to their unpacked
locations. The official Ghidra 12.2 ZIP used in this audit has SHA-256
`2c2cd776db3c1f6a097ba418922378ac3649cadd5e844a6f5f088ae628a7be67`.

```sh
python pipeline/run.py --all-devices --only 5,6,7,8,9,10
python pipeline/run.py --all-devices --only 13,14,15,16,17,12
```

The Capstone stage uses control-flow discovery, vectors, static table candidates,
and image-hash-bound reviewed seeds. It does not classify printable instructions
as strings or declare every address after a return to be a new function.
Ghidra discovers additional code independently. The difference is unresolved
coverage, not a reason to silently inflate agreement percentages.

## Compile and execute reconstructed candidates

Install GNU Arm Embedded GCC/binutils. Set `ARM_GCC` to the compiler executable
if it is not on PATH. The recorded run used GCC 13.2.1.

```sh
python pipeline/build_reconstruction.py
```

This builds preserved-byte baselines for all targets and compiles
`reconstruction/rc102_leaf.c` for Cortex-M4. Original and compiled functions run
in separate clean Unicorn instances. Returns, stack restoration, non-stack memory
writes, and MMIO traces are compared. `build/` is disposable output; the JSON
report records image/source/compiler/binary identity and failures.

## Repository map

| Path | Purpose |
| --- | --- |
| `firmware/` | Immutable vendor inputs and regenerable analysis per target |
| `pipeline/` | Decoder, discovery, decompiler driver, validators, release gate |
| `reconstruction/` | Reviewed candidate C and compiled differential evidence |
| `tests/` | Negative/mutation regressions and pinned upstream vectors |
| `firmware.md` | Evidence-backed reference and limits |
| `docs/historical/` | Pre-audit narratives, retained but not authoritative |

No percentage of exported C blocks, decoded lines, byte accounting, or passing
auxiliary properties is a percentage of recovered functionality.
