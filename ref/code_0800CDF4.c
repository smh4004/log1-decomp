/* Ghidra reference decompilation of code_0800CDF4 (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_0800CDF4 @ 0x0800CDF4 */

void sub_0800CDF4(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined *local_18;
  undefined4 local_14;
  
  iVar1 = sub_080058D6(param_1 + 4);
  __call_via_r2(param_2,iVar1,*(int *)(*param_2 + 8) + *param_2);
  iVar2 = __call_via_r3(param_2,*(undefined4 *)(param_1 + 0x10),0,
                        *(int *)(*param_2 + 0x14) + *param_2);
  local_14 = CONCAT22(*(short *)(iVar2 + 0x22) + *(short *)(param_1 + 0x16),
                      *(short *)(iVar2 + 0x20) + *(short *)(param_1 + 0x14));
  *(undefined4 *)(iVar1 + 0x20) = local_14;
  __call_via_r2(param_2,(undefined4 *)(iVar1 + 0x20),*(int *)(*param_2 + 0x1c) + *param_2);
  sub_0800236E(&local_18,iVar1);
  sub_0800507A(DAT_03000600,&local_18,1,0);
  local_18 = &_0800F250;
  local_14 = iVar1;
  sub_080097F8(&local_18);
  return;
}


/* sub_0800CE80 @ 0x0800CE80 */

void sub_0800CE80(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x40;
  REG_DMA3SAD = 0x5000000;
  REG_DMA3DAD = param_1 + 8;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  return;
}


/* sub_0800CE9C @ 0x0800CE9C */

void sub_0800CE9C(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort local_410 [512];
  
  iVar4 = *(int *)(param_1 + 4) * 0x400;
  iVar1 = 0;
  do {
    uVar3 = (uint)*(ushort *)(iVar1 * 2 + param_1 + 8);
    iVar2 = iVar1 + 1;
    local_410[iVar1] =
         (ushort)(((int)(iVar4 * ((uVar3 << 0x11) >> 0x1b)) >> 0x10) << 10) |
         (ushort)(iVar4 * (uVar3 & 0x1f) >> 0x10) |
         (ushort)(((int)(iVar4 * ((uVar3 << 0x16) >> 0x1b)) >> 0x10) << 5);
    iVar1 = iVar2;
  } while (iVar2 < 0x200);
  REG_DMA3SAD = local_410;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  return;
}


/* sub_0800CF00 @ 0x0800CF00 */

bool sub_0800CF00(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  return iVar1 == 0;
}


/* sub_0800CF10 @ 0x0800CF10 */

void sub_0800CF10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080095DC(*(undefined4 *)(param_1 + 8));
  sub_0800AB3E();
  WaitForVBlank(1);
  REG_DISPCNT = 0x404;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = 0x100;
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = 0x100;
  REG_BLDCNT = 0;
  REG_DMA3SAD = **(undefined4 **)(param_1 + 8);
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  iVar2 = 0;
  do {
    REG_DMA3SAD = iVar2 * 0xf0 + iVar1;
    REG_DMA3DAD = iVar2 * 0xf0 + 0x6000000;
    Ram040000dc = 0x78;
    DAT_040000de = 0x8000;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xa0);
  return;
}


/* sub_0800CF76 @ 0x0800CF76 */

undefined4 sub_0800CF76(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if ((iVar1 != 0) && ((DAT_03003d14 & 1) == 0)) {
    return 0;
  }
  return 1;
}


/* sub_0800CF8E @ 0x0800CF8E */

undefined4 sub_0800CF8E(void)

{
  return 0;
}


/* sub_0800CF92 @ 0x0800CF92 */

undefined4 sub_0800CF92(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    sub_0800494A(&DAT_03000818,*(undefined4 *)(param_1 + 4),0);
    iVar1 = iVar1 + 1;
  } while (iVar1 <= (int)(uint)*(ushort *)(param_1 + 8));
  return 1;
}


/* sub_0800CFB6 @ 0x0800CFB6 */

undefined4 sub_0800CFB6(int param_1)

{
  undefined *local_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(param_1 + 4);
  local_c = (uint)*(ushort *)(param_1 + 8);
  local_10 = &_0800F1E0;
  sub_080097F8(&local_10);
  return 1;
}


/* sub_0800CFD2 @ 0x0800CFD2 */

undefined4 sub_0800CFD2(void)

{
  undefined *local_40c [259];
  
  local_40c[0] = &_0800F238;
  sub_080097F8(local_40c);
  return 1;
}


/* sub_0800CFEE @ 0x0800CFEE */

void sub_0800CFEE(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = __call_via_r1(param_1,*param_1);
  while ((iVar1 != 0 && ((param_2 == 0 || (DAT_03003d14 == 0))))) {
    param_1 = param_1 + 3;
    iVar1 = __call_via_r1(param_1,*param_1);
  }
  return;
}


/* sub_0800D034 @ 0x0800D034 */

void sub_0800D034(int param_1)

{
  *(undefined4 *)(param_1 + 0x24) = 900;
  return;
}


/* sub_0800D03C @ 0x0800D03C */

undefined4 sub_0800D03C(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  short local_28;
  short sStack_26;
  short local_24;
  short local_22;
  undefined4 local_20;
  short local_1c;
  short local_1a;
  undefined2 local_18;
  undefined2 local_16;
  
  if (param_2 == 0) {
    sub_08002300(&local_24,param_1);
    local_1c = local_24;
    local_1a = local_22;
    local_18 = (short)local_20;
    local_16 = local_20._2_2_;
    sub_0800994C(&local_28,&local_1c,2);
    uVar1 = sub_08003398();
    local_20._0_2_ = (short)uVar1;
    if ((((local_28 <= (short)local_20) && ((short)local_20 < local_24)) &&
        (local_20._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_26 <= local_20._2_2_)) &&
       (local_20._2_2_ < local_22)) {
      iVar4 = *(int *)(param_1 + 0x3c);
      local_20 = uVar1;
      iVar2 = sub_08000926(&DAT_03000028,iVar4);
      if (iVar2 != 0) {
        sub_0800ACFE(5);
        pcVar3 = "You can\'t possibly carry more Senzu beans!";
        if (iVar4 != 0x13) {
          pcVar3 = "You can\'t possibly carry more herbs!";
        }
        sub_08004E98(&DAT_03000864,pcVar3);
        return 1;
      }
      sub_0800ACFE(7);
      __call_via_r2(param_1,iVar4,*(undefined4 *)(&DAT_085c2258 + iVar4 * 0x18));
      sub_0800507A(DAT_03000600,&local_1c,1,0);
      return 1;
    }
  }
  else if (param_2 == 6) {
    sub_08002300(&local_1c,param_1);
    sub_0800507A(DAT_03000600,&local_1c,0,0);
    return 0;
  }
  return 0;
}


/* sub_0800D11C @ 0x0800D11C */

void sub_0800D11C(int param_1)

{
  short local_18;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    sub_08002E42(&local_18);
    sub_08002300(&sStack_10,param_1);
    if ((((local_18 < sStack_c) && (sStack_10 < sStack_14)) && (sStack_16 < sStack_a)) &&
       (sStack_e < sStack_12)) {
      *(undefined4 *)(param_1 + 0x24) = 900;
    }
    else {
      sub_0800245A(param_1,&gUnknown_08011E00);
      *(undefined4 *)(param_1 + 0x38) = 0x800d03d;
      sub_08002300(&sStack_10,param_1);
      sub_0800507A(DAT_03000600,&sStack_10,0,0);
    }
  }
  else {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  }
  return;
}


/* sub_0800D19C @ 0x0800D19C */

undefined4 sub_0800D19C(void)

{
  return 0;
}


/* sub_0800D1A0 @ 0x0800D1A0 */

void sub_0800D1A0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  iVar1 = sub_0800AEC6(param_2,param_1);
  *(undefined4 *)(iVar1 + 0x38) = 0x800d03d;
  *(undefined4 *)(iVar1 + 0x3c) = param_1;
  sub_08002300(auStack_10);
  sub_0800507A(DAT_03000600,auStack_10,0,0);
  return;
}


/* sub_0800D1CE @ 0x0800D1CE */

void sub_0800D1CE(undefined4 param_1,int param_2)

{
  sub_08004E98(&DAT_03000864,(&gUnknown_085C2FB8)[param_2]);
  sub_080028C4(param_1);
  return;
}


/* sub_0800D1E6 @ 0x0800D1E6 */

void sub_0800D1E6(undefined4 param_1,int param_2)

{
  (&DAT_0300004e)[param_2] = (&DAT_0300004e)[param_2] + '\x01';
  sub_08004E98(&DAT_03000864,(&gUnknown_085C2FB8)[param_2]);
  sub_080028C4(param_1);
  return;
}


/* sub_0800D20A @ 0x0800D20A */

void sub_0800D20A(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800245A(param_1,&gUnknown_08012124,param_3,param_4,param_4);
  *(undefined4 *)(param_1 + 0x38) = 0x8002553;
  if (param_2 == 0x1f) {
    sub_080032A2(5);
  }
  else if (param_2 == 0x20) {
    sub_080032A2(10);
  }
  else if (param_2 == 0x21) {
    sub_080032A2(0x14);
  }
  return;
}


/* sub_0800D26C @ 0x0800D26C */

void sub_0800D26C(int param_1)

{
  sub_0800ACFE(*(undefined4 *)(param_1 + 4));
  return;
}


/* sub_0800D276 @ 0x0800D276 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800D276(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short sStack_20;
  short sStack_1e;
  
  uVar1 = *param_2;
  sStack_1e = 0;
  if (DAT_03004635 != 0) {
    do {
      sStack_20 = 0;
      if (DAT_03004634 != 0) {
        DAT_0300463a = (short)(uVar1 >> 0x10);
        do {
          iVar2 = 0;
          iVar5 = (sStack_1e * 2 + (int)sStack_20) * 0x4b0;
          do {
            iVar4 = *(int *)(((int)*DAT_03000600 * (int)(short)(DAT_0300463a + sStack_1e) +
                             (int)(short)(((uVar1 & 0xffff) + (int)sStack_20) * 0x10000 >> 0x10)) *
                             4 + *(int *)(DAT_03000600 + iVar2 * 2 + 0x10));
            if (iVar4 == 0) {
              DAT_030047ec = 0;
              REG_DMA3SAD = 0x30047ec;
              REG_DMA3DAD = iVar5 + iVar2 * 0x12c0 + 0x2000000;
              Ram040000dc = 300;
              DAT_040000de = 0x8500;
            }
            else {
              REG_DMA3SAD = iVar4;
              REG_DMA3DAD = iVar5 + iVar2 * 0x12c0 + 0x2000000;
              Ram040000dc = 300;
              DAT_040000de = 0x8400;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 3);
          sStack_20 = sStack_20 + 1;
        } while (sStack_20 < (short)(ushort)DAT_03004634);
      }
      sStack_1e = sStack_1e + 1;
    } while (sStack_1e < (short)(ushort)DAT_03004635);
  }
  _DAT_03004638 = uVar1;
  uVar1 = sub_08004EF4(DAT_03000600,param_2);
  if ((uVar1 != 0) && (DAT_03004636 != uVar1)) {
    DAT_03004636 = (byte)uVar1;
    uVar3 = sub_080095D0(*(undefined4 *)(*(int *)(DAT_03000600 + 0xe) + (uVar1 & 0xff) * 4 + -4));
    sub_08009626(&REG_DMA3SAD,&DAT_06005680,uVar3,0x8980);
  }
  return;
}


/* sub_0800D278 @ 0x0800D278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800D278(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short local_20;
  short local_1e;
  
  uVar1 = *param_2;
  local_1e = 0;
  if (DAT_03004635 != 0) {
    do {
      local_20 = 0;
      if (DAT_03004634 != 0) {
        DAT_0300463a = (short)(uVar1 >> 0x10);
        do {
          iVar2 = 0;
          iVar5 = (local_1e * 2 + (int)local_20) * 0x4b0;
          do {
            iVar4 = *(int *)(((int)*DAT_03000600 * (int)(short)(DAT_0300463a + local_1e) +
                             (int)(short)(((uVar1 & 0xffff) + (int)local_20) * 0x10000 >> 0x10)) * 4
                            + *(int *)(DAT_03000600 + iVar2 * 2 + 0x10));
            if (iVar4 == 0) {
              DAT_030047ec = 0;
              REG_DMA3SAD = 0x30047ec;
              REG_DMA3DAD = iVar5 + iVar2 * 0x12c0 + 0x2000000;
              Ram040000dc = 300;
              DAT_040000de = 0x8500;
            }
            else {
              REG_DMA3SAD = iVar4;
              REG_DMA3DAD = iVar5 + iVar2 * 0x12c0 + 0x2000000;
              Ram040000dc = 300;
              DAT_040000de = 0x8400;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 3);
          local_20 = local_20 + 1;
        } while (local_20 < (short)(ushort)DAT_03004634);
      }
      local_1e = local_1e + 1;
    } while (local_1e < (short)(ushort)DAT_03004635);
  }
  _DAT_03004638 = uVar1;
  uVar1 = sub_08004EF4(DAT_03000600,param_2);
  if ((uVar1 != 0) && (DAT_03004636 != uVar1)) {
    DAT_03004636 = (byte)uVar1;
    uVar3 = sub_080095D0(*(undefined4 *)(*(int *)(DAT_03000600 + 0xe) + (uVar1 & 0xff) * 4 + -4));
    sub_08009626(&REG_DMA3SAD,&DAT_06005680,uVar3,0x8980);
  }
  return;
}


/* sub_0800D3B8 @ 0x0800D3B8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800D3B8(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  short local_68;
  short sStack_66;
  short local_64;
  short sStack_62;
  short local_60;
  short sStack_5e;
  ushort uStack_5c;
  ushort uStack_5a;
  ushort local_58;
  ushort uStack_56;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  ushort uStack_3a;
  int iStack_38;
  uint uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uint uStack_20;
  int iStack_1c;
  int *piStack_18;
  
  if (DAT_03004634 == 1) {
    local_68 = 0;
    local_58 = 0;
    local_60 = 0;
    local_64 = 0;
  }
  else {
    iVar2 = (int)DAT_03000608;
    iVar3 = iVar2 + (iVar2 * 0x1112 >> 0x14) * -0xf0;
    local_68 = (short)(iVar2 * 0x1112 >> 0x14);
    local_58 = (ushort)((uint)(iVar2 << 0x18) >> 0x1b);
    if ((int)_DAT_030005f0 < (int)((int)local_68 + (uint)DAT_03004634)) {
      local_68 = _DAT_030005f0 - (ushort)DAT_03004634;
      local_60 = 0x1e;
      local_64 = 0x1e;
    }
    else {
      local_60 = (short)(iVar3 >> 3);
      local_64 = (short)(iVar3 + 7 >> 3);
    }
  }
  if (DAT_03004635 == 1) {
    sStack_66 = 0;
    uStack_56 = 0;
    sStack_5e = 0;
    sStack_62 = 0;
  }
  else {
    iVar2 = (int)DAT_0300060a;
    iVar3 = iVar2 + (iVar2 * 0x199a >> 0x14) * -0xa0;
    sStack_66 = (short)(iVar2 * 0x199a >> 0x14);
    uStack_56 = (ushort)((uint)(iVar2 << 0x18) >> 0x1b);
    if ((int)DAT_030005f2 < (int)((int)sStack_66 + (uint)DAT_03004635)) {
      sStack_66 = DAT_030005f2 - (ushort)DAT_03004634;
      sStack_5e = 0x14;
      sStack_62 = 0x14;
    }
    else {
      sStack_5e = (short)(iVar3 >> 3);
      sStack_62 = (short)(iVar3 + 7 >> 3);
    }
  }
  piStack_18 = param_1;
  if ((DAT_03004638 != local_68) || (DAT_0300463a != sStack_66)) {
    sub_0800D278(param_1,&local_68);
  }
  uStack_5c = (local_58 + 0x1e) - local_60 & 0x1f;
  uStack_5a = (uStack_56 + 0x14) - sStack_5e & 0x1f;
  if (local_60 != 0x1e) {
    iStack_1c = local_60 * 2;
    puVar1 = (undefined *)(sStack_5e * 0x3c + iStack_1c + 0x2002580);
    iVar2 = (int)(short)local_58 - (int)local_60;
    if (2 < iVar2) {
      uStack_44 = 0x20 - (int)(short)local_58;
      uStack_48 = iVar2 - 2;
    }
    else {
      uStack_44 = 0x1e - (int)local_60;
    }
    uStack_40 = (uint)(2 >= iVar2);
    uStack_3a = uStack_56;
    iVar2 = (int)sStack_5e;
    if (iVar2 < 0x14) {
      uStack_20 = uStack_44 & 0xffff;
      do {
        iStack_24 = (short)uStack_3a * 0x40;
        iStack_4c = iStack_24 + 0x202a5dc;
        iStack_50 = iStack_24 + 0x202ae00;
        puRam000003d4 = puVar1;
        iRam000003d8 = (short)local_58 * 2 + iStack_24 + 0x202b624;
        uRam000003dc = (short)uStack_44;
        if (uStack_40 == 0) {
          puRam000003d4 = puVar1 + uStack_44 * 2;
          iRam000003d8 = iStack_24 + 0x202b624;
          uRam000003dc = (short)uStack_48;
        }
        uRam000003de = 0x8000;
        uStack_3a = uStack_3a + 1 & 0x1f;
        puVar1 = puVar1 + 0x3c;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x14);
    }
    puVar1 = (undefined *)(iStack_1c + 0x2002ee0);
    iVar2 = 0;
    uStack_3a = uStack_5a;
    if (0 < sStack_62) {
      iStack_28 = uStack_44 * 2;
      do {
        iVar3 = (short)uStack_3a * 0x40;
        iStack_4c = iVar3 + 0x202a5dc;
        iStack_50 = iVar3 + 0x202ae00;
        puRam000003d4 = puVar1;
        iRam000003d8 = (short)local_58 * 2 + iVar3 + 0x202b624;
        uRam000003dc = (short)uStack_44;
        if (uStack_40 == 0) {
          puRam000003d4 = puVar1 + iStack_28;
          iRam000003d8 = iVar3 + 0x202b624;
          uRam000003dc = (short)uStack_48;
        }
        uRam000003de = 0x8000;
        uStack_3a = uStack_3a + 1 & 0x1f;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x3c;
      } while (iVar2 < sStack_62);
    }
  }
  if (local_64 != 0) {
    puVar1 = (undefined *)(sStack_5e * 0x3c + 0x2002a30);
    iVar2 = (int)(short)uStack_5c + (int)local_64;
    if (0x20 < iVar2) {
      uStack_44 = 0x20 - (int)(short)uStack_5c;
      uStack_48 = iVar2 - 0x20;
    }
    else {
      uStack_44 = (uint)local_64;
    }
    uStack_40 = (uint)(0x20 >= iVar2);
    uStack_3a = uStack_56;
    iVar2 = (int)sStack_5e;
    if (iVar2 < 0x14) {
      iStack_2c = uStack_44 * 2;
      do {
        iStack_30 = (short)uStack_3a * 0x40;
        iStack_4c = iStack_30 + 0x202a5dc;
        iStack_50 = iStack_30 + 0x202ae00;
        iStack_54 = iStack_30 + 0x202b624;
        iRam000003d8 = (short)uStack_5c * 2 + iStack_54;
        puRam000003d4 = puVar1;
        uRam000003dc = (short)uStack_44;
        if (uStack_40 == 0) {
          puRam000003d4 = puVar1 + iStack_2c;
          iRam000003d8 = iStack_54;
          uRam000003dc = (short)uStack_48;
        }
        uRam000003de = 0x8000;
        uStack_3a = uStack_3a + 1 & 0x1f;
        puVar1 = puVar1 + 0x3c;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x14);
    }
    iVar2 = 0;
    puVar1 = &DAT_02003390;
    uStack_3a = uStack_5a;
    if (0 < sStack_62) {
      uStack_34 = uStack_48 & 0xffff;
      do {
        iStack_38 = (short)uStack_3a * 0x40;
        iStack_4c = iStack_38 + 0x202a5dc;
        iStack_50 = iStack_38 + 0x202ae00;
        iStack_54 = iStack_38 + 0x202b624;
        iRam000003d8 = (short)uStack_5c * 2 + iStack_54;
        puRam000003d4 = puVar1;
        uRam000003dc = (short)uStack_44;
        if (uStack_40 == 0) {
          puRam000003d4 = puVar1 + uStack_44 * 2;
          iRam000003d8 = iStack_54;
          uRam000003dc = (short)uStack_48;
        }
        uRam000003de = 0x8000;
        uStack_3a = uStack_3a + 1 & 0x1f;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x3c;
      } while (iVar2 < sStack_62);
    }
  }
  sub_08008D14(&DAT_02029d94);
  sub_08002556(0,1);
  __call_via_r1(piStack_18,*(int *)(*piStack_18 + 0x20) + *piStack_18);
  sub_08008D8A(&DAT_02029d94);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202addc);
  sub_08008D8A(&DAT_0202b600);
  return;
}


/* sub_0800D966 @ 0x0800D966 */

void sub_0800D966(void)

{
  REG_BG1HOFS = DAT_03000608;
  REG_BG1VOFS = DAT_0300060a;
  REG_BG2HOFS = DAT_03000608;
  REG_BG2VOFS = DAT_0300060a;
  REG_BG3HOFS = DAT_03000608;
  REG_BG3VOFS = DAT_0300060a;
  return;
}


/* sub_0800D97E @ 0x0800D97E */

void sub_0800D97E(void)

{
  sub_08002896();
  return;
}


/* sub_0800D9C4 @ 0x0800D9C4 */

void sub_0800D9C4(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = __call_via_r3(param_2,*(undefined2 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  iVar2 = __call_via_r3(param_2,*(undefined2 *)(param_1 + 6),0,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  if ((iVar1 != 0) && (iVar2 != 0)) {
    local_18 = CONCAT22(*(short *)(iVar2 + 0x22) + *(short *)(param_1 + 10),
                        *(short *)(iVar2 + 0x20) + *(short *)(param_1 + 8));
    local_14 = local_18;
    uVar3 = __call_via_r2(param_2,iVar1,*(int *)(*param_2 + 0x18) + *param_2);
    sub_0800C4C0(iVar1,uVar3,&local_14);
    local_1c = local_14;
    uVar3 = local_1c;
    uVar4 = **(undefined4 **)(iVar1 + 0x1c);
    local_1c._0_2_ = (short)local_14;
    local_20._0_2_ = (short)uVar4;
    local_20._2_2_ = (short)((uint)uVar4 >> 0x10);
    local_1c._2_2_ = (short)((uint)local_14 >> 0x10);
    local_24 = CONCAT22(local_1c._2_2_ + local_20._2_2_,(short)local_1c + (short)local_20);
    local_18 = local_24;
    local_20 = (undefined *)uVar4;
    local_1c = uVar3;
    sub_0800507A(DAT_03000600,&local_1c,1,0);
    local_20 = &_0800F214;
    sub_080097F8(&local_20);
  }
  return;
}


/* sub_0800DA6C @ 0x0800DA6C */

bool sub_0800DA6C(void)

{
  sub_080026F8();
  return DAT_030043a0 == 0;
}


/* sub_0800DA84 @ 0x0800DA84 */

void sub_0800DA84(void)

{
  return;
}


/* sub_0800DA86 @ 0x0800DA86 */

void sub_0800DA86(void)

{
  DAT_03003b60 = 0;
  sub_08009744(&DAT_030005e0);
  return;
}


/* sub_0800DAA0 @ 0x0800DAA0 */

void sub_0800DAA0(void)

{
  return;
}


/* sub_0800DAA2 @ 0x0800DAA2 */

void sub_0800DAA2(int param_1)

{
  sub_0800A5F6(&gUnknown_08591F3C + (uint)*(byte *)(param_1 + 4) * 0xc);
  return;
}


/* sub_0800DABC @ 0x0800DABC */

undefined4 sub_0800DABC(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954();
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_0800DADC @ 0x0800DADC */

void sub_0800DADC(void)

{
  return;
}


/* sub_0800DADE @ 0x0800DADE */

undefined4 sub_0800DADE(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (((param_2 == 2) && (*(byte *)(param_1 + 6) == param_3)) &&
     (iVar1 = sub_08000954(param_1), iVar1 == 0)) {
    sub_08005526(*(undefined1 *)(param_1 + 4));
    return 1;
  }
  return 0;
}


/* sub_0800DB08 @ 0x0800DB08 */

void sub_0800DB08(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 4) == DAT_030005fc) &&
     (iVar1 = sub_08002810(*(undefined1 *)(param_1 + 5)), iVar1 != 0)) {
    if (*(char *)(param_1 + 5) == '4') {
      DAT_030007e0 = (uint)(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)];
    }
    else {
      *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 6);
      iVar2 = *(int *)(iVar1 + 0x3c);
      if (*(short *)(iVar2 + 0x9c) == 0) {
        sub_080062FC(&DAT_03003b48,iVar2);
      }
      else if (*(char *)(iVar2 + 0xb) == '\x02') {
        sub_080062FC(&DAT_03003b54,iVar2);
      }
      else {
        sub_080062FC(&DAT_030047f0,iVar2);
      }
      sub_08006D90(iVar2,2,(&gUnknown_0815A69C)[*(byte *)(iVar1 + 0x15)]);
      sub_080062C4(&DAT_030047f0,iVar2,iVar1);
      sub_080085A0(iVar2,iVar1 + 0x20);
    }
    sub_080024B8(iVar1,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)]],0,0,
                 param_4);
  }
  return;
}


/* sub_0800DBC0 @ 0x0800DBC0 */

void sub_0800DBC0(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_0800DBCC @ 0x0800DBCC */

void sub_0800DBCC(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x40) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
  }
  return;
}


/* sub_0800DBDC @ 0x0800DBDC */

void sub_0800DBDC(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_0800DBE8 @ 0x0800DBE8 */

void sub_0800DBE8(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x50) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
  }
  return;
}


/* sub_0800DBF8 @ 0x0800DBF8 */

void sub_0800DBF8(void)

{
  sub_0800AB1A();
  REG_IME = 0;
  software_interrupt(0);
  return;
}


/* sub_0800DC0C @ 0x0800DC0C */

void sub_0800DC0C(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2,
                        param_4);
  sub_080024B8(iVar1,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 5)]],0,0);
  *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 5);
  return;
}


/* sub_0800DC48 @ 0x0800DC48 */

void sub_0800DC48(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  if ((iVar1 != 0) &&
     (*(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0x28) + (uint)*(byte *)(param_1 + 5) * 0x10) != 0))
  {
    if (*(int *)(*(int *)(iVar1 + 0x18) + (uint)*(byte *)(param_1 + 5) * 0x14) != 0) {
      sub_08002466();
    }
  }
  return;
}


/* sub_0800DC82 @ 0x0800DC82 */

undefined4 sub_0800DC82(undefined4 param_1)

{
  return param_1;
}


/* sub_0800DC84 @ 0x0800DC84 */

void sub_0800DC84(void)

{
  return;
}


/* sub_0800DC86 @ 0x0800DC86 */

undefined4 sub_0800DC86(void)

{
  return 1;
}


/* sub_0800DC8A @ 0x0800DC8A */

void sub_0800DC8A(int param_1,int *param_2)

{
  int iVar1;
  undefined *local_c;
  
  iVar1 = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  *(undefined1 *)(iVar1 + 0x13) = *(undefined1 *)(param_1 + 5);
  local_c = &_0800F274;
  sub_080097F8(&local_c);
  return;
}


/* sub_0800DCB8 @ 0x0800DCB8 */

void sub_0800DCB8(int param_1)

{
  if (*(char *)(param_1 + 4) == DAT_030005fc) {
    sub_080060E6(param_1 + 8);
  }
  return;
}


/* sub_0800DCD4 @ 0x0800DCD4 */

undefined4 sub_0800DCD4(int param_1)

{
  sub_080060A0();
  sub_0800C42E(&gUnknown_0815A778 + (uint)*(byte *)(param_1 + 0xd) * 8);
  return 0;
}


/* sub_0800DCF0 @ 0x0800DCF0 */

void sub_0800DCF0(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  REG_DISPCNT = 0x80;
  sub_080098F8();
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,0x6000000,1,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202b600,&DAT_0600f800,0x6000000,0,&gUnknown_08142380);
  DAT_05000000 = 0;
  DAT_05000004 = 0;
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    (&DAT_05000006)[iVar3] = ((short)iVar3 * -2 + 0x1f) * 0x421;
    iVar3 = iVar2;
  } while (iVar2 < 8);
  sub_08009680(&REG_DMA3SAD,0x6000000,&DAT_02020202,0x9600);
  sub_080092A4(&DAT_0202b600);
  sub_08008D8A(&DAT_0202b600);
  REG_BG0CNT = 0x1c0c;
  iVar3 = 0;
  REG_BG2CNT = 0x1e0c;
  REG_BG3CNT = 0x1f80;
  REG_DISPCNT = 0xd20;
  do {
    uVar1 = sub_0800A6F4();
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(&DAT_02035824 + iVar2) = uVar1;
  } while (iVar3 < 400);
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    (&DAT_0203582a)[iVar3 * 4] = 0;
    iVar3 = iVar2;
  } while (iVar2 < 100);
  sub_08009680(&REG_DMA3SAD,&DAT_0202c224,&DAT_02020202,0x9600);
  return;
}


/* sub_0800DDC4 @ 0x0800DDC4 */

void sub_0800DDC4(void)

{
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  return;
}


/* sub_0800DDE0 @ 0x0800DDE0 */

void sub_0800DDE0(int *param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  int iVar7;
  
  psVar6 = (short *)&DAT_02035824;
  iVar7 = 0;
  do {
    *(undefined1 *)((int)&DAT_0202c224 + (uint)(ushort)psVar6[3]) = 2;
    sVar1 = psVar6[2];
    if (sVar1 == 0) {
      psVar6[3] = 0;
    }
    else {
      iVar2 = sub_0800E640(sVar1,0x100000);
      uVar4 = iVar2 * *psVar6 * 0x78 >> 0x14;
      iVar2 = iVar2 * psVar6[1] * 0x50 >> 0x14;
      uVar3 = iVar2 + 0x50;
      uVar5 = uVar4 + 0x78;
      if ((uVar5 < 0xf0) && (uVar3 < 0xa0)) {
        iVar2 = ((uint)(iVar2 << 0x1d) >> 0x1a) +
                (uVar3 & 0xfffffff8) * 0xf0 + (uVar4 & 7) + ((int)uVar5 >> 3) * 0x40;
        *(byte *)((int)&DAT_0202c224 + iVar2) = (byte)((ushort)sVar1 >> 0xd) + 3;
        psVar6[3] = (short)iVar2;
      }
    }
    iVar7 = iVar7 + 1;
    psVar6[2] = psVar6[2] + -0x200;
    psVar6 = psVar6 + 4;
  } while (iVar7 < 100);
  sub_08009626(&REG_DMA3SAD,0x6000000,&DAT_0202c224,0x9600);
  __call_via_r1(param_1,*(int *)(*param_1 + 0x18) + *param_1);
  return;
}


/* sub_0800DECC @ 0x0800DECC */

void sub_0800DECC(int param_1)

{
  sub_0800DCF0();
  DAT_02029d96 = 3;
  DAT_02029d98 = 4;
  DAT_02029d9a = 0x1b;
  DAT_02029d9c = 8;
  sub_0800930A(&DAT_02029d94,*(undefined4 *)(param_1 + 4));
  return;
}


/* sub_0800DEF2 @ 0x0800DEF2 */

void sub_0800DEF2(void)

{
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_0800DEFC @ 0x0800DEFC */

bool sub_0800DEFC(void)

{
  sub_08009328(&DAT_02029d94,0);
  return DAT_02029da8 == 0;
}


/* sub_0800DF14 @ 0x0800DF14 */

void sub_0800DF14(int param_1)

{
  undefined *local_c;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(param_1 + 4);
  local_c = &_0800F1F8;
  sub_080097F8(&local_c);
  return;
}


/* sub_0800DF3C @ 0x0800DF3C */

int sub_0800DF3C(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  sub_080026F8();
  sub_08002328(auStack_10,*(undefined4 *)(param_1 + 4));
  iVar1 = sub_08002134(auStack_10);
  return 1 - iVar1;
}


/* sub_0800DF5E @ 0x0800DF5E */

void sub_0800DF5E(int param_1)

{
  undefined4 uVar1;
  
  REG_DISPCNT = 0x1f04;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = 0x100;
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = 0x100;
  REG_BLDCNT = 0x84;
  *(undefined1 *)(param_1 + 4) = 0;
  REG_BLDY = 0x10;
  uVar1 = sub_080095DC(&gUnknown_081C7B50);
  REG_DMA3SAD = 0x819badc;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = 0x6000000;
  Ram040000dc = 0x4b00;
  DAT_040000de = 0x8000;
  DAT_03003b60 = 0;
  return;
}


/* sub_0800DF60 @ 0x0800DF60 */

void sub_0800DF60(int param_1)

{
  undefined4 uVar1;
  
  REG_DISPCNT = 0x1f04;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = 0x100;
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = 0x100;
  REG_BLDCNT = 0x84;
  *(undefined1 *)(param_1 + 4) = 0;
  REG_BLDY = 0x10;
  uVar1 = sub_080095DC(&gUnknown_081C7B50);
  REG_DMA3SAD = 0x819badc;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = 0x6000000;
  Ram040000dc = 0x4b00;
  DAT_040000de = 0x8000;
  DAT_03003b60 = 0;
  return;
}


/* sub_0800DFC0 @ 0x0800DFC0 */

void sub_0800DFC0(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 4);
  if (uVar1 < 0x20) {
    REG_BLDY = (char)(uVar1 * -0x8000 + 0x100000 >> 0x10);
    return;
  }
  if (uVar1 < 0xd4) {
    REG_BLDY = 0;
    return;
  }
  REG_BLDY = (char)(uVar1 * 0x8000 + -0x6a0000 >> 0x10);
  return;
}


/* sub_0800DFEE @ 0x0800DFEE */

void sub_0800DFEE(void)

{
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  return;
}


/* sub_0800E00A @ 0x0800E00A */

undefined4 sub_0800E00A(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 4);
  *(byte *)(param_1 + 4) = bVar1 + 1;
  if (0xf3 < bVar1) {
    DAT_03003d18 = 1;
    sub_0800A5F6(&gUnknown_08591FF0);
    sub_08009744(0x300000c);
  }
  return 0;
}


/* sub_0800E058 @ 0x0800E058 */

void sub_0800E058(void)

{
  sub_08001174();
  return;
}


/* sub_0800E060 @ 0x0800E060 */

undefined4 sub_0800E060(void)

{
  return 1;
}


/* sub_0800E064 @ 0x0800E064 */

void sub_0800E064(void)

{
  undefined *local_8 [2];
  
  local_8[0] = &_0800F2D4;
  sub_080097F8(local_8);
  return;
}


/* sub_0800E078 @ 0x0800E078 */

void sub_0800E078(int param_1)

{
  sub_0800A5F6(&gUnknown_08591F3C + (uint)*(byte *)(param_1 + 4) * 0xc);
  return;
}


/* sub_0800E090 @ 0x0800E090 */

undefined4 sub_0800E090(short param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 4) {
    DAT_03004810 = &gUnknown_087A639C;
  }
  else if (param_1 == 0x40) {
    DAT_03004810 = &gUnknown_087A63A8;
  }
  else {
    DAT_03004810 = &gUnknown_087A639C;
    uVar1 = 1;
  }
  return uVar1;
}


/* sub_0800E0D4 @ 0x0800E0D4 */

void sub_0800E0D4(void)

{
  if ((DAT_03004646 != 0) && (DAT_03004646 = DAT_03004646 + -1, DAT_03004646 == 0)) {
    DAT_03004648 = 1;
  }
  return;
}


/* sub_0800E0F8 @ 0x0800E0F8 */

bool sub_0800E0F8(byte param_1,undefined4 *param_2)

{
  if (3 >= param_1) {
    DAT_0300464c = &REG_TM0CNT + (uint)param_1 * 2;
    DAT_03004644 = param_1;
    *param_2 = sub_0800E0D4;
  }
  return 3 < param_1;
}


/* sub_0800E130 @ 0x0800E130 */

undefined4 sub_0800E130(undefined2 *param_1)

{
  ushort uVar1;
  undefined4 in_lr;
  
  DAT_03004650 = REG_IME;
  REG_IME = 0;
  DAT_0300464c[1] = 0;
  REG_IF = (short)(8 << DAT_03004644);
  uVar1 = REG_IE;
  REG_IE = uVar1 | (ushort)(8 << DAT_03004644);
  DAT_03004648 = 0;
  DAT_03004646 = *param_1;
  *DAT_0300464c = param_1[1];
  DAT_0300464c[1] = param_1[2];
  REG_IME = 1;
  return in_lr;
}


/* sub_0800E1B8 @ 0x0800E1B8 */

void sub_0800E1B8(void)

{
  ushort uVar1;
  
  REG_IME = 0;
  *DAT_0300464c = 0;
  DAT_0300464c[1] = 0;
  uVar1 = REG_IE;
  REG_IE = uVar1 & ~(ushort)(8 << DAT_03004644);
  REG_IME = DAT_03004650;
  return;
}


/* sub_0800E1FC @ 0x0800E1FC */

undefined4 sub_0800E1FC(undefined4 param_1,undefined4 param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 in_lr;
  
  uVar2 = REG_IME;
  REG_IME = 0;
  uVar1 = REG_WAITCNT;
  REG_WAITCNT = uVar1 & 0xf8ff | *(ushort *)(DAT_03004810 + 6);
  REG_DMA3SAD = param_1;
  REG_DMA3DAD = param_2;
  Ram040000dc = param_3 & 0xffff | 0x80000000;
  uVar1 = DAT_040000de;
  while ((uVar1 & 0x8000) != 0) {
    uVar1 = DAT_040000de;
  }
  REG_IME = uVar2;
  return in_lr;
}


/* sub_0800E27C @ 0x0800E27C */

void sub_0800E27C(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 auStack_98 [2];
  ushort auStack_96 [67];
  
  param_1 = param_1 & 0xffff;
  if (param_1 < *(ushort *)(DAT_03004810 + 4)) {
    puVar5 = auStack_96 + *(byte *)(DAT_03004810 + 8);
    bVar1 = 0;
    if (*(byte *)(DAT_03004810 + 8) != 0) {
      do {
        *puVar5 = (ushort)param_1;
        puVar5 = puVar5 + -1;
        param_1 = param_1 >> 1;
        bVar1 = bVar1 + 1;
      } while (bVar1 < *(byte *)(DAT_03004810 + 8));
    }
    *puVar5 = 1;
    puVar5[-1] = 1;
    sub_0800E1FC(auStack_98,&DAT_0d000000,*(byte *)(DAT_03004810 + 8) + 3);
    sub_0800E1FC(&DAT_0d000000,auStack_98,0x44);
    puVar5 = auStack_96 + 3;
    puVar6 = (undefined2 *)(param_2 + 6);
    bVar1 = 0;
    do {
      uVar4 = 0;
      bVar2 = 0;
      do {
        uVar4 = (uVar4 << 0x11) >> 0x10 | *puVar5 & 1;
        puVar5 = puVar5 + 1;
        bVar2 = bVar2 + 1;
      } while (bVar2 < 0x10);
      *puVar6 = (short)uVar4;
      puVar6 = puVar6 + -1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80ff;
  }
                    /* WARNING: Could not recover jumptable at 0x0800e324. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3);
  return;
}


/* sub_0800E32C @ 0x0800E32C */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800E32C(uint param_1,ushort *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 auStack_b0 [130];
  undefined2 auStack_2e [17];
  
  param_1 = param_1 & 0xffff;
  if (param_1 < *(ushort *)(DAT_03004810 + 4)) {
    bVar2 = *(byte *)(DAT_03004810 + 8);
    auStack_2e[bVar2 + 1] = 0;
    puVar5 = auStack_2e + bVar2;
    bVar2 = 0;
    do {
      uVar4 = (uint)*param_2;
      param_2 = param_2 + 1;
      bVar1 = 0;
      do {
        *puVar5 = (short)uVar4;
        puVar5 = puVar5 + -1;
        uVar4 = uVar4 >> 1;
        bVar1 = bVar1 + 1;
      } while (bVar1 < 0x10);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 4);
    for (bVar2 = 0; bVar2 < *(byte *)(DAT_03004810 + 8); bVar2 = bVar2 + 1) {
      *puVar5 = (short)param_1;
      puVar5 = puVar5 + -1;
      param_1 = param_1 >> 1;
    }
    *puVar5 = 0;
    puVar5[-1] = 1;
    sub_0800E1FC(auStack_b0,&DAT_0d000000,*(byte *)(DAT_03004810 + 8) + 0x43);
    sub_0800E130(&gUnknown_087A63B4);
    uVar3 = 0;
    do {
      if ((_DAT_0d000000 & 1) != 0) goto _0800E3EA;
    } while (DAT_03004648 == '\0');
    if ((_DAT_0d000000 & 1) == 0) {
      uVar3 = 0xc001;
    }
_0800E3EA:
    sub_0800E1B8();
  }
  else {
    uVar3 = 0x80ff;
  }
                    /* WARNING: Could not recover jumptable at 0x0800e3f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3);
  return;
}


/* sub_0800E408 @ 0x0800E408 */

void sub_0800E408(ushort param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  short *psVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  short asStack_14 [4];
  
  psVar4 = asStack_14;
  uVar5 = 0;
  if (param_1 < *(ushort *)(DAT_03004810 + 4)) {
    sub_0800E27C(param_1,asStack_14);
    bVar3 = 0;
    do {
      sVar1 = *param_2;
      sVar2 = *psVar4;
      psVar4 = psVar4 + 1;
      param_2 = param_2 + 1;
      if (sVar1 != sVar2) {
        uVar5 = 0x8000;
        break;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 4);
  }
  else {
    uVar5 = 0x80ff;
  }
                    /* WARNING: Could not recover jumptable at 0x0800e45c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar5);
  return;
}


/* sub_0800E45E @ 0x0800E45E */

void sub_0800E45E(undefined2 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
    param_3 = sub_0800E32C(param_1,param_2);
    param_3 = param_3 & 0xffff;
    if (param_3 == 0) {
      param_3 = sub_0800E408(param_1,param_2);
      param_3 = param_3 & 0xffff;
      if (param_3 == 0) break;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0800e49c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_3);
  return;
}


/* sub_0800E460 @ 0x0800E460 */

void sub_0800E460(undefined2 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
    param_3 = sub_0800E32C(param_1,param_2);
    param_3 = param_3 & 0xffff;
    if (param_3 == 0) {
      param_3 = sub_0800E408(param_1,param_2);
      param_3 = param_3 & 0xffff;
      if (param_3 == 0) break;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0800e49c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_3);
  return;
}


/* sub_0800E49E @ 0x0800E49E */

void sub_0800E49E(code *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x0800e4a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r0 @ 0x0800E4A0 */

void __call_via_r0(code *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x0800e4a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r1 @ 0x0800E4A2 */

void __call_via_r1(undefined4 param_1,code *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x0800e4a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r2 @ 0x0800E4A4 */

void __call_via_r2(undefined4 param_1,undefined4 param_2,code *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x0800e4a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r3 @ 0x0800E4A6 */

void __call_via_r3(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0800e4a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r4 @ 0x0800E4A8 */

void __call_via_r4(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0800e4a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r5 @ 0x0800E4AA */

void __call_via_r5(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0800e4aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r6 @ 0x0800E4AC */

void __call_via_r6(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0800e4ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* __call_via_r7 @ 0x0800E4AE */

void __call_via_r7(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0800e4ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* sub_0800E4B0 @ 0x0800E4B0 */

void sub_0800E4B0(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)&DAT_0800ee54;
  do {
    __call_via_r0(pcVar1 + *(int *)pcVar1);
    pcVar1 = pcVar1 + 4;
  } while (pcVar1 != sub_0800EEC0);
  return;
}


/* sub_0800E4DC @ 0x0800E4DC */

void sub_0800E4DC(void)

{
  sub_0800E778();
  return;
}


/* sub_0800E4E8 @ 0x0800E4E8 */

void sub_0800E4E8(void)

{
  sub_0800E7A4(0xc);
  return;
}


/* sub_0800E4F6 @ 0x0800E4F6 */

undefined8 sub_0800E4F6(byte *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  bVar9 = 0x1f < param_3;
  param_3 = param_3 - 0x20;
  if (bVar9) {
    do {
      if (bVar9) {
        uVar5 = *(undefined4 *)(param_2 + 4);
        uVar6 = *(undefined4 *)(param_2 + 8);
        uVar8 = *(undefined4 *)(param_2 + 0xc);
        *(undefined4 *)param_1 = *(undefined4 *)param_2;
        *(undefined4 *)(param_1 + 4) = uVar5;
        *(undefined4 *)(param_1 + 8) = uVar6;
        *(undefined4 *)(param_1 + 0xc) = uVar8;
        param_4 = *(undefined4 *)(param_2 + 0x10);
        uVar5 = *(undefined4 *)(param_2 + 0x14);
        uVar6 = *(undefined4 *)(param_2 + 0x18);
        uVar8 = *(undefined4 *)(param_2 + 0x1c);
        param_2 = param_2 + 0x20;
        *(undefined4 *)(param_1 + 0x10) = param_4;
        *(undefined4 *)(param_1 + 0x14) = uVar5;
        *(undefined4 *)(param_1 + 0x18) = uVar6;
        *(undefined4 *)(param_1 + 0x1c) = uVar8;
        param_1 = param_1 + 0x20;
        bVar9 = 0x1f < param_3;
        param_3 = param_3 - 0x20;
      }
    } while (bVar9);
  }
  if ((bool)((byte)(param_3 >> 4) & 1)) {
    param_4 = *(undefined4 *)param_2;
    uVar5 = *(undefined4 *)(param_2 + 4);
    uVar6 = *(undefined4 *)(param_2 + 8);
    uVar8 = *(undefined4 *)(param_2 + 0xc);
    param_2 = param_2 + 0x10;
    *(undefined4 *)param_1 = param_4;
    *(undefined4 *)(param_1 + 4) = uVar5;
    *(undefined4 *)(param_1 + 8) = uVar6;
    *(undefined4 *)(param_1 + 0xc) = uVar8;
    param_1 = param_1 + 0x10;
  }
  if ((int)(param_3 << 0x1c) < 0) {
    param_4 = *(undefined4 *)param_2;
    uVar5 = *(undefined4 *)(param_2 + 4);
    param_2 = param_2 + 8;
    *(undefined4 *)param_1 = param_4;
    *(undefined4 *)(param_1 + 4) = uVar5;
    param_1 = param_1 + 8;
  }
  uVar7 = param_3 << 0x1e;
  pbVar2 = param_1;
  pbVar3 = param_2;
  if ((bool)((byte)(param_3 >> 2) & 1)) {
    pbVar3 = param_2 + 4;
    param_4 = *(undefined4 *)param_2;
    pbVar2 = param_1 + 4;
    *(undefined4 *)param_1 = param_4;
  }
  bVar1 = (byte)param_4;
  if (uVar7 == 0) {
    return CONCAT44(pbVar3,pbVar2);
  }
  bVar10 = (bool)((byte)(param_3 >> 1) & 1);
  param_3 = param_3 << 0x1f;
  bVar9 = (int)param_3 < 0;
  pbVar4 = pbVar3;
  if (bVar9) {
    pbVar4 = pbVar3 + 1;
    param_3 = (uint)*pbVar3;
  }
  if (bVar10) {
    pbVar3 = pbVar4 + 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 2;
    uVar7 = (uint)*pbVar3;
  }
  pbVar3 = pbVar2;
  if (bVar9) {
    pbVar3 = pbVar2 + 1;
    *pbVar2 = (byte)param_3;
  }
  if (bVar10) {
    pbVar2 = pbVar3 + 1;
    *pbVar3 = bVar1;
    pbVar3 = pbVar3 + 2;
    *pbVar2 = (byte)uVar7;
  }
  return CONCAT44(pbVar4,pbVar3);
}


/* sub_0800E4F8 @ 0x0800E4F8 */

undefined8 sub_0800E4F8(byte *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  bVar9 = 0x1f < param_3;
  param_3 = param_3 - 0x20;
  if (bVar9) {
    do {
      if (bVar9) {
        uVar5 = *(undefined4 *)(param_2 + 4);
        uVar6 = *(undefined4 *)(param_2 + 8);
        uVar8 = *(undefined4 *)(param_2 + 0xc);
        *(undefined4 *)param_1 = *(undefined4 *)param_2;
        *(undefined4 *)(param_1 + 4) = uVar5;
        *(undefined4 *)(param_1 + 8) = uVar6;
        *(undefined4 *)(param_1 + 0xc) = uVar8;
        param_4 = *(undefined4 *)(param_2 + 0x10);
        uVar5 = *(undefined4 *)(param_2 + 0x14);
        uVar6 = *(undefined4 *)(param_2 + 0x18);
        uVar8 = *(undefined4 *)(param_2 + 0x1c);
        param_2 = param_2 + 0x20;
        *(undefined4 *)(param_1 + 0x10) = param_4;
        *(undefined4 *)(param_1 + 0x14) = uVar5;
        *(undefined4 *)(param_1 + 0x18) = uVar6;
        *(undefined4 *)(param_1 + 0x1c) = uVar8;
        param_1 = param_1 + 0x20;
        bVar9 = 0x1f < param_3;
        param_3 = param_3 - 0x20;
      }
    } while (bVar9);
  }
  if ((bool)((byte)(param_3 >> 4) & 1)) {
    param_4 = *(undefined4 *)param_2;
    uVar5 = *(undefined4 *)(param_2 + 4);
    uVar6 = *(undefined4 *)(param_2 + 8);
    uVar8 = *(undefined4 *)(param_2 + 0xc);
    param_2 = param_2 + 0x10;
    *(undefined4 *)param_1 = param_4;
    *(undefined4 *)(param_1 + 4) = uVar5;
    *(undefined4 *)(param_1 + 8) = uVar6;
    *(undefined4 *)(param_1 + 0xc) = uVar8;
    param_1 = param_1 + 0x10;
  }
  if ((int)(param_3 << 0x1c) < 0) {
    param_4 = *(undefined4 *)param_2;
    uVar5 = *(undefined4 *)(param_2 + 4);
    param_2 = param_2 + 8;
    *(undefined4 *)param_1 = param_4;
    *(undefined4 *)(param_1 + 4) = uVar5;
    param_1 = param_1 + 8;
  }
  uVar7 = param_3 << 0x1e;
  pbVar2 = param_1;
  pbVar3 = param_2;
  if ((bool)((byte)(param_3 >> 2) & 1)) {
    pbVar3 = param_2 + 4;
    param_4 = *(undefined4 *)param_2;
    pbVar2 = param_1 + 4;
    *(undefined4 *)param_1 = param_4;
  }
  bVar1 = (byte)param_4;
  if (uVar7 == 0) {
    return CONCAT44(pbVar3,pbVar2);
  }
  bVar10 = (bool)((byte)(param_3 >> 1) & 1);
  param_3 = param_3 << 0x1f;
  bVar9 = (int)param_3 < 0;
  pbVar4 = pbVar3;
  if (bVar9) {
    pbVar4 = pbVar3 + 1;
    param_3 = (uint)*pbVar3;
  }
  if (bVar10) {
    pbVar3 = pbVar4 + 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 2;
    uVar7 = (uint)*pbVar3;
  }
  pbVar3 = pbVar2;
  if (bVar9) {
    pbVar3 = pbVar2 + 1;
    *pbVar2 = (byte)param_3;
  }
  if (bVar10) {
    pbVar2 = pbVar3 + 1;
    *pbVar3 = bVar1;
    pbVar3 = pbVar3 + 2;
    *pbVar2 = (byte)uVar7;
  }
  return CONCAT44(pbVar4,pbVar3);
}


/* sub_0800E4FC @ 0x0800E4FC */

undefined8 sub_0800E4FC(byte *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  bVar9 = 0x1f < param_3;
  param_3 = param_3 - 0x20;
  if (bVar9) {
    do {
      if (bVar9) {
        uVar5 = *(undefined4 *)(param_2 + 4);
        uVar6 = *(undefined4 *)(param_2 + 8);
        uVar8 = *(undefined4 *)(param_2 + 0xc);
        *(undefined4 *)param_1 = *(undefined4 *)param_2;
        *(undefined4 *)(param_1 + 4) = uVar5;
        *(undefined4 *)(param_1 + 8) = uVar6;
        *(undefined4 *)(param_1 + 0xc) = uVar8;
        param_4 = *(undefined4 *)(param_2 + 0x10);
        uVar5 = *(undefined4 *)(param_2 + 0x14);
        uVar6 = *(undefined4 *)(param_2 + 0x18);
        uVar8 = *(undefined4 *)(param_2 + 0x1c);
        param_2 = param_2 + 0x20;
        *(undefined4 *)(param_1 + 0x10) = param_4;
        *(undefined4 *)(param_1 + 0x14) = uVar5;
        *(undefined4 *)(param_1 + 0x18) = uVar6;
        *(undefined4 *)(param_1 + 0x1c) = uVar8;
        param_1 = param_1 + 0x20;
        bVar9 = 0x1f < param_3;
        param_3 = param_3 - 0x20;
      }
    } while (bVar9);
  }
  if ((bool)((byte)(param_3 >> 4) & 1)) {
    param_4 = *(undefined4 *)param_2;
    uVar5 = *(undefined4 *)(param_2 + 4);
    uVar6 = *(undefined4 *)(param_2 + 8);
    uVar8 = *(undefined4 *)(param_2 + 0xc);
    param_2 = param_2 + 0x10;
    *(undefined4 *)param_1 = param_4;
    *(undefined4 *)(param_1 + 4) = uVar5;
    *(undefined4 *)(param_1 + 8) = uVar6;
    *(undefined4 *)(param_1 + 0xc) = uVar8;
    param_1 = param_1 + 0x10;
  }
  if ((int)(param_3 << 0x1c) < 0) {
    param_4 = *(undefined4 *)param_2;
    uVar5 = *(undefined4 *)(param_2 + 4);
    param_2 = param_2 + 8;
    *(undefined4 *)param_1 = param_4;
    *(undefined4 *)(param_1 + 4) = uVar5;
    param_1 = param_1 + 8;
  }
  uVar7 = param_3 << 0x1e;
  pbVar2 = param_1;
  pbVar3 = param_2;
  if ((bool)((byte)(param_3 >> 2) & 1)) {
    pbVar3 = param_2 + 4;
    param_4 = *(undefined4 *)param_2;
    pbVar2 = param_1 + 4;
    *(undefined4 *)param_1 = param_4;
  }
  bVar1 = (byte)param_4;
  if (uVar7 != 0) {
    bVar10 = (bool)((byte)(param_3 >> 1) & 1);
    param_3 = param_3 << 0x1f;
    bVar9 = (int)param_3 < 0;
    pbVar4 = pbVar3;
    if (bVar9) {
      pbVar4 = pbVar3 + 1;
      param_3 = (uint)*pbVar3;
    }
    if (bVar10) {
      pbVar3 = pbVar4 + 1;
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 2;
      uVar7 = (uint)*pbVar3;
    }
    pbVar3 = pbVar2;
    if (bVar9) {
      pbVar3 = pbVar2 + 1;
      *pbVar2 = (byte)param_3;
    }
    if (bVar10) {
      pbVar2 = pbVar3 + 1;
      *pbVar3 = bVar1;
      pbVar3 = pbVar3 + 2;
      *pbVar2 = (byte)uVar7;
    }
    return CONCAT44(pbVar4,pbVar3);
  }
  return CONCAT44(pbVar3,pbVar2);
}


/* __16__rt_sdiv @ 0x0800E568 */

ulonglong __16__rt_sdiv(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  ulonglong uVar8;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar3 = uVar2 ^ (int)param_2 >> 0x20;
  if (SUB41(param_2 >> 0x1f,0)) {
    param_2 = -param_2;
  }
  uVar1 = param_1;
  if (param_2 >> 3 < param_1) goto _0800E608;
  if (param_2 >> 8 < param_1) goto _0800E5CC;
  uVar1 = param_1 << 8;
  uVar2 = 0xff000000;
  if (param_2 >> 4 < uVar1) goto _0800E5FC;
  if (param_2 >> 8 < uVar1) goto _0800E5CC;
  uVar1 = param_1 << 0x10;
  uVar2 = 0xffff0000;
  if (uVar1 <= param_2 >> 8) {
    uVar1 = param_1 << 0x18;
    uVar2 = 0xffffff00;
  }
  if (param_2 >> 4 < uVar1) goto _0800E5FC;
  bVar4 = uVar1 == 0;
  if (!bVar4) {
    do {
      if (bVar4) {
        uVar1 = uVar1 >> 8;
      }
_0800E5CC:
      bVar4 = uVar1 <= param_2 >> 7;
      if (bVar4) {
        param_2 = param_2 + uVar1 * -0x80;
      }
      bVar5 = uVar1 <= param_2 >> 6;
      if (bVar5) {
        param_2 = param_2 + uVar1 * -0x40;
      }
      bVar6 = uVar1 <= param_2 >> 5;
      if (bVar6) {
        param_2 = param_2 + uVar1 * -0x20;
      }
      bVar7 = uVar1 <= param_2 >> 4;
      if (bVar7) {
        param_2 = param_2 + uVar1 * -0x10;
      }
      uVar2 = (((uVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6) * 2 + (uint)bVar7;
_0800E5FC:
      bVar4 = uVar1 <= param_2 >> 3;
      if (bVar4) {
        param_2 = param_2 + uVar1 * -8;
      }
      uVar2 = uVar2 * 2 + (uint)bVar4;
_0800E608:
      bVar4 = uVar1 <= param_2 >> 2;
      if (bVar4) {
        param_2 = param_2 + uVar1 * -4;
      }
      bVar5 = uVar1 <= param_2 >> 1;
      if (bVar5) {
        param_2 = param_2 + uVar1 * -2;
      }
      uVar2 = (uVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5;
      bVar5 = uVar1 <= param_2;
      if (bVar5) {
        param_2 = param_2 - uVar1;
      }
      bVar4 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar5);
      uVar2 = uVar2 * 2 + (uint)bVar5;
    } while (bVar4);
    uVar1 = (int)uVar3 >> 0x1f;
    if ((bool)((byte)(uVar3 >> 0x1e) & 1)) {
      param_2 = -param_2;
    }
    return CONCAT44(param_2,(uVar2 ^ uVar1) - uVar1);
  }
  uVar8 = sub_0800EEC0(2,2);
  if ((int)uVar8 == 0) {
    return uVar8 & 0xffffffff00000000;
  }
  uVar8 = sub_0800E9A0();
  return uVar8;
}


/* __rt_sdiv @ 0x0800E56C */

ulonglong __rt_sdiv(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  ulonglong uVar8;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar3 = uVar2 ^ (int)param_2 >> 0x20;
  if (SUB41(param_2 >> 0x1f,0)) {
    param_2 = -param_2;
  }
  uVar1 = param_1;
  if (param_2 >> 3 < param_1) goto _0800E608;
  if (param_2 >> 8 < param_1) goto _0800E5CC;
  uVar1 = param_1 << 8;
  uVar2 = 0xff000000;
  if (param_2 >> 4 < uVar1) goto _0800E5FC;
  if (param_2 >> 8 < uVar1) goto _0800E5CC;
  uVar1 = param_1 << 0x10;
  uVar2 = 0xffff0000;
  if (uVar1 <= param_2 >> 8) {
    uVar1 = param_1 << 0x18;
    uVar2 = 0xffffff00;
  }
  if (param_2 >> 4 < uVar1) goto _0800E5FC;
  bVar4 = uVar1 == 0;
  if (bVar4) {
    uVar8 = sub_0800EEC0(2,2);
    if ((int)uVar8 != 0) {
      uVar8 = sub_0800E9A0();
      return uVar8;
    }
    return uVar8 & 0xffffffff00000000;
  }
  do {
    if (bVar4) {
      uVar1 = uVar1 >> 8;
    }
_0800E5CC:
    bVar4 = uVar1 <= param_2 >> 7;
    if (bVar4) {
      param_2 = param_2 + uVar1 * -0x80;
    }
    bVar5 = uVar1 <= param_2 >> 6;
    if (bVar5) {
      param_2 = param_2 + uVar1 * -0x40;
    }
    bVar6 = uVar1 <= param_2 >> 5;
    if (bVar6) {
      param_2 = param_2 + uVar1 * -0x20;
    }
    bVar7 = uVar1 <= param_2 >> 4;
    if (bVar7) {
      param_2 = param_2 + uVar1 * -0x10;
    }
    uVar2 = (((uVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6) * 2 + (uint)bVar7;
_0800E5FC:
    bVar4 = uVar1 <= param_2 >> 3;
    if (bVar4) {
      param_2 = param_2 + uVar1 * -8;
    }
    uVar2 = uVar2 * 2 + (uint)bVar4;
_0800E608:
    bVar4 = uVar1 <= param_2 >> 2;
    if (bVar4) {
      param_2 = param_2 + uVar1 * -4;
    }
    bVar5 = uVar1 <= param_2 >> 1;
    if (bVar5) {
      param_2 = param_2 + uVar1 * -2;
    }
    uVar2 = (uVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5;
    bVar5 = uVar1 <= param_2;
    if (bVar5) {
      param_2 = param_2 - uVar1;
    }
    bVar4 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar5);
    uVar2 = uVar2 * 2 + (uint)bVar5;
  } while (bVar4);
  uVar1 = (int)uVar3 >> 0x1f;
  if ((bool)((byte)(uVar3 >> 0x1e) & 1)) {
    param_2 = -param_2;
  }
  return CONCAT44(param_2,(uVar2 ^ uVar1) - uVar1);
}


/* sub_0800E640 @ 0x0800E640 */

int sub_0800E640(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  iVar2 = 0;
  uVar1 = param_1;
  if (param_2 >> 3 < param_1) goto _0800E6D4;
  if (param_2 >> 8 < param_1) goto _0800E698;
  uVar1 = param_1 << 8;
  iVar2 = -0x1000000;
  if (param_2 >> 4 < uVar1) goto _0800E6C8;
  if (param_2 >> 8 < uVar1) goto _0800E698;
  uVar1 = param_1 << 0x10;
  iVar2 = -0x10000;
  if (uVar1 <= param_2 >> 8) {
    uVar1 = param_1 << 0x18;
    iVar2 = -0x100;
  }
  if (param_2 >> 4 < uVar1) goto _0800E6C8;
  bVar4 = uVar1 == 0;
  if (!bVar4) {
    do {
      if (bVar4) {
        uVar1 = uVar1 >> 8;
      }
_0800E698:
      bVar4 = uVar1 <= param_2 >> 7;
      if (bVar4) {
        param_2 = param_2 + uVar1 * -0x80;
      }
      bVar5 = uVar1 <= param_2 >> 6;
      if (bVar5) {
        param_2 = param_2 + uVar1 * -0x40;
      }
      bVar6 = uVar1 <= param_2 >> 5;
      if (bVar6) {
        param_2 = param_2 + uVar1 * -0x20;
      }
      bVar7 = uVar1 <= param_2 >> 4;
      if (bVar7) {
        param_2 = param_2 + uVar1 * -0x10;
      }
      iVar2 = (((iVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6) * 2 + (uint)bVar7;
_0800E6C8:
      bVar4 = uVar1 <= param_2 >> 3;
      if (bVar4) {
        param_2 = param_2 + uVar1 * -8;
      }
      iVar2 = iVar2 * 2 + (uint)bVar4;
_0800E6D4:
      bVar4 = uVar1 <= param_2 >> 2;
      if (bVar4) {
        param_2 = param_2 + uVar1 * -4;
      }
      bVar5 = uVar1 <= param_2 >> 1;
      if (bVar5) {
        param_2 = param_2 + uVar1 * -2;
      }
      uVar3 = (iVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5;
      bVar5 = uVar1 <= param_2;
      if (bVar5) {
        param_2 = param_2 - uVar1;
      }
      bVar4 = CARRY4(uVar3,uVar3) || CARRY4(uVar3 * 2,(uint)bVar5);
      iVar2 = uVar3 * 2 + (uint)bVar5;
    } while (bVar4);
    return iVar2;
  }
  iVar2 = sub_0800EEC0(2,2);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = sub_0800E9A0();
  return iVar2;
}


/* sub_0800E644 @ 0x0800E644 */

int sub_0800E644(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  iVar2 = 0;
  uVar1 = param_1;
  if (param_2 >> 3 < param_1) goto _0800E6D4;
  if (param_2 >> 8 < param_1) goto _0800E698;
  uVar1 = param_1 << 8;
  iVar2 = -0x1000000;
  if (param_2 >> 4 < uVar1) goto _0800E6C8;
  if (param_2 >> 8 < uVar1) goto _0800E698;
  uVar1 = param_1 << 0x10;
  iVar2 = -0x10000;
  if (uVar1 <= param_2 >> 8) {
    uVar1 = param_1 << 0x18;
    iVar2 = -0x100;
  }
  if (param_2 >> 4 < uVar1) goto _0800E6C8;
  bVar4 = uVar1 == 0;
  if (bVar4) {
    iVar2 = sub_0800EEC0(2,2);
    if (iVar2 != 0) {
      iVar2 = sub_0800E9A0();
      return iVar2;
    }
    return 0;
  }
  do {
    if (bVar4) {
      uVar1 = uVar1 >> 8;
    }
_0800E698:
    bVar4 = uVar1 <= param_2 >> 7;
    if (bVar4) {
      param_2 = param_2 + uVar1 * -0x80;
    }
    bVar5 = uVar1 <= param_2 >> 6;
    if (bVar5) {
      param_2 = param_2 + uVar1 * -0x40;
    }
    bVar6 = uVar1 <= param_2 >> 5;
    if (bVar6) {
      param_2 = param_2 + uVar1 * -0x20;
    }
    bVar7 = uVar1 <= param_2 >> 4;
    if (bVar7) {
      param_2 = param_2 + uVar1 * -0x10;
    }
    iVar2 = (((iVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6) * 2 + (uint)bVar7;
_0800E6C8:
    bVar4 = uVar1 <= param_2 >> 3;
    if (bVar4) {
      param_2 = param_2 + uVar1 * -8;
    }
    iVar2 = iVar2 * 2 + (uint)bVar4;
_0800E6D4:
    bVar4 = uVar1 <= param_2 >> 2;
    if (bVar4) {
      param_2 = param_2 + uVar1 * -4;
    }
    bVar5 = uVar1 <= param_2 >> 1;
    if (bVar5) {
      param_2 = param_2 + uVar1 * -2;
    }
    uVar3 = (iVar2 * 2 + (uint)bVar4) * 2 + (uint)bVar5;
    bVar5 = uVar1 <= param_2;
    if (bVar5) {
      param_2 = param_2 - uVar1;
    }
    bVar4 = CARRY4(uVar3,uVar3) || CARRY4(uVar3 * 2,(uint)bVar5);
    iVar2 = uVar3 * 2 + (uint)bVar5;
  } while (bVar4);
  return iVar2;
}


/* sub_0800E704 @ 0x0800E704 */

undefined8 sub_0800E704(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = -param_1;
  }
  uVar2 = uVar1 - (uVar1 >> 2);
  uVar2 = uVar2 + (uVar2 >> 4);
  uVar2 = uVar2 + (uVar2 >> 8);
  uVar2 = uVar2 + (uVar2 >> 0x10) >> 3;
  iVar3 = (uVar1 - 10) + uVar2 * -10;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 10;
  }
  else {
    uVar2 = uVar2 + 1;
  }
  if ((int)param_1 < 0) {
    uVar2 = -uVar2;
    iVar3 = -iVar3;
  }
  return CONCAT44(iVar3,uVar2);
}


/* sub_0800E708 @ 0x0800E708 */

undefined8 sub_0800E708(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = -param_1;
  }
  uVar2 = uVar1 - (uVar1 >> 2);
  uVar2 = uVar2 + (uVar2 >> 4);
  uVar2 = uVar2 + (uVar2 >> 8);
  uVar2 = uVar2 + (uVar2 >> 0x10) >> 3;
  iVar3 = (uVar1 - 10) + uVar2 * -10;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 10;
  }
  else {
    uVar2 = uVar2 + 1;
  }
  if ((int)param_1 < 0) {
    uVar2 = -uVar2;
    iVar3 = -iVar3;
  }
  return CONCAT44(iVar3,uVar2);
}


/* sub_0800E748 @ 0x0800E748 */

undefined8 sub_0800E748(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 - (param_1 >> 2);
  uVar1 = uVar1 + (uVar1 >> 4);
  uVar1 = uVar1 + (uVar1 >> 8);
  uVar1 = uVar1 + (uVar1 >> 0x10) >> 3;
  iVar2 = (param_1 - 10) + uVar1 * -10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 10;
  }
  else {
    uVar1 = uVar1 + 1;
  }
  return CONCAT44(iVar2,uVar1);
}


/* sub_0800E74C @ 0x0800E74C */

undefined8 sub_0800E74C(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 - (param_1 >> 2);
  uVar1 = uVar1 + (uVar1 >> 4);
  uVar1 = uVar1 + (uVar1 >> 8);
  uVar1 = uVar1 + (uVar1 >> 0x10) >> 3;
  iVar2 = (param_1 - 10) + uVar1 * -10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 10;
  }
  else {
    uVar1 = uVar1 + 1;
  }
  return CONCAT44(iVar2,uVar1);
}


/* sub_0800E778 @ 0x0800E778 */

int sub_0800E778(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if (param_1 != 0) {
    iVar1 = param_1;
  }
  iVar1 = sub_0800E86A(iVar1);
  if (iVar1 == 0) {
    iVar2 = sub_0800E7C4();
    if (*(int *)(iVar2 + 0x34) != 0) {
      __call_via_r0();
    }
  }
  return iVar1;
}


/* sub_0800E7A2 @ 0x0800E7A2 */

undefined4 sub_0800E7A2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800E880(param_1,0,param_3,param_4,param_4);
  return 0;
}


/* sub_0800E7A4 @ 0x0800E7A4 */

undefined4 sub_0800E7A4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800E880(param_1,0,param_3,param_4,param_4);
  return 0;
}


/* sub_0800E7B4 @ 0x0800E7B4 */

void sub_0800E7B4(void)

{
  int iVar1;
  
  iVar1 = sub_0800EEC0(2,2);
  if (iVar1 == 0) {
    return;
  }
  sub_0800E9A0();
  return;
}


/* sub_0800E7B8 @ 0x0800E7B8 */

void sub_0800E7B8(void)

{
  int iVar1;
  
  iVar1 = sub_0800EEC0(2,2);
  if (iVar1 != 0) {
    sub_0800E9A0();
    return;
  }
  return;
}


/* sub_0800E7C4 @ 0x0800E7C4 */

undefined * sub_0800E7C4(void)

{
  return &DAT_03004654;
}


/* sub_0800E7C8 @ 0x0800E7C8 */

undefined * sub_0800E7C8(void)

{
  return &DAT_03004654;
}


/* sub_0800E7D4 @ 0x0800E7D4 */

void sub_0800E7D4(void)

{
  return;
}


/* sub_0800E7D6 @ 0x0800E7D6 */

void sub_0800E7D6(void)

{
  return;
}


/* sub_0800E7D8 @ 0x0800E7D8 */

bool sub_0800E7D8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = sub_0800E98C(param_2,&local_c);
  if (iVar1 != 0) {
    sub_0800E95C(param_1,local_c,iVar1);
  }
  return iVar1 != 0;
}


/* sub_0800E802 @ 0x0800E802 */

void sub_0800E802(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800E880(9,1,param_3,param_4,param_4);
  return;
}


/* sub_0800E812 @ 0x0800E812 */

void sub_0800E812(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_18;
  
  local_18 = param_4;
  iVar1 = sub_0800E8EE(0);
  if (param_2 < param_1 + iVar1) {
    iVar2 = sub_0800E98C(iVar1,&local_18);
    if (iVar2 == 0) {
      sub_0800E880(9,0);
    }
    if (local_18 != param_2) {
      param_1 = local_18;
    }
    param_2 = local_18 + iVar2;
  }
  iVar2 = sub_0800E7C4();
  *(uint *)(iVar2 + 8) = param_1;
  uVar3 = param_1 + iVar1;
  sub_0800E8E4(param_1);
  if (param_2 != uVar3) {
    sub_0800E95C(*(undefined4 *)(iVar2 + 8),uVar3,param_2 - uVar3);
  }
  return;
}


/* sub_0800E86A @ 0x0800E86A */

void sub_0800E86A(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = sub_0800E7C4();
  sub_0800E8F2(*(undefined4 *)(iVar1 + 8),param_1);
  return;
}


/* sub_0800E880 @ 0x0800E880 */

void sub_0800E880(void)

{
  int iVar1;
  
  iVar1 = sub_0800EEC0();
  if (iVar1 == 0) {
    return;
  }
  sub_0800E9A0();
  return;
}


/* sub_0800E884 @ 0x0800E884 */

void sub_0800E884(void)

{
  int iVar1;
  
  iVar1 = sub_0800EEC0();
  if (iVar1 != 0) {
    sub_0800E9A0();
    return;
  }
  return;
}


/* sub_0800E8A0 @ 0x0800E8A0 */

void sub_0800E8A0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_0800E8B2(0xffffffff,param_1);
  if (iVar1 == -1) {
    uVar2 = sub_0800E9B0(param_1,param_2);
  }
  else {
    if (iVar1 != -3) {
      __call_via_r2(param_1,param_2);
    }
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0800e8c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


/* sub_0800E8B2 @ 0x0800E8B2 */

void sub_0800E8B2(int param_1)

{
  undefined4 uVar1;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  int unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == unaff_r6) {
    uVar1 = sub_0800E9B0(unaff_r4,unaff_r5);
  }
  else {
    if (param_1 != -3) {
      __call_via_r2(unaff_r4,unaff_r5);
    }
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0800e8c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}


/* sub_0800E8E4 @ 0x0800E8E4 */

void sub_0800E8E4(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_1;
  return;
}


/* sub_0800E8EE @ 0x0800E8EE */

undefined4 sub_0800E8EE(void)

{
  return 0xc;
}


/* sub_0800E8F2 @ 0x0800E8F2 */

uint * sub_0800E8F2(uint *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  uVar4 = param_2 + 4;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  uVar4 = uVar4 + 7 & 0xfffffff8;
  if (param_2 - 1U < uVar4) {
    do {
      puVar3 = (uint *)param_1[1];
      puVar2 = param_1;
      while (puVar1 = puVar3, puVar1 != (uint *)0x0) {
        if (uVar4 <= *puVar1) {
          if (*puVar1 < uVar4 + 8) {
            puVar2[1] = puVar1[1];
          }
          else {
            piVar6 = (int *)((int)puVar1 + uVar4);
            piVar6[1] = puVar1[1];
            *piVar6 = *puVar1 - uVar4;
            puVar2[1] = (uint)piVar6;
            *puVar1 = uVar4;
          }
          return puVar1 + 1;
        }
        puVar2 = puVar1;
        puVar3 = (uint *)puVar1[1];
      }
      iVar5 = sub_0800E7D8(param_1,uVar4);
    } while (iVar5 != 0);
  }
  return (uint *)0x0;
}


/* sub_0800E95A @ 0x0800E95A */

void sub_0800E95A(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  piVar1 = (int *)param_1[1];
  piVar4 = param_1;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 < param_2))) {
    piVar4 = piVar2;
    piVar1 = (int *)piVar2[1];
  }
  iVar3 = *piVar4;
  if ((int *)(iVar3 + (int)piVar4) != param_2) {
    param_2 = (int *)(((int)param_2 + 3U & 0xfffffff8) + 4);
  }
  *param_2 = param_3;
  sub_0800EAC8(param_1,param_2 + 1,param_3,(int *)(iVar3 + (int)piVar4),param_4);
                    /* WARNING: Could not recover jumptable at 0x0800e98a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* sub_0800E95C @ 0x0800E95C */

void sub_0800E95C(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  piVar1 = (int *)param_1[1];
  piVar4 = param_1;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 < param_2))) {
    piVar4 = piVar2;
    piVar1 = (int *)piVar2[1];
  }
  iVar3 = *piVar4;
  if ((int *)(iVar3 + (int)piVar4) != param_2) {
    param_2 = (int *)(((int)param_2 + 3U & 0xfffffff8) + 4);
  }
  *param_2 = param_3;
  sub_0800EAC8(param_1,param_2 + 1,param_3,(int *)(iVar3 + (int)piVar4),param_4);
                    /* WARNING: Could not recover jumptable at 0x0800e98a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* sub_0800E98C @ 0x0800E98C */

void sub_0800E98C(void)

{
  sub_0800EBA4();
  return;
}


/* sub_0800E990 @ 0x0800E990 */

void sub_0800E990(void)

{
  sub_0800EBA4();
  return;
}


/* sub_0800E9A0 @ 0x0800E9A0 */

void sub_0800E9A0(void)

{
  software_interrupt(0xab);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* sub_0800E9B0 @ 0x0800E9B0 */

void sub_0800E9B0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = "";
  pcVar3 = pcVar2;
  if (param_1 - 1U < 0xd) {
    pcVar4 = (char *)((int)&PTR_sub_0800D11C_1_08012128 + param_1 * 0x17 + 3);
    if (param_1 == 2) {
      if ((int)param_2 << 5 < 0) {
        pcVar3 = "Invalid Operation";
      }
      else if (((uint)param_2 & 0x8000002) == 0) {
        if ((int)param_2 << 3 < 0) {
          pcVar3 = "Overflow";
        }
        else if ((int)param_2 << 2 < 0) {
          pcVar3 = "Underflow";
        }
        else if ((int)param_2 << 1 < 0) {
          pcVar3 = "Inexact Result";
        }
      }
      else {
        pcVar3 = "Divide By Zero";
      }
    }
    else {
      pcVar3 = param_2;
      if (((param_1 != 8) && (pcVar3 = pcVar2, param_1 == 9)) && (param_2 == (char *)0x1)) {
        pcVar4 = ": Heap memory corrupted";
      }
    }
  }
  else {
    pcVar4 = "Unknown signal";
  }
  sub_0800EC6C(10);
  cVar1 = *pcVar4;
  while (cVar1 != '\0') {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    sub_0800EC6C(cVar1);
    cVar1 = *pcVar4;
  }
  cVar1 = *pcVar3;
  while (cVar1 != '\0') {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    sub_0800EC6C(cVar1);
    cVar1 = *pcVar3;
  }
  sub_0800EC6C(10);
                    /* WARNING: Could not recover jumptable at 0x0800ea44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(1);
  return;
}


/* sub_0800EAC8 @ 0x0800EAC8 */

void sub_0800EAC8(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_2 + -4);
  piVar1 = (int *)param_1[1];
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 < piVar3))) {
    param_1 = piVar2;
    piVar1 = (int *)piVar2[1];
  }
  if ((int *)(*param_1 + (int)param_1) == piVar3) {
    *param_1 = *param_1 + *piVar3;
    piVar3 = param_1;
  }
  else {
    param_1[1] = (int)piVar3;
  }
  if ((int *)(*piVar3 + (int)piVar3) == piVar2) {
    piVar3[1] = piVar2[1];
    *piVar3 = *piVar3 + *piVar2;
  }
  else {
    piVar3[1] = (int)piVar2;
  }
  return;
}


/* sub_0800EB0C @ 0x0800EB0C */

void sub_0800EB0C(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 in_lr;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar1 = sub_0800E7C8();
  uVar2 = uVar1 & 0xfffffff8;
  *(undefined4 *)(uVar2 + 0x5c) = in_lr;
  *(uint *)(uVar2 + 0x58) = uVar1;
  uVar6 = sub_0800EC24();
  puVar3 = *(undefined4 **)(uVar2 + 0x58);
  uVar5 = *(undefined4 *)(uVar2 + 0x5c);
  uVar4 = (uint)((ulonglong)uVar6 >> 0x20) & 0xfffffff8;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0xf] = 0;
  *(undefined4 *)(uVar4 - 4) = uVar5;
  *(undefined4 **)(uVar4 - 8) = puVar3;
  *(undefined8 *)(uVar4 - 0x10) = uVar6;
  puVar3[7] = 0x150;
  puVar3[6] = 0x40;
  puVar3[4] = 1;
  *(undefined4 *)(*(int *)(uVar4 - 8) + 0x14) = *(undefined4 *)(uVar4 - 0x10);
  return;
}


/* sub_0800EB10 @ 0x0800EB10 */

void sub_0800EB10(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 in_lr;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar1 = sub_0800E7C8();
  uVar2 = uVar1 & 0xfffffff8;
  *(undefined4 *)(uVar2 + 0x5c) = in_lr;
  *(uint *)(uVar2 + 0x58) = uVar1;
  uVar6 = sub_0800EC24();
  puVar3 = *(undefined4 **)(uVar2 + 0x58);
  uVar5 = *(undefined4 *)(uVar2 + 0x5c);
  uVar4 = (uint)((ulonglong)uVar6 >> 0x20) & 0xfffffff8;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0xf] = 0;
  *(undefined4 *)(uVar4 - 4) = uVar5;
  *(undefined4 **)(uVar4 - 8) = puVar3;
  *(undefined8 *)(uVar4 - 0x10) = uVar6;
  puVar3[7] = 0x150;
  puVar3[6] = 0x40;
  puVar3[4] = 1;
  *(undefined4 *)(*(int *)(uVar4 - 8) + 0x14) = *(undefined4 *)(uVar4 - 0x10);
  return;
}


/* sub_0800EB30 @ 0x0800EB30 */

void sub_0800EB30(void)

{
  undefined4 *unaff_r4;
  uint uVar1;
  undefined4 in_lr;
  undefined8 uVar2;
  
  uVar2 = sub_0800EC24();
  uVar1 = (uint)((ulonglong)uVar2 >> 0x20) & 0xfffffff8;
  *unaff_r4 = 0;
  unaff_r4[1] = 0;
  unaff_r4[2] = 0;
  unaff_r4[3] = 0;
  unaff_r4[4] = 0;
  unaff_r4[5] = 0;
  unaff_r4[6] = 0;
  unaff_r4[7] = 0;
  unaff_r4[8] = 0;
  unaff_r4[9] = 0;
  unaff_r4[10] = 0;
  unaff_r4[0xb] = 0;
  unaff_r4[0xc] = 0;
  unaff_r4[0xd] = 0;
  unaff_r4[0xe] = 0;
  unaff_r4[0xf] = 0;
  *(undefined4 *)(uVar1 - 4) = in_lr;
  *(undefined4 **)(uVar1 - 8) = unaff_r4;
  *(undefined8 *)(uVar1 - 0x10) = uVar2;
  unaff_r4[7] = 0x150;
  unaff_r4[6] = 0x40;
  unaff_r4[4] = 1;
  *(undefined4 *)(*(int *)(uVar1 - 8) + 0x14) = *(undefined4 *)(uVar1 - 0x10);
  return;
}


/* sub_0800EB74 @ 0x0800EB74 */

void sub_0800EB74(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int unaff_r4;
  
  *(int *)(unaff_r4 + 0x1c) = param_1 + param_2 + 0x40 + 0x110;
  *(int *)(unaff_r4 + 0x18) = param_2 + 0x40;
  *(undefined4 *)(unaff_r4 + 0x10) = 1;
  *(undefined4 *)(param_7 + 0x14) = param_5;
  return;
}


/* sub_0800EBA0 @ 0x0800EBA0 */

int sub_0800EBA0(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  iVar1 = sub_0800E7C8();
  puVar4 = &stack0xfffffff8 + -*(int *)(iVar1 + 0x1c);
  iVar3 = *(int *)(iVar1 + 0x14);
  *param_2 = iVar3;
  puVar6 = (undefined1 *)(iVar3 + param_1);
  if (puVar4 < puVar6) {
    return 0;
  }
  uVar5 = (uint)CARRY4((uint)puVar4,(uint)puVar6) << 0x1f |
          (uint)(puVar4 + (int)puVar6) >> 1 & 0xfffffff8;
  uVar2 = (uint)(puVar6 + 0x1007) & 0xfffffff8;
  if (uVar5 < ((uint)(puVar6 + 0x1007) & 0xfffffff8)) {
    uVar2 = uVar5;
  }
  *(uint *)(iVar1 + 0x14) = uVar2;
  return uVar2 - iVar3;
}


/* sub_0800EBA4 @ 0x0800EBA4 */

int sub_0800EBA4(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  iVar1 = sub_0800E7C8();
  puVar4 = &stack0xfffffff8 + -*(int *)(iVar1 + 0x1c);
  iVar3 = *(int *)(iVar1 + 0x14);
  *param_2 = iVar3;
  puVar6 = (undefined1 *)(iVar3 + param_1);
  if (puVar6 <= puVar4) {
    uVar5 = (uint)CARRY4((uint)puVar4,(uint)puVar6) << 0x1f |
            (uint)(puVar4 + (int)puVar6) >> 1 & 0xfffffff8;
    uVar2 = (uint)(puVar6 + 0x1007) & 0xfffffff8;
    if (uVar5 < ((uint)(puVar6 + 0x1007) & 0xfffffff8)) {
      uVar2 = uVar5;
    }
    *(uint *)(iVar1 + 0x14) = uVar2;
    return uVar2 - iVar3;
  }
  return 0;
}


/* sub_0800EC10 @ 0x0800EC10 */

void sub_0800EC10(void)

{
  return;
}


/* sub_0800EC18 @ 0x0800EC18 */

void sub_0800EC18(void)

{
  return;
}


/* sub_0800EC1C @ 0x0800EC1C */

void sub_0800EC1C(void)

{
  return;
}


/* sub_0800EC20 @ 0x0800EC20 */

undefined8 sub_0800EC20(void)

{
  int iStack_14;
  undefined4 uStack_c;
  
  software_interrupt(0x123456);
  if (iStack_14 == 0) {
    iStack_14 = 0x3004814;
  }
  return CONCAT44(uStack_c,iStack_14);
}


/* sub_0800EC24 @ 0x0800EC24 */

undefined8 sub_0800EC24(void)

{
  undefined4 local_14;
  undefined4 local_c;
  
  software_interrupt(0x123456);
  if (local_14 == 0) {
    local_14 = 0x3004814;
  }
  return CONCAT44(local_c,local_14);
}


/* sub_0800EC6C @ 0x0800EC6C */

undefined8 sub_0800EC6C(void)

{
  undefined1 local_8 [8];
  
  software_interrupt(0xab);
  return CONCAT44(local_8,3);
}


/* sub_0800EC7E @ 0x0800EC7E */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800EC7E(void)

{
  ram0x0300000c = &_0800F180;
  return;
}


/* sub_0800EC80 @ 0x0800EC80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800EC80(void)

{
  ram0x0300000c = &_0800F180;
  return;
}


/* sub_0800EC90 @ 0x0800EC90 */

void sub_0800EC90(void)

{
  DAT_03000018 = &_0800EFEC;
  return;
}


/* sub_0800ECA0 @ 0x0800ECA0 */

void sub_0800ECA0(void)

{
  return;
}


/* sub_0800ECA2 @ 0x0800ECA2 */

void sub_0800ECA2(void)

{
  DAT_030000d8 = &_0800EF9C;
  return;
}


/* sub_0800ECA4 @ 0x0800ECA4 */

void sub_0800ECA4(void)

{
  DAT_030000d8 = &_0800EF9C;
  return;
}


/* sub_0800ECB4 @ 0x0800ECB4 */

void sub_0800ECB4(void)

{
  DAT_030000e4 = &_0800F1C8;
  DAT_030000e8 = &_0800F0D0;
  return;
}


/* sub_0800ECD0 @ 0x0800ECD0 */

void sub_0800ECD0(void)

{
  DAT_030000ec = &_0800EEF0;
  return;
}


/* sub_0800ECE0 @ 0x0800ECE0 */

void sub_0800ECE0(void)

{
  DAT_030000fc = &_0800F100;
  DAT_03000104 = &_0800F164;
  return;
}


/* sub_0800ECFC @ 0x0800ECFC */

void sub_0800ECFC(void)

{
  DAT_0300010c = &_0800EF60;
  return;
}


/* sub_0800ED0C @ 0x0800ED0C */

void sub_0800ED0C(void)

{
  DAT_03000590 = &_0800EF84;
  return;
}


/* sub_0800ED1C @ 0x0800ED1C */

void sub_0800ED1C(void)

{
  DAT_03000598 = &_0800F01C;
  DAT_030046b8 = 0;
  return;
}


/* sub_0800ED38 @ 0x0800ED38 */

void sub_0800ED38(void)

{
  DAT_030005a0 = &_0800F134;
  return;
}


/* sub_0800ED48 @ 0x0800ED48 */

void sub_0800ED48(void)

{
  DAT_030005bc = &_0800F04C;
  return;
}


/* sub_0800ED58 @ 0x0800ED58 */

void sub_0800ED58(void)

{
  DAT_030005c4 = &_0800F11C;
  DAT_030005cc = &_0800F1B0;
  return;
}


/* sub_0800ED74 @ 0x0800ED74 */

void sub_0800ED74(void)

{
  DAT_030005d8 = &_0800F064;
  DAT_030005e0 = &_0800F0B4;
  return;
}


/* sub_0800ED90 @ 0x0800ED90 */

void sub_0800ED90(void)

{
  DAT_030005e8 = &_0800F198;
  return;
}


/* sub_0800EDA0 @ 0x0800EDA0 */

void sub_0800EDA0(void)

{
  DAT_03000610 = 0;
  return;
}


/* sub_0800EDAC @ 0x0800EDAC */

void sub_0800EDAC(void)

{
  DAT_030007f4 = &_0800F034;
  return;
}


/* sub_0800EDBC @ 0x0800EDBC */

void sub_0800EDBC(void)

{
  DAT_0300080c = &_0800F07C;
  return;
}


/* sub_0800EDCC @ 0x0800EDCC */

void sub_0800EDCC(void)

{
  DAT_03000818 = &_0800EFD4;
  return;
}


/* sub_0800EDDC @ 0x0800EDDC */

void sub_0800EDDC(void)

{
  DAT_0300085c = &_0800EF48;
  return;
}


/* sub_0800EDEC @ 0x0800EDEC */

void sub_0800EDEC(void)

{
  DAT_03000864 = &_0800F094;
  return;
}


/* sub_0800EDFC @ 0x0800EDFC */

void sub_0800EDFC(void)

{
  DAT_03000868 = &_0800EF28;
  return;
}


/* sub_0800EE0C @ 0x0800EE0C */

void sub_0800EE0C(void)

{
  DAT_0300087c = 0;
  return;
}


/* sub_0800EE18 @ 0x0800EE18 */

void sub_0800EE18(void)

{
  DAT_03000a14 = 0;
  return;
}


/* sub_0800EE24 @ 0x0800EE24 */

void sub_0800EE24(void)

{
  DAT_03003b68 = &_0800EED8;
  return;
}


/* sub_0800EE34 @ 0x0800EE34 */

void sub_0800EE34(void)

{
  DAT_03004398 = &_0800F0E8;
  return;
}


/* sub_0800EE44 @ 0x0800EE44 */

void sub_0800EE44(void)

{
  DAT_0300463c = &_0800F14C;
  return;
}


/* sub_0800EEC0 @ 0x0800EEC0 */

void sub_0800EEC0(void)

{
  sub_0800E8A0();
  return;
}


