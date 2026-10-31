"""Non-destructive probe of a RadiaCode-102 attached over USB."""

import json
import sys

from radiacode import RadiaCode
from radiacode.types import COMMAND, VS, VSFR

rc = RadiaCode(ignore_firmware_compatibility_check=True)

out = {}


def safe(name, fn):
    try:
        out[name] = fn()
    except Exception as exc:  # noqa: BLE001
        out[name] = f"ERROR: {exc!r}"


safe("fw_signature", rc.fw_signature)
safe("fw_version", rc.fw_version)
safe("serial", rc.serial_number)
safe("hw_serial", rc.hw_serial_number)
safe("status", rc.status)

try:
    cfg = rc.configuration()
    out["configuration"] = cfg
except Exception as exc:  # noqa: BLE001
    out["configuration"] = f"ERROR: {exc!r}"

# virtual strings worth probing
for vs in (VS.FW_DESCRIPTOR, VS.SERIAL_NUMBER, VS.TEXT_MESSAGE, VS.MEM_SNAPSHOT, VS.SFR_FILE):
    try:
        r = rc.read_request(vs)
        out[f"VS[{vs.name}=0x{int(vs):X}]"] = {
            "length": r.size(),
            "head_hex": r._data[:64].hex(),
            "text_preview": r._data[:400].decode("latin-1"),
        }
    except Exception as exc:  # noqa: BLE001
        out[f"VS[{vs.name}=0x{int(vs):X}]"] = f"ERROR: {exc!r}"

# a handful of system VSFRs
for name, member in VSFR.__members__.items():
    if not name.startswith("SYS_"):
        continue
    try:
        v = rc.batch_read_vsfrs([member])[0]
        out[f"VSFR[{name}=0x{int(member):08X}]"] = f"0x{v:08X} ({v})"
    except Exception as exc:  # noqa: BLE001
        out[f"VSFR[{name}=0x{int(member):08X}]"] = f"ERROR: {exc!r}"

if hasattr(rc, "close"):
    rc.close()
print(json.dumps(out, indent=2, default=str))
