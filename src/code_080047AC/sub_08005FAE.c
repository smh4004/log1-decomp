/* sub_08005FAE  (original: 0x08005FAE-0x08005FC0 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 4/4 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_03000076;


void sub_08005FAE(int param_1)

{
  (&DAT_03000076)[*(byte *)(param_1 + 4)] = *(undefined1 *)(param_1 + 5);
  return;
}

