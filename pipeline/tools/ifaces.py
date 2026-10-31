"""Enumerate DOS device names (QueryDosDeviceW) and try opening the Phyton device."""

import ctypes
from ctypes import wintypes

k32 = ctypes.windll.kernel32
k32.QueryDosDeviceW.restype = wintypes.ULONG
k32.QueryDosDeviceW.argtypes = [ctypes.c_wchar_p, ctypes.c_wchar_p, wintypes.ULONG]

size = 65536
buf = ctypes.create_unicode_buffer(size)
n = k32.QueryDosDeviceW(None, buf, size)
err = ctypes.GetLastError()
print("QueryDosDeviceW ->", n, "lasterr", err)
names = [p for p in ctypes.wstring_at(ctypes.byref(buf), max(n, 1)).split("\x00") if p]
print("count:", len(names))
for name in names:
    low = name.lower()
    if any(k in low for k in ("ph", "usb", "rc", "bulk", "phyt")):
        print("  match:", name)
print("first 20:", names[:20])
