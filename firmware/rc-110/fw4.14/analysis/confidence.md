# Evidence report: rc-110/fw4.14

**Firmware equivalence: NOT ESTABLISHED. Release ready: false.**

| Evidence | Result |
| --- | --- |
| Extraction | PASS; 9 payload CRCs verified |
| C export | 1011 blocks; 0 failures; 0 truncated; 43 with warnings |
| Python differential | 0/0 cases; not compiled C |
| Decoder comparison | INCONCLUSIVE |
| Auxiliary proofs | 10 proved; not firmware equivalence |
| Hardware comparison | SKIP |

## Blockers

- Whole application is not reconstructed from source
- Indirect control flow and decompiler warnings require review
- No complete subsystem/interrupt/peripheral equivalence test
- No hardware equivalence evidence or acquired bootloader
