"""Check the state contract against original machine code, not decompiler text."""
import pathlib
import struct
import sys
import unittest

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1] / 'pipeline'))
import build_reconstruction as build
import config


class SessionContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.flash = pathlib.Path(config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()

    def test_literal_resolves_to_actual_state_byte(self):
        self.assertEqual(struct.unpack_from('<I', self.flash, 0x293fc)[0], 0x20000c0c)
        build.validate_session_literal(self.flash)

    def test_all_states_against_independent_oracle(self):
        for state in range(256):
            for context in (state, (state + 1) & 255, 0x102, 0xffffffff):
                with self.subTest(state=state, context=context):
                    result, writes = build.execute(self.flash, 0x08029370,
                        (context, 0, 0, 0), [(0x20000c19, bytes([state, 0x34, 0x12, 0xab]))])
                    self.assertEqual(result['stopped'], 'RETURN')
                    self.assertEqual(result['r0'], build.session_expected(context, state))
                    self.assertFalse(writes)
                    self.assertFalse(result['mmio'])
                    self.assertTrue(result['callee_saved_preserved'])

    def test_wrong_address_reproduces_false_pass(self):
        wrong, _ = build.execute(self.flash, 0x08029370, (2, 0, 0, 0),
                                 [(0x20000c0d, b'\x02')])
        correct, _ = build.execute(self.flash, 0x08029370, (2, 0, 0, 0),
                                   [(0x20000c19, b'\x02')])
        self.assertEqual(wrong['r0'], 1)
        self.assertEqual(correct['r0'], 0x201)
