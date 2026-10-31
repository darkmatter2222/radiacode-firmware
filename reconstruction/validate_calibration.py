"""Original-vs-compiled VFP predicate checks. No hardware or whole-image claim."""
import hashlib
import itertools
import json
import os
from pathlib import Path
import random
import struct
import subprocess
import sys
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'pipeline'))
import build_reconstruction as build
import config
import emulate
from unicorn.arm_const import UC_ARM_REG_FPSCR


def cases():
    # Exact encodings: zeros, subnormals, infinities, qNaN/sNaN and thresholds.
    special = [0,0x80000000,1,0x80000001,0x007fffff,0x00800000,
               0x7f7fffff,0xff7fffff,0x7f800000,0xff800000,
               0x7fc00001,0xffc00001,0x7f800001,0xff800001]
    def bits(f): return struct.unpack('<I',struct.pack('<f',f))[0]
    ordinary = [bits(f) for f in (-30.,-1.,1.,4.,8.,15.625,30.)]
    axes = special + ordinary
    yield from itertools.product(axes, repeat=3)
    # One-ULP neighborhoods at every comparison boundary.
    for offset in (-2,-1,0,1,2):
        for a,b,c in [(bits(30.000001907348633)+offset,bits(8.),0),
                      (0,bits(4.)+offset,0),(0,bits(7.8125)+offset,0),
                      (0,bits(15.625000953674316)+offset,0)]:
            yield a,b,c
    rng=random.Random(0x2abf8)
    for _ in range(1024): yield tuple(rng.getrandbits(32) for _ in range(3))


def execute(image, address, data, fpscr):
    uc,trace=emulate.new_emulator(image)
    uc.mem_write(0x20000400,data)
    uc.reg_write(UC_ARM_REG_FPSCR,fpscr)
    result=emulate.run_function(uc,trace,address,(0x20000400,0,0,0))
    # Predicate output/memory/ABI contract. FPSCR exception flags recorded but
    # not claimed equivalent: VCMP operand ordering can change signaling effects.
    return result, uc.reg_read(UC_ARM_REG_FPSCR), sorted(set(trace.reads))


def main():
    gcc,objcopy,nm=build.tools()
    cfg=config.load('rc-102/hw1-fw4.14')
    flash=(ROOT/cfg['flash']).read_bytes()
    if build.digest(flash)!=build.REFERENCE_SHA256: raise ValueError('image changed')
    folder=ROOT/'build/calibration';folder.mkdir(parents=True,exist_ok=True)
    source=ROOT/'reconstruction/calibration.c'
    flags=['-mcpu=cortex-m4','-mthumb','-mfpu=fpv4-sp-d16','-mfloat-abi=softfp',
           '-ffp-contract=off','-fno-fast-math','-O2','-ffreestanding','-nostdlib',
           '-Wall','-Wextra','-Werror','-Wl,--build-id=none',
           '-Wl,-Ttext=0x08070000','-Wl,-e,recovered_0802abf8']
    build.run([gcc,*flags,str(source),'-o',str(folder/'test.elf')])
    build.run([objcopy,'-O','binary',str(folder/'test.elf'),str(folder/'test.bin')])
    symbols={p[2]:int(p[0],16) for line in subprocess.check_output([nm,'--defined-only',str(folder/'test.elf')],text=True).splitlines() if len(p:=line.split())==3}
    compiled=flash+bytes(0x70000-len(flash))+(folder/'test.bin').read_bytes()
    failures=[];counterexamples=[];fp_flag_differences=0;covered=set();total=0
    modes=[0,1<<22,2<<22,3<<22,1<<24,1<<25,(1<<24)|(1<<25)]
    for case,words in enumerate(cases()):
        data=struct.pack('<III',*words)
        # Full special Cartesian corpus in default mode; stratified sample in
        # all rounding modes and flush-to-zero/default-NaN configurations.
        for mode in modes if case%97==0 else [0]:
            left,lf,lr=execute(flash,0x0802abf8,data,mode)
            right,rf,rr=execute(compiled,symbols['recovered_0802abf8'],data,mode)
            total+=1;covered.update(left['unique_addresses'])
            ok=(left['stopped']==right['stopped']=='RETURN' and left['r0']==right['r0']
                and left['writes']==right['writes']==[] and left['mmio']==right['mmio']==[]
                and left['sp']==right['sp']==emulate.STACK_TOP
                and left['callee_saved_preserved'] and right['callee_saved_preserved'])
            fp_flag_differences += (lf & 0x9f)!=(rf & 0x9f)
            if not ok and len(failures)<30: failures.append({'words':list(map(hex,words)),'fpscr':mode,'original':left,'compiled':right})
            if case%97==0 and len(counterexamples)<8:
                wrong,_,_=execute(compiled,symbols['ordered_transcription'],data,mode)
                if wrong['r0']!=left['r0']:counterexamples.append({'words':list(map(hex,words)),'fpscr':mode,'original':left['r0'],'ordered_transcription':wrong['r0']})
    report={'status':'FAIL' if failures or not counterexamples else 'PASS','scope':'0x0802abf8 predicate return, writes, stack and callee-saved ABI; not FPSCR equivalence or firmware certification',
            'image_sha256':build.digest(flash),'source_sha256':build.digest(source.read_bytes()),
            'harness_sha256':build.digest(Path(__file__).read_bytes()),'flags':flags,
            'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
            'binary_sha256':build.digest((folder/'test.bin').read_bytes()),'cases':total,
            'original_instruction_addresses':sorted(covered),'fpscr_exception_flag_differences':fp_flag_differences,
            'failures':failures,'ordered_transcription_counterexamples':counterexamples}
    (ROOT/'reconstruction/calibration_validation.json').write_text(json.dumps(report,indent=2)+'\n')
    print(report['status'],total,'cases; FPSCR differences',fp_flag_differences,'; negative oracle counterexamples',len(counterexamples))
    return int(report['status']!='PASS')
if __name__=='__main__':raise SystemExit(main())
