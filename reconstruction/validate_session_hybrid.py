"""Pinned session-helper integration experiment; output is NEVER deployable firmware."""
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'pipeline'))
import build_reconstruction as build
import config
import emulate
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB

ENTRY, TARGET, CALLER = 0x08029370, 0x08070000, 0x08027490
OWNER, CONTEXT, INPUT, OUTPUT, FLAG = (0x20004000, 0x20004100, 0x20004200,
                                       0x20004300, 0x20004400)


def integrate(original, candidate, patch):
    """Only one pinned image and one fixed emulation allocation are accepted."""
    if build.digest(original) != build.REFERENCE_SHA256:
        raise ValueError('unreviewed image')
    if not candidate or len(candidate) > 256:
        raise ValueError('invalid candidate size')
    instructions = list(Cs(CS_ARCH_ARM, CS_MODE_THUMB).disasm(patch, ENTRY))
    if (len(patch) != 4 or len(instructions) != 1 or
            instructions[0].mnemonic != 'b.w' or
            instructions[0].op_str != '#' + hex(TARGET)):
        raise ValueError('not the reviewed branch')
    offset = ENTRY - emulate.FLASH_BASE
    prefix = list(Cs(CS_ARCH_ARM, CS_MODE_THUMB).disasm(original[offset:offset+4], ENTRY))
    if sum(i.size for i in prefix) != 4:
        raise ValueError('instruction split')
    image = bytearray(original + bytes(TARGET - emulate.FLASH_BASE - len(original)) + candidate)
    image[offset:offset+4] = patch
    return bytes(image)


def changed_ranges(before, after):
    """Enumerate byte differences, including every byte appended beyond EOF."""
    ranges = []
    start = None
    for index in range(max(len(before), len(after)) + 1):
        changed = index < max(len(before), len(after)) and (
            index >= min(len(before), len(after)) or before[index] != after[index])
        if changed and start is None:
            start = index
        elif not changed and start is not None:
            ranges.append({'address': hex(emulate.FLASH_BASE + start), 'bytes': index-start,
                           'before_sha256': build.digest(before[start:index]),
                           'after_sha256': build.digest(after[start:index])})
            start = None
    return ranges


def handler_presets(state, context, valid):
    return [(OWNER, struct.pack('<5I', CONTEXT, INPUT, OUTPUT, 0, FLAG)),
            (CONTEXT, struct.pack('<5I', context, 0, 0, 0x40, 0x1234)),
            (INPUT, struct.pack('<I', 0xff12ff01 if valid else 0)),
            (OUTPUT, bytes([0xa5])*32), (FLAG, b'\x55'),
            (0x20000c19, bytes([state, 0x34, 0x12, 0xab])),
            (0x2000dff8, struct.pack('<I', 0x80))]


def word(memory, address):
    return sum(memory.get(address+i, 0) << (8*i) for i in range(4))


def equivalent(left, right, lmem, rmem):
    return (left['stopped'] == right['stopped'] == 'RETURN' and
            left['r0'] == right['r0'] and lmem == rmem and
            left['mmio'] == right['mmio'] == [] and
            left['sp'] == right['sp'] == emulate.STACK_TOP and
            left['callee_saved_preserved'] and right['callee_saved_preserved'])


def main():
    gcc, objcopy, nm = build.tools()
    folder = ROOT / 'build/session-hybrid'
    folder.mkdir(parents=True, exist_ok=True)
    original = (ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    build.validate_session_literal(original)
    linker = folder/'candidate.ld'
    linker.write_text('SECTIONS { . = 0x08070000; .text : { *(.text.rc_session_state_flag) } /DISCARD/ : { *(.text*) *(.ARM*) *(.comment) } }\n', encoding='utf-8', newline='\n')
    flags = ['-mcpu=cortex-m4', '-mthumb', '-mfloat-abi=soft', '-O2', '-ffreestanding',
             '-fno-builtin', '-ffunction-sections', '-fno-unwind-tables',
             '-fno-asynchronous-unwind-tables', '-nostdlib', '-Wall', '-Wextra',
             '-Werror', '-Wl,--build-id=none']
    elf, binary = folder/'candidate.elf', folder/'candidate.bin'
    build.run([gcc, *flags, '-T', str(linker), str(build.SOURCE), '-o', str(elf)])
    build.run([objcopy, '-O', 'binary', str(elf), str(binary)])
    candidate = binary.read_bytes()
    if build.symbol_table(nm, elf)['rc_session_state_flag'] != TARGET:
        raise RuntimeError('candidate linked at wrong address')
    asm = folder/'patch.s'
    asm.write_text('.syntax unified\n.thumb\n.cpu cortex-m4\n.section .text\nb.w 0x08070000\n', encoding='utf-8', newline='\n')
    build.run([gcc, *flags, '-Wl,-Ttext='+hex(ENTRY), str(asm), '-o', str(folder/'patch.elf')])
    build.run([objcopy, '-O', 'binary', str(folder/'patch.elf'), str(folder/'patch.bin')])
    patch = (folder/'patch.bin').read_bytes()
    hybrid = integrate(original, candidate, patch)
    mutant = bytearray(hybrid)
    mutant[TARGET-emulate.FLASH_BASE:TARGET-emulate.FLASH_BASE+4] = bytes.fromhex('01207047')
    failures, counts, detections = [], {'direct': 0, 'original_handler': 0}, {'direct': 0, 'original_handler': 0}
    for state in range(256):
        cases = [('direct', ENTRY, (c,0,0,0), [(0x20000c19, bytes([state,0x34,0x12,0xab]))], c, True)
                 for c in (state, (state+1)&255, 0, 2, 255, 0x102, 0xffffffff)]
        # Context 2 invokes the unmodelled cleanup subsystem; no stubs or fake returns.
        cases += [('original_handler', CALLER, (OWNER,0,0,0), handler_presets(state,c,v), c,v)
                  for c in (0,1,3,255) for v in (False,True)]
        for kind, entry, args, presets, context, valid in cases:
            left,lmem = build.execute(original, entry, args, presets)
            right,rmem = build.execute(hybrid, entry, args, presets)
            counts[kind] += 1
            expected = build.session_expected(context,state)
            oracle = left['r0'] == right['r0'] == expected if kind == 'direct' else (
                word(lmem, OUTPUT+12) == word(rmem, OUTPUT+12) == expected if valid else
                word(lmem, OUTPUT) == word(rmem, OUTPUT) == 0xe0000006)
            must_visit = kind == 'direct' or valid
            visited = TARGET in right['unique_addresses']
            if not (equivalent(left,right,lmem,rmem) and oracle and visited == must_visit):
                failures.append({'kind':kind,'state':state,'context':context,'valid':valid,
                                 'original':left,'hybrid':right,'oracle':oracle})
            if valid and state == 2:
                wrong,wmem = build.execute(bytes(mutant),entry,args,presets)
                detections[kind] += int(not equivalent(left,wrong,lmem,wmem))
    guards = 0
    for args in ((b'bad',candidate,patch),(original,b'',patch),
                 (original,candidate,b'\x70\x47'),(original,candidate,bytes(4)),
                 (original,bytes(257),patch)):
        try:
            integrate(*args)
        except ValueError:
            guards += 1
    # Explicitly include zero-fill gap: this extended image is an emulator fixture.
    (folder/'EMULATOR_ONLY.bin').write_bytes(hybrid)
    report = {'status':'PASS' if not failures and guards == 5 and all(detections.values()) else 'FAIL',
              'flashable':False, 'image_sha256':build.digest(original),
              'source_sha256':build.digest(build.SOURCE.read_bytes()),
              'harness_sha256':build.digest(Path(__file__).read_bytes()),
              'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
              'flags':flags, 'linker_script':linker.read_text(), 'entry':hex(ENTRY),
              'target':hex(TARGET), 'original_caller':hex(CALLER),
              'candidate_bytes':len(candidate),'candidate_sha256':build.digest(candidate),
              'candidate_hex':candidate.hex(),
              'candidate_disassembly':subprocess.check_output([build.tool(gcc,'objdump'),'-d',str(elf)],text=True),
              'patch_hex':patch.hex(),'hybrid_sha256':build.digest(hybrid),
              'changed_ranges':changed_ranges(original,hybrid), 'cases':counts,
              'constant_one_detections':detections,'guard_rejections':guards,'failures':failures,
              'limitations':['emulator allocation is not proven free physical flash',
                  'no proof excluding incoming edges into overwritten instructions',
                  'original handler context 2 cleanup path excluded; helper context 2 tested directly',
                  'no boot, peripheral, interrupt, timing or physical-device equivalence']}
    (ROOT/'reconstruction/session_hybrid_validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(report['status'],counts,'guards',guards,'mutants',detections)
    return int(report['status'] != 'PASS')


if __name__ == '__main__':
    raise SystemExit(main())
