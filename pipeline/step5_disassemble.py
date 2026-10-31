"""Disassemble the decoded RadiaCode-102 firmware (ARMv7E-M / Thumb-2) and index it.

Strategy: linear sweep of the whole flash image with re-synchronisation on zero runs and
ASCII blobs, plus a function index built from the interrupt vector table and every
observed branch/link target.

Outputs (under ./firmware):
  rc102_flash.bin          flat flash image, base 0x08010000 (written by decode_firmware.py)
  listing/rc102_flash.s    annotated Thumb-2 disassembly
  analysis/vectors.json    interrupt vector table
  analysis/strings.json    ASCII strings with addresses
  analysis/functions.json  function index (address, name, size, callers, callee count)
"""

import json
import os
from collections import defaultdict

from capstone import CS_ARCH_ARM, CS_MODE_THUMB, Cs

BASE = 0x08000000
IMAGE = "firmware/rc102_flash.bin"
VTOR = 0x08010000

os.makedirs("firmware/analysis", exist_ok=True)
os.makedirs("firmware/listing", exist_ok=True)

CORE_VECTORS = [
    "InitialSP", "Reset", "NMI", "HardFault", "MemManage", "BusFault", "UsageFault",
    "Reserved7", "Reserved8", "Reserved9", "Reserved10", "SVCall", "DebugMon",
    "Reserved13", "PendSV", "SysTick",
]
IRQ_NAMES = [
    "WWDG", "PVD", "TAMP_STAMP", "RTC_WKUP", "FLASH", "RCC", "EXTI0", "EXTI1", "EXTI2",
    "EXTI3", "EXTI4", "DMA1_CH0", "DMA1_CH1", "DMA1_CH2", "DMA1_CH3", "DMA1_CH4",
    "DMA1_CH5", "DMA1_CH6", "ADC1_2", "USB_HP", "USB_LP", "DAC", "SPI1", "USART1",
    "USART2", "USART3", "EXTI9_5", "TIM1", "TIM2", "TIM3", "TIM4", "TIM5", "SPI2",
    "TIM8", "TIM7", "LCD", "TIM9", "TIM10", "TIM11", "USB_OTG_FS", "DMA2_CH0",
    "DMA2_CH1", "DMA2_CH2", "DMA2_CH3", "DMA2_CH4", "DMA2_CH5", "DMA2_CH6", "USART6",
    "JPEG", "NSTC", "AES", "RNG", "CAPTURE_COMPARE", "LCD_TFT", "TIM12", "TIM13",
    "TIM14", "DMA2D", "COMP", "LPTIM1", "LPUART1", "QUADSPI", "LPTIM2", "USB_FS",
    "DMAMUX", "LPUART2", "LPTIM3", "LPTIM4", "LPTIM5", "RTC",
]

data = open(IMAGE, "rb").read()
size = len(data)
end = BASE + size

md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)

# ------------------------------------------------------------------ strings
strings = []
start = None
for i, byte in enumerate(data):
    if 32 <= byte < 127 or byte == 10:
        if start is None:
            start = i
    else:
        if start is not None and i - start >= 4:
            strings.append({"offset": start, "length": i - start, "text": data[start:i].decode("ascii")})
        start = None
string_by_start = {item["offset"]: item for item in strings}
with open("firmware/analysis/strings.json", "w", encoding="utf-8") as fh:
    json.dump(
        [{"address": f"0x{BASE + s['offset']:08X}", "length": s["length"], "text": s["text"]} for s in strings],
        fh,
        indent=2,
    )

# ------------------------------------------------------------------ vector table
rows = []
index = 0
while index < 128 and VTOR + 4 * index + 4 <= end:
    addr = VTOR + 4 * index
    value = int.from_bytes(data[addr - BASE : addr - BASE + 4], "little")
    if index == 0:
        name = "InitialSP"
    elif index < len(CORE_VECTORS):
        name = CORE_VECTORS[index]
    else:
        irq = index - len(CORE_VECTORS)
        name = f"IRQ{irq}_{IRQ_NAMES[irq]}" if irq < len(IRQ_NAMES) else f"IRQ{irq}"
    plausible = value == 0 or ((value & 1) and BASE <= (value & ~1) < end)
    if index and not plausible:
        break
    if index == 0 and not (0x2000_0000 <= value <= 0x2010_0000):
        break
    rows.append({"index": index, "name": name, "address": f"0x{value:08X}"})
    index += 1
    if value == 0 and all(
        int.from_bytes(data[addr + 4 * k - BASE : addr + 4 * k - BASE + 4], "little") == 0 for k in range(1, 9)
    ):
        break
with open("firmware/analysis/vectors.json", "w", encoding="utf-8") as fh:
    json.dump({"vtor": f"0x{VTOR:08X}", "count": len(rows), "entries": rows}, fh, indent=2)

VTOR_END = VTOR + 4 * len(rows)  # the table itself is data, not instructions

# ------------------------------------------------------------------ linear sweep
insns = {}
items = []  # ("ins"|"word"|"ascii"|"fill", address, size) in sweep order
callers = defaultdict(set)
callees = defaultdict(set)


def note(addr, mnemonic, op):
    """Record call graph edges from a decoded instruction."""
    if not op.startswith("#0x"):
        return
    if mnemonic.split(".")[0] not in ("b", "bl"):
        return
    target = int(op[1:], 0)
    if BASE <= (target & ~1) < end:
        callees[addr].add(target & ~1)
        if mnemonic.split(".")[0] == "bl":
            callers[target & ~1].add(addr)


def zero_run(off):
    run = 0
    while off + run + 4 <= size and data[off + run : off + run + 4] == b"\x00\x00\x00\x00":
        run += 4
    return run


def is_data(off):
    addr = BASE + off
    return (
        data[off : off + 4] == b"\x00\x00\x00\x00"
        or off in string_by_start
        or VTOR <= addr < VTOR_END
    )


def decode_run(start_off):
    """Decode a sequential stretch of Thumb instructions; return the next offset."""
    window = data[start_off : start_off + 4096]
    last = start_off
    for ins in md.disasm(window, BASE + start_off):
        insns[ins.address] = ins
        note(ins.address, ins.mnemonic, ins.op_str)
        items.append(("ins", ins.address, ins.size))
        last = ins.address - BASE + ins.size
        if last >= size or is_data(last):
            break
    return last


pos = 0
while pos < size:
    if data[pos : pos + 4] == b"\x00\x00\x00\x00":
        run = max(zero_run(pos), 4)
        items.append(("fill", BASE + pos, run))
        pos += run
        continue
    if VTOR <= BASE + pos < VTOR_END:
        items.append(("word", BASE + pos, 4))  # inside the vector table
        pos += 4
        continue
    if pos in string_by_start:
        item = string_by_start[pos]
        term = 1 if pos + item["length"] < size and data[pos + item["length"]] == 0 else 0
        advance = item["length"] + term
        items.append(("ascii", BASE + pos, advance))
        pos += advance
        if pos % 2:  # keep the Thumb stream 2-byte aligned
            items.append(("byte", BASE + pos, 1))
            pos += 1
        continue
    nxt = decode_run(pos)
    if nxt <= pos:
        items.append(("word", BASE + pos, min(4, size - pos)))
        pos += 4
    else:
        pos = nxt

# ------------------------------------------------------------------ names
names = {}
for row in rows[1:]:
    target = int(row["address"], 16) & ~1
    if BASE <= target < end:
        names.setdefault(target, f"handler_{row['name'].lower()}")
for target in list(callers):
    names.setdefault(target, f"sub_{target:08X}")

# ------------------------------------------------------------------ listing
lines = [
    "; RadiaCode-102 firmware (rc-102z.bin, version 4.14, whole-file crc 13095abb)",
    f"; STM32L4 series (ARMv7E-M, Thumb-2), flash image base 0x{BASE:08X}, size 0x{size:x} ({size} bytes)",
    f"; vector table at 0x{VTOR:08X} ({len(rows)} entries), {len(insns)} instructions decoded",
    "",
]
for kind, addr, width in items:
    off = addr - BASE
    if kind == "ins":
        ins = insns[addr]
        raw = data[off : off + ins.size].hex(" ")
        label = f"        ; {names[addr]}" if addr in names else ""
        lines.append(f"{addr:08x}  {raw:<10}  {ins.mnemonic} {ins.op_str}{label}".rstrip())
    elif kind == "ascii":
        item = string_by_start[off]
        lines.append(f"{addr:08x}              ascii    \"{item['text'].replace(chr(10), chr(92) + 'n')}\"")
    elif kind == "fill":
        lines.append(f"{addr:08x}              .fill    0x{width:x} zero bytes")
    elif kind == "byte":
        lines.append(f"{addr:08x}  {data[off]:02x}          .byte    0x{data[off]:02X}")
    else:
        word = int.from_bytes(data[off : off + 4], "little")
        lines.append(f"{addr:08x}  {data[off:off+4].hex(' ')}   .word    0x{word:08X}")
with open("firmware/listing/rc102_flash.s", "w", encoding="utf-8") as fh:
    fh.write("\n".join(lines) + "\n")

# ------------------------------------------------------------------ function index
starts = {(int(r["address"], 16) & ~1) for r in rows[1:]} | set(callers)
for addr, ins in insns.items():
    if (ins.mnemonic == "bx" and ins.op_str == "lr") or (ins.mnemonic == "pop" and "pc" in ins.op_str):
        starts.add(addr + ins.size)  # a return ends a function; the next address starts one
starts = sorted(addr for addr in starts if addr in insns)
functions = []
for position, addr in enumerate(starts):
    nxt = starts[position + 1] if position + 1 < len(starts) else end
    decoded_here = 0
    probe = addr
    while probe in insns and probe < nxt:
        decoded_here += 1
        probe += insns[probe].size
    functions.append(
        {
            "address": f"0x{addr:08X}",
            "name": names.get(addr, f"sub_{addr:08X}"),
            "size": nxt - addr,
            "instructions_decoded": decoded_here,
            "callers": [f"0x{c:08X}" for c in sorted(callers[addr])],
            "callee_count": len(callees[addr]),
        }
    )
with open("firmware/analysis/functions.json", "w", encoding="utf-8") as fh:
    json.dump(functions, fh, indent=2)

stats = {
    "image_bytes": size,
    "base": f"0x{BASE:08X}",
    "end": f"0x{end:08X}",
    "instructions": len(insns),
    "functions": len(functions),
    "strings": len(strings),
    "vectors": len(rows),
    "listing_lines": len(lines),
    "covered_bytes": sum(width for _, _, width in items),
    "data_word_items": sum(1 for kind, _, _ in items if kind == "word"),
    "ascii_items": sum(1 for kind, _, _ in items if kind == "ascii"),
    "fill_items": sum(1 for kind, _, _ in items if kind == "fill"),
    "byte_items": sum(1 for kind, _, _ in items if kind == "byte"),
}
with open("firmware/analysis/stats.json", "w", encoding="utf-8") as fh:
    json.dump(stats, fh, indent=2)

print(json.dumps(stats))
