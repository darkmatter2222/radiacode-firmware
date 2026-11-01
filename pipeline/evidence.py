"""Deterministic evidence provenance and explicit status vocabulary."""
import hashlib
import importlib.metadata
import json
from pathlib import Path
import config

PASS, FAIL, SKIP, INCONCLUSIVE = 'PASS','FAIL','SKIP','INCONCLUSIVE'


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def provenance(cfg):
    root=Path(config.ROOT)
    sources={p.relative_to(root).as_posix():sha256(p) for p in sorted((root/'pipeline').rglob('*'))
             if p.suffix in ('.py','.java','.json') and '__pycache__' not in p.parts}
    versions={}
    for package in ('capstone','unicorn','z3-solver'):
        try: versions[package]=importlib.metadata.version(package)
        except importlib.metadata.PackageNotFoundError: versions[package]='unavailable'
    return {'schema':1,'inputs':{k:sha256(root/cfg[k]) for k in ('container','flash')},
            'pipeline_source_sha256':hashlib.sha256(json.dumps(sources,sort_keys=True).encode()).hexdigest(),
            'tools':versions}


def write(path,payload,cfg):
    payload=dict(payload,provenance=provenance(cfg))
    Path(path).write_text(json.dumps(payload,indent=2)+'\n',encoding='utf-8',newline='\n')
