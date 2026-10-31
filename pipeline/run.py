"""Single entry point for the whole extraction + decompilation pipeline.

    python pipeline/run.py                 # every step, in order
    python pipeline/run.py --list          # show the steps
    python pipeline/run.py --only 4,5      # run selected steps
    python pipeline/run.py --from 6        # resume at step 6
    python pipeline/run.py 2 --sweep       # step 2 plus the long command-id sweep

Steps 2 and 11 need the device powered and advertising (`RC-102-……`); step 3 needs the network on the
first run. Every device command in this pipeline is a read except the `SET_EXCHANGE` sign and the
idempotent wall-clock write, so the unit cannot be bricked by running it.
"""

import os
import runpy
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HERE = os.path.dirname(os.path.abspath(__file__))

STEPS = [
    (1, "step1_validate.py", "self-test the container primitives against PhytonUtils vectors", "offline"),
    (2, "step2_probe.py", "read-only capture from the live unit (identity, strings, areas)", "BLE"),
    (3, "step3_fetch.py", "fetch the official container, match size/date_time/crc32", "network"),
    (4, "step4_decode.py", "decrypt + LZSS-decode the container into the flat flash image", "offline"),
    (5, "step5_disassemble.py", "capstone Thumb-2 sweep -> listing, strings, vectors, functions", "offline"),
    (6, "step6_decompile.py", "Ghidra headless -> C, one block per function", "offline"),
    (7, "step7_index_c.py", "index the C file (function -> line range)", "offline"),
    (8, "step8_xrefs.py", "literal-pool cross references (string -> function)", "offline"),
    (9, "step9_callgraph.py", "reachability from every vector handler", "offline"),
    (10, "step10_tables.py", "static {id, handler} dispatch tables", "offline"),
    (11, "step11_verify.py", "byte-for-byte device vs image verification", "BLE"),
    (12, "step12_report.py", "assemble firmware/analysis/summary.md", "offline"),
]


def parse(argv):
    selected, extra = [], []
    index = 0
    while index < len(argv):
        token = argv[index]
        if token == "--list":
            return None, ["list"]
        if token == "--only" and index + 1 < len(argv):
            selected += [int(x) for x in argv[index + 1].split(",")]
            index += 2
            continue
        if token == "--from" and index + 1 < len(argv):
            start = int(argv[index + 1])
            selected += [n for n, _, _, _ in STEPS if n >= start]
            index += 2
            continue
        if token.startswith("--"):
            extra.append(token)
        elif token.isdigit():
            selected.append(int(token))
        else:
            extra.append(token)
        index += 1
    return (selected or [n for n, _, _, _ in STEPS]), extra


def main(argv):
    os.chdir(ROOT)
    selected, extra = parse(argv)
    if selected == ["list"]:
        for number, name, what, needs in STEPS:
            print("%-3s %-22s %-8s %s" % (number, name, needs, what))
        return 0
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
        sys.argv = [path] + extra
        try:
            runpy.run_path(path, run_name="__main__")
        except SystemExit as exc:
            if exc.code not in (0, None):
                print("!! step %d exited %s" % (number, exc.code))
                failed.append(number)
        except Exception as exc:  # noqa: BLE001
            print("!! step %d failed: %r" % (number, exc))
            failed.append(number)
    print("\npipeline finished: %d/%d steps ok%s"
          % (len(selected) - len(failed), len(selected),
             "" if not failed else ", failed: %s" % failed))
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
