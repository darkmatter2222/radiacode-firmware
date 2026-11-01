# Firmware deployment preparation CLI

**This version prepares and verifies local firmware archives. It cannot flash,
restore, connect a device session, or read back a complete device.** Deployment
and restore commands return `BLOCKED` without contacting hardware. There is no
`--force` override. Nothing here makes firmware installation impossible to brick.

This directory is separate from raw decompilation and reconstructed C. Start from
the repository root with Python 3.10 or later. Offline commands use the standard
library and do not need USB/Bluetooth packages.

## What works today

| Operation | Availability |
| --- | --- |
| List repository firmware builds and inspect image hashes | Implemented, offline |
| Archive original repository container and decoded application image | Implemented, offline, checked against pinned catalog |
| Verify an archive, detect corruption and wrong model | Implemented, offline |
| Enumerate Bluetooth advertisements or USB devices | Implemented, optional dependencies; no hardware tested here |
| Connect and verify serial, board, bootloader and battery | Not implemented |
| Back up complete device flash, bootloader, calibration and settings | Not implemented |
| Upload custom firmware, select a version to install, downgrade or restore | Blocked |

An archive is **not a complete device backup**. It preserves the known repository
firmware, which may differ from the firmware installed on your device. The padded
`flash.bin` is not a physical flash dump and must not be written as a whole-chip
image. See [recovery instructions](RECOVERY.md) and the
[requirements for enabling writes](SAFETY.md).

## Step 1: check capabilities and choose a build

```sh
python -m deployment capabilities
python -m deployment targets
```

Select the exact key from the list. Examples below use `rc-102/hw1-fw4.14`.
RC-410 uses `rc-410/fw4.16`; neither is automatically compatible with another
hardware revision. Unknown hardware fields mean unknown, not unrestricted.

## Step 2: preserve original files before doing anything else

Choose a new output path outside the checkout, ideally on independent storage:

```sh
python -m deployment backup --target rc-102/hw1-fw4.14 --source repository --output ../rc102-original.zip
python -m deployment verify-backup ../rc102-original.zip
```

The CLI verifies the source hashes, creates the archive exclusively (never
replaces an existing path), flushes it to disk, and reads it back for verification.
Copy the archive to a second storage location and run `verify-backup` on that
copy too. A power failure during creation may leave an incomplete archive; verify
it and create a new filename if necessary. Hashes detect corruption; they do not
protect against someone replacing both the program/catalog and its inputs.

The JSON result explicitly lists missing device-specific content. Requesting
`--source device` returns exit 2 and creates no backup. It does not silently
substitute repository files. Export spectra, logs and supported settings using
vendor software separately; this does not establish a restorable calibration backup.

## Step 3: inspect the proposed image

```sh
python -m deployment inspect --target rc-102/hw1-fw4.14 --image firmware/rc-102/hw1-fw4.14/rc-102z.bin
```

Recognition requires an exact catalog size and SHA-256 match. Modified builds
remain unrecognized. Even recognized vendor bytes are not approved for your
physical device merely because a filename or hash matches.

## Step 4: optional USB or Bluetooth discovery

Only these commands interact with host hardware. Close competing applications
if discovery fails. Do not detach USB drivers or change device modes to make
this CLI work.

```sh
python -m pip install bleak
python -m deployment discover --transport bluetooth --live
python -m pip install pyusb
python -m deployment discover --transport usb --live
```

USB also needs a platform-compatible libusb backend. Missing dependencies,
permissions or adapters produce an error with no fallback. USB enumeration lists
all USB descriptors; Bluetooth discovery lists advertisements. Neither proves a
device is a Radiacode or authorizes selecting it. Bluetooth addresses can change.
No discovery result is automatically selected or connected.

## Step 5: run offline preflight

```sh
python -m deployment plan --target rc-102/hw1-fw4.14 --image firmware/rc-102/hw1-fw4.14/rc-102z.bin --backup ../rc102-original.zip --transport usb --endpoint YOUR_DEVICE_IDENTIFIER
```

Use `--transport bluetooth` to record that intended transport instead. The
endpoint is recorded as an unverified user claim. This command verifies the
archive and hashes the candidate, then reports all outstanding blockers. Exit 2
is expected. The report is not executable and cannot authorize deployment.

`deploy` and `restore` accept the same arguments and perform the same offline
checks, then refuse. They do not open a device connection. No upload/resume/erase
implementation exists behind these commands. An edit to a report or a successful
repository test cannot enable one.

## Step 6: installation or recovery

For an official update, use the manufacturer's supported application and
model-specific instructions. This CLI cannot pass its archive to that app or
promise the app supports an older version. For custom firmware, stop at the
blocked preflight until [all write prerequisites](SAFETY.md) are implemented and
verified. Read [RECOVERY.md](RECOVERY.md) before any update.

```sh
python -m deployment recovery
```

Exit codes: **0** requested offline/discovery operation completed (not deployment
approval); **1** error or failed integrity; **2** blocked/unavailable or invalid
CLI syntax; **130** interrupted. All normal command results are JSON.

## Development and tests

```sh
python -m unittest discover -s tests -v
```

`catalog.json` pins the six existing container/application pairs from their
reviewed manifests. Catalog updates require source/provenance review; never
regenerate it just to make a changed candidate pass. Tests cover corrupt/truncated
archives, target mismatch, forged completeness claims, unsafe archive names,
overwrite prevention, explicit discovery opt-in and the blocked write boundary.
These are software tests; no hardware deployment/recovery was tested.

[Repository guide](../START_HERE.md)
