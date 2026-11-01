# NEXT_STEPS.md — precise remaining blockers (2026-11-01 follow-up)

Ordered; each item says exactly what is missing and which action closes it.

1. **Bootloader bytes** — the 64 KiB below `0x08010000` exist only as zero padding. Needed for:
   vector-table ownership, page geometry, and whether the application depends on code/data in
   that region (its `InitialSP 0x20000800` and reset `0x0803BA71` are application-side; the
   boot `{0,4}` pair is the only bootloader fact observed). Close with: the vendor's
   standalone bootloader image, or an SWD read of `0x08000000-0x0800FFFF` + `0x1FFF7590`
   (DEV_ID) + option bytes (needs probe + separate authorization; RDP state unknown).
2. **Physical flash geometry** — capacity, erase-page size, bank layout: no read-only id
   reports them (all 29 served VSFRs and 6 identity ids are listed in REPORT.md §3; none is a
   size field). Same SWD step, or the ST datasheet once the DEV_ID word `0x0029` is mapped to
   one exact part (datasheet step, still one step short of proof).
3. **`0x08070000` availability** — the emulator replacement address appears 0 times in the
   image and no read-only source reports flash end: UNPROVEN. Needs geometry (item 2).
4. **Release gate** — stays exit 2 until: whole-image equivalence (candidate set 7 compiled /
   3,152 cases covers only transcribed routines), hardware-in-the-loop parity (counts/dose vs
   a reference meter), and bootloader coverage. Do not weaken the gate.
5. **Counter semantics** — `0x0013` (not read-only) and the record-stream consumption rules
   were not exercised; a documented vendor trace or a supervised `0x0013` with prior raw
   capture is the only clean way to characterise them.
6. **Update path trace** — no recovery/upgrade trace exists because no update was initiated;
   capture the vendor app's own update session (USB `PHUSBDEV`, endpoints 0x01/0x81) with the
   unit under its normal power, or ask the vendor for the sequence spec.
7. **Rebuilt-image loop** — once items 1-3 land: `python pipeline/build_reconstruction.py`,
   then `python pipeline/run.py --device rc-102/hw1-fw4.14`, then
   `python pipeline/release_gate.py`; bind every new capture to the image/container hash pair
   (`23c31b7d…157f6` / `67a43a50…5e392`) until a rebuilt image has its own hashes.
8. **Clean A/B of the `0x0007` gate (physical step)** — power-cycle the unit (unplug/replug
   USB), then one connection: pre-reads -> one `0x0007` -> post-reads, all in the same
   connection. The stored final run cannot serve as the A/B because run 1 had already set
   the RAM flag in the same power cycle (see REPORT.md §2). One write per connection, as
   authorized.
9. **Board identification photos** — for the exact MCU part and board revision: close-ups as
   requested in the repo docs (top side full PCB; MCU package marking; any suspected SWD pads
   1-7 with an unambiguous pad-1 dot). Photos only; no probe contact.

Not blockers (settled here): the `0x0007` gate (RAM-only flag, one write, NAK->answer
transition observed); configuration/calibration/identity reproducibility (SHA-identical
repeats and equal to the prior capture); the NAK record decode; container-vs-device field
triple; VSFR read format.
