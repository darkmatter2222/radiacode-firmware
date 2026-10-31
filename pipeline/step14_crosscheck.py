"""Conservative decoder text comparison. Differences are unresolved, never proof of equivalence.

Operand order, conditions, flags, access widths, writeback and shifts are retained.
The exported Ghidra schema must include complete rendered operands; old getOpObjects
exports lose punctuation and cannot support semantic agreement claims.
"""
import json
import os
import re
import config
import evidence

CFG = config.load()
ALIASES = {"r13": "sp", "r14": "lr", "r15": "pc", "ip": "r12",
           "sb": "r9", "sl": "r10", "fp": "r11"}
MNEMONICS = {"bhs": "bcs", "blo": "bcc"}


def canonical(mnemonic, operands):
    mnemonic = re.sub(r"\.(w|n)\b", "", mnemonic.lower())
    mnemonic = MNEMONICS.get(mnemonic, mnemonic)
    # Ghidra condition separators don't change conditions; retain the condition itself.
    mnemonic = mnemonic.replace(".", "")
    operands = operands.lower()
    for old, new in ALIASES.items():
        operands = re.sub(r"\b" + old + r"\b", new, operands)
    operands = re.sub(r"0x([0-9a-f]+)", lambda m: str(int(m[1], 16)), operands)
    operands = re.sub(r"\b0([0-9a-f]{7})\b", lambda m: str(int(m[0], 16)), operands)
    operands = re.sub(r"[\s#]", "", operands)
    return mnemonic, operands


def grade(address, capstone, ghidra):
    if capstone == ghidra:
        return "identical"
    if canonical(*capstone) == canonical(*ghidra):
        return "format_only"
    return "unresolved"


def load_capstone(path):
    out = {}
    pattern = re.compile(r"^([0-9a-f]{8})\s+(?:[0-9a-f]{2}\s+)+\s*([a-z][\w.]*)\s*(.*)$")
    with open(path, encoding="utf-8") as fh:
        for line in fh:
            m = pattern.match(line)
            if m:
                out[int(m[1], 16)] = (m[2], m[3].split(";", 1)[0].strip())
    return out


def main():
    if not os.path.exists(CFG["ghidra_listing"]):
        result = {"target": CFG["key"], "status": "INCONCLUSIVE", "reason": "missing Ghidra listing"}
    else:
        cap = load_capstone(CFG["listing"])
        payload = json.load(open(CFG["ghidra_listing"], encoding="utf-8"))
        gh = {int(a, 16): (m.lower(), op) for a, m, op in payload["instructions"]}
        both = sorted(cap.keys() & gh.keys())
        rows = [{"addr": hex(a), "capstone": cap[a], "ghidra": gh[a], "tier": grade(a, cap[a], gh[a])} for a in both]
        counts = {k: sum(r["tier"] == k for r in rows) for k in ("identical", "format_only", "unresolved")}
        lossless = payload.get("operand_schema") == "rendered-v1"
        result = {"target": CFG["key"], "status": "PASS" if lossless and not counts["unresolved"] and cap.keys() == gh.keys() else "INCONCLUSIVE",
                  "scope": "conservative text agreement; not C or instruction semantic equivalence",
                  "lossless_operands": lossless, "capstone_lines": len(cap), "ghidra_lines": len(gh),
                  "compared": len(both), "tiers": counts,
                  "only_capstone": len(cap.keys() - gh.keys()), "only_ghidra": len(gh.keys() - cap.keys()),
                  "unresolved": [r for r in rows if r["tier"] == "unresolved"],
                  "agreement": None if not lossless or not both else (counts["identical"] + counts["format_only"]) / len(both)}
    with open(CFG["crosscheck"], "w", encoding="utf-8") as fh:
        json.dump(result, fh, indent=2); fh.write("\n")
    evidence.write(CFG["crosscheck"], result, CFG)
    print(result["status"], "decoder comparison:", result.get("tiers", result.get("reason")))
    return 0 if result["status"] == "PASS" else 2


if __name__ == "__main__":
    raise SystemExit(main())
