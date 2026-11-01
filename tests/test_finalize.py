import pathlib
import struct
import sys
import unittest
ROOT=pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'reconstruction'))
import validate_finalize as final

class FinalizerContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.image=(ROOT/final.config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()

    def run_original(self,length,capacity):
        initial=final.initial_state(2,2,True,capacity,0x1000000)
        initial += [(final.OWNER+8,struct.pack('<I',(final.OUTPUT+length)&0xffffffff)),
                    (final.OUTPUT,struct.pack('<I',0x80000007))]
        return final.build.execute(self.image,final.ENTRY,(final.OWNER,0,0,0),initial)

    def test_equal_capacity_preserves_response(self):
        result,writes=self.run_original(16,16)
        self.assertEqual(result['stopped'],'RETURN')
        self.assertEqual(final.word(writes,final.BUFFER),16)
        self.assertEqual(final.word(writes,final.OUTPUT),0x81000007)

    def test_overflow_replaces_header_and_length(self):
        _,writes=self.run_original(16,15)
        self.assertEqual(final.word(writes,final.BUFFER),4)
        self.assertEqual(final.word(writes,final.OUTPUT),0xe1000007)

    def test_comparison_is_unsigned(self):
        _,writes=self.run_original(0x80000000,0x7fffffff)
        self.assertEqual(final.word(writes,final.BUFFER),4)
