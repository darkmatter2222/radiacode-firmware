"""Bounded Cortex-M4 function execution, not a board/peripheral simulator.

Each caller must create a fresh emulator for an independent case. MMIO is modeled
as RAM and reported separately; it does not establish hardware equivalence.
"""
from unicorn import (Uc, UcError, UC_ARCH_ARM, UC_MODE_THUMB, UC_MODE_MCLASS,
                     UC_PROT_READ, UC_PROT_EXEC, UC_HOOK_CODE,
                     UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE)
from unicorn import arm_const
from unicorn.arm_const import (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2,
    UC_ARM_REG_R3, UC_ARM_REG_R12, UC_ARM_REG_LR, UC_ARM_REG_SP, UC_ARM_REG_PC,
    UC_ARM_REG_C1_C0_2, UC_CPU_ARM_CORTEX_M4)

FLASH_BASE, FLASH_SIZE = 0x08000000, 0x80000
# Map the 64 KiB logical SRAM window used by observed globals (event ring at
# 0x2000f424). This test map does not establish the physical MCU RAM capacity.
SRAM_BASE, SRAM_SIZE = 0x20000000, 0x10000
STACK_TOP = 0x20007F00
STACK_RANGE = (0x20007000, 0x20008000)
SENTINEL = 0x0A0A0001
REGIONS = [(0x0A0A0000, 0x1000), (0x1FFF0000, 0x10000),
           (0x40000000, 0x20000), (0x48000000, 0x10000), (0xE000E000, 0x1000)]
M32_MASK = 0xFFFFFFFF


def is_mmio(address):
    return 0x40000000 <= address < 0x60000000 or 0xE0000000 <= address < 0xE0100000


class Trace:
    def __init__(self):
        self.clear()

    def clear(self):
        self.writes, self.reads, self.mmio = [], [], []
        self.instructions = 0
        self.addresses, self.edges = set(), set()
        self.previous = None

    def final_writes(self):
        # Expand BEFORE collapsing: overlapping widths and ordering matter.
        out = {}
        for address, size, value in self.writes:
            for i in range(size):
                out[address + i] = (value >> (8 * i)) & 255
        return out


def new_emulator(flash):
    if len(flash) > FLASH_SIZE:
        raise ValueError("image exceeds configured flash")
    emu = Uc(UC_ARCH_ARM, UC_MODE_THUMB | UC_MODE_MCLASS)
    emu.ctl_set_cpu_model(UC_CPU_ARM_CORTEX_M4)
    emu.reg_write(UC_ARM_REG_C1_C0_2, 0xF << 20)
    trace = Trace()
    emu.mem_map(FLASH_BASE, FLASH_SIZE)
    emu.mem_write(FLASH_BASE, bytes(flash))
    emu.mem_protect(FLASH_BASE, FLASH_SIZE, UC_PROT_READ | UC_PROT_EXEC)
    emu.mem_map(SRAM_BASE, SRAM_SIZE)
    for base, size in REGIONS:
        emu.mem_map(base, size)
    emu.mem_write(SENTINEL & ~1, b"\x00\xbe")

    def on_code(uc, address, size, user):
        if address == SENTINEL & ~1:
            uc.emu_stop()
            return
        trace.instructions += 1
        trace.addresses.add(address)
        if trace.previous is not None:
            trace.edges.add((trace.previous, address))
        trace.previous = address

    def on_write(uc, access, address, size, value, user):
        trace.writes.append((address, size, value))
        if is_mmio(address):
            trace.mmio.append(("write", address, size, value))

    def on_read(uc, access, address, size, value, user):
        trace.reads.append((address, size))
        if is_mmio(address):
            trace.mmio.append(("read", address, size,
                               int.from_bytes(uc.mem_read(address, size), "little")))

    emu.hook_add(UC_HOOK_CODE, on_code)
    # Unicorn 2.1.4 global RAM read hooks corrupt ITSTATE on conditional VFP
    # loads (permanent regression: 0x0802abf8). Only MMIO reads are part of
    # this harness contract. Keep the observer outside ordinary RAM/flash.
    emu.hook_add(UC_HOOK_MEM_READ, on_read, begin=0x40000000, end=0x5fffffff)
    emu.hook_add(UC_HOOK_MEM_READ, on_read, begin=0xe0000000, end=0xe00fffff)
    emu.hook_add(UC_HOOK_MEM_WRITE, on_write)
    # Unmapped accesses are faults. Returning True without mapping is not recovery.
    return emu, trace


def preset(emu, pairs):
    for address, value in pairs:
        emu.mem_write(address, bytes(value))


def read_word(emu, address):
    return int.from_bytes(emu.mem_read(address, 4), "little")


def run_function(emu, trace, address, args=(0, 0, 0, 0), cycles=200000):
    if len(args) != 4 or cycles <= 0:
        raise ValueError("four register arguments and a positive instruction budget required")
    saved = {getattr(arm_const, "UC_ARM_REG_R%d" % i): (0xA5000000 + i) for i in range(4,12)}
    for reg, value in saved.items():
        emu.reg_write(reg, value)
    emu.reg_write(UC_ARM_REG_SP, STACK_TOP)
    emu.reg_write(UC_ARM_REG_LR, SENTINEL)
    for reg, value in zip((UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3), args):
        emu.reg_write(reg, value & M32_MASK)
    emu.reg_write(UC_ARM_REG_R12, 0)
    trace.clear()
    error = None
    try:
        emu.emu_start(address | 1, SENTINEL & ~1, count=cycles)
    except UcError as exc:
        error = str(exc)
    pc = emu.reg_read(UC_ARM_REG_PC) & ~1
    reason = "FAULT" if error else ("RETURN" if pc == SENTINEL & ~1 else "BUDGET_EXHAUSTED")
    return {"r0": emu.reg_read(UC_ARM_REG_R0), "instructions": trace.instructions,
            "writes": list(trace.writes), "mmio": list(trace.mmio),
            "stopped": reason, "pc": pc, "error": error,
            "sp": emu.reg_read(UC_ARM_REG_SP),
            "callee_saved_preserved": all(emu.reg_read(r) == v for r,v in saved.items()),
            "unique_addresses": sorted(trace.addresses),
            "edges": sorted(trace.edges)}
