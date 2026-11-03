/* sub_0800B436  (original: 0x0800B436-0x0800B4AE in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 96% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080028C4();
extern int sub_0800279E();
extern int sub_0800241E();
extern uint volatile DAT_03003b6c;
extern undefined volatile DAT_08011e50;
extern undefined volatile DAT_08011e52;
extern undefined volatile DAT_08011e54;


void sub_0800B436(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_14;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  iVar1 = (uint)*(byte *)(iVar2 + 0x13) * 6;
  *(byte *)(param_1 + 0x13) = *(byte *)(iVar2 + 0x13);
  local_14 = CONCAT22(*(short *)(iVar2 + 0x22) + *(short *)(&DAT_08011e52 + iVar1),
                      *(short *)(iVar2 + 0x20) + *(short *)(&DAT_08011e50 + iVar1));
  *(undefined4 *)(param_1 + 0x20) = local_14;
  *(char *)(param_1 + 0xc) = (char)*(undefined2 *)(&DAT_08011e54 + iVar1);
  iVar2 = *(int *)(param_1 + 0x3c);
  iVar1 = sub_0800279E(iVar2);
  if ((iVar1 == 0) || (iVar1 = sub_0800241E(iVar2), iVar1 != 5)) {
    sub_080028C4(param_1);
  }
  else if ((DAT_03003b6c & 7) == 0) {
    iVar1 = *(int *)(*(int *)(iVar2 + 0x3c) + 0x54);
    if (param_2 <= iVar1) {
      *(int *)(*(int *)(iVar2 + 0x3c) + 0x54) = iVar1 - param_2;
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + param_2;
    }
  }
  return;
}

