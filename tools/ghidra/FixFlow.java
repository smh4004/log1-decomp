// One-time fix-up of an analysed project (run once after import + auto-analysis, NOT read-only so it's saved).
// Ghidra's non-returning-function analysis gets this ROM wrong: it marks armlink veneers (`bx pc; ldr pc, =target`)
// as noreturn, then puts a CALL_RETURN override on every `bl` to them and stops disassembling after the call. Callers
// lose their code after such calls (seen: a fill loop reduced to one call). This clears the noreturn flags and
// the overrides, disassembles the fall-through code and recomputes every function body.
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import java.io.*;

public class FixFlow extends GhidraScript {
    public void run() throws Exception {
        int nr = 0, ov = 0, fx = 0, rm = 0;
        // every label of the disassembly is a global symbol (the decomp build links against them), and auto-analysis
        // starts a function at many of them. Real functions are named sub_*/known names; local labels are _08XXXXXX.
        java.util.List<Function> extra = new java.util.ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            if (f.getName().startsWith("_0")) extra.add(f);
        for (Function f : extra) { currentProgram.getFunctionManager().removeFunction(f.getEntryPoint()); rm++; }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            if (f.hasNoReturn()) { f.setNoReturn(false); nr++; }
        for (Instruction in : currentProgram.getListing().getInstructions(true)) {
            if (in.getFlowOverride() == FlowOverride.CALL_RETURN && in.getMnemonicString().toLowerCase().startsWith("bl")) {
                in.setFlowOverride(FlowOverride.NONE); ov++;
                Address next = in.getMaxAddress().add(1);
                if (getInstructionAt(next) == null) {
                    // disassemble in the caller's mode (Thumb): copy the TMode context of the call instruction
                    ghidra.program.model.lang.Register tm = currentProgram.getRegister("TMode");
                    java.math.BigInteger v = currentProgram.getProgramContext().getValue(tm, in.getAddress(), false);
                    DisassembleCommand dc = new DisassembleCommand(next, null, true);
                    if (v != null) dc.setInitialContext(new ghidra.program.model.lang.RegisterValue(tm, v));
                    dc.applyTo(currentProgram, monitor);
                }
            }
        }
        // the veneers themselves (0x0800EEC0-0x0800EED7: `bx pc; nop; ldr pc, =target`, `ldr ip, =t; bx ip`): model the
        // jump as call-and-return, so the decompiler sees an ordinary function that comes back to its caller
        Address vlo = toAddr(0x0800EEC0L), vhi = toAddr(0x0800EED7L);
        for (Instruction in : currentProgram.getListing().getInstructions(new AddressSet(vlo, vhi), true)) {
            String o = in.toString().toLowerCase();
            if ((o.startsWith("ldr pc") || (o.startsWith("bx ") && !o.contains("lr"))))
                in.setFlowOverride(FlowOverride.CALL_RETURN);
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(new AddressSet(vlo, vhi), true)) {
            if (f.isThunk()) f.setThunkedFunction(null);
            f.setNoReturn(false);
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor)) fx++;
            if (f.hasNoReturn()) { f.setNoReturn(false); nr++; }
        }
        // optional arg: .analysis/ghidra/veneer_sigs.txt from tools/ghidra/veneer_sigs.py ("addr nargs"): give each veneer
        // a fixed `int f(int, ...)` signature so every call site passes the same, complete argument list
        int ns = 0;
        String[] args = getScriptArgs();
        if (args.length > 0) {
            try (BufferedReader br = new BufferedReader(new FileReader(args[0]))) {
                String l;
                while ((l = br.readLine()) != null) {
                    String[] p = l.trim().split("\\s+");
                    if (p.length < 2) continue;
                    Function f = getFunctionAt(toAddr(Long.parseLong(p[0], 16)));
                    if (f == null) continue;
                    int n = Integer.parseInt(p[1]);
                    FunctionDefinitionDataType sig = new FunctionDefinitionDataType(f.getName());
                    ParameterDefinition[] ps = new ParameterDefinition[n];
                    for (int i = 0; i < n; i++) ps[i] = new ParameterDefinitionImpl("a" + i, IntegerDataType.dataType, null);
                    sig.setArguments(ps);
                    sig.setReturnType(IntegerDataType.dataType);
                    if (new ApplyFunctionSignatureCmd(f.getEntryPoint(), sig, SourceType.USER_DEFINED).applyTo(currentProgram, monitor)) ns++;
                }
            }
        }
        println("label functions removed " + rm + ", noreturn cleared " + nr + ", CALL_RETURN overrides cleared " + ov + ", bodies fixed " + fx + ", veneer signatures " + ns);
    }
}
