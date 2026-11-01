# Hardware and recovery findings (RC-102, hardware 1, firmware 4.14)

Evidence layers are kept separate: **A** = read-only device replies (`analysis/capture.json`,
`analysis/vsfr_readout.json`), **B** = bytes inside `flash.bin`, **C** = manufacturer or ST
primary documents, **D** = inference. Every claim below is tagged. A `n/a` means the layer
cannot answer it.

## 1. Identity words returned by the device

`GET_SERIAL` reply (`analysis/capture.json`, layer A), 16 raw bytes:

```
0c 00 00 00 | 29 00 2d 00 | 01 50 32 32 | 42 39 31 20
```

* first word `0x0000000c` = item count (12 payload bytes), layer A.
* next word `0x002d0029` = two 16-bit fields (`0x0029`, `0x002d`), layer A.
* remaining bytes = `01 50 32 32 42 39 31 20`, i.e. a one-byte tag then the ASCII run
  `P22B91 ` (the printable part of the vendor serial string `RC-102-008228` region), layer A.

**These are not the MCU `DEV_ID`.** ST publishes the identity value in the `DBGMCU_IDCODE`
register at `0xE0042000` (bits 11:0), and the L4-family values are `0x4xx`-sized: `0x415`
(STM32L475/476/485/486), `0x435` (L43x/44x), `0x461` (L49x/4Ax), `0x462` (L45x/46x), `0x470`
(L4R/L4S), `0x471` (L4P/L4Q) — see the ST reference manuals RM0351/RM0394/RM0432 and the
mirrored device table in OpenOCD `src/flash/nor/stm32l4x.h` (layer C). `0x0029` is therefore
a vendor field, not a chip code, and must not be reported as a part number.

## 2. Family-level identification (established)

| observation | value | layer |
| --- | --- | --- |
| core / ISA | Thumb-2, ARMv7E-M, single-precision FP present (VFP instructions in the listing) | B |
| application base | `0x08010000`, 98 vector entries, `InitialSP 0x20000800`, `Reset 0x0803BA71` | B |
| image extent | `0x08000000`-`0x0803CA00` (248,320 B), 65,536 B of it zero padding | B |
| system-memory registers referenced | `0x1FFF7590` (96-bit unique device ID), `0x1FFF75A8`, `0x1FFF75AA` (USB calibration), `0x1FFF75E0` (flash size) | B |
| peripheral windows referenced | `0x40000000`/`0x40000400`/`0x40000800`, `0x40010000`/`0x40010200`/`0x40010400`, `0x40020000`/`0x40020400` (watchdog, timers, DMA block layout of the L4 line) | B |
| radio | Nordic UART Service UUID with the MCU-hosted stack; no second processor is referenced by any recovered base address | A + B |

The referenced `0x1FFF75Ax/0x1FFF75E0` register set and the peripheral-window spacing match
the STM32L4 line; within that line the 98-entry vector table with the LCD/DMA2D/JPEG-era
peripheral set is consistent with the L4 7x/8x-class group (L475/L476/L485/L486). This is a
**group** identification, not an orderable part number.

## 3. Established vs unresolved

| item | state |
| --- | --- |
| exact MCU part number (orderable code) | **unresolved** — needs `DBGMCU_IDCODE` (`0xE0042000`) and `0x1FFF75E0`, which no read-only protocol command exposes |
| board revision | **unresolved** — needs the PCB silkscreen / marking photos |
| physical flash and RAM capacity | **unresolved** — `0x1FFF75E0` (FLASH size) is not reachable read-only; the image end (`0x0803CA00`) bounds only the shipped content |
| erase page / bank geometry | datasheet-level for the group (2,048-byte pages, dual-bank option bytes); **not confirmed** on this unit |
| bootloader/application boundary | application at `0x08010000` (B); bootloader content is not in the container and its address is **not established** |
| per-device calibration and settings | `[DeviceParams]`+`[DataStructure]` blob (3,256 B) is byte-identical to VS `0x002`; the two small `0x081C` areas are served XOR-obfuscated; all preserved in `docs/evidence/2026-11-01-writefree/` |
| external nonvolatile memory / co-processor | **no evidence** for either in the recovered address map; not disproved |
| bootloader entry with a dead application | **hypothetical**: the vendor documents only the normal update path; no button sequence is verified (see `deployment/RECOVERY.md`) |
| whether recovery keeps calibration | **unverified** — the vendor archive holds the config text, but no restore cycle has been executed on hardware |

## 4. Photograph request (to close items in §3)

All photos with the enclosure open, unit unpowered, no probe contact:

1. **Top side, whole PCB**, in focus, so the LCD connector, the MCA connector and the crystal
   are all visible in one frame (board layout / revision silkscreen).
2. **MCU package marking**, macro, oblique light so all lines of the laser text are legible
   (orderable code line + the date/lot code line beneath it), including the package pin count.
3. **Suspected debug pads** close-up: the 4-7 pad row near the MCU (SWDIO/SWCLK/GND/3V3),
   with the pad-1 marker visible, plus any unpopulated footprint adjacent to it.
4. **Bottom side**, whole board, for the second-side silkscreen and any external EEPROM or
   MEMS microphone markings.
5. One **scale shot** with a ruler beside the MCU for the pin-pitch count.

Nothing else is needed from the enclosure; with items 1-3 the exact part number and board
revision become decidable.
