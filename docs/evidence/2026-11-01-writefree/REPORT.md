# RadiaCode device evidence — collection report

Collection session: 2026-11-01, host `ryans` workstation, Windows 11 (10.0.26200), Python 3.13.7.
Repository: `https://github.com/darkmatter2222/radiacode-firmware`, commit `3e9fbcd3b7c18a94d2b43c98d6e6652512bb271a`.
Package: `radiacode-device-evidence.zip` (this file is `REPORT.md` inside it).

## 1. Exact identity of the connected unit

| field | value | source |
| --- | --- | --- |
| model | RadiaCode-102 | BLE advertisement name `RadiaCode-102#RC-102-008228` (`raw/ble_scan.json`); USB iProduct `RadiaCode-102` (`hardware/usb_and_host_pnp.json`) |
| serial | `RC-102-008228` | BLE advertisement name; USB `iSerialNumber`; prior capture VS `0x008` |
| BLE address | `52:43:06:60:20:24` | scan |
| BLE GATT | service `e63215e5-…b901`, write `…e6`, notify `…e7`, 18-byte host writes | `raw/session_single_connection.json` |
| USB | VID `0x0483`, PID `0xF123`, bcdDevice `0x0200`, interface class FF/FF/FF (vendor-specific, no CDC COM port), driver `PHUSBDEV` (`oem41.inf`) | `hardware/usb_and_host_pnp.json` |
| application firmware | 4.14, build `Jul  7 2025 11:19:22` | prior capture `GET_VERSION` (`firmware/rc-102/hw1-fw4.14/analysis/capture.json`, taken 2026-10-31T12:17:54) |
| bootloader | 4.0, build `Feb  6 2023 15:49:14` | same `GET_VERSION` reply (id 0 = boot, id 14 = target; the two records carry separate build stamps) |
| container | `rc-102z.bin`, 130 148 B, whole-file CRC-32/MPEG-2 `0x13095ABB`, `date_time 0x5AE7428A` → 2025-07-07 08:20:20, `buffer_size 32768`, chunk 4096, 8 blocks, header CRC `8573b5f0`, SHA-256 `67a43a50…5e392` | `firmware/rc-102/hw1-fw4.14/blocks.json`, `updater/official_packages.json` |
| host radio | Realtek Bluetooth 5.4 Adapter | PnP enumeration |
| tools | bleak 3.0.2, capstone 5.0.9, unicorn 2.1.4, z3-solver 5.3.3.0, radiacode 0.4.0 (not used for the write-free pass) | `identity.json` |

Version-number decoding (verified against the raw reply, not assumed): `GET_VERSION` payload is two
records of `{u16 minor, u16 major, u8 len, char[len]}`. First record = `minor 0, major 4` → boot 4.0,
stamp `Feb  6 2023 15:49:14`; second = `minor 14, major 4` → target 4.14, stamp `Jul  7 2025 11:19:22`.
The field the repository calls “signature” (`RD_SIGNAT` `0x0101`) decodes to
`{date_time, "rc-102.bin", "RadiaCode RC-102", "0"}` — an image descriptor. It is **not** evidence of a
cryptographic signature; the only signature-like constant in the update path is the 4-byte exchange
sign `0xFF12FF01` (see §5).

The unit matches the repository’s registered target `rc-102/hw1-fw4.14` on every field the two
sources share (model, serial, fw/boot versions, container size/CRC/date). `identity.json` lists each
field with its provenance: `fresh-writefree` (this pass, no writes) or `prior-repo-capture`
(produced by `pipeline/step2_probe.py` on 2026-10-31 with the two documented session writes).

## 2. What the write-free pass could and could not read

The transport used here is the framing of `pipeline/rcble.py` re-implemented with per-frame logging
(`scripts/collect_writefree.py`, `collect_writefree2.py`, `collect_single_conn.py`): 18-byte GATT
writes, `u32 LE length | cmd u16 | 0x00 | seq | args`, no implicit traffic. The official `radiacode`
0.4.0 library was **not** used for the write-free pass because its constructor issues three
state-affecting commands automatically (`radiacode/radiacode.py` lines 105-107): `SET_EXCHANGE`
`0x0007` = `01 ff 12 ff`, `SET_LOCAL_TIME` `0x0A04`, and `WR_VIRT_SFR` `0x0825` with
`DEVICE_TIME = 0` — the last one resets the device’s own timestamp counter.

Observed, consistently (tabulated in `decoded/fresh_writefree_answer_table.json`):

| pass | topology | requests | `0x0005` data answers | `0x0006` NAK frames | no frame |
| --- | --- | --- | --- | --- | --- |
| A `raw/session_reads_writefree.json` | one connection per command | 26 | 1 | 0 | 25 |
| B `raw/session_writefree_v2.json` | connection per section, drain per request | 70 | 4 | 53 | 13 |
| C `raw/session_single_connection.json` | one persistent connection, persistent buffer | 99 | 5 | 94 | 0 |
| D `raw/session_reads.json` | earliest variant, frame bytes not stored | 119 | 0 | 0 | 119 |

* `0x0005 GET_STATUS` is the **only** documented read id that returns a data record without the
  session write: 10 answers in the 195 logged requests of passes A-C, every one with payload
  `00000000` and a correct header echo (`080000000500008000000000`). The prior capture at 12:17:54
  had `02000000`; it is a mutable status word, not an identification field.
* `0x000A`, `0x000B`, `0x0012`, `0x0101`, `0x0807`, `0x081C`, `0x0824`, `0x0826` return the same
  4-byte record every time: on the wire `04000000060000e0`, i.e. body `06 00 00 (seq | 0x60)` =
  record id `0x0006`, `n = 6`, index byte = the request's `seq` with `0x60` OR-ed in. That mapping
  holds on **all 147** NAK frames of the three logged passes (`decoded/fresh_nak_record.json`); in
  pass C the index byte walks `e1, e2, e3, e5, …` with the request counter, so the record is
  request-indexed rather than a periodic push - a drain-only wait with no request produced no frame.
  Its meaning is **not established**; the bytes are recorded as observed.
* The split does not depend on connection topology (fresh connection per command and one persistent
  connection give the same result), so it is a property of the session state, not of the reader. The
  prior capture, which issues `0x0007` + `0x0A04` first, gets full records from the same ids - hence
  the inference (labelled as an inference) that `SET_EXCHANGE` is what arms the record reader. That
  has not been isolated further without writes.
* Repeating a NAK’d id does not help inside the write-free pass: `0x000A` at `seq` `0x81`, `0x82`,
  `0x84` returns `0xe1`, `0xe2`, `0xe4` respectively - the same record with the new index
  (`raw/probe_nak_no_session_writes.json`), while `0x0005` twice in the same connection returns two
  clean data records (`raw/probe_one_command_per_connection.json`, `conn1_status_twice`). So the
  `0x0006` record is not a one-off synchronisation artefact of the reader.
* Every decoded value quoted later in this report therefore comes from the prior capture and is
  labelled as such; the fresh pass contributes the status word, the frame/NAK shapes and the
  transport facts.
* Command `0x0013` was never issued (per instruction). Note also that the value stored in
  `analysis/container_check.json` as `device_frame_count_0x0013 = 19` is exactly the command id
  (`0x13 = 19`), i.e. it is an id echo, and reading it as “19 frames” is **unresolved**, not confirmed.

Consequence: identity, configuration text, calibration, flash areas, VSFR values and the baseline in
this package come from `firmware/rc-102/hw1-fw4.14/analysis/capture.json` (prior capture, same
device, previous day) and are labelled `prior-repo-capture`. They are reproducible only if the
session write is permitted.

## 3. Preserved device state (all `prior-repo-capture`, raw + decoded)

`decoded/prior_capture_virtual_strings.json` holds raw hex, declared size, body length, SHA-256 and
decoded form for VS `0x002, 0x003, 0x008, 0x00D, 0x00F, 0x0F0, 0x100, 0x101, 0x200, 0x202, 0x203,
0x205, 0x206, 0x207, 0x208, 0x220`.

* Configuration text (VS `0x002`, 3256 B) is in `decoded/prior_capture_configuration_text.txt` and is
  byte-identical to the in-image copy at `0x0802F9F0` (extracted offline as
  `decoded/image_config_text_0x0802F9F0.txt`); `analysis/verification.json` records the 12/12 true
  checks including `config_text_matches_device`.
* Energy calibration (VS `0x202`, 12 B): `A0 = 5.15874719619751`, `A1 = 2.3756351470947266`,
  `A2 = 0.0003569310065358877` → keV per channel `5.159 / 7.535 / 246.292 / 1315.051 / 2808.972` at
  channels 0/1/100/512/1023 (`decoded/energy_calibration.json`). The same A0 also appears inside the
  76-byte `DEVICE_INFO` record (VS `0x0F0`/`0x203`), so that record carries the factory calibration
  set as well.
* Parameter areas: `decoded/prior_capture_flash_areas.json` keeps the raw XOR-obfuscated payload of
  `RD_FLASH_AREA` indexes 0 and 1 (72 B and 448 B, seed `0xF7FC032D` / `0xF7FC09E5`) plus the decoded
  text; indexes 2 and 3 return `status 12` (no such area). The 448-byte area 1 record contains the
  serial, `rc-102.bin`, `RadiaCode-102`, `RadiaCode`, the 0x05c4/0x0c17 sizes and a `0x83 0x04 0x23`
  word triple that is **not** yet interpreted (`firmware.md` §21 lists 5 unidentified words).
* Counters / dose / spectrum: VS `0x00D` (counters) and `0x101` (SFR file) returned size 0; the
  record stream `0x100` (1009 B) and the spectrum headers `0x200`/`0x205` (22 B) are preserved raw,
  and `0x100` is parsed per `firmware.md` §20 into 45-byte/21-byte records in
  `decoded/prior_capture_virtual_strings.json`.
* These exports are **not** a full device backup: they are the strings and areas the application
  itself exposes. SRAM, the flash word contents, the bootloader and the option bytes are not in them.

## 4. Memory coverage — acquired vs not acquired

`memory-map.csv` is the authoritative table. Summary:

| range | status | basis |
| --- | --- | --- |
| `0x08000000`-`0x0800FFFF` (64 KiB) | **NOT ACQUIRED** | `flash.bin` bytes here are zero padding; no supported read-only memory-read command exists (two full `0x0000`-`0x0FFF` sweeps are recorded in `analysis/sweep_*.json`) |
| `0x08010000`-`0x0803CA00` (8 blocks) | acquired from the **vendor container** | per-block CRC-32/MPEG-2 verified (`blocks.json`, all `crc_ok: true`) |
| `0x0803CA00`-`0x08040000` | zero in the container, physical state unknown | container block table |
| SRAM `0x20000000`+ | NOT ACQUIRED | only `InitialSP 0x20000800` from the vector table |
| option bytes / RDP | NOT ACQUIRED | no read-only id exposes them |
| parameter areas (indexed, not addresses) | acquired (XOR-obfuscated, seeded) | `0x081C` indexes 0/1 answer, 2/3 → status 12 |

No region is zero-filled and labelled as acquired: the zero ranges are explicitly marked
`NOT ACQUIRED` / `ZERO_IN_CONTAINER`. **A real bootloader dump does not exist in this package or in
the repository.**

## 5. Official update path (no update performed)

Primary sources: `official/apk.bin` (vendor Android APK, SHA-256 `d4a170cd…72cec`), `official/exe.bin`
(Windows app, SHA-256 `8fd1a886…7b24`), the decompiled application, and the repository’s reviewed
description (`updater/firmware_md_update_path.md`). Machine-readable extraction:
`updater/official_packages.json`.

* **Image selection.** The APK ships `assets/HardSoft/<model>z.bin` per model
  (`rc-101_v01`, `rc-102z`, `rc-103z`, `rc-103gz`, `rc-110z`, `rc-410z`). `assets/HardSoft/rc-102z.bin`
  has size 130 148 and SHA-256 `67a43a50…5e392` — identical to the repository container, which
  establishes the container’s provenance (asset entry, stored uncompressed, ZIP date 1981-01-01 01:01:02
  as written by the packing tool).
* **Integrity checks that are evidenced.** Whole-file CRC-32/MPEG-2 and per-block CRCs
  (`CRC Error: 0x%08X != 0x%08X` at `0x08027294`, three polynomial tables in the image), plus the
  4-byte exchange sign `0xFF12FF01` (`0x08027DA0`, `0x08028EEC`) and the four framing validators
  (`Error: S%d …` strings, `0x08037267`-`0x08037354`). The dex strings show the decision the app
  makes: `Firmware image signature match, CRC32 match` → nothing to do; `…, CRC32 mismatch, resetting`
  → transfer. “signature” here means that exchange-sign word, **not** a public-key signature; no
  asymmetric verification is evidenced anywhere in the strings or code.
* **Transport and framing.** Same NUS framing as the read path (18-byte GATT writes, length-prefixed
  frames); USB uses the vendor-specific interface with endpoint `0x01` OUT / `0x81` IN. Update ids:
  `FW_IMAGE_GET_INFO 0x0012`, `FW_IMAGE_UPDATE 0x0013` (staging session sized by `buffer_size` 4096),
  `FW_IMAGE_WRITE 0x0014` (`FW Image: Writing %d bytes at offset %d`, errors as
  `FW_IMAGE_WRITE returned error #%d` with the `FLASH_*` enum). 130 148 B / 4096 ≈ 32 chunks.
* **Address restrictions.** Every block in every container starts at `0x08010000` or higher, so the
  vendor update path does not touch the bootloader area (observed from the container block tables of
  all six registered builds).
* **Downgrade / interrupted-update behaviour.** Not established by read-only evidence. The strings
  `RECONNECTION_TIMED_OUT_DURING_UPDATE` and `Failed to boot device` exist; the app’s activation is
  gated on the CRC check (`firmware.md` §17/§18), but no redundant-image or atomic-activation
  mechanism is evidenced, and no trace was captured (capturing one requires an actual update —
  pending, see `NEXT_STEPS.md`).
* **Calibration/settings preservation.** The parameter areas keep their own seed + XOR stream and are
  written only through the VS/VSFR ids, i.e. they are separate from the code image; the config text
  is *compiled into* the application image at `0x0802F9F0`, so a different application build can
  change the reported configuration even when the areas survive.
* **Container decode ≠ acceptance.** The container decodes and re-encodes byte-exactly
  (`analysis/roundtrip.json`, `byte_exact: true`), which shows the *format* is understood; it does not
  show that a modified image would be accepted by the device.

`deployment` CLI (offline, `updater/deployment_cli_*.json`): `plan` returns `status: BLOCKED`,
`device_commands_sent: 0`, `complete_device_backup: false`, `restore_supported: false`, missing
`[bootloader, device calibration, device settings, option bytes, complete device flash readback]`, and
five blockers.

Validator and gate status on this host (captured as `updater/repo_unit_tests.txt`,
`updater/release_gate.txt`, `updater/repo_layer_status.json`):

| command | exit | reading |
| --- | --- | --- |
| `python -m unittest discover -s tests -v` | 1 | 53 tests, `FAILED (failures=1, errors=2)`; all three are environment artifacts on this machine (symlink privilege `WinError 1314`, cp1252 decode of a generated markdown file, generated guides differing after regeneration) |
| `python pipeline/release_gate.py` | **2** | `status: INCONCLUSIVE`, `release_ready: false`, 30 blocker lines - `firmware equivalence not established` and `original-vs-rebuilt hardware evidence absent` per target, plus per-artifact hash mismatches because the generated files were rewritten after the last manifest |

Per `docs/VALIDATION.md` and the current working rules in `agents.md`, **exit 2 means inconclusive /
evidence unavailable, not success** - the gate fails closed and a green test suite does not override
it. `ROADMAP.md` counts the reconstruction as seven compiled candidates (3,152 differential cases),
one floating-point predicate (10,947 bounded comparisons including full FPSCR) and one
emulator-only replacement bridge (1,424 direct and caller cases); the confidence roll-up for this
build is `extraction PASS`, `container_roundtrip PASS` (format only), `decoder_comparison
INCONCLUSIVE` (445 identical / 7,236 format-only / 1,830 unresolved), `python_differential PASS 8/8`,
`formal PASS 10/10` auxiliary model properties, `hardware SKIP`, with
`firmware_equivalence: NOT_ESTABLISHED`. Passing those software checks is not hardware certification.

## 6. Hardware evidence

`hardware/mcu_evidence_from_image.json`, `hardware/bootloader_pointers_check.json`,
`hardware/memory_sized_facts.json`, `hardware/usb_and_host_pnp.json`,
`hardware/repo_artifact_summary.json`.

* **Core, observed:** 98 vector entries at `0x08010000`, `InitialSP 0x20000800`, `Reset 0x0803BA71`,
  Thumb-2 only, `SCB->AIRCR = 0x05FA0004` constant present (`0x08027DC4`), CRC-32/MPEG-2 tables, and
  the system-memory literals `0x1FFF7590` (96-bit unique device ID), `0x1FFF75A8`/`0x1FFF75AA`
  (package/extra data), `0x1FFF75E0` (device ID/flash size registers) referenced from the code.
  ⇒ Cortex-M4F with the STM32L4 memory map, **observed**.
* **Family, inferred:** the image’s own peripheral names (LPUART2, LPTIM3/4/5, QUADSPI, DMA2D, LCD,
  AES, COMP, JPEG-class display path) with that IRQ numbering ⇒ STM32L4 7x/8x-class. The **exact
  orderable part number is not established by any read-only source** — `VSFR_SYS_MCU_ID0..2`
  (`0xFFFF0000..2`), which would carry the DEV_ID, does not answer in the write-free pass.
* **Does the app reach into the missing bootloader region?** 33 four-byte words in the image have
  values in `0x08000000`-`0x0800FFFF`; the disassembly shows **all 33 sit in instruction rows**
  (e.g. `0x0801F448: 0x0800C00C`) — they are Thumb encodings, not pointers. No `.word` data item and
  no branch target in the current listing points below `0x08010000`. So in the *disassembled* portion
  the application is self-contained above `0x08010000`; it is entered by a jump from the bootloader
  (which owns the reset at `0x08000000`). Caveat: the current listing covers 9 511 instructions in
  336 functions with 157 956 bytes unclassified, so absence in the listing is not proof of absence.
* **Board revision:** not established. No photograph of the PCB or the marking was available in this
  session; the USB string record gives the hardware serial (`0x002D0029 / 0x32325001 / 0x20313942`
  as three groups, ASCII tail `P22B91`) but no revision field.
* **SWD/JTAG pads, erase-page/bank geometry, external NVM, radio co-processor:** no read-only source
  in this session; recorded as pending.

## 7. Baseline (write-free, 60 s) and what it is not

The baseline loop is `scripts/collect_single_conn.py --baseline 60`: inside one BLE
connection, alternate a `0x0005 GET_STATUS` read with the rate/temperature/charger/timestamp VSFR
reads and the spectrum window strings, 2 samples, 60 s window. Result
(`decoded/fresh_baseline.json`, raw in `raw/session_single_connection.json`):

| field | sample 0 | sample 1 | note |
| --- | --- | --- | --- |
| `GET_STATUS` (0x0005) | `00000000` | `00000000` | the only id that answers |
| CPS `0x00008020`, DR `0x00008021`, DS `0x00008022`, TEMP `0x00008024`, CHARGER `0x0000C200`, DEV_TIME `0x00000504`, MS_RUN `0x00000603` | `null` | `null` | `0x0006` NAK frames |
| LIVE_WINDOW `VS 0x220`, SPECTRUM `VS 0x200`, DATA_BUF `VS 0x100` | `null` | `null` | `0x0006` NAK frames |

The two samples are `20.056` s apart (the request/response round trips inside the
connection fill the window). No numeric baseline was obtainable write-free, so the
count-rate/dose-rate/spectrum values quoted in section 3 are from the prior capture, not from this
baseline, and the fresh pass adds only the status word plus the NAK shapes.

Environment as far as known: device on the desk of the test host, powered (charger state was read as
`1` in the prior capture), stationary, no controlled source, no thermal control, `VSFR_MS_RUN = 0` in
the prior capture (the on-screen measurement was not running), `DBLag_ms = 180000`. No counters were
reset and no measurement was started or stopped. **This baseline is not an
original-versus-rebuilt equivalence test**; there is no rebuilt image on the device, and the
repository’s `hardware` layer is `SKIP` for exactly that reason.

## 8. Do the new data resolve the prior audit’s open items?

| prior audit item | status after this pass |
| --- | --- |
| only a small set of compiled C candidates | unchanged: `reconstruction/` still holds the leaf/hybrid/calibration candidates. In the emulator 8/8 cases pass (`analysis/confidence.json` `python_differential: PASS 8/8`): three constants (`0x080166CE`, `0x08017EF2`, `0x08017EF6`), three `0x08017EB4` transfer-state branches, the `0x0502` accessor push at `0x080275C4`, and `0x08028A4C` frame serialise - the last one labelled *partial execution to a substituted call*; 81 unique instruction addresses, no fault and no budget exhaustion, and the format layer passes 12/12 CRC-32/MPEG-2, 128/128 Mangle-inverse, 16/16 block round-trip, 8/8 LZSS decode, 13/13 MS-DOS date and 6/6 Borland-LCG vectors. Case applicability is bound to the **full image SHA-256** in `differential.json:provenance.inputs` (`flash 23c31b7d…157f6`), not to a byte prefix |
| emulator-only function replacement at `0x08070000` | unresolved: that address appears only in `reconstruction/HYBRID.md`, `validate_hybrid.py`, `validate_calibration.py` and `build_reconstruction.py` as a link address for the harness; no read-only source reports the physical flash/RAM size, so its availability on hardware is still unproven |
| no proof the address is available on physical hardware | unresolved for the same reason (see `hardware/memory_sized_facts.json`) |
| no implemented firmware writer / full-device backup in the deployment CLI | confirmed still true: `plan`/`deploy`/`restore` return BLOCKED with `device_commands_sent: 0` |
| no acquired bootloader | unchanged: **no bootloader bytes exist** (65 536 zero bytes stand in for it) |

Additional observation from this pass: `analysis/stats.json` (9 511 instructions / 336 functions) no
longer matches the counts quoted in `agents.md` (66 745 / 1 867) and `firmware.md`; the docs are
stale relative to the regenerated artifacts. The same file’s `unclassified_bytes: 157956` is the
honest size of the un-disassembled remainder.
The execution harness records two further constraints (both in `docs/VALIDATION.md`): read observers are
restricted to MMIO because a global RAM-read hook in Unicorn 2.1.4 changed the execution of
a conditional VFP load (pinned regression), and MMIO is plain RAM in that harness, so passing
MMIO cases cannot certify peripheral behaviour. Both are why the `hardware` layer stays `SKIP`.

## 9. Writes and state changes

* This pass: **no device writes at all** (`writes_issued: []` in all four `raw/session_*.json`
  files; 314 logged requests).
  The commands issued were `0x0005`, `0x000A`, `0x000B`, `0x0012`, `0x0101`, `0x0807`, `0x081C`,
  `0x0824`, `0x0826` — the documented read ids. `0x0013` was not issued.
* Documented, for the record, the writes a session normally implies (from
  `radiacode/radiacode.py` lines 105-107 and `pipeline/step2_probe.py` lines 45-48):
  `0x0007 SET_EXCHANGE` args `01 ff 12 ff` (opens the exchange session; without it most ids stay
  silent), `0x0A04 SET_LOCAL_TIME` args = 8 packed bytes `day, month, year-2000, 0, sec, min, hour, 0`
  (writes the RTC), and `0x0825 WR_VIRT_SFR` on `0x0504 = 00000000` (zeroes the device timestamp
  counter, which shifts the record-stream stamps). The prior capture used the first two.
* Repository-side file changes during this session: `python -m deployment …` wrote
  `updater/rc102-repository-archive.zip` (outside the checkout) and `pipeline/run.py --only 17`
  rewrote the generated `analysis/confidence.{json,md}`; no device state was involved.

## 10. Honest bottom line

1. The unit is a RadiaCode-102, hw/serial `RC-102-008228`, application 4.14 (built 2025-07-07),
   bootloader 4.0 (built 2023-02-06), and the repository container is byte-identical to the asset in
   the official APK.
2. A real bootloader dump does **not** exist. The 64 KiB gap is unacquired, not “known zeros”.
3. There is **no complete device backup**: the image is the vendor container’s decoded application
   only. Missing: bootloader, SRAM, option bytes, the physical contents beyond `0x0803CA00`, and any
   independent readback of the flashed words.
4. Device writes in this pass: none.
5. The device can be bricked. The evidenced protections are per-block CRCs and a CRC-gated activation;
   no dual-image or atomic-activation mechanism was found in the read-only evidence, and the update
   path is only reachable through the vendor application.
