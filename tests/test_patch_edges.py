import pathlib
import sys
import unittest
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]/'reconstruction'))
from audit_patch_edges import scan, BASE

class PatchEdges(unittest.TestCase):
    def test_external_branch_into_overwritten_interior(self):
        result=scan(bytes.fromhex('00e0000000000000'),[(BASE+2,BASE+8)])
        row=result['direct_candidates'][0]
        self.assertEqual(row['target'],hex(BASE+4))
        self.assertEqual(row['location'],'interior')
        self.assertTrue(row['overwritten'])

    def test_unaligned_thumb_pointer_is_not_missed(self):
        data=b'x'+(BASE+5).to_bytes(4,'little')
        rows=scan(data,[(BASE+2,BASE+8)])['literal_pointer_candidates']
        self.assertTrue(any(r['offset']==hex(BASE+1) and r['overwritten'] for r in rows))

    def test_internal_branch_is_not_external_edge(self):
        result=scan(bytes.fromhex('00e0000000000000'),[(BASE,BASE+8)])
        self.assertFalse(result['direct_candidates'])
