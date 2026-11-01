"""Prepare firmware archives and review plans without exposing a write primitive.

Exit 0 means the requested offline operation succeeded, never flash approval.
Exit 2 means blocked/unavailable; exit 1 means invalid input or failed integrity.
The catalog is a reviewed repository baseline, not a vendor signature authority.
"""
import argparse
import asyncio
import hashlib
import io
import json
import os
from pathlib import Path
import zipfile

ROOT = Path(__file__).resolve().parents[1]
CATALOG = json.loads((Path(__file__).with_name('catalog.json')).read_text())
LIMIT = 4 * 1024 * 1024
MISSING = ['bootloader', 'device calibration', 'device settings', 'option bytes',
           'complete device flash readback']
BLOCKERS = [
    'No validated device identity/board/bootloader handshake.',
    'No complete device backup and independently tested restore path.',
    'No validated USB or Bluetooth firmware writer.',
    'No verified power-loss recovery or protected bootloader policy.',
    'No whole-firmware equivalence or original-vs-rebuilt hardware validation.',
]


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_bounded(path, limit=LIMIT):
    """Bound actual reads, including files that grow after stat()."""
    with Path(path).open('rb') as stream:
        data = stream.read(limit + 1)
    if len(data) > limit:
        raise ValueError(f'File exceeds {limit} bytes: {path}')
    return data


def target_record(target):
    if target not in CATALOG:
        raise ValueError('Unknown target; run targets for exact model/build keys')
    return CATALOG[target]


def checked_bytes(data, expected):
    if len(data) != expected['bytes'] or digest(data) != expected['sha256']:
        raise ValueError('Size or SHA-256 does not match the pinned repository baseline')
    return data


def inspect(target, image):
    record = target_record(target)
    data = read_bounded(image)
    matches = [kind for kind, entry in record['files'].items()
               if len(data) == entry['bytes'] and digest(data) == entry['sha256']]
    return {'target': target, 'sha256': digest(data), 'bytes': len(data),
            'recognized_as': matches or ['unrecognized or modified image'],
            'device_compatibility_verified': False, 'deployable': False}


def verify_backup(path, expected_target=None):
    """Verify a fixed ZIP schema without extracting any supplied paths.

    Compare payloads to our catalog, not hashes supplied by an archive author.
    This checks integrity against this checkout, not vendor authenticity or
    recoverability. In particular, an edited 'complete' flag grants no authority.
    """
    data = read_bounded(path)
    with zipfile.ZipFile(io.BytesIO(data)) as archive:
        infos = archive.infolist()
        names = [entry.filename for entry in infos]
        if len(names) != 3 or set(names) != {'manifest.json', 'container.bin', 'flash.bin'}:
            raise ValueError('Unexpected, duplicate, or missing archive entries')
        for entry in infos:
            if entry.file_size > LIMIT or entry.flag_bits & 1:
                raise ValueError('Oversized or encrypted archive entry')
        manifest = json.loads(archive.read('manifest.json'))
        target = manifest['target']
        record = target_record(target)
        if expected_target is not None and target != expected_target:
            raise ValueError('Backup belongs to a different target')
        expected_manifest = backup_manifest(target)
        if manifest != expected_manifest:
            raise ValueError('Unsupported or altered archive manifest')
        for kind, entry in record['files'].items():
            checked_bytes(archive.read(kind + '.bin'), entry)
    return {'status': 'ARCHIVE_VERIFIED', 'target': target,
            'archive_sha256': digest(data), 'complete_device_backup': False,
            'restore_supported': False, 'missing': MISSING}


def backup_manifest(target):
    record = target_record(target)
    return {'schema': 1, 'kind': 'repository-firmware-archive', 'target': target,
            'complete_device_backup': False, 'missing': MISSING,
            'files': {kind: {'bytes': value['bytes'], 'sha256': value['sha256']}
                      for kind, value in record['files'].items()}}


def backup(target, output):
    """Snapshot known repository bytes; never label these as device readback.

    Exclusive creation prevents replacement of an earlier backup (or symlink).
    A partial file after power loss will fail verify-backup; retain a second copy.
    """
    record = target_record(target)
    payloads = {kind: checked_bytes(read_bounded(ROOT / entry['path']), entry)
                for kind, entry in record['files'].items()}
    buffer = io.BytesIO()
    with zipfile.ZipFile(buffer, 'w', compression=zipfile.ZIP_STORED) as archive:
        archive.writestr('manifest.json', json.dumps(backup_manifest(target), sort_keys=True))
        for kind, data in payloads.items():
            archive.writestr(kind + '.bin', data)
    # Do not remove output on error: another process must never lose its file.
    with Path(output).open('xb') as stream:
        stream.write(buffer.getvalue())
        stream.flush()
        os.fsync(stream.fileno())
    return verify_backup(output, target)


def plan(target, image, backup_path, transport, endpoint):
    image_info = inspect(target, image)
    backup_info = verify_backup(backup_path, target)
    return {'status': 'BLOCKED', 'target': target, 'transport': transport,
            'endpoint': endpoint, 'endpoint_is_verified_identity': False,
            'candidate': image_info, 'backup': backup_info,
            'blockers': BLOCKERS, 'device_commands_sent': 0,
            'note': 'A plan is a review report, not an authorization token.'}


def discover(transport):
    """Discovery only. Never claim USB interfaces or BLE names prove identity."""
    if transport == 'bluetooth':
        from bleak import BleakScanner
        async def scan():
            devices = await BleakScanner.discover(timeout=5.0)
            return [{'endpoint': d.address, 'advertised_name': d.name} for d in devices]
        devices = asyncio.run(scan())
    else:
        # Enumeration does not claim an interface, detach a driver or reset USB.
        import usb.core
        devices = [{'vendor_id': f'{d.idVendor:04x}', 'product_id': f'{d.idProduct:04x}',
                    'bus': d.bus, 'address': d.address}
                   for d in usb.core.find(find_all=True)]
    return {'transport': transport, 'devices': devices,
            'identity_verified': False, 'connection_or_flashing_supported': False}


def recovery():
    return {'status': 'MANUAL_RECOVERY_REQUIRED', 'restore_supported': False,
            'instructions': [
                'Before any update: preserve the archive and verify a second copy.',
                'Export user data using supported vendor software; the archive lacks device-specific data.',
                'This CLI cannot install or downgrade firmware. Use manufacturer-supported updates only.',
                'If an official update is in progress, keep power and connection stable; follow its instructions.',
                'If the device fails to start or the update fails, contact manufacturer support for your exact model and bootloader.',
                'Do not mass erase, alter option bytes, or overwrite a bootloader with flash.bin.',
            ], 'guide': 'deployment/RECOVERY.md',
            'official_support': 'https://www.radiacode.com/support'}


def parser():
    result = argparse.ArgumentParser(description=__doc__)
    commands = result.add_subparsers(dest='command', required=True)
    commands.add_parser('targets', help='List known builds; not live devices')
    commands.add_parser('capabilities', help='Show implemented and blocked operations')
    commands.add_parser('recovery', help='Show recovery limitations and official support')
    scan = commands.add_parser('discover', help='Enumerate USB or Bluetooth; no device session')
    scan.add_argument('--transport', required=True, choices=['usb', 'bluetooth'])
    scan.add_argument('--live', action='store_true', help='Explicitly allow local hardware discovery')
    check = commands.add_parser('inspect', help='Hash a candidate; does not approve deployment')
    check.add_argument('--target', required=True, choices=sorted(CATALOG))
    check.add_argument('--image', required=True, type=Path)
    save = commands.add_parser('backup', help='Archive repository firmware; full device backup unavailable')
    save.add_argument('--target', required=True, choices=sorted(CATALOG))
    save.add_argument('--source', required=True, choices=['repository', 'device'])
    save.add_argument('--output', required=True, type=Path)
    verify = commands.add_parser('verify-backup', help='Verify archive integrity, not recoverability')
    verify.add_argument('archive', type=Path)
    for name in ('plan', 'deploy', 'restore'):
        command = commands.add_parser(name, help='Offline preflight; device writes remain blocked')
        command.add_argument('--target', required=True, choices=sorted(CATALOG))
        command.add_argument('--image', required=True, type=Path)
        command.add_argument('--backup', required=True, type=Path)
        command.add_argument('--transport', required=True, choices=['usb', 'bluetooth'])
        command.add_argument('--endpoint', required=True, help='User-supplied identifier; never auto-selected')
    return result


def main(argv=None):
    args = parser().parse_args(argv)
    code = 0
    try:
        if args.command == 'targets':
            report = CATALOG
        elif args.command == 'capabilities':
            report = {'offline': ['targets', 'inspect', 'backup --source repository', 'verify-backup', 'plan'],
                      'discovery': ['usb enumeration (pyusb + libusb)', 'bluetooth advertisements (bleak)'],
                      'device_readback': False, 'device_write': False, 'automatic_restore': False,
                      'blockers': BLOCKERS}
        elif args.command == 'recovery':
            report, code = recovery(), 2
        elif args.command == 'discover':
            if not args.live:
                report, code = {'status': 'BLOCKED', 'reason': 'Discovery requires --live'}, 2
            else:
                report = discover(args.transport)
        elif args.command == 'inspect':
            report = inspect(args.target, args.image)
        elif args.command == 'backup':
            if args.source == 'device':
                report, code = {'status': 'BLOCKED', 'reason': 'Full device readback is not implemented',
                                'missing': MISSING, 'device_commands_sent': 0}, 2
            else:
                report = backup(args.target, args.output)
        elif args.command == 'verify-backup':
            report = verify_backup(args.archive)
        else:
            report = plan(args.target, args.image, args.backup, args.transport, args.endpoint)
            report['requested_operation'] = args.command
            code = 2
    except KeyboardInterrupt:
        report, code = {'status': 'INTERRUPTED', 'device_write_supported': False}, 130
    except Exception as exc:
        # A dependency, permission or parse failure must never trigger fallback
        # to another transport, device, image, or a relaxed validation path.
        report, code = {'status': 'ERROR', 'error': str(exc), 'device_write_supported': False}, 1
    print(json.dumps(report, indent=2))
    return code
