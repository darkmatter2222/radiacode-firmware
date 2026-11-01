# Requirements before a real firmware writer can be enabled

The current implementation has no device-write primitive. A future writer must
be a reviewed code change, not a boolean in a manifest, a `--force` switch or an
assumption that passing unit tests proves recovery. Its implementation must also
satisfy the repository release gate, which currently remains closed.

## Required evidence

- Exact model/hardware/bootloader identity from a validated live handshake;
  re-check the same physical device after any reconnect. A BLE name, USB address
  or user-entered serial is not sufficient.
- A documented and tested protocol for the selected transport, including framing,
  authentication if present, sequence/ack rules, timeouts and bootloader transitions.
  Never automatically retry an ambiguous erase/write/commit operation.
- A verified memory map with protected bootloader, calibration, settings, option
  bytes and immutable regions. Enforce range/overflow/alignment checks on every
  block and reject overlap or out-of-region writes.
- A complete backup policy covering all data needed for recovery, with exact
  device identity and independent readback/hash verification. Explicitly identify
  unreadable or protected regions and demonstrate an equivalent recovery route.
- A proven recovery mechanism independent of the application being replaced.
  Determine whether redundant images, atomic activation or a protected recovery
  bootloader actually exist; do not claim the host CLI can add these guarantees.
- Proven rollback compatibility for persistent data, or a tested migration and
  restore procedure. Confirm signing, encryption and downgrade restrictions.
- Candidate image provenance, compiler/build identity, full behavioral evidence,
  application layout and validated entry/vector information. Hash matching alone
  is not proof of compatibility or authenticity.
- Live battery/power prerequisites and a transport-specific failure policy based
  on measured device behavior. No invented battery threshold counts as evidence.

## Future transaction design

1. Acquire exclusive per-device ownership; read identity and power state.
2. Snapshot and verify required backup regions and recovery materials.
3. Bind the exact candidate bytes, backup hashes and live identity to a plan.
4. Present the concrete version transition and device serial for confirmation.
5. Revalidate bytes/identity immediately before opening the write transaction.
6. Persist an append-only transaction journal before destructive steps; flush it.
7. Apply only authorized application ranges using validated acknowledgments.
8. Independently read back and verify installed content before activation where
   supported. Unknown completion is an error, never an assumed success.
9. Activate using a proven device-side commit mechanism; reconnect and verify
   identity, version, persistence, calibration and measurement behavior.
10. On failure, follow the device's proven recovery policy. Never blindly flash
    another image or automatically switch transports/devices.

These steps describe required future work, not implemented features.

## Required tests beyond current unit tests

Use a sacrificial device with a confirmed independent recovery method. Inject
power loss/disconnects at every erase/write/commit boundary; test corrupted and
out-of-order responses, stale identity, concurrent clients, storage exhaustion,
process termination, host restart, wrong hardware, failed readback and rollback
across persistent-data changes. Repeat per supported hardware/bootloader and
transport. Retain original/rebuilt traces and recovery results tied to exact
hashes. Mock tests cannot replace these experiments.

Until this evidence exists, full readback, USB/Bluetooth sessions, writes,
automated restore and release approval remain unavailable.
