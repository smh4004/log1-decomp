// Ghidra headless post-script: make every function's parameter list part of the database, so callers are decompiled
// with all their arguments.
// args: <arg_counts.txt> (from tools/ghidra/arg_counts.py: "addr nargs")
//
// Ghidra infers a function's parameters while decompiling it, but unless they are committed, a caller is decompiled
// with its own guess of the callee's parameters, and arguments go missing (the text printer called
// sub_08008DBE(obj) instead of sub_08008DBE(obj, ch)). This (1) commits the decompiler's parameters of every
// function, callees before callers (two passes), and (2) where the machine code reads more argument registers than
// that (arg_counts.txt), adds int parameters up to that count. Return types are not touched.
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
        try (BufferedReader br = new BufferedReader(new FileReader(getScriptArgs()[0]))) {
            String l;
            while ((l = br.readLine()) != null) {
                String[] p = l.trim().split("\\s+");
                if (p.length == 2) want.put(Long.parseLong(p[0], 16), Integer.parseInt(p[1]));
            }
        }
        DecompInterface di = new DecompInterface();
        di.setOptions(new DecompileOptions()); di.toggleSyntaxTree(true);
        di.setSimplificationStyle("decompile");
        di.openProgram(currentProgram);
        int committed = 0, widened = 0;
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
            if (n == null || f.getParameterCount() >= n || f.hasVarArgs()) continue;
            List<Variable> ps = new ArrayList<>();
            for (Parameter p : f.getParameters()) ps.add(new ParameterImpl(p.getName(), p.getDataType(), currentProgram));
            for (int i = f.getParameterCount(); i < n; i++)
                ps.add(new ParameterImpl("param_" + (i + 1), IntegerDataType.dataType, currentProgram));
            f.setCustomVariableStorage(false);
            f.replaceParameters(ps, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            widened++;
        }
        println("parameters committed for " + committed + " functions, widened " + widened);
    }
}
