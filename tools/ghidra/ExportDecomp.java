// Post-script for Ghidra headless: decompile every function and write one C file per address range.
// args: <out_dir> <ranges file: "name start end" per line>
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class ExportDecomp extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args[0]); outDir.mkdirs();
        List<String[]> ranges = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(args[1]))) {
            String l; while ((l = br.readLine()) != null) { l = l.trim(); if (!l.isEmpty()) ranges.add(l.split("\\s+")); }
        }
        DecompInterface di = new DecompInterface();
        DecompileOptions o = new DecompileOptions();
        di.setOptions(o); di.toggleCCode(true); di.toggleSyntaxTree(false); di.setSimplificationStyle("decompile");
        di.openProgram(currentProgram);
        Map<String, PrintWriter> files = new HashMap<>();
        int ok = 0, bad = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        PrintWriter idx = new PrintWriter(new FileWriter(new File(outDir, "index.tsv")));
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            long ep = f.getEntryPoint().getOffset();
            String file = "misc";
            for (String[] r : ranges) {
                if (ep >= Long.parseLong(r[1], 16) && ep < Long.parseLong(r[2], 16)) { file = r[0]; break; }
            }
            PrintWriter pw = files.get(file);
            if (pw == null) {
                pw = new PrintWriter(new FileWriter(new File(outDir, file + ".c")));
                pw.println("/* Ghidra reference decompilation of " + file + " (read-only; see docs/decomp.md). */");
                pw.println("#include \"ghidra_types.h\"\n");
                files.put(file, pw);
            }
            DecompileResults res = di.decompileFunction(f, 90, monitor);
            pw.printf("/* %s @ 0x%08X */%n", f.getName(), ep);
            if (res != null && res.decompileCompleted()) {
                pw.println(res.getDecompiledFunction().getC()); ok++;
                idx.printf("%08X\t%s\t%s\tok\t%s%n", ep, f.getName(), file, res.getDecompiledFunction().getSignature().replace('\t', ' '));
            } else {
                pw.println("/* decompilation failed: " + (res == null ? "null" : res.getErrorMessage()) + " */\n"); bad++;
                idx.printf("%08X\t%s\t%s\tfail\t%n", ep, f.getName(), file);
            }
        }
        for (PrintWriter pw : files.values()) pw.close();
        idx.close();
        println("decompiled " + ok + " functions, " + bad + " failed");
    }
}
