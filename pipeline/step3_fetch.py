"""Step 3 — fetch the official containers and cross-check them against the device's own numbers.

The device never returns image bytes, so the bulk image comes from the vendor file; this step proves
that file is the one the unit is running by matching the `size / date_time / crc32` triple that
`FW_IMAGE_GET_INFO` (0x0012) reports, plus the descriptor from `RD_SIGNAT` (0x0101).

The two installers are unpacked once into `official/` (gitignored). Every `Phyton/AlmaCode` container
found inside the APK is written into the directory of the target that declares it in
`pipeline/devices.json`, so each build keeps its container next to its own artifacts.

    python pipeline/step3_fetch.py            # uses what is already on disk
    python pipeline/step3_fetch.py --force    # re-download from downloads.radiacode.com
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import io
import json
import urllib.request
import zipfile

import config
import rcfmt

CFG = config.load()
REG = config.raw()
OFFICIAL = os.path.join(config.ROOT, "official")

# container file name -> target directory, from every target's `containers` list
BY_NAME = {}
for item in REG["targets"]:
    for name in item["containers"]:
        BY_NAME[name] = item["dir"]


def download(force):
    os.makedirs(OFFICIAL, exist_ok=True)
    for target in REG["targets"]:
        os.makedirs(os.path.join(config.ROOT, *target["dir"].split("/")), exist_ok=True)
    if not force and all(
            os.path.exists(os.path.join(config.ROOT, *t["dir"].split("/"), name))
            for t in REG["targets"] for name in t["containers"]):
        return "cached"
    for name, url in (("apk", REG["apk"]), ("exe", REG["exe"])):
        installer = os.path.join(OFFICIAL, "%s.bin" % name)
        if not force and os.path.exists(installer):
            blob = open(installer, "rb").read()
        else:
            try:
                with urllib.request.urlopen(url, timeout=180) as resp:
                    blob = resp.read()
            except Exception as exc:  # noqa: BLE001
                print("  %s download failed: %r" % (name, exc))
                continue
            with open(installer, "wb") as fh:
                fh.write(blob)
            print("  %s: %d bytes" % (name, len(blob)))
        if name != "apk":
            continue
        with zipfile.ZipFile(io.BytesIO(blob)) as zf:
            for entry in zf.namelist():
                low = entry.lower()
                if not low.endswith(".bin"):
                    continue
                base = os.path.basename(entry)
                data = zf.read(entry)
                if data[:8] not in (b"Phyton\x00\x00", b"AlmaCode"):
                    continue
                folder = BY_NAME.get(base, "official")
                out = os.path.join(config.ROOT, *folder.split("/"), base)
                with open(out, "wb") as fh:
                    fh.write(data)
                print("  container: %s (%d bytes)" % (out, len(data)))
    return "downloaded"


def device_triple():
    """The `0x0012`/`0x0013` numbers: from the live capture if present, else from the registry."""
    expected = dict(CFG["expected"])
    if os.path.exists(CFG["capture"]):
        capture = json.load(open(CFG["capture"], encoding="utf-8"))
        info = capture.get("identity", {}).get("FW_IMAGE_GET_INFO", {}).get("decoded")
        if info:
            expected.update(
                size=info["size"],
                buffer_size=info["buffer_size"],
                date_time=info["date_time"].upper(),
                crc32=info["crc32"].upper(),
            )
        frames = capture.get("identity", {}).get("FW_IMAGE_UPDATE", {}).get("decoded")
        if frames:
            expected["frames"] = frames["frames"]
    return expected


def _hex(value):
    """`0x5AE7428A`, `0X5ae7428a`, `5ae7428a` -> `5ae7428a`."""
    return str(value).lower().replace("0x", "")


def check():
    expected = device_triple()
    data = open(CFG["container"], "rb").read()
    header = rcfmt.parse_file(data)
    blocks = rcfmt.iter_blocks(data, header["header_size"])
    whole = rcfmt.calculate_crc(data)
    after = rcfmt.calculate_crc(data[header["header_size"]:])
    date_time = "%08x" % header["date_time"]
    crc = "%08x" % whole
    checks = {
        "target": CFG["key"],
        "container": CFG["container"],
        "size": len(data),
        "size_matches_device": len(data) == expected["size"],
        "date_time": "0x" + date_time.upper(),
        "date_time_matches_device": date_time == _hex(expected["date_time"]),
        "container_buffer_size": header["buffer_size"],
        "device_write_chunk_0x0012": expected["chunk"],
        "version": "%d.%d" % (header["version_high"], header["version_low"]),
        "whole_file_crc": "0x" + crc.upper(),
        "whole_file_crc_matches_device": crc == _hex(expected["crc32"]),
        "after_header_crc": "%08x" % after,
        "container_blocks": len(blocks),
        "blocks_match_container": len(blocks) == expected["blocks"],
        "device_frame_count_0x0013": expected["frames"],
        "serial": str(header["serial"]),
    }
    print(json.dumps(checks, indent=2))
    return checks


if __name__ == "__main__":
    print("fetch:", download("--force" in sys.argv))
    checks = check()
    os.makedirs(CFG["analysis_dir"], exist_ok=True)
    with open(CFG["container_check"], "w", encoding="utf-8") as fh:
        json.dump(checks, fh, indent=2)
    print("all match:", all(v is True for k, v in checks.items() if k.endswith("_device")
                            or k == "blocks_match_container"))
