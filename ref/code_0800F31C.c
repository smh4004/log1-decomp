/* Ghidra reference decompilation of code_0800F31C (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_0800F31C @ 0x0800F31C */

void sub_0800F31C(undefined4 param_1)

{
  __call_via_r1(param_1,*(undefined **)(DAT_03004630 + 8));
  return;
}


/* sub_0800F31E @ 0x0800F31E */

void sub_0800F31E(undefined4 param_1,int param_2)

{
  __call_via_r1(param_1,*(undefined **)(*(int *)(param_2 + 8) + 8));
  return;
}


/* sub_0800F330 @ 0x0800F330 */

void sub_0800F330(void)

{
  return;
}


/* sub_0800F332 @ 0x0800F332 */

void sub_0800F332(int param_1)

{
  DAT_0300462c = 0;
  return;
}


/* sub_0800F334 @ 0x0800F334 */

void sub_0800F334(void)

{
  DAT_0300462c = 0;
  return;
}


/* sub_0800F340 @ 0x0800F340 */

void sub_0800F340(undefined4 param_1,undefined4 param_2)

{
  __call_via_r2(param_1,param_2,*(undefined **)(DAT_03004630 + 0x10));
  return;
}


/* sub_0800F342 @ 0x0800F342 */

void sub_0800F342(undefined4 param_1,undefined4 param_2,int param_3)

{
  __call_via_r2(param_1,param_2,*(undefined **)(*(int *)(param_3 + 8) + 0x10));
  return;
}


/* sub_0800F354 @ 0x0800F354 */

void sub_0800F354(void)

{
  return;
}


/* sub_0800F356 @ 0x0800F356 */

void sub_0800F356(short *param_1,int param_2)

{
  sub_08004FFA(DAT_03000600,param_1,param_2);
  return;
}


/* sub_0800F358 @ 0x0800F358 */

void sub_0800F358(short *param_1,int param_2)

{
  sub_08004FFA(DAT_03000600,param_1,param_2);
  return;
}


/* sub_0800F36C @ 0x0800F36C */

undefined4 sub_0800F36C(short *param_1)

{
  undefined4 local_8;
  
  local_8 = CONCAT22((short)(param_1[1] + param_1[3]) >> 1,(short)(*param_1 + param_1[2]) >> 1);
  return local_8;
}


/* sub_0800F39C @ 0x0800F39C */

void sub_0800F39C(int *param_1)

{
  __call_via_r1(param_1,(undefined *)(*(int *)*param_1 + *param_1));
  return;
}


/* sub_0800F3AA @ 0x0800F3AA */

undefined4 sub_0800F3AA(undefined4 param_1)

{
  return param_1;
}


/* sub_0800F3AC @ 0x0800F3AC */

void sub_0800F3AC(void)

{
  return;
}


/* sub_0800F3AE @ 0x0800F3AE */

undefined4 sub_0800F3AE(int param_1)

{
  return 0;
}


/* sub_0800F3B0 @ 0x0800F3B0 */

undefined4 sub_0800F3B0(void)

{
  return 0;
}


/* sub_0800F3B4 @ 0x0800F3B4 */

void sub_0800F3B4(void)

{
  return;
}


/* sub_0800F3B6 @ 0x0800F3B6 */

undefined4 sub_0800F3B6(undefined4 param_1)

{
  return param_1;
}


/* sub_0800F3B8 @ 0x0800F3B8 */

void sub_0800F3B8(void)

{
  return;
}


/* sub_0800F3BA @ 0x0800F3BA */

undefined4 sub_0800F3BA(undefined4 param_1)

{
  return param_1;
}


/* sub_0800F3BC @ 0x0800F3BC */

void sub_0800F3BC(void)

{
  return;
}


/* sub_0800F3BE @ 0x0800F3BE */

undefined4 sub_0800F3BE(int param_1)

{
  return 0;
}


/* sub_0800F3C0 @ 0x0800F3C0 */

undefined4 sub_0800F3C0(void)

{
  return 0;
}


/* sub_0800F3C4 @ 0x0800F3C4 */

void sub_0800F3C4(short *param_1,short *param_2)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(param_1[1] + param_2[1],*param_1 + *param_2);
  *(undefined4 *)(param_1 + 2) = local_8;
  return;
}


/* sub_0800F3E4 @ 0x0800F3E4 */

void sub_0800F3E4(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


/* sub_0800F3EA @ 0x0800F3EA */

undefined4 sub_0800F3EA(undefined4 param_1)

{
  return param_1;
}


/* sub_0800F3EC @ 0x0800F3EC */

void sub_0800F3EC(void)

{
  return;
}


/* sub_0800F3EE @ 0x0800F3EE */

void sub_0800F3EE(undefined2 *param_1,undefined2 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


/* sub_0800F3F0 @ 0x0800F3F0 */

void sub_0800F3F0(undefined2 *param_1,undefined2 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


/* sub_0800F404 @ 0x0800F404 */

undefined4 sub_0800F404(short *param_1,uint param_2)

{
  return CONCAT22((short)((int)param_1[1] << (param_2 & 0xff)),
                  (short)((int)*param_1 << (param_2 & 0xff)));
}


/* sub_0800F41E @ 0x0800F41E */

void sub_0800F41E(short *param_1,byte *param_2,short *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  
  bVar1 = *param_2;
  sVar5 = *param_3;
  bVar2 = param_2[2];
  sVar6 = param_3[1];
  bVar3 = param_2[1];
  bVar4 = param_2[3];
  *param_1 = (ushort)bVar1 + sVar5;
  param_1[1] = (ushort)bVar3 + sVar6;
  param_1[2] = (ushort)bVar1 + (ushort)bVar2 + sVar5;
  param_1[3] = (ushort)bVar3 + (ushort)bVar4 + sVar6;
  return;
}


/* sub_0800F420 @ 0x0800F420 */

void sub_0800F420(short *param_1,byte *param_2,short *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  
  bVar1 = *param_2;
  sVar5 = *param_3;
  bVar2 = param_2[2];
  sVar6 = param_3[1];
  bVar3 = param_2[1];
  bVar4 = param_2[3];
  *param_1 = (ushort)bVar1 + sVar5;
  param_1[1] = (ushort)bVar3 + sVar6;
  param_1[2] = (ushort)bVar1 + (ushort)bVar2 + sVar5;
  param_1[3] = (ushort)bVar3 + (ushort)bVar4 + sVar6;
  return;
}


/* sub_0800F44E @ 0x0800F44E */

undefined4 sub_0800F44E(int param_1)

{
  undefined4 uStack_4;
  
  uStack_4._0_2_ = (short)*(undefined4 *)(param_1 + 0x18);
  uStack_4._2_2_ = (short)((uint)*(undefined4 *)(param_1 + 0x18) >> 0x10);
  uStack_4 = CONCAT22(uStack_4._2_2_ + (ushort)(*(byte *)(param_1 + 0x23) >> 1),
                      (short)uStack_4 + (ushort)(*(byte *)(param_1 + 0x22) >> 1));
  return uStack_4;
}


/* sub_0800F450 @ 0x0800F450 */

undefined4 sub_0800F450(int param_1)

{
  undefined4 local_4;
  
  local_4._0_2_ = (short)*(undefined4 *)(param_1 + 0x18);
  local_4._2_2_ = (short)((uint)*(undefined4 *)(param_1 + 0x18) >> 0x10);
  local_4 = CONCAT22(local_4._2_2_ + (ushort)(*(byte *)(param_1 + 0x23) >> 1),
                     (short)local_4 + (ushort)(*(byte *)(param_1 + 0x22) >> 1));
  return local_4;
}


/* sub_0800F476 @ 0x0800F476 */

void sub_0800F476(int param_1,undefined4 param_2)

{
  undefined4 uStack_20;
  undefined2 uStack_18;
  undefined2 uStack_16;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  uStack_18 = (short)param_2;
  uStack_16 = (short)((uint)param_2 >> 0x10);
  uStack_20 = CONCAT22(uStack_16 << 4,uStack_18 << 4);
  *(undefined4 *)(param_1 + 0x1c) = uStack_20;
  *(ushort *)(param_1 + 0x24) = (ushort)*(byte *)(param_1 + 0x20) + *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x26) = (ushort)*(byte *)(param_1 + 0x21) + *(short *)(param_1 + 0x1a);
  *(ushort *)(param_1 + 0x28) =
       (ushort)*(byte *)(param_1 + 0x20) + (ushort)*(byte *)(param_1 + 0x22) +
       *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x2a) =
       (ushort)*(byte *)(param_1 + 0x21) + (ushort)*(byte *)(param_1 + 0x23) +
       *(short *)(param_1 + 0x1a);
  return;
}


/* sub_0800F478 @ 0x0800F478 */

void sub_0800F478(int param_1,undefined4 param_2)

{
  undefined4 local_20;
  undefined2 local_18;
  undefined2 uStack_16;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  local_18 = (short)param_2;
  uStack_16 = (short)((uint)param_2 >> 0x10);
  local_20 = CONCAT22(uStack_16 << 4,local_18 << 4);
  *(undefined4 *)(param_1 + 0x1c) = local_20;
  *(ushort *)(param_1 + 0x24) = (ushort)*(byte *)(param_1 + 0x20) + *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x26) = (ushort)*(byte *)(param_1 + 0x21) + *(short *)(param_1 + 0x1a);
  *(ushort *)(param_1 + 0x28) =
       (ushort)*(byte *)(param_1 + 0x20) + (ushort)*(byte *)(param_1 + 0x22) +
       *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x2a) =
       (ushort)*(byte *)(param_1 + 0x21) + (ushort)*(byte *)(param_1 + 0x23) +
       *(short *)(param_1 + 0x1a);
  return;
}


/* sub_0800F4DA @ 0x0800F4DA */

void sub_0800F4DA(int param_1)

{
  undefined4 uStack_14;
  
  uStack_14 = CONCAT22(*(short *)(param_1 + 0x1e) >> 4,*(short *)(param_1 + 0x1c) >> 4);
  *(undefined4 *)(param_1 + 0x18) = uStack_14;
  *(ushort *)(param_1 + 0x24) = (ushort)*(byte *)(param_1 + 0x20) + *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x26) = (ushort)*(byte *)(param_1 + 0x21) + *(short *)(param_1 + 0x1a);
  *(ushort *)(param_1 + 0x28) =
       (ushort)*(byte *)(param_1 + 0x20) + (ushort)*(byte *)(param_1 + 0x22) +
       *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x2a) =
       (ushort)*(byte *)(param_1 + 0x21) + (ushort)*(byte *)(param_1 + 0x23) +
       *(short *)(param_1 + 0x1a);
  return;
}


/* sub_0800F4DC @ 0x0800F4DC */

void sub_0800F4DC(int param_1)

{
  undefined4 local_14;
  
  local_14 = CONCAT22(*(short *)(param_1 + 0x1e) >> 4,*(short *)(param_1 + 0x1c) >> 4);
  *(undefined4 *)(param_1 + 0x18) = local_14;
  *(ushort *)(param_1 + 0x24) = (ushort)*(byte *)(param_1 + 0x20) + *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x26) = (ushort)*(byte *)(param_1 + 0x21) + *(short *)(param_1 + 0x1a);
  *(ushort *)(param_1 + 0x28) =
       (ushort)*(byte *)(param_1 + 0x20) + (ushort)*(byte *)(param_1 + 0x22) +
       *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x2a) =
       (ushort)*(byte *)(param_1 + 0x21) + (ushort)*(byte *)(param_1 + 0x23) +
       *(short *)(param_1 + 0x1a);
  return;
}


/* sub_0800F53E @ 0x0800F53E */

int sub_0800F53E(short *param_1,short *param_2)

{
  return (int)(short)(*param_1 - *param_2) * (int)(short)(*param_1 - *param_2) +
         (int)(short)(param_1[1] - param_2[1]) * (int)(short)(param_1[1] - param_2[1]);
}


/* sub_0800F540 @ 0x0800F540 */

int sub_0800F540(short *param_1,short *param_2)

{
  return (int)(short)(*param_1 - *param_2) * (int)(short)(*param_1 - *param_2) +
         (int)(short)(param_1[1] - param_2[1]) * (int)(short)(param_1[1] - param_2[1]);
}


/* sub_0800F56E @ 0x0800F56E */

int sub_0800F56E(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 - param_3;
  iVar3 = -iVar1;
  if (-1 < iVar1) {
    iVar3 = iVar1;
  }
  iVar2 = param_2 - param_4;
  iVar1 = -iVar2;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  return iVar3 + iVar1;
}


/* sub_0800F570 @ 0x0800F570 */

int sub_0800F570(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 - param_3;
  iVar3 = -iVar1;
  if (-1 < iVar1) {
    iVar3 = iVar1;
  }
  iVar2 = param_2 - param_4;
  iVar1 = -iVar2;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  return iVar3 + iVar1;
}


/* sub_0800F588 @ 0x0800F588 */

undefined4 * sub_0800F588(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  iVar2 = *param_3;
  *param_3 = iVar2 + 1;
  puVar10 = (undefined4 *)((iVar2 + 1) * 0x14 + param_2);
  uVar3 = param_1[1];
  uVar8 = param_1[2];
  *puVar10 = *param_1;
  puVar10[1] = uVar3;
  puVar10[2] = uVar8;
  uVar3 = param_1[4];
  puVar1 = param_1 + 5;
  puVar10[3] = param_1[3];
  puVar10[4] = uVar3;
  iVar2 = *param_3;
  if (1 < iVar2) {
    puVar1 = (undefined4 *)(iVar2 * 0x14 + param_2);
    uVar3 = *puVar1;
    uVar8 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    puVar1 = (undefined4 *)puVar1[4];
    *(undefined4 *)(param_2 + 0x10) = 0xfffe7960;
    iVar6 = *(int *)((iVar2 >> 1) * 0x14 + param_2 + 0x10);
    while ((int)puVar1 < iVar6) {
      puVar11 = (undefined4 *)(iVar2 * 0x14 + param_2);
      puVar10 = (undefined4 *)((iVar2 >> 1) * 0x14 + param_2);
      uVar7 = puVar10[1];
      uVar9 = puVar10[2];
      *puVar11 = *puVar10;
      puVar11[1] = uVar7;
      puVar11[2] = uVar9;
      uVar7 = puVar10[4];
      puVar11[3] = puVar10[3];
      puVar11[4] = uVar7;
      iVar6 = *(int *)((iVar2 >> 2) * 0x14 + param_2 + 0x10);
      iVar2 = iVar2 >> 1;
    }
    puVar10 = (undefined4 *)(iVar2 * 0x14 + param_2);
    puVar10[4] = puVar1;
    puVar10[3] = uVar5;
    puVar10[2] = uVar4;
    puVar10[1] = uVar8;
    *puVar10 = uVar3;
  }
  return puVar1;
}


/* sub_0800F628 @ 0x0800F628 */

void sub_0800F628(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar1 = *param_3;
  *param_3 = iVar1 + 1;
  puVar5 = (undefined4 *)((iVar1 + 1) * 0x14 + param_2);
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  *puVar5 = *param_1;
  puVar5[1] = uVar3;
  puVar5[2] = uVar4;
  uVar3 = param_1[4];
  puVar5[3] = param_1[3];
  puVar5[4] = uVar3;
  iVar1 = *param_3;
  if (1 < iVar1) {
    while ((iVar1 = iVar1 + -1, 1 < iVar1 &&
           (puVar5 = (undefined4 *)(iVar1 * 0x14 + param_2), (int)puVar5[3] < (int)puVar5[-2]))) {
      uVar3 = puVar5[2];
      uVar6 = *puVar5;
      uVar7 = puVar5[1];
      uVar4 = puVar5[3];
      uVar2 = puVar5[4];
      *puVar5 = puVar5[-5];
      puVar5[1] = puVar5[-4];
      puVar5[2] = puVar5[-3];
      puVar5[3] = puVar5[-2];
      puVar5[4] = puVar5[-1];
      puVar5[-1] = uVar2;
      puVar5[-2] = uVar4;
      puVar5[-3] = uVar3;
      puVar5[-5] = uVar6;
      puVar5[-4] = uVar7;
    }
  }
  return;
}


/* sub_0800F69E @ 0x0800F69E */

void sub_0800F69E(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uStack_38;
  short asStack_34 [4];
  short asStack_2c [4];
  short sStack_24;
  short sStack_22;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (*(int *)(param_1 + 0xac) + -1 <= *(int *)(param_1 + 0xa8)) {
    iVar4 = (int)*(short *)(param_1 + 0x48);
    if (0xe < iVar4) {
      iVar4 = 0xe;
    }
    if (0 < iVar4) {
      iStack_20 = param_1;
      uStack_1c = param_2;
      uStack_18 = param_3;
      sVar2 = sub_08005CA8(iVar4);
      sVar3 = sub_08005CA8(iVar4);
      sVar1 = (short)(iVar4 >> 1);
      sub_0800F3E4(&sStack_24,(sVar1 - sVar2) + (short)uStack_1c,(sVar1 - sVar3) + (short)param_3);
      if (sStack_24 < DAT_03003b38) {
        sStack_24 = DAT_03003b38;
      }
      if (sStack_22 < DAT_03003b3a) {
        sStack_22 = DAT_03003b3a;
      }
      if (DAT_03003b3c < sStack_24) {
        sStack_24 = DAT_03003b3c;
      }
      if (DAT_03003b3e < sStack_22) {
        sStack_22 = DAT_03003b3e;
      }
      uStack_38 = sub_0800F404(&sStack_24,3);
      sub_0800F420(asStack_34,(byte *)(param_1 + 0x28),(short *)&uStack_38);
      sub_0800F3F0(asStack_2c,asStack_34);
      iVar4 = sub_0800F358(asStack_2c,0);
      if (iVar4 != 0) {
        sub_08006F1A(param_1,&sStack_24,0);
      }
    }
  }
  return;
}


/* sub_0800F6A0 @ 0x0800F6A0 */

void sub_0800F6A0(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 local_38;
  short asStack_34 [4];
  short asStack_2c [4];
  short local_24;
  short local_22;
  int iStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  if (*(int *)(param_1 + 0xac) + -1 <= *(int *)(param_1 + 0xa8)) {
    iVar4 = (int)*(short *)(param_1 + 0x48);
    if (0xe < iVar4) {
      iVar4 = 0xe;
    }
    if (0 < iVar4) {
      iStack_20 = param_1;
      local_1c = param_2;
      uStack_18 = param_3;
      sVar2 = sub_08005CA8(iVar4);
      sVar3 = sub_08005CA8(iVar4);
      sVar1 = (short)(iVar4 >> 1);
      sub_0800F3E4(&local_24,(sVar1 - sVar2) + (short)local_1c,(sVar1 - sVar3) + (short)param_3);
      if (local_24 < DAT_03003b38) {
        local_24 = DAT_03003b38;
      }
      if (local_22 < DAT_03003b3a) {
        local_22 = DAT_03003b3a;
      }
      if (DAT_03003b3c < local_24) {
        local_24 = DAT_03003b3c;
      }
      if (DAT_03003b3e < local_22) {
        local_22 = DAT_03003b3e;
      }
      local_38 = sub_0800F404(&local_24,3);
      sub_0800F420(asStack_34,(byte *)(param_1 + 0x28),(short *)&local_38);
      sub_0800F3F0(asStack_2c,asStack_34);
      iVar4 = sub_0800F358(asStack_2c,0);
      if (iVar4 != 0) {
        sub_08006F1A(param_1,&local_24,0);
      }
    }
  }
  return;
}


/* sub_0800F774 @ 0x0800F774 */

void sub_0800F774(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  
  puVar6 = (undefined1 *)(param_1 + 8);
  iVar7 = param_2 + 8;
  if (param_3 < 2) {
    if (DAT_030007dc != 0) {
      return;
    }
    uVar2 = sub_0800F450((int)puVar6);
    uVar3 = sub_0800F450(iVar7);
    local_24._0_2_ = (short)uVar3;
    local_28._0_2_ = (short)uVar2;
    local_28._2_2_ = (short)((uint)uVar2 >> 0x10);
    local_24._2_2_ = (short)((uint)uVar3 >> 0x10);
    if (((int)(short)local_28 - (int)(short)local_24) *
        ((int)(short)local_28 - (int)(short)local_24) <
        ((int)local_28._2_2_ - (int)local_24._2_2_) * ((int)local_28._2_2_ - (int)local_24._2_2_)) {
      if (local_28._2_2_ < local_24._2_2_) {
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
    uStack_20._0_2_ = (short)uVar2;
    uVar4 = (uint)(*(byte *)(param_2 + 0x2a) >> 1);
    if (((int)(short)uStack_20 <= (int)((int)*(short *)(param_2 + 0x20) - uVar4)) ||
       ((int)((int)*(short *)(param_2 + 0x20) + uStack_18 + uVar4) <= (int)(short)uStack_20)) {
      uStack_20._2_2_ = (short)((uint)uVar2 >> 0x10);
      uVar4 = (uint)(*(byte *)(param_2 + 0x2b) >> 1);
      if (((int)uStack_20._2_2_ <= (int)((int)*(short *)(param_2 + 0x22) - uVar4)) ||
         ((int)((int)*(short *)(param_2 + 0x22) + (uint)*(byte *)(param_2 + 0x2b) + uVar4) <=
          (int)uStack_20._2_2_)) goto _0800F8E4;
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
      local_24._0_2_ = (short)uVar3;
      local_28._0_2_ = (short)uVar2;
      local_28._2_2_ = (short)((uint)uVar2 >> 0x10);
      local_24._2_2_ = (short)((uint)uVar3 >> 0x10);
      if (((int)(short)local_28 - (int)(short)local_24) *
          ((int)(short)local_28 - (int)(short)local_24) <
          ((int)local_28._2_2_ - (int)local_24._2_2_) * ((int)local_28._2_2_ - (int)local_24._2_2_))
      {
        if (local_28._2_2_ < local_24._2_2_) {
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


/* sub_0800F9AC @ 0x0800F9AC */

void sub_0800F9AC(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 local_50;
  short asStack_4c [4];
  short asStack_44 [4];
  short local_3c;
  short local_3a;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  int iStack_24;
  int local_20;
  int local_1c;
  int iStack_18;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar6 = *(int *)(param_1 + 0x78);
    iVar7 = *(int *)(param_1 + 0x7c);
    iVar4 = *(int *)(param_2 + 0x78) - iVar6;
    local_2c = iVar4 * iVar4;
    sVar2 = (short)iVar6;
    iVar3 = *(int *)(param_2 + 0x7c) - iVar7;
    local_30 = iVar3 * iVar3;
    sVar1 = (short)iVar7;
    local_34 = 1;
    if (iVar6 < *(int *)(param_2 + 0x78)) {
      local_34 = 0xffffffff;
    }
    local_38 = 1;
    if (iVar7 < *(int *)(param_2 + 0x7c)) {
      local_38 = 0xffffffff;
    }
    iVar6 = (int)*(short *)(param_1 + 0x48);
    pbVar8 = (byte *)(param_1 + 0x28);
    local_1c = param_1;
    iStack_18 = param_2;
    if (iVar6 * iVar6 <= local_2c + local_30) {
      local_3c = sVar2 - (short)iVar4;
      local_3a = sVar1 - (short)iVar3;
      local_50 = sub_0800F404(&local_3c,3);
      sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
      sub_0800F3F0(asStack_44,asStack_4c);
      iVar3 = sub_0800F358(asStack_44,0);
      if ((iVar3 != 0) && (iVar3 = sub_08006F1A(local_1c,&local_3c,1), iVar3 != 0)) {
        return;
      }
    }
    local_20 = iVar6 >> 1;
    sub_0800F3E4(&local_3c,(short)local_34 * (short)local_20 + sVar2,sVar1);
    local_50 = sub_0800F404(&local_3c,3);
    sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
    sub_0800F3F0(asStack_44,asStack_4c);
    iVar3 = sub_0800F358(asStack_44,0);
    if ((iVar3 == 0) || (iVar3 = sub_08006F1A(local_1c,&local_3c,1), iVar3 == 0)) {
      sub_0800F3E4(&local_3c,sVar2,(short)local_38 * (short)local_20 + sVar1);
      local_50 = sub_0800F404(&local_3c,3);
      sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
      sub_0800F3F0(asStack_44,asStack_4c);
      iVar3 = sub_0800F358(asStack_44,0);
      if ((iVar3 == 0) || (iVar3 = sub_08006F1A(local_1c,&local_3c,1), iVar3 == 0)) {
        sub_0800F3E4(&local_3c,sVar2,sVar1 + (short)local_38);
        local_50 = sub_0800F404(&local_3c,3);
        sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
        sub_0800F3F0(asStack_44,asStack_4c);
        iVar4 = sub_0800F358(asStack_44,0);
        iVar3 = local_1c;
        psVar5 = (short *)(local_1c + 0x80);
        if (iVar4 == 0) {
          sub_0800F3E4(&local_3c,sVar2 + (short)local_34,sVar1);
          local_50 = sub_0800F404(&local_3c,3);
          sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
          sub_0800F3F0(asStack_44,asStack_4c);
          iVar4 = sub_0800F358(asStack_44,0);
          if (iVar4 == 0) {
            if (local_2c < local_30) {
              iStack_24 = local_20 + 1;
              sub_0800F3E4(&local_3c,sVar2 - (short)local_34 * (short)iStack_24,sVar1);
              local_50 = sub_0800F404(&local_3c,3);
              sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
              sub_0800F3F0(asStack_44,asStack_4c);
              iVar4 = sub_0800F358(asStack_44,0);
              if ((iVar4 == 0) || (iVar4 = sub_08006F1A(local_1c,&local_3c,1), iVar4 == 0)) {
                sub_0800F3E4(&local_3c,sVar2,sVar1 - (short)local_38 * (short)iStack_24);
                local_50 = sub_0800F404(&local_3c,3);
                sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
                sub_0800F3F0(asStack_44,asStack_4c);
                iVar4 = sub_0800F358(asStack_44,0);
                if ((iVar4 == 0) || (iVar4 = sub_08006F1A(local_1c,&local_3c,1), iVar4 == 0)) {
                  sub_0800F3E4(&local_3c,sVar2 - (short)local_34,sVar1);
                  local_50 = sub_0800F404(&local_3c,3);
                  sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
                  sub_0800F3F0(asStack_44,asStack_4c);
                  iVar4 = sub_0800F358(asStack_44,0);
                  if (iVar4 == 0) {
                    sub_0800F3E4(&local_3c,sVar2,sVar1 - (short)local_38);
                    local_50 = sub_0800F404(&local_3c,3);
                    sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
                    sub_0800F3F0(asStack_44,asStack_4c);
                    iVar4 = sub_0800F358(asStack_44,0);
                    if (iVar4 != 0) {
                      *psVar5 = local_3c;
                      *(short *)(iVar3 + 0x82) = local_3a;
                      *(short *)(iVar3 + 0xb0) = local_3c;
                      *(short *)(iVar3 + 0xb2) = local_3a;
                      *(undefined4 *)(iVar3 + 0xac) = 1;
                      *(undefined4 *)(iVar3 + 0xa8) = 0;
                    }
                  }
                  else {
                    *psVar5 = local_3c;
                    *(short *)(iVar3 + 0x82) = local_3a;
                    *(short *)(iVar3 + 0xb0) = local_3c;
                    *(short *)(iVar3 + 0xb2) = local_3a;
                    *(undefined4 *)(iVar3 + 0xac) = 1;
                    *(undefined4 *)(iVar3 + 0xa8) = 0;
                  }
                }
              }
            }
            else {
              iStack_28 = local_20 + 1;
              sub_0800F3E4(&local_3c,sVar2,sVar1 - (short)local_38 * (short)iStack_28);
              local_50 = sub_0800F404(&local_3c,3);
              sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
              sub_0800F3F0(asStack_44,asStack_4c);
              iVar4 = sub_0800F358(asStack_44,0);
              if ((iVar4 == 0) || (iVar4 = sub_08006F1A(local_1c,&local_3c,1), iVar4 == 0)) {
                sub_0800F3E4(&local_3c,sVar2 - (short)local_34 * (short)iStack_28,sVar1);
                local_50 = sub_0800F404(&local_3c,3);
                sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
                sub_0800F3F0(asStack_44,asStack_4c);
                iVar4 = sub_0800F358(asStack_44,0);
                if ((iVar4 == 0) || (iVar4 = sub_08006F1A(local_1c,&local_3c,1), iVar4 == 0)) {
                  sub_0800F3E4(&local_3c,sVar2,sVar1 - (short)local_38);
                  local_50 = sub_0800F404(&local_3c,3);
                  sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
                  sub_0800F3F0(asStack_44,asStack_4c);
                  iVar4 = sub_0800F358(asStack_44,0);
                  if (iVar4 == 0) {
                    sub_0800F3E4(&local_3c,sVar2 - (short)local_34,sVar1);
                    local_50 = sub_0800F404(&local_3c,3);
                    sub_0800F420(asStack_4c,pbVar8,(short *)&local_50);
                    sub_0800F3F0(asStack_44,asStack_4c);
                    iVar4 = sub_0800F358(asStack_44,0);
                    if (iVar4 != 0) {
                      *psVar5 = local_3c;
                      *(short *)(iVar3 + 0x82) = local_3a;
                      *(short *)(iVar3 + 0xb0) = local_3c;
                      *(short *)(iVar3 + 0xb2) = local_3a;
                      *(undefined4 *)(iVar3 + 0xac) = 1;
                      *(undefined4 *)(iVar3 + 0xa8) = 0;
                    }
                  }
                  else {
                    *psVar5 = local_3c;
                    *(short *)(iVar3 + 0x82) = local_3a;
                    *(short *)(iVar3 + 0xb0) = local_3c;
                    *(short *)(iVar3 + 0xb2) = local_3a;
                    *(undefined4 *)(iVar3 + 0xac) = 1;
                    *(undefined4 *)(iVar3 + 0xa8) = 0;
                  }
                }
              }
            }
          }
          else {
            *psVar5 = local_3c;
            *(short *)(iVar3 + 0x82) = local_3a;
            *(short *)(iVar3 + 0xb0) = local_3c;
            *(short *)(iVar3 + 0xb2) = local_3a;
            *(undefined4 *)(iVar3 + 0xac) = 1;
            *(undefined4 *)(iVar3 + 0xa8) = 0;
          }
        }
        else {
          *psVar5 = local_3c;
          *(short *)(local_1c + 0x82) = local_3a;
          *(short *)(local_1c + 0xb0) = local_3c;
          *(short *)(local_1c + 0xb2) = local_3a;
          *(undefined4 *)(local_1c + 0xac) = 1;
          *(undefined4 *)(local_1c + 0xa8) = 0;
        }
      }
    }
  }
  return;
}


/* sub_0800FE0C @ 0x0800FE0C */

int * sub_0800FE0C(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      if (param_1[iVar1 * 6 + 1] == *param_2) {
        return param_1 + iVar1 * 6 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  return (int *)0x0;
}


