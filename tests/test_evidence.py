import json
import pathlib
import sys
import unittest
from unittest.mock import patch
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]/'pipeline'))
import models
import step15_differential as diff
import step16_formal as formal
import step17_confidence as confidence
import rcfmt
import config

class EvidenceContracts(unittest.TestCase):
    def test_warning_block_is_not_successful_recovery(self):
        text='/* ===== FUN_08010242 @ 08010242 ===== */\n/* WARNING: Bad instruction - Truncating control flow here */\nvoid f(){halt_baddata();}'
        row=confidence.audit_c(text)[0]
        self.assertTrue(row['truncated'])
        self.assertTrue(row['warnings'])

    def test_prefix_match_does_not_allow_modified_image(self):
        flash=bytearray(pathlib.Path(config.load()['flash']).read_bytes())
        self.assertTrue(models.applies(flash,0x08000000,0x08017eb4))
        flash[-1]^=1
        self.assertFalse(models.applies(flash,0x08000000,0x08017eb4))

    def test_missing_raw_ciphertext_is_skip(self):
        data=pathlib.Path(config.load()['container']).read_bytes()
        with patch.object(diff,'_load',return_value={'flash_areas':{'1':{'hex':'00','size':1,'seed':'0x0'}}}):
            row=next(x for x in diff.format_layer(data) if x['model']=='borland_lcg_device')
        self.assertEqual((row['status'],row['vectors']),('SKIP',0))

    def test_raw_ciphertext_corruption_fails(self):
        import struct
        plain=b'known bytes'; seed=123
        encrypted,_=rcfmt.borland_xor(struct.pack('<I',len(plain))+plain,seed)
        raw=struct.pack('<II',0,seed)+encrypted
        area={'raw_payload_hex':raw.hex(),'hex':plain.hex(),'size':len(plain)}
        data=pathlib.Path(config.load()['container']).read_bytes()
        with patch.object(diff,'_load',return_value={'flash_areas':{'1':area}}):
            row=next(x for x in diff.format_layer(data) if x['model']=='borland_lcg_device')
            self.assertEqual(row['status'],'PASS')
            area['raw_payload_hex']=(raw[:-1]+bytes([raw[-1]^1])).hex()
            row=next(x for x in diff.format_layer(data) if x['model']=='borland_lcg_device')
            self.assertEqual(row['status'],'FAIL')

    def test_independent_crc_proof(self):
        self.assertEqual(formal.check_crc_word_step()['status'],'proved')

class Orchestration(unittest.TestCase):
    def test_default_is_offline(self):
        import run
        selected,_,_=run.parse([])
        self.assertFalse({2,3,6,11}&set(selected))
        self.assertEqual(selected[-1],12)
