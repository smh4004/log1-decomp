# Scope of the C decompilation

* Matching C would need the original ARM compiler (SDT 2.5x / ADS 1.0 era `tcpp`), which isn't redistributable. This repo
  matches in assembly and offers C that is **behaviourally equivalent** (tested per function in Unicorn and in
  whole-game routes, `docs/decomp.md`).
* The disassembly is fully relocatable (`docs/shifting.md`), so code and data can be changed at the source level, and
  new code can be written in C with GCC and linked next to the original.
* `ref/` has Ghidra's C for every function as reading material.
