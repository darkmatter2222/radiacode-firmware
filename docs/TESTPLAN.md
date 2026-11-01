# Staged hardware validation plan (for a spare unit of the same revision)

No step below was executed during the offline work; the plan is prepared for a later,
separately authorized session. Equipment: the unit under test, a second identical unit as
reference, a stable USB host with the official application, a `Cs-137`/`Am-241` check source,
and (only if §5 of `docs/HARDWARE.md` requires it) an ST-LINK/V2 with 1.8 V tolerant lines.

## Stage 0 — prerequisites

Record model, serial, hardware revision, firmware and bootloader version from the official
application; keep the vendor container files and the repository archive, and verify the
archive checksum. *Proves:* the identity pair the artifacts are bound to. *Does not prove:*
anything about flash contents (the archive is not a readback).

## Stage 1 — preserve accessible device-specific data

Read `GET_VERSION`, `GET_SERIAL`, `GET_STATUS`, `FW_IMAGE_GET_INFO`, the config text
(VS `0x002`), the two `0x081C` areas and the VSFR list, then store the raw hex per command.
*Proves:* a byte-exact before-image of everything the protocol exposes. *Does not prove:* the
contents of memory the protocol does not serve — there is no raw memory-read command, so the
bootloader, the option bytes and the calibration block behind `0x081C` remain unrecorded.

## Stage 2 — restore path for the known-good original

Run the official update with the *same* version that is already installed, then confirm the
device boots, answers every supported id, and matches the Stage-1 values.
*Proves:* whether the vendor path accepts a same-version image and what survives it.
*Does not prove:* that a hand-built image is accepted, nor that an arbitrary older version can
be restored.

## Stage 3 — recovery when the application cannot communicate

With the original image restored (Stage 2), note the exact official recovery steps for a
non-answering device as documented by the manufacturer, and stop. Only if the device is a
spare and the failure is reproduced deliberately: record whether the device reappears on BLE
after a power cycle, whether the official application detects it in bootloader mode, and which
version the bootloader reports.
*Proves:* the concrete recovery path for this board and whether it preserves Stage-1 values.
*Does not prove:* behavior under a partially written image unless that exact state is produced.

## Stage 4 — smallest approved modification

Candidate: the reviewed return-only state helper at `0x08029370` (see
`reconstruction/INTEGRATION.md`). Two deployments are possible and must be tried in order:

1. in-place, 24 code bytes at `0x08029370` with the existing literal word at `0x080293fc`
   reused (no other byte changes);
2. if the in-place layout cannot be produced reproducibly, the trampoline variant with the
   body at a *measured* free address (the region must first be shown unused by the Stage-1/2
   evidence, not assumed).

*Proves:* that a source-compiled replacement can be installed, that the device still starts,
and that the changed routine behaves identically from the outside. *Does not prove:* whole
firmware equivalence; only this routine was tested.

## Stage 5 — behavior checks after the modification

Startup; BLE enumeration and the NUS handshake; `GET_VERSION`/`GET_SERIAL`/`GET_STATUS`;
config text and calibration equality against Stage 1 (byte compare); one measurement run with
the check source compared against the reference unit (counts within the declared tolerance,
spectrum peak positions and the temperature reading); charger state and device time; then a
30-minute idle soak with periodic reads.
*Proves:* communication, identity, calibration preservation, measurement sanity, short-term
stability. *Does not prove:* long-term drift behavior, low-power-state behavior, or the
correctness of the numeric models beyond the tested points.

## Stage 6 — restore the original and confirm

Restore the vendor original through the official path and repeat the Stage-5 checks.
*Proves:* reversibility of the modification through the intended mechanism. *Does not prove:*
reversibility of a partially transferred or truncated image.

## Reporting rules

For each stage keep: timestamp, application version, raw frames per command, the file hashes
of the container and image in use, and the pass/fail line per check. A stage is *inconclusive*
when a value cannot be obtained (exit code 2 semantics), not a pass. Any deviation between the
modified and the reference unit is written down as observed, not corrected toward expectation.
