"""Offline assertions against pinned, attributed PhytonUtils sample vectors."""
import json
from pathlib import Path
import rcfmt


def main():
    fixture = Path(__file__).resolve().parents[1] / 'tests/fixtures/phyton_vectors.json'
    arrays = json.loads(fixture.read_text())['vectors']
    for name, compressed in [('sampleBlockFirmwareUncompressed',False),('sampleBlockFirmwareCompressed',True)]:
        raw=bytes.fromhex(arrays[name])
        size=len(raw)-rcfmt.KEY_BLOCK_SIZE-(3 if compressed else 0)
        plain, crc=rcfmt.decrypt_block(raw,size,compressed,outer_offset=0)
        if compressed: plain=rcfmt.lzss_decompress(plain)
        if rcfmt.calculate_crc(plain)!=crc:
            raise ValueError(name+': CRC mismatch')
        print('PASS',name,len(plain),'bytes')
    return 0


if __name__=='__main__': raise SystemExit(main())
