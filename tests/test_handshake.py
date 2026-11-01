"""Machine-code regressions for handler ABI and state effects."""
import pathlib
import struct
import sys
import unittest
ROOT=pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'reconstruction'))
import validate_session_hybrid as session

class HandshakeContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original=(ROOT/session.config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()

    def test_original_returns_incoming_r3_on_both_paths(self):
        for valid in (False,True):
            for incoming in (0,1,0x80000000,0xffffffff):
                result,_=session.build.execute(self.original,session.CALLER,
                    (session.OWNER,0x1234,0xabcd,incoming),session.handler_presets(2,2,valid))
                self.assertEqual(result['stopped'],'RETURN')
                self.assertEqual(result['r0'],incoming)

    def test_invalid_signature_only_advances_cursors_and_writes_error(self):
        _,writes=session.build.execute(self.original,session.CALLER,(session.OWNER,0,0,0),
                                      session.handler_presets(255,2,False))
        expected={}
        for address,value in ((session.OWNER+4,session.INPUT+4),
                              (session.OWNER+8,session.OUTPUT+4),(session.OUTPUT,0xe0000006)):
            expected.update({address+i:byte for i,byte in enumerate(struct.pack('<I',value))})
        self.assertEqual(writes,expected)

    def test_context_two_preserves_nonzero_activation_byte(self):
        initial=session.handler_presets(2,2,True)+[(0x2000082d,b'\xa5')]
        _,writes=session.build.execute(self.original,session.CALLER,(session.OWNER,0,0,0),initial)
        self.assertNotIn(0x2000082d,writes)
