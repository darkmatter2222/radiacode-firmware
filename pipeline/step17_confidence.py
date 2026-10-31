"""Step 17 - roll every evidence file up into five separate confidence categories.

The five numbers are deliberately never merged into one "100 %": each answers a different question
and each comes from a different kind of evidence.

* ``byte_matched``       - output the model writes back is identical to the vendor bytes (step 13).
* ``formally_verified``  - properties discharged for all inputs by the SMT solver (step 16).
* ``tested``             - original machine code vs the Python models, and pure-model vectors
                           (step 15, plus the on-device frame checks of step 11 when present).
* ``preserved_unchanged``- bytes/instructions/strings carried verbatim at their original addresses
                           (steps 5-6 artefacts, key-block tail carried through step 13).
* ``unresolved``         - named open items with their counts; nothing here counts toward a pass.

Result: `analysis/confidence.json` plus the human-readable `analysis/confidence.md`.

    python pipeline/step17_confidence.py
"""

import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config
import rcfmt

CFG = config.load()


def load(name, default=None):
    path = CFG[name]
    if not os.path.exists(path):
        return default
    with open(path, encoding="utf-8") as fh:
        return json.load(fh)


def crc_pair_and_layout(data, image_end):
    """Two direct checks that need no other artefact: the key-block CRC pair, the block layout."""
    header = rcfmt.parse_file(data)
    blocks = rcfmt.iter_blocks(data, header["header_size"])
    pair_ok = 0
    layout_ok = 0
    for index, block in enumerate(blocks):
        mangle_index, inner_key, data_key, pair, _ = rcfmt.split_key_block(block["raw"])
        pair_ok += pair[0] == pair[1]
        following = blocks[index + 1]["addr"] if index + 1 < len(blocks) else int(image_end, 16)
        stream = (rcfmt.mangle_decrypt_key(data_key, bytes(block["raw"][rcfmt.KEY_BLOCK_SIZE:]))
                  if inner_key else bytes(block["raw"][rcfmt.KEY_BLOCK_SIZE:]))[: block["size"]]
        produced = rcfmt.lzss_decompress(stream) if header["compressed"] else stream
        layout_ok += following - block["addr"] == len(produced)
    return {"crc_pair_equal": pair_ok, "blocks": len(blocks), "layout_matches_address_delta": layout_ok}


def main():
    config.ensure_dirs(CFG)
    stats = load("stats", {})
    roundtrip = load("roundtrip", {})
    crosscheck = load("crosscheck", {})
    differential = load("differential", {})
    formal = load("formal", {})
    device = load("verification", {})
    on_device = load("container_check", {})
    tables = load("tables", {})
    callgraph = load("callgraph", {})
    with open(CFG["container"], "rb") as fh:
        data = fh.read()
    direct = crc_pair_and_layout(data, stats.get("end") or "0x00000000")

    carried = roundtrip.get("carried", {})
    reencoded = roundtrip.get("reencoded", {})
    lzss = roundtrip.get("lzss", {})
    cases = differential.get("cases", [])
    run_cases = [row for row in cases if "skipped" not in row]
    format_rows = differential.get("format", [])

    byte_matched = {
        "container_bytes": "%d/%d" % (carried.get("bytes_matched", 0), carried.get("bytes_total", 0)),
        "container_identical": carried.get("byte_identical", False),
        "header_fields_and_crc_field": bool(carried.get("header_match"))
        and bool(carried.get("header_crc32_match")),
        "key_blocks_reencrypted": "%d/%d" % (carried.get("blocks_key_match", 0),
                                             carried.get("blocks", 0)),
        "data_blocks_reencrypted": "%d/%d" % (carried.get("blocks_stream_match", 0),
                                              carried.get("blocks", 0)),
        "whole_file_crc": on_device.get("whole_file_crc_matches_device", None),
        "key_block_crc_pair_equal": "%d/%d" % (direct["crc_pair_equal"], direct["blocks"]),
        "note": "re-encoding from the model reproduces every byte of the vendor container; the "
                "recompress pass differs only in the LZSS tie-break order, so it is reported in "
                "`unresolved`, not here.",
    }

    formally_verified = {
        "checks_proved": formal.get("proved", 0),
        "checks_total": len(formal.get("checks", [])),
        "names": [row["check"] for row in formal.get("checks", []) if row["status"] == "proved"],
        "solver": formal.get("solver", ""),
        "note": "bit-vector proofs over the pure model: Mangle round and 48-round chain, CRC-32 "
                "register and word step, Borland LCG period, MS-DOS date packing, LZSS token and "
                "window-slot layout, 8-byte alignment.",
    }

    tested = {
        "function_cases_passed": "%d/%d" % (
            sum(1 for row in run_cases if row.get("r0_match") and row.get("write_bytes_match")),
            len(run_cases)),
        "function_cases_skipped": len(cases) - len(run_cases),
        "instructions_executed": sum(row.get("instructions", 0) for row in run_cases),
        "format_vectors_passed": "%d/%d" % (sum(row.get("passed", 0) for row in format_rows),
                                            sum(row.get("vectors", 0) for row in format_rows)),
        "format_models": [row["model"] for row in format_rows],
        "device_frames_checked": len(device.get("checks", {})) if device else 0,
        "block_decompressed_length_equals_address_delta": "%d/%d" % (
            direct["layout_matches_address_delta"], direct["blocks"]),
        "decoder_agreement": ("%d/%d lines (%.4f)"
                              % (crosscheck.get("compared", 0), crosscheck.get("ghidra_lines", 0),
                                 crosscheck.get("agreement", 0.0))) if crosscheck else "n/a",
        "note": "every function case compares the returned word and all byte-level memory effects "
                "of the native run with the Python transcription; the stack slots the ABI owns are "
                "excluded on both sides.",
    }

    preserved_unchanged = {
        "image_bytes_covered": "%d/%d" % (stats.get("covered_bytes", 0), stats.get("image_bytes", 0)),
        "instructions_decoded": stats.get("instructions", 0),
        "listing_lines": stats.get("listing_lines", 0),
        "functions_indexed": stats.get("functions", 0),
        "strings_indexed": stats.get("strings", 0),
        "c_blocks": 0,
        "data_and_ascii_items": stats.get("data_word_items", 0) + stats.get("ascii_items", 0),
        "key_block_tail_bytes_carried": (rcfmt.KEY_BLOCK_SIZE - 26) * direct["blocks"],
        "note": "the mixed C + assembly listing keeps the original bytes of data, string and "
                "jump-table regions at their original addresses; nothing in that region is rewritten.",
    }
    c_path = CFG["c"]
    if os.path.exists(c_path):
        with open(c_path, encoding="utf-8") as fh:
            preserved_unchanged["c_blocks"] = sum(1 for line in fh if "@ 0" in line[:40] and "=====" in line)

    unresolved = [
        {"item": "definition of the per-block CRC pair beyond crc1 == crc2",
         "detail": "30 buffer/variant combinations checked, none matched; only equality is verified",
         "count": direct["blocks"]},
        {"item": "own LZSS encoder is not bit-identical with the vendor stream",
         "detail": "%d/%d blocks stream-identical, %d/%d tokens identical, %d vs %d bits"
                   % (lzss.get("stream_identical", 0), lzss.get("blocks", 0),
                      lzss.get("tokens_identical", 0),
                      max(lzss.get("tokens_vendor", 0), lzss.get("tokens_own", 0)),
                      lzss.get("vendor_stream_bytes", 0), lzss.get("own_stream_bytes", 0)),
         "count": lzss.get("blocks", 0) - lzss.get("stream_identical", 0)},
    ]
    if crosscheck:
        tiers = crosscheck.get("tiers", {})
        unresolved.append({"item": "capstone vs SLEIGH lines not identical after normalisation",
                           "detail": "of %d compared: format-only %d, pc-relative %d, semantic %d "
                                     "(agreement %.4f)"
                                     % (crosscheck.get("compared", 0), tiers.get("format_only", 0),
                                        tiers.get("pc_relative", 0), tiers.get("semantic", 0),
                                        crosscheck.get("agreement", 0.0)),
                           "count": tiers.get("semantic", 0)})
        unresolved.append({"item": "lines only one decoder reaches",
                           "detail": "capstone sweeps the whole image, Ghidra stops at data: "
                                     "only-capstone %d, only-ghidra %d"
                                     % (crosscheck.get("only_capstone", 0),
                                        crosscheck.get("only_ghidra", 0)),
                           "count": crosscheck.get("only_capstone", 0)})
    for row in formal.get("checks", []):
        if row["status"] != "proved":
            unresolved.append({"item": "formal check not proved: %s" % row["check"],
                               "detail": json.dumps(row.get("witness", row.get("detail", ""))),
                               "count": 1})
    for row in run_cases:
        if not (row.get("r0_match") and row.get("write_bytes_match")):
            unresolved.append({"item": "differential case not matching: %s" % row["name"],
                               "detail": json.dumps(row.get("error", row.get("first_write_diff", ""))),
                               "count": 1})
    if not device:
        unresolved.append({"item": "on-device frame comparison not available offline",
                           "detail": "steps 2 and 11 need the unit powered", "count": 2})

    handlers = callgraph.get("handlers", 0)
    result = {
        "target": CFG["key"],
        "categories": {
            "byte_matched": byte_matched,
            "formally_verified": formally_verified,
            "tested": tested,
            "preserved_unchanged": preserved_unchanged,
        },
        "unresolved": unresolved,
        "sources": {name: CFG[name] for name in
                    ("stats", "functions", "roundtrip", "crosscheck", "differential", "formal",
                     "verification", "container_check") if os.path.exists(CFG[name])},
        "inventory": {
            "image_bytes": stats.get("image_bytes", 0),
            "instructions": stats.get("instructions", 0),
            "functions": stats.get("functions", 0),
            "strings": stats.get("strings", 0),
            "tables": tables.get("table_count", 0),
            "orphan_functions": callgraph.get("orphan_count", 0),
            "handlers_recovered": len(handlers) if isinstance(handlers, list) else handlers,
        },
    }
    with open(CFG["confidence"], "w", encoding="utf-8") as fh:
        json.dump(result, fh, indent=1)
        fh.write("\n")
    write_markdown(result)

    print("byte_matched       container %s, key blocks %s, data blocks %s, crc pair %s"
          % (byte_matched["container_bytes"], byte_matched["key_blocks_reencrypted"],
             byte_matched["data_blocks_reencrypted"], byte_matched["key_block_crc_pair_equal"]))
    print("formally_verified  %d/%d checks proved" % (formally_verified["checks_proved"],
                                                      formally_verified["checks_total"]))
    print("tested             functions %s (%d insns), format vectors %s, layout %s, decoders %s"
          % (tested["function_cases_passed"], tested["instructions_executed"],
             tested["format_vectors_passed"],
             tested["block_decompressed_length_equals_address_delta"],
             tested["decoder_agreement"]))
    print("preserved_unchanged image %s, %d insns, %d c blocks, %d data/ascii items"
          % (preserved_unchanged["image_bytes_covered"], preserved_unchanged["instructions_decoded"],
             preserved_unchanged["c_blocks"], preserved_unchanged["data_and_ascii_items"]))
    print("unresolved         %d named items" % len(unresolved))
    print("wrote", CFG["confidence"], "and", CFG["confidence_md"])
    return 0


def write_markdown(result):
    categories = result["categories"]
    lines = ["# Confidence report - %s" % result["target"], ""]
    lines += ["| category | what it means | evidence |", "| --- | --- | --- |"]
    rows = [
        ("byte_matched", "model writes back the vendor bytes",
         "%s container bytes, key blocks %s, data blocks %s, CRC pair %s"
         % (categories["byte_matched"]["container_bytes"],
            categories["byte_matched"]["key_blocks_reencrypted"],
            categories["byte_matched"]["data_blocks_reencrypted"],
            categories["byte_matched"]["key_block_crc_pair_equal"])),
        ("formally_verified", "proved for all inputs by the SMT solver",
         "%d/%d checks (%s)" % (categories["formally_verified"]["checks_proved"],
                                categories["formally_verified"]["checks_total"],
                                categories["formally_verified"]["solver"])),
        ("tested", "original code vs Python models, offline",
         "functions %s (%d skipped), format vectors %s"
         % (categories["tested"]["function_cases_passed"],
            categories["tested"]["function_cases_skipped"],
            categories["tested"]["format_vectors_passed"])),
        ("preserved_unchanged", "carried verbatim at the original address",
         "image %s bytes, %d instructions, %d C blocks"
         % (categories["preserved_unchanged"]["image_bytes_covered"],
            categories["preserved_unchanged"]["instructions_decoded"],
            categories["preserved_unchanged"]["c_blocks"])),
    ]
    for name, meaning, evidence in rows:
        lines.append("| %s | %s | %s |" % (name, meaning, evidence))
    lines += ["", "## Unresolved", ""]
    for item in result["unresolved"]:
        lines.append("* **%s** (%s) - %s" % (item["item"], item["count"], item["detail"]))
    lines += ["", "## Inventory", ""]
    for key, value in result["inventory"].items():
        lines.append("* `%s`: %s" % (key, value))
    lines += ["", "Evidence files: " + ", ".join("`%s`" % path for path in
                                                 result["sources"].values()), ""]
    with open(CFG["confidence_md"], "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(lines))


if __name__ == "__main__":
    sys.exit(main())
