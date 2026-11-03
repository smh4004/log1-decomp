/* Ghidra reference decompilation of code_080047AC (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_080047AC @ 0x080047AC */

void sub_080047AC(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  sub_080098F8();
  REG_DISPCNT = 0x404;
  *(undefined1 *)(param_1 + 8) = 0;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = (short)((uint)DAT_03000828 * 0x112 >> 8);
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = (short)((uint)DAT_0300082a * 0x19a >> 8);
  REG_BLDCNT = 0;
  iVar1 = 0;
  while( true ) {
    uVar2 = iVar1 * 0x3e ^ 0x9c;
    uVar3 = iVar1 * 0xe3 + 0x25;
    if ((uVar2 & 0xff) != uVar2) {
      return;
    }
    if (uVar3 != (uVar3 & 0xff)) break;
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      DAT_0300000b = &DAT_03000104;
      return;
    }
  }
  return;
}


/* sub_08004832 @ 0x08004832 */

void sub_08004832(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  ushort local_214 [256];
  
  if ((DAT_03000832 < DAT_03000830) && (iVar2 = sub_080045F8(0x3000824,0), iVar2 != 0)) {
    if (DAT_03000840 != 0) {
      iVar2 = 0;
      do {
        iVar1 = iVar2 * 3;
        iVar3 = iVar2 + 1;
        local_214[iVar2] =
             (ushort)((byte)(&DAT_02035826)[iVar1] >> 3) << 10 |
             (ushort)((byte)(&DAT_02035824)[iVar1] >> 3) |
             (ushort)((byte)(&DAT_02035825)[iVar1] >> 3) << 5;
        iVar2 = iVar3;
      } while (iVar3 < 0x100);
      REG_DMA3SAD = local_214;
      REG_DMA3DAD = 0x5000000;
      Ram040000dc = 0x100;
      DAT_040000de = 0x8000;
    }
    if (*(char *)(param_1 + 8) == '\0') {
      puVar4 = &DAT_0600a000;
    }
    else {
      puVar4 = (undefined *)0x6000000;
    }
    iVar2 = 0;
    if (DAT_0300082a != 0) {
      do {
        REG_DMA3SAD = (undefined4 *)((int)&DAT_0202c224 + iVar2 * (uint)DAT_03000828);
        REG_DMA3DAD = puVar4 + iVar2 * 0xf0;
        Ram040000dc = DAT_03000828 >> 1;
        DAT_040000de = 0x8000;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)DAT_0300082a);
    }
    if (*(char *)(param_1 + 8) == '\0') {
      REG_DISPCNT = 0x414;
    }
    else {
      REG_DISPCNT = 0x404;
    }
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) ^ 1;
  }
  return;
}


/* sub_080048FA @ 0x080048FA */

undefined4 sub_080048FA(int param_1)

{
  int iVar1;
  
  iVar1 = sub_0800A6B2(6,0x8011462);
  if (iVar1 == 0) {
    if (((DAT_03003d14 & 1) != 0) ||
       ((*(int *)(param_1 + 4) == 0 && (DAT_03000830 <= DAT_03000832)))) {
      if (*(int *)(param_1 + 4) == 0) {
        return 1;
      }
      sub_080098F8();
      sub_08009744(*(int **)(param_1 + 4));
    }
  }
  else {
    sub_0800ACFE(7);
    DAT_03000c18 = 1;
  }
  return 0;
}


/* sub_0800494A @ 0x0800494A */

void sub_0800494A(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 4) = param_3;
  sub_080042F4(0x3000824,param_2,2);
  DAT_03000854 = &DAT_0202c224;
  DAT_03000844 = &DAT_02035824;
  if (*(int *)(param_1 + 4) == 0) {
    sub_080097F8((int *)param_1);
  }
  else {
    sub_08009744((int *)param_1);
  }
  return;
}


/* sub_080049B4 @ 0x080049B4 */

undefined4 sub_080049B4(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_080049D4 @ 0x080049D4 */

void sub_080049D4(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    sub_08005DA6(param_1);
  }
  return;
}


/* sub_080049F4 @ 0x080049F4 */

undefined4 sub_080049F4(void)

{
  return 0;
}


/* sub_080049FC @ 0x080049FC */

undefined4 sub_080049FC(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08004A1C @ 0x08004A1C */

void sub_08004A1C(void)

{
  return;
}


/* sub_08004A1E @ 0x08004A1E */

undefined4 sub_08004A1E(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_2 == 0) && ((&DAT_0300004e)[*(byte *)(param_1 + 6)] != '\0')) &&
      (*(byte *)(param_1 + 7) == param_3)) && (iVar1 = sub_08000954(param_1), iVar1 == 0)) {
    (&DAT_0300004e)[*(byte *)(param_1 + 6)] = (&DAT_0300004e)[*(byte *)(param_1 + 6)] + -1;
    sub_0800ACFE(7);
    sub_0800536C((uint)*(byte *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
    sub_08005526((uint)*(byte *)(param_1 + 4));
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* sub_08004A74 @ 0x08004A74 */

void sub_08004A74(void)

{
  return;
}


/* sub_08004A76 @ 0x08004A76 */

void sub_08004A76(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000926(0x3000028,(uint)*(byte *)(param_1 + 4));
  if (iVar1 == 0) {
    sub_08004E98(0x3000864,(int)(&gUnknown_085C2FB8)[*(byte *)(param_1 + 4)]);
    (&DAT_0300004e)[*(byte *)(param_1 + 4)] = (&DAT_0300004e)[*(byte *)(param_1 + 4)] + '\x01';
  }
  return;
}


/* sub_08004AB0 @ 0x08004AB0 */

void sub_08004AB0(void)

{
  return;
}


/* sub_08004AB2 @ 0x08004AB2 */

void sub_08004AB2(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_4c [64];
  
  sub_08008CE8(auStack_4c,"You receive %d experience points!",*(undefined4 *)(param_1 + 4));
  sub_08004E98(0x3000864,(int)auStack_4c);
  DAT_030007d8 = DAT_030007d8 + *(int *)(param_1 + 4);
  iVar2 = *(int *)(DAT_030007b8 + 0x3c);
  iVar1 = *(int *)(iVar2 + 0x84) + *(int *)(param_1 + 4);
  *(int *)(iVar2 + 0x84) = iVar1;
  sub_08005C32(iVar1);
  iVar1 = sub_08005BFE(iVar2);
  if (iVar1 != 0) {
    sub_08005BBC();
    sub_08002FF6();
  }
  return;
}


/* sub_08004B14 @ 0x08004B14 */

void sub_08004B14(void)

{
  return;
}


/* sub_08004B16 @ 0x08004B16 */

void sub_08004B16(int param_1)

{
  sub_0800ACFE(6);
  sub_08004E98(0x3000864,0x85c2e04);
  DAT_030007b2 = DAT_030007b2 + (ushort)*(byte *)(param_1 + 4);
  return;
}


/* sub_08004B40 @ 0x08004B40 */

undefined4 sub_08004B40(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08004B60 @ 0x08004B60 */

void sub_08004B60(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    sub_08005A94(param_1);
  }
  return;
}


/* sub_08004B80 @ 0x08004B80 */

undefined4 sub_08004B80(void)

{
  return 0;
}


/* sub_08004B88 @ 0x08004B88 */

undefined4 sub_08004B88(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08004BA8 @ 0x08004BA8 */

void sub_08004BA8(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 5) == DAT_030005fc) && (iVar1 = sub_08000954(param_1), iVar1 != 0)) {
    sub_08005AE4(param_1);
  }
  return;
}


/* sub_08004BCA @ 0x08004BCA */

undefined4 sub_08004BCA(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if ((((param_2 == 0) && (*(byte *)(param_1 + 7) == param_3)) &&
      (DAT_030007b0 == *(char *)(param_1 + 6))) && (iVar1 = sub_08000954(param_1), iVar1 == 0)) {
    sub_0800536C((uint)*(byte *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
    sub_08005526((uint)*(byte *)(param_1 + 4));
    sub_080031FA();
    return 1;
  }
  return 0;
}


/* sub_08004C10 @ 0x08004C10 */

undefined4 sub_08004C10(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08004C30 @ 0x08004C30 */

void sub_08004C30(void)

{
  return;
}


/* sub_08004C32 @ 0x08004C32 */

undefined4 sub_08004C32(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (((param_2 == 1) && (*(byte *)(param_1 + 6) == param_3)) &&
     (iVar1 = sub_08000954(param_1), iVar1 == 0)) {
    sub_08005526((uint)*(byte *)(param_1 + 4));
    return 1;
  }
  return 0;
}


/* sub_08004C5C @ 0x08004C5C */

undefined4 sub_08004C5C(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      uVar2 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 8) + iVar1 * 4) + 4);
      if (((&DAT_03000028)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))) == 0) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return 1;
}


/* sub_08004CAC @ 0x08004CAC */

undefined4 sub_08004CAC(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 8) + iVar3 * 4);
      iVar2 = __call_via_r1(piVar1,*(undefined **)(*piVar1 + 4));
      if (iVar2 != 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return 0;
}


/* sub_08004CDA @ 0x08004CDA */

undefined4 sub_08004CDA(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      iVar1 = __call_via_r3();
      if (iVar1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 4));
  }
  return 0;
}


/* sub_08004D10 @ 0x08004D10 */

void sub_08004D10(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x10) + iVar2 * 4);
      __call_via_r1(piVar1,*(undefined **)(*piVar1 + 4));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xc));
  }
  return;
}


/* sub_08004D34 @ 0x08004D34 */

void sub_08004D34(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x10) + iVar2 * 4);
      __call_via_r1(puVar1,*(undefined **)*puVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xc));
  }
  return;
}


/* sub_08004D5C @ 0x08004D5C */

void sub_08004D5C(int param_1)

{
  REG_DISPCNT = 0x800;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x88;
  REG_BLDY = 0x10;
  *(undefined2 *)(param_1 + 4) = 0;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586((undefined4 *)&gUnknown_085C2204,0x202b600,(int *)&DAT_06000000);
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  sub_0800A5F6(0x8592008);
  return;
}


/* sub_08004DAC @ 0x08004DAC */

void sub_08004DAC(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(param_1 + 4);
  if (uVar1 < 0x40) {
    REG_BLDY = (char)((int)(0x40 - uVar1) >> 2);
    return;
  }
  REG_BLDY = (char)((int)(uVar1 - 0x40) >> 2);
  return;
}


/* sub_08004DC6 @ 0x08004DC6 */

undefined4 sub_08004DC6(int param_1)

{
  if (*(short *)(param_1 + 4) == 0x40) {
    if ((DAT_03003d14 & 1) != 0) {
      REG_BLDCNT = 200;
      *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    }
  }
  else {
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
  }
  if (0x80 < *(ushort *)(param_1 + 4)) {
    sub_080098F8();
    sub_0800A5F6(0x8591ff0);
    sub_08009744(&DAT_03000018);
    DAT_03003b60 = 0;
  }
  return 0;
}


/* sub_08004E3C @ 0x08004E3C */

void sub_08004E3C(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_080090AE(&DAT_02029d94,(short *)&gUnknown_0801146E);
  return;
}


/* sub_08004E4E @ 0x08004E4E */

void sub_08004E4E(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_080090AE(&DAT_02029d94,(short *)&gUnknown_0801146E);
  REG_DMA3SAD = 0x85c386a;
  REG_DMA3DAD = 0x5000002;
  Ram040000dc = 0xf;
  DAT_040000de = 0x8000;
  return;
}


/* sub_08004E76 @ 0x08004E76 */

void sub_08004E76(void)

{
  sub_08008D8A(0x2029d94);
  return;
}


/* sub_08004E80 @ 0x08004E80 */

bool sub_08004E80(void)

{
  sub_08009328(&DAT_02029d94,0x8004e3d);
  return DAT_02029da8 == 0;
}


/* sub_08004E98 @ 0x08004E98 */

void sub_08004E98(int param_1,int param_2)

{
  DAT_02029d96 = 3;
  DAT_02029d98 = 4;
  DAT_02029d9a = 0x1b;
  DAT_02029d9c = 8;
  sub_0800930A(&DAT_02029d94,param_2);
  sub_080097F8(&DAT_03000864);
  DAT_02029d96 = 0;
  DAT_02029d98 = 0;
  DAT_02029d9a = 0x1e;
  DAT_02029d9c = 0x14;
  return;
}


/* sub_08004EF4 @ 0x08004EF4 */

char sub_08004EF4(short *param_1,short *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = (int)param_2[1];
  iVar5 = (int)*param_1;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar3 = iVar5 * iVar2 + (int)*param_2;
  cVar1 = *(char *)(iVar4 + iVar3);
  if (cVar1 == '\0') {
    if ((int)*param_2 < iVar5 + -1) {
      cVar1 = *(char *)(iVar4 + iVar3 + 1);
      if (cVar1 == '\0') {
        if (iVar2 < param_1[1] + -1) {
          cVar1 = *(char *)(iVar4 + iVar5 + iVar3);
          if (cVar1 == '\0') {
            cVar1 = *(char *)(iVar4 + iVar5 + iVar3 + 1);
          }
        }
        else {
          cVar1 = '\0';
        }
      }
    }
    else if (iVar2 < param_1[1] + -1) {
      cVar1 = *(char *)(iVar4 + iVar5 + iVar3);
    }
    else {
      cVar1 = '\0';
    }
  }
  return cVar1;
}


/* sub_08004F56 @ 0x08004F56 */

void sub_08004F56(int param_1)

{
  undefined4 *puVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  DAT_03000a14 = 0;
  sub_08009680(&REG_DMA3SAD,0x2005040,0xffffffff,0x57e4);
  sVar2 = *(short *)(param_1 + 4);
  sVar3 = *(short *)(param_1 + 6);
  iVar5 = 0;
  do {
    iVar4 = *(int *)(iVar5 * 4 + param_1 + 8);
    if (iVar4 != 0) {
      sub_08009626(&REG_DMA3SAD,(int)(&DAT_02005040 + iVar5 * 0x1d4c),iVar4,
                   (int)sVar3 * (int)sVar2 + 0x1f >> 3);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  if ((*(int *)(param_1 + 0x14) != 0) && (iVar5 = 0, 0 < *(int *)(*(int *)(param_1 + 0x14) + 0x18)))
  {
    do {
      iVar4 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      puVar1 = &DAT_03000a18 + DAT_03000a14;
      DAT_03000a14 = DAT_03000a14 + 1;
      *puVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 0x1c) + iVar4);
    } while (iVar5 < *(int *)(*(int *)(param_1 + 0x14) + 0x18));
  }
  return;
}


/* sub_08004FD0 @ 0x08004FD0 */

void sub_08004FD0(void)

{
  sub_08006118();
  return;
}


/* sub_08004FD8 @ 0x08004FD8 */

undefined4 sub_08004FD8(undefined4 param_1,uint param_2,int param_3)

{
  if (((uint)(byte)(&DAT_02005040)[param_3 * 0x1d4c + ((int)param_2 >> 3)] & 1 << (param_2 & 7)) !=
      0) {
    return 1;
  }
  return 0;
}


/* sub_08004FF6 @ 0x08004FF6 */

undefined4 sub_08004FF6(void)

{
  return 0;
}


/* sub_08004FFA @ 0x08004FFA */

undefined4 sub_08004FFA(int param_1,short *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2[2] + 7 >> 3;
  iVar5 = (int)param_2[1] >> 3;
  iVar3 = param_2[3] + 7 >> 3;
  if (((((int)*param_2 >> 3 < 0) || (iVar5 < 0)) || (*(short *)(param_1 + 4) < iVar6)) ||
     (*(short *)(param_1 + 6) < iVar3)) {
    uVar1 = 0;
  }
  else {
    for (; iVar5 < iVar3; iVar5 = iVar5 + 1) {
      for (iVar2 = (int)*param_2 >> 3; iVar2 < iVar6; iVar2 = iVar2 + 1) {
        uVar4 = iVar5 * *(short *)(param_1 + 4) + iVar2;
        if (((uint)(byte)(&DAT_02005040)[((int)uVar4 >> 3) + param_3 * 0x1d4c] & 1 << (uVar4 & 7))
            == 0) {
          return 0;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


/* sub_0800507A @ 0x0800507A */

void sub_0800507A(int param_1,short *param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  
  sVar1 = *param_2;
  sVar2 = param_2[2];
  sVar3 = param_2[3];
  for (iVar6 = (int)param_2[1] >> 3; iVar6 < sVar3 + 7 >> 3; iVar6 = iVar6 + 1) {
    sVar4 = *(short *)(param_1 + 4);
    for (iVar7 = (int)sVar1 >> 3; iVar7 < sVar2 + 7 >> 3; iVar7 = iVar7 + 1) {
      uVar8 = iVar6 * sVar4 + iVar7;
      pbVar9 = &DAT_02005040 + ((int)uVar8 >> 3) + param_4 * 0x1d4c;
      bVar5 = (byte)(1 << (uVar8 & 7));
      if (param_3 == 0) {
        *pbVar9 = *pbVar9 & ~bVar5;
      }
      else {
        *pbVar9 = bVar5 | *pbVar9;
      }
    }
  }
  return;
}


/* sub_08005108 @ 0x08005108 */

void sub_08005108(void)

{
  return;
}


/* sub_0800510A @ 0x0800510A */

bool sub_0800510A(int param_1)

{
  return *(int *)(param_1 + 8) != 0;
}


/* sub_08005118 @ 0x08005118 */

void sub_08005118(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  REG_DMA3SAD = *(undefined4 *)(param_1 + 4);
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x80;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar2 = (uint)uVar1 * 8;
  puVar3 = (uint *)(&DAT_0202be24 + iVar2);
  uVar4 = (*puVar3 & 0x1ff00ff) + 0x80000000;
  *puVar3 = uVar4;
  uVar1 = param_2[1];
  uVar5 = *(uint *)(&DAT_0202be28 + iVar2);
  *(uint *)(&DAT_0202be28 + iVar2) = uVar1 & 0x3ff | uVar5 & 0xfffff000;
  *(uint *)(&DAT_0202be28 + iVar2) =
       uVar1 & 0x3ff | uVar5 & 0xffff0000 | ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
  uVar5 = ((uint)*param_1 << 0x17) >> 7;
  *puVar3 = uVar4 & 0xfe00ffff | uVar5;
  *puVar3 = param_1[1] & 0xff | uVar4 & 0xfe00ff00 | uVar5;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x200;
  param_2[1] = param_2[1] + 0x10;
  return;
}


/* sub_080051B4 @ 0x080051B4 */

void sub_080051B4(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_080090AE(&DAT_02029d94,(short *)&DAT_0300086c);
  sub_080090AE(&DAT_02029d94,(short *)&DAT_03000874);
  return;
}


/* sub_080051D0 @ 0x080051D0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080051D0(int param_1,byte *param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 local_24 [2];
  ushort local_22;
  undefined *local_20;
  int iStack_1c;
  byte *local_18;
  
  local_20 = (&gUnknown_0815BF28)[param_1];
  local_24[0] = (undefined1)param_1;
  local_22 = (ushort)*param_2;
  REG_DMA3SAD = 0x85c386a;
  REG_DMA3DAD = 0x5000002;
  Ram040000dc = 0xf;
  DAT_040000de = 0x8000;
  iStack_1c = param_1;
  local_18 = param_2;
  while( true ) {
    pcVar4 = local_20 + (uint)*local_18 * 8;
    *local_18 = pcVar4[1];
    if (*pcVar4 == -1) break;
    uStack_2c = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
    uStack_28 = uStack_2c;
    if ((int)(DAT_030007c2 >> 4) - (int)DAT_0300060a < 0x41) {
      sRam0300086e = 0xd;
    }
    else {
      sRam0300086e = 3;
    }
    sRam03000876 = sRam0300086e;
    if ((*pcVar4 == '4') || (*pcVar4 == 'b')) {
      _DAT_03000874 = 2;
      _DAT_0300086c = 8;
    }
    else {
      _DAT_03000874 = 0x18;
      _DAT_0300086c = 3;
    }
    DAT_02029d9a = _DAT_0300086c + 0x13;
    DAT_02029d9c = sRam0300086e + 4;
    sRam0300087a = sRam0300086e + 4;
    sRam03000878 = _DAT_03000874 + 4;
    DAT_02029d96 = _DAT_0300086c;
    DAT_02029d98 = sRam0300086e;
    sRam03000870 = DAT_02029d9a;
    sRam03000872 = DAT_02029d9c;
    sub_08008D14(&DAT_02029d94);
    sub_0800930A(&DAT_02029d94,*(undefined4 *)(pcVar4 + 4));
    sub_0800994C((short *)&uStack_2c,(short *)&DAT_0300086c,1);
    _DAT_0300086c = (short)uStack_2c;
    sRam0300086e = uStack_2c._2_2_;
    sRam03000870 = (undefined2)uStack_28;
    sRam03000872 = uStack_28._2_2_;
    piVar5 = (int *)(&gUnknown_0815A4E8)[*pcVar4];
    puVar2 = (undefined4 *)sub_08002716(*pcVar4 * 4);
    uVar1 = sub_08005EA6(*piVar5);
    *(undefined1 *)((int)puVar2 + 0xd) = uVar1;
    uStack_28 = CONCAT22(sRam03000876 << 3,_DAT_03000874 << 3);
    *puVar2 = uStack_28;
    *(undefined1 *)(puVar2 + 3) = 0;
    uVar3 = sub_080095DC((int)piVar5);
    puVar2[2] = uVar3;
    sub_0800245A((int)puVar2,&gUnknown_08011480);
    sub_08002556(0,1);
    sub_08008D14(&DAT_02029d94);
    sub_080090AE(&DAT_02029d94,(short *)&DAT_0300086c);
    sub_080090AE(&DAT_02029d94,(short *)&DAT_03000874);
    sub_080097F8(&DAT_03000868);
    DAT_02029d96 = 0;
    DAT_02029d98 = 0;
    DAT_02029d9a = 0x1e;
    DAT_02029d9c = 0x14;
    (&DAT_03000994)[(uint)*(byte *)((int)puVar2 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)((int)puVar2 + 0xd) * 2] + -1;
    sub_08002666((int)puVar2);
    sub_08002556(0,1);
    sub_08002896();
  }
  sub_08008D14(&DAT_02029d94);
  sub_08008D8A(0x2029d94);
  sub_08005478(3,local_24);
  return;
}


/* sub_0800536C @ 0x0800536C */

void sub_0800536C(int param_1,undefined1 param_2)

{
  (&DAT_03000076)[param_1] = param_2;
  sub_080051D0(param_1,&DAT_03000076 + param_1);
  return;
}


/* sub_08005380 @ 0x08005380 */

void sub_08005380(void)

{
  sub_08008D8A(0x2029d94);
  return;
}


/* sub_0800538A @ 0x0800538A */

void sub_0800538A(void)

{
  sub_08002896();
  return;
}


/* sub_08005392 @ 0x08005392 */

bool sub_08005392(void)

{
  sub_08009328(&DAT_02029d94,0x80051b5);
  return DAT_02029da8 == 0;
}


/* sub_080053F0 @ 0x080053F0 */

void sub_080053F0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  DAT_0300087c = 0;
  uVar6 = 0;
  do {
    iVar5 = (&gUnknown_085439E0)[uVar6];
    iVar4 = 0;
    if (0 < *(int *)(iVar5 + 4)) {
      do {
        piVar3 = *(int **)(*(int *)(iVar5 + 8) + iVar4 * 4);
        __call_via_r1(piVar3,*(undefined **)(*piVar3 + 8));
        if ((*(int *)*piVar3 != 0) &&
           (iVar2 = __call_via_r1(piVar3,(undefined *)((int *)*piVar3)[1]), iVar2 != 0)) {
          puVar1 = &DAT_03000880 + DAT_0300087c;
          DAT_0300087c = DAT_0300087c + 1;
          *puVar1 = piVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar5 + 4));
    }
    if (((&DAT_03000038)[(int)uVar6 >> 3] & (byte)(1 << (uVar6 & 7))) != 0) {
      sub_08004D34(iVar5);
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0x4b);
  return;
}


/* sub_08005478 @ 0x08005478 */

undefined4 sub_08005478(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_0300087c) {
    do {
      iVar1 = __call_via_r3();
      if (iVar1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0300087c);
  }
  return 0;
}


/* sub_080054AE @ 0x080054AE */

void sub_080054AE(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  do {
    iVar4 = (int)uVar3 >> 3;
    bVar1 = (byte)(1 << (uVar3 & 7));
    if (((&DAT_03000038)[iVar4] & bVar1) == 0) {
      iVar2 = sub_08004C5C((&gUnknown_085439E0)[uVar3]);
      if (iVar2 != 0) {
        (&DAT_03000038)[iVar4] = (&DAT_03000038)[iVar4] | bVar1;
        sub_08004D10((&gUnknown_085439E0)[uVar3]);
        iVar4 = 0;
        if (0 < DAT_0300087c) {
          do {
            iVar2 = __call_via_r3();
            if (iVar2 != 0) {
              return;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_0300087c);
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x4b);
  return;
}


/* sub_08005526 @ 0x08005526 */

void sub_08005526(uint param_1)

{
  (&DAT_03000028)[(int)param_1 >> 3] =
       (byte)(1 << (param_1 & 7)) | (&DAT_03000028)[(int)param_1 >> 3];
  sub_080054AE();
  return;
}


/* sub_08005542 @ 0x08005542 */

void sub_08005542(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  *param_1 = 0;
  do {
    iVar2 = *(int *)(&gUnknown_085439E0)[uVar1];
    if (iVar2 != 0) {
      if (((&DAT_03000038)[(int)uVar1 >> 3] & (byte)(1 << (uVar1 & 7))) != 0) {
        iVar3 = *param_1;
        *param_1 = iVar3 + 1;
        param_1[iVar3 + 1] = iVar2;
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x4b);
  return;
}


/* sub_080055A0 @ 0x080055A0 */

undefined4 sub_080055A0(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) &&
     (iVar1 = sub_08004CAC((&gUnknown_085439E0)[*(byte *)(param_1 + 6)]), iVar1 != 0)) {
    return 1;
  }
  return 0;
}


/* sub_080055C4 @ 0x080055C4 */

void sub_080055C4(void)

{
  return;
}


/* sub_080055C6 @ 0x080055C6 */

undefined4 sub_080055C6(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == 4) && (*(byte *)(param_1 + 6) == param_3)) {
    sub_08005526((uint)*(byte *)(param_1 + 4));
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* sub_080055E4 @ 0x080055E4 */

void sub_080055E4(void)

{
  return;
}


/* sub_080055E6 @ 0x080055E6 */

void sub_080055E6(int param_1)

{
  sub_08001FA8(*(int *)(param_1 + 4),(undefined4 *)(param_1 + 8));
  return;
}


/* sub_080055E8 @ 0x080055E8 */

void sub_080055E8(int param_1,int param_2)

{
  sub_08001FA8(*(int *)(param_1 + 4),(undefined4 *)(param_2 + 8));
  return;
}


/* sub_080055F4 @ 0x080055F4 */

void sub_080055F4(void)

{
  return;
}


/* sub_080055F6 @ 0x080055F6 */

void sub_080055F6(int param_1)

{
  sub_0800536C((uint)*(byte *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  return;
}


/* sub_08005602 @ 0x08005602 */

undefined2 sub_08005602(int param_1,int param_2,short *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short sStack_20;
  short sStack_1e;
  short sStack_1c;
  short sStack_1a;
  undefined4 uStack_18;
  
  if (param_2 == 0) {
    iVar3 = *(int *)(param_1 + 0x3c);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      return 0;
    }
    sub_08002396(&sStack_20,param_1);
    uVar1 = sub_08003446();
    iVar2 = DAT_030007b8;
    uStack_18._0_2_ = (short)uVar1;
    if (((sStack_20 <= (short)uStack_18) && ((short)uStack_18 < sStack_1c)) &&
       ((uStack_18._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_1e <= uStack_18._2_2_ &&
        (uStack_18._2_2_ < sStack_1a)))) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      uStack_18 = uVar1;
      sub_08002466(iVar2,3 - ((DAT_03003b6c << 0x1f) >> 0x1f));
      iVar2 = sub_0800A714(0x80);
      sub_08007416(*(int *)(DAT_030007b8 + 0x3c),iVar3,0,(uint)((iVar2 + 0x180) * DAT_030007cc) >> 9
                  );
      return 1;
    }
  }
  else if (param_2 == 1) {
    iVar3 = *(int *)(param_1 + 0x3c);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 6) != 0) {
      return 0;
    }
    sub_08002396(&sStack_1c,param_1);
    if ((((sStack_1c < param_3[2]) && (*param_3 < (short)uStack_18)) && (sStack_1a < param_3[3])) &&
       (param_3[1] < uStack_18._2_2_)) {
      if (((char)param_3[8] == '\0') || (*(short *)(iVar3 + 0x14) < 1)) {
        sub_08007416(*(int *)(param_3 + 10),iVar3,1,*(int *)(param_3 + 4));
      }
      return 1;
    }
  }
  else if (param_2 == 5) {
    sub_0800236E((undefined4 *)&sStack_1c,param_1);
    sub_0800507A(DAT_03000600,&sStack_1c,1,0);
  }
  else if (param_2 == 3) {
    return 1;
  }
  return 0;
}


/* sub_08005604 @ 0x08005604 */

undefined2 sub_08005604(int param_1,int param_2,short *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short sStack_20;
  short sStack_1e;
  short sStack_1c;
  short sStack_1a;
  undefined4 uStack_18;
  
  if (param_2 == 0) {
    iVar3 = *(int *)(param_1 + 0x3c);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      return 0;
    }
    sub_08002396(&sStack_20,param_1);
    uVar1 = sub_08003446();
    iVar2 = DAT_030007b8;
    uStack_18._0_2_ = (short)uVar1;
    if (((sStack_20 <= (short)uStack_18) && ((short)uStack_18 < sStack_1c)) &&
       ((uStack_18._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_1e <= uStack_18._2_2_ &&
        (uStack_18._2_2_ < sStack_1a)))) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      uStack_18 = uVar1;
      sub_08002466(iVar2,3 - ((DAT_03003b6c << 0x1f) >> 0x1f));
      iVar2 = sub_0800A714(0x80);
      sub_08007416(*(int *)(DAT_030007b8 + 0x3c),iVar3,0,(uint)((iVar2 + 0x180) * DAT_030007cc) >> 9
                  );
      return 1;
    }
  }
  else if (param_2 == 1) {
    iVar3 = *(int *)(param_1 + 0x3c);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 6) != 0) {
      return 0;
    }
    sub_08002396(&sStack_1c,param_1);
    if ((((sStack_1c < param_3[2]) && (*param_3 < (short)uStack_18)) && (sStack_1a < param_3[3])) &&
       (param_3[1] < uStack_18._2_2_)) {
      if (((char)param_3[8] == '\0') || (*(short *)(iVar3 + 0x14) < 1)) {
        sub_08007416(*(int *)(param_3 + 10),iVar3,1,*(int *)(param_3 + 4));
      }
      return 1;
    }
  }
  else if (param_2 == 5) {
    sub_0800236E((undefined4 *)&sStack_1c,param_1);
    sub_0800507A(DAT_03000600,&sStack_1c,1,0);
  }
  else if (param_2 == 3) {
    return 1;
  }
  return 0;
}


/* sub_0800573A @ 0x0800573A */

void sub_0800573A(int param_1)

{
  undefined2 *puVar1;
  short asStack_18 [4];
  
  sub_0800236E((undefined4 *)asStack_18,param_1);
  sub_0800507A(DAT_03000600,asStack_18,1,0);
  puVar1 = DAT_030046b4;
  DAT_030046b4 = DAT_030046b4 + 0x13c;
  sub_08006D90(puVar1,2,(uint)(byte)(&gUnknown_0815A69C)[*(byte *)(param_1 + 0x15)]);
  sub_080062C4(&DAT_030047f0,(int)puVar1,param_1);
  *(undefined2 **)(param_1 + 0x3c) = puVar1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  sub_08002486(param_1,(int)(&gUnknown_085C0C80)
                            [(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 0x15)]],
               &gUnknown_081667F0,0);
  *(undefined4 *)(param_1 + 0x38) = 0x8005605;
  sub_080085A0((int)puVar1,(short *)(param_1 + 0x20));
  return;
}


/* sub_080057A8 @ 0x080057A8 */

undefined4 sub_080057A8(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  short asStack_20 [4];
  short sStack_18;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  undefined4 local_10;
  
  if (param_2 == 0) {
    sub_0800236E((undefined4 *)asStack_20,param_1);
    sub_0800994C(&sStack_18,asStack_20,2);
    uVar1 = sub_08003398();
    local_10._0_2_ = (short)uVar1;
    if ((((sStack_18 <= (short)local_10) && ((short)local_10 < sStack_14)) &&
        (local_10._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_16 <= local_10._2_2_)) &&
       (local_10._2_2_ < sStack_12)) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      local_10 = uVar1;
      iVar2 = sub_08005478(0,(uint)*(byte *)(param_1 + 0x15));
      if (iVar2 != 0) {
        return 1;
      }
      sub_080051D0((uint)*(byte *)(param_1 + 0x16),&DAT_03000076 + *(byte *)(param_1 + 0x16));
      return 1;
    }
  }
  else if ((param_2 == 2) && (*(byte *)(param_1 + 0x15) == param_3)) {
    sub_0800573A(param_1);
  }
  return 0;
}


/* sub_08005840 @ 0x08005840 */

undefined4 sub_08005840(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  short asStack_20 [4];
  short sStack_18;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  undefined4 local_10;
  
  if (param_2 == 0) {
    sub_0800236E((undefined4 *)asStack_20,param_1);
    sub_0800994C(&sStack_18,asStack_20,2);
    uVar1 = sub_08003398();
    local_10._0_2_ = (short)uVar1;
    if ((((sStack_18 <= (short)local_10) && ((short)local_10 < sStack_14)) &&
        (local_10._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_16 <= local_10._2_2_)) &&
       (local_10._2_2_ < sStack_12)) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      local_10 = uVar1;
      iVar2 = sub_08005478(0,(uint)*(byte *)(param_1 + 0x15));
      if (iVar2 != 0) {
        return 1;
      }
      sub_080051D0((uint)*(byte *)(param_1 + 0x16),(byte *)(param_1 + 0x14));
      return 1;
    }
  }
  else if ((param_2 == 2) && (*(byte *)(param_1 + 0x15) == param_3)) {
    sub_0800573A(param_1);
  }
  return 0;
}


/* sub_080058D6 @ 0x080058D6 */

int sub_080058D6(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)(byte)(&gUnknown_08543988)[(ushort)param_1[3]];
  if (*(char *)((int)param_1 + 5) == '\x01') {
    uVar2 = (uint)((&DAT_03000038)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7)));
    if (uVar2 != 0) {
      return 0;
    }
  }
  else if ((*(char *)((int)param_1 + 5) == '\x02') &&
          (uVar2 = (uint)((&DAT_03000038)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))), uVar2 == 0))
  {
    return 0;
  }
  iVar3 = sub_08002716(uVar2);
  *(undefined2 *)(iVar3 + 0x20) = *param_1;
  *(undefined2 *)(iVar3 + 0x22) = param_1[1];
  *(undefined1 *)(iVar3 + 0x15) = *(undefined1 *)(param_1 + 2);
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\0') {
    sub_08002486(iVar3,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 2)]]
                 ,&gUnknown_085C2614,0);
    *(undefined1 *)(iVar3 + 0x16) = *(undefined1 *)((int)param_1 + 9);
    *(undefined1 *)(iVar3 + 0x14) = *(undefined1 *)(param_1 + 5);
    *(undefined4 *)(iVar3 + 0x38) = 0x8005841;
  }
  else if (cVar1 == '\x01') {
    sub_08002486(iVar3,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 2)]]
                 ,&gUnknown_085C2614,0);
    *(undefined1 *)(iVar3 + 0x16) = *(undefined1 *)((int)param_1 + 9);
    *(undefined4 *)(iVar3 + 0x38) = 0x80057a9;
  }
  else if (cVar1 == '\x02') {
    sub_0800573A(iVar3);
  }
  return iVar3;
}


/* sub_0800599A @ 0x0800599A */

undefined4 sub_0800599A(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  short asStack_24 [4];
  short sStack_1c;
  short sStack_1a;
  short sStack_18;
  short sStack_16;
  undefined4 local_14;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(param_1 + 0x3c);
    sub_0800236E((undefined4 *)asStack_24,param_1);
    sub_0800994C(&sStack_1c,asStack_24,2);
    uVar1 = sub_08003398();
    local_14._0_2_ = (short)uVar1;
    if ((((sStack_1c <= (short)local_14) && ((short)local_14 < sStack_18)) &&
        (local_14._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_1a <= local_14._2_2_)) &&
       (local_14._2_2_ < sStack_16)) {
      *(byte *)(param_1 + 0x13) = *(byte *)(DAT_030007b8 + 0x13) ^ 1;
      local_14 = uVar1;
      if (DAT_030007b0 != '\0') {
        sub_0800536C((uint)*(byte *)(iVar2 + 7),*(undefined1 *)(iVar2 + 9));
        return 1;
      }
      sub_0800536C((uint)*(byte *)(iVar2 + 7),*(undefined1 *)(iVar2 + 8));
      sub_08005526((uint)*(byte *)(iVar2 + 4));
      sub_0800236E((undefined4 *)&sStack_18,param_1);
      sub_0800507A(DAT_03000600,&sStack_18,1,0);
      *(undefined4 *)(param_1 + 0x38) = 0x8002553;
      sub_08002FC4((uint)*(byte *)(iVar2 + 6),param_1);
      return 1;
    }
  }
  return 0;
}


/* sub_08005A94 @ 0x08005A94 */

void sub_08005A94(int param_1)

{
  int iVar1;
  short asStack_18 [4];
  
  iVar1 = sub_08002716(param_1);
  *(undefined2 *)(iVar1 + 0x20) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_1 + 0xc);
  *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 6);
  sub_08002486(iVar1,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)]],
               &gUnknown_08011494,0);
  *(undefined4 *)(iVar1 + 0x38) = 0x800599b;
  *(int *)(iVar1 + 0x3c) = param_1;
  sub_0800236E((undefined4 *)asStack_18,iVar1);
  sub_0800507A(DAT_03000600,asStack_18,0,0);
  return;
}


/* sub_08005AE4 @ 0x08005AE4 */

void sub_08005AE4(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08002716(param_1);
  sub_08002486(iVar1,(int)(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 6)]],
               &gUnknown_085C2614,0);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_1 + 0xc);
  *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)(iVar1 + 0x16) = *(undefined1 *)(param_1 + 10);
  *(undefined4 *)(iVar1 + 0x38) = 0x80057a9;
  return;
}


/* sub_08005B38 @ 0x08005B38 */

void sub_08005B38(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  __call_via_r1(param_1,(undefined *)(*(int *)(*param_1 + 0x18) + *param_1));
  DAT_03000980 = (uint)*(byte *)(DAT_03000604 + 1) + DAT_03000980;
  uVar1 = 0;
  iVar2 = (uint)*(ushort *)(DAT_03000604 + 2) * 0x40 + 0x6000000;
  if (*(short *)(DAT_03000604 + 4) != 0) {
    do {
      REG_DMA3SAD = &DAT_0200a824 +
                    ((uVar1 & ~(uint)*(byte *)(DAT_03000604 + 7)) +
                    (uVar1 + (DAT_03000980 >> 6) & (uint)*(byte *)(DAT_03000604 + 7))) * 0x40;
      REG_DMA3DAD = iVar2;
      Ram040000dc = 0x10;
      DAT_040000de = 0x8400;
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x40;
    } while ((int)uVar1 < (int)(uint)*(ushort *)(DAT_03000604 + 4));
  }
  __call_via_r1(param_1,(undefined *)(*(int *)(*param_1 + 0x1c) + *param_1));
  return;
}


/* sub_08005BB4 @ 0x08005BB4 */

int sub_08005BB4(void)

{
  return DAT_03000988 + 1;
}


/* sub_08005BBC @ 0x08005BBC */

void sub_08005BBC(void)

{
  undefined1 auStack_48 [64];
  
  sub_08008CE8(auStack_48,"You reached level %d!",DAT_03000988 + 1);
  sub_0800ACFE(6);
  sub_08004E98(0x3000864,(int)auStack_48);
  return;
}


/* sub_08005BE2 @ 0x08005BE2 */

undefined4 sub_08005BE2(void)

{
  return *(undefined4 *)(&DAT_080114ac + DAT_03000988 * 0x10);
}


/* sub_08005BF0 @ 0x08005BF0 */

undefined4 sub_08005BF0(void)

{
  return *(undefined4 *)(&DAT_080114b0 + DAT_03000988 * 0x10);
}


/* sub_08005BFE @ 0x08005BFE */

bool sub_08005BFE(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x50);
  iVar1 = DAT_03000988 * 0x10;
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(&DAT_080114b0 + iVar1);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(&DAT_080114ac + iVar1);
  sub_08006D70(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (*(int *)(param_1 + 0x50) - iVar2);
  return iVar2 < *(int *)(param_1 + 0x50);
}


/* sub_08005C32 @ 0x08005C32 */

void sub_08005C32(int param_1)

{
  DAT_03000984 = param_1;
  DAT_03000988 = 0;
  while( true ) {
    if ((param_1 < *(int *)(&gUnknown_080114A8 + DAT_03000988 * 0x10)) ||
       (*(int *)(&gUnknown_080114A8 + DAT_03000988 * 0x10) == 0)) break;
    DAT_03000988 = DAT_03000988 + 1;
  }
  DAT_03000988 = DAT_03000988 + -1;
  return;
}


/* sub_08005C5C @ 0x08005C5C */

undefined4 sub_08005C5C(void)

{
  return DAT_03000984;
}


/* sub_08005C62 @ 0x08005C62 */

int sub_08005C62(void)

{
  if (*(int *)(&DAT_080114b8 + DAT_03000988 * 0x10) == 0) {
    return 0;
  }
  return *(int *)(&DAT_080114b8 + DAT_03000988 * 0x10) - DAT_03000984;
}


/* sub_08005C7A @ 0x08005C7A */

undefined4 sub_08005C7A(void)

{
  return *(undefined4 *)(&DAT_080114b4 + DAT_03000988 * 0x10);
}


/* sub_08005C88 @ 0x08005C88 */

void sub_08005C88(undefined4 *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  *param_1 = 0;
  *param_2 = 0;
  iVar1 = (int)DAT_030005f6;
  *param_3 = DAT_030005f4 + -1;
  *param_4 = iVar1 + -1;
  return;
}


/* sub_08005CA8 @ 0x08005CA8 */

int sub_08005CA8(int param_1)

{
  DAT_0300098c = DAT_0300098c + 0x2cbbc71 ^ DAT_03000990;
  DAT_03000990 = (DAT_03000990 >> 0x1d | DAT_03000990 << 3) + 0x632d80f ^ DAT_0300098c;
  return (int)((DAT_03000990 * DAT_0300098c & 0xffff) * (param_1 + 1)) >> 0x10;
}


/* sub_08005CD6 @ 0x08005CD6 */

void sub_08005CD6(int param_1,int param_2,int param_3)

{
  sub_0800C010(*(int *)(param_1 + 0x274),param_2,param_3);
  return;
}


/* sub_08005D04 @ 0x08005D04 */

undefined4 sub_08005D04(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  short sStack_24;
  short sStack_22;
  short local_20;
  short local_1e;
  undefined4 local_1c;
  short local_18;
  short local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  if (param_2 == 0) {
    sub_08002300((undefined4 *)&local_20,param_1);
    local_18 = local_20;
    local_16 = local_1e;
    local_14 = (short)local_1c;
    local_12 = local_1c._2_2_;
    sub_0800994C(&sStack_24,&local_18,2);
    uVar1 = sub_08003398();
    local_1c._0_2_ = (short)uVar1;
    if ((((sStack_24 <= (short)local_1c) && ((short)local_1c < local_20)) &&
        (local_1c._2_2_ = (short)((uint)uVar1 >> 0x10), sStack_22 <= local_1c._2_2_)) &&
       (local_1c._2_2_ < local_1e)) {
      iVar3 = *(int *)(param_1 + 0x3c);
      local_1c = uVar1;
      sub_0800ACFE(7);
      uVar2 = (uint)*(byte *)(iVar3 + 6);
      __call_via_r2(param_1,uVar2,*(undefined **)(&DAT_085c2258 + uVar2 * 0x18));
      sub_08005526((uint)*(byte *)(iVar3 + 4));
      sub_0800507A(DAT_03000600,&local_18,1,0);
      return 1;
    }
  }
  return 0;
}


/* sub_08005DA6 @ 0x08005DA6 */

void sub_08005DA6(int param_1)

{
  int iVar1;
  short asStack_10 [4];
  
  iVar1 = sub_0800AEC6((undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 6));
  *(undefined4 *)(iVar1 + 0x38) = 0x8005d05;
  *(int *)(iVar1 + 0x3c) = param_1;
  sub_08002300((undefined4 *)asStack_10,iVar1);
  sub_0800507A(DAT_03000600,asStack_10,0,0);
  return;
}


/* sub_08005DE0 @ 0x08005DE0 */

void sub_08005DE0(int param_1)

{
  int iVar1;
  
  sub_08002910(param_1);
  iVar1 = *(int *)(param_1 + 0x3c);
  if (3 < *(byte *)(iVar1 + 9)) {
    if (*(byte *)(iVar1 + 9) == 6) {
      *(undefined1 *)(iVar1 + 10) = 0x14;
    }
    else {
      *(undefined1 *)(iVar1 + 10) = 0x2d;
    }
  }
  *(undefined1 *)(iVar1 + 9) = 0;
  return;
}


/* sub_08005E06 @ 0x08005E06 */

void sub_08005E06(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x20);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 8);
  return;
}


/* sub_08005E12 @ 0x08005E12 */

void sub_08005E12(int param_1)

{
  sub_08002930(param_1);
  sub_08005478(1,(uint)*(byte *)(param_1 + 0x15));
  return;
}


/* sub_08005E24 @ 0x08005E24 */

void sub_08005E24(void)

{
  return;
}


/* sub_08005E26 @ 0x08005E26 */

void sub_08005E26(int param_1)

{
  sub_08002C04(param_1);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 8);
  return;
}


/* sub_08005E36 @ 0x08005E36 */

void sub_08005E36(void)

{
  return;
}


/* sub_08005E38 @ 0x08005E38 */

void sub_08005E38(int param_1)

{
  sub_08003B28(param_1);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 8);
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_08005E4C @ 0x08005E4C */

void sub_08005E4C(int param_1)

{
  if ((*(int *)(param_1 + 0x24) == 2) && (0xf < *(byte *)(param_1 + 0x10))) {
    sub_08002466(param_1,0);
  }
  return;
}


/* sub_08005E62 @ 0x08005E62 */

void sub_08005E62(int param_1)

{
  byte bVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x10);
    if (bVar1 < 0x10) {
      *(char *)(param_1 + 0x12) = '\x01' - (char)((int)((uint)bVar1 << 0x1c) >> 0x1f);
      *(byte *)(param_1 + 0x10) = bVar1 + 1;
      return;
    }
  }
  return;
}


/* sub_08005E80 @ 0x08005E80 */

void sub_08005E80(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x20);
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(*(int *)(param_1 + 0x3c) + 8);
  return;
}


/* sub_08005E8C @ 0x08005E8C */

void sub_08005E8C(void)

{
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3000994;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8500;
  return;
}


/* sub_08005EA6 @ 0x08005EA6 */

int sub_08005EA6(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar4 = iVar2;
    if ((&DAT_03000994)[iVar2 * 2] != 0) {
      iVar1 = 1;
      while (iVar4 = iVar3,
            *(short *)(param_1 + iVar1 * 2) == *(short *)((&DAT_03000998)[iVar2 * 2] + iVar1 * 2)) {
        iVar1 = iVar1 + 1;
        if (0xf < iVar1) {
          (&DAT_03000994)[iVar2 * 2] = (&DAT_03000994)[iVar2 * 2] + 1;
          return iVar2;
        }
      }
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar4;
  } while (iVar2 < 0x10);
  (&DAT_03000994)[iVar4 * 2] = (&DAT_03000994)[iVar4 * 2] + 1;
  (&DAT_03000998)[iVar4 * 2] = param_1;
  REG_DMA3SAD = param_1;
  REG_DMA3DAD = &DAT_05000200 + iVar4 * 0x20;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  return iVar4;
}


/* sub_08005F14 @ 0x08005F14 */

int sub_08005F14(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_03000994)[iVar2 * 2] != 0) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return iVar1;
}


/* sub_08005F2C @ 0x08005F2C */

void sub_08005F2C(undefined4 param_1)

{
  REG_DMA3SAD = 0x3000994;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3000994;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8500;
  return;
}


/* sub_08005F58 @ 0x08005F58 */

void sub_08005F58(undefined4 param_1)

{
  int iVar1;
  
  REG_DMA3SAD = param_1;
  REG_DMA3DAD = 0x3000994;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  iVar1 = 0;
  do {
    if ((&DAT_03000994)[iVar1 * 2] != 0) {
      REG_DMA3SAD = (&DAT_03000998)[iVar1 * 2];
      REG_DMA3DAD = &DAT_05000200 + iVar1 * 0x20;
      Ram040000dc = 0x10;
      DAT_040000de = 0x8000;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return;
}


/* sub_08005FAC @ 0x08005FAC */

void sub_08005FAC(void)

{
  return;
}


/* sub_08005FAE @ 0x08005FAE */

void sub_08005FAE(int param_1)

{
  (&DAT_03000076)[*(byte *)(param_1 + 4)] = *(undefined1 *)(param_1 + 5);
  return;
}


/* sub_08005FC0 @ 0x08005FC0 */

undefined4 sub_08005FC0(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08005FE0 @ 0x08005FE0 */

void sub_08005FE0(void)

{
  return;
}


/* sub_08005FE2 @ 0x08005FE2 */

undefined4 sub_08005FE2(int param_1,int param_2,char *param_3)

{
  int iVar1;
  
  if ((((param_2 == 3) && (*(char *)(param_1 + 6) == *param_3)) &&
      ((ushort)*(byte *)(param_1 + 7) == *(ushort *)(param_3 + 2))) &&
     (iVar1 = sub_08000954(param_1), iVar1 == 0)) {
    sub_08005526((uint)*(byte *)(param_1 + 4));
    return 1;
  }
  return 0;
}


/* sub_08006018 @ 0x08006018 */

undefined4 sub_08006018(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08006038 @ 0x08006038 */

void sub_08006038(int param_1)

{
  if (*(char *)(param_1 + 5) == DAT_030005fc) {
    sub_0800640C(param_1);
  }
  return;
}


/* sub_0800604C @ 0x0800604C */

undefined4 sub_0800604C(void)

{
  return 0;
}


/* sub_08006054 @ 0x08006054 */

undefined4 sub_08006054(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08006074 @ 0x08006074 */

void sub_08006074(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    sub_080060E6(param_1 + 8);
  }
  return;
}


/* sub_08006096 @ 0x08006096 */

undefined4 sub_08006096(void)

{
  return 0;
}


/* sub_080060A0 @ 0x080060A0 */

void sub_080060A0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_03000a14) {
    do {
      if ((&DAT_03000a18)[iVar2] == param_1) goto _080060C0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_03000a14);
  }
  iVar2 = -1;
_080060C0:
  DAT_03000a14 = DAT_03000a14 + -1;
  iVar1 = DAT_03000a14 - iVar2;
  if (iVar1 != 0) {
    REG_DMA3SAD = &DAT_03000a1c + iVar2;
    REG_DMA3DAD = &DAT_03000a18 + iVar2;
    Ram040000dc = (short)iVar1;
    DAT_040000de = 0x8400;
  }
  return;
}


/* sub_080060E6 @ 0x080060E6 */

void sub_080060E6(undefined4 param_1)

{
  if (DAT_03000a14 != 0) {
    REG_DMA3SAD = &DAT_03000a14 + DAT_03000a14;
    REG_DMA3DAD = &DAT_03000a18 + DAT_03000a14;
    Ram040000dc = (short)(DAT_03000a14 * 4 >> 2);
    DAT_040000de = 0x84a0;
  }
  DAT_03000a18 = param_1;
  DAT_03000a14 = DAT_03000a14 + 1;
  return;
}


/* sub_08006118 @ 0x08006118 */

void sub_08006118(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  
  sub_08002E42((undefined4 *)&local_24);
  local_1c = local_24;
  local_1a = local_22;
  local_18 = local_20;
  local_16 = local_1e;
  if (DAT_030007dc == 0) {
    bVar4 = 1;
  }
  else {
    bVar4 = 2;
  }
  iVar3 = 0;
  if (0 < DAT_03000a14) {
    do {
      puVar1 = (undefined4 *)(&DAT_03000a18)[iVar3];
      if (((((*(byte *)(puVar1 + 3) & bVar4) != 0) && (*(short *)(puVar1 + 1) <= local_1c)) &&
          (*(short *)((int)puVar1 + 6) <= local_1a)) &&
         (((local_18 <= *(short *)(puVar1 + 2) && (local_16 <= *(short *)((int)puVar1 + 10))) &&
          (iVar2 = __call_via_r1(puVar1,(undefined *)*puVar1), iVar2 != 0)))) {
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_03000a14);
  }
  return;
}


/* sub_080061B0 @ 0x080061B0 */

undefined4 sub_080061B0(int param_1)

{
  byte local_c [4];
  
  local_c[0] = *(byte *)(param_1 + 0xe);
  sub_080051D0((uint)*(byte *)(param_1 + 0xd),local_c);
  sub_080060A0(param_1);
  return 1;
}


/* sub_080061D0 @ 0x080061D0 */

undefined4 sub_080061D0(int param_1)

{
  sub_08004E98(0x3000864,*(int *)(param_1 + 0x10));
  sub_080060A0(param_1);
  return 1;
}


/* sub_080061EC @ 0x080061EC */

void sub_080061EC(int param_1)

{
  if (*(char *)(param_1 + 0xc) == DAT_030005fc) {
    sub_0800507A(DAT_03000600,(short *)(param_1 + 4),1,0);
  }
  return;
}


/* sub_08006214 @ 0x08006214 */

void sub_08006214(void)

{
  return;
}


/* sub_08006216 @ 0x08006216 */

void sub_08006216(int param_1)

{
  DAT_0300004d = DAT_0300004d | (byte)(1 << *(sbyte *)(param_1 + 4));
  return;
}


/* sub_0800622C @ 0x0800622C */

void sub_0800622C(void)

{
  return;
}


/* sub_0800622E @ 0x0800622E */

void sub_0800622E(int param_1)

{
  sub_0800C42E((int *)(&gUnknown_0815A778 + (uint)*(byte *)(param_1 + 4) * 8));
  return;
}


/* sub_08006244 @ 0x08006244 */

undefined4 sub_08006244(int param_1)

{
  sub_080060A0(param_1);
  sub_08005526((uint)*(byte *)(param_1 + 0xd));
  return 1;
}


/* sub_08006256 @ 0x08006256 */

undefined4 sub_08006256(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08006258 @ 0x08006258 */

undefined4 sub_08006258(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_08006278 @ 0x08006278 */

void sub_08006278(int param_1)

{
  if (*(char *)(param_1 + 5) == DAT_030005fc) {
    sub_0800B18E(param_1);
  }
  return;
}


/* sub_0800628C @ 0x0800628C */

undefined4 sub_0800628C(void)

{
  return 0;
}


/* sub_08006294 @ 0x08006294 */

void sub_08006294(int *param_1,int param_2)

{
  if (param_1[1] == 0) {
    param_1[1] = param_2;
    param_1[2] = param_2;
    *(undefined4 *)(param_2 + 0xa4) = 0;
    *(undefined4 *)(param_2 + 0xa0) = 0;
  }
  else {
    *(int *)(param_2 + 0xa4) = param_1[2];
    *(undefined4 *)(param_2 + 0xa0) = 0;
    *(int *)(param_1[2] + 0xa0) = param_2;
    param_1[2] = param_2;
  }
  *param_1 = *param_1 + 1;
  return;
}


/* sub_080062C4 @ 0x080062C4 */

void sub_080062C4(int *param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x274) = param_3;
  if (param_1[1] == 0) {
    param_1[1] = param_2;
    param_1[2] = param_2;
    *(undefined4 *)(param_2 + 0xa4) = 0;
    *(undefined4 *)(param_2 + 0xa0) = 0;
  }
  else {
    *(int *)(param_2 + 0xa4) = param_1[2];
    *(undefined4 *)(param_2 + 0xa0) = 0;
    *(int *)(param_1[2] + 0xa0) = param_2;
    param_1[2] = param_2;
  }
  *param_1 = *param_1 + 1;
  return;
}


/* sub_080062FC @ 0x080062FC */

void sub_080062FC(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 0xa0) == 0) {
    param_1[2] = *(int *)(param_2 + 0xa4);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0xa0) + 0xa4) = *(undefined4 *)(param_2 + 0xa4);
  }
  if (*(int *)(param_2 + 0xa4) == 0) {
    param_1[1] = *(int *)(param_2 + 0xa0);
  }
  else {
    *(undefined4 *)(*(int *)(param_2 + 0xa4) + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  }
  *(undefined4 *)(param_2 + 0xa4) = 0;
  *(undefined4 *)(param_2 + 0xa0) = 0;
  *param_1 = *param_1 + -1;
  return;
}


/* sub_08006330 @ 0x08006330 */

void sub_08006330(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x14) = param_2;
  sub_0800245A(param_1,&gUnknown_08011648);
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) - (*(short *)(param_1 + 4) >> 1);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) - (*(short *)(param_1 + 6) >> 1);
  return;
}


/* sub_0800636C @ 0x0800636C */

undefined4 sub_0800636C(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short local_14;
  short sStack_12;
  
  if (param_2 == 0) {
    iVar3 = *(int *)(param_1 + 0x3c);
    uVar1 = sub_08003398();
    local_14 = (short)uVar1;
    if ((((*(short *)(iVar3 + 8) <= local_14) && (local_14 < *(short *)(iVar3 + 0xc))) &&
        (sStack_12 = (short)((uint)uVar1 >> 0x10), *(short *)(iVar3 + 10) <= sStack_12)) &&
       (sStack_12 < *(short *)(iVar3 + 0xe))) {
      iVar2 = 0;
      do {
        if (((&gUnknown_081C7A84)[iVar2] == *(char *)(iVar3 + 6)) &&
           ((&DAT_0300004e)[iVar2] != '\0')) {
          *(undefined4 *)(param_1 + 0x38) = 0x8002553;
          (&DAT_03000070)[*(byte *)(iVar3 + 7)] = (char)iVar2;
          (&DAT_0300004e)[iVar2] = (&DAT_0300004e)[iVar2] + -1;
          sub_0800ACFE(7);
          sub_08006330(param_1,(char)iVar2);
          sub_08005526((uint)*(byte *)(iVar3 + 4));
          return 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x22);
    }
  }
  return 0;
}


/* sub_0800640C @ 0x0800640C */

void sub_0800640C(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  
  iVar1 = sub_08002716(param_1);
  local_18 = CONCAT22((short)(*(short *)(param_1 + 10) + *(short *)(param_1 + 0xe)) >> 1,
                      (short)(*(short *)(param_1 + 8) + *(short *)(param_1 + 0xc)) >> 1);
  *(undefined4 *)(iVar1 + 0x20) = local_18;
  *(int *)(iVar1 + 0x3c) = param_1;
  iVar2 = sub_08000954(param_1);
  if (iVar2 == 0) {
    sub_0800245A(iVar1,&gUnknown_08011648);
    *(undefined4 *)(iVar1 + 0x38) = 0x800636d;
  }
  else {
    sub_08006330(iVar1,(&DAT_03000070)[*(byte *)(param_1 + 7)]);
  }
  return;
}


/* sub_0800647C @ 0x0800647C */

void sub_0800647C(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(*(int *)(param_1 + 0x3c));
  if (iVar1 == 0) {
    return;
  }
  sub_0800AEFC((short *)param_1);
  return;
}


/* sub_080064A8 @ 0x080064A8 */

undefined4 sub_080064A8(int param_1)

{
  int iVar1;
  
  iVar1 = sub_08000954(param_1);
  if ((iVar1 == 0) && (*(char *)(param_1 + 5) == DAT_030005fc)) {
    return 1;
  }
  return 0;
}


/* sub_080064C8 @ 0x080064C8 */

void sub_080064C8(void)

{
  return;
}


/* sub_080064CA @ 0x080064CA */

undefined4 sub_080064CA(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (((param_2 == 0) && (*(byte *)(param_1 + 7) == param_3)) &&
     (iVar1 = sub_08000954(param_1), iVar1 == 0)) {
    iVar1 = 0;
    do {
      if (((&gUnknown_081C7A84)[iVar1] == *(char *)(param_1 + 6)) &&
         ((&DAT_0300004e)[iVar1] != '\0')) {
        (&DAT_0300004e)[iVar1] = (&DAT_0300004e)[iVar1] + -1;
        sub_0800ACFE(7);
        sub_0800536C((uint)*(byte *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
        sub_08005526((uint)*(byte *)(param_1 + 4));
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x22);
  }
  return 0;
}


/* sub_08006530 @ 0x08006530 */

void sub_08006530(int param_1)

{
  undefined4 local_18;
  undefined4 local_10;
  
  if (*(char *)(param_1 + 4) == DAT_030005fc) {
    local_18 = CONCAT22(*(short *)(param_1 + 0xe) + 8,*(short *)(param_1 + 0xc) + 0xf);
    local_10 = local_18;
    sub_0800AEC6(&local_10,*(undefined1 *)(param_1 + 5));
    sub_0800507A(DAT_03000600,(short *)(param_1 + 0xc),1,0);
    sub_080060E6(param_1 + 8);
  }
  return;
}


/* sub_0800658C @ 0x0800658C */

void sub_0800658C(int param_1)

{
  undefined1 uVar1;
  short local_18;
  short local_16;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  short local_c;
  short local_a;
  
  sub_08002910(param_1);
  uVar1 = sub_0800A714(0x80);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  sub_0800236E((undefined4 *)&local_18,param_1);
  local_10 = local_18;
  local_e = local_16;
  local_c = local_14;
  local_a = local_12;
  sub_08002E42((undefined4 *)&local_18);
  if ((((local_14 <= local_10) || (local_c <= local_18)) || (local_12 <= local_e)) ||
     (local_a <= local_16)) {
    sub_0800236E((undefined4 *)&local_18,param_1);
    sub_0800507A(DAT_03000600,&local_18,0,0);
  }
  return;
}


/* sub_0800660A @ 0x0800660A */

void sub_0800660A(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  short sVar5;
  short sVar6;
  short *psVar7;
  undefined4 uStack_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (((*(int *)(*(int *)(*(int *)(param_1 + 0x1c) + 0x28) + 0x10) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x18) + 0x14) != 0)) && (iVar2 = sub_0800A724(300), iVar2 != 0))
  {
    psVar7 = (short *)(param_1 + 0x2c);
    sub_0800236E(&local_1c,param_1);
    *psVar7 = (short)local_1c;
    *(short *)(param_1 + 0x2e) = local_1c._2_2_;
    *(short *)(param_1 + 0x30) = (short)local_18;
    *(short *)(param_1 + 0x32) = local_18._2_2_;
    iVar2 = sub_0800A714(4);
    puVar4 = (undefined2 *)(param_1 + 0x28);
    if (iVar2 == 0) {
      sVar6 = *(short *)(param_1 + 0x2e) + 8;
      uStack_2c = CONCAT22(sVar6,*psVar7);
      local_24 = uStack_2c;
      uVar1 = *(undefined2 *)(param_1 + 0x30);
      sVar5 = *(short *)(param_1 + 0x32) + 8;
      uStack_2c = CONCAT22(sVar5,uVar1);
      local_20 = uStack_2c;
      local_1c = CONCAT22(sVar6,*psVar7);
      local_18 = CONCAT22(sVar5,uVar1);
      *puVar4 = 0;
      *(undefined2 *)(param_1 + 0x2a) = 1;
    }
    else if (iVar2 == 1) {
      sVar5 = *(short *)(param_1 + 0x2e) + -8;
      uStack_2c = CONCAT22(sVar5,*psVar7);
      uVar1 = *(undefined2 *)(param_1 + 0x30);
      local_24 = uStack_2c;
      sVar6 = *(short *)(param_1 + 0x32) + -8;
      uStack_2c = CONCAT22(sVar6,uVar1);
      local_20 = uStack_2c;
      local_1c = CONCAT22(sVar5,*psVar7);
      local_18 = CONCAT22(sVar6,uVar1);
      *puVar4 = 0;
      *(undefined2 *)(param_1 + 0x2a) = 0xffff;
    }
    else if (iVar2 == 2) {
      local_20 = 8;
      local_24 = CONCAT22(*(undefined2 *)(param_1 + 0x2e),*psVar7 + -8);
      local_1c = local_24;
      local_18 = CONCAT22(*(undefined2 *)(param_1 + 0x32),*(undefined2 *)(param_1 + 0x2c));
      *puVar4 = 0xffff;
      *(undefined2 *)(param_1 + 0x2a) = 0;
    }
    else if (iVar2 == 3) {
      local_1c = CONCAT22(*(undefined2 *)(param_1 + 0x2e),*(undefined2 *)(param_1 + 0x30));
      local_20 = 8;
      local_24 = CONCAT22(*(undefined2 *)(param_1 + 0x32),*(short *)(param_1 + 0x30) + 8);
      local_18 = local_24;
      *puVar4 = 1;
      *(undefined2 *)(param_1 + 0x2a) = 0;
    }
    iVar3 = sub_08004FFA(DAT_03000600,(short *)&local_1c,0);
    if ((iVar3 != 0) &&
       (((sub_08002E42(&local_24), (short)local_18 <= (short)local_24 ||
         ((short)local_20 <= (short)local_1c)) ||
        ((local_18._2_2_ <= local_24._2_2_ || (local_20._2_2_ <= local_1c._2_2_)))))) {
      *(char *)(param_1 + 0x13) = (char)iVar2;
      sub_0800507A(DAT_03000600,(short *)&local_1c,0,0);
      sub_08002466(param_1,1);
    }
  }
  return;
}


/* sub_08006798 @ 0x08006798 */

void sub_08006798(int param_1)

{
  sub_080028FC(param_1);
  *(undefined4 *)(param_1 + 0x24) = 0x20;
  return;
}


/* sub_080067A6 @ 0x080067A6 */

void sub_080067A6(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = uVar1 - 1;
  if ((uVar1 & 3) == 0) {
    *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(param_1 + 0x28);
    *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(param_1 + 0x2a);
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    sub_0800507A(DAT_03000600,(short *)(param_1 + 0x2c),1,0);
    sub_08002466(param_1,0);
  }
  return;
}


