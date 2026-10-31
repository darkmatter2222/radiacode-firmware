"""Independent Python models of recovered firmware routines (input to layers L4 and L5).

Each function model is a hand transcription of one `decompiled.c` block, written against the small
sparse `Mem` below so its result and its memory effects can be compared with the same routine
executed natively by Unicorn (see `emulate.py`).  The native side defines the expected behaviour:
a model that disagrees is reported as a divergence, not silently accepted.

`FORMAT_MODELS` is the container/format layer: pure functions of their arguments, checked against
`rcfmt` by `step15_differential.py` and symbolically by `step16_formal.py`.
"""

M32 = 0xFFFFFFFF


# ------------------------------------------------------------------ sparse memory


class Mem:
    """Byte-addressable memory: flash image read-only, writable overlay for everything else.

    `poke()` applies an initial value without recording it; `write()` is a modelled store and is
    recorded, so the comparison sees exactly what the routine itself changed.
    """

    def __init__(self, flash, base=0x08000000):
        self.flash = flash
        self.base = base
        self.over = {}
        self.dirty = {}

    def _byte(self, addr):
        value = self.over.get(addr)
        if value is not None:
            return value
        offset = addr - self.base
        if 0 <= offset < len(self.flash):
            return self.flash[offset]
        return 0

    def u8(self, addr):
        return self._byte(addr)

    def u16(self, addr):
        return self._byte(addr) | (self._byte(addr + 1) << 8)

    def u32(self, addr):
        return (self._byte(addr) | (self._byte(addr + 1) << 8) | (self._byte(addr + 2) << 16)
                | (self._byte(addr + 3) << 24))

    def poke(self, addr, value, size):
        for i in range(size):
            self.over[addr + i] = (value >> (8 * i)) & 0xFF

    def write(self, addr, value, size):
        for i in range(size):
            byte = (value >> (8 * i)) & 0xFF
            self.over[addr + i] = byte
            self.dirty[addr + i] = byte

    def u8_write(self, addr, value):
        self.write(addr, value, 1)

    def u32_write(self, addr, value):
        self.write(addr, value, 4)

    def snapshot(self):
        return dict(self.dirty)


def signed(value):
    value &= M32
    return value - 0x100000000 if value & 0x80000000 else value


# ------------------------------------------------------------------ function models
# Every model takes (mem, args) where args is (r0, r1, r2, r3) and returns the r0 value.


def model_const(value):
    def run(mem, args):
        return value
    return run


def model_08017eb4(mem, args):
    """FUN_08017eb4: 1 when the transfer state is one of {2,4,6} and head <= tail.

    cVar1 = *(char *)(DAT_08017f28 + 0x11);
    if ((cVar1 == 4 || cVar1 == 2) || cVar1 == 6) { if (u32(+0x50) <= u32(+0x54)) return 1; }
    else if (u32(+0x50) < u32(+0x54)) return 1;
    return 0;
    """
    ptr = mem.u32(0x08017F28)
    state = mem.u8(ptr + 0x11)
    head = signed(mem.u32(ptr + 0x50))
    tail = signed(mem.u32(ptr + 0x54))
    if state in (4, 2, 6):
        return 1 if head <= tail else 0
    return 1 if head < tail else 0


def model_080275c4_502(mem, args):
    """FUN_080275c4, the 0x502 arm: push the byte at *DAT_08027d60 onto the reply cursor.

    uVar8 = (uint)*DAT_08027d60;
    puVar7 = (uint *)param_1[2]; param_1[2] = (int)(puVar7 + 1); *puVar7 = uVar8; return 1;
    """
    cursor_owner = args[0]
    value = mem.u8(mem.u32(0x08027D60))
    cursor = mem.u32(cursor_owner + 8)
    mem.write(cursor_owner + 8, (cursor + 4) & M32, 4)
    mem.write(cursor, value, 4)
    return 1


def model_08028a4c(mem, args):
    """FUN_08028a4c: round a length up to 8, then copy that many words to the out cursor.

    piVar1 = *(int **)(param_1 + 4);  *(param_1 + 4) = piVar1 + 1;
    puVar2 = *(uint **)(param_1 + 4); puVar7 = *piVar1; *(param_1+4) = puVar2 + 1;
    uVar8 = DAT_08028eb4; uVar3 = *puVar2;
    if ((uVar3 & 7) != 0) uVar3 = ((uVar3 >> 3) + 1) * 8;
    ... word-by-word copy from puVar7 into the second cursor ...
    (*(*DAT_08028eb8))(iVar6, iVar5);  return param_4;
    """
    stream = args[0]
    last = args[3]
    ptr = mem.u32(stream + 4)
    mem.write(stream + 4, (ptr + 4) & M32, 4)
    ptr2 = mem.u32(stream + 4)
    source = mem.u32(ptr)
    mem.write(stream + 4, (ptr2 + 4) & M32, 4)
    stamp = mem.u32(0x08028EB4)
    length = mem.u32(ptr2)
    if length & 7:
        length = ((length >> 3) + 1) * 8
    out = mem.u32(stream + 8)
    mem.write(stream + 8, (out + 4) & M32, 4)
    mem.write(out, stamp, 4)
    first = mem.u32(stream + 8)
    second = (first + 0x200) & M32
    mem.write(stream + 8, second, 4)
    for _ in range(length >> 2):
        out = mem.u32(stream + 8)
        word = mem.u32(source)
        mem.write(stream + 8, (out + 4) & M32, 4)
        mem.write(out, word, 4)
        source = (source + 4) & M32
    # `push {r3,r4,r5,r6,r7,lr}` ... the run stops in the tail call at `blx r4` (LR = the sentinel),
    # so the word observed in r0 is that call's first argument: r4 = [stream + 8] as read before
    # the 0x200 adjustment.
    return first & M32


# ------------------------------------------------------------------ format-layer models


def model_crc32_mpeg2(data):
    """STM32 hardware-CRC semantics: 32-bit words, MSB-first, poly 0x04C11DB7, init -1.

    The firmware feeds the CRC block one word at a time (little-endian load, so the byte order
    inside a word is reversed), a partial final word is zero-padded, and the result is used without
    a final XOR.
    """
    crc = M32
    pad = len(data) % 4
    buffer = bytes(data) + (bytes(4 - pad) if pad else b"")
    for i in range(0, len(buffer), 4):
        word = buffer[i] | (buffer[i + 1] << 8) | (buffer[i + 2] << 16) | (buffer[i + 3] << 24)
        for shift in (24, 16, 8, 0):
            index = ((word >> shift) & 0xFF) ^ ((crc >> 24) & 0xFF)
            value = index
            for _ in range(32):
                bit = value >> 31
                value = (value << 1) & M32
                if bit:
                    value ^= 0x04C11DB7
            crc = (value ^ ((crc << 8) & M32)) & M32
    return crc


def logical_right(value, count):
    """Identical unsigned shift for Python words and Z3 bit-vectors."""
    if isinstance(value, int):
        return (value & M32) >> count
    import z3
    return z3.LShR(value, count)


def model_mangle_round(key, a, b, rnd):
    """One forward Mangle round: (A, B) -> (B, r + key + ((B>>8)^(B<<6)) + B + A)."""
    mixed = (logical_right(b, 8) ^ ((b << 6) & M32)) & M32
    return b, (rnd + key + mixed + b + a) & M32


def model_mangle_unround(key, a, b, rnd):
    """Inverse round of `model_mangle_round`."""
    mixed = (logical_right(a, 8) ^ ((a << 6) & M32)) & M32
    return (b - a - mixed - key - rnd) & M32, a


def model_lzss_decode(stream):
    """Token walk of the vendor LZSS stream (same constants as the container decoder)."""
    window = bytearray([0x20]) * 2048
    index = 2031
    out = bytearray()
    state = {"bit": 0}
    total = len(stream) * 8

    def take(count):
        value = 0
        for _ in range(count):
            if state["bit"] >= total:
                return None
            position = state["bit"]
            state["bit"] += 1
            value = (value << 1) | ((stream[position >> 3] >> (7 - (position & 7))) & 1)
        return value

    while True:
        flag = take(1)
        if flag is None:
            break
        if flag:
            literal = take(8)
            if literal is None:
                break
            out.append(literal)
            window[index & 2047] = literal
            index = (index + 1) & 2047
        else:
            offset = take(11)
            length = take(4)
            if offset is None or length is None:
                break
            for step in range(length + 2):
                byte = window[(offset + step) & 2047]
                out.append(byte)
                window[(index + step) & 2047] = byte
            index = (index + length + 2) & 2047
    return bytes(out)


def model_msdos_datetime(packed):
    """Unpack the MS-DOS `date_time` field: high half = y/m/d, low half = h:m:s (2 s units)."""
    high = (packed >> 16) & 0xFFFF
    low = packed & 0xFFFF
    return dict(
        year=((high >> 9) & 127) + 1980,
        month=(high >> 5) & 15,
        day=high & 31,
        hour=(low >> 11) & 31,
        minute=(low >> 5) & 63,
        second=(low & 31) * 2,
    )


def model_borland_lcg(seed, count=1):
    """Borland/Delphi LCG keystream: seed = seed * 0x015A4E35 + 1, byte = (seed >> 16) & 0xFF."""
    out = []
    for _ in range(count):
        seed = (seed * 0x015A4E35 + 1) & M32
        out.append((seed >> 16) & 0xFF)
    return seed, out


# ------------------------------------------------------------------ case table

# (addr, model, args, presets, cycles)  -- presets are (variable_address, offset, value) pairs
# where `variable_address` holds the pointer to the struct the routine works on.
#
# SIGNATURES are the first 16 bytes of each routine as recorded in rc-102/hw1-fw4.14, the build the
# transcriptions were read from.  A case only runs on another target when those bytes still match,
# so a model is never credited against an image it was not read from.

CONST_CASES = [(0x080166CE, 1), (0x08017EF2, 2), (0x08017EF6, 3)]

SIGNATURES = {
    0x080166CE: "012070470000bcff002090500120c00c",
    0x08017EF2: "0220704703207047002070470a490120",
    0x08017EF6: "03207047002070470a49012008740022",
    0x08017EB4: "1c4a507c116d526d04281cbf02280628",
    0x080275C4: "2de9f84f044601254ff4a060091a94b0",
    0x08028A4C: "f8b54168091d4160426851f8045d121d",
}


VALIDATED_IMAGES = {'828a080d4a1eb2f2d19da51c6a14652e0a19d728ed716e994ab461ae7485f8e5', '96c11b9f61b59f67429c379190a2013d6f55cf2a37982beaac820bbd31a2336d', '23c31b7dabc59fe35a698cbd4f690498ded9bbb9f6590f3f2ea72ae5cfd157f6'}

def applies(flash, base, addr):
    """True when the image carries the exact bytes this model was transcribed from."""
    import hashlib
    if hashlib.sha256(flash).hexdigest() not in VALIDATED_IMAGES:
        return False
    signature = SIGNATURES.get(addr)
    if signature is None:
        return False
    offset = addr - base
    return flash[offset : offset + 16].hex() == signature

# One shared table: the signature gate decides per target which models actually apply.
COMMON_CASES = [
        {"name": "const_080166ce", "addr": 0x080166CE, "model": model_const(1), "args": (0, 0, 0, 0)},
        {"name": "const_08017ef2", "addr": 0x08017EF2, "model": model_const(2), "args": (0, 0, 0, 0)},
        {"name": "const_08017ef6", "addr": 0x08017EF6, "model": model_const(3), "args": (0, 0, 0, 0)},
        {"name": "transfer_state_le", "addr": 0x08017EB4, "model": model_08017eb4, "args": (0, 0, 0, 0),
         "preset": [(0x08017F28, 0x11, [4]), (0x08017F28, 0x50, [0x10, 0x00, 0x00, 0x00]),
                    (0x08017F28, 0x54, [0x20, 0x00, 0x00, 0x00])]},
        {"name": "transfer_state_gt", "addr": 0x08017EB4, "model": model_08017eb4, "args": (0, 0, 0, 0),
         "preset": [(0x08017F28, 0x11, [6]), (0x08017F28, 0x50, [0x20, 0x00, 0x00, 0x00]),
                    (0x08017F28, 0x54, [0x10, 0x00, 0x00, 0x00])]},
        {"name": "transfer_state_other", "addr": 0x08017EB4, "model": model_08017eb4, "args": (0, 0, 0, 0),
         "preset": [(0x08017F28, 0x11, [1]), (0x08017F28, 0x50, [0x20, 0x00, 0x00, 0x00]),
                    (0x08017F28, 0x54, [0x10, 0x00, 0x00, 0x00])]},
        {"name": "item_502_push", "addr": 0x080275C4, "model": model_080275c4_502,
         "args": (0x20000400, 0x502, 0, 0), "preset": []},
        {"name": "frame_serialize", "addr": 0x08028A4C, "model": model_08028a4c,
         "args": (0x20000500, 0, 0, 0xA5A5A5A5), "preset": [], "stop_slots": [0x08028EB8]},
]

CASES = {
    "rc-102/hw1-fw4.14": COMMON_CASES,
    "rc-101/fw4.14": COMMON_CASES,
    "rc-103/fw4.14": COMMON_CASES,
    "rc-103g/fw4.14": COMMON_CASES,
    "rc-110/fw4.14": COMMON_CASES,
    "rc-410/fw4.16": COMMON_CASES,
}

# Static layout used by the two cursor cases: the caller-side structs live in SRAM.
STRUCT_PRESETS = {
    # reply-cursor struct used by FUN_080275c4: [0]=buf, [1]=?, [2]=write pointer
    0x20000400: [(0, 0x20000600), (4, 0x20000700), (8, 0x20000600)],
    # stream struct used by FUN_08028a4c: [1]=in cursor, [2]=out cursor
    0x20000500: [(4, 0x20000800), (8, 0x20000900)],
    # words the two cursors point at
    0x20000600: [(0, 0x11223344), (4, 0x55667788)],
    # words the two cursors point at: [1] is the length word (12 -> 16 bytes), [0] the source pointer
    0x20000800: [(0, 0x20000810), (4, 12)],
    0x20000810: [(0, 0xA1A2A3A4), (4, 0xB1B2B3B4), (8, 0xC1C2C3C4), (12, 0xD1D2D3D4)],
    0x20000900: [(0, 0)],
}

FORMAT_MODELS = [
    ("crc32_mpeg2", model_crc32_mpeg2),
    ("mangle_round", model_mangle_round),
    ("mangle_unround", model_mangle_unround),
    ("lzss_decode", model_lzss_decode),
    ("msdos_datetime", model_msdos_datetime),
    ("borland_lcg", model_borland_lcg),
]
