"""Step 6 - decompile the active target's flat image with Ghidra in headless mode.

Seeds functions from the interrupt vector table and from the capstone function index, then writes one
C block per function to the target's `decompiled.c`.

The Ghidra tree and its JDK are expected next to this package (unpacked, not on the system path):

    ghidra_12.2_PUBLIC/            (Ghidra 12.2, `support/analyzeHeadless.bat`)
    jdk-25.0.5+8/                  (Ghidra 12.2 requires JDK 25+)

    python pipeline/step6_decompile.py            # active target
    RC_TARGET=rc-110/fw4.14 python pipeline/step6_decompile.py
"""

import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import config

CFG = config.load()
GHIDRA = os.path.join(config.ROOT, "ghidra_12.2_PUBLIC")
JDK = next((os.path.join(config.ROOT, d) for d in os.listdir(config.ROOT)
            if d.startswith("jdk-")), None)
IMAGE = CFG["flash"]
OUT_C = CFG["c"]
BASE = CFG["mcu"]["base"]
PROJECT = CFG["ghidra_project"]
NAME = CFG["model"].replace("-", "").upper()


def main():
    if not os.path.isdir(GHIDRA):
        print("!! Ghidra tree not found at", GHIDRA)
        return 1
    os.makedirs(PROJECT, exist_ok=True)
    env = dict(os.environ)
    if JDK:
        env["JAVA_HOME"] = JDK
        env["PATH"] = os.path.join(JDK, "bin") + os.pathsep + env.get("PATH", "")
    headless = os.path.join(GHIDRA, "support",
                            "analyzeHeadless.bat" if os.name == "nt" else "analyzeHeadless")
    cmd = [headless, PROJECT, NAME,
           "-import", IMAGE,
           "-loader", "BinaryLoader",
           "-loader-baseAddr", BASE,
           "-loader-blockName", "FLASH",
           "-processor", CFG["mcu"]["processor"],
           "-scriptPath", os.path.join("pipeline", "scripts"),
           "-postScript", "DumpC.java", CFG["dir"],
           "-overwrite"]
    print(" ".join(cmd))
    log = os.path.join(config.ROOT, "ghidra_log.txt")
    with open(log, "w", encoding="utf-8", errors="replace") as fh:
        rc = subprocess.call(cmd, cwd=config.ROOT, env=env, stdout=fh, stderr=subprocess.STDOUT)
    print("ghidra exit", rc, "log", log)
    if os.path.exists(OUT_C):
        lines = sum(1 for _ in open(OUT_C, encoding="utf-8", errors="replace"))
        blocks = sum(1 for line in open(OUT_C, encoding="utf-8", errors="replace")
                     if line.startswith("/* ===== "))
        print("C output:", OUT_C, lines, "lines,", blocks, "function blocks")
    return rc


if __name__ == "__main__":
    sys.exit(main())
