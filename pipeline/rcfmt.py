"""Phyton/RadiaCode firmware file format: decode, decrypt, decompress.

Implements the reverse-engineered format documented at
https://github.com/WeebDataHoarder/PhytonUtils (doc/*.md).
"""

import struct

# ---------------------------------------------------------------- Mangle cipher

HARDCODED_KEY_TABLE = [
    (0x0539C06F, 0x3A235801, 0x1BB4DA80, 0x44916A65),  # 0 flash (outer)
    (0x5B01CB35, 0xB498A4FB, 0xE9486D82, 0xF4945010),  # 1 device id (outer)
    (0xE8BABCEC, 0x2AA73DF8, 0x4CF9F79C, 0x886D73E7),  # 2
    (0x25483503, 0xB1A0A8AF, 0x24A745B2, 0xF5E21339),  # 3
    (0x42D89088, 0x37A379AF, 0x422689E0, 0x636239E9),  # 4
    (0xABD061F0, 0x7F710579, 0xBD626B51, 0x2AF22C15),  # 5
    (0xB341BC06, 0x6E6E4674, 0xB3EB7B01, 0xF1965B32),  # 6 memory (outer)
    (0x52F33E6F, 0x4D69A2F9, 0x77AB77C4, 0x468F4508),  # 7
]
ALTERNATE_KEY_TABLE = [(0, 0, 0, 0)] * 8

M32 = 0xFFFFFFFF
ROUNDS = 48


def _enc_step(key, a, b, rnd):
    """One forward round: (A, B) -> (B, r + key + ((B>>8)^(B<<6)) + B + A)."""
    mixed = ((b >> 8) ^ ((b << 6) & M32)) & M32
    new_a = b
    new_b = (rnd + key + mixed + b + a) & M32
    return new_a, new_b


def _dec_step(key, a, b, rnd):
    """Inverse of _enc_step."""
    mixed = ((a >> 8) ^ ((a << 6) & M32)) & M32
    new_a = ((b - a) - mixed - key - rnd) & M32
    new_b = a
    return new_a, new_b


def mangle_encrypt_key(key, data):
    return _mangle(data, key, encrypt=True)


def mangle_decrypt_key(key, data):
    return _mangle(data, key, encrypt=False)


def _mangle(data, key, encrypt):
    if isinstance(key, (bytes, bytearray)):
        key = struct.unpack("<4I", bytes(key[:16]))
    out = bytearray(data)
    for i in range(0, len(out) - 7, 8):
        block = struct.unpack_from("<Q", out, i)[0]
        if encrypt:
            block = _enc_block(key, block)
        else:
            block = _dec_block(key, block)
        struct.pack_into("<Q", out, i, block)
    return bytes(out)


def _enc_block(key, block):
    a, b = block & M32, (block >> 32) & M32
    for rnd in range(ROUNDS):
        a, b = _enc_step(key[rnd & 3], a, b, rnd)
    return (a & M32) | ((b & M32) << 32)


def _dec_block(key, block):
    a, b = block & M32, (block >> 32) & M32
    for rnd in range(ROUNDS - 1, -1, -1):
        a, b = _dec_step(key[rnd & 3], a, b, rnd)
    return (a & M32) | ((b & M32) << 32)


def device_mangle_key(device_id, offset=1):
    """Device-specific key (PhytonUtils DeviceMangleKeyOffset{1,0} helpers)."""
    outer = HARDCODED_KEY_TABLE[offset]
    if offset == 1:
        return (device_id[0] ^ outer[0], device_id[1] ^ outer[1], device_id[2] ^ outer[2], outer[3])
    return (
        device_id[0] ^ outer[0],
        device_id[1] ^ outer[1],
        device_id[2] ^ outer[2],
        (device_id[0] ^ 0xFFFFFFFF) ^ outer[3],
    )


# ---------------------------------------------------------------- CRC (MPEG-2 style, custom)

CRC_POLY = 0x04C11DB7


def _build_table():
    table = []
    for i in range(256):
        value = i
        for _ in range(32):
            bit_out = value >> 31
            value = (value << 1) & M32
            if bit_out:
                value ^= CRC_POLY
        table.append(value & M32)
    return tuple(table)


CRC_TABLE = _build_table()


def calculate_crc(data):
    crc = 0xFFFFFFFF
    n = len(data) // 4 * 4
    for i in range(0, n, 4):
        chunk = data[i] | (data[i + 1] << 8) | (data[i + 2] << 16) | (data[i + 3] << 24)
        crc = CRC_TABLE[((chunk >> 24) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc = CRC_TABLE[((chunk >> 16) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc = CRC_TABLE[((chunk >> 8) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc = CRC_TABLE[((chunk) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc &= M32
    rem = len(data) % 4
    if rem:
        tail = bytearray(4)
        tail[:rem] = data[n:]
        chunk = tail[0] | (tail[1] << 8) | (tail[2] << 16) | (tail[3] << 24)
        crc = CRC_TABLE[((chunk >> 24) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc = CRC_TABLE[((chunk >> 16) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc = CRC_TABLE[((chunk >> 8) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc = CRC_TABLE[((chunk) ^ (crc >> 24)) & 0xFF] ^ ((crc << 8) & M32)
        crc &= M32
    return crc


# ---------------------------------------------------------------- Borland LCG (memory dumps)

def borland_next(seed):
    return (seed * 0x015A4E35 + 1) & M32


def borland_xor(data, seed):
    # keystream byte = (seed >> 16) & 0xFF - the 8-bit form the unit actually uses: decoding the
    # live 0x081C area 1 with it yields clean ASCII (`analysis/capture.json`), the 7-bit form
    # mangles 214 of its 448 bytes.
    out = bytearray(data)
    for i in range(len(out)):
        seed = borland_next(seed)
        out[i] ^= (seed >> 16) & 0xFF
    return bytes(out), seed


# ---------------------------------------------------------------- LZSS decompression

DATA_MAX_SIZE = 0x8000
OFFSET_BITS = 11
LENGTH_BITS = 4
WINDOW_SIZE = 1 << OFFSET_BITS
MAX_UNCODED = 2
MAX_CODED = MAX_UNCODED + (1 << LENGTH_BITS)
WINDOW_INITIAL_INDEX = WINDOW_SIZE - 0x10 - 1
WINDOW_FILL = 0x20


def lzss_decompress(data):
    window = bytearray([WINDOW_FILL]) * WINDOW_SIZE
    window_index = WINDOW_INITIAL_INDEX
    out = bytearray()

    bit_pos = 0
    total_bits = len(data) * 8

    def read_bits(count):
        nonlocal bit_pos
        value = 0
        for _ in range(count):
            if bit_pos >= total_bits:
                return None
            byte = data[bit_pos >> 3]
            bit = (byte >> (7 - (bit_pos & 7))) & 1
            bit_pos += 1
            value = (value << 1) | bit
        return value

    while True:
        flag = read_bits(1)
        if flag is None:
            break
        if flag:
            literal = read_bits(8)
            if literal is None:
                break
            out.append(literal)
            window[window_index & (WINDOW_SIZE - 1)] = literal
            window_index = (window_index + 1) & (WINDOW_SIZE - 1)
        else:
            offset_index = read_bits(OFFSET_BITS)
            length = read_bits(LENGTH_BITS)
            if offset_index is None or length is None:
                break
            length += MAX_UNCODED
            if length + len(out) > DATA_MAX_SIZE:
                raise ValueError("out of bounds output")
            for j in range(length):
                byte = window[(offset_index + j) & (WINDOW_SIZE - 1)]
                out.append(byte)
                window[(window_index + j) & (WINDOW_SIZE - 1)] = byte
            window_index = (window_index + length) & (WINDOW_SIZE - 1)
    return bytes(out)


# ---------------------------------------------------------------- file layout

KEY_BLOCK_SIZE = 512
BLOCK_HEADER_SIZE_KEY = 0xCE27A932
BLOCK_HEADER_ADDR_KEY = 0xB2D5A864
BASE_ADDRESS = 0x08000000


def align_size(size):
    if size % 8:
        size = (size & 0xFFFFFFF8) + 8
    return size


def parse_file(data):
    """Return (header_dict, [block dicts]) for a Phyton/AlmaCode firmware file."""
    marker = data[:8]
    if marker not in (b"Phyton\x00\x00", b"AlmaCode"):
        raise ValueError(f"bad marker {marker!r}")
    header_size = struct.unpack_from("<I", data, 8)[0]
    pos = 12
    date_time = struct.unpack_from("<I", data, pos)[0]
    pos += 4
    buffer_size = struct.unpack_from("<I", data, pos)[0]
    pos += 4
    serial = data[pos : pos + 16]
    pos += 16
    version_low, version_high = data[pos], data[pos + 1]
    pos += 2
    file_count = struct.unpack_from("<I", data, pos)[0]
    pos += 4
    firmware_header_size = struct.unpack_from("<I", data, pos)[0]
    pos += 4
    compressed = data[pos] if pos < len(data) else 0
    reserved = data[pos + 1] if pos + 1 < len(data) else 0
    crc32 = struct.unpack_from("<I", data, pos + 2)[0] if pos + 6 <= len(data) else None
    header = {
        "marker": marker.decode("latin-1").rstrip("\x00"),
        "header_size": header_size,
        "date_time": date_time,
        "date": _decode_datetime(date_time),
        "buffer_size": buffer_size,
        "serial": serial.hex(),
        "version": f"{version_high}.{version_low:02d}",
        "version_low": version_low,
        "version_high": version_high,
        "compressed": compressed,
        "reserved": reserved,
        "header_crc32": None if crc32 is None else f"{crc32:08x}",
        "file_count": file_count,
        "firmware_header_size": firmware_header_size,
    }
    return header


def _decode_datetime(dt):
    high = (dt >> 16) & 0xFFFF
    low = dt & 0xFFFF
    year = ((high >> 9) & 127) + 1980
    month = (high >> 5) & 15
    day = high & 31
    hours = (low >> 11) & 31
    minutes = (low >> 5) & 63
    seconds = (low & 31) * 2
    return f"{year:04d}-{month:02d}-{day:02d} {hours:02d}:{minutes:02d}:{seconds:02d}"


def iter_blocks(data, start):
    buf = memoryview(data)[start:]
    pos = 0
    blocks = []
    while pos < len(buf):
        header_size, size_enc, addr_enc = struct.unpack_from("<III", buf, pos)
        size = size_enc ^ BLOCK_HEADER_SIZE_KEY
        addr = addr_enc ^ BLOCK_HEADER_ADDR_KEY
        aligned = align_size(size)
        block_start = pos + 12
        block = bytes(buf[block_start : block_start + KEY_BLOCK_SIZE + aligned])
        blocks.append(
            {
                "header_size": header_size,
                "size": size,
                "addr": addr,
                "aligned": aligned,
                "raw": block,
            }
        )
        pos = block_start + KEY_BLOCK_SIZE + aligned
    return blocks


def decrypt_block(raw, size, compressed, outer_offset=0, device_key=None):
    """Decrypt one firmware block; returns plaintext (possibly LZSS-compressed)."""
    key_block = bytearray(raw[:KEY_BLOCK_SIZE])
    data_block = bytearray(raw[KEY_BLOCK_SIZE:])

    # outer unmangle of the whole key block
    key_block = bytearray(mangle_decrypt_key(HARDCODED_KEY_TABLE[outer_offset], bytes(key_block)))
    mangle_index = struct.unpack_from("<H", key_block, 0)[0]

    if mangle_index <= 7:
        inner = HARDCODED_KEY_TABLE[mangle_index]
    elif 8 <= mangle_index <= 15:
        inner = ALTERNATE_KEY_TABLE[mangle_index - 8]
    elif mangle_index == 0xFFFF:
        if device_key is None:
            raise ValueError("device-key block encountered without a device id")
        inner = device_key
    else:
        raise ValueError(f"invalid mangle index {mangle_index}")

    # inner unmangle of key + crc region (bytes 2 .. 26)
    key_block[2:26] = mangle_decrypt_key(inner, bytes(key_block[2:26]))

    # the true per-block data key only exists after the inner unmangle
    inner_key = tuple(struct.unpack_from("<4I", key_block, 2))
    crc1, crc2 = struct.unpack_from("<II", key_block, 2 + 16)

    plain = mangle_decrypt_key(inner_key, bytes(data_block))
    if crc1 != crc2:
        raise ValueError(f"CRC pair mismatch {crc1:08X} != {crc2:08X}")
    if compressed:
        return plain[:size], crc1
    return plain[:size], crc1


def build_flash_image(data, device_key=None, verbose=False):
    """Decode a firmware file into a flat flash image (base 0x08000000)."""
    header = parse_file(data)
    start = header["header_size"]
    compressed = header["compressed"] > 0
    blocks = iter_blocks(data, start)
    image = bytearray()
    for index, block in enumerate(blocks):
        plain, crc1 = decrypt_block(block["raw"], block["size"], compressed, 0, device_key)
        if compressed:
            plain = lzss_decompress(plain)
        crc_ok = calculate_crc(plain) == crc1
        offset = block["addr"] - BASE_ADDRESS
        if offset < 0:
            raise ValueError(f"block {index} below base address: {block['addr']:#x}")
        end = offset + len(plain)
        if len(image) < end:
            image.extend(bytes(end - len(image)))
        image[offset:end] = plain
        if verbose:
            print(
                f"block {index:3d} addr={block['addr']:#010x} size={block['size']:#06x} "
                f"aligned={block['aligned']:#06x} crc={crc1:08x} ok={crc_ok}"
            )
    return header, blocks, bytes(image)


# ---------------------------------------------------------------- encoding (inverse primitives)


def lzss_compress(data, tie="nearest"):
    """Greedy LZSS encoder for the bit stream read by `lzss_decompress`.

    Same 2048-byte window, same initial fill (`WINDOW_FILL`) and initial index, same token layout
    (one flag bit, then 8 literal bits or an 11-bit window position plus 4 length bits), MSB-first.
    The window slot of output index k is `(WINDOW_INITIAL_INDEX + k) % 2048`; slots not written yet
    hold the fill byte, exactly as the decoder sees them.  Candidates are walked through a
    two-byte-prefix hash chain (the minimum coded match is two bytes long).
    """
    total = len(data)
    mask = WINDOW_SIZE - 1
    longest = MAX_UNCODED + (1 << LENGTH_BITS) - 1  # 4 length bits -> 2..17
    head = [-1] * 0x10000
    chain = [-1] * WINDOW_SIZE
    out = bytearray()
    bit_buf = 0
    bit_count = 0

    def emit(value, count):
        nonlocal bit_buf, bit_count
        for shift in range(count - 1, -1, -1):
            bit_buf = (bit_buf << 1) | ((value >> shift) & 1)
            bit_count += 1
            if bit_count == 8:
                out.append(bit_buf)
                bit_buf = 0
                bit_count = 0

    def run_length(dist, limit, pos):
        """Bytes a reference `dist` back reproduces (the ring buffer makes it periodic)."""
        length = 0
        while length < limit:
            index = pos - dist + length
            value = data[index] if index >= 0 else WINDOW_FILL
            if value != data[pos + length]:
                break
            length += 1
        return length

    def insert(index):
        if index + 1 >= total:
            return
        hash_value = (data[index] << 8) | data[index + 1]
        slot = (WINDOW_INITIAL_INDEX + index) & mask
        chain[slot] = head[hash_value]
        head[hash_value] = index

    pos = 0
    while pos < total:
        limit = min(longest, total - pos)
        best_len = 0
        best_dist = 0
        if limit >= 2 and pos:
            index = head[(data[pos] << 8) | data[pos + 1]] if pos + 1 < total else -1
            while index != -1:
                dist = pos - index
                if dist <= 0 or dist > WINDOW_SIZE:
                    break
                length = run_length(dist, limit, pos)
                if length > best_len or (length == best_len and tie == "farthest" and dist > best_dist):
                    best_len, best_dist = length, dist
                if best_len == limit:
                    break
                index = chain[(WINDOW_INITIAL_INDEX + index) & mask]
        if best_len >= MAX_UNCODED:
            emit(0, 1)
            emit((WINDOW_INITIAL_INDEX + pos - best_dist) & mask, OFFSET_BITS)
            emit(best_len - MAX_UNCODED, LENGTH_BITS)
            for offset in range(best_len):
                insert(pos + offset)
            pos += best_len
        else:
            emit(1, 1)
            emit(data[pos], 8)
            insert(pos)
            pos += 1
    if bit_count:
        out.append((bit_buf << (8 - bit_count)) & 0xFF)
    return bytes(out)


def encode_key_block(mangle_index, inner_key, data_key, crc_pair, tail, outer_key=None):
    """Rebuild the 512-byte key block: outer mangle over (index | inner-mangled key+crc | tail)."""
    if len(tail) != KEY_BLOCK_SIZE - 26:
        raise ValueError("key block tail must be %d bytes" % (KEY_BLOCK_SIZE - 26))
    plain = bytearray(KEY_BLOCK_SIZE)
    struct.pack_into("<H", plain, 0, mangle_index)
    inner_plain = struct.pack("<4I", *data_key) + struct.pack("<II", *crc_pair)
    plain[2:26] = mangle_encrypt_key(inner_key, inner_plain)
    plain[26:] = tail
    outer = HARDCODED_KEY_TABLE[0] if outer_key is None else outer_key
    return mangle_encrypt_key(outer, bytes(plain))


def encode_block(mangle_index, inner_key, data_key, crc_pair, tail, addr, payload, compressed):
    """Rebuild one block (12-byte header + 512-byte key block + aligned data block)."""
    stream = lzss_compress(bytes(payload)) if compressed else bytes(payload)
    size = len(stream)
    aligned = align_size(size)
    data_block = mangle_encrypt_key(data_key, stream + bytes(aligned - size))
    header = struct.pack(
        "<III",
        12,
        (size ^ BLOCK_HEADER_SIZE_KEY) & M32,
        (addr ^ BLOCK_HEADER_ADDR_KEY) & M32,
    )
    return header + encode_key_block(mangle_index, inner_key, data_key, crc_pair, tail) + data_block, size


def encode_header(header, body):
    """Rebuild the 52-byte file header; the trailing CRC covers everything after it."""
    marker = b"Phyton\x00\x00" if header["marker"] == "Phyton" else b"AlmaCode"
    serial = bytes.fromhex(header["serial"])
    out = bytearray(header["header_size"])
    out[0 : len(marker)] = marker
    struct.pack_into("<I", out, 8, header["header_size"])
    struct.pack_into("<I", out, 12, header["date_time"])
    struct.pack_into("<I", out, 16, header["buffer_size"])
    out[20 : 20 + len(serial)] = serial
    out[36] = header["version_low"]
    out[37] = header["version_high"]
    struct.pack_into("<I", out, 38, header["file_count"])
    struct.pack_into("<I", out, 42, header["firmware_header_size"])
    out[46] = header["compressed"]
    out[47] = header["reserved"]
    struct.pack_into("<I", out, 48, calculate_crc(body))
    return bytes(out) + body


def split_key_block(raw):
    """Decrypt one block's key area -> (mangle_index, inner_key, data_key, crc_pair, tail)."""
    key_block = bytearray(mangle_decrypt_key(HARDCODED_KEY_TABLE[0], bytes(raw[:KEY_BLOCK_SIZE])))
    mangle_index = struct.unpack_from("<H", key_block, 0)[0]
    if mangle_index <= 7:
        inner_key = HARDCODED_KEY_TABLE[mangle_index]
    elif 8 <= mangle_index <= 15:
        inner_key = ALTERNATE_KEY_TABLE[mangle_index - 8]
    else:
        inner_key = None
    if inner_key is not None:
        key_block[2:26] = mangle_decrypt_key(inner_key, bytes(key_block[2:26]))
    data_key = tuple(struct.unpack_from("<4I", key_block, 2)) if inner_key else None
    crc_pair = struct.unpack_from("<II", key_block, 18)
    return mangle_index, inner_key, data_key, crc_pair, bytes(key_block[26:])


def reencode_file(data, recompress=True):
    """Rebuild a whole container from the decoded model; -> (bytes, per-layer evidence dict).

    `recompress` re-runs `lzss_compress` on every payload (a real round trip through both models);
    with False the stored stream is carried through, which isolates the crypto/layout layer.
    """
    header = parse_file(data)
    blocks = iter_blocks(data, header["header_size"])
    body = bytearray()
    detail = []
    for block in blocks:
        raw = block["raw"]
        mangle_index, inner_key, data_key, crc_pair, tail = split_key_block(raw)
        data_block = bytes(raw[KEY_BLOCK_SIZE:])
        stream = mangle_decrypt_key(data_key, data_block) if inner_key else data_block
        payload = lzss_decompress(stream[: block["size"]]) if header["compressed"] else stream
        expected = struct.pack(
            "<III",
            12,
            (block["size"] ^ BLOCK_HEADER_SIZE_KEY) & M32,
            (block["addr"] ^ BLOCK_HEADER_ADDR_KEY) & M32,
        ) + raw
        if recompress and inner_key is not None:
            rebuilt, size = encode_block(
                mangle_index, inner_key, data_key, crc_pair, tail, block["addr"], payload,
                header["compressed"] > 0,
            )
        else:
            rebuilt, size = expected, block["size"]
        detail.append(
            {
                "addr": "0x%08X" % block["addr"],
                "size": block["size"],
                "rebuilt_size": size,
                "size_match": size == block["size"],
                "key_block_match": rebuilt[12:524] == raw[:512],
                "data_block_match": rebuilt[524:] == data_block,
                "block_match": rebuilt == expected,
                "payload_len": len(payload),
            }
        )
        body += rebuilt
    rebuilt = encode_header(header, bytes(body))
    return rebuilt, {
        "header_match": rebuilt[: header["header_size"]] == data[: header["header_size"]],
        "header_crc32_match": (
            header["header_crc32"] == "%08x" % calculate_crc(bytes(data[header["header_size"]:]))
        ),
        "blocks": detail,
    }
