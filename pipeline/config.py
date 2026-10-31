"""Target registry and path resolution for the whole pipeline.

Every step and tool reads its paths from here, so one build = one directory and adding a device means
appending one block to `pipeline/devices.json`.

Resolution order for the active target: the `key` argument, else the `RC_TARGET` environment variable,
else `"default"` in `devices.json`.

    import config
    CFG = config.load()                      # active target
    CFG["flash"], CFG["analysis"], CFG["mcu"]["base"], CFG["expected"]["crc32"], ...

The keys are flat and stable: `dir` plus one entry per artifact, so a step never concatenates paths
itself. `ensure_dirs()` is the only function that touches the filesystem.
"""

import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
REGISTRY = os.path.join(HERE, "devices.json")

# artifact file names inside a target directory (derived files carry neutral names; the vendor
# container keeps its own name so the provenance is visible on disk)
ANALYSIS_FILES = {
    "stats": "stats.json",
    "functions": "functions.json",
    "strings": "strings.json",
    "vectors": "vectors.json",
    "xrefs": "xrefs.json",
    "callgraph": "callgraph.json",
    "tables": "tables.json",
    "verification": "verification.json",
    "capture": "capture.json",
    "container_check": "container_check.json",
    "vsfr": "vsfr_readout.json",
    "sweep_noarg": "sweep_noarg.json",
    "sweep_witharg": "sweep_witharg.json",
    "summary": "summary.md",
    "ghidra_listing": "ghidra_listing.json",
    "roundtrip": "roundtrip.json",
    "crosscheck": "crosscheck.json",
    "differential": "differential.json",
    "formal": "formal.json",
    "confidence": "confidence.json",
    "confidence_md": "confidence.md",
}


def raw():
    """The registry exactly as written in devices.json."""
    with open(REGISTRY, encoding="utf-8") as fh:
        return json.load(fh)


def keys():
    return [item["key"] for item in raw()["targets"]]


def record(key=None):
    data = raw()
    chosen = key or os.environ.get("RC_TARGET") or data["default"]
    for item in data["targets"]:
        if item["key"] == chosen:
            return dict(item), data
    raise KeyError("unknown target %r; known: %s" % (chosen, ", ".join(keys())))


def load(key=None):
    item, registry = record(key)
    target = item["dir"].replace("\\", "/")
    out = dict(item)
    out.update({
        "root": ROOT.replace("\\", "/"),
        "dir": target,
        "container": "%s/%s" % (target, item["primary_container"]),
        "flash": "%s/flash.bin" % target,
        "blocks": "%s/blocks.json" % target,
        "listing": "%s/listing.s" % target,
        "c": "%s/decompiled.c" % target,
        "index": "%s/index.json" % target,
        "manifest": "%s/manifest.json" % target,
        "ghidra_project": "%s/ghidra_proj" % target,
        "analysis_dir": "%s/analysis" % target,
        "apk_url": registry["apk"],
        "exe_url": registry["exe"],
        "transport": registry["transport"],
    })
    for name, filename in ANALYSIS_FILES.items():
        out[name] = "%s/analysis/%s" % (target, filename)
    out["analysis_files"] = ANALYSIS_FILES
    return out


def ensure_dirs(cfg):
    os.makedirs(cfg["analysis_dir"], exist_ok=True)
    return cfg["dir"]
