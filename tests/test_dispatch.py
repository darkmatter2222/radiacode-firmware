import pathlib
import sys
import unittest
ROOT=pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'reconstruction'))
import validate_dispatch as dispatch

class DispatchBoundary(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.image=(ROOT/dispatch.config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()

    def test_actual_indirect_call_reaches_boundary(self):
        initial=dispatch.handler_presets(2,2,True)
        for table in dispatch.TABLES:
            result=dispatch.run_slice(self.image,table,initial)
            self.assertEqual(result['stop'],'BOUNDARY_REACHED')
            self.assertIn((0x08027322,0x08027490),result['edges'])
            self.assertTrue(result['saved'])

    def test_short_budget_is_not_return(self):
        result=dispatch.run_slice(self.image,dispatch.TABLES[0],dispatch.handler_presets(2,2,True),budget=1)
        self.assertEqual(result['stop'],'BUDGET_EXHAUSTED')

    def test_unmapped_table_is_fault(self):
        result=dispatch.run_slice(self.image,0x30000000,dispatch.handler_presets(2,2,True))
        self.assertEqual(result['stop'],'FAULT')
