"""Generate device entry points without moving source or replacing old documents."""
import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]


def main():
    targets=json.loads((ROOT/'reconstruction/annotated/targets.json').read_text(encoding='utf-8'))
    reviewed=json.loads((ROOT/'reconstruction/annotated/index.json').read_text(encoding='utf-8'))
    overview=['# Choose your device','',
              'The `decompiled.c` inside each build directory is always **raw Ghidra output**.',
              'Use the guide below to find readable or compilable source, where available.','',
              '| Model / build | Device guide | Raw C | Readable source status |',
              '| --- | --- | --- | --- |']
    for target in targets:
        key=target['target'];model,version=key.split('/')
        available=key==reviewed['target']
        count=reviewed['reviewed_functions'] if available else 0
        status=(str(count)+' / '+str(target['functions'])+' functions reviewed') if available else 'Not available yet; raw only'
        overview.append('| '+model.upper()+' / '+version+' | [Open guide]('+key+'/README.md) | [Raw export]('+key+'/decompiled.c) | '+status+' |')
        lines=['# '+model.upper()+' '+version+': where to find the code','',
               '**The `decompiled.c` in this directory is the raw export. Generic names are expected.**','',
               '## Readable source','']
        if available:
            lines += ['**[Open the named-function index](../../../reconstruction/annotated/README.md)** first.',
                      'It links directly to the '+str(count)+' reviewed functions out of '+str(target['functions'])+' export blocks.','',
                      '| Version of the code | Open | Meaning |','| --- | --- | --- |',
                      '| Raw | [decompiled.c](decompiled.c) | Original Ghidra output, unchanged |',
                      '| Readable companion | [rc102.c](../../../reconstruction/annotated/rc102.c) | Reviewed names/comments; remaining names unresolved |',
                      '| Compilable core | [Core functions](../../../reconstruction/rc102_leaf.c) | Tested small reconstructed routines with named fields |',
                      '| Compilable floating point | [Coefficient checks](../../../reconstruction/calibration.c) | Tested bounds calculation and FPSCR behavior |']
        else:
            lines += ['**No reviewed English-named source or compiled reconstruction is available for this build yet.**',
                      'The raw export has '+str(target['functions'])+' function blocks. The naming work completed for RC-102',
                      'has not been transferred to this model. Its tests do not validate this build.','',
                      'You can read the [raw export](decompiled.c), or view the',
                      '[RC-102 readable-source example](../../../reconstruction/annotated/README.md)',
                      'to see the intended format. That example is for a different target.']
        lines += ['', '## Files in this directory','',
                  '| File or folder | What it is |','| --- | --- |',
                  '| `*.bin` | Vendor package(s) and decoded application image; not editable source |',
                  '| [decompiled.c](decompiled.c) | Raw pseudocode with Ghidra-generated names |',
                  '| [listing.s](listing.s) | ARM instruction listing |',
                  '| [index.json](index.json) | Raw function-address and line lookup |',
                  '| [analysis/summary.md](analysis/summary.md) | Existing analysis narrative and current update |',
                  '| [analysis/confidence.md](analysis/confidence.md) | What has been checked and what remains unresolved |','',
                  '[Choose another device](../../README.md) · [Start here](../../../START_HERE.md)','']
        (ROOT/'firmware'/key/'README.md').write_text('\n'.join(lines), encoding='utf-8', newline='\n')
        # One version per model at present; collect all registered versions to
        # avoid overwriting a model guide if a future registry adds a version.
    overview += ['', 'Readable source means reviewed names and comments, not a guarantee of compilability.',
                 'A complete source-built replacement firmware is not yet available for any model.','',
                 '[Start here](../START_HERE.md) · [Readable/rebuilt source guide](../reconstruction/README.md)','']
    (ROOT/'firmware/README.md').write_text('\n'.join(overview), encoding='utf-8', newline='\n')
    for model in sorted({t['target'].split('/')[0] for t in targets}):
        rows=['# '+model.upper()+' firmware','', 'Choose the firmware version to see raw and readable-source availability.','']
        for t in targets:
            m,version=t['target'].split('/')
            if m==model:rows.append('- ['+version+']('+version+'/README.md)')
        rows += ['', '[All devices](../README.md) · [Start here](../../START_HERE.md)','']
        (ROOT/'firmware'/model/'README.md').write_text('\n'.join(rows), encoding='utf-8', newline='\n')
    print('Generated guides for',len(targets),'builds; raw/readable status explicit')
if __name__=='__main__':main()
