"""Minimal BLE transport + protocol layer for RadiaCode devices (bleak-based)."""

import asyncio
import struct

from bleak import BleakClient

SERVICE_UUID = "e63215e5-7003-49d8-96b0-b024798fb901"
WRITE_UUID = "e63215e6-7003-49d8-96b0-b024798fb901"
NOTIFY_UUID = "e63215e7-7003-49d8-96b0-b024798fb901"


class BleTransport:
    """Mirrors radiacode.transports.bluetooth framing on top of bleak."""

    def __init__(self, address):
        self._address = address
        self._client = None
        self._chunks = []
        self._seq = 0

    async def open(self):
        self._client = BleakClient(self._address)
        await self._client.connect()
        await self._client.start_notify(NOTIFY_UUID, self._on_notify)

    def _on_notify(self, handle, data):
        self._chunks.append(bytes(data))

    async def close(self):
        if self._client is not None and self._client.is_connected:
            await self._client.disconnect()

    async def _collect(self, timeout=5.0):
        raw = b""
        loop = asyncio.get_running_loop()
        deadline = loop.time() + timeout
        total = None
        while loop.time() < deadline:
            while self._chunks:
                raw += self._chunks.pop(0)
                if total is None and len(raw) >= 4:
                    total = 4 + struct.unpack_from("<I", raw)[0]
                if total is not None and len(raw) >= total:
                    return raw[4:total]
            await asyncio.sleep(0.005)
        return raw[4:] if total is not None and raw else b""

    async def execute(self, cmd, args=b""):
        req_seq_no = 0x80 + self._seq
        self._seq = (self._seq + 1) % 32
        request = struct.pack("<HBB", int(cmd), 0, req_seq_no) + bytes(args)
        full = struct.pack("<I", len(request)) + request
        self._chunks.clear()
        for pos in range(0, len(full), 18):
            await self._client.write_gatt_char(WRITE_UUID, full[pos : pos + 18])
        data = await self._collect()
        if not data:
            raise RuntimeError(f"no response for cmd 0x{int(cmd):04X}")
        header = request[:4]
        if data[:4] != header:
            raise RuntimeError(
                f"cmd 0x{int(cmd):04X}: header {data[:4].hex()} != {header.hex()}"
            )
        return data[4:]
