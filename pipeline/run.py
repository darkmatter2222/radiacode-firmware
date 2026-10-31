"""Pipeline orchestration. Default is offline; select live/network/Ghidra stages explicitly.

Exit 0: selected checks passed. Exit 1: failure. Exit 2: incomplete evidence.
A successful report generation is not a firmware release certification.
"""

import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import config  # noqa: E402

STEPS = [
    (1, "step1_validate.py", "self-test the container primitives against PhytonUtils vectors", "offline"),
    (2, "step2_probe.py", "explicit live capture (--live); session writes occur", "BLE"),
    (3, "step3_fetch.py", "fetch the official containers, match size/date_time/crc32", "network"),
    (4, "step4_decode.py", "decrypt + LZSS-decode the container into the flat flash image", "offline"),
    (5, "step5_disassemble.py", "reachable Thumb candidates, unknown bytes and unresolved transfers", "offline"),
    (6, "step6_decompile.py", "Ghidra headless -> C, one block per function", "offline"),
    (7, "step7_index_c.py", "index the C file (function -> line range)", "offline"),
    (8, "step8_xrefs.py", "literal-pool cross references (string -> function)", "offline"),
    (9, "step9_callgraph.py", "reachability from every vector handler", "offline"),
    (10, "step10_tables.py", "static {id, handler} dispatch tables", "offline"),
    (11, "step11_verify.py", "explicit live identity/config comparison (--live), not whole-flash readback", "BLE"),
    (12, "step12_report.py", "assemble the target's analysis/summary.md", "offline"),
    (13, "step13_roundtrip.py", "byte-exact container re-encode + LZSS encoder equivalence (L1)", "offline"),
    (14, "step14_crosscheck.py", "capstone vs Ghidra/SLEIGH instruction agreement (L2)", "offline"),
    (15, "step15_differential.py", "Unicorn vs Python models, native code as reference (L4)", "offline"),
    (16, "step16_formal.py", "Z3 proofs over the pure model (L5)", "offline"),
    (17, "step17_confidence.py", "evidence inventory and explicit release blockers", "offline"),
]


def parse(argv):
    """-> (selected step numbers or None for all, device keys, extra args for the steps)"""
    selected, devices, extra = [], [], []
    index = 0
    while index < len(argv):
        token = argv[index]
        if token == "--list":
            return ["list"], [], []
        if token in ("--device", "-d") and index + 1 < len(argv):
            devices += argv[index + 1].split(",")
            index += 2
            continue
        if token == "--all-devices":
            devices += config.keys()
            index += 1
            continue
        if token == "--only" and index + 1 < len(argv):
            selected += [int(x) for x in argv[index + 1].split(",")]
            index += 2
            continue
        if token == "--from" and index + 1 < len(argv):
            selected += [n for n, _, _, _ in STEPS if n >= int(argv[index + 1])]
            index += 2
            continue
        if token.startswith("--"):
            extra.append(token)
        elif token.isdigit():
            selected.append(int(token))
        else:
            extra.append(token)
        index += 1
    return (selected or [1,4,5,7,8,9,10,13,14,15,16,17,12]), devices, extra


def show_list():
    print("targets (pipeline/devices.json), * = default")
    for item in config.raw()["targets"]:
        print("  %-20s %-16s dir=%-34s %s"
              % (item["key"], item["device"], item["dir"],
                 "C export present" if os.path.exists(item["dir"] + "/decompiled.c") else "no C export"))
    print("\nsteps")
    for number, name, what, needs in STEPS:
        print("  %-3s %-22s %-8s %s" % (number, name, needs, what))
    return 0


def run_target(key, selected, extra):
    selected = [n for n in selected if n != 12] + ([12] if 12 in selected else [])
    cfg = config.load(key)
    os.makedirs(os.path.join(ROOT, *cfg["dir"].split("/")), exist_ok=True)
    env = dict(os.environ, RC_TARGET=key)
    print("\n########  %s  ->  %s  ########" % (key, cfg["dir"]))
    completed = 0
    failed = []
    inconclusive = []
    for number, name, what, needs in sorted(STEPS, key=lambda row: selected.index(row[0]) if row[0] in selected else 999):
        if number not in selected:
            continue
        path = os.path.join(HERE, name)
        print("\n=== step %d  %s  (%s) ===" % (number, name, needs))
        if not os.path.exists(path):
            print("!! missing", path)
            failed.append(number)
            break
        result = subprocess.run([sys.executable, path] + extra, cwd=ROOT, env=env)
        completed += 1
        if result.returncode == 2:
            inconclusive.append(number)
        elif result.returncode not in (0, None):
            print("!! step %d exited %s" % (number, result.returncode))
            failed.append(number)
            break
    print("\n%s finished: %d/%d steps ok%s"
          % (key, completed - len(failed) - len(inconclusive), len(selected),
             "" if not failed else ", failed: %s" % failed))
    print("inconclusive/skipped steps:", inconclusive)
    return 1 if failed else (2 if inconclusive else 0)


def main(argv):
    os.chdir(ROOT)
    selected, devices, extra = parse(argv)
    if selected == ["list"]:
        return show_list()
    codes = [run_target(key, selected, extra) for key in (devices or [config.load()["key"]])]
    return 1 if 1 in codes else (2 if 2 in codes else 0)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
