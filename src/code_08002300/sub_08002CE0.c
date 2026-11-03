/* sub_08002CE0  (original: 0x08002CE0-0x08002E30 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 21% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08004FFA();
extern int sub_08002134();
extern int sub_08002328();
extern int sub_0800F3C4();
extern ushort volatile DAT_030007b2;
extern ushort volatile DAT_03003d12;
extern short volatile DAT_030007c2;
extern short volatile DAT_030007c0;
extern int volatile DAT_03000600;
extern short volatile DAT_030005fa;
extern short volatile DAT_030005f8;
extern undefined2 volatile gUnknown_08010840;


void sub_08002CE0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  unsigned int __frame[9];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_24 ((short *)((char *)__frame + 0x0))
#define uStack_20 (*(undefined4 *)((char *)__frame + 0x4))
#define local_1c (*(short *)((char *)__frame + 0x8))
#define local_1a (*(short *)((char *)__frame + 0xa))
  iVar2 = (uint)DAT_030007b2 * param_2;
  uVar4 = (uint)DAT_03003d12;
  if ((int)(uVar4 << 0x19) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 1;
    iVar2 = DAT_030007c2 - iVar2;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    local_1c = DAT_030007c0 >> 4;
    local_1a = (short)(iVar2 >> 4);
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar1 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar1 != 0) {
      DAT_030007c2 = (short)iVar2;
    }
  }
  else if ((int)(uVar4 << 0x18) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 0;
    iVar3 = (DAT_030005fa + -8) * 0x10;
    iVar1 = DAT_030007c2 + iVar2;
    if (iVar3 < DAT_030007c2 + iVar2) {
      iVar1 = iVar3;
    }
    local_1c = DAT_030007c0 >> 4;
    local_1a = (short)(iVar1 >> 4);
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar2 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar2 != 0) {
      DAT_030007c2 = (short)iVar1;
    }
  }
  else if ((int)(uVar4 << 0x1a) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 2;
    iVar2 = DAT_030007c0 - iVar2;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    local_1c = (short)(iVar2 >> 4);
    local_1a = DAT_030007c2 >> 4;
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar1 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar1 != 0) {
      DAT_030007c0 = (short)iVar2;
    }
  }
  else if ((int)(uVar4 << 0x1b) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 3;
    iVar3 = (DAT_030005f8 + -0x10) * 0x10;
    iVar1 = DAT_030007c0 + iVar2;
    if (iVar3 < DAT_030007c0 + iVar2) {
      iVar1 = iVar3;
    }
    local_1c = (short)(iVar1 >> 4);
    local_1a = DAT_030007c2 >> 4;
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar2 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar2 != 0) {
      DAT_030007c0 = (short)iVar1;
    }
  }
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c != 0) {
    uStack_20 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
    *(undefined4 *)(param_1 + 0x20) = uStack_20;
    sub_08002328((undefined4 *)asStack_24,param_1);
    sub_08002134(asStack_24);
  }
  return;
}

