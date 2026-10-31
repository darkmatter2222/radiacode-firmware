"""Robust BLE session for the RadiaCode-102 (Nus-like service, 4-byte length framing)."""

import asyncio
import struct

from bleak import BleakClient

SERVICE_UUID = "e63215e5-7003-49d8-96b0-b024798fb901"
WRITE_UUID = "e63215e6-7003-49d8-96b0-b024798fb901"
NOTIFY_UUID = "e63215e7-7003-49d8-96b0-b024798fb901"

ADDRESS = "52:43:06:60:20:24"


class Session:
    def __init__(self, address=ADDRESS):
        self._address = address
        self._client = None
        self._buf = b""
        self._seq = 0

    async def open(self):
        self._client = BleakClient(self._address, timeout=10.0)
        await self._client.connect()
        self._buf = b""
        await self._client.start_notify(NOTIFY_UUID, self._on_notify)

    def _on_notify(self, handle, data):
        self._buf += bytes(data)

    async def close(self):
        try:
            if self._client is not None and self._client.is_connected:
                await self._client.disconnect()
        except Exception:  # noqa: BLE001
            pass

    @property
    def connected(self):
        return self._client is not None and self._client.is_connected

    def _take(self, header):
        """Pull complete responses out of the stream; return payload of matching one."""
        while len(self._buf) >= 4:
            total = 4 + struct.unpack_from("<I", self._buf)[0]
            if len(self._buf) < total:
                return None
            payload = self._buf[4:total]
            self._buf = self._buf[total:]
            if len(payload) >= 4 and payload[:4] == header:
                return payload[4:]
        return None

    async def cmd(self, command, args=b"", timeout=2.0, retries=2):
        last = "no-response"
        for _ in range(retries + 1):
            try:
                if not self.connected:
                    await self.close()
                    await self.open()
                seq = 0x80 + self._seq
                self._seq = (self._seq + 1) % 32
                request = struct.pack("<HBB", int(command), 0, seq) + bytes(args)
                header = request[:4]
                full = struct.pack("<I", len(request)) + request
                for pos in range(0, len(full), 18):
                    await self._client.write_gatt_char(WRITE_UUID, full[pos : pos + 18])
                loop = asyncio.get_running_loop()
                deadline = loop.time() + timeout
                while loop.time() < deadline:
                    out = self._take(header)
                    if out is not None:
                        return out
                    await asyncio.sleep(0.005)
            except Exception as exc:  # noqa: BLE001
                last = repr(exc)
                await asyncio.sleep(0.05)
        raise RuntimeError(f"cmd 0x{int(command):04X} failed: {last}")
