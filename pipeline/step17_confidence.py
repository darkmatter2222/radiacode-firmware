"""Evidence inventory, explicitly not a firmware-equivalence certification."""
import json
import re
from pathlib import Path
import config
import evidence
import report_documents
import rcfmt
from step15_differential import case_passed

CFG=config.load()


def load(key):
    p=Path(CFG[key]); return json.loads(p.read_text()) if p.exists() else {}


def audit_c(text):
    rows=[]
    for block in re.split(r'(?=/\* ===== )',text):
        m=re.match(r'/\* ===== (.*?) @ ([0-9a-fA-F]+) ===== \*/',block)
        if not m: continue
        rows.append({'address':'0x'+m[2], 'name':m[1],
                     'failed':'decompilation failed' in block,
                     'truncated':'Bad instruction - Truncating' in block,
                     'warnings':re.findall(r'WARNING: ([^*\n]+)',block)})
    return rows


def main():
    data=Path(CFG['container']).read_bytes()
    _,blocks,image=rcfmt.build_flash_image(data) # raises on CRC failure
    extraction=image==Path(CFG['flash']).read_bytes()
    c=audit_c(Path(CFG['c']).read_text()) if Path(CFG['c']).exists() else []
    roundtrip,cross,diff,formal=(load(k) for k in ('roundtrip','crosscheck','differential','formal'))
    executed=[r for r in diff.get('cases',[]) if 'skipped' not in r]
    report={'target':CFG['key'],'status':'INCONCLUSIVE',
            'firmware_equivalence':'NOT_ESTABLISHED',
            'extraction':{'status':'PASS' if extraction else 'FAIL','blocks_crc_verified':len(blocks),
                          'flash_matches_decoded_container':extraction,
                          'absent_bootloader_bytes':int(CFG['mcu']['vector_table'],16)-int(CFG['mcu']['base'],16)},
            'container_roundtrip':{'status':'PASS' if roundtrip.get('byte_exact') else 'FAIL',
                                  'scope':'container format only; no source compilation'},
            'decoder_comparison':{'status':cross.get('status','INCONCLUSIVE'),'tiers':cross.get('tiers',{}),
                                  'only_capstone':cross.get('only_capstone'), 'only_ghidra':cross.get('only_ghidra')},
            'decompilation':{'blocks':len(c),'failed':sum(r['failed'] for r in c),
                             'truncated':sum(r['truncated'] for r in c),
                             'with_warnings':sum(bool(r['warnings']) for r in c),
                             'review_required':[r for r in c if r['failed'] or r['warnings']]},
            'python_differential':{'status':diff.get('function_status','SKIP'),
                                   'passed':sum(case_passed(r) for r in executed),'executed':len(executed),
                                   'skipped':len(diff.get('cases',[]))-len(executed),
                                   'unique_instructions':diff.get('unique_instruction_addresses',0)},
            'formal':{'status':'PASS' if formal and formal.get('proved')==len(formal.get('checks',[])) else 'INCONCLUSIVE',
                      'scope':'auxiliary model properties; no original-vs-rebuilt proof',
                      'proved':formal.get('proved',0),'unknown':formal.get('unknown',0)},
            'hardware':{'status':'SKIP','reason':'No fresh original-vs-rebuilt hardware comparison'},
            'release_ready':False,
            'blockers':['Whole application is not reconstructed from source',
                        'Indirect control flow and decompiler warnings require review',
                        'No complete subsystem/interrupt/peripheral equivalence test',
                        'No hardware equivalence evidence or acquired bootloader']}
    evidence.write(CFG['confidence'],report,CFG)
    lines=['## Current evidence: '+CFG['key'],'', '**Firmware equivalence: NOT ESTABLISHED. Release ready: false.**','',
           '| Evidence | Result |','| --- | --- |',
           f'| Extraction | {report["extraction"]["status"]}; {len(blocks)} payload CRCs verified |',
           f'| C export | {len(c)} blocks; {report["decompilation"]["failed"]} failures; {report["decompilation"]["truncated"]} truncated; {report["decompilation"]["with_warnings"]} with warnings |',
           f'| Python differential | {report["python_differential"]["passed"]}/{len(executed)} cases; not compiled C |',
           f'| Decoder comparison | {cross.get("status","INCONCLUSIVE")} |',
           f'| Auxiliary proofs | {formal.get("proved",0)} proved; not firmware equivalence |','| Hardware comparison | SKIP |','',
           '### Current blockers','',*['- '+x for x in report['blockers']],'']
    report_documents.update(CFG['confidence_md'], '\n'.join(lines))
    print(CFG['key'],report['decompilation']['blocks'],'C blocks;',report['decompilation']['truncated'],'truncated; release_ready=False')
    return 0 if extraction else 1 # successful report generation is not a release pass


if __name__=='__main__': raise SystemExit(main())
