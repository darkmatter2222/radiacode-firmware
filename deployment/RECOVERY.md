# Updating, backing out and recovering

## Before starting

1. Record the exact model, serial number, hardware revision, current firmware and
   bootloader version from the device/vendor application. Unknown is a blocker
   for experimental installation.
2. Preserve and verify the repository archive following [the CLI guide](README.md).
   It is not a device readback. Preserve supported data exports separately.
3. Confirm with the manufacturer how recovery works on that specific device and
   whether restoration of the requested older firmware is supported. A newer
   firmware may change persistent data formats; an old application image alone
   does not guarantee a valid rollback.
4. Use stable power and a reliable connection. Follow the official application's
   instructions. Do not interrupt an update or run multiple device clients.
5. Do not attempt a custom update using this repository: the writer, full backup,
   recovery route and full reconstructed firmware are not validated.

## If you have only run this CLI

`plan`, `deploy` and `restore` send no device commands. There is no device change
to roll back. Preserve the JSON error/report if troubleshooting. Discovery also
performs no firmware update. A failed local archive operation may leave a partial
file; it is not valid until `verify-backup` succeeds.

## Official update route

For the **100-series**, the manufacturer's device documentation describes the
Windows application over USB, Android over Bluetooth with bootloader 4.0 or
higher (USB OTG for earlier bootloaders), and iOS over Bluetooth. Use its exact
current instructions and compatibility checks. Do not infer RC-410 support from
100-series instructions. Downloads and documentation are linked below.

This is not an arbitrary firmware-version selector. We have not established
that official applications can reinstall your archived version, downgrade, or
recover after every failure. This repository has no verified button sequence for
bootloader entry; do not guess one.

## If an update fails or the device no longer starts

1. Follow the official updater's recovery instructions, keeping power and the
   connection stable while it is updating or recovering. Avoid repeated resets.
2. Record the error, update stage, exact device identity, prior/requested versions,
   connection type and application version. Preserve logs and original archives.
3. Contact manufacturer support for device-specific recovery/service instructions.
   Do not assume a USB port means generic STM32 DFU is available.
4. Do not write the padded `flash.bin` over the entire device, mass erase flash,
   change option bytes/readout protection, or substitute another device's
   calibration. These can destroy material absent from the archive.
5. After manufacturer-guided recovery, check identity, settings, calibration and
   measurement behavior using an appropriate reference procedure. A successful
   boot alone does not demonstrate correct radiation measurements.

## Sources and uncertainty

Reviewed 2026-10-31:

- [Manufacturer firmware update instructions](https://radiacode.com/docs/en/100-series/maintenance/firmware-updates)
- [Manufacturer update knowledge article](https://www.radiacode.com/knowledge/downloading-software-and-updating-firmware-for-radiacode?lang=en)
- [Official downloads](https://www.radiacode.com/downloads)
- [Official support](https://www.radiacode.com/support)

The device instructions warn that interruption can cause failure requiring
service, while the knowledge article describes reconnect/resume without damage.
That inconsistency is not evidence of universal power-loss recovery. Neither
establishes a guarantee for custom firmware or every model/bootloader revision.
