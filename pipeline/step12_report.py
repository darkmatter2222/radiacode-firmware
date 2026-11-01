"""Summarize current evidence and hash artifacts after generation, using LF text bytes."""
import json
from pathlib import Path
import config
import evidence
import report_documents

CFG=config.load()


def main():
    config.ensure_dirs(CFG)
    report=json.loads(Path(CFG['confidence']).read_text()) if Path(CFG['confidence']).exists() else {}
    dec=report.get('decompilation', {})
    summary=['## Current analysis update','',
             '| Item | Current result |','| --- | --- |',
             '| Target | `'+CFG['key']+'` |',
             '| Application extraction | '+report.get('extraction',{}).get('status','INCONCLUSIVE')+' |',
             '| Exported C blocks | '+str(dec.get('blocks','unknown'))+' |',
             '| Explicit failures / truncated / warnings | '+str(dec.get('failed','?'))+' / '+str(dec.get('truncated','?'))+' / '+str(dec.get('with_warnings','?'))+' |',
             '| Complete rebuilt firmware | Not yet established |','',
             'The original report below retains its section links and baseline observations.',
             'Current evidence: [confidence.md](confidence.md), [confidence.json](confidence.json),',
             '[recovery_delta.json](recovery_delta.json). Counts measure discovery, not functional coverage.','',
             'Regenerate from the repository root with `python pipeline/run.py --all-devices --only 17,12`.',
             'Exit 2 denotes incomplete or inconclusive evidence; it is not a pass.','']
    report_documents.update(CFG['summary'], '\n'.join(summary))
    files={}
    paths={name:CFG[name] for name in ('container','flash','blocks','listing','c','index')}
    paths.update({name:CFG[name] for name in config.ANALYSIS_FILES if name!='summary'})
    for extra in ('ghidra_run','recovery_delta'):
        paths[extra]=str(Path(CFG['analysis_dir'])/(extra+'.json'))
    for name,path in paths.items():
        p=Path(path)
        if p.exists():
            files[name]={'path':p.as_posix(),'bytes':p.stat().st_size,'sha256':evidence.sha256(p)}
    payload={'target':CFG['key'],'hash_convention':'exact bytes; text files are UTF-8/LF via .gitattributes',
             'mcu':CFG['mcu'],'expected':CFG['expected'],'landmarks':CFG['landmarks'],
             'files':files}
    evidence.write(CFG['manifest'],payload,CFG)
    print('wrote',CFG['manifest'])
    return 0


if __name__=='__main__': raise SystemExit(main())
