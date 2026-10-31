"""RadiaCode-102 wire protocol: command ids, framing, record decoders.

All ids/decoders here were confirmed against a live unit (`RC-102-008228`, FW 4.14) and against the
decompiled image; the two independent sources agree on every field decoded so far.

Command names in CAPS come from the vendor SDK string table inside `official/apk.bin`
(`classes.dex`, package `ru.almacode.vk.corelib`).  `VS <n>` string names follow the community
`radiacode` Python library.  Items marked (inferred) are read from structure, not from a name.
"""

import struct

# ---------------------------------------------------------------- transport

SERVICE_UUID = "e63215e5-7003-49d8-96b0-b024798fb901"
WRITE_UUID = "e63215e6-7003-49d8-96b0-b024798fb901"
NOTIFY_UUID = "e63215e7-7003-49d8-96b0-b024798fb901"
CHUNK = 18              # host writes are chopped into 18-byte GATT writes
SEQ_BASE = 0x80         # seq = 0x80 + (counter % 32)
SIGN = b"\x01\xff\x12\xff"   # SET_EXCHANGE argument, word 0xFF12FF01 @ 0x08027DA0

# ---------------------------------------------------------------- command ids

CMD = {
    0x0005: "GET_STATUS",
    0x0007: "SET_EXCHANGE",
    0x000A: "GET_VERSION",
    0x000B: "GET_SERIAL",
    0x0012: "FW_IMAGE_GET_INFO",
    0x0013: "FW_IMAGE_UPDATE",          # opens the staging session; replies with the id itself
    0x0014: "FW_IMAGE_WRITE",           # (inferred) chunked writer, answers only during a session
    0x0101: "RD_SIGNAT",                # image descriptor: date_time + file name + product
    0x0807: "RD_HW_CONFIG",
    0x081C: "RD_FLASH_AREA",
    0x0824: "RD_VIRT_SFR",
    0x0825: "WR_VIRT_SFR",
    0x0826: "RD_VIRT_STRING",
    0x0827: "WR_VIRT_STRING",
    0x082A: "RD_VIRT_SFR_BATCH",
    0x082B: "WR_VIRT_SFR_BATCH",
    0x0A04: "SET_LOCAL_TIME",
}

# ids that answered during a full 0x0000-0x0FFF sweep, with and without a u32 argument
ANSWERING = (0x0005, 0x0007, 0x000A, 0x000B, 0x0012, 0x0013, 0x0101, 0x0807, 0x081C,
             0x0824, 0x0826, 0x082A, 0x0A04)

# ---------------------------------------------------------------- virtual strings

VS = {
    0x002: "CONFIGURATION",     # [DeviceParams] + [DataStructure] text, 3256 B
    0x003: "FW_DESCRIPTOR",     # 8 B header
    0x008: "SERIAL_NUMBER",     # "RC-102-008228"
    0x00D: "COUNTERS",          # 8 B
    0x00F: "EVENT_LOG",         # "<ms>, <text>" lines, ring buffer
    0x0F0: "DEVICE_INFO",       # 76 B capability/descriptor record
    0x100: "DATA_BUF",          # real-time record stream (grows with uptime)
    0x101: "SFR_FILE",
    0x200: "SPECTRUM",          # header + channel->keV calibration
    0x202: "ENERGY_CALIB",      # 12 B = float A0, A1, A2
    0x203: "DEVICE_INFO_2",     # same 76 B record as 0x0F0
    0x205: "SPEC_ACCUM",
    0x206: "ACCUM_A",
    0x207: "ACCUM_B",
    0x208: "POWERS_OF_TWO",     # 104 B descending power-of-two table
    0x220: "LIVE_WINDOW",       # {counts, ms, us} accumulation window
}

# channel ids from [DataStructure] (numbered register space, 0x00-0x5A)
CHANNELS = {
    0: "CHN_Flags", 2: "CHN_Count", 3: "CHN_CountRate", 4: "CHN_DoseRate",
    5: "CHN_DoseRateErr", 6: "CHN_Duration", 7: "CHN_Dose", 8: "CHN_Temperature",
    9: "CHN_ChargeLevel", 14: "CHN_Event", 15: "CHN_EventChnMsk",
    16: "CHN_CountRateErr", 17: "CHN_RealTimeFlags", 22: "CHN_DoseCounter",
}

# ---------------------------------------------------------------- frame codec


def encode(command, args=b"", seq=0):
    """One wire frame: u32 LE length | cmd u16 LE | 0x00 | seq | args."""
    request = struct.pack("<HBB", int(command), 0, (SEQ_BASE + seq) % 0x100) + bytes(args)
    return struct.pack("<I", len(request)) + request


def chunks(frame, size=CHUNK):
    return [frame[i:i + size] for i in range(0, len(frame), size)]


def split(payload):
    """Split a reply payload (header already removed) into (version, size, data)."""
    if len(payload) < 8:
        return None, None, b""
    version, size = struct.unpack_from("<II", payload, 0)
    return version, size, payload[8:8 + size]


# ---------------------------------------------------------------- small codecs


def borland_next(seed):
    return (seed * 0x015A4E35 + 1) & 0xFFFFFFFF


def borland_xor(data, seed):
    """XOR stream used by RD_FLASH_AREA: keystream = (seed >> 16) & 0x7FFF per byte."""
    out = bytearray(len(data))
    for i, b in enumerate(data):
        seed = borland_next(seed)
        out[i] = b ^ ((seed >> 16) & 0x7FFF) & 0xFF
    return bytes(out), seed


def decode_flash_area(payload):
    """RD_FLASH_AREA reply: {u32 status, u32 seed, u32 enc_size, u8[enc_size] enc}."""
    if len(payload) < 12:
        return {"status": struct.unpack_from("<I", payload, 0)[0] if payload else None}
    status, seed, enc_size = struct.unpack_from("<III", payload, 0)
    if status != 0:
        return {"status": status}
    size, seed2 = borland_xor(struct.pack("<I", enc_size), seed)
    size = struct.unpack("<I", size)[0]
    data, _ = borland_xor(payload[12:12 + size], seed2)
    rec = {"status": status, "seed": f"0x{seed:08X}", "size": size, "hex": data.hex()}
    text = data.split(b"\x00")[0]
    if text and all(32 <= b < 127 for b in text):
        rec["text"] = text.decode()
    return rec


def decode_versions(payload):
    """GET_VERSION array: {u16 id, u16 version, u8 len, char[len] (NUL inside)}*."""
    out, pos = [], 0
    while pos + 5 <= len(payload):
        vid, ver, ln = struct.unpack_from("<HHB", payload, pos)
        if ln == 0 or pos + 5 + ln > len(payload):
            break
        stamp = payload[pos + 5:pos + 5 + ln].split(b"\x00")[0].decode("ascii", "replace")
        out.append({"id": vid, "version": ver, "stamp": stamp})
        pos += 5 + ln
    return out


def decode_image_info(payload):
    """FW_IMAGE_GET_INFO: {u32 size, u32 buffer_size, u32 date_time, u32 crc32}."""
    size, buffer_size, date_time, crc = struct.unpack_from("<IIII", payload, 0)
    return {"size": size, "buffer_size": buffer_size, "date_time": f"0x{date_time:08X}",
            "crc32": f"0x{crc:08X}"}


def decode_signature(payload):
    """RD_SIGNAT: {u32 date_time, u8 len, name[len], u8 len, product[len], u8, u8}."""
    date_time = struct.unpack_from("<I", payload, 0)[0]
    pos, fields = 4, []
    while pos < len(payload):
        ln = payload[pos]
        if pos + 1 + ln <= len(payload) and payload[pos + 1] >= 32 and ln and all(
                32 <= b < 127 for b in payload[pos + 1:pos + 1 + ln]):
            fields.append(payload[pos + 1:pos + 1 + ln].decode("ascii"))
            pos += 1 + ln
        else:
            fields.append(payload[pos:].hex())
            break
    return {"date_time": f"0x{date_time:08X}", "fields": fields}


def decode_calib(payload):
    """ENERGY_CALIB / spectrum tail: three IEEE-754 coefficients channel -> keV."""
    a0, a1, a2 = struct.unpack_from("<fff", payload, 0)
    return {"A0": a0, "A1": a1, "A2": a2,
            "keV_at_channel": [round(a0 + a1 * ch + a2 * ch * ch, 3) for ch in (0, 1, 100, 512, 1023)]}


def serial_from_address(address):
    """`52:43:06:60:20:24` -> `RC-102-008228`: the ASCII prefix plus the last two bytes as decimal."""
    parts = [p for p in address.replace("-", ":").split(":") if p]
    return "RC-102-%06d" % (int(parts[-2], 16) * 256 + int(parts[-1], 16))


def keV(channel, a0, a1, a2):
    return a0 + a1 * channel + a2 * channel * channel
