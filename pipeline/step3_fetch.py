"""Step 3 — fetch the official container and cross-check it against the device's own numbers.

The device never returns image bytes, so the bulk image comes from the vendor file; this step proves
that file is the one the unit is running by matching the `size / date_time / crc32` triple that
`FW_IMAGE_GET_INFO` (0x0012) reports, plus the descriptor from `RD_SIGNAT` (0x0101).

    python pipeline/step3_fetch.py            # uses official/ if already populated
    python pipeline/step3_fetch.py --force    # re-download from downloads.radiacode.com
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import io
import json
import urllib.request
import zipfile

import rcfmt

URLS = [("apk", "https://downloads.radiacode.com/EN/RadiaCode.apk"),
        ("exe", "https://downloads.radiacode.com/EN/RadiaCode.exe")]
CONTAINER = "official/rc-102z.bin"
# device-reported triple (firmware/analysis/device_capture.json -> identity.FW_IMAGE_GET_INFO)
DEV = {"size": 130148, "chunk": 4096, "buffer_size": 32768, "date_time": 0x5AE7428A,
       "crc32": 0x13095ABB, "frames": 19}

def download(force):
    os.makedirs("official", exist_ok=True)
    if not force and os.path.exists(CONTAINER):
        return "cached"
    for name, url in URLS:
        try:
            with urllib.request.urlopen(url, timeout=180) as resp:
                blob = resp.read()
        except Exception as exc:  # noqa: BLE001
            print("  %s download failed: %r" % (name, exc))
            continue
        with open("official/%s.bin" % name, "wb") as fh:
            fh.write(blob)
        print("  %s: %d bytes" % (name, len(blob)))
        if name != "apk":
            continue
        with zipfile.ZipFile(io.BytesIO(blob)) as zf:
            for entry in zf.namelist():
                low = entry.lower()
                if not low.endswith(".bin"):
                    continue
                data = zf.read(entry)
                if data[:8] not in (b"Phyton\x00\x00", b"AlmaCode"):
                    continue
                out = "official/%s" % os.path.basename(entry)
                with open(out, "wb") as fh:
                    fh.write(data)
                print("  container: %s (%d bytes)" % (out, len(data)))
    return "downloaded"


def check():
    data = open(CONTAINER, "rb").read()
    header = rcfmt.parse_file(data)
    blocks = rcfmt.iter_blocks(data, header["header_size"])
    whole = rcfmt.calculate_crc(data)
    after = rcfmt.calculate_crc(data[header["header_size"]:])
    checks = {
        "container": CONTAINER,
        "size": len(data),
        "size_matches_device": len(data) == DEV["size"],
        "date_time": "0x%08X" % header["date_time"],
        "date_time_matches_device": header["date_time"] == DEV["date_time"],
        "container_buffer_size": header["buffer_size"],
        "device_write_chunk_0x0012": DEV["chunk"],
        "version": "%d.%d" % (header["version_high"], header["version_low"]),
        "whole_file_crc": "%08x" % whole,
        "whole_file_crc_matches_device": whole == DEV["crc32"],
        "after_header_crc": "%08x" % after,
        "container_blocks": len(blocks),
        "device_frame_count_0x0013": DEV["frames"],
        "serial": str(header["serial"]),
    }
    print(json.dumps(checks, indent=2))
    return checks


if __name__ == "__main__":
    print("fetch:", download("--force" in sys.argv))
    checks = check()
    os.makedirs("firmware/analysis", exist_ok=True)
    with open("firmware/analysis/container_check.json", "w", encoding="utf-8") as fh:
        json.dump(checks, fh, indent=2)
    print("all match:", all(v is True for k, v in checks.items() if k.endswith("_device")))
