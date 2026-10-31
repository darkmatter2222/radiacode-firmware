"""Download the official installers and pull out the bundled firmware containers.

Thin wrapper over the same logic `step3_fetch.py` uses; containers are written into the directory of
the target that declares them in `pipeline/devices.json` (`official/` for anything unknown).
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import io
import json
import urllib.request
import zipfile

import config
import rcfmt

REG = config.raw()
OFFICIAL = os.path.join(config.ROOT, "official")
BY_NAME = {}
for item in REG["targets"]:
    for name in item["containers"]:
        BY_NAME[name] = item["dir"]

os.makedirs(OFFICIAL, exist_ok=True)

for name, url in (("apk", REG["apk"]), ("exe", REG["exe"])):
    try:
        with urllib.request.urlopen(url, timeout=120) as resp:
            blob = resp.read()
    except Exception as exc:  # noqa: BLE001
        print(name, "download failed:", repr(exc))
        continue
    path = os.path.join(OFFICIAL, "%s.bin" % name)
    with open(path, "wb") as fh:
        fh.write(blob)
    print(name, "size", len(blob))
    if name != "apk":
        continue
    with zipfile.ZipFile(io.BytesIO(blob)) as zf:
        for entry in zf.namelist():
            low = entry.lower()
            if not (low.endswith(".bin") or "firmware" in low or "rc-1" in low or "rc_1" in low):
                continue
            base = os.path.basename(entry)
            data = zf.read(entry)
            if data[:8] not in (b"Phyton\x00\x00", b"AlmaCode"):
                continue
            folder = BY_NAME.get(base, "official")
            out = os.path.join(config.ROOT, *folder.split("/"), base)
            os.makedirs(os.path.dirname(out), exist_ok=True)
            with open(out, "wb") as fh:
                fh.write(data)
            print("  firmware file:", out, len(data), json.dumps(rcfmt.parse_file(data)))
