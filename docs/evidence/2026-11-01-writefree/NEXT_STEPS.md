# NEXT_STEPS — missing evidence and the least disruptive way to get it

Ordered by information-per-risk. “Write-free” = no device write; each item states what it unblocks.

## N1. One approved session write, then re-read the read-only set (highest value, lowest risk)

* Action: issue exactly one frame — `cmd 0x0007`, args `01 ff 12 ff`, seq `0x80` — then the same
  read ids already used (`0x0005`, `0x000A`, `0x000B`, `0x0012`, `0x0101`, `0x0807`, `0x081C` ×0-3,
  `0x0824` per VSFR, `0x0826` per VS). Skip `0x0A04` and `0x0825` unless the wall-clock/timestamp
  stamps are needed (they change the RTC and the record stamps).
* Why: with the exchange sign accepted, the bulk ids answer, so identity, calibration, the two
  parameter areas, the record stream and the VSFR block (including `VSFR_SYS_MCU_ID0..2` at
  `0xFFFF0000..2`, which is the DEV_ID and would pin the exact MCU) come back in one pass.
* Unblocks: fresh same-pass identity (§2), the 60 s baseline with real rates (§7), the MCU DEV_ID (§6).
* Cost: two 18-byte GATT writes at most; no flash operation is involved.
* Cheap test to run first, still with one write: the `0x0006` record’s index byte equals
  `seq | 0x60` on all 147 NAK frames of this pass (`decoded/fresh_nak_record.json`), so the device
  keeps its own record index. After granting the single `0x0007` write, replay one NAK’d id once and
  compare the index byte, which tells whether the index alone resynchronises the reader or whether
  `SET_EXCHANGE` is genuinely the gate.
* Reference for that first reply: the repository’s own `analysis/probe_raw.json` records the answer
  to `0x0007` + `01 ff 12 ff` as `0501dada2010001001020000` (a data record, not the `0x0006` form),
  so the handshake itself is answered and can be diffed against a re-run.

## N2. Repeated-read stability for the mutable records

* Action: read `0x100` (record stream), `0x220` (window), `0x0F0` (device info) and `0x202`
  (calibration) five times, 1 s apart, and diff the SHA-256 per id.
* Why: the record stream and window grow with uptime; calibration and the config text must be
  byte-stable. `decoded/prior_capture_*.json` has only 2-3 samples.
* Unblocks: a defensible “stable vs mutable” split for a future backup policy.

## N3. Bootloader region — 64 KiB at `0x08000000`

* Status: no supported read-only id returns memory; two full `0x0000`-`0x0FFF` id sweeps are recorded
  in `analysis/sweep_noarg.json` / `sweep_witharg.json` and none of the 13 answering ids is a memory
  read.
* Least disruptive options, in order:
  1. Ask the vendor for the bootloader image with its version stamp (`4.0`, built 2023-02-06) — no
     hardware action at all.
  2. Read the shipped container’s own fields again after N1 (`0x0012` gives size/date/CRC of the
     *application* container only, so it cannot fill the gap).
  3. Attach an SWD debugger (ST-LINK/J-Link) and read `0x08000000`-`0x0800FFFF`, the DEV_ID at
     `0xE0042000`, the unique ID at `0x1FFF7590`, and the FLASH option bytes at `0x1FFF7800`/`0x1FFF7810`.
     This is still read-only, but it needs the pads/connector and separately granted permission.
* What it would prove: whether the bootloader validates an image beyond CRC, whether it can be
  rewritten through `0x0012`-`0x0014`, and the true flash/RAM geometry (which also settles the
  `0x08070000` harness address).

## N4. Physical board identification

* Action: photograph the PCB silkscreen + MCU marking under raking light; record the marking lines.
  Note the pad pattern (SWD: `SWDIO`/`SWCLK`/`GND`/`VDD`, plus `BOOT0` if broken out).
* Unblocks: exact MCU part, board revision, external NVM / radio part, and the recovery pins.
* Alternative with no opening: DEV_ID via N1 (`VSFR_SYS_MCU_ID0..2`) gives the 12-bit DEV_ID, which
  narrows the part number for STM32L4 to one or two orderables.

## N5. Update-path traces without an update

* Action: with the vendor application already installed, capture the USB/BLE frames that the *existing*
  app exchanges during its “check for update” step, which is read-only on the device side
  (`0x000A`, `0x0012`), and keep the app’s own log files. Do not press “update”.
* Additions worth extracting offline: `classes.dex` string table around `FWProgressUpdater` /
  `EVT_FW_WRITE` (already partially extracted), and the `FLASH_*` enum ordering, which maps the
  numeric error codes in `FW_IMAGE_WRITE returned error #%d` to names.
* Pending, requires an actual update: the interrupted-update behaviour (power loss at each chunk
  boundary), whether `0x0013` opens staging idempotently, the exact write-address validation, and the
  recovery path when the application cannot boot. Use a sacrificial unit for these.

## N6. Firmware-writer implementation prerequisites (repository work)

* Implement the two-step session (`0x0007`, optional `0x0A04`) + read `0x0012` in
  `deployment/cli.py` as a *read-only* connect-and-verify command, with the existing 18-byte framing,
  and hash the results into the archive. This is the only way `deployment` can ever claim an identity
  match instead of `endpoint_is_verified_identity: false`.
* Then `SAFETY.md`’s checklist for a writer: reviewed writer, memory map with protected ranges,
  backup policy including the bootloader (N3), a recovery route independent of the application, and
  the injected-failure test matrix. Until then `plan`/`deploy`/`restore` must keep returning BLOCKED.

## N7. Small documentation corrections found during this pass

* `analysis/stats.json` (9 511 instructions, 336 functions, 157 956 unclassified bytes) disagrees with
  the numbers quoted in `agents.md`/`firmware.md` (66 745 / 1 867); regenerate or annotate.
* `container_check.json: device_frame_count_0x0013 = 19` equals the command id `0x13`; label it
  “echoed id, interpretation unresolved” rather than a frame count.
* Repository tests currently show 1 failure + 1-2 errors on this host for environment reasons
  (symlink privilege, cp1252 default encoding) — pin `encoding="utf-8"` in `tests/test_navigation.py`
  and skip the symlink test when unprivileged so the gate is reproducible.
