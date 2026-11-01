"""Emulator-only branch replacement experiment. Never a flashable release."""
import json
from pathlib import Path
import random
import struct
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'pipeline'))
import build_reconstruction as build
import config
import emulate

ENTRY=0x08017eb4
TARGET=0x08070000
CALLER=0x08071000


def checked_patch(original, extended, patch):
    if build.digest(original)!=build.REFERENCE_SHA256:
        raise ValueError('unreviewed original image')
    if len(patch)!=4 or len(extended)>emulate.FLASH_SIZE:
        raise ValueError('invalid patch/image size')
    if extended[:len(original)]!=original:
        raise ValueError('extended image modifies original bytes')
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
    cs=Cs(CS_ARCH_ARM,CS_MODE_THUMB)
    decoded=list(cs.disasm(patch,ENTRY))
    if len(decoded)!=1 or decoded[0].mnemonic!='b.w' or decoded[0].op_str!=hex(TARGET):
        # Capstone prints immediate targets with a leading #.
        if len(decoded)!=1 or decoded[0].mnemonic!='b.w' or decoded[0].op_str!='#'+hex(TARGET):
            raise ValueError('patch must be a single unconditional branch to reviewed candidate')
    prefix=list(cs.disasm(original[ENTRY-emulate.FLASH_BASE:ENTRY-emulate.FLASH_BASE+4],ENTRY))
    if sum(i.size for i in prefix)!=4:raise ValueError('patch cuts an instruction')
    hybrid=bytearray(extended);offset=ENTRY-emulate.FLASH_BASE
    hybrid[offset:offset+4]=patch
    return bytes(hybrid)


def main():
    gcc,objcopy,nm=build.tools()
    folder=ROOT/'build/hybrid';folder.mkdir(parents=True,exist_ok=True)
    original=(ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    # Only the complete transfer-state leaf is eligible. Partial dispatcher
    # and floating-point candidates deliberately have no replacement path.
    source=folder/'candidate.c'
    source.write_text((ROOT/'reconstruction/rc102_leaf.c').read_text(encoding='utf-8'), encoding='utf-8', newline='\n')
    # Put each function in its own section so the linker can place the reviewed
    # function exactly, independent of compiler ordering of other functions.
    linker=folder/'candidate.ld'
    linker.write_text('SECTIONS { . = 0x08070000; .text : { *(.text.rc_transfer_positions_allow_progress) } /DISCARD/ : { *(.text*) *(.ARM*) *(.comment) } }', encoding='utf-8', newline='\n')
    flags=['-mcpu=cortex-m4','-mthumb','-O2','-ffreestanding','-fno-builtin','-ffunction-sections',
           '-fno-unwind-tables','-fno-asynchronous-unwind-tables','-nostdlib','-Wl,--build-id=none']
    build.run([gcc,*flags,'-T',str(linker),str(source),'-o',str(folder/'candidate.elf')])
    build.run([objcopy,'-O','binary',str(folder/'candidate.elf'),str(folder/'candidate.bin')])
    candidate=(folder/'candidate.bin').read_bytes()
    def assemble(name,text,address):
        asm=folder/(name+'.s');asm.write_text('.syntax unified\n.thumb\n.cpu cortex-m4\n.section .text\n'+text+'\n', encoding='utf-8', newline='\n')
        elf=folder/(name+'.elf');binary=folder/(name+'.bin')
        build.run([gcc,*flags,'-Wl,-Ttext='+hex(address),str(asm),'-o',str(elf)])
        build.run([objcopy,'-O','binary',str(elf),str(binary)])
        return binary.read_bytes()
    patch=assemble('patch','b.w '+hex(TARGET),ENTRY)
    caller=assemble('caller','push {r4, lr}\nbl '+hex(ENTRY)+'\npop {r4, pc}',CALLER)
    extended=original+bytes(TARGET-emulate.FLASH_BASE-len(original))+candidate
    extended+=bytes(CALLER-emulate.FLASH_BASE-len(extended))+caller
    hybrid=checked_patch(original,extended,patch)
    # Guards are negative tests, not silently accepted alternative inputs.
    rejected=0
    for bad_original,bad_extended,bad_patch in [(b'bad',extended,patch),(original,extended,b'\x70\x47'),(original,extended,b'\x00\x00\x00\x00'),(original,b'bad',patch)]:
        try:checked_patch(bad_original,bad_extended,bad_patch)
        except ValueError:rejected+=1
    rng=random.Random(0x17eb4);corners=[0,1,0x7fffffff,0x80000000,0xffffffff]
    pairs=[(a,b) for a in corners for b in corners]+[(rng.getrandbits(32),rng.getrandbits(32)) for _ in range(64)]
    failures=[];total=0;paths=set();mutant_detected=False
    mutant=bytearray(hybrid);offset=ENTRY-emulate.FLASH_BASE;mutant[offset:offset+4]=bytes.fromhex('00207047')
    for mode in (0,1,2,3,4,5,6,255):
        for head,tail in pairs:
            presets=[(0x20000d7d,bytes([mode])),(0x20000dbc,struct.pack('<II',head,tail))]
            for entry in (ENTRY,CALLER):
                left,lmem=build.execute(extended,entry,(0,0,0,0),presets)
                right,rmem=build.execute(hybrid,entry,(0,0,0,0),presets)
                paths.update(right['unique_addresses']);total+=1
                if not(left['stopped']==right['stopped']=='RETURN' and left['r0']==right['r0'] and lmem==rmem and left['mmio']==right['mmio'] and left['sp']==right['sp']==emulate.STACK_TOP and left['callee_saved_preserved'] and right['callee_saved_preserved']):
                    failures.append({'mode':mode,'head':head,'tail':tail,'entry':entry})
                if not mutant_detected and left['r0']==1:
                    wrong,_=build.execute(bytes(mutant),entry,(0,0,0,0),presets)
                    mutant_detected=wrong['r0']!=left['r0']
    report={'status':'PASS' if not failures and rejected==4 and mutant_detected and TARGET in paths else 'FAIL',
            'scope':'one complete leaf, direct entry and synthetic BL caller; emulator only, not system/hardware equivalence',
            'source_sha256':build.digest((ROOT/'reconstruction/rc102_leaf.c').read_bytes()),
            'harness_sha256':build.digest(Path(__file__).read_bytes()),'image_sha256':build.digest(original),
            'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
            'flags':flags,'candidate_sha256':build.digest(candidate),'patch_hex':patch.hex(),
            'original_prefix_hex':original[offset:offset+4].hex(),'entry':ENTRY,'target':TARGET,
            'caller':CALLER,'hybrid_sha256':build.digest(hybrid),'cases':total,'failures':failures,
            'guard_rejections':rejected,'incorrect_return_mutation_detected':mutant_detected,
            'flashable':False,'limitations':['synthetic appended code addresses are not proven free on device','no incoming interior-edge proof','no interrupts, peripherals, startup or physical tests']}
    (ROOT/'reconstruction/hybrid_validation.json').write_text(json.dumps(report,indent=2)+'\n', encoding='utf-8', newline='\n')
    print(report['status'],total,'direct/caller cases; guard rejections',rejected)
    return int(report['status']!='PASS')
if __name__=='__main__':raise SystemExit(main())
