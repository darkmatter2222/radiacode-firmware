## N7. Small documentation corrections found during this pass

* `analysis/stats.json` (9 511 instructions, 336 functions, 157 956 unclassified bytes) disagrees with
  the numbers quoted in `agents.md`/`firmware.md` (66 745 / 1 867); regenerate or annotate.
* `container_check.json: device_frame_count_0x0013 = 19` equals the command id `0x13`; label it
  “echoed id, interpretation unresolved” rather than a frame count.
* Repository tests currently show 1 failure + 1-2 errors on this host for environment reasons
  (symlink privilege, cp1252 default encoding) — pin `encoding="utf-8"` in `tests/test_navigation.py`
  and skip the symlink test when unprivileged so the gate is reproducible.

## N8. Repository-side items from the current working rules (no hardware action)

* Regenerate in the documented order so the gate's per-artifact lines clear: run the analysis steps,
  then `python pipeline/run.py --only 12` (manifests **last**, they hash the other artifacts), then
  `python pipeline/release_gate.py`. Expect the `artifact mismatch …` blockers to disappear; the exit
  code stays `2` (= inconclusive, evidence unavailable) until whole-firmware and hardware evidence
  exist. A green `python -m unittest discover -s tests -v` does not change that.
* Bind every future capture or candidate result to the full image hash pair already pinned in
  `analysis/differential.json:provenance.inputs` - container `67a43a5037262214…5e392`, flash
  `23c31b7dabc59fe3…157f6`. A 16-byte prefix match alone is not an identity claim.
* Keep the pinned VFP read-observer regression: read observers stay MMIO-only, and MMIO is plain RAM
  in the harness, so peripheral behaviour remains uncertified.
* Merge tested repository increments separately from firmware certification; the release gate remains
  closed until whole-firmware and hardware evidence exist.
