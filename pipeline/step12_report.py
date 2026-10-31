"""Summarize current evidence and hash artifacts after generation, using LF text bytes."""
import json
from pathlib import Path
import config
import evidence

CFG=config.load()


def main():
    config.ensure_dirs(CFG)
    report=json.loads(Path(CFG['confidence']).read_text()) if Path(CFG['confidence']).exists() else {}
    summary=['# '+CFG['key'],'',
             'This is an extracted application and research reconstruction. Full firmware equivalence is not established.',
             'The synthetic bootloader padding is not acquired device memory. C output is not a complete buildable application.','',
             'See [confidence.md](confidence.md) for current evidence, warnings, and blockers.','',
             '## Reproduce','', '```sh',
             'python -m unittest discover -s tests -v',
             'python pipeline/run.py --all-devices --only 1,13,14,15,16,17',
             'python pipeline/step12_report.py', '```','',
             'Exit 2 denotes incomplete or inconclusive evidence; it is not a pass.','']
    Path(CFG['summary']).write_text('\n'.join(summary))
    files={}
    paths={name:CFG[name] for name in ('container','flash','blocks','listing','c','index')}
    paths.update({name:CFG[name] for name in config.ANALYSIS_FILES if name!='summary'})
    for extra in ('ghidra_run','recovery_delta'):
        paths[extra]=str(Path(CFG['analysis_dir'])/(extra+'.json'))
    for name,path in paths.items():
        p=Path(path)
        if p.exists():
            files[name]={'path':path,'bytes':p.stat().st_size,'sha256':evidence.sha256(p)}
    payload={'target':CFG['key'],'hash_convention':'exact bytes; text files are UTF-8/LF via .gitattributes',
             'mcu':CFG['mcu'],'expected':CFG['expected'],'landmarks':CFG['landmarks'],
             'files':files}
    evidence.write(CFG['manifest'],payload,CFG)
    print('wrote',CFG['manifest'])
    return 0


if __name__=='__main__': raise SystemExit(main())
