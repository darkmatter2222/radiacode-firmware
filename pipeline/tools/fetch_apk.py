"""Download the official RadiaCode Android APK and pull out the bundled firmware .bin files."""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import io
import json
import os
import urllib.request
import zipfile

import rcfmt

URLS = [
    ("apk", "https://downloads.radiacode.com/EN/RadiaCode.apk"),
    ("exe", "https://downloads.radiacode.com/EN/RadiaCode.exe"),
]

os.makedirs("official", exist_ok=True)

for name, url in URLS:
    try:
        with urllib.request.urlopen(url, timeout=120) as resp:
            blob = resp.read()
    except Exception as exc:  # noqa: BLE001
        print(name, "download failed:", repr(exc))
        continue
    path = f"official/{name}.bin"
    with open(path, "wb") as fh:
        fh.write(blob)
    print(name, "size", len(blob))
    if name == "apk":
        with zipfile.ZipFile(io.BytesIO(blob)) as zf:
            for n in zf.namelist():
                low = n.lower()
                if low.endswith(".bin") or "firmware" in low or "rc-1" in low or "rc_1" in low:
                    data = zf.read(n)
                    if data[:8] in (b"Phyton\x00\x00", b"AlmaCode"):
                        out = f"official/{os.path.basename(n)}"
                        with open(out, "wb") as fh:
                            fh.write(data)
                        print("  firmware file:", n, len(data), json.dumps(rcfmt.parse_file(data)))
