// DumpC.java -- headless helper: seed functions from the vector table, decompile them all.
//
// Run with:
//   analyzeHeadless firmware\ghidra_proj RC102 -import firmware\rc102_flash.bin \
//     -loader BinaryLoader -loader-baseAddr 0x08010000 -loader-blockName FLASH \
//     -processor "ARM:LE:32:v7" -scriptPath scripts -postScript DumpC.java

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompiledFunction;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressFactory;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Program;

public class DumpC extends GhidraScript {

    private static final long VTOR = 0x08010000L;
    private static final int VECTOR_COUNT = 96;

    @Override
    public void run() throws Exception {
        Program program = currentProgram;
        AddressFactory factory = program.getAddressFactory();

        for (int i = 1; i < VECTOR_COUNT; i++) {
            long value = readWord(program, factory, VTOR + 4L * i);
            if (value != 0 && (value & 1L) == 1L) {
                Address target = factory.getAddress(String.format("%08x", value & ~1L));
                if (target != null && program.getFunctionManager().getFunctionAt(target) == null) {
                    createFunction(target, "handler_" + i + "_" + nameOf(i));
                }
            }
        }

        // seed the remaining function starts discovered by the capstone pass
        int seeded = 0;
        seeded += seedFromJson(factory, new File("firmware/analysis/functions.json"), "\"address\": \"0x([0-9A-Fa-f]{8})\"");
        seeded += seedTableHandlers(factory, new File("firmware/analysis/tables.json"));

        File dir = new File("firmware/decompiled");
        if (!dir.exists()) {
            dir.mkdirs();
        }

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(program);

        int done = 0;
        int failed = 0;
        PrintWriter out = new PrintWriter(new File(dir, "rc102_flash.c"));
        try {
            out.println("/* RadiaCode-102 firmware, rc-102z.bin v4.14 (whole-file crc 13095abb)");
            out.println(" * decoded flash image 0x08000000 - 0x0803ca00 (blocks at 0x08010000+), Cortex-M4 (ARMv7E-M)");
            out.println(" * Ghidra headless decompilation */");
            out.println();

            Iterator<Function> functions = program.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                Function function = functions.next();
                out.println("/* ===== " + function.getName() + " @ " + function.getEntryPoint() + " ===== */");
                DecompileResults results = decomp.decompileFunction(function, 60, monitor);
                DecompiledFunction decompiled = results == null ? null : results.getDecompiledFunction();
                if (decompiled == null || decompiled.getC() == null) {
                    out.println("/* decompilation failed */");
                    failed++;
                }
                else {
                    out.println(decompiled.getC());
                    done++;
                }
                out.println();
            }
        }
        finally {
            out.close();
            decomp.dispose();
        }
        println("DumpC: seeded=" + seeded + " decompiled=" + done + " failed=" + failed);
    }

    private int seedTableHandlers(AddressFactory factory, File file) throws Exception {
        if (!file.exists()) {
            return 0;
        }
        StringBuilder text = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            char[] buffer = new char[8192];
            int read;
            while ((read = reader.read(buffer)) > 0) {
                text.append(buffer, 0, read);
            }
        }
        int created = 0;
        Matcher matcher = Pattern.compile(
            "\"id\": \"0x([0-9A-Fa-f]+)\",\\s*\"handler\": \"0x([0-9A-Fa-f]{8})\"").matcher(text.toString());
        while (matcher.find()) {
            long id = Long.parseLong(matcher.group(1), 16);
            long value = Long.parseLong(matcher.group(2), 16);
            Address target = factory.getAddress(String.format("%08x", value & ~1L));
            if (target != null && currentProgram.getFunctionManager().getFunctionAt(target) == null) {
                createFunction(target, "tbl_" + matcher.group(1) + "_" + String.format("%08x", value & ~1L));
                created++;
            }
        }
        return created;
    }

    private int seedFromJson(AddressFactory factory, File file, String pattern) throws Exception {
        if (!file.exists()) {
            return 0;
        }
        StringBuilder text = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            char[] buffer = new char[8192];
            int read;
            while ((read = reader.read(buffer)) > 0) {
                text.append(buffer, 0, read);
            }
        }
        int created = 0;
        Matcher matcher = Pattern.compile(pattern).matcher(text.toString());
        while (matcher.find()) {
            long value = Long.parseLong(matcher.group(1), 16);
            Address target = factory.getAddress(String.format("%08x", value & ~1L));
            if (target != null && currentProgram.getFunctionManager().getFunctionAt(target) == null) {
                createFunction(target, null);
                created++;
            }
        }
        return created;
    }

    private long readWord(Program program, AddressFactory factory, long address) {
        Address addr = factory.getAddress(String.format("%08x", address));
        if (addr == null) {
            return 0;
        }
        try {
            return program.getMemory().getInt(addr) & 0xFFFFFFFFL;
        }
        catch (Exception e) {
            return 0;
        }
    }

    private String nameOf(int index) {
        String[] core = { "sp", "reset", "nmi", "hardfault", "memmanage", "busfault", "usagefault", "r7", "r8",
                "r9", "r10", "svcall", "debugmon", "r13", "pendsv", "systick" };
        if (index < core.length) {
            return core[index];
        }
        return "irq" + (index - core.length);
    }
}
