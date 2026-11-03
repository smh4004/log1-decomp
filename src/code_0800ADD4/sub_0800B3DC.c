/* sub_0800B3DC  (original: 0x0800B3DC-0x0800B3FC in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002716();
extern int sub_08002486();
extern undefined volatile DAT_08011e38;
extern undefined volatile gUnknown_08011E44;


void sub_0800B3DC(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = sub_08002716(param_1);
  *(int *)(iVar1 + 0x3c) = param_1;
  sub_08002486(iVar1,*(int *)(&DAT_08011e38 + param_2 * 4),
               *(undefined4 *)(&gUnknown_08011E44 + param_2 * 4),0);
  return;
}

