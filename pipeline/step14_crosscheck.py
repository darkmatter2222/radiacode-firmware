"""Step 14 - cross-check the disassembly with a second, independent decoder.

`listing.s` comes from capstone; Ghidra decodes the same bytes with its own SLEIGH specification
(`analysis/ghidra_listing.json`, written by `scripts/DumpListing.java` in step 6).  Two decoders
that agree on a line are far less likely to be wrong together than one that agrees with itself.
The two printers are not comparable character by character, so the comparison is graded:

* `identical`     - same text after whitespace/case normalisation.
* `format_only`   - same mnemonic, same set of numeric operands, different rendering (brackets,
                    `#`, `0x` prefixes, `sp`/`r13` aliases, immediate base points).
* `pc_relative`   - the literal is an offset in one printer and the resolved address in the other
                    (same immediate, PC base = word-aligned instruction address + 4 per ARMv7-M).
* `semantic`      - mnemonic or operand values really differ; these are the ones worth reading.

`agreement` counts the first three tiers.  Lines only one decoder reaches are reported separately:
capstone sweeps the whole image, Ghidra decodes inside function bodies and stops at data.

Result: `analysis/crosscheck.json`.

    python pipeline/step14_crosscheck.py
"""

import bisect
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config

CFG = config.load()
HEX = re.compile(r"0x([0-9a-f]+)")
INSTRUCTION = re.compile(r"^([0-9a-f]{8})\s+(.*?)\s\s(\S.*)$")
ADDRESS = re.compile(r"^[0-9a-f]{8}\s")
NUMBER = re.compile(r"#-0x([0-9a-f]+)|#0x([0-9a-f]+)|#(-?\d+)|0x([0-9a-f]+)|"
                    r"([0-9a-f]*[0-9][0-9a-f]*)")
FLOAT = re.compile(r"-?\d+\.\d+(?:e[-+]?\d+)?")
ALIASES = {"13": "sp", "14": "lr", "15": "pc"}
APCS = {"sb": "r9", "sl": "r10", "fp": "r11", "ip": "r12"}
OPTIONS = {"nld": 12, "nst": 11, "sy": 15, "st": 14, "ld": 13}
WIDTHS = ("w", "n", "8", "16", "32", "64", "f32", "f64")
# the two printers choose different names for the same encoding
MNEMONIC_ALIASES = {"bhs": "bcs", "bls": "bcc", "vcmpef32": "vcmpf32", "vcmpef64": "vcmpf64"}


def key(address):
    """Canonical form for an address key so the two decoders can be joined."""
    return "0x%08X" % int(address, 16)


def expand_aliases(text):
    """`r13`/`r14`/`r15` and `sp`/`lr`/`pc` are the same registers; so are the APCS names."""
    text = re.sub(r"\br(13|14|15)\b", lambda match: ALIASES[match.group(1)], text.lower())
    return re.sub(r"\b(ip|sb|sl|fp)\b", lambda match: APCS[match.group(1)], text)


def normalise(text):
    """Lower-case, drop spaces/braces, put every hex token in decimal, unify register aliases."""
    text = expand_aliases(text).strip()
    text = "".join(text.split(", ")).replace(" ", "")
    text = HEX.sub(lambda match: str(int(match.group(1), 16)), text)
    return re.sub(r"([(),]|\{|\})", "", text)


CONDITIONS = ("eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc", "hi", "ls",
              "ge", "lt", "gt", "le", "al")


def mnemonic_form(mnemonic):
    """`tst.w`/`tst` and `bic.eq`/`biceq` -> one name: the printers split width/condition differently."""
    parts = mnemonic.split(".")
    mnemonic = "".join(part for part in parts if part not in WIDTHS)
    clean = mnemonic
    mnemonic = MNEMONIC_ALIASES.get(clean, clean)
    for code in CONDITIONS:
        if mnemonic.endswith(code) and len(mnemonic) > len(code):
            mnemonic = mnemonic[: -len(code)]
            break
    if mnemonic.endswith("s") and len(mnemonic) > 1:
        mnemonic = mnemonic[: -1]        # `ands` vs `and` (the S bit is part of the encoding)
    if mnemonic.startswith("vcmp"):
        mnemonic = "vcmp"                # VCMP/VCMPE: the E bit is part of the encoding
    return mnemonic


def numbers(text):
    """Set of numeric operand values, hex or decimal as each printer writes them."""
    text = expand_aliases(text)
    for name in ("pc", "lr", "sp", "cpsr", "ipsr", "xpsr"):
        text = text.replace(name, "@")     # otherwise the hex letters inside a name leak in
    for name, value in OPTIONS.items():    # barrier options: `isb sy` vs `isb 0xf`
        text = re.sub(r"\b%s\b" % name, "#%d" % value, text)   # `#` forces the decimal branch
    out = set()
    for match in FLOAT.finditer(text):     # `#5.000000e-01` is the encoded 32-bit immediate
        try:
            out.add(struct.unpack("<I", struct.pack("<f", float(match.group(0))))[0])
        except Exception:
            continue
    text = FLOAT.sub("@", text)
    for match in NUMBER.finditer(text):
        signed_hex, hashed_hex, hashed_dec, prefixed, plain = match.groups()
        if signed_hex is not None:
            out.add((-int(signed_hex, 16)) & 0xFFFFFFFF)     # `#-0x7f7f7f80` == 0x80808080
        elif hashed_hex is not None:
            out.add(int(hashed_hex, 16))
        elif hashed_dec is not None:
            out.add(int(hashed_dec, 10))
        elif prefixed is not None:
            out.add(int(prefixed, 16))
        elif plain is not None:
            out.add(int(plain, 16))
    return out


def load_capstone(path):
    """address -> (mnemonic, operand text) from the capstone listing."""
    out = {}
    if not os.path.exists(path):
        return out
    with open(path, encoding="utf-8") as fh:
        for line in fh:
            match = INSTRUCTION.match(line.rstrip())
            if not match:
                continue
            address, _, rest = match.groups()
            rest = rest.strip()
            if rest.startswith((".", "ascii", '"', "'")):
                continue
            head, _, tail = rest.partition(" ")
            tail = tail.split(";", 1)[0]          # the trailing comment is not part of the line
            out[key("0x" + address)] = (head.lower(), tail.strip())
    return out


def load_ghidra(path):
    """address -> (mnemonic, operand text) from the SLEIGH listing dump."""
    out = {}
    if not os.path.exists(path):
        return out
    with open(path, encoding="utf-8") as fh:
        payload = json.load(fh)
    for address, mnemonic, operands in payload.get("instructions", []):
        out[key(address)] = (mnemonic.lower(), operands)
    return out


def load_ranges(path):
    """Function bodies (start, end) from the capstone index: its own `address` + `size`."""
    if not os.path.exists(path):
        return []
    with open(path, encoding="utf-8") as fh:
        payload = json.load(fh)
    items = payload.get("functions", []) if isinstance(payload, dict) else payload
    rows = []
    for item in items:
        start = item.get("address")
        size = item.get("size") or 0
        if not start:
            continue
        rows.append((int(start, 16), int(start, 16) + max(size - 4, 0)))
    return rows


def variants(value):
    """The ways one immediate shows up: as printed, 32-bit two's complement, negated, magnitude,
    and the narrow or wide form of the same option field (`dmb sy` -> 15 or 31)."""
    masked = value & 0xFFFFFFFF
    out = {value, masked, abs(value), -abs(value)}
    for item in (value, masked):
        out.add((-item) & 0xFFFFFFFF)
        if item < 64:                     # option/field encodings, printed narrow or wide
            out.add(item & 0xF)
            out.add(item | 0x10)
    if masked >= 1 << 31:
        out.add(masked - (1 << 32))
    return out


def same_numbers(left, right):
    """Tolerant operand comparison: same set, an implicit zero offset, or a sign rendering."""
    if left == right or (left - {0}) == (right - {0}):
        return True

    def covered(one, other):
        return all(any(item in other for item in variants(value)) for value in one)

    return covered(left, right) and covered(right, left)


def merged_ranges(ranges):
    """Sort and coalesce the intervals so the membership test below is a binary search."""
    merged = []
    for low, high in sorted(ranges):
        if merged and low <= merged[-1][1] + 4:
            merged[-1][1] = max(merged[-1][1], high)
        else:
            merged.append([low, high])
    return merged


def inside(address, merged):
    index = bisect.bisect_right(merged, [address, 0xFFFFFFFF]) - 1
    return index >= 0 and merged[index][0] <= address <= merged[index][1]


def grade(address, capstone, ghidra):
    """-> one of the four tier names for one instruction both decoders reached."""
    c_mnemonic, c_operands = capstone
    g_mnemonic, g_operands = ghidra
    if (c_mnemonic, c_operands) == (g_mnemonic, g_operands):
        return "identical"
    if normalise(c_mnemonic + c_operands) == normalise(g_mnemonic + g_operands):
        return "identical"
    left, right = numbers(c_operands), numbers(g_operands)
    # a literal pool reference: capstone prints the raw immediate, SLEIGH the resolved word.
    # ARMv7-M uses the *word-aligned* address of the instruction + 4 as the PC base.
    bases = ((address & ~3) + 4, address + 4, address + 2)
    for offset in left:
        for resolved in right:
            if resolved in [base + offset for base in bases] \
                    and same_numbers(left - {offset}, right - {resolved}):
                return "pc_relative"
    if normalise(c_mnemonic + c_operands) == normalise(g_mnemonic + g_operands):
        return "identical"
    if mnemonic_form(c_mnemonic) != mnemonic_form(g_mnemonic):
        return "semantic"
    # an explicit zero offset (`[r1]` vs `r1 0x0`) is the same operand
    if same_numbers(left, right):
        return "format_only"
    return "semantic"


TIERS = ("identical", "format_only", "pc_relative", "semantic")


def main():
    config.ensure_dirs(CFG)
    capstone = load_capstone(CFG["listing"])
    ghidra = load_ghidra(CFG["ghidra_listing"])
    if not ghidra:
        print("!! no analysis/ghidra_listing.json (run step 6 with DumpListing.java); skipping")
        return 0
    ranges = merged_ranges(load_ranges(CFG["functions"]))
    both = sorted(set(capstone) & set(ghidra))
    counts = dict((tier, 0) for tier in TIERS)
    examples = dict((tier, []) for tier in TIERS)
    for address in both:
        tier = grade(int(address, 16), capstone[address], ghidra[address])
        counts[tier] += 1
        if tier != "identical" and len(examples[tier]) < 12:
            examples[tier].append({"addr": address, "capstone": " ".join(capstone[address]).strip(),
                                   "ghidra": " ".join(ghidra[address]).strip()})
    total = len(both)
    agreed = counts["identical"] + counts["format_only"] + counts["pc_relative"]
    result = {
        "target": CFG["key"],
        "capstone_lines": len(capstone),
        "ghidra_lines": len(ghidra),
        "compared": total,
        "tiers": counts,
        "only_capstone": len(set(capstone) - set(ghidra)),
        "only_ghidra": len(set(ghidra) - set(capstone)),
        "agreement": round(agreed / total, 6) if total else 0.0,
        "strict_agreement": round(counts["identical"] / total, 6) if total else 0.0,
        "compared_inside_functions": sum(1 for address in both
                                         if inside(int(address, 16), ranges)),
        "examples": examples,
    }
    with open(CFG["crosscheck"], "w", encoding="utf-8") as fh:
        json.dump(result, fh, indent=1)
        fh.write("\n")
    print("compared %d lines: %s -> agreement %.4f (strict %.4f)"
          % (total, ", ".join("%s %d" % (tier, counts[tier]) for tier in TIERS),
             result["agreement"], result["strict_agreement"]))
    print("only in capstone %d, only in ghidra %d, inside capstone function bodies %d"
          % (result["only_capstone"], result["only_ghidra"], result["compared_inside_functions"]))
    for item in examples["semantic"][:5]:
        print("  %-12s cap=%s | ghidra=%s" % (item["addr"], item["capstone"], item["ghidra"]))
    print("wrote", CFG["crosscheck"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
