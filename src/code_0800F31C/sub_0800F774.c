/* sub_0800F774  (original: 0x0800F774-0x0800F9AC in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: equal, mem@03000000, stack-garbage:mem@03000000.
 */
#include "ghidra_types.h"
extern int sub_08005CA8();
extern int sub_08005CD6();
extern int sub_0800F6A0();
extern int sub_0800F450();
extern int sub_08007416();
extern int sub_08006F1A();
extern int volatile DAT_030007dc;


void sub_0800F774(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  unsigned int __frame[10];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_28 (*(undefined4 *)((char *)__frame + 0x0))
#define local_24 (*(undefined4 *)((char *)__frame + 0x4))
#define uStack_20 (*(undefined4 *)((char *)__frame + 0x8))
#define uStack_1c (*(undefined4 *)((char *)__frame + 0xc))
#define uStack_18 (*(uint *)((char *)__frame + 0x10))
  puVar6 = (undefined1 *)(param_1 + 8);
  iVar7 = param_2 + 8;
  if (param_3 < 2) {
    if (DAT_030007dc != 0) {
      return;
    }
    uVar2 = sub_0800F450((int)puVar6);
    uVar3 = sub_0800F450(iVar7);
    (*(undefined2 *)((char *)&local_24 + 0)) = (short)uVar3;
    (*(undefined2 *)((char *)&local_28 + 0)) = (short)uVar2;
    (*(undefined2 *)((char *)&local_28 + 2)) = (short)((uint)uVar2 >> 0x10);
    (*(undefined2 *)((char *)&local_24 + 2)) = (short)((uint)uVar3 >> 0x10);
    if (((int)(short)local_28 - (int)(short)local_24) *
        ((int)(short)local_28 - (int)(short)local_24) <
        ((int)(*(undefined2 *)((char *)&local_28 + 2)) - (int)(*(undefined2 *)((char *)&local_24 + 2))) * ((int)(*(undefined2 *)((char *)&local_28 + 2)) - (int)(*(undefined2 *)((char *)&local_24 + 2)))) {
      if ((*(undefined2 *)((char *)&local_28 + 2)) < (*(undefined2 *)((char *)&local_24 + 2))) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else if ((short)local_28 < (short)local_24) {
      uVar1 = 3;
    }
    else {
      uVar1 = 2;
    }
    *puVar6 = uVar1;
    local_24 = uVar3;
    iVar7 = sub_08005CA8(*(int *)(param_1 + 0x4c) >> 1);
    sub_08007416(param_1,param_2,0,iVar7 + (*(int *)(param_1 + 0x4c) >> 2));
    return;
  }
  uVar2 = sub_0800F450((int)puVar6);
  if (*(int *)(param_1 + 0x58) >> 4 < *(int *)(param_1 + 0x54)) {
    uStack_18 = (uint)*(byte *)(param_2 + 0x2a);
    (*(undefined2 *)((char *)&uStack_20 + 0)) = (short)uVar2;
    uVar4 = (uint)(*(byte *)(param_2 + 0x2a) >> 1);
    if (((int)(short)uStack_20 <= (int)((int)*(short *)(param_2 + 0x20) - uVar4)) ||
       ((int)((int)*(short *)(param_2 + 0x20) + uStack_18 + uVar4) <= (int)(short)uStack_20)) {
      (*(undefined2 *)((char *)&uStack_20 + 2)) = (short)((uint)uVar2 >> 0x10);
      uVar4 = (uint)(*(byte *)(param_2 + 0x2b) >> 1);
      if (((int)(*(undefined2 *)((char *)&uStack_20 + 2)) <= (int)((int)*(short *)(param_2 + 0x22) - uVar4)) ||
         ((int)((int)*(short *)(param_2 + 0x22) + (uint)*(byte *)(param_2 + 0x2b) + uVar4) <=
          (int)(*(undefined2 *)((char *)&uStack_20 + 2)))) goto _0800F8E4;
    }
    uStack_20 = uVar2;
    iVar5 = sub_08005CA8(100);
    uVar2 = uStack_20;
    if ((iVar5 < 2) && (DAT_030007dc == 0)) {
      if (*(byte *)(param_1 + 9) == 4) {
        return;
      }
      if (3 < *(byte *)(param_1 + 9)) {
        *(undefined1 *)(param_1 + 10) = 0x2d;
      }
      *(undefined1 *)(param_1 + 9) = 4;
      uVar2 = sub_0800F450((int)puVar6);
      uVar3 = sub_0800F450(iVar7);
      (*(undefined2 *)((char *)&local_24 + 0)) = (short)uVar3;
      (*(undefined2 *)((char *)&local_28 + 0)) = (short)uVar2;
      (*(undefined2 *)((char *)&local_28 + 2)) = (short)((uint)uVar2 >> 0x10);
      (*(undefined2 *)((char *)&local_24 + 2)) = (short)((uint)uVar3 >> 0x10);
      if (((int)(short)local_28 - (int)(short)local_24) *
          ((int)(short)local_28 - (int)(short)local_24) <
          ((int)(*(undefined2 *)((char *)&local_28 + 2)) - (int)(*(undefined2 *)((char *)&local_24 + 2))) * ((int)(*(undefined2 *)((char *)&local_28 + 2)) - (int)(*(undefined2 *)((char *)&local_24 + 2))))
      {
        if ((*(undefined2 *)((char *)&local_28 + 2)) < (*(undefined2 *)((char *)&local_24 + 2))) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else if ((short)local_28 < (short)local_24) {
        uVar1 = 3;
      }
      else {
        uVar1 = 2;
      }
      *puVar6 = uVar1;
      local_24 = uVar3;
      iVar7 = sub_08005CA8(*(int *)(param_1 + 0x54) >> 1);
      sub_08005CD6(param_1,0,iVar7 + (*(int *)(param_1 + 0x54) >> 2));
      return;
    }
  }
_0800F8E4:
  uStack_20 = uVar2;
  sub_0800F450((int)puVar6);
  local_24 = sub_0800F450(iVar7);
  uStack_1c = *(undefined4 *)(param_2 + 0x20);
  if (*(short *)(param_1 + 0x1c) < 0xf) {
    local_28 = CONCAT22((short)((int)uStack_1c >> 0x13),(short)uStack_1c >> 3);
    local_24 = local_28;
    iVar7 = sub_08006F1A(param_1,(short *)&local_24,0);
    if (iVar7 == 0) {
      *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + 1;
    }
    else {
      *(undefined2 *)(param_1 + 0x1c) = 0;
    }
  }
  else {
    sub_0800F6A0(param_1,*(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x7c));
    *(undefined2 *)(param_1 + 0x1c) = 0;
  }
  return;
}

