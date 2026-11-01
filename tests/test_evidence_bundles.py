"""Regression tests for the 2026-11-01 evidence bundles (audited defects).

Every check is offline. The defects covered: empty/missing decoded exports, wrong provenance
labels, manifest hashing itself, word-scan pointer classes, CRLF/non-UTF-8 generated text,
and the write ledger of the single handshake experiment. The committed repository copy holds
the root browsable files plus the ZIP; all bundle members are checked inside the ZIP.
"""

import hashlib
import json
import pathlib
import unittest
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[1]
WF = ROOT / "docs" / "evidence" / "2026-11-01-writefree"
FU = ROOT / "docs" / "evidence" / "2026-11-01-handshake"
WF_ZIP = "radiacode-device-evidence.zip"
FU_ZIP = "radiacode-device-evidence-followup.zip"
COVERAGE_KINDS = {
    "instruction", "instruction(partial)", "data(.word)", "data(.word)(partial)",
    "unclassified_data(.byte)", "unclassified_data(.byte)(partial)",
    "padding(.fill)", "padding(.fill)(partial)", "NOT_IN_LISTING",
}


def _zip(dirpath, name):
    return zipfile.ZipFile(str(dirpath / name))


def _manifest(dirpath):
    return json.loads((dirpath / "manifest.json").read_text(encoding="utf-8"))


def _member(dirpath, zipname, member):
    with _zip(dirpath, zipname) as zf:
        return json.loads(zf.read(member).decode("utf-8"))


class BundleIntegrity(unittest.TestCase):
    def _contract(self, dirpath, zipname):
        man = _manifest(dirpath)
        self.assertTrue(man["self_excluded"])
        with _zip(dirpath, zipname) as zf:
            names = set(zf.namelist())
            self.assertIn("manifest.json", names, "manifest must ship inside the ZIP")
            for e in man["files"]:
                self.assertNotEqual(e["path"], "manifest.json", "manifest excludes itself")
                self.assertNotEqual(e["path"], "CHECKSUMS256.txt")
                got = hashlib.sha256(zf.read(e["path"])).hexdigest()
                self.assertEqual(got, e["sha256"], f"hash mismatch: {e['path']}")
            self.assertNotIn("CHECKSUMS256.txt", names,
                             "checksum file stays outside the ZIP")
            for name in names:
                if not name.endswith((".json", ".md", ".txt", ".csv", ".hex")):
                    continue
                raw = zf.read(name)
                self.assertNotIn(b"\r", raw, f"CRLF survived in {name}")
                raw.decode("utf-8")  # raises on invalid encoding
        for line in (dirpath / "CHECKSUMS256.txt").read_text(encoding="utf-8").split("\n"):
            if not line.strip():
                continue
            want, path = line.split()
            got = hashlib.sha256((dirpath / path).read_bytes()).hexdigest()
            self.assertEqual(got, want, f"CHECKSUMS256 mismatch: {path}")

    def test_writefree_manifest_zip_checksum_contract(self):
        self._contract(WF, WF_ZIP)

    def test_followup_manifest_zip_checksum_contract(self):
        self._contract(FU, FU_ZIP)


class DecodedExports(unittest.TestCase):
    """The two files the earlier audit found empty/missing, and their sources."""

    def test_configuration_text_nonempty_and_byte_consistent(self):
        raw_capture = _member(WF, WF_ZIP, "raw/prior_capture.json")
        hexed = raw_capture["virtual_strings"]["0x002"]["hex"]
        with _zip(WF, WF_ZIP) as zf:
            text = zf.read("decoded/prior_capture_configuration_text.txt").decode("utf-8")
            hexfile = zf.read("decoded/prior_capture_configuration_bytes.hex").decode(
                "utf-8").strip()
        self.assertTrue(text.startswith("[DeviceParams]"))
        self.assertEqual(len(bytes.fromhex(hexed)), 3256)
        self.assertEqual(hexfile, hexed)

    def test_energy_calibration_exported_with_history(self):
        doc = _member(WF, WF_ZIP, "decoded/energy_calibration.json")
        raw_capture = _member(WF, WF_ZIP, "raw/prior_capture.json")
        self.assertEqual(doc["raw_hex"], raw_capture["virtual_strings"]["0x202"]["hex"])
        self.assertTrue(doc["source"].startswith("prior-repo-capture"))
        self.assertIn("2026-10-31", doc["source"])
        self.assertAlmostEqual(doc["decoded_f32le"]["A0"], 5.15874719619751, places=9)

    def test_fresh_config_and_calibration_equal_prior(self):
        cons = _member(FU, FU_ZIP, "decoded/consistency_report.json")["checks"]
        self.assertTrue(cons["config_equal_to_prior"])
        self.assertTrue(cons["config_bytes_equal_in_image_blob"])
        self.assertTrue(cons["calibration_equal_to_prior"])
        cal = _member(FU, FU_ZIP, "decoded/fresh_energy_calibration.json")
        self.assertTrue(cal["equal_to_prior_capture"])
        self.assertAlmostEqual(cal["coefficients"]["A1"], 2.3756351470947266, places=6)


class Provenance(unittest.TestCase):
    def test_historical_files_are_not_tagged_fresh(self):
        ents = {e["path"]: e["source"] for e in _manifest(WF)["files"]}
        for p in ("raw/prior_capture.json", "raw/vsfr_readout_prior.json",
                  "raw/sweep_noarg.json", "raw/sweep_witharg.json"):
            self.assertTrue(ents[p].startswith("prior-repo-capture"), p)
        for p in ("raw/session_reads.json", "decoded/fresh_baseline.json"):
            self.assertTrue(ents[p].startswith("fresh-writefree"), p)
        self.assertTrue(ents["raw/handshake_experiment.json"].startswith("fresh-handshake"))

    def test_write_ledger(self):
        ident = _member(FU, FU_ZIP, "identity.json")
        self.assertEqual(ident["writes_issued"][0]["cmd"], "0x0007")
        self.assertEqual(ident["writes_issued"][0]["count"], 1)
        self.assertEqual(ident["session_writes_total"]["0x0007"], 2)


class PointerCoverage(unittest.TestCase):
    """Defect: the first word scan defaulted missing listing rows to 'instruction'."""

    def test_classes_come_from_real_spans(self):
        doc = _member(FU, FU_ZIP, "hardware/bootloader_pointers_check.json")
        self.assertEqual(sum(doc["by_coverage"].values()),
                         doc["total_words_in_0x0800_range"])
        for item in doc["items"]:
            self.assertIn(item["listing_coverage"], COVERAGE_KINDS)
            self.assertNotIn("instruction_row", item)  # the old empty-evidence kind
        self.assertGreater(doc["by_coverage"].get("unclassified_data(.byte)", 0), 0)


class HandshakeRecord(unittest.TestCase):
    def test_handshake_reply_equals_repo_probe(self):
        rec = _member(FU, FU_ZIP, "decoded/handshake_record.json")
        self.assertTrue(rec["matches_repo_probe"])
        self.assertEqual(rec["frame"]["payload_hex"], "0501dada2010001001020000")
        probe = json.loads((ROOT / "firmware" / "rc-102" / "hw1-fw4.14" / "analysis" /
                            "probe_raw.json").read_text(encoding="utf-8"))
        self.assertEqual(probe["exchange"], rec["frame"]["payload_hex"])

    def test_status_stable_and_counters_untouched(self):
        base = _member(FU, FU_ZIP, "decoded/fresh_baseline.json")
        self.assertEqual(base["stats"]["GET_STATUS"]["distinct"], 1)
        self.assertEqual(base["samples"][0]["GET_STATUS"], "02000000")
        self.assertEqual(base["stats"]["CPS"]["distinct"], 1)
        self.assertEqual(base["samples"][0]["CPS"], "00000000")


if __name__ == "__main__":
    unittest.main()
