"""Validate the Python implementation against PhytonUtils test vectors."""

import re
import urllib.request

import rcfmt

URL = "https://raw.githubusercontent.com/WeebDataHoarder/PhytonUtils/master/encryption/block_testdata.go"
text = urllib.request.urlopen(URL, timeout=30).read().decode()

arrays = {}
for match in re.finditer("var (sample[A-Za-z0-9_]+) = EncryptedBlock{([^}]*)}", text, re.S):
    body = match.group(2)
    values = [int(v, 16) for v in re.findall("0x([0-9A-Fa-f][0-9A-Fa-f])", body)]
    arrays[match.group(1)] = bytes(values)

print("arrays:", [(k, len(v)) for k, v in arrays.items()])

for name, compressed in (("sampleBlockFirmwareUncompressed", False), ("sampleBlockFirmwareCompressed", True)):
    raw = arrays[name]
    size = len(raw) - rcfmt.KEY_BLOCK_SIZE - (3 if compressed else 0)
    plain, crc1 = rcfmt.decrypt_block(raw, size, compressed, outer_offset=0)
    if compressed:
        plain = rcfmt.lzss_decompress(plain)
    print(
        f"{name}: len={len(plain)} crc={crc1:08x} "
        f"crc_ok={rcfmt.calculate_crc(plain) == crc1} head={plain[:32].hex()}"
    )
