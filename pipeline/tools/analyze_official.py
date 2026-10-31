"""Container inventory: header + block summary for every container in the registry."""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import json

import config
import rcfmt

for item in config.raw()["targets"]:
    for name in item["containers"]:
        path = os.path.join(config.ROOT, *item["dir"].split("/"), name)
        if not os.path.exists(path):
            print("%s: missing (%s)" % (item["key"], path))
            continue
        data = open(path, "rb").read()
        header = rcfmt.parse_file(data)
        blocks = rcfmt.iter_blocks(data, header["header_size"])
        primary = name == item["primary_container"]
        print(json.dumps({
            "target": item["key"],
            "file": path.replace("\\", "/"),
            "bytes": len(data),
            "version": "%d.%d" % (header["version_high"], header["version_low"]),
            "compressed": header["compressed"],
            "date_time": "0x%08X" % header["date_time"],
            "whole_crc": "%08x" % rcfmt.calculate_crc(data),
            "blocks": len(blocks),
            "first_addr": "0x%08X" % blocks[0]["addr"],
            "last_addr": "0x%08X" % blocks[-1]["addr"],
            "registry_matches": None if not primary else (
                len(data) == item["expected"]["size"]
                and "0x%08X" % header["date_time"] == item["expected"]["date_time"]
                and "%08x" % rcfmt.calculate_crc(data) == item["expected"]["crc32"].lower().removeprefix("0x")
                and len(blocks) == item["expected"]["blocks"]
            ),
        }))
