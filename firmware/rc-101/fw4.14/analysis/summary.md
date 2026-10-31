# rc-101/fw4.14

This is an extracted application and research reconstruction. Full firmware equivalence is not established.
The synthetic bootloader padding is not acquired device memory. C output is not a complete buildable application.

See [confidence.md](confidence.md) for current evidence, warnings, and blockers.

## Reproduce

```sh
python -m unittest discover -s tests -v
python pipeline/run.py --all-devices --only 1,13,14,15,16,17
python pipeline/step12_report.py
```

Exit 2 denotes incomplete or inconclusive evidence; it is not a pass.
