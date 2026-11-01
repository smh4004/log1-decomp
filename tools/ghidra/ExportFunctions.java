// Ghidra headless post-script: per-function JSON lines with C body, globals (name/type/address) and callee prototypes.
// args: <out.jsonl>
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class ExportFunctions extends GhidraScript {
    static String js(String s) {
        StringBuilder b = new StringBuilder("\"");
        for (char c : s.toCharArray()) {
            switch (c) {
                case '"': b.append("\\\""); break;
                case '\\': b.append("\\\\"); break;
                case '\n': b.append("\\n"); break;
                case '\r': break;
                case '\t': b.append("\\t"); break;
                default: if (c < 0x20) b.append(String.format("\\u%04x", (int) c)); else b.append(c);
            }
        }
        return b.append('"').toString();
    }
    public void run() throws Exception {
        PrintWriter pw = new PrintWriter(new FileWriter(getScriptArgs()[0]));
        DecompInterface di = new DecompInterface();
        di.setOptions(new DecompileOptions()); di.toggleCCode(true); di.toggleSyntaxTree(true);
        di.setSimplificationStyle("decompile");
        di.openProgram(currentProgram);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            DecompileResults r = di.decompileFunction(f, 90, monitor);
            StringBuilder o = new StringBuilder("{");
            o.append("\"name\":").append(js(f.getName()));
            o.append(",\"addr\":").append(f.getEntryPoint().getOffset());
            if (r == null || !r.decompileCompleted()) { pw.println(o.append(",\"c\":null}")); continue; }
            o.append(",\"c\":").append(js(r.getDecompiledFunction().getC()));
            o.append(",\"sig\":").append(js(r.getDecompiledFunction().getSignature()));
            o.append(",\"globals\":[");
            HighFunction hf = r.getHighFunction();
            boolean first = true;
            Iterator<HighSymbol> gs = hf.getGlobalSymbolMap().getSymbols();
            while (gs.hasNext()) {
                HighSymbol h = gs.next();
                String addr = "";
                try { SymbolEntry e = h.getFirstWholeMap(); if (e != null && e.getStorage() != null && e.getStorage().isMemoryStorage()) addr = Long.toString(e.getStorage().getMinAddress().getOffset()); } catch (Exception ex) {}
                if (!first) o.append(','); first = false;
                o.append("[").append(js(h.getName())).append(',').append(js(h.getDataType().getDisplayName()))
                 .append(',').append(js(addr)).append(',').append(h.getSize()).append("]");
            }
            o.append("],\"callees\":[");
            first = true;
            for (Function c : f.getCalledFunctions(monitor)) {
                if (!first) o.append(','); first = false;
                o.append("[").append(js(c.getName())).append(',').append(js(c.getPrototypeString(false, false)))
                 .append(',').append(c.getEntryPoint().getOffset()).append("]");
            }
            o.append("]}");
            pw.println(o);
        }
        pw.close();
    }
}
