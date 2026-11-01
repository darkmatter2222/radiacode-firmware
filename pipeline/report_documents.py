"""Refresh a bounded generated section without erasing linked report content."""
from pathlib import Path
START = '<!-- current-evidence:start -->'
END = '<!-- current-evidence:end -->'


def update(path, current):
    path=Path(path)
    old=path.read_text() if path.exists() else ''
    block=START+'\n'+current.rstrip()+'\n'+END
    if START in old or END in old:
        if old.count(START)!=1 or old.count(END)!=1 or old.index(END)<old.index(START):
            raise ValueError('malformed current-evidence markers: '+str(path))
        before,rest=old.split(START,1)
        _,after=rest.split(END,1)
        text=before+block+after
    elif old:
        # Keep the original title, heading anchors and narrative intact.
        title,sep,body=old.partition('\n')
        text=title+'\n\n'+block+'\n\n'+body.lstrip('\n')
    else:
        text=block+'\n'
    path.write_text(text, encoding="utf-8", newline="\n")
