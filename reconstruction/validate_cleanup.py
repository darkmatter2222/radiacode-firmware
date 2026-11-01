"""Original cleanup chain versus compiled C, with bounded acyclic-list contracts."""
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
from validate_session_hybrid import equivalent, handler_presets, CALLER, OWNER

NODE, HEAD, FLAG = 0x20000858, 0x2000dfa8, 0x20004400
SOURCE=ROOT/'reconstruction/rc102_cleanup.c'


def presets(nodes,bits):
    pairs=[(0x20000918,struct.pack('<I',FLAG)),(FLAG,b'\xff'),
           (0x2000dfd0,struct.pack('<6I',bits,0,0,0,0,0xdeadbeef)),
           (HEAD,struct.pack('<I',nodes[0] if nodes else 0)),
           (NODE,struct.pack('<4I',0x11111111,0,0x22222222,0xffffffff))]
    pairs += [(node,struct.pack('<4I',0x11111111,nodes[i+1] if i+1<len(nodes) else 0,
                                 0x22222222,0xffffffff)) for i,node in enumerate(nodes)]
    return pairs


def main():
    gcc,objcopy,nm=build.tools();folder=ROOT/'build/cleanup';folder.mkdir(parents=True,exist_ok=True)
    original=(ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    if build.digest(original)!=build.REFERENCE_SHA256:raise ValueError('unreviewed image')
    flags=['-mcpu=cortex-m4','-mthumb','-O2','-ffreestanding','-fno-builtin','-nostdlib',
           '-fno-unwind-tables','-fno-asynchronous-unwind-tables','-Wall','-Wextra','-Werror',
           '-Wl,--build-id=none','-Wl,-Ttext=0x08070000','-Wl,-e,rc_session_cleanup']
    elf,binary=folder/'cleanup.elf',folder/'cleanup.bin'
    build.run([gcc,*flags,str(SOURCE),'-o',str(elf)])
    build.run([objcopy,'-O','binary',str(elf),str(binary)])
    candidate=binary.read_bytes();compiled=original+bytes(0x70000-len(original))+candidate
    entry=build.symbol_table(nm,elf)['rc_session_cleanup']
    mutant_source=folder/'mutant.c'
    mutant_source.write_text(SOURCE.read_text().replace('bits & ~4u','bits'),encoding='utf-8',newline='\n')
    build.run([gcc,*flags,str(mutant_source),'-o',str(folder/'mutant.elf')])
    build.run([objcopy,'-O','binary',str(folder/'mutant.elf'),str(folder/'mutant.bin')])
    mutant=original+bytes(0x70000-len(original))+(folder/'mutant.bin').read_bytes()
    mutant_entry=build.symbol_table(nm,folder/'mutant.elf')['rc_session_cleanup']
    patch_source=folder/'patch.s'
    patch_source.write_text('.syntax unified\n.thumb\n.cpu cortex-m4\n.section .text\nb.w 0x08070000\n',encoding='utf-8',newline='\n')
    patch_flags=[f for f in flags if not f.startswith('-Wl,-Ttext') and not f.startswith('-Wl,-e')]
    build.run([gcc,*patch_flags,'-Wl,-Ttext=0x08029086',str(patch_source),'-o',str(folder/'patch.elf')])
    build.run([objcopy,'-O','binary',str(folder/'patch.elf'),str(folder/'patch.bin')])
    patch=(folder/'patch.bin').read_bytes()
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
    decoded=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(patch,0x08029086))
    if len(patch)!=4 or len(decoded)!=1 or decoded[0].mnemonic!='b.w' or decoded[0].op_str!='#0x8070000':
        raise ValueError('invalid cleanup branch')
    hybrid=bytearray(compiled);hybrid[0x29086:0x2908a]=patch;hybrid=bytes(hybrid)
    failures=[];total=0;detected=0;caller_cases=0
    for size in range(9):
        others=[0x20005000+32*i for i in range(size)]
        for position in range(-1,size+1):
            nodes=others.copy()
            if position>=0:nodes.insert(position,NODE)
            for bits in (0,4,0x80000004,0xffffffff):
                pairs=presets(nodes,bits)
                left,lmem=build.execute(original,0x08029086,(0,0,0,0),pairs)
                right,rmem=build.execute(compiled,entry,(0,0,0,0),pairs)
                total+=1
                wrong,wmem=build.execute(mutant,mutant_entry,(0,0,0,0),pairs)
                detected += int(not equivalent(left,wrong,lmem,wmem))
                expected={FLAG:0,NODE+12:0,**{NODE+4+i:0 for i in range(4)}}
                for address,value in [(0x2000dfd0,bits&~4),(0x2000dfe4,0)]:
                    expected.update({address+i:(value>>(8*i))&255 for i in range(4)})
                if NODE in nodes:
                    index=nodes.index(NODE)
                    address=HEAD if index==0 else nodes[index-1]+4
                    value=nodes[index+1] if index+1<len(nodes) else 0
                    expected.update({address+i:(value>>(8*i))&255 for i in range(4)})
                if not(equivalent(left,right,lmem,rmem) and left['r0']==NODE and lmem==expected):
                    failures.append({'size':size,'position':position,'bits':bits,'original':left,'compiled':right})
                for state in (0,2):
                    initial=handler_presets(state,2,True)+pairs
                    a,am=build.execute(original,CALLER,(OWNER,0,0,0),initial)
                    b,bm=build.execute(hybrid,CALLER,(OWNER,0,0,0),initial)
                    caller_cases+=1
                    if not(equivalent(a,b,am,bm) and entry in b['unique_addresses']):
                        failures.append({'caller':True,'size':size,'position':position,'state':state})
    report={'status' :'FAIL' if failures or not detected else 'PASS','flashable':False,'cases':total,'original_handler_cases':caller_cases,
            'patch_hex':patch.hex(),'hybrid_sha256':build.digest(hybrid),'failures':failures,
            'missing_bit_clear_mutation_detections':detected,
            'scope':'complete sequential cleanup chain, valid acyclic lists of up to nine nodes',
            'original_entries':['0x08029086','0x08022e60','0x08016780'],
            'source_sha256':build.digest(SOURCE.read_bytes()),'image_sha256':build.digest(original),
            'harness_sha256':build.digest(Path(__file__).read_bytes()),
            'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
            'flags':flags,'candidate_hex':candidate.hex(),'candidate_sha256':build.digest(candidate),
            'limitations':['no concurrency or interrupts','invalid pointers and cyclic lists outside contract',
                           'handler uses original state helper and compiled cleanup; simultaneous replacement not tested']}
    (ROOT/'reconstruction/cleanup_validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(report['status'],total,'cleanup cases')
    return int(report['status']!='PASS')
if __name__=='__main__':raise SystemExit(main())
