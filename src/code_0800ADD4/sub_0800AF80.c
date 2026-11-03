/* sub_0800AF80  (original: 0x0800AF80-0x0800B01E in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 97% of instructions covered.
 */
#include "ghidra_types.h"
extern short volatile DAT_03000608;
extern short volatile DAT_0300060a;


undefined4 sub_0800AF80(short *param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  short *psVar4;
  undefined4 local_18;
  
  psVar4 = *(short **)(*(int *)(param_1 + 4) + (uint)*(byte *)((int)param_1 + 0x13) * 4);
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(psVar4 + 2);
  sVar1 = (param_1[0x10] + *psVar4) - DAT_03000608;
  sVar2 = (param_1[0x11] + psVar4[1]) - DAT_0300060a;
  local_18 = CONCAT22(sVar2,sVar1);
  *(undefined4 *)param_1 = local_18;
  if (((((short)(*param_1 + param_1[2]) < 1) || (0xef < sVar1)) ||
      ((short)(param_1[1] + param_1[3]) < 1)) || (0x9f < sVar2)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

