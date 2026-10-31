"""Compare exports to the audited baseline without equating fewer warnings to coverage."""
import json
from pathlib import Path
import subprocess
import config
import evidence
from step17_confidence import audit_c

BASELINE='09371d0b2750ab329bc2c046ff895a3ea97c89ef'


def main():
    for key in config.keys():
        cfg=config.load(key)
        old=subprocess.check_output(['git','show',BASELINE+':'+cfg['c']],cwd=config.ROOT,text=True)
        before={r['address']:r for r in audit_c(old)}
        after={r['address']:r for r in audit_c(Path(cfg['c']).read_text())}
        def counts(rows):
            return {'blocks':len(rows),'failed':sum(r['failed'] for r in rows.values()),
                    'truncated':sum(r['truncated'] for r in rows.values()),
                    'with_warnings':sum(bool(r['warnings']) for r in rows.values())}
        result={'target':key,'baseline_commit':BASELINE,'before':counts(before),'after':counts(after),
                'scope':'export inventory delta; removed entries are not presumed false functions',
                'removed_entries_require_classification':sorted(before.keys()-after.keys()),
                'added_entries':sorted(after.keys()-before.keys()),
                'recovered_explicit_failures':[a for a in before.keys()&after.keys() if before[a]['failed'] and not after[a]['failed']],
                'warnings_resolved_at_existing_entries':[a for a in sorted(before.keys()&after.keys()) if before[a]['warnings'] and not after[a]['warnings']]}
        evidence.write(Path(cfg['analysis_dir'])/'recovery_delta.json',result,cfg)
        print(key,result['before'],'->',result['after'])


if __name__=='__main__': main()
