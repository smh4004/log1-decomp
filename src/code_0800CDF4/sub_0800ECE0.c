/* sub_0800ECE0  (original: 0x0800ECE0-0x0800ECFC in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_long.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern undefined * volatile DAT_030000fc;
extern undefined * volatile DAT_03000104;
extern undefined volatile _0800F100;
extern undefined volatile _0800F164;


void sub_0800ECE0(void)

{
  DAT_030000fc = &_0800F100;
  DAT_03000104 = &_0800F164;
  return;
}

