"""Failure-path tests for the deployment preparation boundary."""
import contextlib
import io
import json
from pathlib import Path
import tempfile
import unittest
import warnings
from unittest.mock import patch
import zipfile
from deployment import cli

TARGET = 'rc-102/hw1-fw4.14'


class DeploymentTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.archive = Path(self.temp.name) / 'backup.zip'
        self.image = cli.ROOT / cli.CATALOG[TARGET]['files']['container']['path']

    def invoke(self, args):
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            code = cli.main(args)
        return code, json.loads(output.getvalue())

    def make_backup(self):
        return cli.backup(TARGET, self.archive)

    def rewrite(self, transform):
        with zipfile.ZipFile(self.archive) as z:
            entries = {n: z.read(n) for n in z.namelist()}
        transform(entries)
        with zipfile.ZipFile(self.archive, 'w') as z:
            for name, data in entries.items():
                z.writestr(name, data)

    def test_all_target_archives_verify(self):
        for index, target in enumerate(cli.CATALOG):
            with self.subTest(target=target):
                report = cli.backup(target, Path(self.temp.name) / f'{index}.zip')
                self.assertFalse(report['complete_device_backup'])
                self.assertFalse(report['restore_supported'])

    def test_wrong_model_rejected(self):
        self.make_backup()
        with self.assertRaisesRegex(ValueError, 'different target'):
            cli.verify_backup(self.archive, 'rc-410/fw4.16')

    def test_backup_never_overwrites(self):
        self.archive.write_bytes(b'valuable previous backup')
        with self.assertRaises(FileExistsError):
            self.make_backup()
        self.assertEqual(self.archive.read_bytes(), b'valuable previous backup')

    def test_symlink_destination_never_overwrites(self):
        destination = Path(self.temp.name) / 'original'
        destination.write_bytes(b'original')
        self.archive.symlink_to(destination)
        with self.assertRaises(FileExistsError):
            self.make_backup()
        self.assertEqual(destination.read_bytes(), b'original')

    def test_corrupted_payload_rejected(self):
        self.make_backup()
        self.rewrite(lambda e: e.update({'flash.bin': b'wrong'}))
        with self.assertRaisesRegex(ValueError, 'SHA-256'):
            cli.verify_backup(self.archive)

    def test_fake_complete_backup_flag_rejected(self):
        self.make_backup()
        def forge(entries):
            manifest = json.loads(entries['manifest.json'])
            manifest['complete_device_backup'] = True
            entries['manifest.json'] = json.dumps(manifest).encode()
        self.rewrite(forge)
        with self.assertRaisesRegex(ValueError, 'altered'):
            cli.verify_backup(self.archive)

    def test_traversal_member_rejected(self):
        self.make_backup()
        self.rewrite(lambda e: e.update({'../outside': b'bad'}))
        with self.assertRaisesRegex(ValueError, 'entries'):
            cli.verify_backup(self.archive)
        self.assertFalse((Path(self.temp.name).parent / 'outside').exists())

    def test_duplicate_member_rejected(self):
        self.make_backup()
        with warnings.catch_warnings():
            warnings.simplefilter('ignore', UserWarning)
            with zipfile.ZipFile(self.archive, 'a') as archive:
                archive.writestr('flash.bin', b'fake')
        with self.assertRaisesRegex(ValueError, 'entries'):
            cli.verify_backup(self.archive)

    def test_compressed_oversize_member_rejected_before_read(self):
        self.make_backup()
        with zipfile.ZipFile(self.archive) as archive:
            manifest = archive.read('manifest.json')
        with zipfile.ZipFile(self.archive, 'w', zipfile.ZIP_DEFLATED) as archive:
            archive.writestr('manifest.json', manifest)
            archive.writestr('container.bin', b'fake')
            archive.writestr('flash.bin', bytes(cli.LIMIT + 1))
        with self.assertRaisesRegex(ValueError, 'Oversized'):
            cli.verify_backup(self.archive)

    def test_truncated_archive_is_not_a_backup(self):
        self.make_backup()
        self.archive.write_bytes(self.archive.read_bytes()[:80])
        self.assertEqual(self.invoke(['verify-backup', str(self.archive)])[0], 1)

    def test_bounded_input(self):
        self.archive.write_bytes(b'12345')
        with self.assertRaisesRegex(ValueError, 'exceeds'):
            cli.read_bounded(self.archive, 4)

    def test_device_backup_refuses_without_creating_file(self):
        code, result = self.invoke(['backup', '--target', TARGET, '--source', 'device',
                                    '--output', str(self.archive)])
        self.assertEqual(code, 2)
        self.assertEqual(result['device_commands_sent'], 0)
        self.assertFalse(self.archive.exists())

    def test_all_write_requests_stay_blocked(self):
        self.make_backup()
        with patch.object(cli, 'discover', side_effect=AssertionError('hardware accessed')):
            for operation in ('plan', 'deploy', 'restore'):
                for transport in ('usb', 'bluetooth'):
                    with self.subTest(operation=operation, transport=transport):
                        code, result = self.invoke([operation, '--target', TARGET,
                            '--image', str(self.image), '--backup', str(self.archive),
                            '--transport', transport, '--endpoint', 'not-a-device'])
                        self.assertEqual(code, 2)
                        self.assertEqual(result['status'], 'BLOCKED')
                        self.assertEqual(result['device_commands_sent'], 0)
                        self.assertTrue(result['blockers'])

    def test_modified_candidate_is_not_approved(self):
        candidate = Path(self.temp.name) / 'modified.bin'
        candidate.write_bytes(b'custom firmware')
        result = cli.inspect(TARGET, candidate)
        self.assertFalse(result['deployable'])
        self.assertEqual(result['recognized_as'], ['unrecognized or modified image'])

    def test_discovery_requires_explicit_live(self):
        with patch.object(cli, 'discover', side_effect=AssertionError('hardware accessed')):
            self.assertEqual(self.invoke(['discover', '--transport', 'usb'])[0], 2)

    def test_missing_dependency_fails_without_fallback(self):
        with patch.object(cli, 'discover', side_effect=ImportError('no USB backend')) as scan:
            code, _ = self.invoke(['discover', '--transport', 'usb', '--live'])
            self.assertEqual(code, 1)
            scan.assert_called_once_with('usb')

    def test_repository_payload_tampering_rejected(self):
        with patch.object(cli, 'read_bounded', return_value=b'corrupt'):
            with self.assertRaises(ValueError):
                self.make_backup()
        self.assertFalse(self.archive.exists())

    def test_no_force_override(self):
        with contextlib.redirect_stderr(io.StringIO()), self.assertRaises(SystemExit) as exc:
            cli.main(['capabilities', '--force'])
        self.assertEqual(exc.exception.code, 2)
