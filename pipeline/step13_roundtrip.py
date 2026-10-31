"""Step 13 - rebuild every container from the decoded model and diff it against the vendor file.

`rcfmt.reencode_file` writes the file back from the values the decoder extracted (header fields,
XOR-masked block headers, Mangle keys, LZSS payload), so a byte-for-byte match proves the container
model is a complete, non-lossy description of that build, not just a readable one.  Two passes are
recorded:

* `carried`  - the stored LZSS stream is reused: isolates header + crypto + layout correctness.
* `reencoded` - the payload goes through `rcfmt.lzss_compress` as well: also tests the compressor.

Result: `analysis/roundtrip.json`.

    python pipeline/step13_roundtrip.py
"""

import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config
import evidence
import rcfmt

CFG = config.load()


def token_list(stream, expect):
    """(output position, offset field, length) for every match token in a packed stream."""
    state = {"bit": 0, "out": 0}
    total = len(stream) * 8
    tokens = []

    def take(count):
        value = 0
        for _ in range(count):
            if state["bit"] >= total:
                return None
            position = state["bit"]
            state["bit"] += 1
            value = (value << 1) | ((stream[position >> 3] >> (7 - (position & 7))) & 1)
        return value

    while state["out"] < expect:
        flag = take(1)
        if flag is None:
            break
        if flag:
            take(8)
            state["out"] += 1
        else:
            offset = take(11)
            length = (take(4) or 0) + 2
            tokens.append((state["out"], offset, length))
            state["out"] += length
    return tokens


def pass_summary(data, recompress):
    rebuilt, info = rcfmt.reencode_file(data, recompress=recompress)
    shared = min(len(rebuilt), len(data))
    matched = sum(1 for index in range(shared) if rebuilt[index] == data[index])
    first_diff = next((index for index in range(shared) if rebuilt[index] != data[index]), None)
    blocks = info["blocks"]
    return {
        "bytes_total": len(data),
        "bytes_rebuilt": len(rebuilt),
        "bytes_matched": matched,
        "ratio": round(matched / len(data), 6) if data else 0.0,
        "byte_identical": rebuilt == data,
        "first_difference": None if first_diff is None else "0x%08X" % first_diff,
        "header_match": info["header_match"],
        "header_crc32_match": info["header_crc32_match"],
        "blocks": len(blocks),
        "blocks_exact": sum(1 for item in blocks if item["block_match"]),
        "blocks_key_match": sum(1 for item in blocks if item["key_block_match"]),
        "blocks_stream_match": sum(1 for item in blocks if item["data_block_match"]),
        "blocks_size_match": sum(1 for item in blocks if item["size_match"]),
        "block_detail": blocks,
    }


def compression_layer(data):
    """Per-block LZSS encoder equivalence: identical decode, stream length, token agreement."""
    header = rcfmt.parse_file(data)
    blocks = rcfmt.iter_blocks(data, header["header_size"])
    rows = []
    for block in blocks:
        _, inner_key, data_key, _, _ = rcfmt.split_key_block(block["raw"])
        data_block = bytes(block["raw"][rcfmt.KEY_BLOCK_SIZE:])
        stream = (rcfmt.mangle_decrypt_key(data_key, data_block) if inner_key else data_block)
        stream = stream[: block["size"]]
        payload = rcfmt.lzss_decompress(stream)
        mine = rcfmt.lzss_compress(payload)
        prefix = next((i for i in range(min(len(mine), len(stream))) if mine[i] != stream[i]),
                      min(len(mine), len(stream)))
        vendor_tokens = token_list(stream, len(payload))
        own_tokens = token_list(mine, len(payload))
        rows.append({
            "addr": "0x%08X" % block["addr"],
            "payload": len(payload),
            "decode_identical": rcfmt.lzss_decompress(mine) == payload,
            "stream_identical": mine == stream,
            "vendor_bits": len(stream),
            "own_bits": len(mine),
            "bit_prefix_identical": prefix,
            "vendor_tokens": len(vendor_tokens),
            "own_tokens": len(own_tokens),
            "tokens_identical": sum(1 for a, b in zip(vendor_tokens, own_tokens) if a == b),
        })
    total = sum(row["payload"] for row in rows)
    return {
        "blocks": len(rows),
        "decode_identical": sum(1 for row in rows if row["decode_identical"]),
        "stream_identical": sum(1 for row in rows if row["stream_identical"]),
        "payload_bytes": total,
        "vendor_stream_bytes": sum(row["vendor_bits"] for row in rows),
        "own_stream_bytes": sum(row["own_bits"] for row in rows),
        "tokens_vendor": sum(row["vendor_tokens"] for row in rows),
        "tokens_own": sum(row["own_tokens"] for row in rows),
        "tokens_identical": sum(row["tokens_identical"] for row in rows),
        "detail": rows,
    }


def main():
    config.ensure_dirs(CFG)
    if not os.path.exists(CFG["container"]):
        print("!! container missing:", CFG["container"])
        return 1
    with open(CFG["container"], "rb") as fh:
        data = fh.read()
    result = {
        "target": CFG["key"],
        "container": CFG["container"],
        "carried": pass_summary(data, False),
        "reencoded": pass_summary(data, True),
        "lzss": compression_layer(data),
    }
    exact = result["carried"]["byte_identical"]
    result["byte_exact"] = exact
    out = CFG["roundtrip"]
    with open(out, "w", encoding="utf-8") as fh:
        json.dump(result, fh, indent=1)
        fh.write("\n")
    for label in ("carried", "reencoded"):
        part = result[label]
        print("%-10s %d/%d bytes matched (%.4f) identical=%s blocks %d/%d key %d/%d stream %d/%d"
              % (label, part["bytes_matched"], part["bytes_total"], part["ratio"],
                 part["byte_identical"], part["blocks_exact"], part["blocks"],
                 part["blocks_key_match"], part["blocks"], part["blocks_stream_match"], part["blocks"]))
    lzss = result["lzss"]
    print("lzss        decode-identical %d/%d blocks, stream-identical %d/%d, %d/%d tokens, "
          "%d bytes payload (%d vendor vs %d own bits)"
          % (lzss["decode_identical"], lzss["blocks"], lzss["stream_identical"], lzss["blocks"],
             lzss["tokens_identical"], max(lzss["tokens_vendor"], lzss["tokens_own"]),
             lzss["payload_bytes"], lzss["vendor_stream_bytes"], lzss["own_stream_bytes"]))
    evidence.write(CFG["roundtrip"], result, CFG)
    print("wrote", out)
    return 0 if exact and lzss["decode_identical"] == lzss["blocks"] else 1


if __name__ == "__main__":
    sys.exit(main())
