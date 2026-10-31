"""Diff the in-image vendor configuration text against the live device's VS CONFIGURATION."""

import json

payload = json.load(open("firmware/analysis/verification.json", encoding="utf-8"))
device = bytes.fromhex(payload["device"]["raw_hex"]["VS_CONFIGURATION"])
image = open("firmware/rc102_flash.bin", "rb").read()

offset = 0x030000
in_image = image[offset:].split(b"\x00")[0]
body = device[8:]
device_text = body.split(b"\x00")[0]

print("declared length prefix:", device[:8].hex())
print("in-image bytes:", len(in_image), " device bytes:", len(device_text))
limit = min(len(in_image), len(device_text))
first_difference = next((i for i in range(limit) if in_image[i] != device_text[i]), None)
print("first difference at:", first_difference)
if first_difference is not None:
    print("  image :", in_image[max(0, first_difference - 8) : first_difference + 24])
    print("  device:", device_text[max(0, first_difference - 8) : first_difference + 24])
print("tail image :", in_image[-40:])
print("tail device:", device_text[-40:])
print("device body has extra after NUL:", body[len(device_text) + 1 :][:80])
