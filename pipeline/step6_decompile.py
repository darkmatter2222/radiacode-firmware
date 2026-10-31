"""Step 6 — decompile the flat image with Ghidra in headless mode.

Seeds functions from the interrupt vector table and from the capstone function index, then writes one
C block per function to `firmware/decompiled/rc102_flash.c`.

The Ghidra tree and its JDK are expected next to this package (unpacked, not on the system path):

    ghidra_12.2_PUBLIC/            (Ghidra 12.2, `support/analyzeHeadless.bat`)
    jdk-25.0.5+8/                  (Ghidra 12.2 requires JDK 25+)

    python pipeline/step6_decompile.py
"""

import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GHIDRA = os.path.join(ROOT, "ghidra_12.2_PUBLIC")
JDK = next((os.path.join(ROOT, d) for d in os.listdir(ROOT) if d.startswith("jdk-")), None)
IMAGE = "firmware/rc102_flash.bin"
OUT_C = "firmware/decompiled/rc102_flash.c"
BASE = "0x08000000"          # image[0] is the word at 0x08000000; the vector table is at 0x08010000
PROJECT = os.path.join("firmware", "ghidra_proj")
NAME = "RC102"


def main():
    if not os.path.isdir(GHIDRA):
        print("!! Ghidra tree not found at", GHIDRA)
        return 1
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
           "-processor", "ARM:LE:32:v7",
           "-scriptPath", os.path.join("pipeline", "scripts"),
           "-postScript", "DumpC.java"]
    print(" ".join(cmd))
    log = os.path.join(ROOT, "ghidra_log.txt")
    with open(log, "w", encoding="utf-8", errors="replace") as fh:
        rc = subprocess.call(cmd, cwd=ROOT, env=env, stdout=fh, stderr=subprocess.STDOUT)
    print("ghidra exit", rc, "log", log)
    if os.path.exists(OUT_C):
        lines = sum(1 for _ in open(OUT_C, encoding="utf-8", errors="replace"))
        blocks = sum(1 for line in open(OUT_C, encoding="utf-8", errors="replace")
                     if line.startswith("/* ===== "))
        print("C output:", OUT_C, lines, "lines,", blocks, "function blocks")
    return rc


if __name__ == "__main__":
    sys.exit(main())
