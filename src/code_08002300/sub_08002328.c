/* sub_08002328  (original: 0x08002328-0x0800236E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08002328(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  short *psVar3;
  short sVar4;
  undefined4 local_c;
  
  psVar3 = (short *)**(undefined4 **)(param_2 + 8);
  sVar4 = *(short *)(param_2 + 0x20) + *psVar3;
  sVar2 = *(short *)(param_2 + 0x22) + psVar3[1];
  local_c = CONCAT22(sVar2,sVar4);
  uVar1 = local_c;
  local_c = CONCAT22(sVar2 + psVar3[3],sVar4 + psVar3[2]);
  *param_1 = uVar1;
  param_1[1] = local_c;
  return;
}

