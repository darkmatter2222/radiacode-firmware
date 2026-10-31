// DumpListing.java -- headless helper: export the SLEIGH listing and the function ranges as JSON.
//
// Used by pipeline/step14_crosscheck.py to compare the disassembly that produced `listing.s`
// (capstone) with the independent decoder inside Ghidra (SLEIGH).  Both sides are normalised in
// Python; the Java side only prints "<address>|<mnemonic>|<operand text>".
//
// Run with (same script argument convention as DumpC.java):
//   analyzeHeadless firmware/rc-102/hw1-fw4.14/ghidra_proj RC102 \
//     -import firmware/rc-102/hw1-fw4.14/flash.bin \
//     -loader BinaryLoader -loader-baseAddr 0x08000000 -loader-blockName FLASH \
//     -processor "ARM:LE:32:v7" -scriptPath pipeline/scripts \
//     -postScript DumpListing.java firmware/rc-102/hw1-fw4.14

import java.io.File;
import java.io.PrintWriter;
import java.util.Iterator;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.listing.Program;

public class DumpListing extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] scriptArgs = getScriptArgs();
        String dir = scriptArgs.length > 0 && !scriptArgs[0].isEmpty() ? scriptArgs[0] : "firmware";
        Program program = currentProgram;
        Listing listing = program.getListing();

        File analysis = new File(dir, "analysis");
        if (!analysis.exists()) {
            analysis.mkdirs();
        }
        try (PrintWriter out = new PrintWriter(new File(analysis, "ghidra_listing.json"))) {
            out.print("{\"operand_schema\":\"rendered-v1\",\"instructions\":[");
            int instructions = 0;
            InstructionIterator walker = listing.getInstructions(true);
            while (walker.hasNext()) {
                Instruction ins = walker.next();
                if (instructions++ > 0) {
                    out.print(",");
                }
                out.print("[\"");
                out.print(hex(ins.getAddress()));
                out.print("\",\"");
                out.print(escape(ins.getMnemonicString()));
                out.print("\",\"");
                out.print(escape(operands(ins)));
                out.print("\"]");
            }
            out.print("],\"functions\":[");
            int functions = 0;
            Iterator<Function> it = listing.getFunctions(true);
            while (it.hasNext()) {
                Function function = it.next();
                AddressSetView body = function.getBody();
                Address start = body.getMinAddress();
                Address end = body.getMaxAddress();
                if (start == null || end == null) {
                    continue;
                }
                if (functions++ > 0) {
                    out.print(",");
                }
                out.print("[\"");
                out.print(hex(start));
                out.print("\",\"");
                out.print(hex(end));
                out.print("\",\"");
                out.print(escape(function.getName()));
                out.print("\",");
                out.print(function.getSignature() == null ? 0 : 1);
                out.print("]");
            }
            out.println("]}");
            println("DumpListing: instructions=" + instructions + " functions=" + functions);
        }
    }

    private String operands(Instruction ins) {
        String text = ins.toString();
        int space = text.indexOf(' ');
        return space < 0 ? "" : text.substring(space + 1).trim();
    }

    private String hex(Address address) {
        String text = address.toString();
        int colon = text.indexOf(':');
        if (colon >= 0) {
            text = text.substring(colon + 1);
        }
        text = text.trim();
        try {
            return String.format("0x%08X", Long.parseLong(text, 16));
        } catch (NumberFormatException error) {
            return "0x" + text;
        }
    }

    private String escape(String value) {
        if (value == null) {
            return "";
        }
        return value.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", " ");
    }
}
