"""Complete compiled handshake handler and recovered callees; never a device release."""
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
from validate_cleanup import presets, NODE
from validate_session_hybrid import handler_presets, equivalent, changed_ranges, CALLER, OWNER, OUTPUT, word
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB


def main():
    gcc,objcopy,nm=build.tools();folder=ROOT/'build/handshake';folder.mkdir(parents=True,exist_ok=True)
    original=(ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    if build.digest(original)!=build.REFERENCE_SHA256:raise ValueError('unreviewed image')
    linker=folder/'combined.ld'
    linker.write_text('SECTIONS { . = 0x08070000; .session : { *(.text.rc_session_state_flag) } ASSERT(SIZEOF(.session) <= 256, "session overlap") . = 0x08070100; .cleanup : { *(.text.rc_session_cleanup) } ASSERT(SIZEOF(.cleanup) <= 256, "cleanup overflow") . = 0x08070200; .handler : { *(.text.rc_handshake_handler) } ASSERT(SIZEOF(.handler) <= 512, "handler overflow") /DISCARD/ : { *(.text*) *(.ARM*) *(.comment) } }\n',encoding='utf-8',newline='\n')
    flags=['-mcpu=cortex-m4','-mthumb','-mfloat-abi=soft','-O2','-ffreestanding','-fno-builtin',
           '-ffunction-sections','-nostdlib','-fno-unwind-tables','-fno-asynchronous-unwind-tables',
           '-Wall','-Wextra','-Werror','-Wl,--build-id=none']
    sources=[ROOT/'reconstruction/rc102_leaf.c',ROOT/'reconstruction/rc102_cleanup.c',ROOT/'reconstruction/rc102_handshake.c']
    elf,binary=folder/'combined.elf',folder/'combined.bin'
    build.run([gcc,*flags,'-T',str(linker),*[str(p) for p in sources],'-o',str(elf)])
    build.run([objcopy,'-O','binary',str(elf),str(binary)])
    body=binary.read_bytes();symbols=build.symbol_table(nm,elf)
    if symbols['rc_session_state_flag']!=0x08070000 or symbols['rc_session_cleanup']!=0x08070100 or symbols['rc_handshake_handler']!=0x08070200:
        raise ValueError('unexpected placement')
    hybrid=bytearray(original+bytes(0x70000-len(original))+body);patches=[]
    for entry,target in ((CALLER,0x08070200),):
        asm=folder/'patch.s';pe=folder/'patch.elf';pb=folder/'patch.bin'
        asm.write_text('.syntax unified\n.thumb\n.cpu cortex-m4\n.section .text\nb.w '+hex(target)+'\n',encoding='utf-8',newline='\n')
        build.run([gcc,*flags,'-Wl,-Ttext='+hex(entry),str(asm),'-o',str(pe)])
        build.run([objcopy,'-O','binary',str(pe),str(pb)])
        patch=pb.read_bytes();decoded=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(patch,entry))
        offset=entry-emulate.FLASH_BASE
        prefix=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(original[offset:offset+4],entry))
        if len(patch)!=4 or len(decoded)!=1 or decoded[0].mnemonic!='b.w' or decoded[0].op_str!='#'+hex(target) or sum(i.size for i in prefix)!=4:
            raise ValueError('invalid branch or split instruction')
        hybrid[offset:offset+4]=patch;patches.append({'entry':hex(entry),'target':hex(target),'bytes':patch.hex()})
    hybrid=bytes(hybrid);failures=[];total=0;mutations={'session':0,'cleanup':0,'handler':0}
    for size in range(5):
        others=[0x20005000+32*i for i in range(size)]
        for position in range(-1,size+1):
            nodes=others.copy()
            if position>=0:nodes.insert(position,NODE)
            for bits in (0,4,0x80000004,0xffffffff):
                for state in (0,1,2,255):
                    for context in (0,1,2,3,255):
                        for valid in (False,True):
                            initial=handler_presets(state,context,valid)+presets(nodes,bits)
                            metadata_a=(bits+position)&0xffffffff
                            metadata_b=(state*0x01010101)&0xffffffff
                            initial += [(0x2000410c,struct.pack('<II',metadata_a,metadata_b)),
                                        (0x2000082d,bytes([state]))]
                            args=(OWNER,0x1234,0xabcd,bits)
                            a,am=build.execute(original,CALLER,args,initial)
                            b,bm=build.execute(hybrid,CALLER,args,initial);total+=1
                            oracle=word(bm,OUTPUT+12)==build.session_expected(context,state) if valid else word(bm,OUTPUT)==0xe0000006
                            oracle = oracle and a['r0']==b['r0']==bits
                            oracle = oracle and word(bm,OWNER+4)==0x20004204
                            oracle = oracle and word(bm,OWNER+8)==OUTPUT+(16 if valid else 4)
                            if valid:
                                oracle = oracle and word(bm,OUTPUT)==0x80000007 and word(bm,OUTPUT+4)==0xdada0105
                                oracle = oracle and word(bm,OUTPUT+8)==(metadata_b | (((metadata_a-32)&0xffffffff)<<16))&0xffffffff
                                if context==2:
                                    oracle = oracle and (bm.get(0x2000082d)==1 if state==0 else 0x2000082d not in bm)
                            paths=b['unique_addresses']
                            visited=0x08070200 in paths and (0x08070000 in paths)==valid and (0x08070100 in paths)==(valid and context==2)
                            if not(equivalent(a,b,am,bm) and oracle and visited):
                                failures.append({'size':size,'position':position,'bits':bits,'state':state,'context':context,'valid':valid})
                            if valid and context==2 and state==2 and bits==4:
                                for name,target in (('session',0x70000),('cleanup',0x70100),('handler',0x70200)):
                                    mutant=bytearray(hybrid);mutant[target:target+4]=bytes.fromhex('01207047')
                                    wrong,wm=build.execute(bytes(mutant),CALLER,args,initial)
                                    mutations[name]+=int(not equivalent(a,wrong,am,wm))
    sequence_cases=0
    for state in range(256):
        initial=handler_presets(state,2,True)+presets([0x20005000,NODE,0x20005020],0xffffffff)
        original_uc,original_trace=emulate.new_emulator(original)
        hybrid_uc,hybrid_trace=emulate.new_emulator(hybrid)
        emulate.preset(original_uc,initial);emulate.preset(hybrid_uc,initial)
        for context in (2,2,1,0,255):
            # Restore only request cursors/context. Cleanup state and list mutations
            # survive across commands in each emulator.
            request=[(OWNER,struct.pack('<5I',0x20004100,0x20004200,OUTPUT,0,0x20004400)),
                     (0x20004100,struct.pack('<I',context))]
            emulate.preset(original_uc,request);emulate.preset(hybrid_uc,request)
            a=emulate.run_function(original_uc,original_trace,CALLER,(OWNER,0,0,0))
            b=emulate.run_function(hybrid_uc,hybrid_trace,CALLER,(OWNER,0,0,0))
            am=build.byte_map_of_native(a['writes']);bm=build.byte_map_of_native(b['writes'])
            same_ram=all(bytes(original_uc.mem_read(start,end-start))==bytes(hybrid_uc.mem_read(start,end-start))
                         for start,end in ((emulate.SRAM_BASE,emulate.STACK_RANGE[0]),
                                           (emulate.STACK_RANGE[1],emulate.SRAM_BASE+emulate.SRAM_SIZE)))
            sequence_cases+=1
            if not(equivalent(a,b,am,bm) and same_ram):
                failures.append({'sequence':True,'state':state,'context':context})
    report={'status' :'PASS' if not failures and all(mutations.values()) else 'FAIL','flashable':False,
            'cases':total,'persistent_sequence_calls':sequence_cases,'failures':failures,'mutation_detections':mutations,'patches':patches,
            'source_hashes':{p.name:build.digest(p.read_bytes()) for p in sources},
            'image_sha256':build.digest(original),'harness_sha256':build.digest(Path(__file__).read_bytes()),
            'compiler':subprocess.check_output([gcc,'--version'],text=True).splitlines()[0],
            'flags':flags,'linker_script':linker.read_text(),'candidate_hex':body.hex(),
            'hybrid_sha256':build.digest(hybrid),'changed_ranges':changed_ranges(original,hybrid),
            'limitations':['bounded acyclic lists; no concurrent mutation','no physical allocation or recovery validation',
                           'handler boundary has no complete incoming-edge proof','no interrupts, boot or hardware tests']}
    (ROOT/'reconstruction/handshake_validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(report['status'],total,'compiled-handler cases;',sequence_cases,'persistent calls;',mutations)
    return int(report['status']!='PASS')
if __name__=='__main__':raise SystemExit(main())
