# Scope of the C decompilation

* **Matching C would need ARM ADS 1.1/1.2 `tcpp`**, a proprietary Windows compiler that isn't redistributable and isn't on
  decomp.me. GCC and agbcc can't reproduce its output. So this repo matches in assembly and offers C that is
  **behaviourally equivalent** (tested per function in Unicorn and in whole-game routes), see `docs/decomp.md`.
* For a ROM hack this is enough: the disassembly is fully relocatable (`docs/shifting.md`), so code and data can be changed
  at the source level, and new code can be written in C with GCC and linked next to the original.
* `ref/` gives Ghidra's C for every function as reading material, including the ones not yet replaced.
