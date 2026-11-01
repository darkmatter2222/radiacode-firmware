# HANDSHAKE_ANALYSIS.md — wire command 0x0007 (SET_EXCHANGE), instruction-level review

Reference build: `firmware/rc-102/hw1-fw4.14` — application image, base `0x08010000`,
`flash.bin` base `0x08000000` (image-file offset = `addr - 0x08000000`).
Application SHA-256 `23c31b7dabc59fe35a698cbd4f690498ded9bbb9f6590f3f2ea72ae5cfd157f6`.
Sources: `listing.s` (capstone), `decompiled.c` + `index.json` (Ghidra 12.2), raw word scans of
`flash.bin`, `analysis/tables.json`. Quoted lines are literal listing text, truncated to about
60 characters.

## 1. Dispatch: wire id 0x0007 -> handler 0x08027490

A static `{u32 id, u32 handler}` run was read directly from `flash.bin` at
`0x08037838..0x080378F8`. The id word carries a flag bit `0x80000000` OR-ed with the wire id
(observed encoding; `0x80000007` is the row for wire command `0x0007`). Relevant rows (raw words):

| id word | handler | wire id | note |
| --- | --- | --- | --- |
| 0x80000005 | 0x08027478 | GET_STATUS | |
| 0x80000007 | 0x08027490 | SET_EXCHANGE | reviewed below |
| 0x80000009 | 0x08027518 | (reset-like) | same magic word, different function |
| 0x8000000A | 0x080288E4 | GET_VERSION | |
| 0x8000000B | 0x080288A0 | GET_SERIAL | |
| 0x80000012 | 0x08028C04 | FW_IMAGE_GET_INFO | |
| 0x80000014 | 0x08028CEE | (excluded from the experiment) | |
| 0x80000101 | 0x08028814 | RD_SIGNAT | |
| 0x80000807 | 0x08028878 | RD_HW_CONFIG | |
| 0x8000081C | 0x08028960 | RD_FLASH_AREA | |
| 0x80000824 | 0x08027CE4 | RD_VIRT_SFR | per-item reader |
| 0x80000825 | 0x08028480 | WR_VIRT_SFR | excluded from the experiment |
| 0x80000826 | 0x08028672 | RD_VIRT_STRING | |
| 0x80000A04 | 0x08028AA8 | SET_LOCAL_TIME | excluded (clock write) |

`0x08027490` and `0x08027518` are not in the 336 vector-seeded entries of
`analysis/functions.json` (no `callers` rows): reachability is established only through this
dispatch table; call-graph status UNKNOWN. `analysis/tables.json` does not contain this table
(its 8 runs are elsewhere); the rows above were verified word-by-word against `flash.bin`
(`scripts/verify_dispatch.py`).

## 2. The magic word and the two candidate functions

`0xFF12FF01` occurs at exactly two addresses in the image:

| literal address | neighbouring words | used by |
| --- | --- | --- |
| `0x08027DA0` | prev `0x80000005`, next `0xDADA0105` | `FUN_08027490` (id 0x0007) and `FUN_08027518` (id 0x0009) — both load `DAT_08027da0` |
| `0x08028EEC` | prev `0x0800D050`, next `0x80000014` | pool of the `0x08028E40` serialiser area |

The dispatch table decides between the two: id `0x0007` -> `0x08027490`, id `0x0009` ->
`0x08027518`. They must not be confused (see §5).

## 3. FUN_08027490 body — effects with instruction addresses

`08027494  ldr.w r2,[pc,#...]` loads the magic from `0x08027da0`; the first argument word is
popped through the message cursor (`0802749e ldr.w r1,[r0,#-0x4]!` style read per `index.json`
C range 25903-25960) and compared (`080274a2 cmp r1,r2`, `080274a4 bne 0x08027508`).
Capstone prints byte rows (not instruction lines) for part of the function body — the mnemonics
below match the Ghidra SLEIGH listing (`analysis/ghidra_listing.json`) and the C; the addresses
are the byte-row starts. The 16-byte rows carry the values quoted.

Match path, in order:

1. `080274ae-080274b4`: `ldr r1,[r0,#0x4]` / `orr r1,r1,#0x2` / `str` —
   `[0x2000DFF8] |= 2` (RAM exchange/session flag; literal `0x08027d6c -> 0x2000DFF4`).
2. `080274bc str r1,[r0,#0x0]` — reply word 0 = `0x80000007` (literal `0x08027da8`).
3. `080274be str r2,[r0,#0x4]` — reply word 1 = `0xDADA0105` (literal `0x08027da4`).
4. `080274ce orr.w r3,r3,r2,lsl #0x10` + `080274d2 str r3,[r0,#0x8]` — reply word 2 =
   message-block field `[mb,#0x10] | (([mb,#0xc]-0x20) << 16)`.
5. `080274da ldrb r0,[r1,#0x0]` (transport/context byte), `080274dc bl 0x08029370`,
   `080274e0 str r0,[r5,#0x0]` — reply word 3.
6. Branch on the transport/context byte:
   - `= 1`: `080274ee strb r0,[r1,#0x0]` clears the pending byte in the context slot, return.
   - `= 2`: `080274f6 bl 0x08029086`, then `080274fe ldrb r0,[r1,#0xd]` (r1 = literal
     `0x08027DAC` = `0x20000820`) and (if zero) `08027504 strb r2,[r1,#0xd]` —
     `[0x2000082D] = 1`. Return at `08027506`.
   - other: fall through, return at `08027516`.
7. Mismatch path: `0802750a ldr.w r0,[0x08027d98]`, `08027512 str` — single error word
   `0xE0000006`.

Observed live reply body (this package, `raw/handshake_experiment.json`):
`0501dada2010001001020000` = reply w1 `0xDADA0105` (stamp), w2 `0x10001020`
(`[mb,#0x10] | (([mb,#0xc]-0x20)<<16)`), w3 `0x00000201` = `FUN_08029370(T)` return.
Exact word-3 semantics: with S = byte[`0x20000C0D`] and T = message-block byte 0,
`return = ((T==S) || (S==0) ? 1 : 0) | (S << 8)` (emulator-verified: S=2,T=2 -> `0x201`;
S=2,T=0 -> `0x200`; S=0,T=0x55 -> `0x01`). The low byte is an equality/S==0 flag, **not** a
raw copy of the context byte; the high byte is the stored byte S. `0x201` therefore forces
S = 2 and, since S != 0, the equality T == S, hence T = 2 — the stored byte and the branch
byte are different sources that the reply shows agreeing. The branch itself re-loads T
(`0x080274e4 ldrb r0,[r1]`).

Callees:

| function | range | what it does | stores |
| --- | --- | --- | --- |
| `FUN_08029370` | `0x08029370-0x08029386` | pure value function: S = byte[`[0x080293FC]`+0x0d] (pointer word `0x20000C0C` -> byte at `0x20000C0D`); `08029374 cmp r0,r1` (T vs S), match -> 1, else 1 iff S==0; `08029382 orr.w r0,r0,r1,lsl #0x8`; `08029386 bx lr` | none (return-value-only; 0 writes in the emulator) |
| `FUN_08029086` | `0x08029086-0x0802909C` | clears queue/link state: `0802908c strb r0,[r2,#0x0]`, `08029094 str r1,[r0,#0x14]`, `0802909a str r2,[r0,#0x0]` (`[head] &= ~4`), tail `0802909c b.w 0x08022e60` | RAM only (`0x2000DFD0`, `0x20000908` heads) |
| `FUN_08022e60` | `0x08022e60-0x08022e64` | thunk: `08022e60 ldr r0,[pc,#0x5c]` (`0x20000858`), `08022e62 b.w 0x08016780` | — |
| `FUN_08016780` | `0x08016780-0x080167A4` | unlinks the node at `0x20000858` from the list head `[0x2000DFA8]`: `0801678c/0801679c str`, `080167a0 strb`, `080167a2 str`, `bx lr` | RAM only (pool free) |

## 4. Effect classification for 0x0007

| class | finding |
| --- | --- |
| RAM session state | `[0x2000DFF8] |= 2` (0x080274AE-080274B4); reply words (0x080274BC/BE, 0x080274D2, 0x080274E0); error word (0x08027512); pending-byte clear (0x080274EE); `[0x20000820+0xd]=1` (0x08027504); `FUN_08029086` stores (0x0802908C/94/9A); `FUN_08016780` unlink (0x0801678C-A2) |
| peripheral (MMIO) init | none observed on this path |
| persistent (flash/NVM) write | none: no FLASH_* program/erase helper and no AIRCR write is reachable from `0x08027490` |
| clock/RTC change | none observed (`FUN_08029370` only reads; the RTC writers sit behind other ids, e.g. `0x0A04`) |
| measurement-counter reset | none observed; roles of the `0x2000DFD0` / `0x20000908` list heads beyond queue/pool bookkeeping: UNKNOWN |

Consequence observed on the device: `GET_STATUS` returns `0x00000002` once the flag word has
bit 1 set (`0x00000000` in the power cycle before any `0x0007`). The identity of the `GET_STATUS`
value word with `0x2000DFF8` is consistent with, but not proven by, the instruction walk.

## 5. Adjacent FUN_08027518 (id 0x0009) — the reset-like function

Same magic compare (`DAT_08027da0`), different shape: on match it calls `FUN_080273d2`,
`FUN_080188fe`, `FUN_0801919a`, `FUN_0801c83c`, `FUN_08016586`, then writes the marker values
`0xaaaa` / `0x55aa` / `0x5a5a` into literals, sets/clears bit `0x100` of `*DAT_08027db8`,
executes `DataSynchronizationBarrier(0xf)`, spins on `FUN_0801671a`, and consumes the AIRCR
key word `0x05FA0004` (literal word at `0x08027DC4`; use instructions around
`0x080275A0-0x080275B0`, self-loop near `0x080275B8`). This is a system-reset-shaped tail —
id `0x0009` was therefore excluded from the experiment; it was never sent.

## 6. Unresolved paths (recorded, not guessed)

1. Indirect `blx` without a static target inside the walked range: `0x080272C0`
   (`[ctx+0x18]`), `0x0802733C` / `0x08027416` (driver slot `[mb+0x14]`), `0x08027434`
   (`[0x0800D010+0x18]`).
2. Level-2+ callees not expanded: `0x0801814C`, `0x08020F70`/`0x08020F94`, `0x0802af36`,
   `0x080189dc`.
3. `listing.s` prints byte rows (no instruction lines) over parts of the walked range
   (`0x08027496`-`0x080274f6`, `0x08027CE4`+, `0x08029086`+, `0x08029370`+); mnemonics there
   come from `analysis/ghidra_listing.json` (L2 tier), not capstone.
4. `FUN_08027490` / `FUN_08027518` have no `callers` rows in `analysis/functions.json`;
   reachability rests on the dispatch table above.
5. id `0x0009` is absent from `protocol.ANSWERING` although its replies are non-zero — the
   gate that adds ids to that list was not located; UNKNOWN.
6. The second-stage table at `0x08038CD4` (ids 1..B -> `0x08034xxx`) was not traced to a
   consumer.
7. The message-block static base `0x0800D000`/`0x0800D010` lies in the zero-filled region of
   `flash.bin`; the runtime RAM mirror address is UNKNOWN.
8. Transport byte values 1 and 2 map to timeout constants `0x28000`/`0x1e0000` near
   `0x08029388`; which physical interface each denotes is inferred (the NUS capture shows 2),
   not name-confirmed.
