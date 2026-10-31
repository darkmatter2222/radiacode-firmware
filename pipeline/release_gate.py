"""Fail closed: evidence existence is not evidence of complete firmware equivalence."""
import json
from pathlib import Path
import config
import evidence


def evaluate(root=Path(config.ROOT)):
    blockers=[]
    for key in config.keys():
        cfg=config.load(key)
        path=root/cfg['confidence']
        if not path.exists():
            blockers.append(key+': missing confidence report'); continue
        report=json.loads(path.read_text())
        if report.get('release_ready') is not True:
            blockers.append(key+': firmware equivalence not established')
        if report.get('provenance') != evidence.provenance(cfg):
            blockers.append(key+': stale confidence provenance')
        manifest=root/cfg['manifest']
        if not manifest.exists():
            blockers.append(key+': missing manifest'); continue
        for entry in json.loads(manifest.read_text()).get('files',{}).values():
            file=root/entry['path']
            if not file.exists() or evidence.sha256(file)!=entry['sha256']:
                blockers.append(key+': artifact mismatch '+entry['path'])
        hardware=root/cfg['analysis_dir']/'hardware_equivalence.json'
        if not hardware.exists():
            blockers.append(key+': original-vs-rebuilt hardware evidence absent')
        else:
            # A manually asserted boolean cannot satisfy this gate. Integration is
            # intentionally blocked until a device-specific evidence policy exists.
            blockers.append(key+': hardware evidence policy not yet independently validated')
    return {'status':'INCONCLUSIVE' if blockers else 'PASS','release_ready':not blockers,'blockers':blockers}


if __name__=='__main__':
    report=evaluate(); print(json.dumps(report,indent=2))
    raise SystemExit(0 if report['release_ready'] else 2)
