/* sub_08006A72  (original: 0x08006A72-0x08006B98 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08004FFA();
extern ushort volatile DAT_030007b2;
extern int volatile DAT_03000600;


undefined4 sub_08006A72(int param_1,int param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  unsigned int __frame[7];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_1c (*(short *)((char *)__frame + 0x0))
#define local_1a (*(short *)((char *)__frame + 0x2))
#define local_18 (*(short *)((char *)__frame + 0x4))
#define local_16 (*(short *)((char *)__frame + 0x6))
#define local_14 (*(undefined4 *)((char *)__frame + 0x8))
  uVar3 = **(undefined4 **)(param_1 + 0x1c);
  (*(undefined2 *)((char *)&local_14 + 0)) = (short)uVar3;
  (*(undefined2 *)((char *)&local_14 + 2)) = (short)((uint)uVar3 >> 0x10);
  local_14 = uVar3;
  if (param_2 == 0) {
    iVar5 = (uint)DAT_030007b2 + (int)*(short *)(param_1 + 0x2a);
    local_1c = *(short *)(param_1 + 0x20);
    local_1a = *(short *)(param_1 + 0x22) + (*(undefined2 *)((char *)&local_14 + 2));
    local_18 = *(short *)(param_1 + 0x20) + (short)local_14;
    sVar2 = (short)(iVar5 >> 4);
    local_16 = (*(undefined2 *)((char *)&local_14 + 2)) + sVar2;
    iVar4 = sub_08004FFA(DAT_03000600,&local_1c,0);
    if (iVar4 == 0) {
      uVar3 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x13) = 0;
      *(short *)(param_1 + 0x22) = sVar2;
      *(short *)(param_1 + 0x2a) = (short)iVar5;
      uVar3 = 1;
    }
  }
  else if (param_2 == 1) {
    iVar5 = (int)*(short *)(param_1 + 0x2a) - (uint)DAT_030007b2;
    local_1c = *(short *)(param_1 + 0x20);
    uVar1 = (undefined2)(iVar5 >> 4);
    local_18 = *(short *)(param_1 + 0x20) + (short)local_14;
    local_16 = *(undefined2 *)(param_1 + 0x22);
    local_1a = uVar1;
    iVar4 = sub_08004FFA(DAT_03000600,&local_1c,0);
    if (iVar4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
      *(undefined1 *)(param_1 + 0x13) = 1;
      *(undefined2 *)(param_1 + 0x22) = uVar1;
      *(short *)(param_1 + 0x2a) = (short)iVar5;
    }
  }
  else if (param_2 == 2) {
    iVar5 = (int)*(short *)(param_1 + 0x28) - (uint)DAT_030007b2;
    sVar2 = (short)(iVar5 >> 4);
    local_1a = *(undefined2 *)(param_1 + 0x22);
    local_18 = *(undefined2 *)(param_1 + 0x20);
    local_16 = *(short *)(param_1 + 0x22) + (*(undefined2 *)((char *)&local_14 + 2));
    local_1c = sVar2;
    iVar4 = sub_08004FFA(DAT_03000600,&local_1c,0);
    if (iVar4 == 0) {
      uVar3 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x13) = 2;
      *(short *)(param_1 + 0x20) = sVar2;
      *(short *)(param_1 + 0x28) = (short)iVar5;
      uVar3 = 1;
    }
  }
  else if (param_2 == 3) {
    iVar5 = (uint)DAT_030007b2 + (int)*(short *)(param_1 + 0x28);
    local_1c = *(short *)(param_1 + 0x20) + (short)local_14;
    local_1a = *(undefined2 *)(param_1 + 0x22);
    sVar2 = (short)(iVar5 >> 4);
    local_18 = (short)local_14 + sVar2;
    local_16 = *(short *)(param_1 + 0x22) + (*(undefined2 *)((char *)&local_14 + 2));
    iVar4 = sub_08004FFA(DAT_03000600,&local_1c,0);
    if (iVar4 == 0) {
      uVar3 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x13) = 3;
      *(short *)(param_1 + 0x20) = sVar2;
      *(short *)(param_1 + 0x28) = (short)iVar5;
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

