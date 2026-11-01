"""Regression checks for the pinned emulator-only replacement boundary."""
import pathlib
import sys
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'reconstruction'))
import validate_session_hybrid as session


class SessionIntegration(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.original = (ROOT/session.config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
        cls.patch = bytes.fromhex('46f046be')

    def test_only_entry_changes_within_original_image(self):
        candidate = bytes.fromhex('01207047')
        image = session.integrate(self.original, candidate, self.patch)
        offset = session.ENTRY-session.emulate.FLASH_BASE
        self.assertEqual(image[:offset], self.original[:offset])
        self.assertEqual(image[offset+4:len(self.original)], self.original[offset+4:])
        self.assertEqual(image[-4:], candidate)
        self.assertEqual(image[offset:offset+4], self.patch)

    def test_rejects_branch_to_different_target(self):
        with self.assertRaises(ValueError):
            session.integrate(self.original, b'\x70\x47', bytes.fromhex('46f047be'))

    def test_rejects_modified_original(self):
        original = bytearray(self.original)
        original[-1] ^= 1
        with self.assertRaises(ValueError):
            session.integrate(original, b'\x70\x47', self.patch)

    def test_inventory_includes_zero_filled_extension(self):
        changes = session.changed_ranges(b'abc', b'axc\x00\x00')
        self.assertEqual([(r['address'], r['bytes']) for r in changes],
                         [('0x8000001', 1), ('0x8000003', 2)])
        self.assertEqual(session.changed_ranges(b'abc', b'abc'), [])
