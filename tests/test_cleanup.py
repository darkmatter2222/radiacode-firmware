import pathlib
import sys
import unittest
ROOT=pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'reconstruction'))
import validate_cleanup as cleanup

class CleanupRegression(unittest.TestCase):
    def test_original_unlinks_middle_and_clears_flag(self):
        original=(ROOT/cleanup.config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
        pairs=cleanup.presets([0x20005000,cleanup.NODE,0x20005020],0xff)
        uc,trace=cleanup.emulate.new_emulator(original)
        cleanup.emulate.preset(uc,pairs)
        result=cleanup.emulate.run_function(uc,trace,0x08029086)
        self.assertEqual(result['stopped'],'RETURN')
        self.assertEqual(cleanup.emulate.read_word(uc,0x20005004),0x20005020)
        self.assertEqual(cleanup.emulate.read_word(uc,cleanup.NODE+4),0)
        self.assertEqual(cleanup.emulate.read_word(uc,0x2000dfd0),0xfb)
        self.assertEqual(bytes(uc.mem_read(cleanup.FLAG,1)),b'\0')

    def test_cycle_is_budget_exhaustion_not_success(self):
        original=(ROOT/cleanup.config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
        pairs=cleanup.presets([0x20005000],4)
        pairs.append((0x20005004,(0x20005000).to_bytes(4,'little')))
        uc,trace=cleanup.emulate.new_emulator(original)
        cleanup.emulate.preset(uc,pairs)
        result=cleanup.emulate.run_function(uc,trace,0x08029086,cycles=100)
        self.assertEqual(result['stopped'],'BUDGET_EXHAUSTED')
