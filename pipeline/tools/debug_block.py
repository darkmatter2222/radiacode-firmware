"""Debug the Mangle decryption of a known-good test block."""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import re
import struct
import urllib.request

import rcfmt

URL = "https://raw.githubusercontent.com/WeebDataHoarder/PhytonUtils/master/encryption/block_testdata.go"
text = urllib.request.urlopen(URL, timeout=30).read().decode()
arrays = {}
for match in re.finditer("var (sample[A-Za-z0-9_]+) = EncryptedBlock{([^}]*)}", text, re.S):
    values = [int(v, 16) for v in re.findall("0x([0-9A-Fa-f][0-9A-Fa-f])", match.group(2))]
    arrays[match.group(1)] = bytes(values)

raw = arrays["sampleBlockFirmwareUncompressed"]
key_block = bytes(raw[:512])

probe = bytes(range(32))
enc = rcfmt.mangle_encrypt_key(rcfmt.HARDCODED_KEY_TABLE[0], probe)
dec = rcfmt.mangle_decrypt_key(rcfmt.HARDCODED_KEY_TABLE[0], enc)
print("cipher round-trip ok:", dec == probe, "enc:", enc.hex())

outer = rcfmt.mangle_decrypt_key(rcfmt.HARDCODED_KEY_TABLE[0], key_block)
mangle_index = struct.unpack_from("<H", outer, 0)[0]
print("mangle index after outer decrypt:", hex(mangle_index))
print("key bytes 2..18:", outer[2:18].hex())
print("crc1/crc2:", [hex(v) for v in struct.unpack_from("<II", outer, 18)])

if mangle_index <= 15:
    inner = rcfmt.HARDCODED_KEY_TABLE[mangle_index % 8]
    patched = rcfmt.mangle_decrypt_key(inner, outer[2:26])
    print("after inner decrypt key:", patched[:16].hex())
    print("after inner crc pair:", [hex(v) for v in struct.unpack_from("<II", patched, 16)])
