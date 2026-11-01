"""Recovered response finalization, including original dispatch-to-finalizer path."""
import json
from pathlib import Path
import struct
import subprocess
import sys
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'pipeline'))
import build_reconstruction as build
import config
import emulate
import validate_dispatch as dispatch
from validate_session_hybrid import handler_presets, equivalent, changed_ranges, OWNER, CONTEXT, OUTPUT, word
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
SOURCE=ROOT/'reconstruction/rc102_finalize.c'
ENTRY,TARGET,STOP=0x080273a2,0x08070400,0x0802732a
BUFFER=OUTPUT-4


def initial_state(state,context,valid,capacity,flags):
    return handler_presets(state,context,valid)+[(CONTEXT+8,struct.pack('<I',BUFFER)),
        (CONTEXT+16,struct.pack('<I',capacity)),(0x2000dff4,struct.pack('<I',flags))]


def main():
    if dispatch.main()!=0:raise RuntimeError('dispatch prerequisites failed')
    gcc,objcopy,nm=build.tools();folder=ROOT/'build/finalize';folder.mkdir(parents=True,exist_ok=True)
    original=(ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    flags=['-mcpu=cortex-m4','-mthumb','-O2','-ffreestanding','-fno-builtin','-nostdlib',
        '-fno-unwind-tables','-fno-asynchronous-unwind-tables','-Wall','-Wextra','-Werror','-Wl,--build-id=none']
    elf,binary=folder/'finalize.elf',folder/'finalize.bin'
    build.run([gcc,*flags,'-Wl,-Ttext='+hex(TARGET),'-Wl,-e,rc_finalize_response',str(SOURCE),'-o',str(elf)])
    build.run([objcopy,'-O','binary',str(elf),str(binary)])
    candidate=binary.read_bytes()
    if build.symbol_table(nm,elf)['rc_finalize_response']!=TARGET:raise ValueError('placement')
    compiled=original+bytes(TARGET-emulate.FLASH_BASE-len(original))+candidate
    evidence=json.loads((ROOT/'reconstruction/handshake_validation.json').read_text())
    body=bytes.fromhex(evidence['candidate_hex'])
    if len(body)>0x400:raise ValueError('handler overlaps finalizer')
    hybrid=bytearray(original+bytes(0x70000-len(original))+body)
    for patch in evidence['patches']:
        offset=int(patch['entry'],16)-emulate.FLASH_BASE
        hybrid[offset:offset+4]=bytes.fromhex(patch['bytes'])
    hybrid+=bytes(TARGET-emulate.FLASH_BASE-len(hybrid))+candidate
    asm=folder/'patch.s';asm.write_text('.syntax unified\n.thumb\n.cpu cortex-m4\n.section .text\nb.w '+hex(TARGET)+'\n',encoding='utf-8',newline='\n')
    build.run([gcc,*flags,'-Wl,-Ttext='+hex(ENTRY),str(asm),'-o',str(folder/'patch.elf')])
    build.run([objcopy,'-O','binary',str(folder/'patch.elf'),str(folder/'patch.bin')])
    patch=(folder/'patch.bin').read_bytes();decoded=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(patch,ENTRY))
    prefix=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(original[0x273a2:0x273a6],ENTRY))
    if len(patch)!=4 or len(decoded)!=1 or decoded[0].mnemonic!='b.w' or decoded[0].op_str!='#'+hex(TARGET) or sum(i.size for i in prefix)!=4:raise ValueError('invalid patch')
    hybrid[0x273a2:0x273a6]=patch;hybrid=bytes(hybrid)
    failures=[];direct=0;integrated=0;detections=0
    values=(0,1,3,4,15,16,0x80000000,0xffffffff)
    for length in values:
        for capacity in values:
            for first in (0,0x80000007,0xffffffff):
                for bits in (0,0x1f000000,0xffffffff):
                    initial=initial_state(2,2,True,capacity,bits)+[(OWNER+8,struct.pack('<I',(OUTPUT+length)&0xffffffff)),(OUTPUT,struct.pack('<I',first))]
                    a,am=build.execute(original,ENTRY,(OWNER,0,0,0),initial)
                    b,bm=build.execute(compiled,TARGET,(OWNER,0,0,0),initial);direct+=1
                    overflow=length>capacity;size=4 if overflow else length
                    expected={}
                    for addr,value in ((OWNER+8,OUTPUT),(BUFFER,size),(OUTPUT,(0xe0000007 if overflow else first)|bits)):
                        expected.update({addr+i:v for i,v in enumerate(struct.pack('<I',value))})
                    if not(equivalent(a,b,am,bm) and am==expected and a['r0']==bits):
                        failures.append({'direct':True,'length':length,'capacity':capacity,'first':first,'flags':bits})
    mutant=bytearray(hybrid);mutant[0x70400:0x70404]=bytes.fromhex('00207047')
    for table in dispatch.TABLES:
        for state in (0,1,2,255):
            for context in (0,1,2,3,255):
                for capacity in (0,3,4,15,16,17,0xffffffff):
                    for valid in (False,True):
                        for bits in (0,0x01000000,0x1f000000):
                            initial=initial_state(state,context,valid,capacity,bits)
                            a=dispatch.run_slice(original,table,initial,stop=STOP)
                            b=dispatch.run_slice(hybrid,table,initial,stop=STOP);integrated+=1
                            size=16 if valid else 4;overflow=size>capacity
                            expected_first=(0xe0000007 if overflow else (0x80000007 if valid else 0xe0000006))|bits
                            fields=('stop','pc','r0','sp','saved','writes','ram_sha256','mmio')
                            ok=(all(a[k]==b[k] for k in fields) and b['stop']=='BOUNDARY_REACHED'
                                and b['saved'] and b['sp']==emulate.STACK_TOP and not b['mmio']
                                and TARGET in b['addresses'] and 0x08070200 in b['addresses']
                                and word(b['writes'],BUFFER)==(4 if overflow else size)
                                and word(b['writes'],OUTPUT)==expected_first)
                            if not ok:failures.append({'table':table,'state':state,'context':context,'capacity':capacity,'valid':valid,'flags':bits})
                            if state==2 and context==2 and capacity==16 and valid and bits==0:
                                wrong=dispatch.run_slice(bytes(mutant),table,initial,stop=STOP)
                                detections+=int(wrong['writes']!=a['writes'])
    report={'status':'PASS' if not failures and detections==2 else 'FAIL','flashable':False,
        'direct_cases':direct,'dispatch_cases':integrated,'failures':failures,'mutation_detections':detections,
        'source_sha256':build.digest(SOURCE.read_bytes()),'harness_sha256':build.digest(Path(__file__).read_bytes()),
        'image_sha256':build.digest(original),'hybrid_sha256':build.digest(hybrid),
        'handler_validation_sha256':build.digest((ROOT/'reconstruction/handshake_validation.json').read_bytes()),
        'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
        'flags':flags+['-Wl,-Ttext='+hex(TARGET),'-Wl,-e,rc_finalize_response'],
        'candidate_hex':candidate.hex(),'patch_hex':patch.hex(),'changed_ranges':changed_ranges(original,hybrid),
        'boundary_stop':hex(STOP),'limitations':['capacity check happens after payload writes; no buffer-safety claim',
            'upstream frame handling and transport callbacks not tested','no interrupts or hardware/recovery validation']}
    (ROOT/'reconstruction/finalize_validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(report['status'],direct,'direct finalizer;',integrated,'dispatch-through-finalizer cases')
    return int(report['status']!='PASS')
if __name__=='__main__':raise SystemExit(main())
