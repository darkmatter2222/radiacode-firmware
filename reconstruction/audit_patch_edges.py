"""Conservative incoming-edge candidates, not an executable-code classification."""
import json
from pathlib import Path
import struct
import sys
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'pipeline'))
import build_reconstruction as build
import config
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_GRP_JUMP, CS_GRP_CALL
from capstone.arm import ARM_OP_IMM

BASE=0x08000000
RANGES=((0x080273a2,0x080273d2),(0x08027490,0x08027518),(0x08029086,0x080290a0),(0x08029370,0x08029388))


def scan(image,ranges,base=BASE):
    cs=Cs(CS_ARCH_ARM,CS_MODE_THUMB);cs.detail=True
    direct=[];pointers=[]
    # Decode at EVERY halfword: catches possible code absent from the seeded walk,
    # at the cost of interpreting data and second halves as potential instructions.
    for offset in range(0,len(image)-1,2):
        inst=next(cs.disasm(image[offset:offset+4],base+offset,count=1),None)
        if inst is None or not (inst.group(CS_GRP_JUMP) or inst.group(CS_GRP_CALL)):
            continue
        if not inst.operands or inst.operands[-1].type!=ARM_OP_IMM:
            continue
        target=inst.operands[-1].imm & 0xffffffff
        for start,end in ranges:
            if start<=target<end and not start<=inst.address<end:
                direct.append({'source':hex(inst.address),'target':hex(target),
                               'instruction':inst.mnemonic+' '+inst.op_str,
                               'location':'entry' if target==start else 'interior',
                               'overwritten':start<=target<start+4})
    for start,end in ranges:
        for target in range(start,end):
            needle=struct.pack('<I',target);offset=image.find(needle)
            while offset!=-1:
                normalized=target&~1
                pointers.append({'offset':hex(base+offset),'value':hex(target),
                                 'location':'entry' if normalized==start else 'interior',
                                 'overwritten':start<=normalized<start+4})
                offset=image.find(needle,offset+1)
    return {'direct_candidates':direct,'literal_pointer_candidates':pointers}


def main():
    image=(ROOT/config.load('rc-102/hw1-fw4.14')['flash']).read_bytes()
    if build.digest(image)!=build.REFERENCE_SHA256:raise ValueError('unreviewed image')
    result=scan(image,RANGES)
    result.update({'status':'INCONCLUSIVE','release_ready':False,
                   'image_sha256':build.digest(image),'harness_sha256':build.digest(Path(__file__).read_bytes()),
                   'ranges':[{'start':hex(a),'end_exclusive':hex(b),'overwrite_bytes':4} for a,b in RANGES],
                   'limitations':['candidates include data and overlapping instruction decodes',
                       'literal values do not prove use as code pointers',
                       'computed indirect targets and dynamic control flow remain unresolved',
                       'absence of candidates does not establish absence of incoming edges']})
    (ROOT/'reconstruction/patch_edge_audit.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print('INCONCLUSIVE',len(result['direct_candidates']),'direct candidates;',len(result['literal_pointer_candidates']),'pointer candidates')
    return 2
if __name__=='__main__':raise SystemExit(main())
