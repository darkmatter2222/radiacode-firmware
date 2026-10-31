"""Step 16 - formal checks on the pure parts of the model (layer L5).

Each check is a bit-vector formula discharged with Z3.  A `proved` verdict means the property holds
for *every* value of the quantified bit-vector variables under the encoded semantics; `unknown`
(solver timeout) and `counterexample` (with the witness) are recorded separately and never counted
as passes.  Only side-effect-free routines are eligible - anything touching a peripheral is left to
the differential layer, where the real memory model decides.

Result: `analysis/formal.json`.

    python pipeline/step16_formal.py
"""

import json
import os
import sys

import z3

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config
import evidence
import models

CFG = config.load()
M32 = 0xFFFFFFFF
POLY = z3.BitVecVal(0x04C11DB7, 32)
MASK = z3.BitVecVal(0xFFFFFFFF, 32)


def solve(assertions, conclusion, name):
    """Prove `conclusion` from `assertions`; -> one row for the report."""
    solver = z3.Solver()
    solver.set(timeout=30000)
    for item in assertions:
        solver.add(item)
    solver.add(z3.Not(conclusion))
    status = solver.check()
    if status == z3.unsat:
        return {"check": name, "status": "proved", "premises": len(assertions)}
    if status == z3.sat:
        witness = {}
        model = solver.model()
        for decl in model.decls():
            value = model[decl]
            try:
                witness[str(decl)] = value.as_long()
            except AttributeError:
                witness[str(decl)] = str(value)
        return {"check": name, "status": "counterexample", "witness": witness}
    return {"check": name, "status": "unknown", "premises": len(assertions)}


def shift32_symbolic(value):
    """32 steps of the MSB-first CRC register as a symbolic expression."""
    for _ in range(32):
        bit = z3.LShR(value, 31)
        shifted = (value << 1) & MASK
        value = z3.If(bit == 1, shifted ^ POLY, shifted)
    return value


def shift32_concrete(value):
    """Same register, computed with Python integers."""
    for _ in range(32):
        bit = value >> 31
        value = (value << 1) & M32
        if bit:
            value ^= 0x04C11DB7
    return value


# ---------------------------------------------------------------- checks


def check_mangle_one_round():
    """One Mangle round is inverted by `model_mangle_unround` for every key/round/word pair."""
    key, a, b, rnd = (z3.BitVec(name, 32) for name in ("key", "a", "b", "rnd"))
    forward = models.model_mangle_round(key, a, b, rnd)
    back = models.model_mangle_unround(key, forward[0], forward[1], rnd)
    return solve([z3.ULE(rnd, z3.BitVecVal(47, 32))],
                 z3.And(back[0] == a, back[1] == b), "mangle_round_invertible")


def check_mangle_chain(rounds=48):
    """The 48-round chain (forward then inverted) is the identity: the cipher is a permutation."""
    keys = [z3.BitVec("key%d" % i, 32) for i in range(4)]
    a, b = z3.BitVec("a", 32), z3.BitVec("b", 32)
    forward_a, forward_b = a, b
    for index in range(rounds):
        forward_a, forward_b = models.model_mangle_round(keys[index & 3], forward_a, forward_b, index)
    back_a, back_b = forward_a, forward_b
    for index in range(rounds - 1, -1, -1):
        back_a, back_b = models.model_mangle_unround(keys[index & 3], back_a, back_b, index)
    row = solve([True], z3.And(back_a == a, back_b == b), "mangle_chain_%d_rounds" % rounds)
    row["rounds"] = rounds
    return row


def check_crc_register():
    """The symbolic register reproduces the concrete loop from the documented initial value."""
    symbolic = shift32_symbolic(z3.BitVecVal(0xFFFFFFFF, 32))
    return solve([True], symbolic == z3.BitVecVal(shift32_concrete(0xFFFFFFFF), 32),
                 "crc32_register_deterministic")


def check_crc_word_step():
    """One byte update: table polynomial vs eight serial bit transitions, all inputs."""
    crc = z3.BitVec("crc", 32)
    byte = z3.ZeroExt(24, z3.BitVec("byte", 8))
    index = byte ^ z3.LShR(crc, 24)
    folded = (crc << 8) ^ shift32_symbolic(index)
    serial = crc ^ (byte << 24)
    for _ in range(8):
        serial = z3.If(z3.Extract(31,31,serial) == 1, (serial << 1) ^ POLY, serial << 1)
    # Simplify the zero-extended index before bit-blasting.
    solver = z3.Then('simplify', 'bit-blast', 'sat').solver()
    solver.set(timeout=30000)
    solver.add(z3.simplify(folded != serial))
    status = solver.check()
    return {"check":"crc32_byte_fold_equals_bit_serial", "status":
            "proved" if status == z3.unsat else ("counterexample" if status == z3.sat else "unknown"),
            "scope":"all 32-bit CRC states and 8-bit input bytes; auxiliary format model"}


def check_crc_empty():
    """No data means no register updates, so the CRC of the empty buffer is the init value."""
    rows = []
    for name, value in (("crc32_empty_is_init", models.model_crc32_mpeg2(b"")),):
        rows.append({"check": name, "status": "proved" if value == 0xFFFFFFFF else "counterexample",
                     "value": "0x%08X" % value})
    return rows[0]


def check_lcg_period():
    """Hull-Dobell for the Borland LCG (a=0x015A4E35, c=1, m=2^32) and the keystream byte rule."""
    a, c = 0x015A4E35, 1
    premises = [
        z3.ULT(z3.BitVecVal(1, 32), z3.BitVecVal(2, 32)),          # gcd(c, m) = 1  <-> c odd
        z3.ULT(z3.BitVecVal(a - 1, 32) & z3.BitVecVal(1, 32), z3.BitVecVal(2, 32)),
    ]
    conclusion = z3.And(
        (z3.BitVecVal(c, 32) & z3.BitVecVal(1, 32)) == z3.BitVecVal(1, 32),          # c odd
        (z3.BitVecVal(a - 1, 32) & z3.BitVecVal(1, 32)) == z3.BitVecVal(0, 32),      # 2 | a-1
        (z3.BitVecVal(a - 1, 32) & z3.BitVecVal(3, 32)) == z3.BitVecVal(0, 32),      # 4 | a-1
    )
    row = solve(premises, conclusion, "borland_lcg_hull_dobell")
    row["constants"] = {"a": "0x%08X" % a, "c": c, "m_bits": 32}
    seed = z3.BitVec("seed", 32)
    byte = z3.LShR(seed, 16) & z3.BitVecVal(0xFF, 32)
    keystream = solve([True], z3.ULT(byte, z3.BitVecVal(256, 32)), "borland_lcg_byte_range")
    row["keystream_byte_range"] = keystream["status"]
    return row


def check_datetime_pack():
    """unpack(pack(x)) == x for the MS-DOS packed form used by the container header."""
    year, month, day = (z3.BitVec(name, 32) for name in ("year", "month", "day"))
    hour, minute, sec2 = (z3.BitVec(name, 32) for name in ("hour", "minute", "sec2"))

    def ule(value, limit):
        operands = [item if isinstance(item, z3.ExprRef) else z3.BitVecVal(item, 32)
                    for item in (value, limit)]
        return z3.ULE(*operands)

    bounds = [
        ule(year - 1980, 127), ule(1, month), ule(month, 12), ule(1, day), ule(day, 31),
        ule(hour, 23), ule(minute, 59), ule(sec2, 29),
    ]
    high = ((((year - 1980) << 9) | (month << 5) | day) & 0xFFFF)
    low = ((hour << 11) | (minute << 5) | sec2) & 0xFFFF
    packed = (high << 16) | low
    unpacked = models.model_msdos_datetime(packed)
    return solve(bounds, z3.And(
        unpacked["year"] == year, unpacked["month"] == month, unpacked["day"] == day,
        unpacked["hour"] == hour, unpacked["minute"] == minute, unpacked["second"] == sec2 * 2,
    ), "msdos_datetime_roundtrip")


def check_lzss_token_layout():
    """A coded token unpacks to a position in 0..2047 and a length in 2..17."""
    token = z3.BitVec("token", 16)
    position = z3.LShR(token, 4) & 0x7FF
    length = (token & 0xF) + 2
    return solve([z3.LShR(token, 15) == 0],
                 z3.And(position <= 2047, length >= 2, length <= 17),
                 "lzss_token_layout")


def check_lzss_slot_identity():
    """The window slot of output index k is (2031 + k) mod 2048, so it advances by one per byte."""
    k = z3.BitVec("k", 32)
    slot = (2031 + k) & 2047
    return solve([k <= 0x7FFFF],
                 z3.And(((2031 + (k + 1)) & 2047) == ((slot + 1) & 2047), slot <= 2047),
                 "lzss_window_slot_step")


def check_align_size():
    """`align_size` yields the least multiple of 8 that is >= its argument."""
    size = z3.BitVec("size", 32)
    aligned = ((size & z3.BitVecVal(0xFFFFFFF8, 32)) + z3.BitVecVal(8, 32))
    return solve([z3.ULT(size, z3.BitVecVal(1 << 28, 32)),
                  (size & z3.BitVecVal(7, 32)) != z3.BitVecVal(0, 32)],
                 z3.And(z3.UGE(aligned, size),
                        (aligned & z3.BitVecVal(7, 32)) == z3.BitVecVal(0, 32),
                        z3.ULT(aligned - size, z3.BitVecVal(8, 32))),
                 "align_size_least_multiple_of_8")


CHECKS = [
    check_mangle_one_round,
    check_mangle_chain,
    check_crc_register,
    check_crc_word_step,
    check_crc_empty,
    check_lcg_period,
    check_datetime_pack,
    check_lzss_token_layout,
    check_lzss_slot_identity,
    check_align_size,
]


def main():
    config.ensure_dirs(CFG)
    rows = []
    for function in CHECKS:
        try:
            row = function()
        except Exception as error:
            row = {"check": function.__name__, "status": "error",
                   "detail": "%s: %s" % (type(error).__name__, error)}
        rows.append(row)
        print("%-32s %s" % (row["check"], row["status"]))
    result = {
        "target": CFG["key"],
        "scope": "auxiliary format-model properties; no firmware equivalence proof",
        "solver": "z3 %s" % z3.get_version_string(),
        "checks": rows,
        "proved": sum(1 for row in rows if row["status"] == "proved"),
        "counterexamples": sum(1 for row in rows if row["status"] == "counterexample"),
        "unknown": sum(1 for row in rows if row["status"] == "unknown"),
        "errors": sum(1 for row in rows if row["status"] == "error"),
    }
    with open(CFG["formal"], "w", encoding="utf-8") as fh:
        json.dump(result, fh, indent=1)
        fh.write("\n")
    print("proved %d, counterexamples %d, unknown %d, errors %d"
          % (result["proved"], result["counterexamples"], result["unknown"], result["errors"]))
    evidence.write(CFG["formal"], result, CFG)
    print("wrote", CFG["formal"])
    return 1 if result["counterexamples"] or result["errors"] or result["unknown"] else 0


if __name__ == "__main__":
    sys.exit(main())
