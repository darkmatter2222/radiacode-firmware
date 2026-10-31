import json
import pathlib
import sys
import unittest
from unittest.mock import patch

ROOT = pathlib.Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'pipeline'))
import config
import emulate
import models
import rcfmt
import step14_crosscheck as cross
import step15_differential as diff
import z3


class ValidationRegression(unittest.TestCase):
    def test_conditional_vfp_read_observer_does_not_change_execution(self):
        import struct
        image = (ROOT / config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
        uc, trace = emulate.new_emulator(image)
        # A global UC_HOOK_MEM_READ caused stale ITSTATE to skip the MOVS
        # return assignment, leaving the input pointer in r0 instead of zero.
        uc.mem_write(0x20000400, struct.pack('<III', 0, 0x7f7fffff, 0x80000001))
        out = emulate.run_function(uc, trace, 0x0802abf8, (0x20000400,0,0,0))
        self.assertEqual((out['stopped'],out['r0']), ('RETURN',0))
        self.assertIn(0x0802ac56, out['unique_addresses'])

    def test_mmio_reads_remain_observed(self):
        uc, trace = emulate.new_emulator(bytes.fromhex('00687047'))
        uc.mem_write(0x40000000, bytes.fromhex('78563412'))
        out = emulate.run_function(uc, trace, emulate.FLASH_BASE, (0x40000000,0,0,0))
        self.assertEqual(out['r0'], 0x12345678)
        self.assertEqual(out['mmio'], [('read',0x40000000,4,0x12345678)])

    def test_budget_is_not_return(self):
        uc, trace = emulate.new_emulator(bytes.fromhex('fee7'))
        out = emulate.run_function(uc, trace, emulate.FLASH_BASE, cycles=7)
        self.assertEqual(out['stopped'], 'BUDGET_EXHAUSTED')
        self.assertEqual(out['instructions'], 7)
        self.assertFalse(diff.case_passed(dict(out, r0_match=True, write_bytes_match=True)))

    def test_return_and_fault(self):
        uc, trace = emulate.new_emulator(bytes.fromhex('01207047'))
        out = emulate.run_function(uc, trace, emulate.FLASH_BASE)
        self.assertEqual((out['stopped'], out['r0']), ('RETURN', 1))
        uc, trace = emulate.new_emulator(bytes.fromhex('00687047')) # ldr r0,[r0]
        out = emulate.run_function(uc, trace, emulate.FLASH_BASE)
        self.assertEqual(out['stopped'], 'FAULT')

    def test_overlapping_write_order(self):
        writes = [(0x20000100, 4, 0x11223344), (0x20000100, 2, 0xBBAA)]
        self.assertEqual(list(diff.byte_map_of_native(writes).values()), [0xAA,0xBB,0x22,0x11])
        self.assertEqual(list(diff.byte_map_of_native(writes[::-1]).values()), [0x44,0x33,0x22,0x11])

    def test_semantic_mutations_are_not_formatting(self):
        pairs = [(('mov','r0, r1'), ('mov','r1, r0')),
                 (('beq','#0x08012340'), ('bne','#0x08012340')),
                 (('adds','r0, r1, #1'), ('add','r0, r1, #1')),
                 (('ldr','r0, [r1, #4]'), ('ldr','r1, [r0, #4]')),
                 (('str','r0, [r1], #4'), ('str','r0, [r1, #4]')),
                 (('eor','r0, r1, r2, asr #32'), ('eor','r0, r1, r2'))]
        for a,b in pairs:
            with self.subTest(a=a,b=b):
                self.assertEqual(cross.grade(0x08010000,a,b),'unresolved')
        self.assertEqual(cross.grade(0, ('mov.w','r12, #0x10'),('mov','ip, #16')), 'format_only')

    def test_format_failure_is_fatal(self):
        self.assertTrue(diff.result_failed({'cases': [], 'format': [{'passed': 0, 'vectors': 1}]}))

    def test_symbolic_matches_unsigned_concrete(self):
        for value in (0, 1, 0x7fffffff, 0x80000000, 0xffffffff):
            expected = models.model_mangle_round(0,0,value,0)[1]
            actual = z3.simplify(models.model_mangle_round(z3.BitVecVal(0,32),z3.BitVecVal(0,32),z3.BitVecVal(value,32),0)[1]).as_long()
            self.assertEqual(expected, actual)

    def test_encrypt_is_required_for_carried_roundtrip(self):
        data = (ROOT / config.load()['container']).read_bytes()
        with patch.object(rcfmt, 'mangle_encrypt_key', side_effect=RuntimeError('disabled')):
            with self.assertRaises(RuntimeError):
                rcfmt.reencode_file(data, recompress=False)

    def test_broken_date_decoder_rejected(self):
        data = (ROOT / config.load()['container']).read_bytes()
        with patch.object(models,'model_msdos_datetime',return_value=dict(year=0,month=0,day=0,hour=0,minute=0,second=0)):
            row = next(x for x in diff.format_layer(data) if x['model']=='msdos_datetime')
        self.assertEqual(row['passed'],0)
        self.assertEqual(row['status'],'FAIL')

    def test_all_containers_decode_and_crc(self):
        for key in config.keys():
            cfg = config.load(key)
            with self.subTest(target=key):
                _, _, image = rcfmt.build_flash_image((ROOT/cfg['container']).read_bytes())
                self.assertEqual(image, (ROOT/cfg['flash']).read_bytes())

    def test_wrong_crc_rejected(self):
        data = (ROOT/config.load()['container']).read_bytes()
        with patch.object(rcfmt, 'calculate_crc', return_value=0):
            with self.assertRaisesRegex(ValueError,'CRC mismatch'):
                rcfmt.build_flash_image(data)



class RecoveryRegression(unittest.TestCase):
    def test_printable_code_is_not_a_string(self):
        import step5_disassemble as dis
        import struct
        data=bytearray(0x10200)
        struct.pack_into('<III',data,0x10000,0x20000800,0x08010101,0xdeadbeee)
        data[0x10100:0x10104]=bytes.fromhex('0a607047') # str r2,[r1]; bx lr, all printable
        _,ins,_,_=dis.analyze(bytes(data))
        self.assertIn(0x08010100,ins)
        self.assertIn(0x08010102,ins)

    def test_unreferenced_bytes_after_return_not_a_function(self):
        import step5_disassemble as dis
        import struct
        data=bytearray(0x10200)
        struct.pack_into('<III',data,0x10000,0x20000800,0x08010101,0xdeadbeee)
        data[0x10100:0x10108]=bytes.fromhex('0120704702207047')
        _,_,funcs,_=dis.analyze(bytes(data))
        self.assertEqual([x['address'] for x in funcs],['0x08010100'])

    def test_item_accessor_is_byte_sized(self):
        mem=models.Mem((ROOT/config.load()['flash']).read_bytes())
        mem.poke(0x20000cc0,0x7fffffff,4)
        mem.poke(0x20000408,0x20000600,4)
        models.model_080275c4_502(mem,(0x20000400,0x502,0,0))
        self.assertEqual(mem.u32(0x20000600),255)

class ContainerBounds(unittest.TestCase):
    def test_truncated_header_rejected(self):
        with self.assertRaisesRegex(ValueError,'truncated'):
            rcfmt.parse_file(b'Phyton\0\0')

    def test_truncated_payload_rejected(self):
        data=(ROOT/config.load()['container']).read_bytes()
        with self.assertRaises(ValueError):
            rcfmt.build_flash_image(data[:-8])

    def test_bad_header_size_rejected(self):
        data=bytearray((ROOT/config.load()['container']).read_bytes())
        data[8:12]=bytes([255])*4
        with self.assertRaises(ValueError):
            rcfmt.build_flash_image(data)

if __name__ == "__main__":
    unittest.main()
