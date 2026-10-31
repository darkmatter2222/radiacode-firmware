# Firmware evidence reference

The application extraction is reproducible. The complete source, bootloader,
board model, peripheral timing and device-level equivalence are not recovered.

## RC-102 hw1 / firmware 4.14

| Fact | Evidence |
| --- | --- |
| Vendor container: 130,148 bytes | `rc-102z.bin`, manifest SHA-256 |
| Flat image: 248,320 bytes | `flash.bin`, regenerated from container |
| Application: `0x08010000` through `0x0803C9FF` | Decoded block addresses |
| Application payload: 182,784 bytes | Block payload sum |
| Initial stack pointer: `0x20000800` | First application vector word |
| Reset handler pointer: `0x0803BA71` | Second application vector word |
| Bootloader below `0x08010000` | Absent from acquired container; padding is synthetic |
| Saved device/container correspondence | Stored size, timestamp, CRC and 3,256-byte configuration match |
| Exact MCU part and peripheral model | Still require independent confirmation |

The vector-table address is not the reset-handler address. No bootloader execution
was acquired or traced, so bootloader activation, rollback, or failure-recovery
behavior must not be asserted from application strings alone.

## Acquisition and checks

The format implementation is based on attributed PhytonUtils work and pinned
sample vectors. Every target is decoded and payload CRC-checked. The own encoder
may choose a different valid LZSS stream; compare decoded payloads separately
from compressed byte identity. Never credit container encoding as a firmware
source rebuild.

A command sweep only establishes which commands answered in those observed
sessions and argument forms. It cannot prove that a memory-read operation does
not exist. Some command IDs mutate state. New captures retain raw area replies;
old decoded plaintext is not independent ciphertext evidence.

## Recovery and interpretation

`decompiled.c` is generated pseudocode. Globals, types, prototypes, indirect calls,
shared tails and warning sites need review before use as buildable C. The two
specific RC-102 entries `0x08010242` and `0x0802ABF8` were demonstrated to contain
coherent code; they must not be dismissed as data-table slots.

The `0x502` accessor reads a byte and emits a 32-bit reply word. Expanded compiled
execution caught the old Python model's incorrect 32-bit load. Regression inputs
include high nonzero bytes to prevent recurrence.

`FrameTimeStep_us = 10000` denotes a 10 ms interval (100 Hz), not 100 kHz. This
field interpretation alone does not prove the entire sensor sampling schedule.

## Documentation confidence

Use these labels for new claims:

- **Observed bytes:** precise image hash, address and byte range.
- **Captured behavior:** raw request/reply, device identity and session conditions.
- **Tested reconstruction:** compiled candidate hash, input corpus and comparisons.
- **Proven under assumptions:** original/rebuilt semantics, assumptions and proof artifact.
- **Hypothesis:** an explicit inference awaiting confirmation.

The earlier detailed protocol narrative remains in
[docs/historical/firmware.md](docs/historical/firmware.md) as research leads. It
contains known overclaims and is not a normative device specification.
