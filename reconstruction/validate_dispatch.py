"""Bounded original table dispatch into the compiled handshake chain.

Stops at the real post-handler instruction, not a fabricated function return.
Frame validation, table-selection policy and response finalization are excluded.
"""
import json
from pathlib import Path
import struct
import sys
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'pipeline'))
import build_reconstruction as build
import config
import emulate
import validate_handshake
from validate_session_hybrid import handler_presets, OWNER, OUTPUT, word
from unicorn import UcError
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3, UC_ARM_REG_R4, UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC
from unicorn import arm_const

START, STOP = 0x08027310, 0x08027324
TABLES=(0x08027344,0x08037838)


def run_slice(image,table,initial,command=0x80000007,budget=20000):
    uc,trace=emulate.new_emulator(image);emulate.preset(uc,initial)
    saved={getattr(arm_const,'UC_ARM_REG_R%d'%i):0xa5000000+i for i in range(4,12)}
    saved[UC_ARM_REG_R4]=OWNER
    for reg,value in saved.items():uc.reg_write(reg,value)
    for reg,value in ((UC_ARM_REG_R0,0),(UC_ARM_REG_R1,command),(UC_ARM_REG_R2,table),
                      (UC_ARM_REG_R3,0x13579bdf),(UC_ARM_REG_SP,emulate.STACK_TOP),
                      (UC_ARM_REG_LR,emulate.SENTINEL)):
        uc.reg_write(reg,value)
    error=None
    try:uc.emu_start(START|1,STOP,count=budget)
    except UcError as exc:error=str(exc)
    pc=uc.reg_read(UC_ARM_REG_PC)&~1
    reason='FAULT' if error else ('BOUNDARY_REACHED' if pc==STOP else 'BUDGET_EXHAUSTED')
    memory=build.byte_map_of_native(trace.writes)
    snapshot=b''.join(bytes(uc.mem_read(a,b-a)) for a,b in
                     ((emulate.SRAM_BASE,emulate.STACK_RANGE[0]),
                      (emulate.STACK_RANGE[1],emulate.SRAM_BASE+emulate.SRAM_SIZE)))
    return {'stop':reason,'pc':pc,'error':error,'r0':uc.reg_read(UC_ARM_REG_R0),
            'sp':uc.reg_read(UC_ARM_REG_SP),'saved':all(uc.reg_read(r)==v for r,v in saved.items()),
            'writes':memory,'ram_sha256':build.digest(snapshot),'mmio':trace.mmio,
            'addresses':sorted(trace.addresses),'edges':sorted(trace.edges)}


def main():
    if validate_handshake.main()!=0:raise RuntimeError('compiled handler validation failed')
    evidence=json.loads((ROOT/'reconstruction/handshake_validation.json').read_text())
    original=(ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    if build.digest(original)!=build.REFERENCE_SHA256:raise ValueError('unreviewed image')
    hybrid=bytearray(original+bytes(0x70000-len(original))+bytes.fromhex(evidence['candidate_hex']))
    for patch in evidence['patches']:
        offset=int(patch['entry'],16)-emulate.FLASH_BASE
        hybrid[offset:offset+4]=bytes.fromhex(patch['bytes'])
    hybrid=bytes(hybrid)
    if build.digest(hybrid)!=evidence['hybrid_sha256']:raise ValueError('artifact mismatch')
    failures=[];total=0;mutant_detections=0
    mutant=bytearray(hybrid);mutant[0x70200:0x70204]=bytes.fromhex('01207047')
    for table in TABLES:
        for state in range(256):
            for context in (0,1,2,3,255):
                for valid in (False,True):
                    initial=handler_presets(state,context,valid)
                    a=run_slice(original,table,initial);b=run_slice(hybrid,table,initial);total+=1
                    comparable=('stop','pc','r0','sp','saved','writes','ram_sha256','mmio')
                    expected=build.session_expected(context,state) if valid else 0xe0000006
                    reply=word(b['writes'],OUTPUT+(12 if valid else 0))
                    indirect=(0x08027322,0x08027490) in b['edges']
                    ok=(all(a[k]==b[k] for k in comparable) and b['stop']=='BOUNDARY_REACHED'
                        and b['sp']==emulate.STACK_TOP and b['saved'] and not b['mmio']
                        and reply==expected and indirect and 0x08070200 in b['addresses'])
                    if not ok:failures.append({'table':hex(table),'state':state,'context':context,'valid':valid,'original_stop':a['stop'],'compiled_stop':b['stop']})
                    if state==2 and context==2 and valid:
                        wrong=run_slice(bytes(mutant),table,initial)
                        mutant_detections+=int(wrong['writes']!=a['writes'])
    report={'status':'PASS' if not failures and mutant_detections==2 else 'FAIL','flashable':False,
            'cases':total,'failures':failures,'mutation_detections':mutant_detections,
            'boundary':{'start':hex(START),'stop':hex(STOP),'classification':'BOUNDARY_REACHED, not function RETURN'},
            'tables':[hex(t) for t in TABLES],'command':'0x80000007',
            'image_sha256':build.digest(original),'hybrid_sha256':build.digest(hybrid),
            'harness_sha256':build.digest(Path(__file__).read_bytes()),
            'handler_validation_sha256':build.digest((ROOT/'reconstruction/handshake_validation.json').read_bytes()),
            'limitations':['preselected tables; excludes upstream frame and mode validation',
                           'stops before response finalization and transport callbacks',
                           'no physical allocation, interrupts, timing or recovery proof']}
    (ROOT/'reconstruction/dispatch_validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(report['status'],total,'bounded original-dispatch cases')
    return int(report['status']!='PASS')
if __name__=='__main__':raise SystemExit(main())
