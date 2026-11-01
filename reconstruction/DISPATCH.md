# Original dispatcher integration

Run `python reconstruction/validate_dispatch.py` with `ARM_GCC` available.
This first rebuilds and validates the recovered handler/callees, then tests the
same image through the original dispatch instructions. No dispatch table is
modified and no synthetic caller replaces the original indirect call.

The two observed tables begin at 0x08027344 and 0x08037838. Both map command
0x80000007 to Thumb entry 0x08027491. The experiment starts at 0x08027310 with
the table and command registers explicitly initialized, runs the table search
and `blx r1` at 0x08027322, and stops at 0x08027324 after the handler returns.
The replacement branch at the original handler entry leads to the compiled C
handler and compiled state/cleanup callees.

The stop classification is BOUNDARY_REACHED, not a whole-function return.
Instruction-budget exhaustion and unmapped access remain distinct failures,
with regression tests. No fake sentinel return is inserted.

There are 5,120 comparisons: two tables, all 256 stored state bytes, five context
values and valid/invalid handshake words. Tests compare the observable result,
stack restoration, saved registers, final non-stack writes, non-stack SRAM,
and absence of MMIO. Independent checks validate the session/error reply word.
Execution traces must contain the actual indirect-call edge and the compiled
handler entry. A broken handler is detected through each table.

The report binds the pinned original image, rebuilt hybrid image, harness and
fresh handler validation report by SHA-256. CI runs this script, which also
reruns the 3,200 handler comparisons and 1,280 persistent calls.

## Remaining boundaries

This does not validate upstream frame parsing, table-selection policy, CRC
handling, response finalization at 0x080273a2, transport callbacks or the rest
of the dispatcher. Table pointers and request structures are prepared in the
harness. It is not a test of receiving a real USB/Bluetooth packet.

The original physical flash allocation and a verified restore route are still
missing. A compiled command chain passing this experiment is not a bootable
application rebuilt from source, nor authorization to flash the emulator image.
