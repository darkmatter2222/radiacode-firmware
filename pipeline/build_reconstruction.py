"""Build a byte-preserved baseline and test ARM-compiled leaf candidates.

No device writes. The baseline is an original-byte build, not source recovery.
Candidates are tested in separate emulator images and are not patched into a
flashable release. Requires GNU Arm Embedded tools (ARM_GCC may override PATH).
"""
import hashlib
import json
import os
from pathlib import Path
import random
import shutil
import struct
import subprocess
import sys

import config
import emulate
from step15_differential import byte_map_of_native

ROOT = Path(config.ROOT)
BUILD = ROOT / 'build/reconstruction'
SOURCE = ROOT / 'reconstruction/rc102_leaf.c'
REFERENCE_SHA256 = '23c31b7dabc59fe35a698cbd4f690498ded9bbb9f6590f3f2ea72ae5cfd157f6'


def digest(blob):
    return hashlib.sha256(blob).hexdigest()


def tools():
    gcc = os.environ.get('ARM_GCC') or shutil.which('arm-none-eabi-gcc')
    if not gcc:
        raise RuntimeError('ARM compiler unavailable; set ARM_GCC')
    gcc = str(Path(gcc).resolve())
    return gcc, tool(gcc, 'objcopy'), tool(gcc, 'nm')


def tool(gcc, suffix):
    """Sibling tool of the compiler: .../arm-none-eabi-gcc(.exe) -> .../arm-none-eabi-<suffix>."""
    name = Path(gcc).name
    stem = name[:-4] if name.endswith('.exe') else name
    if stem.endswith('gcc'):
        stem = stem[:-3]
    return str(Path(gcc).parent / (stem + suffix))


def run(argv):
    subprocess.run(argv, cwd=ROOT, check=True, capture_output=True, text=True)


def symbol_table(nm, artifact):
    table = {}
    for line in subprocess.check_output([nm, '--defined-only', str(artifact)], text=True).splitlines():
        parts = line.split()
        if len(parts) == 3:
            table[parts[2]] = int(parts[0], 16)
    return table


# Deliberately wrong replacements for the 0x08029370 candidate. Each must be caught by
# the same comparison the correct candidate passes; an undetected variant is a defect of
# the case set, so it fails the build rather than passing silently.
NEGATIVE_SOURCES = {
    'negative_constant_return':
        'unsigned int recovered_08029370(unsigned int c){(void)c;return 0x201u;}',
    'negative_context_low_byte':
        'unsigned int recovered_08029370(unsigned int c){'
        'unsigned int s=*(const unsigned char *)0x20000c0d;'
        'return (c&0xffu)|(s<<8);}',
    'negative_word_load':
        'unsigned int recovered_08029370(unsigned int c){'
        'unsigned int s=*(const unsigned int *)0x20000c0d;'
        'unsigned int m=(c==s)?1u:((s==0u)?1u:0u);'
        'return m|(s<<8);}',
}


def negative_controls(gcc, objcopy, nm, flags, flash):
    """Return per-variant detection counts for the reviewed replacement mechanism."""
    cases = [((context, 0, 0, 0), [(0x20000c0d, bytes([stored, 0x34, 0x12, 0xab]))])
             for stored in (0, 1, 2, 0xff)
             for context in (stored, 0, 2, 0x102, 0xffffffff)]
    results = []
    for name, text in NEGATIVE_SOURCES.items():
        source, elf, binary = BUILD/(name+'.c'), BUILD/(name+'.elf'), BUILD/(name+'.bin')
        source.write_text(text+'\n', encoding='utf-8', newline='\n')
        link_flags = [item for item in flags if not item.startswith('-Wl,-e')]
        run([gcc, *link_flags, '-Wl,-e,recovered_08029370', str(source), '-o', str(elf)])
        run([objcopy, '-O', 'binary', str(elf), str(binary)])
        image = flash + bytes(0x70000-len(flash)) + binary.read_bytes()
        entry = symbol_table(nm, elf)['recovered_08029370']
        detected = 0
        for args, presets in cases:
            left, lmem = execute(flash, 0x08029370, args, presets)
            right, rmem = execute(image, entry, args, presets)
            if not (left['stopped'] == right['stopped'] == 'RETURN' and left['r0'] == right['r0']
                    and lmem == rmem):
                detected += 1
        results.append({'variant': name, 'cases': len(cases), 'detected': detected,
                        'expected': '>=1', 'ok': detected > 0})
    return results


def build_baseline(cfg, gcc, objcopy):
    folder = BUILD / cfg['key']; folder.mkdir(parents=True, exist_ok=True)
    flash = ROOT / cfg['flash']
    asm, elf, binary = folder/'baseline.s', folder/'baseline.elf', folder/'baseline.bin'
    asm.write_text('.section .original,"a"\n.incbin "' + flash.as_posix() + '"\n', encoding='utf-8', newline='\n')
    linker = folder/'baseline.ld'
    linker.write_text('SECTIONS { . = 0x08000000; .original : { *(.original) } }\n', encoding='utf-8', newline='\n')
    run([gcc,'-nostdlib','-Wl,--build-id=none','-T',str(linker),str(asm),'-o',str(elf)])
    run([objcopy,'-O','binary',str(elf),str(binary)])
    original, rebuilt = flash.read_bytes(), binary.read_bytes()
    return {'target': cfg['key'], 'status': 'PASS' if original == rebuilt else 'FAIL',
            'scope': 'original bytes assembled and linked; zero source-recovery credit',
            'original_sha256': digest(original), 'rebuilt_sha256': digest(rebuilt)}


def execute(image, address, args, presets):
    uc, trace = emulate.new_emulator(image)
    emulate.preset(uc, presets)
    result = emulate.run_function(uc, trace, address, args)
    return result, byte_map_of_native(result['writes'])


def main():
    BUILD.mkdir(parents=True, exist_ok=True)
    gcc, objcopy, nm = tools()
    baselines = [build_baseline(config.load(key),gcc,objcopy) for key in config.keys()]
    flash = (ROOT / config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    if digest(flash) != REFERENCE_SHA256:
        raise RuntimeError('reference image changed; review all candidate contracts')
    elf, binary = BUILD/'leaf.elf', BUILD/'leaf.bin'
    flags = ['-mcpu=cortex-m4','-mthumb','-mfloat-abi=soft','-O2','-ffreestanding',
             '-fno-builtin','-fno-unwind-tables','-fno-asynchronous-unwind-tables',
             '-nostdlib','-Wall','-Wextra','-Werror','-Wl,--build-id=none',
             '-Wl,-Ttext=0x08070000','-Wl,-e,recovered_080166ce']
    run([gcc,*flags,str(SOURCE),'-o',str(elf)])
    run([objcopy,'-O','binary',str(elf),str(binary)])
    symbols = symbol_table(nm, elf)
    compiled = flash + bytes(0x70000-len(flash)) + binary.read_bytes()
    cases = []
    for addr in (0x080166ce,0x08017ef2,0x08017ef6):
        cases.append((addr,'recovered_%08x'%addr,(0,0,0,0),[]))
    corners = [0,1,0x7fffffff,0x80000000,0xffffffff]
    pairs = [(a,b) for a in corners for b in corners]
    rng = random.Random(0x5243)
    pairs += [(rng.getrandbits(32),rng.getrandbits(32)) for _ in range(128)]
    for mode in (0,1,2,3,4,5,6,255):
        for head,tail in pairs:
            cases.append((0x08017eb4,'recovered_08017eb4',(0,0,0,0),
                          [(0x20000d7d,bytes([mode])),(0x20000dbc,struct.pack('<II',head,tail))]))
    for value in corners + [rng.getrandbits(32) for _ in range(128)]:
        cases.append((0x080275c4,'recovered_item_502',(0x20000400,0x502,0,0),
                      [(0x20000408,struct.pack('<I',0x20000600)),(0x20000cc0,struct.pack('<I',value))]))
    # All valid ring-index pairs, including empty/full and wraparound, with
    # high-halfword inputs that must be truncated by the original STRH.
    for write_index in range(16):
        for read_index in range(16):
            ring = struct.pack('<16HII', *range(0x9000,0x9010), write_index, read_index)
            for event_code in (0,1,0x7fff,0xffff,0x10000,0xdeadbeef):
                cases.append((0x08016862,'recovered_08016862',(event_code,0,0,0),[(0x2000f424,ring)]))
            cases.append((0x080168a0,'recovered_080168a0',(0,0,0,0),[(0x2000f424,ring)]))
    # Original 0x08029370: stored state byte S at 0x20000c0d (literal 0x080293fc ->
    # 0x20000c0c), compared context word in r0. Every S value runs with its own equality
    # case, the adjacent value, zero and out-of-byte context words. Trailing non-zero
    # bytes in the preset make the byte-vs-word load width observable in this routine.
    for stored in range(256):
        for context in (stored,(stored+1)&0xff,0,2,0xff,0x102,0xffffffff):
            cases.append((0x08029370,'recovered_08029370',(context,0,0,0),
                          [(0x20000c0d,bytes([stored,0x34,0x12,0xab]))]))
    for _ in range(128):
        cases.append((0x08029370,'recovered_08029370',(rng.getrandbits(32),0,0,0),
                      [(0x20000c0d,bytes([rng.randrange(256),0x34,0x12,0xab]))]))
    negatives = negative_controls(gcc, objcopy, nm, flags, flash)
    failures, addresses = [], set()
    for index,(original,name,args,presets) in enumerate(cases):
        left,lmem = execute(flash,original,args,presets)
        right,rmem = execute(compiled,symbols[name],args,presets)
        addresses.update(left['unique_addresses'])
        if not (left['stopped'] == right['stopped'] == 'RETURN' and left['r0'] == right['r0']
                and lmem == rmem and left['mmio'] == right['mmio']
                and left['sp'] == right['sp'] == emulate.STACK_TOP
                and left['callee_saved_preserved'] and right['callee_saved_preserved']):
            failures.append({'case':index,'function':name,'args':args,
                             'presets':[(a,b.hex()) for a,b in presets],
                             'original':left,'compiled':right})
    report = {'status':'FAIL' if failures or negatives and not all(n['ok'] for n in negatives)
                      or any(b['status']!='PASS' for b in baselines) else 'PASS',
              'scope':'eight compiled candidates, including one partial dispatcher path, two '
                      'event-ring routines and one return-only state helper; not complete firmware',
              'source_sha256':digest(SOURCE.read_bytes()),'image_sha256':digest(flash),
              'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
              'flags':flags,'compiled_binary_sha256':digest(binary.read_bytes()),
              'compiled_disassembly':subprocess.check_output(
                  [tool(gcc,'objdump'),'-d',str(elf)],text=True),
              'cases':len(cases),'passed':len(cases)-len(failures),'unique_original_instructions':len(addresses),
              'functions':symbols,'negative_controls':negatives,'failures':failures,'baselines':baselines}
    out = ROOT/'reconstruction/validation.json'; out.write_text(json.dumps(report,indent=2)+'\n', encoding='utf-8', newline='\n')
    print(report['status'],report['passed'],'/',report['cases'],'compiled ARM differential cases')
    return int(report['status']!='PASS')


if __name__ == '__main__':
    raise SystemExit(main())
