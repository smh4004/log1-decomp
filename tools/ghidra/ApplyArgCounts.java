// Ghidra headless post-script: make every function's parameter list part of the database, so callers are decompiled
// with all their arguments.
// args: <arg_counts.txt> (from tools/ghidra/arg_counts.py: "addr nargs")
//
// Ghidra infers a function's parameters while decompiling it, but unless they are committed, a caller is decompiled
// with its own guess of the callee's parameters, and arguments go missing (the text printer called
// sub_08008DBE(obj) instead of sub_08008DBE(obj, ch)). This (1) commits the decompiler's parameters of every
// function, callees before callers (two passes), and (2) where the machine code reads more argument registers than
// that (arg_counts.txt), adds int parameters up to that count; where the decompiler committed more (it assumes a call
// through a register passes r1-r3 along), drops the extra ones. Functions marked `varargs` there get only their named
// parameters and `...` (their prologue spills r0-r3, which would otherwise look like 4 fixed parameters and make
// every caller pass registers it never set). Return types are not touched.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.*;

public class ApplyArgCounts extends GhidraScript {
    public void run() throws Exception {
        Map<Long, Integer> want = new HashMap<>();
        Set<Long> varargs = new HashSet<>();
        try (BufferedReader br = new BufferedReader(new FileReader(getScriptArgs()[0]))) {
            String l;
            while ((l = br.readLine()) != null) {
                String[] p = l.trim().split("\\s+");
                if (p.length >= 2) want.put(Long.parseLong(p[0], 16), Integer.parseInt(p[1]));
                if (p.length >= 3 && p[2].equals("varargs")) varargs.add(Long.parseLong(p[0], 16));
            }
        }
        DecompInterface di = new DecompInterface();
        di.setOptions(new DecompileOptions()); di.toggleSyntaxTree(true);
        di.setSimplificationStyle("decompile");
        di.openProgram(currentProgram);
        int committed = 0, widened = 0;
        // variadic functions first: named parameters only, plus `...`, so call sites keep every argument they pass
        for (Long a : varargs) {
            Function f = getFunctionAt(toAddr(a));
            if (f == null) continue;
            List<Variable> ps = new ArrayList<>();
            for (int i = 0; i < want.get(a) && i < f.getParameterCount(); i++)
                ps.add(new ParameterImpl(f.getParameter(i).getName(), f.getParameter(i).getDataType(), currentProgram));
            f.setCustomVariableStorage(false);
            f.replaceParameters(ps, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            f.setVarArgs(true);
        }
        for (int pass = 0; pass < 2; pass++) {
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Function f = it.next();
                if (f.isThunk() || f.hasVarArgs()) continue;
                DecompileResults r = di.decompileFunction(f, 90, monitor);
                if (r == null || !r.decompileCompleted()) continue;
                HighFunction hf = r.getHighFunction();
                try {
                    HighFunctionDBUtil.commitParamsToDatabase(hf, true, HighFunctionDBUtil.ReturnCommitOption.NO_COMMIT, SourceType.USER_DEFINED);
                    if (pass == 0) committed++;
                } catch (Exception e) { println("commit failed " + f.getName() + ": " + e); }
            }
        }
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            Integer n = want.get(f.getEntryPoint().getOffset());
            if (n == null || f.getParameterCount() == n || f.hasVarArgs() || f.getName().startsWith("__call_via")) continue;
            if (n == 4 && f.getParameterCount() > 4) continue;     // all four registers used: the rest are stack arguments
            List<Variable> ps = new ArrayList<>();
            for (Parameter p : f.getParameters())
                if (ps.size() < n) ps.add(new ParameterImpl(p.getName(), p.getDataType(), currentProgram));
            for (int i = f.getParameterCount(); i < n; i++)
                ps.add(new ParameterImpl("param_" + (i + 1), IntegerDataType.dataType, currentProgram));
            f.setCustomVariableStorage(false);
            f.replaceParameters(ps, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            widened++;
        }
        println("parameters committed for " + committed + " functions, set to the machine-code count for " + widened);
    }
}
