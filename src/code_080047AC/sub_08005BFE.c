/* sub_08005BFE  (original: 0x08005BFE-0x08005C32 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 10/10 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08006D70();
extern int volatile DAT_03000988;
extern undefined volatile DAT_080114ac;
extern undefined volatile DAT_080114b0;


bool sub_08005BFE(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x50);
  iVar1 = DAT_03000988 * 0x10;
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(&DAT_080114b0 + iVar1);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(&DAT_080114ac + iVar1);
  sub_08006D70(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (*(int *)(param_1 + 0x50) - iVar2);
  return iVar2 < *(int *)(param_1 + 0x50);
}

