"""Diff the in-image vendor configuration text against the live device's VS CONFIGURATION."""

import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import config

CFG = config.load()
BASE = int(CFG["mcu"]["base"], 16)
payload = json.load(open(CFG["verification"], encoding="utf-8"))
device = bytes.fromhex(payload["device"]["raw_hex"]["VS_CONFIGURATION"])
image = open(CFG["flash"], "rb").read()

offset = int(payload["checks"]["config_text_address"], 16) - BASE
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
