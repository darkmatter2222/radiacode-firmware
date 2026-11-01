"""Keep source entry points honest and usable as model coverage changes."""
import json
from pathlib import Path
import re
import sys
import unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'reconstruction'))
import render_navigation


class SourceNavigation(unittest.TestCase):
    def test_generated_guides_reproduce_without_changes(self):
        paths=[ROOT/'firmware/README.md',*sorted((ROOT/'firmware').glob('*/README.md')),*sorted((ROOT/'firmware').glob('*/*/README.md'))]
        before={p:p.read_bytes() for p in paths}
        render_navigation.main()
        self.assertEqual(before,{p:p.read_bytes() for p in paths})

    def test_local_navigation_links_exist(self):
        paths=[ROOT/'START_HERE.md',ROOT/'reconstruction/README.md',ROOT/'firmware/README.md',*sorted((ROOT/'firmware').glob('*/README.md')),*sorted((ROOT/'firmware').glob('*/*/README.md'))]
        for path in paths:
            for link in re.findall(r'\]\(([^)]+)\)',path.read_text(encoding='utf-8')):
                if '://' in link or link.startswith('#'):continue
                target=link.split('#')[0]
                with self.subTest(page=str(path),link=link):self.assertTrue((path.parent/target).exists())

    def test_no_cross_model_readable_coverage_claim(self):
        targets=json.loads((ROOT/'reconstruction/annotated/targets.json').read_text(encoding='utf-8'))
        for target in targets:
            text=(ROOT/'firmware'/target['target']/'README.md').read_text(encoding='utf-8')
            if target['reviewed_function_names']==0:
                self.assertIn('No reviewed English-named source or compiled reconstruction is available',text)
                self.assertIn('for a different target',text)
            else:self.assertIn('Open the named-function index',text)
