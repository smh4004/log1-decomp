/* Ghidra reference decompilation of code_080067E8 (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_080067E8 @ 0x080067E8 */

void sub_080067E8(int param_1)

{
  *(undefined2 *)(param_1 + 4) = 0x10;
  *(undefined2 *)(param_1 + 6) = 0x10;
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  return;
}


/* sub_080067F4 @ 0x080067F4 */

void sub_080067F4(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  REG_DMA3SAD = *(undefined4 *)(param_1 + 4);
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar2 = (uint)uVar1 * 8;
  puVar3 = (uint *)(&DAT_0202be24 + iVar2);
  uVar4 = (*puVar3 & 0x1ff00ff) + 0x40000000;
  *puVar3 = uVar4;
  uVar5 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar2) & 0xfffff000) + 0x800;
  *(uint *)(&DAT_0202be28 + iVar2) = uVar5;
  *(uint *)(&DAT_0202be28 + iVar2) =
       uVar5 & 0xffff0fff | ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
  uVar5 = ((uint)*param_1 << 0x17) >> 7;
  *puVar3 = uVar4 & 0xfe00ffff | uVar5;
  *puVar3 = param_1[1] & 0xff | uVar4 & 0xfe00ff00 | uVar5;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x80;
  param_2[1] = param_2[1] + 4;
  return;
}


/* sub_0800689A @ 0x0800689A */

undefined4 sub_0800689A(int param_1,int param_2,short *param_3)

{
  undefined4 uVar1;
  short asStack_20 [2];
  short sStack_1c;
  short sStack_1a;
  short sStack_18;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  
  if (param_2 == 1) {
    if (*(int *)(param_3 + 6) != 0) {
      return 0;
    }
    sub_08002300((undefined4 *)&sStack_1c,param_1);
    sStack_14 = sStack_1c;
    sStack_12 = sStack_1a;
    if (((sStack_1c < param_3[2]) && (*param_3 < sStack_18)) &&
       ((sStack_1a < param_3[3] && (param_3[1] < sStack_16)))) {
      sub_0800507A(DAT_03000600,&sStack_14,1,0);
      sub_080028C4(param_1);
      sub_0800ACFE(0x16);
      sub_0800286A(6,0);
      return 1;
    }
  }
  else if (param_2 == 0) {
    sub_08002300((undefined4 *)asStack_20,param_1);
    sub_0800994C(&sStack_18,asStack_20,2);
    uVar1 = sub_08003398();
    sStack_10 = (short)uVar1;
    if ((((sStack_18 <= sStack_10) && (sStack_10 < sStack_14)) &&
        (sStack_e = (short)((uint)uVar1 >> 0x10), sStack_16 <= sStack_e)) && (sStack_e < sStack_12))
    {
      return 1;
    }
  }
  return 0;
}


/* sub_0800697E @ 0x0800697E */

void sub_0800697E(ushort *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  short asStack_14 [4];
  
  iVar2 = sub_08002716((int)param_1);
  piVar3 = (int *)(&gUnknown_0815B948)[*param_1];
  *(ushort *)(iVar2 + 0x20) = param_1[2];
  *(ushort *)(iVar2 + 0x22) = param_1[3];
  *(int *)(iVar2 + 8) = piVar3[1];
  uVar1 = sub_08005EA6(*piVar3);
  *(undefined1 *)(iVar2 + 0xd) = uVar1;
  sub_0800245A(iVar2,&gUnknown_0801165C);
  *(undefined4 *)(iVar2 + 0x38) = 0x800689b;
  sub_08002300((undefined4 *)asStack_14,iVar2);
  sub_0800507A(DAT_03000600,asStack_14,0,0);
  return;
}


/* sub_080069E8 @ 0x080069E8 */

void sub_080069E8(int param_1)

{
  undefined1 uVar1;
  
  sub_08002910(param_1);
  uVar1 = sub_0800A714(0x80);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  return;
}


/* sub_080069FA @ 0x080069FA */

void sub_080069FA(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(short)((DAT_030007c0 >> 4) - *(short *)(param_1 + 0x20));
  iVar2 = (int)(short)((DAT_030007c2 >> 4) - *(short *)(param_1 + 0x22));
  if (0x100 < iVar1 * iVar1 + iVar2 * iVar2) {
    sub_08002466(param_1,1);
  }
  return;
}


/* sub_08006A52 @ 0x08006A52 */

void sub_08006A52(int param_1)

{
  undefined4 local_c;
  
  sub_080028FC(param_1);
  local_c = CONCAT22(*(short *)(param_1 + 0x22) << 4,*(short *)(param_1 + 0x20) << 4);
  *(undefined4 *)(param_1 + 0x28) = local_c;
  return;
}


/* sub_08006A72 @ 0x08006A72 */

undefined4 sub_08006A72(int param_1,int param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  undefined4 local_14;
  
  uVar3 = **(undefined4 **)(param_1 + 0x1c);
  local_14._0_2_ = (short)uVar3;
  local_14._2_2_ = (short)((uint)uVar3 >> 0x10);
  local_14 = uVar3;
  if (param_2 == 0) {
    iVar5 = (uint)DAT_030007b2 + (int)*(short *)(param_1 + 0x2a);
    local_1c = *(short *)(param_1 + 0x20);
    local_1a = *(short *)(param_1 + 0x22) + local_14._2_2_;
    local_18 = *(short *)(param_1 + 0x20) + (short)local_14;
    sVar2 = (short)(iVar5 >> 4);
    local_16 = local_14._2_2_ + sVar2;
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
    local_16 = *(short *)(param_1 + 0x22) + local_14._2_2_;
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
    local_16 = *(short *)(param_1 + 0x22) + local_14._2_2_;
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


/* sub_08006B98 @ 0x08006B98 */

void sub_08006B98(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_18 = local_1c;
  sVar1 = (DAT_030007c0 >> 4) - *(short *)(param_1 + 0x20);
  sVar2 = (DAT_030007c2 >> 4) - *(short *)(param_1 + 0x22);
  local_20 = CONCAT22(sVar2,sVar1);
  local_1c = local_20;
  iVar3 = (int)sVar1 * (int)sVar1 + (int)sVar2 * (int)sVar2;
  if (iVar3 < 0x1901) {
    if (iVar3 < 100) {
      sub_08002466(param_1,0);
    }
    else {
      uVar4 = (uint)*(byte *)(param_1 + 0x13);
      if (((int)(char)(&DAT_08011674)[uVar4] *
           (int)*(short *)((int)&local_1c + (uint)(byte)(&DAT_08011670)[uVar4] * 2) < 1) ||
         (iVar3 = sub_08006A72(param_1,uVar4), iVar3 == 0)) {
        iVar3 = (int)local_1c._2_2_ * (int)local_1c._2_2_;
        iVar5 = (int)(short)local_1c * (int)(short)local_1c;
        uVar4 = (uint)(iVar3 - iVar5 != 0 && iVar5 <= iVar3);
        iVar3 = uVar4 * 2;
        iVar3 = sub_08006A72(param_1,(uint)(byte)(&DAT_08011678)
                                                 [(uint)(0 < *(short *)((int)&local_1c + iVar3)) +
                                                  iVar3]);
        if (iVar3 == 0) {
          iVar3 = (uVar4 ^ 1) * 2;
          sub_08006A72(param_1,(uint)(byte)(&DAT_08011678)
                                           [(uint)(0 < *(short *)((int)&local_1c + iVar3)) + iVar3])
          ;
        }
      }
    }
  }
  else {
    sub_0800245A(param_1,&gUnknown_0801167C);
  }
  return;
}


/* sub_08006C88 @ 0x08006C88 */

void sub_08006C88(int param_1)

{
  sub_080028FC(param_1);
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + 0x10;
  return;
}


/* sub_08006C9A @ 0x08006C9A */

void sub_08006C9A(int param_1)

{
  short sVar1;
  short sVar2;
  
  sVar1 = (DAT_030007c0 >> 4) - *(short *)(param_1 + 0x20);
  sVar2 = (DAT_030007c2 >> 4) - *(short *)(param_1 + 0x22);
  if ((int)sVar1 * (int)sVar1 + (int)sVar2 * (int)sVar2 < 0x10) {
    if (DAT_030007dc == 0) {
      sub_08002466(param_1,0);
    }
    else {
      sub_0800245A(param_1,&PTR_sub_0800AEF8_1_08011690);
    }
  }
  else {
    if (sVar2 < 2) {
      if (sVar2 + 1 < 0 != SCARRY4((int)sVar2,1)) {
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + -3;
        *(undefined1 *)(param_1 + 0x13) = 1;
      }
    }
    else {
      *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + 3;
      *(undefined1 *)(param_1 + 0x13) = 0;
    }
    if (sVar1 < 2) {
      if (sVar1 + 1 < 0 != SCARRY4((int)sVar1,1)) {
        *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + -3;
        *(undefined1 *)(param_1 + 0x13) = 2;
      }
    }
    else {
      *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 3;
      *(undefined1 *)(param_1 + 0x13) = 3;
    }
  }
  return;
}


/* sub_08006D56 @ 0x08006D56 */

undefined4 sub_08006D56(void)

{
  return 0;
}


/* sub_08006D70 @ 0x08006D70 */

void sub_08006D70(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x58) >> 6;
  if (*(short *)(param_1 + 0x9a) == 1) {
    iVar1 = __16__rt_sdiv(3,*(uint *)(param_1 + 0x50));
    DAT_03000c1c = iVar1 + 1;
  }
  return;
}


/* sub_08006D90 @ 0x08006D90 */

void sub_08006D90(undefined2 *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if ((((param_2 == 2) || (param_2 == 1)) && (-1 < param_3)) && (param_3 < 0x23)) {
    DAT_030047ec = 0;
    REG_DMA3SAD = 0x30047ec;
    REG_DMA3DAD = param_1 + 4;
    Ram040000dc = 0xb;
    DAT_040000de = 0x8500;
    *param_1 = (short)param_3;
    param_1[0x4d] = (short)param_2;
    param_1[0x4e] = 1;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x52) = 0;
    *(undefined4 *)(param_1 + 0x4a) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    param_1[0x4c] = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x56) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x12e) = 0;
    iVar7 = 0;
    do {
      iVar6 = iVar7 + 1;
      *(undefined4 *)(param_1 + iVar7 * 2 + 0x130) = 0;
      iVar7 = iVar6;
    } while (iVar6 < 5);
    iVar7 = 0;
    do {
      iVar6 = iVar7 + 1;
      param_1[iVar7 * 2 + 0x120] = 0xffff;
      param_1[iVar7 * 2 + 0x121] = 1;
      iVar7 = iVar6;
    } while (iVar6 < 5);
    param_1[0x12a] = 0;
    param_1[299] = 0;
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x42) = DAT_030007d8;
      iVar7 = DAT_030007c4;
      *(int *)(param_1 + 0x2c) = DAT_030007c4;
      *(undefined4 *)(param_1 + 0x2a) = DAT_030007c8;
      uVar4 = DAT_030007cc;
      *(uint *)(param_1 + 0x28) = DAT_030007cc;
      uVar5 = DAT_030007d0;
      *(int *)(param_1 + 0x2e) = iVar7 >> 6;
      *(undefined4 *)(param_1 + 0x26) = uVar5;
      if (param_1[0x4d] == 1) {
        iVar7 = __16__rt_sdiv(3,uVar4);
        DAT_03000c1c = iVar7 + 1;
      }
      *(undefined1 *)(param_1 + 0x14) = 0;
      *(undefined1 *)((int)param_1 + 0x29) = 0;
      *(undefined1 *)(param_1 + 0x15) = 0x10;
      *(undefined1 *)((int)param_1 + 0x2b) = 8;
      *(undefined4 *)(param_1 + 0x30) = 0xfa;
    }
    else {
      iVar7 = param_3 * 0x40;
      *(undefined4 *)(param_1 + 0x2a) = *(undefined4 *)(&DAT_086b60c8 + iVar7);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(&DAT_086b60c8 + iVar7);
      *(undefined4 *)(param_1 + 0x26) = *(undefined4 *)(&DAT_086b60cc + iVar7);
      iVar6 = *(int *)(&DAT_086b60cc + iVar7);
      *(int *)(param_1 + 0x28) = iVar6;
      if (iVar6 < 1) {
        *(undefined4 *)(param_1 + 0x28) = 1;
      }
      *(undefined4 *)(param_1 + 2) = *(undefined4 *)(&DAT_086b6098 + iVar7);
      param_1[1] = (short)*(undefined4 *)(&DAT_086b609c + iVar7);
      *(undefined4 *)(param_1 + 0x42) = *(undefined4 *)(&DAT_086b60a0 + iVar7);
      param_1[0x1e] = *(undefined2 *)(&DAT_086b60a4 + iVar7);
      param_1[0x1f] = *(undefined2 *)(&DAT_086b60a6 + iVar7);
      param_1[0x20] = *(undefined2 *)(&DAT_086b60a8 + iVar7);
      param_1[0x21] = *(undefined2 *)(&DAT_086b60aa + iVar7);
      sVar1 = *(short *)(&DAT_086b60ac + iVar7);
      param_1[0x22] = sVar1;
      if (1 < sVar1) {
        *(undefined2 **)(param_1 + 0x48) = param_1;
        param_1[0x4c] = 1;
      }
      param_1[0x23] = *(undefined2 *)(&DAT_086b60ae + iVar7);
      param_1[0x24] = *(undefined2 *)(&DAT_086b60b0 + iVar7);
      *(int *)(param_1 + 0x34) = (int)*(short *)(&DAT_086b60b2 + iVar7);
      *(int *)(param_1 + 0x36) = (int)*(short *)(&DAT_086b60b4 + iVar7);
      *(int *)(param_1 + 0x32) = (int)*(short *)(&DAT_086b60b6 + iVar7);
      *(int *)(param_1 + 0x38) = (int)*(short *)(&DAT_086b60b8 + iVar7);
      *(int *)(param_1 + 0x3a) = (int)*(short *)(&DAT_086b60ba + iVar7);
      *(int *)(param_1 + 0x1a) = (int)*(short *)(&DAT_086b60bc + iVar7);
      *(int *)(param_1 + 0x3c) = (int)*(short *)(&DAT_086b60be + iVar7);
      uVar2 = *(undefined2 *)(&DAT_086b60c4 + iVar7);
      uVar3 = *(undefined2 *)(&DAT_086b60c2 + iVar7);
      *(int *)(param_1 + 0x3e) = (int)*(short *)(&DAT_086b60c0 + iVar7);
      sub_0800F3E4(param_1 + 0x40,uVar3,uVar2);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(&DAT_086b60d0 + iVar7);
      *(int *)(param_1 + 0x2e) = *(int *)(param_1 + 0x2c) >> 6;
      if (param_1[0x4d] == 1) {
        iVar7 = __16__rt_sdiv(3,*(uint *)(param_1 + 0x28));
        DAT_03000c1c = iVar7 + 1;
      }
    }
  }
  return;
}


/* sub_08006F1A @ 0x08006F1A */

undefined4 sub_08006F1A(int param_1,short *param_2,int param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  short sVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 uStack_4c;
  short asStack_48 [2];
  undefined4 local_44;
  short asStack_40 [4];
  short sStack_38;
  undefined2 uStack_36;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  int iStack_20;
  short *psStack_1c;
  int iStack_18;
  
  sVar5 = *(short *)(param_1 + 0x20) >> 3;
  sVar3 = *(short *)(param_1 + 0x22) >> 3;
  local_44 = CONCAT22(sVar3,sVar5);
  local_30 = local_44;
  if (((sVar5 == *param_2) && (sVar3 == param_2[1])) ||
     ((psVar7 = (short *)(param_1 + 0x80), *psVar7 == *param_2 &&
      (*(short *)(param_1 + 0x82) == param_2[1])))) {
    uVar4 = 1;
  }
  else {
    iVar6 = (int)*param_2;
    if ((((iVar6 < DAT_03003b38) || (DAT_03003b3c <= iVar6)) ||
        (iVar8 = (int)param_2[1], iVar8 < DAT_03003b3a)) || (DAT_03003b3e <= iVar8)) {
      uVar4 = 0;
    }
    else {
      iStack_20 = param_1;
      psStack_1c = param_2;
      iStack_18 = param_3;
      iVar6 = sub_0800F570((int)sVar5,(int)sVar3,iVar6,iVar8);
      pbVar9 = (byte *)(param_1 + 0x28);
      if (iVar6 < 2) {
        uStack_4c = sub_0800F404(param_2,3);
        sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
        sub_0800F3F0(asStack_40,asStack_48);
        iVar6 = sub_0800F358(asStack_40,0);
        if (iVar6 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined4 *)param_2;
          *(undefined4 *)psVar7 = uVar4;
          *(undefined4 *)(param_1 + 0xb0) = uVar4;
          *(undefined4 *)(param_1 + 0xac) = 1;
          *(undefined4 *)(param_1 + 0xa8) = 0;
          uVar4 = 1;
        }
      }
      else {
        if (*(short *)(param_1 + 0x48) < iVar6) {
          sVar3 = *param_2;
          if ((int)sVar3 < (int)(short)local_30) {
            uStack_28 = 0xffffffff;
          }
          else {
            uStack_28 = 1;
          }
          sVar5 = param_2[1];
          if ((int)sVar5 < (int)local_30._2_2_) {
            uStack_2c = 0xffffffff;
          }
          else {
            uStack_2c = 1;
          }
          iVar6 = (int)sVar3 - (int)(short)local_30;
          iVar6 = iVar6 * iVar6;
          iVar8 = (int)sVar5 - (int)local_30._2_2_;
          iVar8 = iVar8 * iVar8;
          sVar2 = (short)((int)*(short *)(param_1 + 0x48) >> 1);
          if (iVar6 - iVar8 == 0 || iVar6 < iVar8) {
            sub_0800F3E4(&sStack_38,sVar3,sVar5 + (short)uStack_2c * sVar2);
            uStack_4c = sub_0800F404(&sStack_38,3);
            sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
            sub_0800F3F0(asStack_40,asStack_48);
            iVar6 = sub_0800F358(asStack_40,0);
            if ((iVar6 != 0) &&
               (iVar6 = sub_08007A4E((short *)&local_30,&sStack_38,param_1,2), iVar6 != 0)) {
              return 1;
            }
            sub_0800F3E4(&sStack_38,(short)local_30,local_30._2_2_ + (short)uStack_2c);
            uStack_4c = sub_0800F404(&sStack_38,3);
            sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
            sub_0800F3F0(asStack_40,asStack_48);
            iVar6 = sub_0800F358(asStack_40,0);
            if (iVar6 != 0) {
              *psVar7 = sStack_38;
              *(undefined2 *)(param_1 + 0x82) = uStack_36;
              *(short *)(param_1 + 0xb0) = sStack_38;
              *(undefined2 *)(param_1 + 0xb2) = uStack_36;
              *(undefined4 *)(param_1 + 0xac) = 1;
              *(undefined4 *)(param_1 + 0xa8) = 0;
              return 1;
            }
          }
          else {
            sub_0800F3E4(&sStack_38,sVar3 + (short)uStack_28 * sVar2,sVar5);
            uStack_4c = sub_0800F404(&sStack_38,3);
            sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
            sub_0800F3F0(asStack_40,asStack_48);
            iVar6 = sub_0800F358(asStack_40,0);
            if ((iVar6 != 0) &&
               (iVar6 = sub_08007A4E((short *)&local_30,&sStack_38,param_1,2), iVar6 != 0)) {
              return 1;
            }
            sub_0800F3E4(&sStack_38,(short)local_30 + (short)uStack_28,local_30._2_2_);
            uStack_4c = sub_0800F404(&sStack_38,3);
            sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
            sub_0800F3F0(asStack_40,asStack_48);
            iVar6 = sub_0800F358(asStack_40,0);
            if (iVar6 != 0) {
              *psVar7 = sStack_38;
              *(undefined2 *)(param_1 + 0x82) = uStack_36;
              *(short *)(param_1 + 0xb0) = sStack_38;
              *(undefined2 *)(param_1 + 0xb2) = uStack_36;
              *(undefined4 *)(param_1 + 0xac) = 1;
              *(undefined4 *)(param_1 + 0xa8) = 0;
              return 1;
            }
          }
        }
        else {
          uStack_34 = *(undefined4 *)param_2;
          uStack_4c = sub_0800F404((short *)&uStack_34,3);
          sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
          sub_0800F3F0(asStack_40,asStack_48);
          iVar6 = sub_0800F358(asStack_40,0);
          if ((iVar6 != 0) &&
             (iVar6 = sub_08007A4E((short *)&local_30,(short *)&uStack_34,param_1,2), iVar6 != 0)) {
            return 1;
          }
          if (iStack_18 == 1) {
            return 0;
          }
          iStack_24 = (int)*param_2 - (int)(short)local_30;
          sVar3 = param_2[1];
          iVar6 = (int)local_30._2_2_;
          uVar1 = (short)local_30 + (short)(iStack_24 >> 1);
          sVar5 = local_30._2_2_ + (short)(sVar3 - iVar6 >> 1);
          uStack_34 = CONCAT22(sVar5,uVar1);
          if (((uint)uVar1 == (local_30 & 0xffff)) && (sVar5 == local_30._2_2_)) {
            return 0;
          }
          uStack_4c = sub_0800F404((short *)&uStack_34,3);
          sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
          sub_0800F3F0(asStack_40,asStack_48);
          iVar8 = sub_0800F358(asStack_40,0);
          if ((iVar8 != 0) &&
             (iVar8 = sub_08007A4E((short *)&local_30,(short *)&uStack_34,param_1,2), iVar8 != 0)) {
            return 1;
          }
          uVar1 = (short)local_30 + (short)(iStack_24 >> 2);
          sVar3 = local_30._2_2_ + (short)(sVar3 - iVar6 >> 2);
          uStack_34 = CONCAT22(sVar3,uVar1);
          if (((uint)uVar1 == (local_30 & 0xffff)) && (sVar3 == local_30._2_2_)) {
            return 0;
          }
          iVar6 = ((int)(short)uVar1 - (int)(short)local_30) *
                  ((int)(short)uVar1 - (int)(short)local_30);
          iVar8 = ((int)sVar3 - (int)local_30._2_2_) * ((int)sVar3 - (int)local_30._2_2_);
          if (iVar6 - iVar8 == 0 || iVar6 < iVar8) {
            sub_0800F3E4(&sStack_38,param_2[1],sVar3);
          }
          else {
            sub_0800F3E4(&sStack_38,uVar1,param_2[1]);
          }
          uStack_4c = sub_0800F404(&sStack_38,3);
          sub_0800F420(asStack_48,pbVar9,(short *)&uStack_4c);
          sub_0800F3F0(asStack_40,asStack_48);
          iVar6 = sub_0800F358(asStack_40,0);
          if ((iVar6 != 0) &&
             (iVar6 = sub_08007A4E((short *)&local_30,&sStack_38,param_1,2), iVar6 != 0)) {
            return 1;
          }
        }
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}


/* sub_08007352 @ 0x08007352 */

undefined4 sub_08007352(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(short *)(param_2 + 0x9a) == 1) ||
     ((*(char *)(param_2 + 10) == '\0' &&
      ((*(char *)(param_2 + 0xb) != '\x02' || (*(int *)(param_2 + 0x60) == 0)))))) {
    iVar3 = param_4;
    if (*(int *)(param_2 + 0x60) != 0) {
      iVar2 = sub_08005CA8(10000);
      if (iVar2 < 0x2329) {
        if (iVar2 < 0x1d4d) {
          if (iVar2 < 0x1389) {
            if (0x12c0 < iVar2) {
              return 0;
            }
          }
          else {
            iVar3 = 0;
            iVar2 = *(int *)(param_2 + 0x60) >> 2;
            if (iVar2 <= param_4) {
              iVar3 = param_4 - iVar2;
            }
          }
        }
        else {
          iVar3 = 0;
          iVar2 = *(int *)(param_2 + 0x60) >> 1;
          if (iVar2 <= param_4) {
            iVar3 = param_4 - iVar2;
          }
        }
      }
      else {
        iVar3 = 0;
        if (*(int *)(param_2 + 0x60) <= param_4) {
          iVar3 = param_4 - *(int *)(param_2 + 0x60);
        }
      }
    }
    if (iVar3 < *(int *)(param_2 + 0x4c)) {
      if (iVar3 == 0) {
        uVar1 = 0;
      }
      else if ((DAT_03000c18 == 0) || (*(short *)(param_2 + 0x9a) != 1)) {
        *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) - iVar3;
        uVar1 = 2;
      }
      else {
        uVar1 = 2;
      }
    }
    else if ((DAT_03000c18 == 0) || (*(short *)(param_2 + 0x9a) != 1)) {
      *(undefined4 *)(param_2 + 0x4c) = 0;
      *(undefined2 *)(param_2 + 0x9c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* sub_08007416 @ 0x08007416 */

void sub_08007416(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uStack_18;
  
  if (*(short *)(param_2 + 0x14) == 0) {
    if (*(short *)(param_1 + 0x9c) == 0) {
      *(undefined4 *)(param_1 + 600) = 0;
      if (*(int *)(param_2 + 0x25c) == param_1) {
        *(undefined4 *)(param_2 + 0x25c) = 0;
      }
    }
    else if (*(short *)(param_2 + 0x9c) == 0) {
      *(undefined4 *)(param_2 + 600) = 0;
      if (*(int *)(param_1 + 0x25c) == param_2) {
        *(undefined4 *)(param_1 + 0x25c) = 0;
      }
    }
    else {
      uStack_18 = param_4;
      if (*(short *)(param_1 + 0x9a) == 2) {
        if (param_3 == 0) {
          sub_08007F4C(param_1,5);
        }
        *(undefined4 *)(param_1 + 0xa8) = 0;
        if (DAT_03000c1c < param_4) {
          uStack_18 = DAT_03000c1c;
        }
      }
      else {
        sVar1 = sub_08005CA8(900);
        *(short *)(param_2 + 0x1e) = sVar1 + 900;
      }
      *(int *)(param_1 + 600) = param_2;
      *(int *)(param_2 + 0x25c) = param_1;
      iVar2 = sub_08007352(param_1,param_2,param_3,uStack_18);
      if (iVar2 == 2) {
        if (*(short *)(param_2 + 0x9a) == 2) {
          iVar2 = 0x1c;
          if (param_3 != 0) {
            iVar2 = 0x16;
          }
          sub_0800ACFE(iVar2);
        }
        else {
          sub_0800ACFE(0x14);
        }
        sub_08007F4C(param_2,6);
      }
      else if (iVar2 == 1) {
        *(undefined4 *)(param_1 + 600) = 0;
        if (*(int *)(param_1 + 0x25c) == param_2) {
          *(undefined4 *)(param_1 + 0x25c) = 0;
        }
        *(undefined4 *)(param_2 + 0x25c) = 0;
        *(undefined4 *)(param_2 + 600) = 0;
        sub_08007F4C(param_2,7);
        if (*(short *)(param_1 + 0x9a) == 1) {
          iVar2 = *(int *)(param_1 + 0x84) + *(int *)(param_2 + 0x84);
          *(int *)(param_1 + 0x84) = iVar2;
          sub_08005C32(iVar2);
          iVar2 = sub_08005BFE(param_1);
          if (iVar2 != 0) {
            sub_08005BBC();
          }
        }
      }
      else {
        if (*(int *)(param_2 + 0x18) < DAT_03003b6c) {
          sub_0800ACFE(0x1d);
          *(int *)(param_2 + 0x18) = DAT_03003b6c + 0x14;
        }
        sub_0800BEB8(*(int *)(param_2 + 0x274));
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0x18) < DAT_03003b6c) {
      sub_0800ACFE(0x1d);
      *(int *)(param_2 + 0x18) = DAT_03003b6c + 0x14;
    }
    sub_0800BEB8(*(int *)(param_2 + 0x274));
  }
  return;
}


/* sub_0800755A @ 0x0800755A */

void sub_0800755A(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int extraout_r1;
  int iVar7;
  undefined4 uStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  short *local_1c;
  int local_18;
  
  iVar3 = *(int *)(param_1 + 0x78);
  local_18 = param_1 + 0x240;
  iVar6 = *(int *)(param_1 + 0x7c);
  iVar7 = *(int *)(param_1 + 0x25c);
  if (iVar7 == 0) {
    iVar7 = *(int *)(param_1 + 600);
  }
  local_1c = (short *)(param_1 + 0x40);
  if (iVar7 == 0) {
    iStack_20 = (int)*(short *)(param_1 + 0x3e);
    iVar4 = sub_0800F570(iVar3,iVar6,*(int *)(DAT_030047f4 + 0x78),*(int *)(DAT_030047f4 + 0x7c));
    iVar7 = 0;
    if (iVar4 <= local_1c[4]) {
      iVar7 = DAT_030047f4;
    }
    if (iVar7 == 0) {
      if (*(int *)(param_1 + 0xac) + -1 <= *(int *)(param_1 + 0xa8)) {
        switch(*(undefined2 *)(param_1 + 0x3c)) {
        case 0:
        case 1:
          break;
        case 2:
          sVar2 = (short)*(undefined4 *)(param_1 + 0x70);
          sVar1 = (short)*(undefined4 *)(param_1 + 0x74);
          uStack_44 = CONCAT22(sVar1,sVar2);
          if ((sVar2 != iVar3) || (sVar1 != iVar6)) {
            sub_08006F1A(param_1,(short *)&uStack_44,0);
          }
          break;
        case 3:
          iVar7 = 0;
          do {
            uVar5 = *(undefined4 *)(iVar7 * 4 + param_1 + 0x240);
            uStack_44._0_2_ = (short)uVar5;
            if (((short)uStack_44 == iVar3) &&
               (uStack_44._2_2_ = (short)((uint)uVar5 >> 0x10), uStack_44._2_2_ == iVar6)) {
              uStack_44 = uVar5;
              __16__rt_sdiv(5,iVar7 + 1);
              uStack_44 = *(undefined4 *)(extraout_r1 * 4 + param_1 + 0x240);
              if ((iStack_38 < 0) || (iStack_3c < 0)) break;
              *(short *)(local_18 + 0x14) = (short)extraout_r1;
              iVar4 = sub_08006F1A(param_1,(short *)&uStack_44,0);
              if (iVar4 != 0) {
                return;
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 5);
          uStack_44 = *(int *)(*(short *)(local_18 + 0x14) * 4 + param_1 + 0x240);
          if ((((short)uStack_44 < 0) || (uStack_44 < 0)) ||
             (iVar7 = sub_08006F1A(param_1,(short *)&uStack_44,0), iVar7 == 0)) {
            sub_0800F6A0(param_1,iVar3,iVar6);
          }
          break;
        case 4:
          sub_0800F6A0(param_1,iVar3,iVar6);
          break;
        case 5:
          sVar2 = (short)*(undefined4 *)(param_1 + 0x68);
          sVar1 = (short)*(undefined4 *)(param_1 + 0x6c);
          uStack_44 = CONCAT22(sVar1,sVar2);
          iVar4 = *(int *)(param_1 + 100);
          iVar7 = sub_0800F570(iVar3,iVar6,(int)sVar2,(int)sVar1);
          if ((iVar7 < iVar4) || (iVar7 = sub_08006F1A(param_1,(short *)&uStack_44,0), iVar7 == 0))
          {
            sub_0800F6A0(param_1,iVar3,iVar6);
          }
        }
      }
    }
    else {
      iVar4 = sub_0800F570(iVar3,iVar6,*(int *)(iVar7 + 0x78),*(int *)(iVar7 + 0x7c));
      if (iStack_20 == 1) {
        sub_0800F774(param_1,iVar7,iVar4);
      }
      else if (iStack_20 == 2) {
        iVar4 = 0;
        do {
          if ((iVar4 < 0) || (5 < iVar4)) {
            iStack_40 = 0;
          }
          else {
            iStack_40 = *(int *)(iVar4 * 4 + param_1 + 0x260);
          }
          if (iVar7 == iStack_40) {
            iVar3 = sub_0800F570(iVar3,iVar6,*(int *)(iStack_40 + 0x78),*(int *)(iStack_40 + 0x7c));
            sub_0800F774(param_1,iStack_40,iVar3);
            return;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 5);
        sub_0800F9AC(param_1,iVar7);
      }
      else if (iStack_20 == 3) {
        if (*(int *)(iVar7 + 0x25c) == 0) {
          sub_0800F9AC(param_1,iVar7);
        }
        else {
          iVar3 = sub_0800F570(iVar3,iVar6,*(int *)(iVar7 + 0x78),*(int *)(iVar7 + 0x7c));
          sub_0800F774(param_1,iVar7,iVar3);
        }
      }
      else {
        sub_0800F9AC(param_1,iVar7);
      }
    }
  }
  else if (*(short *)(param_1 + 0x3e) == 4) {
    sub_0800F9AC(param_1,iVar7);
  }
  else {
    iStack_34 = (int)*local_1c;
    iStack_28 = *(int *)(param_1 + 0x4c);
    iStack_24 = *(int *)(param_1 + 0x50);
    iStack_30 = *(int *)(iVar7 + 0x4c);
    iStack_2c = *(int *)(iVar7 + 0x50);
    iVar3 = sub_0800F570(iVar3,iVar6,*(int *)(iVar7 + 0x78),*(int *)(iVar7 + 0x7c));
    if (iStack_34 == 1) {
      if ((iStack_30 >> 3) + iStack_30 < iStack_2c) {
        sub_0800F774(param_1,iVar7,iVar3);
      }
      else {
        sub_0800F9AC(param_1,iVar7);
      }
    }
    else if (iStack_34 == 2) {
      if (iStack_30 < iStack_28) {
        sub_0800F774(param_1,iVar7,iVar3);
      }
      else {
        sub_0800F9AC(param_1,iVar7);
      }
    }
    else if (iStack_34 == 3) {
      if ((iStack_28 < iStack_24 >> 1) && (iVar6 = sub_08005CA8(100), iVar6 < 6)) {
        sub_0800F9AC(param_1,iVar7);
      }
      else {
        sub_0800F774(param_1,iVar7,iVar3);
      }
    }
    else {
      sub_0800F774(param_1,iVar7,iVar3);
    }
  }
  return;
}


/* sub_0800786A @ 0x0800786A */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int sub_0800786A(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  short asStack_34 [2];
  undefined4 local_30;
  short local_2c;
  short sStack_2a;
  short asStack_28 [4];
  undefined4 local_20;
  int iStack_1c;
  undefined4 *puStack_18;
  
  *(short *)(param_2 + 0x16) = *(short *)(param_2 + 0x16) + 1;
  local_20._0_2_ = (short)param_1;
  pbVar5 = (byte *)(param_2 + 0x28);
  iVar4 = 0;
  uVar1 = param_1;
  iStack_1c = param_2;
  puStack_18 = param_3;
  if (_DAT_03003b40 < (short)local_20) {
    local_2c = (short)local_20 + -8;
    sStack_2a = (short)((uint)param_1 >> 0x10);
    local_20 = param_1;
    sub_0800F420(asStack_34,pbVar5,&local_2c);
    sub_0800F3F0(asStack_28,asStack_34);
    iVar2 = sub_0800F358(asStack_28,(uint)*(ushort *)(param_2 + 0x10));
    uVar1 = local_20;
    if (iVar2 != 0) {
      local_30 = CONCAT22(sStack_2a >> 3,local_2c >> 3);
      iVar4 = 1;
      *param_3 = local_30;
    }
  }
  local_20 = uVar1;
  if ((short)local_20 < _DAT_03003b44) {
    local_2c = (short)local_20 + 8;
    sStack_2a = (short)((uint)local_20 >> 0x10);
    sub_0800F420(asStack_34,pbVar5,&local_2c);
    sub_0800F3F0(asStack_28,asStack_34);
    iVar2 = sub_0800F358(asStack_28,(uint)*(ushort *)(param_2 + 0x10));
    if (iVar2 != 0) {
      puVar3 = param_3 + iVar4;
      local_30 = CONCAT22(sStack_2a >> 3,local_2c >> 3);
      iVar4 = iVar4 + 1;
      *puVar3 = local_30;
    }
  }
  if (DAT_03003b42 < local_20._2_2_) {
    sStack_2a = local_20._2_2_ + -8;
    local_2c = (short)local_20;
    sub_0800F420(asStack_34,pbVar5,&local_2c);
    sub_0800F3F0(asStack_28,asStack_34);
    iVar2 = sub_0800F358(asStack_28,(uint)*(ushort *)(param_2 + 0x10));
    if (iVar2 != 0) {
      puVar3 = param_3 + iVar4;
      local_30 = CONCAT22(sStack_2a >> 3,local_2c >> 3);
      iVar4 = iVar4 + 1;
      *puVar3 = local_30;
    }
  }
  if (local_20._2_2_ < DAT_03003b46) {
    sStack_2a = local_20._2_2_ + 8;
    local_2c = (short)local_20;
    sub_0800F420(asStack_34,pbVar5,&local_2c);
    sub_0800F3F0(asStack_28,asStack_34);
    iVar2 = sub_0800F358(asStack_28,(uint)*(ushort *)(param_2 + 0x10));
    if (iVar2 != 0) {
      puVar3 = param_3 + iVar4;
      local_30 = CONCAT22(sStack_2a >> 3,local_2c >> 3);
      iVar4 = iVar4 + 1;
      *puVar3 = local_30;
    }
  }
  return iVar4;
}


/* sub_080079E4 @ 0x080079E4 */

undefined4 sub_080079E4(int param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_4 == 0) {
    uVar1 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0xc);
    if (iVar4 == *(int *)(param_3 + 0x20)) {
      uVar1 = 1;
      *param_2 = 1;
    }
    else if (param_4 == 1) {
      uVar1 = 0;
    }
    else if (iVar4 == *(int *)(param_4 * 0x14 + param_3 + 0xc)) {
      uVar1 = 1;
      *param_2 = param_4;
    }
    else {
      iVar3 = 1;
      while (iVar5 = param_4, param_4 = iVar3 + iVar5 >> 1, iVar3 != param_4) {
        iVar2 = *(int *)(param_4 * 0x14 + param_3 + 0xc);
        if (iVar4 == iVar2) {
          *param_2 = param_4;
          return 1;
        }
        if (iVar2 <= iVar4) {
          iVar3 = param_4;
          param_4 = iVar5;
        }
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* sub_08007A4E @ 0x08007A4E */

undefined4 sub_08007A4E(short *param_1,short *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uStack_88;
  int iStack_7c;
  short sStack_78;
  short sStack_76;
  short sStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  short asStack_64 [8];
  int iStack_54;
  int local_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 *puStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 *local_28;
  short *psStack_24;
  short *psStack_20;
  int local_1c;
  int iStack_18;
  
  local_28 = (undefined4 *)(param_3 + 0x80);
  local_50 = 0;
  *(undefined4 *)(param_3 + 0xac) = 0;
  iVar11 = 0;
  *(undefined4 *)(param_3 + 0xa8) = 0;
  if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) {
    return 1;
  }
  DAT_03000c20 = 0;
  DAT_03000c24 = 0;
  iStack_44 = 0;
  psStack_24 = param_1;
  psStack_20 = param_2;
  local_1c = param_3;
  iStack_18 = param_4;
  iStack_7c = sub_0800F570((int)*param_1,(int)param_1[1],(int)*param_2,(int)param_2[1]);
  if (iStack_7c == 1) {
    local_28[0xb] = 1;
    uVar4 = *(undefined4 *)param_2;
    *local_28 = uVar4;
    *(undefined4 *)(local_1c + 0xb0) = uVar4;
    return 1;
  }
  sStack_78 = *param_1;
  sStack_76 = param_1[1];
  sStack_74 = 0;
  iStack_6c = *param_1 * 0x400 + (int)param_1[1];
  iStack_68 = iStack_7c * 0x80 + 0x7f;
  iStack_70 = iStack_7c;
  sub_0800F628((undefined4 *)&sStack_78,0x30023ac,&DAT_03000c24);
  iStack_7c = iStack_7c * 2;
  if (iStack_7c < 6) {
    iStack_7c = 6;
  }
  uStack_88 = CONCAT22(param_1[1] << 3,*param_1 << 3);
  iStack_40 = sub_0800786A(uStack_88,local_1c,(undefined4 *)asStack_64);
  iVar12 = 0;
  if (iStack_40 < 1) {
_08007B2A:
    iStack_30 = (int)param_2 + ((int)param_2 >> 1) + 1;
    puStack_34 = &DAT_03000c3c;
    iVar12 = iVar11;
    do {
      iVar11 = iVar12;
      if (DAT_03000c20 < 1) {
        if (iStack_18 == 0) {
          return 0;
        }
        local_50 = 1;
        break;
      }
      DAT_030047fc = *puStack_34;
      DAT_03004800 = puStack_34[1];
      DAT_03004804 = puStack_34[2];
      DAT_03004808 = puStack_34[3];
      DAT_0300480c = puStack_34[4];
      iVar13 = DAT_03000c20 * 0x14;
      uVar4 = *(undefined4 *)(&DAT_03000c2c + iVar13);
      uVar8 = *(undefined4 *)(&DAT_03000c30 + iVar13);
      *puStack_34 = *(undefined4 *)(&DAT_03000c28 + iVar13);
      puStack_34[1] = uVar4;
      puStack_34[2] = uVar8;
      uVar4 = *(undefined4 *)(&DAT_03000c38 + iVar13);
      puStack_34[3] = *(undefined4 *)(&DAT_03000c34 + iVar13);
      puStack_34[4] = uVar4;
      iVar2 = DAT_03000c20 + -1;
      uVar4 = *puStack_34;
      uVar8 = puStack_34[1];
      uVar5 = puStack_34[2];
      uVar6 = puStack_34[3];
      iVar3 = puStack_34[4];
      iStack_38 = iVar2 >> 1;
      iVar13 = 1;
      DAT_03000c20 = iVar2;
      if (0 < iStack_38) {
        do {
          iVar1 = iVar13 * 2;
          if ((iVar1 < iVar2) &&
             ((int)(&DAT_03000c4c)[iVar13 * 10] <= *(int *)(&DAT_03000c38 + iVar13 * 0x28))) {
            iVar1 = iVar1 + 1;
          }
          iVar9 = iVar1 * 0x14;
          if (iVar3 < *(int *)(&DAT_03000c38 + iVar9)) break;
          iVar13 = iVar13 * 0x14;
          uVar7 = *(undefined4 *)(&DAT_03000c2c + iVar9);
          uVar10 = *(undefined4 *)(&DAT_03000c30 + iVar9);
          *(undefined4 *)(&DAT_03000c28 + iVar13) = *(undefined4 *)(&DAT_03000c28 + iVar9);
          *(undefined4 *)(&DAT_03000c2c + iVar13) = uVar7;
          *(undefined4 *)(&DAT_03000c30 + iVar13) = uVar10;
          uVar7 = *(undefined4 *)(&DAT_03000c38 + iVar9);
          *(undefined4 *)(&DAT_03000c34 + iVar13) = *(undefined4 *)(&DAT_03000c34 + iVar9);
          *(undefined4 *)(&DAT_03000c38 + iVar13) = uVar7;
          iVar13 = iVar1;
        } while (iVar1 <= iStack_38);
      }
      iVar13 = iVar13 * 0x14;
      *(int *)(&DAT_03000c38 + iVar13) = iVar3;
      *(undefined4 *)(&DAT_03000c34 + iVar13) = uVar6;
      *(undefined4 *)(&DAT_03000c30 + iVar13) = uVar5;
      *(undefined4 *)(&DAT_03000c2c + iVar13) = uVar8;
      *(undefined4 *)(&DAT_03000c28 + iVar13) = uVar4;
      iVar2 = sub_080079E4(0x30047fc,&iStack_4c,0x30023ac,DAT_03000c24);
      iVar13 = DAT_03004804;
      if (iVar2 == 0) {
        iVar11 = iVar12 + 1;
        iStack_48 = (short)DAT_03004800 + 1;
        iVar2 = iVar12 * 4 + local_1c;
        *(short *)(iVar2 + 0xb0) = (short)DAT_030047fc;
        *(short *)(iVar2 + 0xb2) = DAT_030047fc._2_2_;
        if ((iStack_30 < iStack_48) || (iStack_7c < iStack_48 + iVar13 + -1)) {
          if (iStack_18 == 0) {
            return 0;
          }
          local_50 = 1;
          break;
        }
        if (0x62 < iVar11) {
          if (iStack_18 == 0) {
            return 0;
          }
          local_50 = 1;
          break;
        }
        if (7 < *(short *)(local_1c + 0x16)) {
          if (iStack_18 == 0) {
            return 0;
          }
          local_50 = 1;
          break;
        }
        sub_0800F628(&DAT_030047fc,0x30023ac,&DAT_03000c24);
        uStack_88 = CONCAT22(DAT_030047fc._2_2_ << 3,(short)DAT_030047fc << 3);
        iStack_40 = sub_0800786A(uStack_88,local_1c,(undefined4 *)asStack_64);
        iVar13 = 0;
        if (0 < iStack_40) {
          iStack_3c = (int)(short)iStack_48;
          do {
            if ((asStack_64[iVar13 * 2] == *param_2) && (asStack_64[iVar13 * 2 + 1] == param_2[1]))
            {
              iVar13 = iVar11 * 4;
              iVar11 = iVar12 + 2;
              *(undefined4 *)(iVar13 + local_1c + 0xb0) = *(undefined4 *)param_2;
              goto _08007DE0;
            }
            sStack_78 = asStack_64[iVar13 * 2];
            sStack_76 = asStack_64[iVar13 * 2 + 1];
            iStack_70 = sub_0800F570((int)sStack_78,(int)sStack_76,(int)*param_2,(int)param_2[1]);
            iStack_70 = iStack_70 + iStack_48;
            sStack_74 = (short)iStack_3c;
            iStack_6c = sStack_78 * 0x400 + (int)sStack_76;
            iStack_68 = iStack_70 * 0x80 + (0x7f - sStack_74);
            iVar2 = sub_080079E4((int)&sStack_78,&iStack_4c,0x30023ac,DAT_03000c24);
            if (iVar2 == 0) {
              sub_0800F588((undefined4 *)&sStack_78,0x3000c28,&DAT_03000c20);
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 < iStack_40);
        }
      }
      iVar12 = iVar11;
    } while (iStack_44 == 0);
  }
  else {
    uStack_2c = 1;
    do {
      sStack_78 = asStack_64[iVar12 * 2];
      sStack_76 = asStack_64[iVar12 * 2 + 1];
      iStack_70 = sub_0800F570((int)sStack_78,(int)sStack_76,(int)*param_2,(int)param_2[1]);
      iStack_70 = iStack_70 + 1;
      sStack_74 = (short)uStack_2c;
      iStack_6c = sStack_78 * 0x400 + (int)sStack_76;
      iStack_68 = iStack_70 * 0x80 + (0x7f - sStack_74);
      sub_0800F588((undefined4 *)&sStack_78,0x3000c28,&DAT_03000c20);
      iVar12 = iVar12 + 1;
    } while (iVar12 < iStack_40);
    if (iStack_44 == 0) goto _08007B2A;
  }
_08007DE0:
  iVar12 = iVar11 * 4 + local_1c;
  *(undefined2 *)(iVar12 + 0xb0) = 0xffff;
  *(undefined2 *)(iVar12 + 0xb2) = 0xffff;
  if (iVar11 < 2) {
    return 0;
  }
  iStack_54 = 0;
  iStack_40 = iVar11 + -1;
  iVar13 = local_1c;
  for (iVar12 = iVar11 + -2; local_1c = iVar13, 0 < iVar12; iVar12 = iVar12 + -1) {
    iVar2 = iStack_40 * 4 + iVar13;
    iVar13 = iVar12 * 4 + iVar13;
    iVar3 = sub_0800F570((int)*(short *)(iVar13 + 0xb0),(int)*(short *)(iVar13 + 0xb2),
                         (int)*(short *)(iVar2 + 0xb0),(int)*(short *)(iVar2 + 0xb2));
    iVar2 = iVar12;
    if (iVar3 != 1) {
      *(undefined2 *)(iVar13 + 0xb0) = 0xffff;
      *(undefined2 *)(iVar13 + 0xb2) = 0xffff;
      iStack_54 = 1;
      iVar2 = iStack_40;
    }
    iStack_40 = iVar2;
    iVar13 = local_1c;
  }
  iVar12 = iStack_40 * 4 + iVar13;
  iVar12 = sub_0800F570((int)*(short *)(iVar13 + 0xb0),(int)*(short *)(iVar13 + 0xb2),
                        (int)*(short *)(iVar12 + 0xb0),(int)*(short *)(iVar12 + 0xb2));
  if (iVar12 == 1) {
    iVar12 = iVar11;
    if (iStack_54 == 0) goto _08007EC2;
  }
  else {
    *(undefined2 *)(iVar13 + 0xb0) = 0xffff;
    *(undefined2 *)(iVar13 + 0xb2) = 0xffff;
  }
  iVar12 = 0;
  iVar13 = 0;
  if (0 < iVar11) {
    do {
      iVar2 = iVar13 * 4 + local_1c;
      if (*(short *)(iVar2 + 0xb0) != -1) {
        iVar3 = iVar12 * 4 + local_1c;
        *(undefined2 *)(iVar3 + 0xb0) = *(undefined2 *)(iVar2 + 0xb0);
        iVar12 = iVar12 + 1;
        *(undefined2 *)(iVar3 + 0xb2) = *(undefined2 *)(iVar2 + 0xb2);
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar11);
  }
_08007EC2:
  if (iVar12 < 1) {
    uVar4 = 0;
  }
  else if (local_50 == 0) {
    local_1c = iVar12 * 4 + local_1c;
    if ((*(short *)(local_1c + 0xac) == *param_2) && (*(short *)(local_1c + 0xae) == param_2[1])) {
_08007F38:
      local_28[0xb] = iVar12;
      *local_28 = *(undefined4 *)param_2;
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    iVar11 = 0;
    do {
      iVar13 = iVar11 * 4 + local_1c;
      iVar13 = sub_0800F570((int)*(short *)(iVar13 + 0xb0),(int)*(short *)(iVar13 + 0xb2),
                            (int)*param_2,(int)param_2[1]);
      if (iVar13 <= iStack_18) {
        local_1c = iVar11 * 4 + local_1c;
        *(undefined2 *)(local_1c + 0xb0) = 0xffff;
        *(undefined2 *)(local_1c + 0xb2) = 0xffff;
        iVar12 = iVar11;
        goto _08007F38;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar12);
    uVar4 = 0;
  }
  return uVar4;
}


/* sub_08007F4C @ 0x08007F4C */

void sub_08007F4C(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((uint)*(byte *)(param_1 + 9) == (param_2 & 0xff)) {
    if (param_2 != 6) {
      return;
    }
  }
  else {
    if (3 < *(byte *)(param_1 + 9)) {
      *(undefined1 *)(param_1 + 10) = 0x2d;
    }
    *(char *)(param_1 + 9) = (char)param_2;
  }
  if ((param_2 == 7) && (*(short *)(param_1 + 0x9a) == 2)) {
    piVar1 = &DAT_030047f0;
    if (*(char *)(param_1 + 0xb) == '\x02') {
      piVar1 = &DAT_03003b54;
    }
    sub_080062FC(piVar1,param_1);
    sub_08006294(&DAT_03003b48,param_1);
  }
  iVar3 = *(int *)(param_1 + 0x274);
  if (param_2 == 6) {
    sub_0800BEB8(iVar3);
    sub_08002466(iVar3,0);
    if (*(byte *)(param_1 + 9) != 0) {
      if (3 < *(byte *)(param_1 + 9)) {
        *(undefined1 *)(param_1 + 10) = 0x2d;
      }
      *(undefined1 *)(param_1 + 9) = 0;
    }
    if (*(short *)(param_1 + 0x9a) == 2) {
      *(undefined1 *)(param_1 + 10) = 0x14;
      *(undefined2 *)(param_1 + 0x14) = 0x50;
    }
  }
  else if (param_2 == 7) {
    sub_0800BEEC(iVar3);
    sub_0800ACFE(0x17);
    *(undefined2 *)(param_1 + 0x88) = 7;
  }
  else {
    iVar2 = *(int *)(&gUnknown_086B6068 + param_2 * 4);
    if ((*(int *)(*(int *)(*(int *)(iVar3 + 0x1c) + 0x28) + iVar2 * 0x10) != 0) &&
       (*(int *)(*(int *)(iVar3 + 0x18) + iVar2 * 0x14) != 0)) {
      sub_08002466(iVar3,iVar2);
    }
  }
  return;
}


/* sub_08008016 @ 0x08008016 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08008016(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  short *psStack_18;
  
  iVar8 = DAT_030047f4;
  if (DAT_030047f4 != 0) {
    if (((DAT_030007dc == 0) && ((DAT_03003b6c & 0xf) == 0)) &&
       (*(int *)(DAT_030047f4 + 0x54) < *(int *)(DAT_030047f4 + 0x58))) {
      iVar7 = *(int *)(DAT_030047f4 + 0x54) + *(int *)(DAT_030047f4 + 0x5c);
      *(int *)(DAT_030047f4 + 0x54) = iVar7;
      if (*(int *)(iVar8 + 0x58) < iVar7) {
        *(int *)(iVar8 + 0x54) = *(int *)(iVar8 + 0x58);
      }
    }
    if (DAT_03003b34 == 0) {
      if ((*(short *)(iVar8 + 0x20) >> 3 == DAT_030007c0 >> 7) &&
         (*(short *)(iVar8 + 0x22) >> 3 == DAT_030007c2 >> 7)) {
        uStack_20 = (uint)(_DAT_03003b30 == 0);
        if (_DAT_03003b30 == 0) {
          _DAT_03003b30 = sub_08005CA8(0x3c);
          _DAT_03003b30 = _DAT_03003b30 + 0x1e;
        }
        else {
          _DAT_03003b30 = _DAT_03003b30 + -1;
        }
      }
      else {
        uStack_28 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
        sub_0800F478(iVar8 + 8,uStack_28);
        iVar8 = DAT_030047f4;
        *(int *)(DAT_030047f4 + 0x78) = (int)(*(short *)(DAT_030047f4 + 0x20) >> 3);
        *(int *)(iVar8 + 0x7c) = (int)(*(short *)(iVar8 + 0x22) >> 3);
        uStack_20 = 1;
      }
      uStack_28 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
      uStack_1c = uStack_28;
      uStack_2c = CONCAT22((short)(DAT_0300060a + DAT_0300060e) >> 1,
                           (short)(DAT_03000608 + DAT_0300060c) >> 1);
      uStack_24 = uStack_2c;
      iVar8 = DAT_03003b58;
      if (uStack_20 != 0) {
        while (iVar8 != 0) {
          psVar5 = (short *)(iVar8 + 0x20);
          uVar4 = sub_0800F540((short *)&uStack_1c,psVar5);
          if ((uVar4 < *(ushort *)(iVar8 + 0xe)) || (*(short *)(iVar8 + 0x1e) != 0)) {
            uVar4 = sub_0800F540((short *)&uStack_24,psVar5);
            if (uVar4 < 0x5101) {
              *(undefined1 *)(iVar8 + 0xb) = 1;
              iVar7 = *(int *)(iVar8 + 0xa0);
              sub_080062FC(&DAT_03003b54,iVar8);
              sub_08006294(&DAT_030047f0,iVar8);
              iVar8 = iVar7;
            }
            else {
              iVar8 = *(int *)(iVar8 + 0xa0);
            }
          }
          else if ((((*(short *)(iVar8 + 0x12) == 0) || (3 < DAT_030047f0)) ||
                   (uVar4 = sub_0800F540((short *)&uStack_24,psVar5), 0x50ff < uVar4)) ||
                  (iVar7 = sub_08005CA8(0xffff), 199 < iVar7)) {
            iVar8 = *(int *)(iVar8 + 0xa0);
          }
          else {
            *(undefined1 *)(iVar8 + 0xb) = 3;
            iVar7 = *(int *)(iVar8 + 0xa0);
            sub_080062FC(&DAT_03003b54,iVar8);
            sub_08006294(&DAT_030047f0,iVar8);
            iVar8 = iVar7;
          }
        }
      }
      iVar8 = *(int *)(DAT_030047f4 + 0xa0);
joined_r0x0800820c:
      do {
        while( true ) {
          while( true ) {
            if (iVar8 == 0) {
              return;
            }
            if ((*(short *)(iVar8 + 0x1e) != 0) &&
               (((iVar7 = (*(ushort *)(iVar8 + 0x1e) - 1) * 0x10000,
                 *(short *)(iVar8 + 0x1e) = (short)((uint)iVar7 >> 0x10), iVar7 >> 0x10 == 0 &&
                 (*(short *)(iVar8 + 0x3e) != 1)) || (iVar7 = sub_08005CA8(10000), 0x2648 < iVar7)))
               ) {
              *(undefined4 *)(iVar8 + 600) = 0;
              *(undefined4 *)(iVar8 + 0x25c) = 0;
            }
            if (*(short *)(iVar8 + 0x14) != 0) {
              *(short *)(iVar8 + 0x14) = *(short *)(iVar8 + 0x14) + -1;
            }
            cVar1 = *(char *)(iVar8 + 10);
            if (cVar1 == '\0') break;
            *(char *)(iVar8 + 10) = cVar1 + -1;
            if ((cVar1 == '\x01') &&
               (*(int *)(iVar8 + 0xa8) < *(int *)(iVar8 + 0xac) ||
                ((*(ushort *)(iVar8 + 0x22) | *(ushort *)(iVar8 + 0x20)) & 7) != 0)) {
              if (*(short *)(iVar8 + 0x10) == 0) {
                uVar4 = 1;
              }
              else {
                uVar4 = 3;
              }
              sub_08007F4C(iVar8,uVar4);
            }
            *(undefined1 *)(iVar8 + 0xb) = 0;
            iVar8 = *(int *)(iVar8 + 0xa0);
          }
          if (*(byte *)(iVar8 + 9) < 4) break;
          iVar8 = *(int *)(iVar8 + 0xa0);
        }
        if ((uStack_20 != 0) && (*(char *)(iVar8 + 0xb) != '\x03')) {
          uVar4 = sub_0800F540((short *)&uStack_1c,(short *)(iVar8 + 0x20));
          if (((*(ushort *)(iVar8 + 0xe) < uVar4) && (*(short *)(iVar8 + 0x1e) == 0)) ||
             (uVar4 = sub_0800F540((short *)&uStack_24,(short *)(iVar8 + 0x20)), 0x5100 < uVar4)) {
            *(undefined1 *)(iVar8 + 0xb) = 2;
            if (*(byte *)(iVar8 + 9) < 3) {
              sub_08007F4C(iVar8,0);
            }
            else {
              *(undefined1 *)(iVar8 + 8) = 0;
            }
            iVar7 = *(int *)(iVar8 + 0xa0);
            sub_080062FC(&DAT_030047f0,iVar8);
            sub_08006294(&DAT_03003b54,iVar8);
            iVar8 = iVar7;
            goto joined_r0x0800820c;
          }
        }
        if ((DAT_03003b6c & 0xf) == 0) {
          iVar7 = *(int *)(iVar8 + 0x58);
          if ((*(int *)(iVar8 + 0x54) < iVar7) &&
             (iVar6 = *(int *)(iVar8 + 0x54) + *(int *)(iVar8 + 0x5c),
             *(int *)(iVar8 + 0x54) = iVar6, iVar7 < iVar6)) {
            *(int *)(iVar8 + 0x54) = iVar7;
          }
        }
        if ((uStack_20 == 0) && (*(int *)(iVar8 + 0xa8) < *(int *)(iVar8 + 0xac))) {
_080083B4:
          if ((*(char *)(iVar8 + 9) == '\x01') || (*(char *)(iVar8 + 9) == '\x03')) {
            uVar4 = *(uint *)(iVar8 + 0x20);
            iVar7 = *(int *)(iVar8 + 0xa8) * 4 + iVar8;
            uVar2 = *(short *)(iVar7 + 0xb0) << 3;
            sVar3 = *(short *)(iVar7 + 0xb2) << 3;
            uStack_30 = CONCAT22(sVar3,uVar2);
            uStack_2c = uStack_30;
            uStack_28._0_2_ = (short)uVar4;
            uStack_28._2_2_ = (short)(uVar4 >> 0x10);
            if (((uint)uVar2 == (uVar4 & 0xffff)) && (sVar3 == uStack_28._2_2_)) {
              if (*(char *)(iVar8 + 0xb) != '\x02') {
                *(int *)(iVar8 + 0x78) = (int)(short)uStack_28 >> 3;
                *(int *)(iVar8 + 0x7c) = (int)uStack_28._2_2_ >> 3;
                *(int *)(iVar8 + 0xa8) = *(int *)(iVar8 + 0xa8) + 1;
              }
              if (*(int *)(iVar8 + 0xac) <= *(int *)(iVar8 + 0xa8)) {
                *(undefined1 *)(iVar8 + 0xb) = 0;
                iVar8 = *(int *)(iVar8 + 0xa0);
                goto joined_r0x0800820c;
              }
              iVar7 = *(int *)(iVar8 + 0xa8) * 4 + iVar8;
              uStack_30 = CONCAT22(*(short *)(iVar7 + 0xb2) << 3,*(short *)(iVar7 + 0xb0) << 3);
              uStack_2c = uStack_30;
              *(undefined1 *)(iVar8 + 0xb) = 1;
            }
            if ((uStack_2c & 0xffff) == (uVar4 & 0xffff)) {
              if (uStack_28._2_2_ < uStack_2c._2_2_) {
                iVar7 = ((uint)*(ushort *)(iVar8 + 0x26) + (uint)*(ushort *)(iVar8 + 0xc)) * 0x10000
                ;
                *(short *)(iVar8 + 0x26) = (short)((uint)iVar7 >> 0x10);
                if ((int)uStack_2c._2_2_ < iVar7 >> 0x14) {
                  *(short *)(iVar8 + 0x26) = uStack_2c._2_2_ << 4;
                }
                sub_0800F4DC(iVar8 + 8);
                *(undefined1 *)(iVar8 + 8) = 0;
              }
              else {
                iVar7 = ((uint)*(ushort *)(iVar8 + 0x26) - (uint)*(ushort *)(iVar8 + 0xc)) * 0x10000
                ;
                *(short *)(iVar8 + 0x26) = (short)((uint)iVar7 >> 0x10);
                if (iVar7 >> 0x14 < (int)uStack_2c._2_2_) {
                  *(short *)(iVar8 + 0x26) = uStack_2c._2_2_ << 4;
                }
                sub_0800F4DC(iVar8 + 8);
                *(undefined1 *)(iVar8 + 8) = 1;
              }
              *(int *)(iVar8 + 0x7c) = (int)*(short *)(iVar8 + 0x22) >> 3;
            }
            else {
              if ((short)uStack_28 < (short)uStack_2c) {
                iVar7 = ((uint)*(ushort *)(iVar8 + 0x24) + (uint)*(ushort *)(iVar8 + 0xc)) * 0x10000
                ;
                *(short *)(iVar8 + 0x24) = (short)((uint)iVar7 >> 0x10);
                if ((int)(short)uStack_2c < iVar7 >> 0x14) {
                  *(short *)(iVar8 + 0x24) = (short)uStack_2c << 4;
                }
                sub_0800F4DC(iVar8 + 8);
                *(undefined1 *)(iVar8 + 8) = 3;
              }
              else {
                iVar7 = ((uint)*(ushort *)(iVar8 + 0x24) - (uint)*(ushort *)(iVar8 + 0xc)) * 0x10000
                ;
                *(short *)(iVar8 + 0x24) = (short)((uint)iVar7 >> 0x10);
                if (iVar7 >> 0x14 < (int)(short)uStack_2c) {
                  *(short *)(iVar8 + 0x24) = (short)uStack_2c << 4;
                }
                sub_0800F4DC(iVar8 + 8);
                *(undefined1 *)(iVar8 + 8) = 2;
              }
              *(int *)(iVar8 + 0x78) = (int)*(short *)(iVar8 + 0x20) >> 3;
            }
            if ((*(byte *)(iVar8 + 9) < 3) && (iVar7 = *(int *)(DAT_030047f4 + 0xa0), iVar8 != 0)) {
              psStack_18 = (short *)(iVar7 + 0x2c);
              iVar6 = iVar8;
              do {
                if ((((iVar7 != iVar6) && (*psStack_18 < *(short *)(iVar6 + 0x30))) &&
                    (*(short *)(iVar6 + 0x2c) < psStack_18[2])) &&
                   (((psStack_18[1] < *(short *)(iVar6 + 0x32) &&
                     (*(short *)(iVar6 + 0x2e) < psStack_18[3])) && (*(char *)(iVar7 + 9) != '\0')))
                   ) {
                  if (*(short *)(iVar6 + 0xc) < *(short *)(iVar7 + 0xc)) {
                    sub_08007F4C(iVar6,0);
                    *(undefined1 *)(iVar6 + 10) = 8;
                    break;
                  }
                  sub_08007F4C(iVar7,0);
                  *(undefined1 *)(iVar7 + 10) = 8;
                }
                iVar6 = *(int *)(iVar6 + 0xa0);
              } while (iVar6 != 0);
            }
            iVar8 = *(int *)(iVar8 + 0xa0);
            goto joined_r0x0800820c;
          }
          iVar8 = *(int *)(iVar8 + 0xa0);
          goto joined_r0x0800820c;
        }
        *(undefined1 *)(iVar8 + 0xb) = 0;
        *(undefined2 *)(iVar8 + 0x16) = 0;
        sub_0800755A(iVar8);
        if (*(int *)(iVar8 + 0xa8) < *(int *)(iVar8 + 0xac)) {
          if (*(byte *)(iVar8 + 9) == 0) {
            if (*(short *)(iVar8 + 0x10) == 0) {
              uVar4 = 1;
            }
            else {
              uVar4 = 3;
            }
            sub_08007F4C(iVar8,uVar4);
          }
          goto _080083B4;
        }
        if (*(byte *)(iVar8 + 9) < 4) {
          sub_08007F4C(iVar8,0);
        }
        iVar8 = *(int *)(iVar8 + 0xa0);
      } while( true );
    }
    DAT_03003b34 = DAT_03003b34 + -1;
  }
  return;
}


/* sub_080085A0 @ 0x080085A0 */

void sub_080085A0(int param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  short local_28;
  undefined2 local_26;
  short local_24;
  undefined2 local_22;
  short local_20 [3];
  undefined2 local_1a;
  int local_18;
  
  if (param_1 == 0) {
    return;
  }
  *(int *)(param_1 + 0x78) = (int)*param_2 >> 3;
  *(int *)(param_1 + 0x7c) = (int)param_2[1] >> 3;
  *(undefined1 *)(param_1 + 8) = 0;
  sub_08007F4C(param_1,0);
  *(undefined1 *)(param_1 + 10) = 0;
  local_18 = param_1 + 0x40;
  *(undefined4 *)(param_1 + 0x18) = 0;
  local_20[2] = *(short *)(param_1 + 0x48) << 3;
  local_1a = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  sVar1 = sub_0800F540(local_20 + 2,local_20);
  uVar2 = sub_0800F540(local_20 + 2,local_20);
  *(short *)(param_1 + 0xe) = sVar1 + (short)(uVar2 >> 1);
  iVar3 = *(int *)(param_1 + 0x274);
  sub_0800236E(&local_30,iVar3);
  sub_0800507A(DAT_03000600,(short *)&local_30,1,0);
  sub_0800236E(&local_30,iVar3);
  local_28 = (short)local_30;
  local_26 = local_30._2_2_;
  local_24 = (short)local_2c;
  local_22 = local_2c._2_2_;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  *(char *)(param_1 + 0x2a) = (char)local_2c - (char)local_30;
  *(char *)(param_1 + 0x2b) = (char)((uint)local_2c >> 0x10) - (char)((uint)local_30 >> 0x10);
  local_2c = *(undefined4 *)param_2;
  sub_0800F478(param_1 + 8,local_2c);
  if (*(short *)(local_18 + 6) == 1) {
    *(undefined2 *)(param_1 + 0x10) = 1;
  }
  else {
    *(undefined2 *)(param_1 + 0x10) = 0;
  }
  *(undefined2 *)(param_1 + 0xc) =
       *(undefined2 *)(&gUnknown_080116A4 + *(int *)(param_1 + 0x34) * 2);
  if (*(short *)(param_1 + 0x9a) == 1) {
    return;
  }
  if (*(short *)(param_1 + 0x3c) == 0) {
    sub_080062FC(&DAT_030047f0,param_1);
    sub_08006294(&DAT_03003b48,param_1);
    sub_0800507A(DAT_03000600,(short *)(param_1 + 0x2c),0,0);
  }
  else {
    uStack_34 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
    local_30 = uStack_34;
    uVar2 = sub_0800F540((short *)&local_30,param_2);
    if (uVar2 <= *(ushort *)(param_1 + 0xe)) {
      uStack_38 = CONCAT22((short)(DAT_0300060a + DAT_0300060e) >> 1,
                           (short)(DAT_03000608 + DAT_0300060c) >> 1);
      local_2c = uStack_38;
      uVar2 = sub_0800F540((short *)&local_2c,(short *)(param_1 + 0x20));
      if (uVar2 < 0x5101) {
        *(undefined1 *)(param_1 + 0xb) = 0;
        goto _0800872A;
      }
    }
    *(undefined1 *)(param_1 + 0xb) = 2;
    sub_080062FC(&DAT_030047f0,param_1);
    sub_08006294(&DAT_03003b54,param_1);
  }
_0800872A:
  sVar1 = *(short *)(param_1 + 0x3c);
  if ((((sVar1 == 2) || (sVar1 == 3)) || (sVar1 == 4)) || (sVar1 == 5)) {
    *(undefined2 *)(param_1 + 0x12) = 1;
  }
  else {
    *(undefined2 *)(param_1 + 0x12) = 0;
  }
  return;
}


/* sub_08008764 @ 0x08008764 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08008764(undefined4 param_1)

{
  undefined4 local_10;
  undefined2 local_c;
  undefined2 uStack_a;
  
  _DAT_03003b40 = 0;
  local_c = (short)param_1;
  uStack_a = (short)((uint)param_1 >> 0x10);
  local_10 = CONCAT22(uStack_a << 3,local_c << 3);
  _DAT_03003b44 = local_10;
  _DAT_03003b38 = 0;
  _DAT_03003b3c = param_1;
  return;
}


/* sub_080087A0 @ 0x080087A0 */

void sub_080087A0(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  DAT_03003b34 = param_1;
  for (iVar3 = *(int *)(DAT_030047f4 + 0xa0); iVar2 = DAT_03003b58, iVar3 != 0;
      iVar3 = *(int *)(iVar3 + 0xa0)) {
    bVar1 = *(byte *)(iVar3 + 10);
    if ((bVar1 != 0) && (param_1 < bVar1)) {
      *(byte *)(iVar3 + 10) = bVar1 - (char)param_1;
    }
    if (*(char *)(iVar3 + 9) != '\x03') {
      sub_08007F4C(iVar3,0);
    }
  }
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa0)) {
    bVar1 = *(byte *)(iVar2 + 10);
    if ((bVar1 != 0) && (param_1 < bVar1)) {
      *(byte *)(iVar2 + 10) = bVar1 - (char)param_1;
    }
    if (*(char *)(iVar2 + 9) != '\x03') {
      sub_08007F4C(iVar2,0);
    }
  }
  return;
}


