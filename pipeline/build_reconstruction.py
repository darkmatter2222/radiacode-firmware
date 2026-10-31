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
    gcc = Path(gcc).resolve()
    prefix = str(gcc).removesuffix('gcc')
    return str(gcc), prefix + 'objcopy', prefix + 'nm'


def run(argv):
    subprocess.run(argv, cwd=ROOT, check=True, capture_output=True, text=True)


def build_baseline(cfg, gcc, objcopy):
    folder = BUILD / cfg['key']; folder.mkdir(parents=True, exist_ok=True)
    flash = ROOT / cfg['flash']
    asm, elf, binary = folder/'baseline.s', folder/'baseline.elf', folder/'baseline.bin'
    asm.write_text('.section .original,"a"\n.incbin "' + flash.as_posix() + '"\n')
    linker = folder/'baseline.ld'
    linker.write_text('SECTIONS { . = 0x08000000; .original : { *(.original) } }\n')
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
    symbols = {}
    listing = subprocess.check_output([nm,'--defined-only',str(elf)],text=True)
    for line in listing.splitlines():
        parts = line.split()
        if len(parts) == 3: symbols[parts[2]] = int(parts[0],16)
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
    report = {'status':'FAIL' if failures or any(b['status']!='PASS' for b in baselines) else 'PASS',
              'scope':'five compiled candidates, including one partial dispatcher path; not complete firmware',
              'source_sha256':digest(SOURCE.read_bytes()),'image_sha256':digest(flash),
              'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
              'flags':flags,'compiled_binary_sha256':digest(binary.read_bytes()),
              'cases':len(cases),'passed':len(cases)-len(failures),'unique_original_instructions':len(addresses),
              'functions':symbols,'failures':failures,'baselines':baselines}
    out = ROOT/'reconstruction/validation.json'; out.write_text(json.dumps(report,indent=2)+'\n')
    print(report['status'],report['passed'],'/',report['cases'],'compiled ARM differential cases')
    return int(report['status']!='PASS')


if __name__ == '__main__':
    raise SystemExit(main())
