"""Manifest byte-check for one build: working tree and simulated fresh checkout.

Text files are UTF-8/LF by .gitattributes, so a fresh checkout yields LF bytes while a
Windows Python writer may leave CRLF. Both byte forms are hashed and compared with
manifest.json; `*.bin` entries are binary and therefore identical in both forms.

    python pipeline/tools/check_manifest.py                 # default target
    python pipeline/tools/check_manifest.py rc-410/fw4.16   # one build
    python pipeline/tools/check_manifest.py --all           # every registered build
"""
import hashlib
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import config  # noqa: E402


def check(key):
    cfg = config.load(key)
    root = config.ROOT
    manifest = json.load(open(os.path.join(root, cfg['manifest']), encoding='utf-8'))
    work_bad, checkout_bad = [], []
    for name, rec in manifest['files'].items():
        path = os.path.join(root, rec['path'])
        if not os.path.exists(path):
            work_bad.append((name, 'MISSING'))
            checkout_bad.append((name, 'MISSING'))
            continue
        raw = open(path, 'rb').read()
        if hashlib.sha256(raw).hexdigest() != rec['sha256']:
            work_bad.append((name, hashlib.sha256(raw).hexdigest()[:12]))
        # `text=auto eol=lf` normalises text to LF on checkout; git keeps files containing
        # a NUL byte (and every `*.bin`) verbatim, so only text files need the second check.
        lf = raw.replace(b'\r\n', b'\n') if b'\x00' not in raw else raw
        if hashlib.sha256(lf).hexdigest() != rec['sha256']:
            checkout_bad.append((name, hashlib.sha256(lf).hexdigest()[:12]))
    print('%s entries=%d working_mismatches=%s fresh_checkout_mismatches=%s'
          % (key, len(manifest['files']), work_bad or 'none', checkout_bad or 'none'))
    return 1 if work_bad else 0


def main():
    keys = config.keys() if '--all' in sys.argv else [
        arg for arg in sys.argv[1:] if not arg.startswith('--')]
    if not keys:
        keys = [config.raw()["default"]]
    return max(check(key) for key in keys)


if __name__ == '__main__':
    raise SystemExit(main())
