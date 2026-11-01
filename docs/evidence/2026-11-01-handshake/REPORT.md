# REPORT.md — fresh evidence after the reviewed handshake (2026-11-01)

Bundle: `radiacode-device-evidence-followup.zip` (this directory holds the unzipped copies plus
the ZIP and `CHECKSUMS256.txt`). Unit: RadiaCode-102 `RC-102-008228`, BLE `52:43:06:60:20:24`,
fw 4.14, boot 4.0. Companion (historical, unchanged in meaning):
`docs/evidence/2026-11-01-writefree/`.

## 1. Provenance labels

| label | meaning |
| --- | --- |
| `fresh-handshake` | acquired 2026-11-01T14:12:52 -> 14:14:03 local, single BLE connection, `raw/handshake_experiment.json` |
| `fresh-handshake (run 1)` | crashed collector run of the same experiment; it issued the one `0x0007` frame of its connection and nothing else (its frames are NOT in the surviving JSON) |
| `prior-repo-capture` | `firmware/rc-102/hw1-fw4.14/analysis/capture.json`, taken 2026-10-31T12:17:54 with the documented session writes — quoted, never relabelled as fresh |
| `offline` | computed from files already in the checkout |

Writes issued by the experiment: exactly one frame per connection, command `0x0007`
(SET_EXCHANGE), args `01 ff 12 ff`, sent once per connection with no retry and no silent
reconnect. Over the whole session `0x0007` reached the device twice: once in run 1 (which then
crashed in its own JSON assembly) and once in the final run. `0x0A04`, `0x0825`, `0x0013`,
`0x0014` and every `FLASH_*` id were never sent. The transport is the minimal one
(`scripts/handshake_experiment.py`): 18-byte NUS chunks, `u32 LE len | cmd u16 | 0x00 | seq`,
no library constructor, so no implicit initialization exists.

## 2. Handshake gate result (the experiment this package was made for)

* `0x0007` answered: request wire `080000000700008201ff12ff`, reply body (12 bytes)
  `0501dada2010001001020000` — byte-identical to the repo probe record
  (`analysis/probe_raw.json`), so the reviewed path is the executed path
  (`HANDSHAKE_ANALYSIS.md`).
* After that single write every supported read id answered: final run 898 requests / 898
  matching replies / 898 frames, zero NAK frames (`06 00 00 …`), versus 195 requests / 10
  answers in the write-free passes. The NAK-vs-answer transition across one connection is the
  isolating evidence that the session flag — not time or luck — gates the readers.
* `GET_STATUS` returned `0x02000000` at BOTH pre- and post-handshake reads in the final run:
  the exchange flag lives in RAM and survived the reconnect, set by run 1's write within the
  same power cycle. The write-free passes (before any `0x0007` since power-on) had seen
  `0x00000000`. Consistent with the flag word `[0x2000DFF8] |= 2` of the review; identity of
  the two words not proven.

## 3. Freshly acquired values (all `fresh-handshake`)

* Identity — `GET_SERIAL` (0x000B) payload `29002d00 01503232 42393120` (three words, same as
  VSFR `0xFFFF0000-0xFFFF0002`); `RD_HW_CONFIG` (0x0807) `0f00000000000000000001e8030000`;
  `FW_IMAGE_GET_INFO` (0x0012) decodes to `{size 130148, buffer word 4096, date_time
  0x5AE7428A, crc32 0x13095ABB}` matching the vendor container `rc-102z.bin` (SHA-256
  `67a43a50372622140ec5604f97d81be9042ae6291fa5f689f147db4f1ce5e392`); `RD_SIGNAT` (0x0101)
  `{0x5AE7428A, "rc-102.bin", "RadiaCode RC-102", "0"}` — a descriptor, not a cryptographic
  signature. `GET_VERSION` (0x000A) = boot `{id 0, version 4, "Feb  6 2023 15:49:14"}` and
  target `{id 14, version 4, "Jul  7 2025 11:19:22"}`. All six ids repeat byte-identical in the
  repeat phase (8/8 SHA matches) and equal the prior capture's values.
* Configuration text — VS `0x002`, 3,256 bytes, body SHA-256
  `c7b7228ad8a6c087c76e404b7f47d20266f20096deab9f19c08e2a250754fa99`: identical to the prior
  capture and equal to the bytes at `0x0802F9F0` in `flash.bin` (checked in
  `decoded/consistency_report.json`). Exact bytes: `decoded/fresh_configuration_bytes.hex`;
  decoded text (cp1251 -> UTF-8, LF): `decoded/fresh_configuration_text.txt`; the raw body is
  not valid strict UTF-8 (0xF1 at offset 226 -> cp1251 'c'), so the text file records both the
  strict-decode status and the cp1251 decoding.
* Energy calibration — VS `0x202` (12 bytes `7514a540680a18407822bb39`): A0 =
  5.15874719619751, A1 = 2.3756351470947266, A2 = 0.0003569310065358877; keV at channels
  5.159 / 7.535 / 246.292 / 1315.051 / 2808.972 (`decoded/fresh_energy_calibration.json`).
  Equal to the prior capture's `0x202`. The same 12 bytes occur inside VS `0x200` and
  `0x205` (offsets in the decoded file).
* Other virtual strings: `0x008` = "RC-102-008228"; `0x00D`/`0x101` = empty (size 0); `0x003`
  = raw `00000000`; `0x0F0` (76 B) and `0x203`/`0x208` stable and equal to prior; `0x00F`,
  `0x100`, `0x200`, `0x205`, `0x206`, `0x207`, `0x220` differ from the prior capture — they are
  the live event/record/spectrum streams and are NOT expected to repeat.
* Readable parameter areas (`0x081C`): index 0 (72 B) and index 1 (448 B) decode via the
  Borland-LCG XOR; index 1 contains the ASCII `RC-102-008228`. Indexes 2 and 3 reply with
  status word 12 (not served). Seeds differ per session by design (`0xB5444133`, `0xB5444600`).
* VSFR snapshot (`decoded/fresh_vsfr.json`, format: reply word 0 = item count 1, word 1 = the
  value; observed pattern, per-field semantics per the in-image VSFR map at `0x080306AC`):
  `0x500`=1, `0x502`=1, `0x503`=1, `0x504`=65,708,084, `0x700`=3, `0x510`=5, `0x511`=9,
  `0x603`=0, `0x8020`=0.0, `0x8021`=0, `0x8022`=0, `0x8024`~24.26 degC, `0xC000`=28,346 mV,
  `0xC001`=677, `0xC002`=0, `0xC200`=1; system block `0xFFFF0000`=0x002D0029,
  `0xFFFF0001`=0x32325001, `0xFFFF0002`=0x20313942 ("B91 "), `0xFFFF0005`=0xDADA0105,
  `0xFFFF0006`=0x5AE7428A (equals the container `date_time`), `0xFFFF0007`/`8`=4128,
  `0xFFFF0009`={0,4}, `0xFFFF000A`={14,4}, `0xFFFF000B`=2, `0xFFFF000C`=2111,
  `0xFFFF000D`=2328. The `0xFFFF0000-2` words are the vendor's device-id block (same bytes as
  `GET_SERIAL`); mapping 0x0029 to one exact STM32L4 part number is a datasheet step left
  UNPROVEN here.
* Baseline (60 s, 83 samples, counters untouched, `decoded/fresh_baseline.json`):
  `GET_STATUS` constant `0x02000000`; `CPS`/`DR_uR_h`/`DS_uR`/`MS_RUN` constant 0 (no
  measurement active — the MCA was not started, so no counter was consumed); `TEMP_degC`
  24.2633-24.2681 degC; `0x504`/VS `0x220` monotone (record/timestamp stream: delta
  59,979 over 59.983 s -> 1 ms units fits; unit inferred, not proven).

## 4. Offline facts added by this package

* Listing coverage is now classified by real spans (start<=addr and addr+4<=end over parsed
  `listing.s`): of the 33 `0x0800xxxx` words, 25 sit inside `.byte` data rows, 7 span two rows
  (partial), 1 spans an instruction row boundary; zero rows were silently defaulted to
  "instruction" as the first script did. A word scan still does not prove a runtime pointer —
  classification only (`hardware/bootloader_pointers_check.json`).
* Geometry facts (`hardware/memory_sized_facts.json`): acquired application range
  `0x08010000-0x0803CA00` (182,784 B), zero padding below `0x08010000` = 65,536 B
  (padding, NOT acquired bootloader content), 8 container blocks, initial SP `0x20000800`.
  The word `0x08070000` occurs 0 times in the image; eight words lie between
  `0x0803CA00` and `0x08080000`. Physical flash size, erase-page geometry and the
  availability of `0x08070000` remain UNPROVEN from read-only evidence.

## 5. What this package is not

`flash.bin` is a container-decoded image with a zero-padded first 64 KiB — it is not a device
backup. No memory-read command exists (`0x0013`/`0x0014` never sent), so no bootloader, SRAM,
option-byte or RDP state was acquired: no complete persistent-state backup exists. The release
gate stays closed (exit 2, `firmware_equivalence: NOT_ESTABLISHED`, `hardware: SKIP`).
Communication success + passing offline layers still do not establish full device
functionality of any rebuilt image.
