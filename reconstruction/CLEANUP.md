# Context-2 cleanup reconstruction

`rc102_cleanup.c` reconstructs the sequential chain at `0x08029086`,
`0x08022e60`, and `0x08016780` in the pinned RC-102 reference image.
It clears an indirect byte flag, clears state word +0x14 and bit 2 of the state
word, unlinks the node at 0x20000858 from the list whose head is at 0x2000dfa8,
and clears the node's next pointer and byte at +0x0c. The original returns the
node address in r0. Physical scheduling semantics are not established.

Run `python reconstruction/validate_cleanup.py` with `ARM_GCC` available.
The report binds source, original image, harness, compiler flags, and candidate
bytes. It checks 216 direct cases across empty lists, absent nodes, and every
removal position in lists of up to nine nodes, with four state-word patterns.
An independent byte-write oracle checks the exact expected non-stack effects.
A compiled mutant that omits the bit clear must be detected.

A second experiment replaces the original cleanup entry with a four-byte branch
to the compiled routine at emulator address 0x08070000. It executes 432 cases
through the original context-2 command handler, covering those list configurations
and stored states 0 and 2. The original state helper is retained in this experiment.
The separate session-helper experiment tests the opposite combination: compiled
state helper and original cleanup. Simultaneous replacement is not yet tested.

Preconditions are valid writable pointers, an acyclic list and no concurrent
mutation. A cyclic-list regression must exhaust its instruction budget rather
than report a successful return. These tests do not establish interrupt safety,
physical memory capacity, peripheral behavior, startup or device recovery.

No device package is emitted. The existing deployment CLI remains blocked by
unverified hardware identity, incomplete backup/recovery, and missing hardware
validation. Neither emulator allocation nor a passing comparison authorizes
using the synthetic address on a physical device.
