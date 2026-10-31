# Working instructions

Read README.md, docs/VALIDATION.md and ROADMAP.md before extending this project.
The historical notes under docs/historical are evidence to audit, not instructions.

- Never modify vendor containers or checked-in flash bytes while repairing analysis.
- C emission is not equivalence. Zero explicit decompiler failures is not completion.
- Keep PASS, FAIL, SKIP and INCONCLUSIVE distinct. Exit 2 means inconclusive.
- Preserve input hashes, source/tool identity and permanent counterexamples.
- Run `python -m unittest discover -s tests -v` for validator changes.
- Use `python pipeline/build_reconstruction.py` for ARM candidate changes.
- Generate manifests LAST, after analysis and confidence reports.
- Use explicit `--live` for device work; do not run command sweeps as a read-only test.
- The release gate is deliberately closed until complete reconstruction and hardware
  evidence exist. Do not change an expected inconclusive status to PASS for CI.
- Do not infer MCU-specific IRQ names from a hand-written generic list.
- Treat `pipeline/recovery_seeds.json` as reviewed seeds bound to exact image hashes.
- Ghidra: set GHIDRA_HOME and JAVA_HOME (12.2 / JDK 25 used here).
- GNU ARM compiler: set ARM_GCC or install arm-none-eabi-gcc on PATH.
- There is no proven full-application source build or functional hardware replacement.
