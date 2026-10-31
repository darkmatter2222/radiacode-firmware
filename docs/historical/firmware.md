> Historical pre-audit narrative. Contains known unsupported or incorrect claims.
> Use the current README, firmware reference, and generated evidence instead.

# RadiaCode-102 firmware — full description

Extracted from a live unit (`RC-102-008228`) over BLE, then decoded, disassembled and decompiled.
Every value below comes from the artifacts of the build `rc-102/hw1-fw4.14`, i.e. the directory
`firmware/rc-102/hw1-fw4.14/` - **all artifact paths in this file are relative to that directory**
(`flash.bin`, `listing.s`, `decompiled.c`, `index.json`, `analysis/*.json`); other registered builds
are listed in `README.md` §3.1 and have the same layout. Items marked *(inferred)* are derived from
code structure rather than a name in the binary.

## 1. Identity

| item | value | evidence |
| --- | --- | --- |
| device | RadiaCode-102 (scintillation dosimeter / radiometer) | string `RadiaCode-102` @ `0x08019F1C` |
| hardware id | `2BDDP-102` | @ `0x080149F8` |
| firmware version | 4.14 (`version_high 4`, `version_low 14`) | container header; format `v%02d.%02d` @ `0x08014A04` |
| firmware build | `Jul  7 2025 11:19:22` = `date_time 0x5AE7428A` | @ `0x08028F14`, cmd `0x000A` |
| bootloader build | `Feb  6 2023 15:49:14` | cmd `0x000A` |
| container | `Phyton\0\0`, 130148 B, whole-file CRC `0x13095ABB`, 8 blocks | `blocks.json` |
| flat image | 248320 B, `0x08000000`-`0x0803CA00` | `flash.bin` |
| MCU | STM32L47x/L48x-class, Cortex-M4F, ARMv7E-M, Thumb-2 | vector names + IRQ numbering (LPUART2=65, LPTIM3/4/5=66/67/68, JPEG/DMA2D/LCD exist) |
| BLE name | `RC-102-%06.6X` | @ `0x08019F0C` |
| GATT | Nordic UART service `e63215e5-7003-49d8-96b0-b024798fb901`, write `...e6`, notify `...e7` | live probing (`rcsession.py`) |

Image-vs-unit identity is proven by four independent matches (size, `date_time`, CRC, and the 3256-byte
config string read back byte-identically from the device): `analysis/verification.json`.

## 2. Memory model

| region | range | content |
| --- | --- | --- |
| boot (absent from container) | `0x08000000`-`0x0800FFFF` | 64 KiB of zeros in the image; vendor bootloader |
| application | `0x08010000`-`0x0803CA00` | 232 KiB: vector table, code, literal pools, embedded config text |
| SRAM | `0x20000000`-`0x2000FFFF` | 64 KiB; `InitialSP = 0x20000800` (small stack at the bottom), pool/heap control literals at the top (`0x2000f3bc`...`0x2000ffbc`) |

Data blobs living inside the code image:

| address | size | content |
| --- | --- | --- |
| `0x0802F9F0` | 3256 B | `[DeviceParams]` + `[DataStructure]` text (§9, §10) |
| `0x080306AC` | 4587 B | `[VSFR_*]` register map, 67 records (§8) |
| `0x08035EBE` +0x49 x7 | 72 B each | seven monotonic byte ramps (0x20-0x7E, step 1-3) — quantised log / gamma-style curves *(inferred)* |
| `0x08036C10` | 44 pairs | `{u32 id, u32 handler}` table; ids `0x0`-`0x6`, `0x400`-`0x40A`, `0x800`-`0x80A`, `0xC01`-`0xC18` |
| `0x08038D9C` | 36 B | base-36 digit alphabet `0123456789abcdefghijklmnopqrstuvwxyz` |
| `0x08022F4C`, `0x08038454`, `0x08038494`, `0x08038CD4`, `0x0803943C`, `0x0803A3FC`, `0x08020A18` | 4-10 pairs | further `{id, handler}` runs (`analysis/tables.json`) |

## 3. Decoded block layout

All 8 blocks decrypt and CRC-verify; stored size = LZSS + 8-byte alignment, `plain` = size in flash.

| # | address | stored | decompressed | crc | instructions |
| --- | --- | --- | --- | --- | --- |
| 0 | `0x08010000` | 17838 | 28672 | `7f0ef5e3` | 10686 |
| 1 | `0x08017000` | 16726 | 20224 | `d87719e6` | 7599 |
| 2 | `0x0801bf00` | 12536 | 16384 | `affad014` | 6193 |
| 3 | `0x0801ff00` | 26080 | 31232 | `91a0e8c8` | 11986 |
| 4 | `0x08027900` | 22141 | 25600 | `a87ba0d5` | 9714 |
| 5 | `0x0802dd00` | 10496 | 20224 | `3a567504` | 5872 |
| 6 | `0x08032c00` | 11128 | 22272 | `c758d839` | 8555 |
| 7 | `0x08038300` | 8945 | 18176 | `f790ccd9` | 6673 |

## 4. Container format (how the firmware is packed)

```
header   : "Phyton\0\0" | u32 header_size(52) | u32 date_time | u32 buffer_size | u8[16] serial
           | u8 version_low | u8 version_high | u32 file_count | u32 fw_header_size
           | u8 compressed | u8 reserved | u32 crc32
blocks[] : u32 header_size | u32 size ^ 0xCE27A932 | u32 addr ^ 0xB2D5A864
           | u8 key_block[512] | u8 data[align8(size)]
```

* `key_block`: unmangle with hardcoded key-table slot 0; index at `[0:2]`, 16-byte data key at `[2:18]`,
  equal CRC pair at `[18:26]`; that region is unmangled a second time with the table selected by `index`
  (`0-7` hardcoded, `8-15` zero table, `0xFFFF` device-id key).
* Mangle cipher: 48-round Feistel over 8-byte little-endian blocks, four round keys (`key[rnd & 3]`),
  round function `B' = rnd + key + ((B>>8)^(B<<6)) + B + A`.
* CRC: MPEG-2 polynomial `0x04C11DB7`, no reflection, init `0xFFFFFFFF`, fed as 4-byte LE chunks.
* Payload: LZSS — 2048-byte window pre-filled with `0x20`, initial index `2031` (`2048-0x10-1`), flag
  bit 1 = literal, 0 = match (11-bit offset + 4-bit length, `+2`, so match length `2..17`), MSB-first.
* The small flash areas returned by cmd `0x081C` use a *different* stream cipher: Borland LCG keystream
  (`seed * 0x015A4E35 + 1`, XOR of the low 8 bits of `seed >> 16`, one continuous state across the size
  word and the payload).

All four primitives are implemented and test-vector-verified in `pipeline/rcfmt.py`, and self-tested by `pipeline/step1_validate.py`.

## 5. Execution model

**Reset** — `handler_1_reset` @ `0x0803BA70` (3 instructions + literal pool):

1. `if (isCurrentModePrivileged()) setMainStackPointer(0x20000800)` — SP from the vector table.
2. `bl` to `0x08038A59` (`FUN_08038a58`) — clock bring-up: enable the internal RC oscillator
   (`CR |= 0xF00000`), program the PLL block (multiplier `0x1000`, prescaler word cleared), then write the
   clock-selector word. Three register blocks, in that order.
3. `bl` to `0x0803C459` (`FUN_0803c458`) — enter the event loop.

**Event loop** (`FUN_0803c458`): `FUN_0803a978()`, then spin on `FUN_0803aee0()` until it returns a
message block; decode the 8-byte block header (size in bits 3+, type in bits 0-1) and tail-jump to the
pool processor at `0x08023F92`. That processor is a size-class, first-fit allocator with coalescing and
an integrity checker (`FUN_0802d368` on corruption) — a `malloc`/`free` pair over a pool whose control
block sits near `0x2000fxxx`. ISRs only post message blocks; all real work happens in the main loop.

**Driver framework.** The dispatcher `sub_0801F474` (right after the string `Start Main loop` @
`0x0801F464`) walks a table of descriptors: `n = [dev + 0x14]`, entry `i` at `table[i * 4]`, class
selected by `flags & 0x7000` (`0x1000` = "call slot `+0x18` of the descriptor's vtable"), then per-id
post-processing (sub-ids 2 and 6 observed). A static-vtable peripheral model *(inferred)*.

**Library.** Compact stdio with bounds-checked variants: `printf_s` / `wprintf_s`
(`bad %s argument`, `bad %ls argument`, `%n disallowed` @ `0x08021CF4`-`0x0802EE44`) and a
`constraint handler: bad message` assert path @ `0x0802C4AF`. Time/duration formats:
`%02d:%02d:%02d` @ `0x0803BFE0`, `%dd %02d:%02d` @ `0x0803BFF0`; integer-to-text uses the base-36
alphabet at `0x08038D9C`.

## 6. Interrupt usage

98 vector entries. Nine exception stubs at `0x080363FD`-`0x0803640D` (2-byte `b` each). Only these IRQs
have their own code; every other entry points at `0x0803C4D9`, a 4-byte self-loop (`b.w` to itself —
idle/trap), which also appears 66 times as a literal.

| IRQ | handler | IRQ | handler | IRQ | handler |
| --- | --- | --- | --- | --- | --- |
| 7 EXTI1 | `0x0803640F` | 11 DMA1_CH0 | `0x08036455` | 40 DMA2_CH0 | `0x080364F9` |
| 8 EXTI2 | `0x08036423` | 12 DMA1_CH1 | `0x08036475` | 50 AES | `0x0803651B` |
| 9 EXTI3 | `0x0803654B` | 18 ADC1_2 | `0x080364A1` | 54 TIM12 | `0x0803651F` |
| 10 EXTI4 | `0x08036437` | 23 USART1 | `0x080364BF` | 65 LPUART2 | `0x08036523` |
| — | — | 66 LPTIM3 | `0x0803653B` | 67 LPTIM4 | `0x0803655B` |

Each real ISR is a 3-6 instruction trampoline: read a peripheral status word, OR a bit into a shadow
status (`0x20`, `0x40`, `0x80`, ...), post an event (e.g. `FUN_08036474` -> `FUN_080191f0`). The
IRQ-numbered trampolines at `0x0803C4B6`+ load the id (`movs r1, #n`) and tail-jump into the shared entry
at `0x0803C4B2`. Used peripherals implied by this list: USART1 + DMA (BLE link), ADC1/2 (battery / analog),
LPTIM3/4 + TIM12 (timebase / wake), EXTI (buttons, radio INT), AES (hardware crypto).

## 7. BLE transport and packet framing

* Host writes in 18-byte chunks; every frame = `u32 LE total_length` + payload.
* Payload starts with a 4-byte header `cmd:u16 LE | 0x00 | seq`; the host uses `seq = 0x80 + (counter % 32)`
  and matches replies by comparing the echoed header.
* Validation is `sub_08027D06`, whose failure strings are:
  `Error: S%d Packet size corrupted! PacketSize = 0x%08X` (`0x08037267`),
  `Error: S%d Command corrupted! Cmd = 0x%08X` (`0x080372A0`),
  `Error: S%d Valid sign corrupted! Sgn = 0x%08X` (`0x080372CC`),
  `Error: S%d Packet or String size corrupted! PacketSize = ..., StringSize = ...` (`0x080372FC`),
  `Error: S%d Data frame corrupted!` (`0x08037354`) — `S%d` is the slot/sequence index.
  Overruns report `%d message(s) lost!` @ `0x0803BD3C`.
* Link lifecycle strings: `BLE: client connected` (`0x08038124`), `BLE: connection timeout expired`
  (`0x0803813C`), `BLE: HW error/SPI|Radio|Timer overrun|Unknown` (`0x0803815C`-`0x080381A0`),
  `BLE: disconnected by remote user` / `by reason 0x%0.2X` (`0x08038E5C`, `0x08038E80`),
  `BLE: Connection parameter update error #0x%0.2X! Interval is %d.` (`0x08039008`),
  `BLE: error packet received => ...` (`0x080392DC`), and the state machine's
  `BLE: Hardware initialization` / `BLE: Start` / `BLE: Stop` / `BLE: Init sequence error!` /
  `BLE: Start sequence error!` (`0x08022EE0`-`0x08022F34`). The radio is SPI-attached (`HW error/SPI`).
* Inside the firmware, per-item access is one big address switch, `sub_080275C4`, built as a `subs`/`beq`
  chain over the 16-bit VSFR address: `0x500`, `0x502`, `0x503`, `0x504`, `0x505`-`0x50D`, `0x510`-`0x516`,
  `0x520`-`0x522`, `0x530`, `0x531`, `0x5E0`, `0x603`, `0x700`, then `+0x7900` for the `0x8000`-`0x8035`
  measurement block, the `0xC000`-`0xC200` calibration block, and `0xFFFF0000`+ for the system block —
  exactly the four address ranges declared in the config text. Callers pass an item count and an
  8-byte-per-item result buffer.

## 8. Register interface (VSFR map, 67 records @ `0x080306AC`)

All records are `Virtual=1` (software-decoded, not memory-mapped). Fields per record: `Addr`, `Size`
(bytes), `Type=float` (IEEE-754), `Signed=1`, `DisplayFormat=1` (LCD-formatted), `Min`/`Max` (enum bounds).

| # | VSFR | Addr | Size | flags |
| --- | --- | --- | --- | --- |
| 1 | `VSFR_DEVICE_CTRL` | `0x00000500` | 1 | — |
| 2 | `VSFR_DEVICE_LANG` | `0x00000502` | 1 | fmt |
| 3 | `VSFR_DEVICE_ON` | `0x00000503` | 1 | fmt, 0..1 |
| 4 | `VSFR_DEVICE_TIME` | `0x00000504` | 4 | fmt |
| 5 | `VSFR_BLE_TX_PWR` | `0x00000700` | 1 | fmt |
| 6 | `VSFR_DISP_CTRL` | `0x00000510` | 1 | — |
| 7 | `VSFR_DISP_BRT` | `0x00000511` | 1 | fmt |
| 8 | `VSFR_DISP_CONTR` | `0x00000512` | 1 | fmt |
| 9 | `VSFR_DISP_OFF_TIME` | `0x00000513` | 4 | fmt |
| 10 | `VSFR_DISP_ON` | `0x00000514` | 1 | fmt, 0..1 |
| 11 | `VSFR_DISP_DIR` | `0x00000515` | 1 | fmt |
| 12 | `VSFR_DISP_BACKLT_ON` | `0x00000516` | 1 | fmt, 0..1 |
| 13 | `VSFR_SOUND_CTRL` | `0x00000520` | 2 | — |
| 14 | `VSFR_SOUND_VOL` | `0x00000521` | 1 | fmt |
| 15 | `VSFR_SOUND_ON` | `0x00000522` | 1 | fmt, 0..1 |
| 16 | `VSFR_VIBRO_CTRL` | `0x00000530` | 1 | — |
| 17 | `VSFR_VIBRO_ON` | `0x00000531` | 1 | fmt, 0..1 |
| 18 | `VSFR_ALARM_MODE` | `0x000005E0` | 1 | fmt |
| 19 | `VSFR_MS_RUN` | `0x00000603` | 1 | fmt, 0..1 |
| 20 | `VSFR_PLAY_SIGNAL` | `0x000005E1` | 1 | fmt |
| 21 | `VSFR_CHARGER_STATE` | `0x0000C200` | 1 | fmt, signed |
| 22 | `RC_VSFR_DR_LEV1_uR_h` | `0x00008000` | 4 | fmt |
| 23 | `RC_VSFR_DR_LEV2_uR_h` | `0x00008001` | 4 | fmt |
| 24 | `RC_VSFR_DS_LEV1_100uR` | `0x00008002` | 4 | fmt |
| 25 | `RC_VSFR_DS_LEV2_100uR` | `0x00008003` | 4 | fmt |
| 26 | `RC_VSFR_DS_LEV1_uR` | `0x00008014` | 4 | fmt |
| 27 | `RC_VSFR_DS_LEV2_uR` | `0x00008015` | 4 | fmt |
| 28 | `RC_VSFR_DS_UNITS` | `0x00008004` | 1 | fmt, 0..1 |
| 29 | `RC_VSFR_USE_nSv_h` | `0x0000800C` | 1 | fmt, 0..1 |
| 30 | `RC_VSFR_CR_UNITS` | `0x00008013` | 1 | fmt, 0..1 |
| 31 | `RC_VSFR_CPS_FILTER` | `0x00008005` | 1 | fmt |
| 32 | `RC_VSFR_CR_LEV1_cp10s` | `0x00008008` | 4 | fmt |
| 33 | `RC_VSFR_CR_LEV2_cp10s` | `0x00008009` | 4 | fmt |
| 34 | `RC_VSFR_TEMP_UNITS` | `0x00008016` | 1 | fmt, 0..1 |
| 35 | `RC_VSFR_DOSE_RESET` | `0x00008007` | 1 | fmt, 0..1 |
| 36 | `RC_VSFR_CHN_TO_keV_A0` | `0x00008010` | 4 | float |
| 37 | `RC_VSFR_CHN_TO_keV_A1` | `0x00008011` | 4 | float |
| 38 | `RC_VSFR_CHN_TO_keV_A2` | `0x00008012` | 4 | float |
| 39 | `RC_VSFR_CPS` | `0x00008020` | 4 | fmt |
| 40 | `RC_VSFR_DR_uR_h` | `0x00008021` | 4 | fmt |
| 41 | `RC_VSFR_DS_uR` | `0x00008022` | 4 | fmt |
| 42 | `RC_VSFR_TEMP_degC` | `0x00008024` | 4 | float |
| 43 | `RC_VSFR_RAW_TEMP_degC` | `0x00008033` | 4 | float |
| 44 | `RC_VSFR_TEMP_UP_degC` | `0x00008034` | 4 | float |
| 45 | `RC_VSFR_TEMP_DN_degC` | `0x00008035` | 4 | float |
| 46 | `RC_VSFR_ACC_X` | `0x00008025` | 2 | fmt, signed |
| 47 | `RC_VSFR_ACC_Y` | `0x00008026` | 2 | fmt, signed |
| 48 | `RC_VSFR_ACC_Z` | `0x00008027` | 2 | fmt, signed |
| 49 | `RC_VSFR_OPT` | `0x00008028` | 2 | fmt |
| 50 | `RC_VSFR_VBIAS_mV` | `0x0000C000` | 2 | fmt |
| 51 | `RC_VSFR_COMP_LEV` | `0x0000C001` | 2 | fmt, signed |
| 52 | `RC_VSFR_CALIB_MODE` | `0x0000C002` | 1 | fmt, 0..1 |
| 53 | `VSFR_SYS_MCU_ID0` | `0xFFFF0000` | 4 | — |
| 54 | `VSFR_SYS_MCU_ID1` | `0xFFFF0001` | 4 | — |
| 55 | `VSFR_SYS_MCU_ID2` | `0xFFFF0002` | 4 | — |
| 56 | `VSFR_SYS_DEVICE_ID` | `0xFFFF0005` | 4 | — |
| 57 | `VSFR_SYS_SIGNATURE` | `0xFFFF0006` | 4 | — |
| 58 | `VSFR_SYS_RX_SIZE` | `0xFFFF0007` | 2 | fmt |
| 59 | `VSFR_SYS_TX_SIZE` | `0xFFFF0008` | 2 | fmt |
| 60 | `VSFR_SYS_BOOT_VERSION` | `0xFFFF0009` | 4 | — |
| 61 | `VSFR_SYS_TARGET_VERSION` | `0xFFFF000A` | 4 | — |
| 62 | `VSFR_SYS_STATUS` | `0xFFFF000B` | 4 | — |
| 63 | `VSFR_SYS_MCU_VREF` | `0xFFFF000C` | 4 | fmt, signed |
| 64 | `VSFR_SYS_MCU_TEMP` | `0xFFFF000D` | 4 | fmt, signed |
| 65 | `RC_VSFR_DPOT_RDAC` | `0x0000C004` | 1 | fmt |
| 66 | `RC_VSFR_DPOT_RDAC_EEPROM` | `0x0000C005` | 1 | fmt |
| 67 | `RC_VSFR_DPOT_TOLER` | `0x0000C006` | 1 | fmt |

Address-space meaning *(inferred from the names and the switch)*: `0x500`-block = device/display/sound/
vibration UI settings, `0x700` = radio TX power, `0x8000`-block = measurement + alarm values,
`0xC000`-block = analog front-end and calibration (bias, comparator, digital-potentiometer codes),
`0xFFFF0000`-block = system/debug mirror (MCU ID/signature, MTU sizes, versions, VREF, die temp).

## 9. What is configurable — `[DeviceParams]` (20 keys, @ `0x0802F9F0`)

INI-style text, byte-identical to the device's `VS CONFIGURATION` answer. Values use `1e-1`-style
notation, and enum values are `label|unicode-label` pairs.

| key | value | meaning |
| --- | --- | --- |
| `CR_AlarmsNum` | 2 | number of count-rate alarm levels |
| `CR_AlarmMin_cps` / `CR_AlarmMax_cps` | `1e-1` / `50e3` | count-rate alarm range, cps |
| `DR_AlarmsNum` | 2 | dose-rate alarm levels |
| `DR_AlarmMin_R_h` / `DR_AlarmMax_R_h` | `1e-6` / `1e-1` | dose-rate alarm range, R/h |
| `DS_AlarmsNum` | 2 | dose alarm levels |
| `DS_AlarmMin_R` / `DS_AlarmMax_R` | `1e-6` / `1e3` | dose alarm range, R |
| `MinFrmPeriod_ms` | 500 | minimum frame period (max 2 Hz refresh) |
| `VSFR_DISP_OFF_TIME` | `5 s;10 s;15 s;30 s;2 min;5 min` | enum table for VSFR `0x513` |
| `DispBacklight` | `0-9` | brightness scale |
| `Language` | English | UI language |
| `DBLag_ms` | 180000 | database lag window, 180 s |
| `FrameTimeStep_us` | 10000 | 100 Hz sampling grid |
| `EnergyCompensation` | 1 | energy-compensation curve enabled |
| `SpecFormatVersion` | 1 | spectrum wire format |
| `SP2DR_Table` | `CsI_10x10x10` | spectrum->dose-rate table for the 10x10x10 mm CsI(Tl) crystal |
| `TextASCII_MaxSize` | 0 | ASCII text block disabled |
| `BattChargeMonitor` | 0 | charge monitoring disabled |

The 19 value-bearing keys above are the tunables; the remaining keys of the blob belong to
`[DataStructure]` (§10). Writable VSFRs are those with `Min`/`Max` or `DisplayFormat`.

## 10. Data model — `[DataStructure]`: 6 groups, 14 channels

Groups (name / `Id` / flag mask): `GRP_RealTimeData` 0 `FlgMsk=0x000063DB`, `GRP_RawData` 1,
`GRP_DoseRateDB` 2 `0x00009000`, `GRP_RareData` 3 `0x00009000`, `GRP_DoseCounter` 4 `0x00009000`,
`GRP_Event` 7 `0x00009000`. Each group lists the channels it contains; a host reads a group in one batch
(VSFR batch commands), so `FlgMsk` selects which channels are present in the frame *(inferred)*.

| channel | `Id` | sensor | unit | `DType` | `RType` | range / scaling |
| --- | --- | --- | --- | --- | --- | --- |
| `CHN_Flags` | 0 | — | — | 4 | 8 | bitmask |
| `CHN_Count` | 2 | `c10_CsI_C30035` | — | 8 | 8 | raw counts |
| `CHN_CountRate` | 3 | `c10_CsI_C30035` | `" cps\| имп/с"` | 1 | 1 | `MaxVal=50e3` |
| `CHN_DoseRate` | 4 | `c10_CsI_C30035` | `" R/h\| Р/ч"` | 1 | 1 | `ScaledUnit=1`, `MaxVal=1e-1` |
| `CHN_DoseRateErr` | 5 | `c10_CsI_C30035` | `%` | 4 | 1 | `0`-`50`, `Expr=1 P1=0.1` |
| `CHN_Duration` | 6 | — | `" s\| с"` | 8 | 8 | |
| `CHN_Dose` | 7 | `c10_CsI_C30035` | `" R\| Р"` | 1 | 1 | `ScaledUnit=1`, `1e-6`-`1e3` |
| `CHN_Temperature` | 8 | `AS6212-AWLT` | `°C` | 5 | 1 | `-20`-`40`, `Expr=1 P1=0.01 P2=-20` |
| `CHN_ChargeLevel` | 9 | `MCU_ADC` | `%` | 4 | 1 | `0`-`100`, `Expr=1 P1=0.01` |
| `CHN_Event` | 14 | — | — | 2 | 2 | |
| `CHN_EventChnMsk` | 15 | — | — | 2 | 8 | `Expr=1 P1=8 P2=7` |
| `CHN_CountRateErr` | 16 | `c10_CsI_C30035` | `%` | 4 | 1 | `0`-`50`, `Expr=1 P1=0.1` |
| `CHN_RealTimeFlags` | 17 | — | — | 2 | 8 | |
| `CHN_DoseCounter` | 22 | `c10_CsI_C30035` | `" uR\| мкР"` | 8 | 8 | `ScaledUnit=1` |

Field semantics *(inferred — consistent across all 14 channels)*:

* `DType` = stored representation: 1 = scaled integer, 2 = small int, 4 = integer percent,
  5 = 32-bit float, 8 = raw / passthrough.
* `RType` = report encoding: 1 = value, 2 = id, 8 = bitmask / packed.
* `ScaledUnit=1` = apply the decimal prefix given in `Unit`.
* `Expr=1` selects the linear transform `value = raw * P1 (+ P2)`: temperature `raw*0.01 - 20`,
  charge `raw*0.01`, error `raw*0.1`. Only `Expr` value `1` occurs in this image.

Named hardware in the config: **`c10_CsI_C30035`** (CsI(Tl) scintillator, 10x10x10 mm, with the MCA chain
behind `RC_VSFR_VBIAS_mV` / `COMP_LEV` / `DPOT_RDAC*`), **`AS6212-AWLT`** (temperature),
**`MCU_ADC`** (battery), plus a 3-axis accelerometer (`ACC_X/Y/Z`) and an optical channel (`OPT`).
The 3-coefficient float calibration `CHN_TO_keV_A0/A1/A2` maps MCA channel -> keV (polynomial in the
channel number), and `CPS_FILTER` toggles count-rate filtering.

## 11. Command set (observed on the live unit)

A complete sweep of `0x0000`-`0x0FFF`, repeated with and without a `u32` argument, produced answers only
from these ids. Payloads are the bytes after the 4-byte header.

| cmd | role | request | response (hex) | decoded |
| --- | --- | --- | --- | --- |
| `0x0005` | status | — | `02000000` | `u32 2` |
| `0x0007` | exchange / negotiation | `01 ff 12 ff` | ack | sets the framing tuple |
| `0x000A` | versions | — | `0000040014` + `Feb  6 2023 15:49:14` + `0e0004 0015` + `Jul  7 2025 11:19:22` + `00` | array of `{u16 id, u16 major, u8 len, chars}`; id `0` = bootloader (4.x), id `0x0E` = firmware (4.x) |
| `0x000B` | serial | — | `0c000000` `29002d0001` `503232423931 20` | `u32 len=12`, then the container's 16-byte serial field; printable part `P22B91 `; human-readable id `RC-102-008228` (`RC-102-%06.6X`) |
| `0x0012` | image info | — | `64fc0100 00100000 8a42e75a bb5a0913` | size `130148`, buffer `4096`, `date_time 0x5AE7428A`, crc `0x13095ABB` |
| `0x0013` | block/frame count | — | `13000000` | `u32 19` |
| `0x0101` | image descriptor | — | `8a42e75a` `0a` + `rc-102.bin` + `10` + `RadiaCode RC-102` + `01` `30` | `date_time`, 8-bit-length-prefixed file name, product name, `01`, `0x30` |
| `0x0807` | flash area info | `u32 area` | small record | paired with `0x081C` |
| `0x081C` | read flash area | `u32 area` (0, 1) | `{u32 status, u32 seed, u32 enc_size, enc_data}` | Borland-LCG XOR (§4); yields the `PublicAPI` struct + device parameters |
| `0x0824`-`0x082B` | virtual-SFR / string batch | index, optional `u32` | text / values | serves `VS CONFIGURATION`, the VSFR map (§8) |
| `0x0A04` | set time | `8 x u8`: `day, month, year-2000, 0, sec, min, hour, 0` | ack | the only write-style id found |

There is **no** raw memory/image read command, so bulk bytes come from the vendor `.bin`; the device only
confirms the `size / date_time / crc32` triple and the two XOR-obfuscated config areas.

## 12. Subsystems and what they do

| area | address | role |
| --- | --- | --- |
| vectors | `0x08010000` | 98 entries, `InitialSP 0x20000800`, `Reset 0x0803BA71` |
| queues / low level | `0x08010190`+ | ring-buffer primitives (head/tail polling on `DAT_08010c08`), number + base-36 output |
| main loop | `0x0801F464`, `0x0801F474` | `Start Main loop`, driver-table dispatcher |
| stdio | `0x08021CF4`-`0x0802EE44` | `printf_s` / `wprintf_s`, `%n` restrictions; assert path at `0x0802C4AF` |
| CRC report | `0x08027294` | `CRC Error: 0x%08X != 0x%08X` — container/area validation |
| item accessor | `0x080275C4` | VSFR address switch (§7 end) |
| frame validator | `0x08027D06` | packet/field validation, loop over items with an 8-byte result stride |
| config serialiser | `0x08028E40` | emits `[DeviceParams]` / `[DataStructure]` / `[VSFR_*]` text |
| pool allocator | `0x08023F92` | first-fit `free` path with integrity check |
| BLE link handlers | `0x08022E98`, `0x08024638`, `0x08027086` | connection-parameter updates, lost-message report, error-packet report |
| BLE state machine | `0x08034E78`, `0x08034F08`, `0x08035040` | connect / timeout / HW-error paths |
| time formatting | `0x0802BD18` | `%02d:%02d:%02d` and `%dd %02d:%02d` |
| exception + IRQ stubs | `0x080363FD`-`0x0803655B` | see §6 |
| dispatch table | `0x08036C10` | 44 `{id, handler}` pairs |
| framing errors | `0x08037260`-`0x08037354` | the five `Error: S%d ...` strings |
| reset | `0x0803BA70` | §5 |
| idle / pump | `0x0803C458`-`0x0803C4D9` | event pump, IRQ trampolines, idle self-loop |

## 13. String catalog (real text, with the function that references it)

| address | text | referenced by |
| --- | --- | --- |
| `0x080149F8` | `2BDDP-102` | — |
| `0x08014A04` | `v%02d.%02d` | — |
| `0x08019EF4` | `BLE: error #0x%0.2X!` | `sub_08034F08`, `sub_08034F5E`, `sub_08034FA0`, `sub_08035014` |
| `0x08019F0C` | `RC-102-%06.6X` | — |
| `0x08019F1C` | `RadiaCode-102` | — |
| `0x0801F464` | `Start Main loop` | — |
| `0x08021CF4`…`0x08021D4C` | `printf_s: bad %ls argument`, `printf_s: bad %s argument`, `printf_s: %n disallowed`, `printf: bad %n argument` | — |
| `0x08022EB8`-area | `BLE: error #0x%0.2X!`, `BLE: Hardware initialization`, `BLE: Start`, `BLE: Stop`, `BLE: Init sequence error!`, `BLE: Start sequence error!` | `sub_08022E98` |
| `0x08027294` | `CRC Error: 0x%08X != 0x%08X` | — |
| `0x08028F14` | `Jul  7 2025 11:19:22` | — |
| `0x0802C4AF` | `constraint handler: bad message` | — |
| `0x08037267`…`0x08037354` | the five `Error: S%d ...` framing errors | `sub_08027D06` |
| `0x0802EDCC`…`0x0802EE24` | `wprintf_s: %n disallowed`, `wprintf: bad %n argument`, `wprintf_s: bad %ls/%s argument` | — |
| `0x08038124`…`0x080381A0` | `BLE: client connected`, `BLE: connection timeout expired`, `BLE: HW error/SPI`, `/Radio`, `/Timer overrun`, `/Unknown` | `sub_08035040`, `sub_08034F08` |
| `0x08038D9C` | `0123456789abcdefghijklmnopqrstuvwxyz` | — |
| `0x08038E5C`, `0x08038E80` | `BLE: disconnected by remote user`, `BLE: disconnected by reason 0x%0.2X` | `sub_08034E78` |
| `0x08039008` | `BLE: Connection parameter update error #0x%0.2X! Interval is %d.` | `sub_08022E98` |
| `0x080392DC` | `BLE: error packet received => %0.2X; %0.2X; %0.2X; %0.2X!` | `sub_08027086` |
| `0x0803BD3C` | `%d message(s) lost!` | `sub_08024638` |
| `0x0803BFE0`, `0x0803BFF0` | `%02d:%02d:%02d`, `%dd %02d:%02d` | `sub_0802BD18` |
| `0x0802F9F0`, `0x080306AC` | the two config blobs (§9-§10) | `sub_08028E40` |

1906 ASCII runs in total (`analysis/strings.json`); the rest are 4-7-character literal-pool
fragments.

## 14. Static-analysis facts

| metric | value |
| --- | --- |
| decoded instructions (capstone linear sweep) | 66,745 over 69,209 listing lines, 100 % byte coverage |
| function candidates | 1,867 |
| decompiled function blocks (Ghidra 12.2) | 1,895 (`seeded 1172`, `decompiled 1893`, `failed 2`) |
| unresolved stubs | `0x08016cc6`, `0x0802abf8` (data-table slots; code only in the listing) |
| functions reachable from a vector handler | 99 of 1,867 (the rest via tables / indirect calls) |
| deepest reachability | `Reset` -> 33 functions, depth 7 |
| most-called | `0x08017FA8` (163), `0x0801953C` (110), `0x08017FCC` (85), `0x080194F4` (63) |
| static `{id, handler}` runs | 8, 85 handlers, all present in the C output |
| ASCII strings | 1,906 |
| strings reached by a literal / functions with string refs | 87 / 38 (step 8) |

## 15. Querying the results

```powershell
python pipeline/tools/lookup.py 0x080275C4        # owning function + C line range + callers + dispatch ids + strings + asm
```

Indexes: `index.json` (function -> C lines), `analysis/{functions,xrefs,
vectors,callgraph,tables,strings,stats,verification,capture,container_check,vsfr_readout}.json`, and the
verification layer's `analysis/{roundtrip,crosscheck,differential,formal,confidence}.json` (§27). Naming: `sub_XXXXXXXX` (capstone index),
`FUN_xxxxxxxx` (Ghidra C), `handler_<n>_<name>` (vector entries), `tbl_<id>_<address>` (table handlers).

## 16. Caveats

* The listing is a linear sweep, so short data runs between functions decode as plausible instructions;
  trust mnemonics inside known function ranges, and expect `.word` / `ascii` / `.fill` lines for pools.
* Some hint-class 32-bit encodings fail to decode and appear as `.word` in the listing.
* Two functions remain stubs (§14); their bodies exist only as disassembly.
* `0x08036C10`'s 44-entry table is *not* the BLE command table: its ids (`0x400`-`0x40A`, `0x800`-`0x80A`,
  `0xC01`-`0xC18`) do not match the ids that answer on the wire, so it is an internal object/property
  registry keyed the same way — the real per-item dispatcher is the switch at `0x080275C4`.
* `date_time` is an **MS-DOS packed date/time** word (high half `(year-1980)<<9 | month<<5 | day`, low
  half `hour<<11 | minute<<5 | (second/2)`), so `0x5AE7428A` decodes to 2025-07-07 08:20:20 — it is *not*
  a Unix epoch (`rcfmt._decode_datetime`); the
  in-image build stamp string `Jul  7 2025 11:19:22` is the compiled `__DATE__ __TIME__` of the same build.

## 17. How a firmware update works

The protocol's own names come from the vendor SDK (`classes.dex` of the official APK, package
`ru.almacode.vk.corelib`): `SET_EXCHANGE`, `SET_BT_EXCHANGE_ID`, `SET_LOCAL_TIME`, `GET_STATUS`,
`GET_VERSION`, `GET_SERIAL`, `RD_FLASH_AREA`, `RD_HW_CONFIG`, `RD_SIGNAT`, `RD_VIRT_SFR`,
`RD_VIRT_SFR_BATCH`, `RD_VIRT_STRING`, `RD_VIRT_STRING_BATCH`, `FW_IMAGE_GET_INFO`, `FW_IMAGE_UPDATE`,
`FW_IMAGE_WRITE`, plus a flash status enum (`FLASH_OK`, `FLASH_PROG`, `FLASH_NOT_BLANK`, `FLASH_WR_PROT`,
`FLASH_RDP_ERROR`, `FLASH_INVALID_CRC`, `FLASH_INVALID_SIGN`, `FLASH_INVALID_TARGET`, `FLASH_INV_ADDR`,
`FLASH_REQUIRED`, `FLASH_VERIFY`, `FLASH_STATE`, …).

Three layers, only one of which is the "firmware":

| layer | content | replaced by an update? |
| --- | --- | --- |
| vendor bootloader | `0x08000000`-`0x0800FFFF` (64 KiB) | **no** — no block in any container starts below `0x08010000`, so the programmer itself survives |
| application image | `0x08010000`-`0x0803CA00`, i.e. `flash.bin` | **yes**, wholesale — it is a complete program (vectors, code, literal pools) with the config text compiled in |
| parameter areas | the two `RD_FLASH_AREA` records (0 and 1), XOR-obfuscated, seeded | no — separate, calibration/id-bearing, so per-unit data survives |

So: the *code* really is reflashed (a full image, not a data file), while the *device parameters* behave
like data: read via `0x081C`, written only through the VSFR/parameter commands.

### Step-by-step

1. **Open the session.** `SET_EXCHANGE` (`0x0007`) with the 4-byte sign `01 FF 12 FF`. The compiled-in
   copy of that constant is at `0x08027DA0` and `0x08028EEC` (word `0xFF12FF01`). Before it is accepted,
   most ids stay silent — verified: `0x0012` only answered after step 1. The sign is what the parser
   checks as `"Valid sign corrupted! Sgn = 0x%08X"`.
2. **Compare versions.** `FW_IMAGE_GET_INFO` (`0x0012`) returns `{u32 size, u32 buffer_size,
   u32 date_time, u32 crc32}` = `130148, 4096, 0x5AE7428A, 0x13095ABB`. The app holds the identical file
   as `assets/HardSoft/rc-102z.bin` inside the APK (130148 B — same length, so the app never needs the
   network during an update). Two decisions, straight from the app's strings:
   * `Firmware image signature match, CRC32 match` → nothing to do;
   * `Firmware image signature match, CRC32 mismatch, resetting` → start the transfer.
3. **Open the image session.** `FW_IMAGE_UPDATE` (one `0x0013`-style id in the same numeric block) —
   starts a staging session sized by `buffer_size` (4096).
4. **Stream the container.** Repeated `FW_IMAGE_WRITE`, each = offset + up-to-4096-byte chunk; the app
   logs `FW Image: Writing %d bytes at offset %d` per chunk, and any NAK becomes
   `FW_IMAGE_WRITE returned error #%d` where `#` is one of the `FLASH_*` codes above.
   130148 B / 4096 ≈ 32 chunks.
5. **Verify.** The device recomputes the whole-file CRC-32/MPEG-2 (poly `0x04C11DB7` is baked into the
   image at `0x0801F424`, `0x0802ACD8`, `0x0802D748`) and the per-block CRCs; mismatch is reported with
   `CRC Error: 0x%08X != 0x%08X` (`0x08027294`). Only a CRC-verified image is activated.
6. **Reboot into the new image.** The app issues the boot step (failure string `Failed to boot device`);
   on the device the reset is the standard `SCB->AIRCR = 0x05FA0004` (VECTKEY | SYSRESETREQ) — that
   constant pair sits in pools at `0x0801E330`, `0x08022724`, `0x08027DC0`. The BLE link drops, and the
   app reconnects; if it does not come back the app reports `RECONNECTION_TIMED_OUT_DURING_UPDATE`.
   The bootloader then re-validates and jumps to `0x08010001`; the app's own vector table at
   `0x08010000` is what makes that relocation work.

Progress is surfaced per chunk through `FWProgressUpdater` / `EVT_FW_WRITE`.

### Where the numbered ids come from

The device keeps a 91-entry table at `0x08035A64` of `{u32 id, u32 getter, u32 setter}` with ids
`0x00`-`0x5A` (getters `0x0801BB1F`+, setters `0x0801BD95`+) — that is the index space the
`RD_VIRT_SFR`/`RD_VIRT_STRING` batch commands use, and it is why the small wire ids (`0x0005`, `0x0007`,
`0x000A`, `0x000B`, `0x0012`, `0x0013`) answer at all. Larger ids (`0x0101`, `0x0807`, `0x081C`,
`0x0824`-`0x082B`, `0x0A04`) are handled by second-level switches, and per-item access ultimately goes
through the VSFR address chain in `sub_080275C4` (§7).

## 18. Integrity / anti-brick properties

| control | evidence |
| --- | --- |
| Every frame is length-prefixed and validated on 4 independent fields (packet size, command, sign, data frame) before anything is executed | `Error: S%d …` strings @ `0x08037267`-`0x08037354` |
| A session must be opened before state-changing ids take effect, so a stray packet cannot half-program the device | `SET_EXCHANGE` gating (observed), sign constant `0xFF12FF01` |
| Whole-image CRC-32/MPEG-2 **and** per-block CRCs must match before activation | `CRC Error: 0x%08X != 0x%08X`, poly in 3 places, `FLASH_INVALID_CRC` |
| The write path checks the flash controller's own error bits and reports them as numbered errors | `FLASH_PROG`, `FLASH_NOT_BLANK`, `FLASH_WR_PROT`, `FLASH_RDP_ERROR`, `FLASH_VERIFY` |
| The bootloader is outside every container, so it is never overwritten by an update | all 8 blocks start at `0x08010000` or higher |
| A failed/timed-out transfer leaves the previous image active: activation happens only after the CRC check, and reconnect failures are reported rather than assumed | `RECONNECTION_TIMED_OUT_DURING_UPDATE` |
| Parameter/calibration records are separate from the code image | the two `0x081C` areas keep their own seed + XOR stream |
| Only 13 ids accept anything at all (full `0x0000`-`0x0FFF` sweep) — a small, closed surface | `analysis/sweep_noarg.json`, `analysis/sweep_witharg.json` |

Practical consequences for this repo's read-only workflow: `0x0005`, `0x000A`, `0x000B`, `0x0012`,
`0x0013`, `0x0101`, `0x0807`, `0x081C`, `0x0824`-`0x082B` are pure reads; `0x0007` (sign) and `0x0A04`
(wall-clock) are the only idempotent writes that were exercised. Nothing else was needed to reproduce
`flash.bin` bit-for-bit (§1 identity table).

## 19. Boot-up and the main loop

```
 reset (hardware) ──► 0x08000000 vendor bootloader
        │  validates the application image (whole-image CRC-32/MPEG-2 + the 8 block CRCs)
        │  mismatch  -> stays in the bootloader and waits for FW_IMAGE_WRITE
        │  ok        -> jumps to the application vector table
        ▼
 0x08010001  Reset @ 0x0803BA70/71
        │  1. SP = word at 0x08010000 = 0x20000800
        │  2. install the 98-entry vector table (VTOR = 0x08010000)
        │  3. bind the 91-entry item table @ 0x08035A64 and the 44-entry registry @ 0x08036C10
        ▼
 "Start Main loop" @ 0x0801F464   (driver-table dispatcher: poll each registered driver)
        ▼
 +--------------------------------------+    +-------------------------------------+
 | event pump 0x0803C458-0x0803C4D9     | <-- | the 9 ISRs post bits into a shadow  |
 | drains queues, runs deferred work    |    | status word (0x20 / 0x40 / 0x80 ...) |
 +--------------------------------------+    +-------------------------------------+
        ▼
 "BLE: Hardware initialization" -> "BLE: Start"      (0x08022EE0-0x08022F34)
        ▼  advertise "RC-102-008228" ("RC-102-%06.6X" @ 0x08019F0C)
        ▼  connect + subscribe  ->  "BLE: client connected" @ 0x08038124
        ▼  first host frame: SET_EXCHANGE 0x0007, sign 01 FF 12 FF -> session open
```

Failure paths are stringed: `BLE: Init sequence error!`, `BLE: Start sequence error!`,
`BLE: connection timeout expired`, `BLE: HW error/SPI|Radio|Timer overrun|Unknown`. Idle time is spent in
the 4-byte self-loop at `0x0803C4D9`, which doubles as the unused-vector target (66 literal occurrences).

## 20. Record-stream grammar (VS `0x100`, `DATA_BUF`)

Observed on a live unit; two record sizes alternate, and the record counter byte increments once per
record, so the stride is derived from the anchor positions (45, 21, 45, 21, ...; 14 full frames + a
65-byte tail in a 1010-byte capture, and the same stride in a second 1058-byte capture).

```
 A-record, 45 B   header(13) + 2 x {u32 raw, f32 value, f32 ripple, u32 stamp} + 0
   [0] u8      seq                                   0x22
   [1] u8      groupId                               0x01  GRP_RawData
   [2] u8      channelId                             0x02  CHN_Count
   [3] u8      tag                                   0x2d
   [4] u8[3]   tick, 24-bit LE                        0xE6A994
   [7] u8 0x02, [8] u8 0x00, [9..12] u32 9600
  [13] u32 475, [17] f32 4.947917, [21] f32 7.438e-06, [25] u32 stamp 33 01 00 b0
  [29] u32 468, [33] f32 4.875,    [37] f32 8.399e-06, [41] u32 stamp 3a 01 00 b0

 B-record, 21 B   header(4) + tick(3) + u32 + f32 + u8 + 5 B tail
   [0] u8      seq                                   0x23
   [1] u8      groupId                               0x00  GRP_RealTimeData
   [2] u8      channelId                             0x03  CHN_CountRate
   [3] u8      tag                                   0x40
   [4] u8[3]   tick                                   0xE6A9F3   (+95 from A)
   [7] u32      28403139                               window/uptime word
  [11] f32      0.0595957                              the sample
  [15] u8       0x8f                                   flags
  [16] u8[5]    11 10 27 40 b0                          constant tail
```

The `f32` of the B-record equals the value the `0x8021` VSFR reports, so the two read paths are two views
of the same sample set. The buffer grows with uptime (1004 -> 1058 bytes observed across reads 1 s apart)
and is the only place the per-frame series is exposed.

## 21. Live readout, decoded

Three structures worth naming precisely, all captured in `analysis/capture.json`.

**The 76-byte `DEVICE_INFO` record (VS `0x0F0`, duplicated at `0x203`)**

```
 [0..3]   u32 magic 0x19601217          (same magic opens both RD_FLASH areas)
 [4..]    repeating {u16 count, u16 tag} groups, then IEEE-754 floats
          observed:  {1, 0x50} {1, 0x10} {0} {3, 0x20} 5.158747 9.502541 0.005710896
                     {9, 0x42} 25401.26 46.20266 -0.08978523 16.45725 -0.1268294
                              0.0001654905 0.07347484 0.00061069 1.228892e-07
          5.158747 is VS 0x202's A0, so this record carries the factory calibration set
```

**The window record (VS `0x220`)**: `{u32 counts = 64573, u32 ms = 184233, u32 us = 30612653, u32 0}` -
the accumulation window the current rate is computed over, which is why the 500-ms and 3-min cadences are
visible in one record.

**The spectrum headers (VS `0x200`, `0x205`)**: 22 bytes = `{u32 0, f32 A0, f32 A1, f32 A2, u16 0x4000}`.
`0x206`/`0x207` (10 B each) are the accumulator pairs, zero at idle. `0x208` (104 B) is a fixed descending
power-of-two table used by the scale/rounding code, not measurement data.

## 22. Timings and intervals (the device's own numbers)

| key | value | consequence |
| --- | --- | --- |
| `FrameTimeStep_us` | 10000 | 100 kHz tick grid; the record ticks advance ~90 between A and B |
| `MinFrmPeriod_ms` | 500 | 2 Hz real-time ceiling |
| `DBLag_ms` | 180000 | 3 min for the `GRP_RareData` / DB-backed group |
| `CR_AlarmsNum` / band | 2 / `1e-1`-`50e3` cps | two count-rate alarm levels |
| `DR_AlarmsNum` / band | 2 / `1e-6`-`1e-1` R/h | two dose-rate levels |
| `DS_AlarmsNum` / band | 2 / `1e-6`-`1e3` R | two accumulated-dose levels |
| `VSFR_DISP_OFF_TIME` | 6-entry enum | live index 5 = 5 min |
| `DispBacklight` | 0-9 | live value 9 |

## 23. Storage budget

| region | range / size | note |
| --- | --- | --- |
| bootloader | `0x08000000`-`0x0800FFFF`, 65536 B | not present in any container |
| application | `0x08010000`-`0x0803CA00`, 182784 B | 8 blocks, individually CRC'd |
| unused flash tail | `0x0803CA00`-`0x08040000`, 13824 B | free |
| RAM (modelled) | `0x20000000`-`0x2000FFFF`, 65536 B | stack top `0x20000800` |
| container on the wire | 130148 B | 8 Mangle/LZSS blocks, header 52 B, `buffer_size` 32768 |
| parameter area 0 | 72 B | magic + size + `0xFF` filler |
| parameter area 1 | 448 B | magic + size `0x1C0` + serial / file / product strings + `05 01 da da da` + 3000 |

## 24. App-side persistence model

The official APK ships `assets/DatabaseInit.sql`; the tables are `Log`, `Tracks`, `TracksData`,
`Backgrounds`, `Spectrograms`, `SpgSpectrums`, `DeviceProfiles`, `Folders`, `Dictionary`. The `Log` table
is the mirror of the channel model:

```
 Log(Id, Timestamp, LastModified, DeviceSN, DeviceFW, GroupId, Channels, Event, EventParam1,
     PulseCount, CountRate, DoseRate, DoseRateError, CountRateError, AlarmDoseRate, AlarmDose,
     AlarmCountRate, AlarmTemp, DAcDuration, Dose, Temp, Charge, Flags, Latitude, Longitude,
     Comment, SystemComment)
      ^^^^^^^^^^  ^^^^^^^^^  ^^^^^^^^  ^^^^^^^^  ^^^^      ^^^^^^  ^^^^^^
        id 2        id 3       id 4      id 5/16   id 7     id 8    id 9     <- [DataStructure] ids
```

plus `Tracks`/`TracksData` (GPS traces), `Spectrograms`/`SpgSpectrums` (stored histograms), `Backgrounds`
(reference spectra) and `Dictionary` (id/string pairs). `GroupId` is the `GRP_*` id and `Flags` is
`CHN_Flags`, so a row is one group snapshot - which matches the group-oriented wire protocol rather than
per-channel rows.

## 25. Capability matrix

| # | capability | path | status |
| --- | --- | --- | --- |
| 1 | identity: serial, product, build stamps, versions | `0x000A`, `0x000B`, `0x0101` | read - works |
| 2 | image identity (`size/date_time/crc32/chunk`) | `0x0012` | read - works |
| 3 | staged frame count | `0x0013` | read - works |
| 4 | full configuration + channel model text | `0x0826` VS `0x002` | read - 3256 B, byte-identical to flash |
| 5 | calibration polynomial, spectrum header, window | `0x0826` VS `0x200`-`0x220` | read - works |
| 6 | real-time record stream | `0x0826` VS `0x100` | read - grammar in §20 |
| 7 | event log ring | `0x0826` VS `0x00F` | read - works |
| 8 | per-unit parameter areas | `0x081C` 0/1 | read - XOR-unwrapped |
| 9 | device/display/sound/vibro/alarm/charger settings | `0x0824` + VSFR addr | read - 20 entries, §README 5.4 |
| 10 | measurement + system VSFR block at idle | `0x0824` `0x8000`+, `0xFFFF0000`+ | **zero word** (rare-data cycle) |
| 11 | 1024-channel spectrum array | - | **locked out**, no id returns it |
| 12 | raw memory read | - | **locked out**, no such id (two full sweeps) |
| 13 | bulk image bytes from the device | - | **locked out** by design; vendor file + CRC triple instead |
| 14 | write calibration/parameter (VSFR/string/batch) | `0x0825`, `0x0827`, `0x082B` | named by the SDK, **not exercised** here |
| 15 | wall clock | `0x0A04` | write - idempotent, used by the pipeline |
| 16 | open the session | `0x0007` | write - idempotent sign |
| 17 | batch VSFR reads | `0x082A` | partial - plain `u32` address form only |
| 18 | numbered item table through the index form | `0x0824` `0x00`-`0x5A` | **no data**, recovered statically (step 10) |
| 19 | SWD/JTAG dump | - | locked out, BLE-only workflow |

## 26. Pipeline reference

Artifacts are listed relative to the target directory (`firmware/<model>/<hw+fw>/`):

| step | file | artifact |
| --- | --- | --- |
| 1 | `pipeline/step1_validate.py` | self-test of Mangle/CRC/LZSS against the reference vectors |
| 2 | `pipeline/step2_probe.py` (+`--sweep`) | `analysis/capture.json`, `analysis/sweep_noarg.json`, `analysis/sweep_witharg.json` |
| 3 | `pipeline/step3_fetch.py` | `<container>.bin` in the target dir, `official/{apk,exe}.bin`, `analysis/container_check.json` |
| 4 | `pipeline/step4_decode.py` | `flash.bin`, `blocks.json` |
| 5 | `pipeline/step5_disassemble.py` | `listing.s`, `analysis/{strings,vectors,functions,stats}.json` |
| 6 | `pipeline/step6_decompile.py` + `pipeline/scripts/DumpC.java` | `decompiled.c` |
| 7 | `pipeline/step7_index_c.py` | `index.json` |
| 8 | `pipeline/step8_xrefs.py` | `analysis/xrefs.json` |
| 9 | `pipeline/step9_callgraph.py` | `analysis/callgraph.json` |
| 10 | `pipeline/step10_tables.py` | `analysis/tables.json` |
| 11 | `pipeline/step11_verify.py` | `analysis/verification.json` |
| 12 | `pipeline/step12_report.py` | `analysis/summary.md`, `manifest.json` |
| 13 | `pipeline/step13_roundtrip.py` | `analysis/roundtrip.json` - container re-encoded byte for byte (§27) |
| 14 | `pipeline/step14_crosscheck.py` (+ `pipeline/scripts/DumpListing.java`) | `analysis/ghidra_listing.json`, `analysis/crosscheck.json` |
| 15 | `pipeline/step15_differential.py` (+ `emulate.py`, `models.py`) | `analysis/differential.json` |
| 16 | `pipeline/step16_formal.py` | `analysis/formal.json` |
| 17 | `pipeline/step17_confidence.py` | `analysis/confidence.json`, `analysis/confidence.md` |
| - | `pipeline/tools/*.py` | one-off inspectors: `lookup.py`, `read_vsfrs.py`, `probe.py`, `inspect_*.py`, `debug_*.py`, `blescan.py`, `ifaces.py`, `fetch_apk.py`, `analyze_official.py` |

Run from the repo root: `python pipeline/run.py`, `--only 4,5`, `--from 7`, `--device <key>`,
`--all-devices`; the target comes from `pipeline/devices.json` and reaches every step via `RC_TARGET`.
`pipeline/protocol.py` holds
the id table, the frame codec and the record decoders; `pipeline/rcble.py`, `rcsession.py`, `rcfmt.py` are
the transport and container libraries.

## 27. Verification layers and confidence

Five independent layers, all offline, all per build. `python pipeline/run.py --only 13,14,15,16,17`
(`--all-devices` for every registered build) writes `analysis/confidence.json` + `confidence.md`; the
categories are deliberately **not** merged into one percentage - each answers a different question.
Reference build `rc-102/hw1-fw4.14`:

| category | measured | how |
| --- | --- | --- |
| `byte_matched` | `130148/130148` container bytes, key blocks `8/8`, data blocks `8/8`, header fields and the CRC field equal, key-block CRC pair equal `8/8`, whole-file CRC equal to the unit's `0x0012` reply | step 13 - `rcfmt.reencode_file` rewrites the vendor file from the model and the bytes are compared (`recompress=False`, so the payload stream is carried verbatim) |
| `formally_verified` | `10/10` goals proved (z3 5.3.3): Mangle one round and the 48-round chain are permutations, the CRC register and word-step forms agree, CRC of the empty message is the init word, Borland LCG has full period (Hull-Dobell), MS-DOS date pack/unpack round-trips, LZSS token layout and window-slot step, `align_size` is the least multiple of 8 | step 16 - bit-vector premises, `unsat` on the negation |
| `tested` | `8/8` function cases, `122` instructions executed, `189/189` model vectors, `8/8` decompressed-length identities, `39260` disassembly lines compared at `0.9999` agreement | step 15 runs each routine natively in Unicorn and compares the returned word **and** every byte the routine wrote with the Python transcription (the ABI's stack slots are excluded on both sides); the vectors cover CRC-32/MPEG-2, Mangle round/inverse and whole blocks, LZSS decode, MS-DOS dates, the Borland LCG (synthetic and against the captured `0x081C` replies) |
| `preserved_unchanged` | `248320/248320` image bytes covered, `66745` instructions, `69209` listing lines, `1895` C blocks, `1027` data/ascii items, `3888` key-block tail bytes carried | the mixed C + assembly listing keeps those regions at their original address without rewriting them |
| `unresolved` | `4` named items | listed below |

Per build (same command, same fields):

| target | container bytes | proofs | function cases | model vectors | line agreement | image bytes / insns / C blocks |
| --- | --- | --- | --- | --- | --- | --- |
| `rc-101/fw4.14` | 130388/130388 | 10/10 | 0/0 | 183/183 | 37891/39338 (`0.9999`) | 249344 / 67163 / 1832 |
| `rc-102/hw1-fw4.14` | 130148/130148 | 10/10 | 8/8 | 189/189 | 39260/40743 (`0.9999`) | 248320 / 66745 / 1895 |
| `rc-103/fw4.14` | 130132/130132 | 10/10 | 8/8 | 183/183 | 39260/40743 (`0.9999`) | 248320 / 66745 / 1895 |
| `rc-103g/fw4.14` | 130444/130444 | 10/10 | 8/8 | 183/183 | 39258/40743 (`0.9999`) | 248576 / 66570 / 1894 |
| `rc-110/fw4.14` | 133312/133312 | 10/10 | 0/0 | 186/186 | 39619/41147 (`0.9999`) | 251904 / 67873 / 1934 |
| `rc-410/fw4.16` | 140836/140836 | 10/10 | 0/0 | 189/189 | 38477/40453 (`0.9958`) | 264192 / 72189 / 2123 |

`0/0` function cases means the 16-byte signature of the transcribed routines is not at the same address
in that build, so nothing is claimed - not a failure (the five builds without a live unit also carry the
extra unresolved item "on-device frame comparison not available offline"). `0.9958` for `rc-410` is the
one build where the two decoders differ on more lines (`161` graded semantic, largely the `movs r0, #9`
vs `mov.cs r0, 0x9` flag-attachment class), which is why its agreement is the only one below `0.9999`.
The vector total itself scales with the container's block count
(`mangle_blocks` runs twice per block, `lzss_decode` once) and gains the 6 device-anchored Borland
vectors where a `capture.json` exists - hence `189` for `rc-102` and `rc-410`, `183`/`186` elsewhere.

The four remaining open points for `rc-102/hw1-fw4.14` (`analysis/confidence.json -> unresolved`):

1. the definition of the per-block key-block CRC pair beyond `crc1 == crc2` (30 buffer/variant
   combinations checked, none matched - only the equality is verified);
2. the pipeline's own LZSS encoder is not bit-identical with the vendor stream (`0/8` stream-identical,
   `4649/31831` tokens, `125890` vs `125815` bits) - a tie-break/search-order difference in the vendor's
   hash chain, while every stream decodes identically;
3. `4` disassembly lines where capstone and SLEIGH still disagree after normalisation:
   `0x080220EA`, `0x080220EE`, `0x080255B6`, `0x0802C266`;
4. lines only one decoder reaches - capstone sweeps the whole image, Ghidra stops at data
   (`28676` only-capstone, `1483` only-ghidra).
