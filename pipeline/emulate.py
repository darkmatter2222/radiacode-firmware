"""Unicorn-based execution of the original image, for differential testing (layer L4).

The whole flat image is mapped at its real address, SRAM and the peripheral blocks the firmware
touches are mapped as plain RAM, and every access outside the image is recorded.  A function is
entered with the Thumb ABI (r0..r3 = arguments, LR = a sentinel address) and the run stops when the
sentinel is reached, i.e. when the function returns.  Nothing here needs the device.
"""

from unicorn import (
    Uc,
    UC_ARCH_ARM,
    UC_MODE_ARM,
    UC_PROT_ALL,
    UC_HOOK_CODE,
    UC_HOOK_MEM_READ_UNMAPPED,
    UC_HOOK_MEM_WRITE_UNMAPPED,
    UC_HOOK_MEM_FETCH_UNMAPPED,
)
from unicorn.arm_const import (
    UC_ARM_REG_R0,
    UC_ARM_REG_R1,
    UC_ARM_REG_R2,
    UC_ARM_REG_R3,
    UC_ARM_REG_R12,
    UC_ARM_REG_LR,
    UC_ARM_REG_SP,
    UC_ARM_REG_PC,
)

FLASH_BASE = 0x08000000
FLASH_SIZE = 0x00080000
SRAM_BASE = 0x20000000
SRAM_SIZE = 0x00008000
STACK_TOP = 0x20007F00
# the native side uses real stack slots that a Python model has no reason to touch
STACK_RANGE = (0x20007000, 0x20008000)
SENTINEL = 0x0A0A0001
# (base, size) pairs; Unicorn rounds each block up to the next power-of-two boundary, so one
# 64K block at 0x1FFF0000 also covers the VSFR/DEV_ID area at 0x1FFF7000+.  Anything else falls
# through to the unmapped-access hooks below.
REGIONS = [
    (0x0A0A0000, 0x1000),
    (0x1FFF0000, 0x10000),
    (0x40000000, 0x20000),
    (0x48000000, 0x10000),
    (0xE000E000, 0x1000),
]


class Trace:
    """Ordered record of memory and MMIO effects, plus the instruction count."""

    def __init__(self):
        self.writes = []
        self.reads = []
        self.instructions = 0

    def final_writes(self):
        last = {}
        for addr, size, value in self.writes:
            last[addr] = (size, value)
        return last


def new_emulator(flash):
    """Map the image and the RAM regions, and return (emu, trace)."""
    emu = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    trace = Trace()
    emu.mem_map(FLASH_BASE, FLASH_SIZE, UC_PROT_ALL)
    emu.mem_write(FLASH_BASE, bytes(flash))
    emu.mem_map(SRAM_BASE, SRAM_SIZE, UC_PROT_ALL)
    for base, size in REGIONS:
        emu.mem_map(base, size, UC_PROT_ALL)

    def on_code(emu, address, size, user):
        trace.instructions += 1
        if address == SENTINEL & 0xFFFFFFFE:
            emu.emu_stop()

    def on_read_unmapped(emu, access, address, size, value, user):
        trace.reads.append((address, size, 0))
        return True  # handled: the value reads back as zero

    def on_write_unmapped(emu, access, address, size, value, user):
        trace.writes.append((address, size, value))
        return True

    def on_fetch_unmapped(emu, access, address, size, value, user):
        trace.reads.append((address, size, 0))
        return True

    def on_write(emu, access, address, size, value, user):
        trace.writes.append((address, size, value))

    def on_read(emu, access, address, size, value, user):
        trace.reads.append((address, size, value))

    from unicorn import UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE

    emu.hook_add(UC_HOOK_CODE, on_code)
    emu.hook_add(UC_HOOK_MEM_READ, on_read)
    emu.hook_add(UC_HOOK_MEM_WRITE, on_write)
    emu.hook_add(UC_HOOK_MEM_READ_UNMAPPED, on_read_unmapped)
    emu.hook_add(UC_HOOK_MEM_WRITE_UNMAPPED, on_write_unmapped)
    emu.hook_add(UC_HOOK_MEM_FETCH_UNMAPPED, on_fetch_unmapped)
    emu.mem_write(SENTINEL & 0xFFFFFFFE, b"\x00\xbe")  # bkpt #0, only reached via the hook
    return emu, trace


def preset(emu, pairs):
    """Apply (address, bytes) pairs."""
    for address, value in pairs:
        emu.mem_write(address, bytes(value))


def read_word(emu, address):
    return int.from_bytes(emu.mem_read(address, 4), "little")


def run_function(emu, trace, address, args=(0, 0, 0, 0), cycles=200000):
    """Execute one Thumb function; -> dict with the return value, effects and stop reason."""
    emu.reg_write(UC_ARM_REG_SP, STACK_TOP)
    emu.reg_write(UC_ARM_REG_LR, SENTINEL)
    for reg, value in zip((UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3), args):
        emu.reg_write(reg, value & M32_MASK)
    emu.reg_write(UC_ARM_REG_R12, 0)
    trace.writes.clear()
    trace.reads.clear()
    trace.instructions = 0
    stopped = True
    try:
        emu.emu_start(address | 1, SENTINEL & 0xFFFFFFFE, 0, cycles)
    except Exception as error:  # unicorn raises UcError; keep the reason for the report
        stopped = "reached sentinel" if _at_sentinel(emu) else "error: %s" % error
    if stopped is True:
        stopped = "reached sentinel"
    return {
        "r0": emu.reg_read(UC_ARM_REG_R0),
        "instructions": trace.instructions,
        "writes": dict((a, (s, v)) for a, s, v in trace.writes),
        "stopped": stopped,
    }


def _at_sentinel(emu):
    try:
        return (emu.reg_read(UC_ARM_REG_PC) & 0xFFFFFFFE) == (SENTINEL & 0xFFFFFFFE)
    except Exception:
        return False


M32_MASK = 0xFFFFFFFF
