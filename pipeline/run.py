"""Single entry point for the whole extraction + decompilation pipeline.

    python pipeline/run.py                          # every step for the default target
    python pipeline/run.py --list                   # targets + step table
    python pipeline/run.py --device rc-110/fw4.14    # one specific build
    python pipeline/run.py --all-devices            # every registry target, in order
    python pipeline/run.py --only 1,4,5             # selected steps
    python pipeline/run.py --from 6                 # resume at step 6
    python pipeline/run.py 2 --sweep                # step 2 plus the long command-id sweep

The target is the registry key from `pipeline/devices.json`; it is passed to each step through
`RC_TARGET`, and every step is a separate process so its `config.load()` sees that value. Steps 2
and 11 need the device powered and advertising (`RC-102-……`) and are skipped for targets without a
`ble_address`; step 3 needs the network on the first run. Every device command in this pipeline is a
read except the `SET_EXCHANGE` sign and the idempotent wall-clock write, so the unit cannot be
bricked by running it.
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
    (2, "step2_probe.py", "read-only capture from the live unit (identity, strings, areas)", "BLE"),
    (3, "step3_fetch.py", "fetch the official containers, match size/date_time/crc32", "network"),
    (4, "step4_decode.py", "decrypt + LZSS-decode the container into the flat flash image", "offline"),
    (5, "step5_disassemble.py", "capstone Thumb-2 sweep -> listing, strings, vectors, functions", "offline"),
    (6, "step6_decompile.py", "Ghidra headless -> C, one block per function", "offline"),
    (7, "step7_index_c.py", "index the C file (function -> line range)", "offline"),
    (8, "step8_xrefs.py", "literal-pool cross references (string -> function)", "offline"),
    (9, "step9_callgraph.py", "reachability from every vector handler", "offline"),
    (10, "step10_tables.py", "static {id, handler} dispatch tables", "offline"),
    (11, "step11_verify.py", "byte-for-byte device vs image verification", "BLE"),
    (12, "step12_report.py", "assemble the target's analysis/summary.md", "offline"),
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
    return (selected or [n for n, _, _, _ in STEPS]), devices, extra


def show_list():
    print("targets (pipeline/devices.json), * = default")
    for item in config.raw()["targets"]:
        print("  %-20s %-16s dir=%-34s %s"
              % (item["key"], item["device"], item["dir"],
                 "analyzed" if item["analyzed"] else "container only"))
    print("\nsteps")
    for number, name, what, needs in STEPS:
        print("  %-3s %-22s %-8s %s" % (number, name, needs, what))
    return 0


def run_target(key, selected, extra):
    cfg = config.load(key)
    os.makedirs(os.path.join(ROOT, *cfg["dir"].split("/")), exist_ok=True)
    env = dict(os.environ, RC_TARGET=key)
    print("\n########  %s  ->  %s  ########" % (key, cfg["dir"]))
    failed = []
    for number, name, what, needs in STEPS:
        if number not in selected:
            continue
        path = os.path.join(HERE, name)
        print("\n=== step %d  %s  (%s) ===" % (number, name, needs))
        if not os.path.exists(path):
            print("!! missing", path)
            failed.append(number)
            continue
        result = subprocess.run([sys.executable, path] + extra, cwd=ROOT, env=env)
        if result.returncode not in (0, None):
            print("!! step %d exited %s" % (number, result.returncode))
            failed.append(number)
    print("\n%s finished: %d/%d steps ok%s"
          % (key, len(selected) - len(failed), len(selected),
             "" if not failed else ", failed: %s" % failed))
    return 1 if failed else 0


def main(argv):
    os.chdir(ROOT)
    selected, devices, extra = parse(argv)
    if selected == ["list"]:
        return show_list()
    codes = [run_target(key, selected, extra) for key in (devices or [config.load()["key"]])]
    return 1 if any(codes) else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
