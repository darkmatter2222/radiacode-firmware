import hashlib
import json
from pathlib import Path
import sys
import unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'reconstruction'))
import render_annotations as annotations


class AnnotationIntegrity(unittest.TestCase):
    def test_identifiers_only_preserve_strings_and_comments(self):
        raw='int param_1; /* param_1 */ const char *s="param_1"; // param_1\nparam_1 += 1;'
        got=annotations.rename(raw,{'param_1':'event_code'})
        self.assertEqual(got,'int event_code; /* param_1 */ const char *s="param_1"; // param_1\nevent_code += 1;')

    def test_collisions_and_noninvertible_names_are_rejected(self):
        with self.assertRaises(ValueError):annotations.rename('int old; int renamed;',{'old':'renamed'})
        with self.assertRaises(ValueError):annotations.rename('int a,b;',{'a':'value','b':'value'})

    def test_raw_export_change_requires_review(self):
        spec=json.loads((ROOT/'reconstruction/annotations/rc102.json').read_text(encoding='utf-8'))
        raw=(ROOT/'firmware/rc-102/hw1-fw4.14/decompiled.c').read_text(encoding='utf-8')
        with self.assertRaises(ValueError):annotations.render(raw+'\n',spec)

    def test_complete_export_is_reversible_and_warnings_survive(self):
        spec=json.loads((ROOT/'reconstruction/annotations/rc102.json').read_text(encoding='utf-8'))
        raw=(ROOT/'firmware/rc-102/hw1-fw4.14/decompiled.c').read_text(encoding='utf-8')
        named,inventory=annotations.render(raw,spec)
        self.assertEqual(len(inventory),999)
        self.assertEqual(sum(e['status']=='reviewed' for e in inventory),len(spec['functions']))
        self.assertEqual(named.count('WARNING:'),raw.count('WARNING:'))
        self.assertIn('KNOWN DECOMPILER DEFECT',named)
        self.assertIn('event_ring_try_push_08016862',named)
        self.assertIn('next_write_index',named)
        self.assertIn('unresolved_incoming_r7',named)

    def test_local_map_does_not_escape_its_function(self):
        first='/* ===== FUN_1 @ 00000001 ===== */\nint FUN_1(int param_1) {return param_1;}\n'
        second='/* ===== FUN_2 @ 00000002 ===== */\nint FUN_2(int param_1) {return param_1;}\n'
        raw=first+second
        spec={'raw_source_sha256':annotations.digest(raw.encode()),'globals':{},'functions':[{'address':'0x00000001','original':'FUN_1','name':'read_value','locals':{'param_1':'input_value'},'summary':'Read value.','notes':'','confidence':'test','raw_block_sha256':annotations.digest(first.encode())}]}
        named,_=annotations.render(raw,spec)
        self.assertIn('int read_value(int input_value)',named)
        self.assertIn('int FUN_2(int param_1)',named)
