"""Reachability-guided Thumb discovery; unknown bytes remain unknown.

Roots: vector entries and previously identified static table targets. Direct calls
add roots; branch edges extend a body. Indirect transfers are recorded unresolved.
Printable bytes never suppress instruction decoding. This is candidate discovery,
not a claim that all executable bytes or all function boundaries are recovered.
"""
import hashlib
import json
from pathlib import Path
from collections import defaultdict, deque
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_GRP_CALL, CS_GRP_JUMP
from capstone.arm import ARM_OP_IMM, ARM_CC_AL, ARM_CC_INVALID
import config

CFG = config.load()
BASE = int(CFG['mcu']['base'],16)
VTOR = int(CFG['mcu']['vector_table'],16)


def analyze(data, table_entries=()):
    end = BASE + len(data)
    md = Cs(CS_ARCH_ARM,CS_MODE_THUMB); md.detail = True
    def valid(a): return VTOR <= a < end and a % 2 == 0
    vectors=[]
    for i in range(128):
        off=VTOR-BASE+i*4
        if off+4>len(data): break
        v=int.from_bytes(data[off:off+4],'little')
        if i == 0:
            if not 0x20000000<=v<=0x20100000: break
        elif v and (not v&1 or not valid(v&~1)): break
        vectors.append({'index':i,'name':'InitialSP' if i==0 else ('Reset' if i==1 else f'Vector{i}'), 'address':f'0x{v:08X}'})
    vector_end=VTOR+len(vectors)*4
    roots={int(r['address'],16)&~1 for r in vectors[1:] if int(r['address'],16)}
    roots.update(a for a in table_entries if valid(a))
    pending=deque(sorted(roots)); done=set(); insns={}; bodies={}; callers=defaultdict(set); unresolved=[]
    while pending:
        entry=pending.popleft()
        if entry in done or not valid(entry) or entry<vector_end: continue
        done.add(entry); body=set(); blocks=deque([entry])
        while blocks:
            address=blocks.popleft()
            if address in body or not valid(address): continue
            for ins in md.disasm(data[address-BASE:],address):
                a=ins.address
                if a in body or a<vector_end: break
                if a in roots and a!=entry: break
                body.add(a); insns[a]=ins
                if ins.group(CS_GRP_CALL):
                    if ins.operands and ins.operands[-1].type==ARM_OP_IMM:
                        target=ins.operands[-1].imm&~1
                        if valid(target):
                            callers[target].add(a); roots.add(target); pending.append(target)
                    else: unresolved.append({'address':hex(a),'kind':'indirect_call','instruction':str(ins.mnemonic)+' '+ins.op_str})
                elif ins.group(CS_GRP_JUMP):
                    target=ins.operands[-1].imm&~1 if ins.operands and ins.operands[-1].type==ARM_OP_IMM else None
                    if target is not None and valid(target): blocks.append(target)
                    elif ins.op_str!='lr': unresolved.append({'address':hex(a),'kind':'indirect_branch','instruction':ins.mnemonic+' '+ins.op_str})
                    conditional=ins.cc not in (ARM_CC_AL,ARM_CC_INVALID) or ins.mnemonic.startswith(('cbz','cbnz'))
                    if not conditional: break
                elif ('pc' in ins.op_str and ins.mnemonic.startswith(('pop','ldm'))) or ins.mnemonic in ('udf','bkpt'):
                    if ins.cc in (ARM_CC_AL,ARM_CC_INVALID): break
        bodies[entry]=body
    functions=[]
    for entry,body in sorted(bodies.items()):
        functions.append({'address':f'0x{entry:08X}','name':f'sub_{entry:08X}',
                          'size':max((a+insns[a].size for a in body),default=entry)-entry,
                          'boundary_status':'candidate; body may share tails',
                          'instruction_addresses':[f'0x{a:08X}' for a in sorted(body)],
                          'instructions_decoded':len(body),'callers':[f'0x{a:08X}' for a in sorted(callers[entry])],
                          'callee_count':sum(insns[a].group(CS_GRP_CALL) for a in body)})
    return vectors,insns,functions,unresolved


def main():
    data=Path(CFG['flash']).read_bytes()
    tables=json.loads(Path(CFG['tables']).read_text()) if Path(CFG['tables']).exists() else {}
    entries=[int(e['handler'],16)&~1 for t in tables.get('tables',[]) for e in t['entries']]
    reviewed=json.loads((Path(config.HERE)/'recovery_seeds.json').read_text()).get(CFG['key'],{})
    if reviewed.get('image_sha256')==hashlib.sha256(data).hexdigest():
        entries.extend(int(r['address'],16) for r in reviewed['entries'])
    vectors,insns,functions,unresolved=analyze(data,entries)
    lines=[f'; {CFG["key"]}; reachable Thumb candidates; unknown regions are .byte data, not proven data']
    import bisect
    known=sorted(insns)
    pos=0; unknown=0; unknown_lines=0
    if data[:VTOR-BASE]==bytes(VTOR-BASE):
        lines.append(f'{BASE:08x}              .fill 0x{VTOR-BASE:x} ; absent bootloader padding')
        pos=VTOR-BASE
    while pos<len(data):
        addr=BASE+pos
        if addr in insns:
            ins=insns[addr]; raw=data[pos:pos+ins.size].hex(' ')
            lines.append(f'{addr:08x}  {raw:<12}  {ins.mnemonic} {ins.op_str}')
            pos+=ins.size
        else:
            index=bisect.bisect_right(known,addr)
            next_code=known[index]-BASE if index<len(known) else len(data)
            width=min(16,next_code-pos,len(data)-pos)
            lines.append(f'{addr:08x}              .byte '+','.join(f'0x{b:02x}' for b in data[pos:pos+width])+' ; unclassified')
            pos+=width; unknown+=width; unknown_lines+=1
    import re
    strings=[{'address':f'0x{BASE+m.start():08X}','length':len(m[0]),'text':m[0].decode('ascii'),
              'status':'candidate; may overlap code'} for m in re.finditer(rb'[\x20-\x7e\n]{4,}',data)]
    def save(key,obj): Path(CFG[key]).write_text(json.dumps(obj,indent=2)+'\n')
    Path(CFG['listing']).write_text('\n'.join(lines)+'\n')
    save('vectors',{'vtor':f'0x{VTOR:08X}','count':len(vectors),'entries':vectors})
    save('functions',functions); save('strings',strings)
    stats={'image_bytes':len(data),'base':f'0x{BASE:08X}','end':f'0x{BASE+len(data):08X}',
           'instructions':len(insns),'functions':len(functions),'strings':len(strings),'vectors':len(vectors),
           'listing_lines':len(lines),'covered_bytes':len(data),'data_word_items':0,'ascii_items':0,
           'fill_items':1,'byte_items':unknown_lines,'unclassified_bytes':unknown,
           'instruction_bytes':sum(x.size for x in insns.values()),'image_sha256':hashlib.sha256(data).hexdigest(),
           'scope':'candidate CFG discovery; coverage is byte accounting, not C equivalence',
           'unresolved_transfers':unresolved}
    save('stats',stats)
    print(CFG['key'],len(insns),'instructions',len(functions),'candidate functions',len(unresolved),'unresolved transfers')


if __name__=='__main__': main()
