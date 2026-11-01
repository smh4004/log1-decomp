/* sub_080055A0  (original: 0x080055A0-0x080055C4 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 87% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08000954();
extern int sub_08004CAC();
extern undefined4 volatile gUnknown_085439E0;


undefined4 sub_080055A0(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954();
  if ((iVar1 == 0) &&
     (iVar1 = sub_08004CAC((&gUnknown_085439E0)[*(byte *)(param_1 + 6)]), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

