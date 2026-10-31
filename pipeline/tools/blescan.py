"""Scan for the RadiaCode-102 over BLE."""

import asyncio
import json

from bleak import BleakScanner


async def main():
    devices = await BleakScanner.discover(timeout=8.0, return_adv=True)
    out = []
    for addr, (dev, adv) in devices.items():
        out.append(
            {
                "address": dev.address,
                "name": dev.name,
                "rssi": adv.rssi,
                "service_uuids": list(adv.service_uuids),
                "manufacturer_data": {k: v.hex() for k, v in adv.manufacturer_data.items()},
            }
        )
    print(json.dumps(out, indent=2))


asyncio.run(main())
