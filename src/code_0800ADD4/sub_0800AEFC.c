/* sub_0800AEFC  (original: 0x0800AEFC-0x0800AF80 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern short volatile DAT_03000608;
extern short volatile DAT_0300060a;


undefined4 sub_0800AEFC(short *param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 local_10;
  
  sVar1 = param_1[0x11] - DAT_0300060a;
  sVar2 = param_1[0x10] - DAT_03000608;
  local_10 = CONCAT22(sVar1,sVar2);
  *(undefined4 *)param_1 = local_10;
  if (((((short)(*param_1 + param_1[2]) < 1) || (0xef < sVar2)) ||
      ((short)(param_1[1] + param_1[3]) < 1)) || (0x9f < sVar1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

