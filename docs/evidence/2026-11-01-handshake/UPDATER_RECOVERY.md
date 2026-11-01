# UPDATER_RECOVERY.md — official updater, acceptance checks, recovery (observed vs inferred)

Sources: `updater/official_packages.json` (APK inventory),
`updater/apk_dex_command_vocabulary.json` (printable-string scan of `classes.dex`,
SHA-256 `4a1c4ada…537c5`), `updater/firmware_md_update_path.md`,
`updater/deployment_cli_*.json`, fresh replies in `raw/handshake_experiment.json`,
`firmware/<target>/analysis/*` offline layers.

## Observed (byte-level facts)

1. Official containers (APK `assets/HardSoft/`): `rc-102z.bin` 130,148 B, SHA-256
   `67a43a50…5e392`, `Phyton` marker, header `date_time 0x5AE7428A`; the same bytes are the
   repo's `firmware/rc-102/hw1-fw4.14/rc-102z.bin`. Five more containers for the other five
   registered models are inventoried with sizes/hashes.
2. The dex string scan yields 62 command-style names, of which 22 carry the `FLASH_*` status
   enum; the update path in the app uses `0x0012 FW_IMAGE_GET_INFO`, `0x0101 RD_SIGNAT`,
   `0x0807 RD_HW_CONFIG`, and the `0x0013`/`0x0014` block-transfer pair (the latter two were
   never issued here; `0x0013` is not a read-only query).
3. Device-side identity fields, fresh (this bundle): `0x0012` replies `{size 130148, word
   4096, date_time 0x5AE7428A, crc32 0x13095ABB}` — every field equals the vendor container's
   header; `0x0101` replies `{0x5AE7428A, "rc-102.bin", "RadiaCode RC-102", "0"}`. The
   exchange marker `0xFF12FF01` / reply stamp `0xDADA0105` are the session constants.
4. Offline container checks (repo): L1 re-encode byte-exact (`analysis/roundtrip.json:
   byte_exact true`), header CRC and per-block CRCs match; the device confirms the
   `size / date_time / crc32` triple (`analysis/verification.json`, `analysis/container_check.json`).

## Inferred (explicitly not proven)

* The acceptance check the updater performs is plausibly the `size/date_time/crc32` triple
  (fields observed in `0x0012`) plus a model/name match (`"rc-102.bin"`, `"RadiaCode RC-102"`
  strings in `0x0101`). Whether the BOOTLOADER additionally enforces a cryptographic
  authentication over the image: **UNKNOWN** — no authentication-shaped strings or hash
  comparisons were located in the dex scan or in the disassembled update path; successful
  container encoding does NOT establish device acceptance.
* The `0x0013`/`0x0014` pair is the block write/verify channel used by the vendor updater
  (string evidence + the `FLASH_*` enum); their exact framing was captured before only in the
  2026-10-31 sweep notes (19 vs 21-byte records for `0x100` are the record stream, not the
  update path). Untested here by design.

## Recovery behaviour (what is documented vs unknown)

* `deployment/RECOVERY.md` + `updater/deployment_cli_recovery.json`: status
  `MANUAL_RECOVERY_REQUIRED`, `restore_supported: false`. The CLI cannot install or downgrade;
  official updates only; do not mass erase, alter option bytes, or overwrite a bootloader with
  `flash.bin`.
* Recovery entry when the application cannot boot: **UNKNOWN** from read-only evidence. No
  read-only id reports bootloader version beyond the `0x000A`/`0xFFFF0009` `{0,4}` pair;
  no captured trace exists (no update was initiated). Whether recovery preserves calibration
  (the `0x081C` areas and the VS `0x202` block) or only the application region: **UNKNOWN**;
  the calibration bytes live in area 1 / dedicated flash and are model-unit specific — no
  evidence shows which flash pages an official recovery rewrites.

## Consequences for the modified-firmware experiment

* A rebuilt image must reproduce the container header fields the device echoes (`size`,
  `date_time`, `crc32`) or the vendor updater's own checks are likely to reject it — that is
  the extent of the provable acceptance contract today.
* The bootloader region (`0x08000000-0x0800FFFF`) is absent from every artifact (padding
  only), so link layout, vector-table ownership and the FLASH_* page geometry cannot be
  completed from the application image alone: see NEXT_STEPS.md items 1-2.
