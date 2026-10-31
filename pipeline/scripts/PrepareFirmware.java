// Explicit Thumb context before automatic analysis. No synthetic bootloader code.
import java.math.BigInteger;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;

public class PrepareFirmware extends GhidraScript {
    public void run() throws Exception {
        Address first = toAddr(0x08010000L);
        Address last = currentProgram.getMemory().getMaxAddress();
        currentProgram.getProgramContext().setValue(
            currentProgram.getRegister("TMode"), first, last, BigInteger.ONE);
        MemoryBlock flash = currentProgram.getMemory().getBlock(first);
        if (flash.getStart().compareTo(first) < 0) {
            currentProgram.getMemory().split(flash, first);
            flash.setName("ABSENT_BOOTLOADER_PADDING");
            flash.setExecute(false);
            flash = currentProgram.getMemory().getBlock(first);
        }
        flash.setName("APPLICATION");
        flash.setWrite(false);
        flash.setExecute(true);
        MemoryBlock ram = currentProgram.getMemory().createUninitializedBlock("SRAM", toAddr(0x20000000L), 0x8000, false);
        ram.setRead(true); ram.setWrite(true); ram.setExecute(false);
        MemoryBlock mmio = currentProgram.getMemory().createUninitializedBlock("PERIPHERALS", toAddr(0x40000000L), 0x10000000, false);
        mmio.setRead(true); mmio.setWrite(true); mmio.setVolatile(true); mmio.setExecute(false);
        // Entries are data words. Terminate at the first implausible entry; no guessed IRQ names.
        for (int i = 1; i < 128; i++) {
            long value = Integer.toUnsignedLong(getInt(first.add(i * 4)));
            if (value == 0) continue;
            if ((value & 1) == 0 || value < 0x08010000L || value > last.getOffset()) break;
            Address entry = toAddr(value & ~1L);
            disassemble(entry);
            createFunction(entry, i == 1 ? "Reset_Handler" : null);
        }
    }
}
