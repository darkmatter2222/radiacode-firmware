# Recovered response finalization

`rc102_finalize.c` reconstructs 0x080273a2 through 0x080273d0. It resets the
owner output cursor, computes unsigned payload length, compares that length
with context capacity, substitutes error 0xe0000007 on overflow, writes the
length prefix, and merges response flags into the first payload word. The
observed return value is the flags word.

The capacity check occurs after the handler has written its payload. It cannot
prevent an earlier write beyond the supplied buffer. The tests provide enough
physical buffer space even when the reported capacity is deliberately small.
No buffer-safety or exploitability conclusion follows from these tests.

## Reproduction and results

Run `python reconstruction/validate_finalize.py` with `ARM_GCC` available.
It rebuilds and reruns the handler and dispatch prerequisites before compiling
the finalizer at emulator address 0x08070400. A four-byte branch replaces the
original finalizer entry; both overwritten instructions are complete.
The handler and recovered callees are also compiled replacements in this image.

* 576 direct cases compare original and compiled execution against an independent
  exact byte-write oracle. Length/capacity values include equality, overflow,
  zero and unsigned 0x80000000/0xffffffff boundaries.
* 1,680 integrated cases run the original table search and indirect call, the
  compiled handler/callees and compiled finalizer. Both tables, five contexts,
  four stored states, valid/invalid signatures, seven capacities and three flag
  patterns are covered. Final response length/header, non-stack RAM, write effects,
  return register, stack restoration and preserved registers must agree.
* A broken finalizer is detected through both tables. Unit regressions retain
  equality, overflow and unsigned comparison behavior.

Execution stops at 0x0802732a, immediately after the original call to finalization
returns. This is BOUNDARY_REACHED, not a return from the full dispatcher.
CI reruns the earlier 3,200 handler comparisons, 1,280 persistent calls and
5,120 bounded dispatch comparisons as prerequisites.

`finalize_validation.json` records source/harness hashes, original and hybrid
hashes, compiled bytes, patch bytes and complete changed ranges. Incoming-edge
scanning now includes the finalizer range and remains INCONCLUSIVE.

## Remaining work

Upstream frame parsing/CRC/mode selection, optional owner callbacks, actual
transport callbacks, interrupts and timing remain outside this experiment.
Memory allocation is synthetic; physical flash placement and recovery are not
validated. No modified device-update package is emitted.
