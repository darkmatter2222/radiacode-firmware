import pathlib
import sys
import tempfile
import unittest
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]/'pipeline'))
import report_documents as reports


class LinkedReportPreservation(unittest.TestCase):
    def test_refresh_preserves_original_sections_and_links(self):
        with tempfile.TemporaryDirectory() as d:
            p=pathlib.Path(d)/'summary.md'
            original='# Original title\n\n## Existing linked section\n\n[artifact](../flash.bin)\n\nExisting explanation.\n'
            p.write_text(original, encoding='utf-8', newline='\n')
            reports.update(p,'## Current evidence\n\nFirst result.')
            reports.update(p,'## Current evidence\n\nSecond result.')
            got=p.read_text(encoding='utf-8')
            self.assertTrue(got.startswith('# Original title\n'))
            self.assertIn(original.split('\n\n',1)[1],got)
            self.assertNotIn('First result.',got)
            self.assertEqual(got.count('Second result.'),1)
            self.assertEqual(got.count(reports.START),1)
            reports.update(p,'## Current evidence\n\nSecond result.')
            self.assertEqual(p.read_text(encoding='utf-8'),got)

    def test_malformed_markers_do_not_overwrite_document(self):
        with tempfile.TemporaryDirectory() as d:
            p=pathlib.Path(d)/'confidence.md'
            old='# Important\n'+reports.START+'\nUnclosed block'
            p.write_text(old, encoding='utf-8', newline='\n')
            with self.assertRaises(ValueError):reports.update(p,'replacement')
            self.assertEqual(p.read_text(encoding='utf-8'),old)

    def test_new_report_can_be_refreshed(self):
        with tempfile.TemporaryDirectory() as d:
            p=pathlib.Path(d)/'new.md'
            reports.update(p,'# New report\n')
            reports.update(p,'# Updated report\n')
            self.assertIn('# Updated report',p.read_text(encoding='utf-8'))
            self.assertNotIn('# New report',p.read_text(encoding='utf-8'))
