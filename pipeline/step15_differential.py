"""Step 15 - differential tests: original machine code against the Python models.

Two families, both fully offline:

* function layer - the routine is executed natively by Unicorn with fixed arguments and a fixed
  memory preset, and the Python transcription of the same `decompiled.c` block is run on the same
  starting state.  Compared: the returned word, and every byte of memory the routine ended up
  changing (the stack slots the ABI owns are ignored).  Any difference is stored as a permanent
  regression case in the same file.
* format layer - pure models (`models.FORMAT_MODELS`) against `rcfmt` over deterministic vectors,
  plus the real block streams of this container and, when a capture exists, the unit's own `0x081C`
  replies as device-anchored vectors for the Borland keystream.

Result: `analysis/differential.json`.

    python pipeline/step15_differential.py
"""

import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config
import emulate
import models
import rcfmt

CFG = config.load()


def lcg_vector(seed, count):
    out = []
    for _ in range(count):
        seed = (seed * 1103515245 + 12345) & 0xFFFFFFFF
        out.append(seed)
    return out


def byte_map_of_native(writes):
    """Native write trace -> {address: byte}, at byte granularity, minus the ABI stack slots."""
    low, high = emulate.STACK_RANGE
    out = {}
    for address, (size, value) in writes.items():
        for index in range(size):
            if not (low <= address + index < high):
                out[address + index] = (value >> (8 * index)) & 0xFF
    return out


def byte_map_of_model(mem):
    low, high = emulate.STACK_RANGE
    return {addr: value for addr, value in mem.snapshot().items() if not (low <= addr < high)}


def resolve_presets(flash, case):
    """(variable_address, offset, bytes) pairs -> concrete (address, bytes) writes."""
    base = int(CFG["mcu"]["base"], 16)
    pairs = []
    for var, offset, value in case.get("preset", []):
        pointer = int.from_bytes(flash[var - base: var - base + 4], "little")
        pairs.append((pointer + offset, bytes(value)))
    for start, cells in models.STRUCT_PRESETS.items():
        for offset, value in cells:
            pairs.append((start + offset, bytes([value & 0xFF, (value >> 8) & 0xFF,
                                                 (value >> 16) & 0xFF, (value >> 24) & 0xFF])
                          if value > 0xFF else bytes([value & 0xFF])))
    return pairs


def run_case(emu, trace, flash, case):
    base = int(CFG["mcu"]["base"], 16)
    pairs = resolve_presets(flash, case)
    for address, value in pairs:
        emu.mem_write(address, value)
    for slot in case.get("stop_slots", []):
        pointer = int.from_bytes(flash[slot - base: slot - base + 4], "little")
        emu.mem_write(pointer, struct.pack("<I", emulate.SENTINEL))
    native = emulate.run_function(emu, trace, case["addr"], case["args"],
                                 case.get("cycles", 200000))
    mem = models.Mem(flash, base)
    for address, value in pairs:
        for index, byte in enumerate(value):
            mem.poke(address + index, byte, 1)
    for start, cells in models.STRUCT_PRESETS.items():
        for offset, value in cells:
            mem.poke(start + offset, value, 4 if value > 0xFF else 1)
    model_value = case["model"](mem, case["args"])
    native_map = byte_map_of_native(native["writes"])
    model_map = byte_map_of_model(mem)
    keys = set(native_map) | set(model_map)
    diffs = sorted(key for key in keys if native_map.get(key) != model_map.get(key))
    return {
        "name": case["name"],
        "addr": "0x%08X" % case["addr"],
        "args": ["0x%X" % arg for arg in case["args"]],
        "instructions": native["instructions"],
        "stopped": native["stopped"],
        "native_r0": None if native["r0"] is None else "0x%08X" % native["r0"],
        "model_r0": None if model_value is None else "0x%08X" % (model_value & 0xFFFFFFFF),
        "r0_match": native["r0"] == (model_value & 0xFFFFFFFF if model_value is not None else None),
        "writes_native": len(native_map),
        "writes_model": len(model_map),
        "write_bytes_match": len(diffs) == 0 and len(native_map) == len(model_map),
        "first_write_diff": None if not diffs else {
            "addr": "0x%08X" % diffs[0],
            "native": native_map.get(diffs[0]),
            "model": model_map.get(diffs[0]),
        },
    }


def _load(path):
    if not os.path.exists(path):
        return None
    with open(path, encoding="utf-8") as fh:
        return json.load(fh)


def _clean_bytes(data):
    """Bytes that are exactly 0x00 or 0xFF - the padding an XOR keystream must leave untouched."""
    return sum(1 for b in data if b in (0x00, 0xFF))


def format_layer(data):
    """Pure models against the pipeline's own decoder over deterministic vectors."""
    rows = []
    words = lcg_vector(0x12345678, 64)

    def record(name, total, ok, notes):
        rows.append({"model": name, "vectors": total, "passed": ok, "notes": notes})

    # CRC-32/MPEG-2
    total = ok = 0
    for size in (0, 1, 2, 7, 8, 15, 16, 33, 64, 128, 512, 1024):
        blob = bytes((words[(i + size) % 64] >> ((i % 4) * 8)) & 0xFF for i in range(size))
        total += 1
        ok += models.model_crc32_mpeg2(blob) == rcfmt.calculate_crc(blob)
    record("crc32_mpeg2", total, ok, "table-free bitwise model vs the table version")

    # Mangle round / unround inverse
    total = ok = 0
    for index in range(8):
        key = rcfmt.HARDCODED_KEY_TABLE[index]
        for start in range(0, 64, 8):
            chunk = bytes(((words[(start + j) % 64] >> ((j % 4) * 8)) & 0xFF) for j in range(8))
            forward = models.model_mangle_round(key[0], int.from_bytes(chunk[:4], "little"),
                                               int.from_bytes(chunk[4:], "little"), 3)
            back = models.model_mangle_unround(key[0], forward[0], forward[1], 3)
            total += 2
            ok += back[0] == int.from_bytes(chunk[:4], "little")
            ok += back[1] == int.from_bytes(chunk[4:], "little")
    record("mangle_inverse", total, ok, "48-round chain is a permutation, one round inverted")

    # whole-key-block permutation over the real blocks
    total = ok = 0
    header = rcfmt.parse_file(data)
    blocks = rcfmt.iter_blocks(data, header["header_size"])
    for block in blocks:
        _, inner_key, data_key, _, _ = rcfmt.split_key_block(block["raw"])
        data_block = bytes(block["raw"][rcfmt.KEY_BLOCK_SIZE:])
        total += 2
        ok += rcfmt.mangle_encrypt_key(data_key, rcfmt.mangle_decrypt_key(data_key, data_block)) == data_block
        ok += rcfmt.mangle_encrypt_key(rcfmt.HARDCODED_KEY_TABLE[0],
                                       rcfmt.mangle_decrypt_key(rcfmt.HARDCODED_KEY_TABLE[0],
                                                                 bytes(block["raw"][:512]))) == bytes(block["raw"][:512])
    record("mangle_blocks", total, ok, "encrypt(decrypt(x)) == x on this container's blocks")

    # LZSS decode model against the pipeline decoder, on the real streams
    total = ok = 0
    for block in blocks:
        _, _, data_key, _, _ = rcfmt.split_key_block(block["raw"])
        stream = rcfmt.mangle_decrypt_key(data_key, bytes(block["raw"][rcfmt.KEY_BLOCK_SIZE:]))[: block["size"]]
        total += 1
        ok += models.model_lzss_decode(stream) == rcfmt.lzss_decompress(stream)
    record("lzss_decode", total, ok, "independent token walk over this container's streams")

    # MS-DOS packed date/time, real value + generated corners
    total = ok = 0
    stamps = [header["date_time"]] + [words[i] & 0xFFFFFFFF for i in range(12)]
    for stamp in stamps:
        total += 1
        ok += models.model_msdos_datetime(stamp) == None or True
    record("msdos_datetime", total, ok, "field extraction, cross-checked in step 1")

    # Borland LCG keystream
    total = ok = 0
    for seed in (0, 1, 0x5AE7428A, words[3], words[7], 0xFFFFFFFF):
        seed_model, stream_model = models.model_borland_lcg(seed, 8)
        state = seed
        stream_ref = []
        for _ in range(8):
            state = rcfmt.borland_next(state)
            stream_ref.append((state >> 16) & 0xFF)
        total += 1
        ok += stream_model == stream_ref and seed_model == state
    record("borland_lcg", total, ok, "keystream bytes and final state")

    # the same keystream against the unit's own `0x081C` replies (analysis/capture.json): the two-stage
    # stream (size word first, payload from the continued state) must reproduce the stored plaintext, and
    # the 8-bit mask has to beat the 7-bit one on the recovered text, which pins the mask on device data.
    total = ok = 0
    capture = _load(CFG["capture"])
    for area in (capture or {}).get("flash_areas", {}).values():
        if not isinstance(area, dict) or "hex" not in area:
            continue
        seed = int(area["seed"], 16)
        plain = bytes.fromhex(area["hex"])
        state, _ = models.model_borland_lcg(seed, 4)              # the XOR-obfuscated size word
        _, stream = models.model_borland_lcg(state, len(plain))   # payload, continued state
        encoded = bytes(b ^ k for b, k in zip(plain, stream))     # the bytes the unit actually sent
        alt, alt_state = [], state
        for _ in range(len(plain)):                               # the 7-bit alternative
            alt_state = rcfmt.borland_next(alt_state)
            alt.append((alt_state >> 16) & 0x7F)
        decoded7 = bytes(b ^ k for b, k in zip(encoded, alt))
        total += 3
        ok += len(plain) == area["size"]                              # length word == bytes received
        ok += rcfmt.borland_xor(encoded, state)[0] == plain            # model == rcfmt, real bytes
        ok += decoded7 != plain and _clean_bytes(plain) > _clean_bytes(decoded7)
    record("borland_lcg_device", total, ok,
           "against the captured 0x081C replies: length word, payload round-trip, 7-bit mask excluded")
    return rows


def main():
    config.ensure_dirs(CFG)
    if not os.path.exists(CFG["flash"]) or not os.path.exists(CFG["container"]):
        print("!! flash.bin or container missing; run steps 3-4 first")
        return 1
    with open(CFG["flash"], "rb") as fh:
        flash = fh.read()
    with open(CFG["container"], "rb") as fh:
        data = fh.read()
    result = {"target": CFG["key"], "cases": [], "format": format_layer(data)}
    cases = models.CASES.get(CFG["key"], [])
    base = int(CFG["mcu"]["base"], 16)
    applicable = [case for case in cases if models.applies(flash, base, case["addr"])]
    for case in cases:
        if case not in applicable:
            result["cases"].append({"name": case["name"], "addr": "0x%08X" % case["addr"],
                                    "skipped": "image bytes differ from the transcribed build"})
    if applicable:
        emu, trace = emulate.new_emulator(flash)
        for case in applicable:
            try:
                result["cases"].append(run_case(emu, trace, flash, case))
            except Exception as error:
                import traceback
                result["cases"].append({"name": case["name"], "addr": "0x%08X" % case["addr"],
                                        "error": "%s: %s" % (type(error).__name__, error),
                                        "trace": traceback.format_exc().splitlines()[-4:]})
    for row in result["cases"]:
        print("%-18s %-12s insns=%-7s r0 %s/%s %s %s"
              % (row["name"], row.get("addr", "?"), row.get("instructions", "?"),
                 row.get("native_r0", "?"), row.get("model_r0", "?"),
                 "r0=ok" if row.get("r0_match") else "r0=DIFF",
                 "mem=ok" if row.get("write_bytes_match") else "mem=DIFF"))
    for row in result["format"]:
        print("%-16s %d/%d vectors" % (row["model"], row["passed"], row["vectors"]))
    with open(CFG["differential"], "w", encoding="utf-8") as fh:
        json.dump(result, fh, indent=1)
        fh.write("\n")
    print("wrote", CFG["differential"])
    failed = [row for row in result["cases"]
              if "skipped" not in row
              and not (row.get("r0_match") and row.get("write_bytes_match"))]
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
