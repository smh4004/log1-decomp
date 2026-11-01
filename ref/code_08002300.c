/* Ghidra reference decompilation of code_08002300 (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_08002300 @ 0x08002300 */

void sub_08002300(undefined4 *param_1,int param_2)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(*(short *)(param_2 + 0x22) + *(short *)(param_2 + 6),
                     *(short *)(param_2 + 0x20) + *(short *)(param_2 + 4));
  *param_1 = *(undefined4 *)(param_2 + 0x20);
  param_1[1] = local_8;
  return;
}


/* sub_08002328 @ 0x08002328 */

void sub_08002328(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  short *psVar3;
  short sVar4;
  undefined4 local_c;
  
  psVar3 = (short *)**(undefined4 **)(param_2 + 8);
  sVar4 = *(short *)(param_2 + 0x20) + *psVar3;
  sVar2 = *(short *)(param_2 + 0x22) + psVar3[1];
  local_c = CONCAT22(sVar2,sVar4);
  uVar1 = local_c;
  local_c = CONCAT22(sVar2 + psVar3[3],sVar4 + psVar3[2]);
  *param_1 = uVar1;
  param_1[1] = local_c;
  return;
}


/* sub_0800236E @ 0x0800236E */

void sub_0800236E(undefined4 *param_1,int param_2)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(*(short *)(param_2 + 0x22) + (*(short **)(param_2 + 0x1c))[1],
                     *(short *)(param_2 + 0x20) + **(short **)(param_2 + 0x1c));
  *param_1 = *(undefined4 *)(param_2 + 0x20);
  param_1[1] = local_8;
  return;
}


/* sub_08002396 @ 0x08002396 */

void sub_08002396(short *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  
  sVar1 = *(short *)(param_2 + 0x20);
  iVar6 = *(int *)(param_2 + 0x1c) + (uint)*(byte *)(param_2 + 0x13) * 8;
  sVar2 = *(short *)(param_2 + 0x22);
  sVar3 = *(short *)(iVar6 + 6);
  sVar4 = *(short *)(iVar6 + 8);
  sVar5 = *(short *)(iVar6 + 10);
  *param_1 = *(short *)(iVar6 + 4) + sVar1;
  param_1[1] = sVar3 + sVar2;
  param_1[2] = sVar4 + sVar1;
  param_1[3] = sVar5 + sVar2;
  return;
}


/* sub_080023EE @ 0x080023EE */

void sub_080023EE(int param_1,short *param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = CONCAT22(param_2[1] + (*(short **)(param_1 + 0x1c))[1],
                      *param_2 + **(short **)(param_1 + 0x1c));
  local_10 = *(undefined4 *)param_2;
  local_c = local_14;
  sub_08004FFA(DAT_03000600,&local_10);
  return;
}


/* sub_0800241E @ 0x0800241E */

int sub_0800241E(int param_1)

{
  return (*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x18)) * 0xccd >> 0x10;
}


/* sub_0800242C @ 0x0800242C */

void sub_0800242C(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x34);
  *(int *)(param_1 + 0x2c) = iVar1;
  *(int *)(param_1 + 0x34) = param_2 + ((*(int *)(param_1 + 0x34) - iVar1) * 0xccd >> 0x10) * 0x14;
  return;
}


/* sub_08002450 @ 0x08002450 */

void sub_08002450(int param_1)

{
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x2c);
  return;
}


/* sub_0800245A @ 0x0800245A */

void sub_0800245A(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 **)(param_1 + 0x34) = param_2;
  __call_via_r1(param_1,*param_2,param_3,param_4,param_4);
  return;
}


/* sub_08002466 @ 0x08002466 */

void sub_08002466(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + param_2 * 0x10;
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x18) + param_2 * 0x14);
  *(undefined4 **)(param_1 + 0x34) = puVar1;
  __call_via_r1(param_1,*puVar1,*(int *)(param_1 + 0x18),param_2 * 4,param_4);
  return;
}


/* sub_08002486 @ 0x08002486 */

void sub_08002486(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  
  *(int *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  uVar1 = sub_08005EA6(*(undefined4 *)(param_2 + 0x24));
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + param_4 * 0x10;
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x18) + param_4 * 0x14);
  *(undefined4 **)(param_1 + 0x34) = puVar2;
  __call_via_r1(param_1,*puVar2);
  return;
}


/* sub_080024B8 @ 0x080024B8 */

void sub_080024B8(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = sub_0800BEA8();
  uVar4 = *(byte *)(param_1 + 0xd) & 0xf;
  if (iVar2 != 0) {
    uVar4 = (uint)(*(byte *)(param_1 + 0xd) >> 4);
  }
  (&DAT_03000994)[uVar4 * 2] = (&DAT_03000994)[uVar4 * 2] + -1;
  if (param_3 == 0) {
    param_3 = *(int *)(param_1 + 0x18);
  }
  *(int *)(param_1 + 0x1c) = param_2;
  *(int *)(param_1 + 0x18) = param_3;
  uVar1 = sub_08005EA6(*(undefined4 *)(param_2 + 0x24));
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + param_4 * 0x10;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x18) + param_4 * 0x14);
  *(undefined4 **)(param_1 + 0x34) = puVar3;
  __call_via_r1(param_1,*puVar3);
  if (iVar2 != 0) {
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + 1;
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | *(byte *)(param_1 + 0xd) << 4;
  }
  return;
}


/* sub_0800252E @ 0x0800252E */

void sub_0800252E(void)

{
  DAT_03000610 = 0;
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = 0x30007a0;
  Ram040000dc = 6;
  DAT_040000de = 0x8100;
  sub_08005E8C();
  return;
}


/* sub_08002552 @ 0x08002552 */

undefined4 sub_08002552(void)

{
  return 0;
}


/* sub_08002556 @ 0x08002556 */

void sub_08002556(undefined2 param_1,undefined2 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1a0;
  int local_198;
  int local_194 [96];
  
  sub_080098DE();
  iVar6 = DAT_03000610;
  DAT_03000798 = &DAT_0200b024;
  local_198 = 0;
  iVar5 = 0;
  DAT_03000794 = param_1;
  DAT_03000796 = param_2;
  DAT_0300079c = param_1;
  DAT_0300079e = param_2;
  if (0 < DAT_03000610) {
    do {
      iVar7 = (&DAT_03000614)[iVar5];
      __call_via_r1(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0x34) + 8));
      iVar3 = __call_via_r1(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0x34) + 0xc));
      if (iVar3 != 0) {
        local_194[local_198] = iVar7;
        local_198 = local_198 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  iVar5 = local_198 + -1;
  local_1a0 = 0;
  iVar6 = iVar5;
  if (0 < iVar5) {
    do {
      iVar3 = 0;
      bVar2 = true;
      if (iVar6 < 1) break;
      do {
        iVar7 = local_194[iVar3];
        iVar4 = local_194[iVar3 + 1];
        if (*(byte *)(iVar7 + 0xc) == *(byte *)(iVar4 + 0xc)) {
          if ((int)*(short *)(iVar7 + 2) + (int)*(short *)(iVar7 + 6) <
              (int)*(short *)(iVar4 + 2) + (int)*(short *)(iVar4 + 6)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else if (*(byte *)(iVar4 + 0xc) < *(byte *)(iVar7 + 0xc)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_194[iVar3] = iVar4;
          local_194[iVar3 + 1] = iVar7;
          bVar2 = false;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar6);
      if (bVar2) break;
      local_1a0 = local_1a0 + 1;
      iVar6 = iVar6 + -1;
    } while (local_1a0 < iVar5);
  }
  iVar6 = 0;
  if (0 < local_198) {
    do {
      __call_via_r2(local_194[iVar6],&DAT_03000794,
                    *(undefined4 *)(*(int *)(local_194[iVar6] + 0x34) + 0x10));
      iVar6 = iVar6 + 1;
    } while (iVar6 < local_198);
  }
  return;
}


/* sub_08002666 @ 0x08002666 */

void sub_08002666(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_03000610) {
    do {
      if ((&DAT_03000614)[iVar1] == param_1) goto _08002688;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_03000610);
  }
  iVar1 = -1;
_08002688:
  DAT_03000610 = DAT_03000610 + -1;
  if (DAT_03000610 - iVar1 != 0) {
    REG_DMA3SAD = &DAT_03000618 + iVar1;
    REG_DMA3DAD = &DAT_03000614 + iVar1;
    Ram040000dc = (short)(DAT_03000610 - iVar1);
    DAT_040000de = 0x8400;
  }
  iVar1 = ((uint)(param_1 + -0x2003840 >> 0x1f) >> 0x1a) + param_1 + -0x2003840;
  (&DAT_030007a0)[iVar1 >> 9] = (&DAT_030007a0)[iVar1 >> 9] & ~(byte)(1 << (iVar1 >> 6 & 7U));
  return;
}


/* sub_080026DE @ 0x080026DE */

void sub_080026DE(int param_1)

{
  (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
       (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + -1;
  sub_08002666();
  return;
}


/* sub_080026F2 @ 0x080026F2 */

undefined4 sub_080026F2(void)

{
  return 0;
}


/* sub_080026F6 @ 0x080026F6 */

void sub_080026F6(void)

{
  return;
}


/* sub_080026F8 @ 0x080026F8 */

void sub_080026F8(void)

{
  int iVar1;
  
  for (iVar1 = DAT_03000610 + -1; -1 < iVar1; iVar1 = iVar1 + -1) {
    __call_via_r1((&DAT_03000614)[iVar1],
                  *(undefined4 *)(*(int *)((&DAT_03000614)[iVar1] + 0x34) + 4));
  }
  return;
}


/* sub_08002716 @ 0x08002716 */

void sub_08002716(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (((&DAT_030007a0)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))) == 0) {
      (&DAT_030007a0)[(int)uVar2 >> 3] = (&DAT_030007a0)[(int)uVar2 >> 3] | (byte)(1 << (uVar2 & 7))
      ;
      param_1 = uVar2 * 0x40 + 0x2003840;
      break;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x60);
  piVar1 = &DAT_03000614 + DAT_03000610;
  DAT_03000610 = DAT_03000610 + 1;
  *piVar1 = param_1;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8500;
  *(undefined4 *)(param_1 + 0x38) = 0x8002553;
  *(undefined1 *)(param_1 + 0x15) = 0xff;
  return;
}


/* sub_0800279E @ 0x0800279E */

undefined4 sub_0800279E(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = ((uint)(param_1 + -0x2003840 >> 0x1f) >> 0x1a) + param_1 + -0x2003840;
  uVar2 = iVar1 >> 6;
  if (((int)uVar2 < 0) || (0x60 < (int)uVar2)) {
    uVar3 = 0;
  }
  else if (((&DAT_030007a0)[iVar1 >> 9] & (byte)(1 << (uVar2 & 7))) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


/* sub_08002810 @ 0x08002810 */

undefined4 sub_08002810(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_03000610) {
    do {
      if (*(byte *)((&DAT_03000614)[iVar1] + 0x15) == param_1) {
        return (&DAT_03000614)[iVar1];
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_03000610);
  }
  return 0;
}


/* sub_0800283C @ 0x0800283C */

undefined4 sub_0800283C(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_03000610 + -1;
  while( true ) {
    if (iVar2 < 0) {
      return 0;
    }
    iVar1 = __call_via_r3((&DAT_03000614)[iVar2],param_1,param_2,
                          *(undefined4 *)((&DAT_03000614)[iVar2] + 0x38),param_4);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + -1;
  }
  return 1;
}


/* sub_0800286A @ 0x0800286A */

uint sub_0800286A(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (iVar2 = DAT_03000610 + -1; -1 < iVar2; iVar2 = iVar2 + -1) {
    uVar1 = __call_via_r3((&DAT_03000614)[iVar2],param_1,param_2,
                          *(undefined4 *)((&DAT_03000614)[iVar2] + 0x38),param_4);
    uVar3 = uVar3 | uVar1;
  }
  return uVar3;
}


/* sub_08002896 @ 0x08002896 */

void sub_08002896(void)

{
  sub_080098C6();
  if (DAT_03000798 + 0xfdff4fdcU != 0) {
    REG_DMA3SAD = 0x200b024;
    REG_DMA3DAD = (uint)DAT_0300079e * 0x20 + 0x6010000;
    Ram040000dc = (short)(DAT_03000798 + 0xfdff4fdcU >> 2);
    DAT_040000de = 0x8400;
  }
  return;
}


/* sub_080028C4 @ 0x080028C4 */

void sub_080028C4(int param_1)

{
  *(undefined ***)(param_1 + 0x34) = &gUnknown_0854298C;
  __call_via_r1(param_1,0x800aefb);
  *(undefined4 *)(param_1 + 0x38) = 0x8002553;
  return;
}


/* sub_080028FC @ 0x080028FC */

void sub_080028FC(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  return;
}


/* sub_08002902 @ 0x08002902 */

void sub_08002902(int param_1)

{
  *(byte *)(param_1 + 0x12) = (byte)(((uint)*(byte *)(param_1 + 0x10) << 0x1b) >> 0x1e);
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) + 1;
  return;
}


/* sub_08002910 @ 0x08002910 */

void sub_08002910(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  return;
}


/* sub_08002916 @ 0x08002916 */

void sub_08002916(int param_1)

{
  if ((*(byte *)(param_1 + 0x10) & 0x7f) < 0x71) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x12) = 1;
  }
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) + 1;
  return;
}


/* sub_08002930 @ 0x08002930 */

void sub_08002930(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x2f;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_0800293C @ 0x0800293C */

void sub_0800293C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x40) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    if (bVar1 == 0x3f) {
      sub_08005478(2,*(undefined1 *)(param_1 + 0x15),bVar1 >> 4,param_4,param_4);
    }
  }
  return;
}


/* sub_0800295E @ 0x0800295E */

void sub_0800295E(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08002960 @ 0x08002960 */

void sub_08002960(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_0800296C @ 0x0800296C */

void sub_0800296C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 3;
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  if (0x1f < (byte)(bVar1 + 1)) {
    sub_08002466(param_1,0);
    __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
  }
  return;
}


/* sub_08002996 @ 0x08002996 */

void sub_08002996(int param_1)

{
  sub_08002910();
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_08002998 @ 0x08002998 */

void sub_08002998(int param_1)

{
  sub_08002910();
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_080029A6 @ 0x080029A6 */

void sub_080029A6(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10) & 0x7f;
  if (bVar1 == 0x70) {
    if (((*(int *)(param_1 + 0x24) == 4) &&
        (*(int *)(*(int *)(*(int *)(param_1 + 0x1c) + 0x28) + 0xf0) != 0)) &&
       (*(int *)(*(int *)(param_1 + 0x18) + 300) != 0)) {
      sub_08002466(param_1,0xf);
    }
    else {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
  }
  else if (bVar1 < 0x71) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x12) = 1;
  }
  *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
  return;
}


/* sub_080029F8 @ 0x080029F8 */

void sub_080029F8(undefined4 param_1)

{
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c != 0) {
    sub_08002466(param_1,1);
  }
  sub_08002E80(param_1);
  return;
}


/* sub_08002A16 @ 0x08002A16 */

void sub_08002A16(undefined4 param_1)

{
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c == 0) {
    sub_08002466(param_1,0);
  }
  sub_08002E80(param_1);
  return;
}


/* sub_08002A34 @ 0x08002A34 */

void sub_08002A34(undefined4 param_1)

{
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c != 0) {
    sub_08002466(param_1,1);
  }
  sub_08002E80(param_1);
  return;
}


/* sub_08002A52 @ 0x08002A52 */

void sub_08002A52(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x10) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 2;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  sub_08002466(param_1,0);
  __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
  return;
}


/* sub_08002A7A @ 0x08002A7A */

void sub_08002A7A(int param_1)

{
  sub_08002C78();
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_08002A88 @ 0x08002A88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08002A88(int param_1)

{
  int iVar1;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  
  if ((int)((uint)DAT_03003d14 << 0x17) < 0) {
    sub_0800236E(auStack_18,param_1);
    iVar1 = sub_08004FFA(DAT_03000600,auStack_18,0);
    if (iVar1 == 0) {
      sub_0800ACFE(0x13);
      return;
    }
  }
  else {
    sub_08002CE0(param_1,2,1);
    if (((uint)DAT_03003d12 << 0x18) >> 0x1c == 0) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x24) + 1;
    *(int *)(param_1 + 0x24) = iVar1;
    if (iVar1 < 8) {
      return;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar1 = sub_08003290();
    if (iVar1 != 0) {
      return;
    }
    sub_0800236E(auStack_18,param_1);
    iVar1 = sub_08004FFA(DAT_03000600,auStack_18,0);
    if (iVar1 == 0) {
      DAT_030007c0 = _DAT_030007d4;
      DAT_030007c2 = DAT_030007d6;
      uStack_14 = CONCAT22(DAT_030007d6 >> 4,_DAT_030007d4 >> 4);
      *(undefined4 *)(param_1 + 0x20) = uStack_14;
      sub_08002328(auStack_18,param_1);
      sub_08002134(auStack_18);
      sub_0800BEB8(param_1);
      sub_0800ACFE(0x13);
    }
  }
  sub_080031E2();
  sub_08002466(param_1,1);
  iVar1 = DAT_030007bc;
  if (DAT_030007b0 != '\0') {
    *(undefined4 *)(DAT_030007bc + 0x20) = *(undefined4 *)(param_1 + 0x20);
    sub_08002466(iVar1,0);
  }
  return;
}


/* sub_08002B62 @ 0x08002B62 */

void sub_08002B62(void)

{
  sub_08002930();
  sub_0800ACFE(0xd);
  return;
}


/* sub_08002B70 @ 0x08002B70 */

void sub_08002B70(int param_1)

{
  if (*(int *)(param_1 + 0x24) == 0x80) {
    sub_08000F8C(&DAT_030000ec,&DAT_0300085c,&DAT_0300010c);
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return;
}


/* sub_08002B8C @ 0x08002B8C */

void sub_08002B8C(int param_1)

{
  sub_08003B28();
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_08002B9A @ 0x08002B9A */

void sub_08002B9A(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(int *)(param_1 + 0x24) == 2) && (0xf < *(byte *)(param_1 + 0x10))) {
    sub_08002466(param_1,0,param_3,param_4,param_4);
  }
  return;
}


/* sub_08002BB0 @ 0x08002BB0 */

void sub_08002BB0(int param_1)

{
  byte bVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    if (-1 < (int)((uint)DAT_03003d12 << 0x1e)) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
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


/* sub_08002C04 @ 0x08002C04 */

void sub_08002C04(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  sub_0800ACFE(2);
  return;
}


/* sub_08002C18 @ 0x08002C18 */

void sub_08002C18(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x10) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 2;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  sub_08002466(param_1,0);
  __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
  return;
}


/* sub_08002C40 @ 0x08002C40 */

void sub_08002C40(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08002C4C @ 0x08002C4C */

void sub_08002C4C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 4;
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  if (0x2f < (byte)(bVar1 + 1)) {
    sub_08002466(param_1,0);
    __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
  }
  return;
}


/* sub_08002C76 @ 0x08002C76 */

void sub_08002C76(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x18;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08002C78 @ 0x08002C78 */

void sub_08002C78(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x18;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08002C84 @ 0x08002C84 */

void sub_08002C84(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x18) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 3;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  *(char *)(param_1 + 0x12) = (char)((int)((uint)bVar1 << 0x1c) >> 0x1f) + '\x02';
  *(byte *)(param_1 + 0x10) = (bVar1 + 1 & 0x1f) + 0x20;
  return;
}


/* sub_08002CAA @ 0x08002CAA */

void sub_08002CAA(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08002CAC @ 0x08002CAC */

void sub_08002CAC(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08002CB8 @ 0x08002CB8 */

void sub_08002CB8(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x30) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  *(char *)(param_1 + 0x12) = (char)((int)((uint)bVar1 << 0x1b) >> 0x1f) + '\x04';
  *(byte *)(param_1 + 0x10) = (bVar1 + 1 & 0x3f) + 0x40;
  return;
}


/* sub_08002CDE @ 0x08002CDE */

void sub_08002CDE(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  short sStack_1c;
  short sStack_1a;
  
  param_2 = (uint)DAT_030007b2 * param_2;
  uVar3 = (uint)DAT_03003d12;
  if ((int)(uVar3 << 0x19) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 1;
    param_2 = DAT_030007c2 - param_2;
    if (param_2 < 0) {
      param_2 = 0;
    }
    sStack_1c = DAT_030007c0 >> 4;
    sStack_1a = (short)(param_2 >> 4);
    sub_0800F3C4(&sStack_1c,&gUnknown_08010840);
    iVar1 = sub_08004FFA(DAT_03000600,&sStack_1c,param_3);
    if (iVar1 != 0) {
      DAT_030007c2 = (short)param_2;
    }
  }
  else if ((int)(uVar3 << 0x18) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 0;
    iVar2 = (DAT_030005fa + -8) * 0x10;
    iVar1 = DAT_030007c2 + param_2;
    if (iVar2 < DAT_030007c2 + param_2) {
      iVar1 = iVar2;
    }
    sStack_1c = DAT_030007c0 >> 4;
    sStack_1a = (short)(iVar1 >> 4);
    sub_0800F3C4(&sStack_1c,&gUnknown_08010840);
    iVar2 = sub_08004FFA(DAT_03000600,&sStack_1c,param_3);
    if (iVar2 != 0) {
      DAT_030007c2 = (short)iVar1;
    }
  }
  else if ((int)(uVar3 << 0x1a) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 2;
    param_2 = DAT_030007c0 - param_2;
    if (param_2 < 0) {
      param_2 = 0;
    }
    sStack_1c = (short)(param_2 >> 4);
    sStack_1a = DAT_030007c2 >> 4;
    sub_0800F3C4(&sStack_1c,&gUnknown_08010840);
    iVar1 = sub_08004FFA(DAT_03000600,&sStack_1c,param_3);
    if (iVar1 != 0) {
      DAT_030007c0 = (short)param_2;
    }
  }
  else if ((int)(uVar3 << 0x1b) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 3;
    iVar2 = (DAT_030005f8 + -0x10) * 0x10;
    iVar1 = DAT_030007c0 + param_2;
    if (iVar2 < DAT_030007c0 + param_2) {
      iVar1 = iVar2;
    }
    sStack_1c = (short)(iVar1 >> 4);
    sStack_1a = DAT_030007c2 >> 4;
    sub_0800F3C4(&sStack_1c,&gUnknown_08010840);
    iVar2 = sub_08004FFA(DAT_03000600,&sStack_1c,param_3);
    if (iVar2 != 0) {
      DAT_030007c0 = (short)iVar1;
    }
  }
  if (((uint)DAT_03003d12 << 0x18) >> 0x1c != 0) {
    uStack_20 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
    *(undefined4 *)(param_1 + 0x20) = uStack_20;
    sub_08002328(auStack_24,param_1);
    sub_08002134(auStack_24);
  }
  return;
}


/* sub_08002CE0 @ 0x08002CE0 */

void sub_08002CE0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  short local_1c;
  short local_1a;
  
  param_2 = (uint)DAT_030007b2 * param_2;
  uVar3 = (uint)DAT_03003d12;
  if ((int)(uVar3 << 0x19) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 1;
    param_2 = DAT_030007c2 - param_2;
    if (param_2 < 0) {
      param_2 = 0;
    }
    local_1c = DAT_030007c0 >> 4;
    local_1a = (short)(param_2 >> 4);
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar1 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar1 != 0) {
      DAT_030007c2 = (short)param_2;
    }
  }
  else if ((int)(uVar3 << 0x18) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 0;
    iVar2 = (DAT_030005fa + -8) * 0x10;
    iVar1 = DAT_030007c2 + param_2;
    if (iVar2 < DAT_030007c2 + param_2) {
      iVar1 = iVar2;
    }
    local_1c = DAT_030007c0 >> 4;
    local_1a = (short)(iVar1 >> 4);
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar2 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar2 != 0) {
      DAT_030007c2 = (short)iVar1;
    }
  }
  else if ((int)(uVar3 << 0x1a) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 2;
    param_2 = DAT_030007c0 - param_2;
    if (param_2 < 0) {
      param_2 = 0;
    }
    local_1c = (short)(param_2 >> 4);
    local_1a = DAT_030007c2 >> 4;
    sub_0800F3C4(&local_1c,&gUnknown_08010840);
    iVar1 = sub_08004FFA(DAT_03000600,&local_1c,param_3);
    if (iVar1 != 0) {
      DAT_030007c0 = (short)param_2;
    }
  }
  else if ((int)(uVar3 << 0x1b) < 0) {
    *(undefined1 *)(param_1 + 0x13) = 3;
    iVar2 = (DAT_030005f8 + -0x10) * 0x10;
    iVar1 = DAT_030007c0 + param_2;
    if (iVar2 < DAT_030007c0 + param_2) {
      iVar1 = iVar2;
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
    sub_08002328(auStack_24,param_1);
    sub_08002134(auStack_24);
  }
  return;
}


/* sub_08002E30 @ 0x08002E30 */

void sub_08002E30(void)

{
  DAT_030007dc = 1;
  DAT_030007b4 = sub_0800ACFE(0x12);
  return;
}


/* sub_08002E42 @ 0x08002E42 */

void sub_08002E42(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  local_8 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  uVar1 = local_8;
  local_8 = CONCAT22((DAT_030007c2 >> 4) + 8,(DAT_030007c0 >> 4) + 0x10);
  *param_1 = uVar1;
  param_1[1] = local_8;
  return;
}


/* sub_08002E80 @ 0x08002E80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08002E80(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  sub_08002CE0(param_1,1,0);
  if (((int)((uint)DAT_03003d14 << 0x1f) < 0) && (iVar1 = sub_0800283C(0,0), iVar1 == 0)) {
    sub_08002466(param_1,3 - ((DAT_03003b6c << 0x1f) >> 0x1f));
  }
  if ((int)((uint)DAT_03003d14 << 0x17) < 0) {
    sub_08002E42(auStack_18);
    iVar1 = sub_08004FFA(DAT_03000600,auStack_18,1);
    if ((iVar1 == 0) || (DAT_030007ad == '\0')) {
      sub_0800ACFE(0x13);
    }
    else {
      _DAT_030007d4 = _DAT_030007c0;
      sub_08002466(param_1,0xe);
      DAT_030007dc = 1;
      DAT_030007b4 = sub_0800ACFE(0x12);
      if (DAT_030007b0 != '\0') {
        sub_0800245A(DAT_030007bc,&gUnknown_0801167C);
      }
    }
  }
  else if (((((int)((uint)DAT_03003d14 << 0x1e) < 0) && (DAT_030005fc != 0xd)) &&
           (DAT_030005fc != 0xe)) && ((DAT_030007b1 != '\x02' || (DAT_030007e4 <= DAT_03003b6c)))) {
    sub_0800B3DC(param_1,DAT_030007b1);
    sub_08002466(param_1,5);
  }
  return;
}


/* sub_08002F3E @ 0x08002F3E */

void sub_08002F3E(void)

{
  DAT_030007b2 = 0x10;
  DAT_030007d8 = 0;
  sub_08005C32(0);
  DAT_030007c4 = sub_08005BF0();
  DAT_030007c8 = DAT_030007c4;
  DAT_030007cc = sub_08005BE2();
  DAT_030007d0 = DAT_030007cc;
  DAT_030007ac = sub_08005C7A();
  DAT_030007ad = DAT_030007ac;
  DAT_030007ae = 0x14;
  DAT_030007af = 0x14;
  DAT_030007b1 = 0;
  DAT_030007b0 = 0;
  DAT_030007bc = 0;
  DAT_030007c0 = 0;
  DAT_030007c2 = 0;
  DAT_030007e0 = 0x20;
  return;
}


/* sub_08002F80 @ 0x08002F80 */

void sub_08002F80(void)

{
  DAT_030007d8 = DAT_030000c8;
  DAT_030007b0 = DAT_030000cd;
  DAT_030007b2 = (ushort)DAT_030000ce;
  DAT_030007e0 = (uint)DAT_030000cc;
  sub_08005C32(DAT_030000c8);
  DAT_030007c4 = sub_08005BF0();
  DAT_030007c8 = DAT_030007c4;
  DAT_030007cc = sub_08005BE2();
  DAT_030007d0 = DAT_030007cc;
  DAT_030007ac = sub_08005C7A();
  DAT_030007ad = DAT_030007ac;
  DAT_030007ae = 0x14;
  DAT_030007af = 0x14;
  DAT_030007b1 = 0;
  return;
}


/* sub_08002FC4 @ 0x08002FC4 */

void sub_08002FC4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  DAT_030007b0 = (char)param_1;
  iVar1 = sub_0800279E(param_2);
  if (iVar1 != 0) {
    DAT_030007bc = param_2;
    *(char *)(param_2 + 0x15) = (char)param_1;
    sub_08002486(param_2,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[param_1]],
                 &gUnknown_08166944,0,param_4);
  }
  return;
}


/* sub_08002FF6 @ 0x08002FF6 */

void sub_08002FF6(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_030007b8 + 0x3c);
  DAT_030007d8 = *(undefined4 *)(iVar1 + 0x84);
  DAT_030007cc = *(undefined4 *)(iVar1 + 0x50);
  DAT_030007c4 = *(undefined4 *)(iVar1 + 0x58);
  DAT_030007d0 = *(undefined4 *)(iVar1 + 0x4c);
  DAT_030007c8 = *(undefined4 *)(iVar1 + 0x54);
  DAT_030007ac = sub_08005C7A();
  return;
}


/* sub_0800301C @ 0x0800301C */

void sub_0800301C(void)

{
  if (DAT_030007b4 != 0) {
    *(byte *)(DAT_030007b4 + 0xc) = *(byte *)(DAT_030007b4 + 0xc) & 0xfe;
    DAT_030007b4 = 0;
  }
  return;
}


/* sub_08003032 @ 0x08003032 */

undefined4 sub_08003032(undefined4 param_1,int param_2,short *param_3)

{
  short sStack_1c;
  short sStack_1a;
  short sStack_18;
  short sStack_16;
  short sStack_14;
  short sStack_12;
  short sStack_10;
  short sStack_e;
  
  if (param_2 == 1) {
    if (*(int *)(param_3 + 6) == 0) {
      return 0;
    }
    sub_08002396(&sStack_1c,param_1);
    sStack_14 = sStack_1c;
    sStack_12 = sStack_1a;
    sStack_10 = sStack_18;
    sStack_e = sStack_16;
    if ((((sStack_1c < param_3[2]) && (*param_3 < sStack_18)) && (sStack_1a < param_3[3])) &&
       (param_3[1] < sStack_16)) {
      sub_08007416(*(undefined4 *)(param_3 + 10),*(undefined4 *)(DAT_030007b8 + 0x3c),1,
                   *(undefined4 *)(param_3 + 4));
      return 1;
    }
  }
  else if (param_2 == 5) {
    sub_0800236E(&sStack_14,param_1);
    sub_0800507A(DAT_03000600,&sStack_14,1,0);
  }
  else if (param_2 == 4) {
    if (DAT_030007b4 != 0) {
      *(byte *)(DAT_030007b4 + 0xc) = *(byte *)(DAT_030007b4 + 0xc) & 0xfe;
      DAT_030007b4 = 0;
    }
  }
  else if (param_2 == 3) {
    return 1;
  }
  return 0;
}


/* sub_08003120 @ 0x08003120 */

void sub_08003120(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_18;
  
  DAT_030007b8 = sub_08002716();
  sub_08002486(DAT_030007b8,(&gUnknown_085C0C80)[DAT_030007e0],&gUnknown_0816696C,0);
  local_18 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  *(undefined4 *)(DAT_030007b8 + 0x20) = local_18;
  iVar3 = DAT_030007b8;
  *(undefined4 *)(DAT_030007b8 + 0x38) = 0x8003033;
  iVar4 = DAT_030046b4;
  iVar2 = DAT_030046b4 + 0x278;
  *(int *)(iVar3 + 0x3c) = DAT_030046b4;
  DAT_030046b4 = iVar2;
  *(undefined1 *)(iVar3 + 0x15) = 0x34;
  sub_08006D90(iVar4,1,0);
  iVar3 = *(int *)(DAT_030007b8 + 0x3c);
  DAT_030007d8 = *(undefined4 *)(iVar3 + 0x84);
  DAT_030007cc = *(undefined4 *)(iVar3 + 0x50);
  DAT_030007c4 = *(undefined4 *)(iVar3 + 0x58);
  DAT_030007d0 = *(undefined4 *)(iVar3 + 0x4c);
  DAT_030007c8 = *(undefined4 *)(iVar3 + 0x54);
  DAT_030007ac = sub_08005C7A();
  sub_080062C4(&DAT_030047f0,iVar4,DAT_030007b8);
  if (DAT_030007b0 != 0) {
    iVar3 = sub_08002716();
    DAT_030007bc = iVar3;
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(DAT_030007b8 + 0x20);
    bVar1 = DAT_030007b0;
    uVar5 = (uint)DAT_030007b0;
    iVar4 = sub_0800279E();
    if (iVar4 != 0) {
      DAT_030007bc = iVar3;
      *(byte *)(iVar3 + 0x15) = bVar1;
      sub_08002486(iVar3,(&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[uVar5]],&gUnknown_08166944,
                   0);
    }
  }
  return;
}


/* sub_080031E2 @ 0x080031E2 */

void sub_080031E2(void)

{
  DAT_030007dc = 0;
  if (DAT_030007b4 != 0) {
    *(byte *)(DAT_030007b4 + 0xc) = *(byte *)(DAT_030007b4 + 0xc) & 0xfe;
    DAT_030007b4 = 0;
  }
  return;
}


/* sub_080031FA @ 0x080031FA */

void sub_080031FA(void)

{
  undefined1 auStack_14 [8];
  
  if (DAT_030007b0 != '\0') {
    sub_08002486(DAT_030007bc,*(undefined4 *)(DAT_030007bc + 0x1c),&gUnknown_085C2614,0);
    sub_0800236E(auStack_14,DAT_030007bc);
    sub_0800507A(DAT_03000600,auStack_14,1,0);
    DAT_030007b0 = '\0';
    DAT_030007bc = 0;
  }
  return;
}


/* sub_08003232 @ 0x08003232 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08003232(short *param_1)

{
  undefined4 local_4;
  
  local_4 = CONCAT22(param_1[1] << 4,*param_1 << 4);
  _DAT_030007c0 = local_4;
  return;
}


/* sub_0800324E @ 0x0800324E */

void sub_0800324E(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_030007b8 + 0x3c);
  if (DAT_030007d0 != 0) {
    if ((int)param_1 < 1) {
      sub_08002466(DAT_030007b8,2,DAT_030007b8,param_4,param_4);
      *(undefined2 *)(iVar1 + 0x9c) = 0;
      DAT_030007d0 = 0;
    }
    else {
      DAT_030007d0 = param_1;
      if (DAT_030007cc < param_1) {
        DAT_030007d0 = DAT_030007cc;
      }
    }
  }
  *(uint *)(iVar1 + 0x4c) = DAT_030007d0;
  return;
}


/* sub_08003284 @ 0x08003284 */

void sub_08003284(undefined4 param_1)

{
  DAT_030007c8 = param_1;
  *(undefined4 *)(*(int *)(DAT_030007b8 + 0x3c) + 0x54) = param_1;
  return;
}


/* sub_08003290 @ 0x08003290 */

undefined4 sub_08003290(void)

{
  if (DAT_030007ad == '\0') {
    return 0;
  }
  DAT_030007ad = DAT_030007ad + -1;
  return 1;
}


/* sub_080032A2 @ 0x080032A2 */

void sub_080032A2(char param_1)

{
  DAT_030007ad = DAT_030007ad + param_1;
  if (DAT_030007ac < DAT_030007ad) {
    DAT_030007ad = DAT_030007ac;
  }
  return;
}


/* sub_080032B8 @ 0x080032B8 */

void sub_080032B8(void)

{
  sub_08005BB4();
  return;
}


/* sub_080032C0 @ 0x080032C0 */

void sub_080032C0(void)

{
  sub_08005C62();
  return;
}


/* sub_080032C8 @ 0x080032C8 */

void sub_080032C8(short *param_1)

{
  char cVar1;
  undefined4 local_18;
  undefined4 local_14;
  short sStack_10;
  short sStack_e;
  
  local_18 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_14 = local_18;
  sub_0800F3C4(&local_14,&gUnknown_08010840);
  cVar1 = *(char *)(DAT_030007b8 + 0x13);
  if (cVar1 == '\0') {
    *param_1 = (short)local_14 + 4;
    param_1[1] = sStack_e + 2;
    param_1[2] = sStack_10 + -4;
    param_1[3] = sStack_e + 4;
  }
  else if (cVar1 == '\x01') {
    *param_1 = (short)local_14 + 4;
    param_1[1] = local_14._2_2_ + -4;
    param_1[2] = sStack_10 + -4;
    param_1[3] = local_14._2_2_ + -2;
  }
  else if ((cVar1 == '\x02') || (cVar1 != '\x03')) {
    *param_1 = (short)local_14 + -4;
    param_1[1] = local_14._2_2_ + 2;
    param_1[2] = (short)local_14 + -2;
    param_1[3] = sStack_e + -2;
  }
  else {
    *param_1 = sStack_10 + 2;
    param_1[1] = local_14._2_2_ + 2;
    param_1[2] = sStack_10 + 4;
    param_1[3] = sStack_e + -2;
  }
  return;
}


/* sub_08003398 @ 0x08003398 */

undefined4 sub_08003398(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_10;
  undefined4 local_c;
  short local_8;
  short local_6;
  
  local_10 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_c = local_10;
  sub_0800F3C4(&local_c,&gUnknown_08010840);
  sVar2 = (short)((short)local_c + local_8) >> 1;
  sVar3 = (short)(local_c._2_2_ + local_6) >> 1;
  cVar1 = *(char *)(DAT_030007b8 + 0x13);
  if (cVar1 == '\0') {
    local_1c = CONCAT22(local_6 + 2,sVar2);
  }
  else if (cVar1 == '\x01') {
    local_1c = CONCAT22(local_c._2_2_ + -2,sVar2);
  }
  else if ((cVar1 == '\x02') || (cVar1 != '\x03')) {
    uStack_20 = CONCAT22(sVar3,(short)local_c + -2);
    local_1c = uStack_20;
  }
  else {
    local_1c = CONCAT22(sVar3,local_8 + 2);
  }
  return local_1c;
}


/* sub_08003446 @ 0x08003446 */

undefined4 sub_08003446(void)

{
  char cVar1;
  short sVar2;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  short local_8;
  undefined2 local_6;
  
  local_10 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  local_c = local_10;
  sub_0800F3C4(&local_c,&gUnknown_08010840);
  sVar2 = (short)((short)local_c + local_8) >> 1;
  cVar1 = *(char *)(DAT_030007b8 + 0x13);
  if (cVar1 == '\0') {
    local_18 = CONCAT22(local_6,sVar2);
    local_1c = local_18;
  }
  else if (cVar1 == '\x01') {
    local_14 = CONCAT22(local_c._2_2_ + -8,sVar2);
    local_1c = local_14;
  }
  else if ((cVar1 == '\x02') || (cVar1 != '\x03')) {
    uStack_20 = CONCAT22(local_c._2_2_ + -8,(short)local_c + -2);
    local_1c = uStack_20;
  }
  else {
    local_1c = CONCAT22(local_c._2_2_ + -8,local_8 + 2);
  }
  return local_1c;
}


/* sub_08003524 @ 0x08003524 */

void sub_08003524(void)

{
  do {
    DAT_030007b1 = DAT_030007b1 + 1;
    if (2 < DAT_030007b1) {
      DAT_030007b1 = 0;
      return;
    }
  } while (((uint)DAT_0300004d & 1 << (uint)DAT_030007b1) == 0);
  return;
}


/* sub_08003550 @ 0x08003550 */

void sub_08003550(void)

{
  sub_0800BEB8(DAT_030007b8);
  sub_0800ACFE(0x15);
  return;
}


/* sub_0800356C @ 0x0800356C */

undefined4 sub_0800356C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_08001FA8(*(undefined2 *)(param_1 + 0xe),param_1 + 0x10,param_3,param_4,param_4);
  return 1;
}


/* sub_0800356E @ 0x0800356E */

undefined4 sub_0800356E(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  sub_08001FA8(*(undefined2 *)(param_1 + 0xe),param_2 + 0x10,param_3,param_4,param_4);
  return 1;
}


/* sub_0800357C @ 0x0800357C */

bool sub_0800357C(undefined4 *param_1)

{
  short *psVar1;
  bool bVar2;
  undefined4 uStack_8;
  
  bVar2 = DAT_030007e8 != 0;
  if (bVar2) {
    psVar1 = *(short **)(param_1[2] + (uint)*(byte *)((int)param_1 + 0x13) * 4);
    uStack_8 = CONCAT22(psVar1[1] + 0x88,*psVar1 + 0xd0);
    *param_1 = uStack_8;
  }
  return bVar2;
}


/* sub_080035B0 @ 0x080035B0 */

void sub_080035B0(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 8;
  return;
}


/* sub_080035B6 @ 0x080035B6 */

void sub_080035B6(void)

{
  if ((int)((uint)DAT_03003d14 << 0x1d) < 0) {
    DAT_030007f0 = 1 - DAT_030007f0;
  }
  return;
}


/* sub_080035CC @ 0x080035CC */

uint sub_080035CC(void)

{
  if (DAT_030007e8 == 0) {
    return 0;
  }
  return ((uint)DAT_03003d12 << 0x16) >> 0x1f ^ DAT_030007f0;
}


/* sub_080035E4 @ 0x080035E4 */

void sub_080035E4(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_1c;
  
  iVar3 = *(int *)(DAT_03000800 + 0x1c) + (uint)*(byte *)(DAT_03000800 + 0x13) * 8;
  uVar2 = *(short *)(iVar3 + 6) + 0x88;
  local_1c = CONCAT22(uVar2,*(short *)(iVar3 + 4) + 0xd0);
  iVar7 = (int)*(short *)(iVar3 + 8) - (int)*(short *)(iVar3 + 4);
  iVar3 = (int)*(short *)(iVar3 + 10) - (int)*(short *)(iVar3 + 6);
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  *puVar5 = *puVar5 & 0xc1ff00ff | 0xc0000000;
  uVar10 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar10;
  *(uint *)(&DAT_0202be28 + iVar4) =
       uVar10 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10;
  *puVar5 = uVar2 & 0xff | (uint)(local_1c << 0x17) >> 7 | 0xc0000000;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x200;
  DAT_040000de = 0x8500;
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar8 = *(int *)(param_2 + 2) + ((uint)(iVar4 << 0x1d) >> 0x1b) + (iVar4 >> 3) * 0x100;
      iVar6 = 0;
      if (0 < iVar7) {
        do {
          bVar9 = 0x10;
          if (-1 < iVar6 << 0x1f) {
            bVar9 = 1;
          }
          iVar11 = (iVar6 >> 3) * 0x20 + ((uint)(iVar6 << 0x1d) >> 0x1e);
          iVar6 = iVar6 + 1;
          *(byte *)(iVar8 + iVar11) = bVar9 | *(byte *)(iVar8 + iVar11);
        } while (iVar6 < iVar7);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x800;
  param_2[1] = param_2[1] + 0x40;
  return;
}


/* sub_0800370C @ 0x0800370C */

void sub_0800370C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 == '\0') {
    param_1 = (*(byte *)(param_1 + 4) + 1) - (uint)*(byte *)(param_1 + 5);
    cVar1 = '\x01';
    DAT_02029d9e = 1;
    DAT_02029da0 = (undefined2)param_1;
  }
  else if (cVar1 == '\x01') {
    param_1 = *(byte *)(param_1 + 6) + 1;
    cVar1 = '\r';
    DAT_02029d9e = 0xd;
    DAT_02029da0 = (undefined2)param_1;
  }
  else if (cVar1 == '\x02') {
    DAT_02029d9e = 0x19;
    param_1 = 0xf;
    DAT_02029da0 = 0xf;
  }
  sub_08009064(&DAT_02029d94,&_08003980,param_1,cVar1,param_4);
  return;
}


/* sub_08003750 @ 0x08003750 */

void sub_08003750(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  
  if (DAT_030007ec != 0) {
    uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x10) + 0xd);
    (&DAT_03000994)[uVar2 * 2] = (&DAT_03000994)[uVar2 * 2] + -1;
  }
  puVar6 = (undefined4 *)(&gUnknown_0815A4E8)[*(byte *)(param_1 + 4)];
  if (puVar6 == (undefined4 *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
  }
  else {
    uVar1 = sub_08005EA6(*puVar6);
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0xd) = uVar1;
    uVar3 = sub_080095DC(puVar6);
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = uVar3;
  }
  DAT_030007ec = (uint)(puVar6 != (undefined4 *)0x0);
  uVar2 = 0;
  if ((*(char *)(param_1 + 8) == '\x01') || (*(char *)(param_1 + 8) == '\x02')) {
    uVar2 = (uint)*(byte *)(param_1 + 6);
  }
  if (DAT_030007e8 != 0) {
    uVar4 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0xd);
    (&DAT_03000994)[uVar4 * 2] = (&DAT_03000994)[uVar4 * 2] + -1;
  }
  DAT_030007e8 = 0;
  puVar5 = (&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 4)]];
  if (((puVar5 != (undefined *)0x0) && (*(int *)(*(int *)(puVar5 + 0x28) + uVar2 * 0x10) != 0)) &&
     ((&PTR_sub_08002910_1_08010868)[uVar2 * 5] != (undefined *)0x0)) {
    sub_08002486(*(undefined4 *)(param_1 + 0xc),puVar5,&PTR_sub_08002910_1_08010868,uVar2,param_4);
    DAT_030007e8 = 1;
  }
  return;
}


/* sub_080037F6 @ 0x080037F6 */

void sub_080037F6(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  DAT_030007ec = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_080090AE(&DAT_0202a5b8,&DAT_08010858);
  sub_080090AE(&DAT_0202a5b8,&DAT_08010860);
  sub_08008D8A(&DAT_0202a5b8);
  sub_0800252E();
  uVar2 = sub_08002716();
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  uVar2 = sub_08002716();
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  uVar2 = sub_08002716();
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  puVar3 = *(undefined2 **)(param_1 + 0x10);
  *puVar3 = 200;
  puVar3[1] = 8;
  sub_0800245A(*(undefined4 *)(param_1 + 0x10),&gUnknown_08011480);
  uVar1 = sub_08005EA6(*(undefined4 *)(&gUnknown_0815A4E8)[*(byte *)(param_1 + 4)]);
  *(undefined1 *)(*(int *)(param_1 + 0x10) + 0xd) = uVar1;
  uVar1 = sub_08005EA6(&gUnknown_080109D0);
  *(undefined1 *)(*(int *)(param_1 + 0x14) + 0xd) = uVar1;
  sub_0800245A(*(undefined4 *)(param_1 + 0x14),&PTR_sub_080035B0_1_080109bc);
  sub_08003750(param_1);
  return;
}


/* sub_08003880 @ 0x08003880 */

void sub_08003880(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  sub_08008D14(&DAT_02029d94);
  sub_08008D14(&DAT_0202addc);
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 != '\0') {
    if ((cVar1 != '\x01') && (cVar1 != '\x02')) goto _080038F4;
    sub_080090AE(&DAT_0202addc,&DAT_08010850);
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      DAT_02029d9e = 0xe;
      DAT_02029da0 = (undefined2)iVar3;
      sub_08009064(&DAT_02029d94,(&gUnknown_08010EC4)[iVar2]);
      iVar2 = iVar3;
    } while (iVar3 < 0x11);
  }
  sub_080090AE(&DAT_0202addc,&DAT_08010848);
  iVar2 = 0;
  do {
    DAT_02029d9e = 2;
    iVar3 = iVar2 + 1;
    DAT_02029da0 = (undefined2)iVar3;
    sub_08009064(&DAT_02029d94,
                 (&PTR_gUnknown_08010BA4_080109f0)[(uint)*(byte *)(param_1 + 5) + iVar2]);
    iVar2 = iVar3;
  } while (iVar3 < 0x12);
_080038F4:
  sub_08002556(0,1);
  sub_08002896();
  if (DAT_030007ec == 0) {
    DAT_02029d9e = 0x1a;
    DAT_02029da0 = 2;
    sub_08008E06(&DAT_02029d94,sub_080039AC);
    DAT_02029d9e = 0x1a;
    DAT_02029da0 = 3;
    sub_08008E06(&DAT_02029d94,0x80039b0);
  }
  if (DAT_030007e8 == 0) {
    DAT_02029d9e = 0x19;
    DAT_02029da0 = 0xf;
    sub_08008E06(&DAT_02029d94,0x80039b4);
  }
  sub_0800370C(param_1);
  sub_08008D8A(&DAT_02029d94);
  sub_08008D8A(&DAT_0202addc);
  return;
}


/* sub_08003952 @ 0x08003952 */

undefined4 sub_08003952(int param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  sub_080026F8();
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 == '\0') {
    uVar3 = (uint)DAT_03003d14;
    if ((int)(uVar3 << 0x1e) < 0) {
      sub_080098DE();
      sub_08008DA0(&DAT_0202a5b8);
      sub_08009798();
    }
    else if ((DAT_03003d14 & 1) == 0) {
      if (((int)(uVar3 << 0x19) < 0) || ((int)((uint)DAT_03003d12 << 0x1a) < 0)) {
        cVar1 = *(char *)(param_1 + 4);
        if (cVar1 != '\0') {
          *(char *)(param_1 + 4) = cVar1 + -1;
          if ((byte)(cVar1 - 1U) < *(byte *)(param_1 + 5)) {
            *(char *)(param_1 + 5) = cVar1 + -1;
          }
        }
        sub_08003750(param_1);
      }
      else if (((int)(uVar3 << 0x18) < 0) || ((int)((uint)DAT_03003d12 << 0x1b) < 0)) {
        if (*(byte *)(param_1 + 4) < 0x6c) {
          bVar2 = *(byte *)(param_1 + 4) + 1;
          *(byte *)(param_1 + 4) = bVar2;
          iVar4 = bVar2 - 0x11;
          if ((int)(uint)*(byte *)(param_1 + 5) < iVar4) {
            *(char *)(param_1 + 5) = (char)iVar4;
          }
        }
        sub_08003750(param_1);
      }
    }
    else {
      *(undefined1 *)(param_1 + 6) = 0;
      *(undefined1 *)(param_1 + 8) = 1;
    }
  }
  else if (cVar1 == '\x01') {
    uVar3 = (uint)DAT_03003d14;
    if ((int)(uVar3 << 0x1e) < 0) {
      *(undefined1 *)(param_1 + 8) = 0;
    }
    else if ((DAT_03003d14 & 1) == 0) {
      if ((int)(uVar3 << 0x19) < 0) {
        if (*(char *)(param_1 + 6) == '\0') {
          *(undefined1 *)(param_1 + 6) = 0x10;
        }
        else {
          *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
        }
        sub_08003750(param_1);
      }
      else if ((int)(uVar3 << 0x18) < 0) {
        if (*(byte *)(param_1 + 6) < 0x10) {
          *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) + 1;
        }
        else {
          *(undefined1 *)(param_1 + 6) = 0;
        }
        sub_08003750(param_1);
      }
    }
    else if (DAT_030007e8 != 0) {
      *(undefined1 *)(param_1 + 8) = 2;
    }
  }
  else if (cVar1 == '\x02') {
    uVar3 = (uint)DAT_03003d14;
    if ((int)(uVar3 << 0x1e) < 0) {
      *(undefined1 *)(param_1 + 8) = 1;
    }
    else if ((DAT_03003d14 & 1) == 0) {
      if ((int)(uVar3 << 0x1a) < 0) {
        *(undefined1 *)(param_1 + 7) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x13) = 2;
      }
      else if ((int)(uVar3 << 0x1b) < 0) {
        *(undefined1 *)(param_1 + 7) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x13) = 3;
      }
      else if ((int)(uVar3 << 0x19) < 0) {
        *(undefined1 *)(param_1 + 7) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x13) = 1;
      }
      else if ((int)(uVar3 << 0x18) < 0) {
        *(undefined1 *)(param_1 + 7) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x13) = 0;
      }
    }
    else {
      sub_08003750(param_1);
    }
  }
  return 0;
}


/* sub_080039AC @ 0x080039AC */

undefined4 sub_080039AC(undefined4 param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int unaff_r4;
  int unaff_r5;
  
  *(undefined4 *)(unaff_r5 + 0x54) = *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(unaff_r5 + 0x54) = *(undefined4 *)(param_2 + 0x74);
  cVar1 = *(char *)(unaff_r4 + 8);
  if (cVar1 == '\0') {
    uVar3 = (uint)DAT_03003d14;
    if ((int)(uVar3 << 0x1e) < 0) {
      sub_080098DE();
      sub_08008DA0(&DAT_0202a5b8);
      sub_08009798();
    }
    else if ((DAT_03003d14 & 1) == 0) {
      if (((int)(uVar3 << 0x19) < 0) || ((int)((uint)DAT_03003d12 << 0x1a) < 0)) {
        cVar1 = *(char *)(unaff_r4 + 4);
        if (cVar1 != '\0') {
          *(char *)(unaff_r4 + 4) = cVar1 + -1;
          if ((byte)(cVar1 - 1U) < *(byte *)(unaff_r4 + 5)) {
            *(char *)(unaff_r4 + 5) = cVar1 + -1;
          }
        }
        sub_08003750(unaff_r4);
      }
      else if (((int)(uVar3 << 0x18) < 0) || ((int)((uint)DAT_03003d12 << 0x1b) < 0)) {
        if (*(byte *)(unaff_r4 + 4) < 0x6c) {
          bVar2 = *(byte *)(unaff_r4 + 4) + 1;
          *(byte *)(unaff_r4 + 4) = bVar2;
          iVar4 = bVar2 - 0x11;
          if ((int)(uint)*(byte *)(unaff_r4 + 5) < iVar4) {
            *(char *)(unaff_r4 + 5) = (char)iVar4;
          }
        }
        sub_08003750(unaff_r4);
      }
    }
    else {
      *(undefined1 *)(unaff_r4 + 6) = 0;
      *(undefined1 *)(unaff_r4 + 8) = 1;
    }
  }
  else if (cVar1 == '\x01') {
    uVar3 = (uint)DAT_03003d14;
    if ((int)(uVar3 << 0x1e) < 0) {
      *(undefined1 *)(unaff_r4 + 8) = 0;
    }
    else if ((DAT_03003d14 & 1) == 0) {
      if ((int)(uVar3 << 0x19) < 0) {
        if (*(char *)(unaff_r4 + 6) == '\0') {
          *(undefined1 *)(unaff_r4 + 6) = 0x10;
        }
        else {
          *(char *)(unaff_r4 + 6) = *(char *)(unaff_r4 + 6) + -1;
        }
        sub_08003750(unaff_r4);
      }
      else if ((int)(uVar3 << 0x18) < 0) {
        if (*(byte *)(unaff_r4 + 6) < 0x10) {
          *(byte *)(unaff_r4 + 6) = *(byte *)(unaff_r4 + 6) + 1;
        }
        else {
          *(undefined1 *)(unaff_r4 + 6) = 0;
        }
        sub_08003750(unaff_r4);
      }
    }
    else if (DAT_030007e8 != 0) {
      *(undefined1 *)(unaff_r4 + 8) = 2;
    }
  }
  else if (cVar1 == '\x02') {
    uVar3 = (uint)DAT_03003d14;
    if ((int)(uVar3 << 0x1e) < 0) {
      *(undefined1 *)(unaff_r4 + 8) = 1;
    }
    else if ((DAT_03003d14 & 1) == 0) {
      if ((int)(uVar3 << 0x1a) < 0) {
        *(undefined1 *)(unaff_r4 + 7) = 0;
        *(undefined1 *)(*(int *)(unaff_r4 + 0xc) + 0x13) = 2;
      }
      else if ((int)(uVar3 << 0x1b) < 0) {
        *(undefined1 *)(unaff_r4 + 7) = 0;
        *(undefined1 *)(*(int *)(unaff_r4 + 0xc) + 0x13) = 3;
      }
      else if ((int)(uVar3 << 0x19) < 0) {
        *(undefined1 *)(unaff_r4 + 7) = 0;
        *(undefined1 *)(*(int *)(unaff_r4 + 0xc) + 0x13) = 1;
      }
      else if ((int)(uVar3 << 0x18) < 0) {
        *(undefined1 *)(unaff_r4 + 7) = 0;
        *(undefined1 *)(*(int *)(unaff_r4 + 0xc) + 0x13) = 0;
      }
    }
    else {
      sub_08003750(unaff_r4);
    }
  }
  return 0;
}


/* sub_08003B0C @ 0x08003B0C */

void sub_08003B0C(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08003B18 @ 0x08003B18 */

void sub_08003B18(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x50) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 4;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
  }
  return;
}


/* sub_08003B28 @ 0x08003B28 */

void sub_08003B28(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_08003B34 @ 0x08003B34 */

void sub_08003B34(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if (bVar1 < 0x18) {
    *(byte *)(param_1 + 0x12) = bVar1 >> 3;
    *(byte *)(param_1 + 0x10) = bVar1 + 1;
    return;
  }
  *(char *)(param_1 + 0x12) = (char)((int)((uint)bVar1 << 0x1c) >> 0x1f) + '\x02';
  *(byte *)(param_1 + 0x10) = (bVar1 + 1 & 0xf) + 0x10;
  return;
}


/* sub_08003B5A @ 0x08003B5A */

void sub_08003B5A(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}


/* sub_08003B5C @ 0x08003B5C */

void sub_08003B5C(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}


/* sub_08003B66 @ 0x08003B66 */

void sub_08003B66(void)

{
  return;
}


/* sub_08003B68 @ 0x08003B68 */

void sub_08003B68(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x28;
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}


/* sub_08003B72 @ 0x08003B72 */

void sub_08003B72(void)

{
  return;
}


/* sub_08003B74 @ 0x08003B74 */

void sub_08003B74(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_08010F84);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(2,0xb);
  return;
}


/* sub_08003BA4 @ 0x08003BA4 */

void sub_08003BA4(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486(&DAT_08010fb4,&DAT_02029d94);
  sub_0800946E(&UNK_08010f8c + (uint)DAT_03000020 * 8,&DAT_02029d94);
  DAT_02029d9e = 6;
  DAT_02029da0 = 0xe;
  sub_08008E3A(&DAT_02029d94,&_08003D7C,DAT_03000021);
  DAT_02029d9e = 6;
  DAT_02029da0 = 0x10;
  sub_08008E3A(&DAT_02029d94,&_08003D7C,DAT_03000022);
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08003BFE @ 0x08003BFE */

undefined4 sub_08003BFE(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = sub_080094B8(&DAT_08010fb4,param_1 + 4,param_3,param_4,param_4);
  if (iVar2 != 0) {
    sub_08000A32(2,(uint)*(byte *)(param_1 + 4) * 2 + 0xb);
    sub_0800ACFE(0);
  }
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\0') {
    if ((DAT_03003d14 & 1) == 0) {
      if ((int)((uint)DAT_03003d14 << 0x1b) < 0) {
        if (DAT_03000020 != '\x02') {
          DAT_03000020 = DAT_03000020 + '\x01';
          sub_0800ACFE(0);
        }
      }
      else if (((int)((uint)DAT_03003d14 << 0x1a) < 0) && (DAT_03000020 != '\0')) {
        DAT_03000020 = DAT_03000020 + -1;
        sub_0800ACFE(0);
      }
    }
    else {
      if (DAT_03000020 == '\x02') {
        DAT_03000020 = '\0';
      }
      else {
        DAT_03000020 = DAT_03000020 + '\x01';
      }
      sub_0800ACFE(0);
    }
  }
  else if (cVar1 == '\x01') {
    if (((int)((uint)DAT_03003d14 << 0x1a) < 0) && (DAT_03000021 != 0)) {
      DAT_03000021 = DAT_03000021 - 1;
      sub_0800A9CC();
      sub_0800ACFE(0);
    }
    if (((int)((uint)DAT_03003d14 << 0x1b) < 0) && (DAT_03000021 < 8)) {
      DAT_03000021 = DAT_03000021 + 1;
      sub_0800A9CC();
      sub_0800ACFE(0);
    }
  }
  else if (cVar1 == '\x02') {
    if (((int)((uint)DAT_03003d14 << 0x1a) < 0) && (DAT_03000022 != 0)) {
      DAT_03000022 = DAT_03000022 - 1;
      sub_0800A9A2();
      sub_0800ACFE(0);
    }
    if (((int)((uint)DAT_03003d14 << 0x1b) < 0) && (DAT_03000022 < 8)) {
      DAT_03000022 = DAT_03000022 + 1;
      sub_0800A9A2();
      sub_0800ACFE(0);
    }
  }
  else if (cVar1 == '\x03') {
    uVar3 = (uint)DAT_03003d12;
    if (((((int)(uVar3 << 0x16) < 0) && ((int)(uVar3 << 0x17) < 0)) && ((int)(uVar3 << 0x19) < 0))
       && ((DAT_03003d14 & 1) != 0)) {
      sub_08009744(&DAT_030000d8);
    }
    else if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1c) < 0)) {
      sub_08000784(&DAT_03000020);
      sub_0800ACFE(0);
      sub_08009798();
    }
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  return 0;
}


/* sub_08003D90 @ 0x08003D90 */

undefined4 sub_08003D90(void)

{
  return 1;
}


/* sub_08003D94 @ 0x08003D94 */

void sub_08003D94(undefined2 *param_1)

{
  undefined1 uVar1;
  
  *param_1 = 8;
  param_1[1] = 8;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 6) = 0x10;
  uVar1 = sub_08005EA6(&gUnknown_085C0FB4);
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  uVar1 = sub_08005EA6(&gUnknown_085C0F08);
  *(undefined1 *)(param_1 + 10) = uVar1;
  return;
}


/* sub_08003DBE @ 0x08003DBE */

void sub_08003DBE(int param_1)

{
  if ((int)((uint)DAT_03003d14 << 0x16) < 0) {
    sub_08003524();
  }
  if ((DAT_030007dc != 0) || ((int)((uint)DAT_03003d12 << 0x1d) < 0)) {
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + -1;
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0x14) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0x14) * 2] + -1;
    sub_0800245A(param_1,&gUnknown_08011438);
  }
  return;
}


/* sub_08003E02 @ 0x08003E02 */

void sub_08003E02(int param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  
  REG_DMA3SAD = 0x85c0f34;
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0x1ff00ff) + 0x40000000;
  *puVar5 = uVar7;
  uVar8 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10 | uVar8 & 0xffff0fff;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x80000 & 0xffffff00) + 8;
  iVar4 = *(int *)(param_2 + 2);
  *(int *)(param_2 + 2) = iVar4 + 0x80;
  param_2[1] = param_2[1] + 4;
  REG_DMA3SAD = *(undefined4 *)((&gUnknown_08010FE8)[DAT_030007b1] + 4);
  REG_DMA3DAD = iVar4 + 0x80;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0x1ff00ff) + 0x40000000;
  *puVar5 = uVar7;
  uVar8 = (*(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000 | param_2[1] & 0x3ff) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       uVar8 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x480000 & 0xffffff00) + 8;
  iVar6 = *(int *)(param_2 + 2) + 0x80;
  *(int *)(param_2 + 2) = iVar6;
  param_2[1] = param_2[1] + 4;
  REG_DMA3SAD = 0x85c0e88;
  REG_DMA3DAD = iVar6;
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0x1ff00ff) + 0x40000000;
  *puVar5 = uVar7;
  uVar8 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       uVar8 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0x14) << 0x1c) >> 0x10;
  *puVar5 = ((uVar7 & 0xfe00ffff) + 0x180000 & 0xffffff00) + 8;
  iVar4 = *(int *)(param_2 + 2);
  *(int *)(param_2 + 2) = iVar4 + 0x80;
  param_2[1] = param_2[1] + 4;
  REG_DMA3SAD = 0x85c0fe0;
  REG_DMA3DAD = iVar4 + 0x80;
  Ram040000dc = 0x40;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar4 = (uint)uVar1 * 8;
  puVar5 = (uint *)(&DAT_0202be24 + iVar4);
  uVar7 = (*puVar5 & 0xffff00ff) + 0x4000;
  *puVar5 = uVar7;
  uVar7 = (uVar7 & 0x1ffffff) + 0x80000000;
  *puVar5 = uVar7;
  uVar8 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar4) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar4) = uVar8;
  *(uint *)(&DAT_0202be28 + iVar4) =
       ((uint)*(byte *)(param_1 + 0x14) << 0x1c) >> 0x10 | uVar8 & 0xffff0fff;
  uVar7 = uVar7 & 0xfe00ffff;
  *puVar5 = (uVar7 + 0x280000 & 0xffffff00) + 8;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x100;
  param_2[1] = param_2[1] + 8;
  iVar2 = sub_0800E640(DAT_030007c4,DAT_030007c8 * 0x2c,puVar5,uVar7,param_4);
  iVar4 = sub_0800E640(DAT_030007cc,DAT_030007d0 * 0x2c);
  if (0x2c < iVar2) {
    iVar2 = 0x2c;
  }
  if (0x2c < iVar4) {
    iVar4 = 0x2c;
  }
  piVar3 = &gUnknown_08011214;
  for (; 1 < iVar4; iVar4 = iVar4 + -2) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xcc;
    piVar9 = piVar3 + 2;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xcc;
    piVar3 = piVar3 + 3;
    *(undefined1 *)(iVar6 + *piVar9) = 0xee;
  }
  if (iVar4 != 0) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xac;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xac;
    *(undefined1 *)(iVar6 + piVar3[2]) = 0xae;
  }
  piVar3 = &DAT_08011004;
  for (; 1 < iVar2; iVar2 = iVar2 + -2) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xbb;
    piVar9 = piVar3 + 2;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xbb;
    piVar3 = piVar3 + 3;
    *(undefined1 *)(iVar6 + *piVar9) = 0xdd;
  }
  if (iVar2 != 0) {
    *(undefined1 *)(iVar6 + *piVar3) = 0xab;
    *(undefined1 *)(iVar6 + piVar3[1]) = 0xab;
    *(undefined1 *)(iVar6 + piVar3[2]) = 0xad;
  }
  return;
}


/* sub_080040F0 @ 0x080040F0 */

void sub_080040F0(undefined2 *param_1)

{
  undefined1 uVar1;
  
  *param_1 = 8;
  param_1[1] = 8;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 6) = 0x18;
  uVar1 = sub_08005EA6(&gUnknown_085C0E5C);
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  return;
}


/* sub_08004112 @ 0x08004112 */

void sub_08004112(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((DAT_030007dc != 1) && (-1 < (int)((uint)DAT_03003d12 << 0x1d))) {
    iVar1 = (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2];
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] = iVar1 + -1;
    sub_0800245A(param_1,&PTR_sub_08003D94_1_08011424,iVar1 + -1,&DAT_03000994,param_4);
  }
  return;
}


/* sub_0800413E @ 0x0800413E */

void sub_0800413E(int param_1,ushort *param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint *puVar4;
  short extraout_r1;
  short extraout_r1_00;
  uint uVar5;
  uint uVar6;
  
  sub_080090AE(&DAT_02029d94,&DAT_08010fe0);
  sVar2 = sub_0800E704(DAT_030007ad);
  DAT_02029e40 = sVar2 + 0x12;
  DAT_02029e42 = extraout_r1 + 0x12;
  DAT_02029e44 = 0x11;
  sVar2 = sub_0800E704(DAT_030007ac);
  DAT_02029e46 = sVar2 + 0x12;
  DAT_02029e48 = extraout_r1_00 + 0x12;
  REG_DMA3SAD = 0x85c0ddc;
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar3 = (uint)uVar1 * 8;
  puVar4 = (uint *)(&DAT_0202be24 + iVar3);
  uVar5 = (*puVar4 & 0x1ff00ff) + 0x40000000;
  *puVar4 = uVar5;
  uVar6 = (param_2[1] & 0x3ff | *(uint *)(&DAT_0202be28 + iVar3) & 0xfffff000) + 0x400;
  *(uint *)(&DAT_0202be28 + iVar3) = uVar6;
  *(uint *)(&DAT_0202be28 + iVar3) =
       uVar6 & 0xffff0fff | ((uint)*(byte *)(param_1 + 0xd) << 0x1c) >> 0x10;
  *puVar4 = ((uVar5 & 0xfe00ffff) + 0x60000 & 0xffffff00) + 0xc;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x80;
  param_2[1] = param_2[1] + 4;
  return;
}


/* sub_0800426E @ 0x0800426E */

undefined4 sub_0800426E(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 4) {
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x34);
    sub_0800245A(param_1,&gUnknown_0801144C,param_3,param_4,param_4);
  }
  else if (param_2 == 5) {
    sub_0800245A(param_1,*(undefined4 *)(param_1 + 0x3c),param_3,param_4,param_4);
  }
  return 0;
}


/* sub_0800428E @ 0x0800428E */

void sub_0800428E(void)

{
  int iVar1;
  
  iVar1 = sub_08002716();
  sub_0800245A(iVar1,&PTR_sub_08003D94_1_08011424);
  *(undefined4 *)(iVar1 + 0x38) = 0x800426f;
  return;
}


/* sub_080042B4 @ 0x080042B4 */

undefined4 sub_080042B4(int param_1)

{
  if (DAT_03000814 < DAT_03003b6c + -0x3c) {
    DAT_03000814 = DAT_03003b6c;
    if (DAT_030007d0 != 0) {
      sub_0800324E(DAT_030007d0 + *(int *)(param_1 + 0x10));
      if (*(int *)(param_1 + 0x10) < 0) {
        sub_08003550();
      }
    }
  }
  return 0;
}


/* sub_080042F4 @ 0x080042F4 */

undefined4 sub_080042F4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x1c;
  DAT_040000de = 0x8100;
  if ((param_3 == 1) || (param_3 == 2)) {
    if ((*(short *)(param_2 + 4) == -0x50ef) || (*(short *)(param_2 + 4) == -0x50ee)) {
      uVar1 = *(ushort *)(param_2 + 8);
      *(ushort *)(param_1 + 4) = uVar1;
      uVar2 = *(ushort *)(param_2 + 10);
      *(ushort *)(param_1 + 6) = uVar2;
      *(uint *)(param_1 + 8) = (uint)uVar2 * (uint)uVar1;
      *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 6);
      if (*(short *)(param_2 + 4) == -0x50ef) {
        *(undefined2 *)(param_1 + 0x10) = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0x10) = 2;
      }
      *(undefined2 *)(param_1 + 0x12) = 8;
      if (*(short *)(param_1 + 0x10) == 1) {
        iVar4 = 1000;
        if (*(ushort *)(param_2 + 0x10) != 0) {
          iVar4 = (uint)*(ushort *)(param_2 + 0x10) * 1000;
        }
        uVar3 = sub_0800E640(0x46,iVar4,0xaf11,(uint)*(byte *)(param_2 + 0x11) << 8,param_4);
        *(undefined4 *)(param_1 + 0x14) = uVar3;
      }
      else {
        *(uint *)(param_1 + 0x14) = (uint)*(ushort *)(param_2 + 0x10);
      }
      param_2 = param_2 + 0x80;
      *(int *)(param_1 + 0x34) = param_2;
      *(int *)(param_1 + 0x24) = param_2;
      *(int *)(param_1 + 0x28) = param_2;
      *(int *)(param_1 + 0x2c) = param_2;
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* sub_080043AC @ 0x080043AC */

void sub_080043AC(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = (uint)*param_2 + (uint)param_2[1] * 0x100;
  param_2 = param_2 + 2;
  while (iVar6 != 0) {
    iVar6 = iVar6 + -1;
    bVar1 = *param_2;
    uVar3 = (uint)param_2[1];
    param_2 = param_2 + 2;
    if (uVar3 == 0) {
      uVar3 = 0x100;
    }
    iVar4 = iVar4 + (uint)bVar1;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar2 = iVar4 * 3;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2) = *param_2;
      pbVar5 = param_2 + 2;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 1) = param_2[1];
      param_2 = param_2 + 3;
      iVar4 = iVar4 + 1;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 2) = *pbVar5;
    }
  }
  *(undefined2 *)(param_1 + 0x1c) = 1;
  return;
}


/* sub_08004406 @ 0x08004406 */

void sub_08004406(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = (uint)*param_2 + (uint)param_2[1] * 0x100;
  param_2 = param_2 + 2;
  while (iVar6 != 0) {
    iVar6 = iVar6 + -1;
    bVar1 = *param_2;
    uVar3 = (uint)param_2[1];
    param_2 = param_2 + 2;
    if (uVar3 == 0) {
      uVar3 = 0x100;
    }
    iVar4 = iVar4 + (uint)bVar1;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar2 = iVar4 * 3;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2) = *param_2 << 2;
      pbVar5 = param_2 + 2;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 1) = param_2[1] << 2;
      param_2 = param_2 + 3;
      iVar4 = iVar4 + 1;
      *(byte *)(*(int *)(param_1 + 0x20) + iVar2 + 2) = *pbVar5 << 2;
    }
  }
  *(undefined2 *)(param_1 + 0x1c) = 1;
  return;
}


/* sub_08004466 @ 0x08004466 */

void sub_08004466(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  
  pbVar7 = *(byte **)(param_1 + 0x30);
  iVar4 = (uint)*param_2 + (uint)param_2[1] * 0x100;
  param_2 = param_2 + 2;
  while (iVar4 = iVar4 + -1, iVar4 != -1) {
    iVar5 = (uint)*param_2 + (uint)param_2[1] * 0x100;
    pbVar3 = param_2;
    while( true ) {
      iVar8 = iVar5 * 0x10000 >> 0x10;
      param_2 = pbVar3 + 2;
      pbVar6 = pbVar7;
      if ((uint)(iVar8 << 0x10) >> 0x1e == 0) break;
      if ((uint)(iVar8 << 0x10) >> 0x1e == 3) {
        pbVar7 = pbVar7 + -(iVar8 * (uint)*(ushort *)(param_1 + 4));
      }
      else if (iVar8 < 0) {
        pbVar7[*(ushort *)(param_1 + 4) - 1] = (byte)((uint)(iVar5 * 0x10000) >> 0x10);
      }
      iVar5 = (uint)*param_2 + (uint)pbVar3[3] * 0x100;
      pbVar3 = param_2;
    }
    while (iVar8 != 0) {
      iVar8 = (iVar8 + -1) * 0x10000 >> 0x10;
      pbVar6 = pbVar6 + *param_2;
      iVar5 = (int)(char)param_2[1];
      pbVar3 = param_2 + 2;
      if (iVar5 < 0) {
        bVar1 = param_2[2];
        bVar2 = param_2[3];
        param_2 = param_2 + 4;
        while (iVar5 = iVar5 + 1, iVar5 != 1) {
          *pbVar6 = bVar1;
          pbVar6[1] = bVar2;
          pbVar6 = pbVar6 + 2;
        }
      }
      else {
        for (; param_2 = pbVar3, iVar5 != 0; iVar5 = iVar5 + -1) {
          *pbVar6 = *param_2;
          pbVar6[1] = param_2[1];
          pbVar6 = pbVar6 + 2;
          pbVar3 = param_2 + 2;
        }
      }
    }
    pbVar7 = pbVar7 + *(ushort *)(param_1 + 4);
  }
  return;
}


/* sub_0800453A @ 0x0800453A */

void sub_0800453A(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  
  pbVar4 = param_2 + 4;
  iVar2 = (uint)param_2[2] + (uint)param_2[3] * 0x100;
  pbVar7 = (byte *)(*(int *)(param_1 + 0x30) +
                   ((uint)*param_2 + (uint)param_2[1] * 0x100) * (uint)*(ushort *)(param_1 + 4));
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    uVar6 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar7;
    while (uVar6 != 0) {
      uVar6 = uVar6 - 1;
      pbVar3 = pbVar3 + *pbVar4;
      iVar8 = (int)(char)pbVar4[1];
      pbVar5 = pbVar4 + 2;
      if (iVar8 < 0) {
        bVar1 = *pbVar5;
        pbVar4 = pbVar4 + 3;
        while (iVar8 = iVar8 + 1, iVar8 != 1) {
          *pbVar3 = bVar1;
          pbVar3 = pbVar3 + 1;
        }
      }
      else {
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          *pbVar3 = bVar1;
          pbVar3 = pbVar3 + 1;
          iVar8 = iVar8 + -1;
          pbVar4 = pbVar5;
        } while (iVar8 != 0);
      }
    }
    pbVar7 = pbVar7 + *(ushort *)(param_1 + 4);
  }
  return;
}


/* sub_080045AE @ 0x080045AE */

void sub_080045AE(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = (uint)*(ushort *)(param_1 + 6);
  pbVar4 = *(byte **)(param_1 + 0x30);
  while (uVar6 != 0) {
    uVar6 = uVar6 - 1;
    uVar5 = (uint)*param_2;
    param_2 = param_2 + 1;
    while (uVar5 != 0) {
      uVar5 = uVar5 - 1;
      iVar2 = (int)(char)*param_2;
      pbVar3 = param_2 + 1;
      if (iVar2 < 0) {
        do {
          bVar1 = *pbVar3;
          pbVar3 = pbVar3 + 1;
          *pbVar4 = bVar1;
          pbVar4 = pbVar4 + 1;
          iVar2 = iVar2 + 1;
          param_2 = pbVar3;
        } while (iVar2 != 0);
      }
      else {
        bVar1 = *pbVar3;
        param_2 = param_2 + 2;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pbVar4 = bVar1;
          pbVar4 = pbVar4 + 1;
        }
      }
    }
  }
  return;
}


/* sub_080045F8 @ 0x080045F8 */

undefined4 sub_080045F8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_18;
  
  local_18 = 1;
  if (((param_2 == 1) || (*(short *)(param_1 + 0xe) == 0)) ||
     ((uint)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14)) <= (uint)(DAT_03003b6c << 4))) {
    if (*(ushort *)(param_1 + 0xe) < *(ushort *)(param_1 + 0xc)) {
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) + 1;
    }
    else {
      *(undefined2 *)(param_1 + 0xe) = 1;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
    }
    uVar3 = *(uint *)(param_1 + 0x28);
    if (*(short *)(uVar3 + 4) == -0xf00) {
      uVar1 = (uVar3 << 0x1e) >> 0x1b;
      uVar3 = uVar3 + (*(uint *)(uVar3 & 0xfffffffc) >> uVar1 |
                      ((uint *)(uVar3 & 0xfffffffc))[1] << (0x20 - uVar1 & 0xff));
      *(uint *)(param_1 + 0x28) = uVar3;
    }
    if (*(short *)(uVar3 + 4) == -0xe06) {
      uVar1 = uVar3 + 0x10;
      iVar4 = 0;
      if (*(short *)(uVar3 + 6) != 0) {
        do {
          switch(*(undefined2 *)(uVar1 + 4)) {
          case 4:
            sub_080043AC(param_1,uVar1 + 6);
            break;
          case 7:
            sub_08004466(param_1,uVar1 + 6);
            break;
          case 0xb:
            sub_08004406(param_1,uVar1 + 6);
            break;
          case 0xc:
            sub_0800453A(param_1,uVar1 + 6);
            break;
          case 0xd:
            DAT_030047e8 = 0;
            REG_DMA3SAD = 0x30047e8;
            REG_DMA3DAD = *(undefined4 *)(param_1 + 0x30);
            Ram040000dc = (short)(*(uint *)(param_1 + 8) >> 1);
            DAT_040000de = 0x8100;
            break;
          case 0xf:
            sub_080045AE(param_1,uVar1 + 6);
            break;
          case 0x10:
            REG_DMA3SAD = uVar1 + 6;
            REG_DMA3DAD = *(undefined4 *)(param_1 + 0x30);
            Ram040000dc = (short)(*(uint *)(param_1 + 8) >> 1);
            DAT_040000de = 0x8000;
            goto _08004720;
          }
_08004720:
          uVar2 = (uVar1 << 0x1e) >> 0x1b;
          uVar1 = (*(uint *)(uVar1 & 0xfffffffc) >> uVar2 |
                  ((uint *)(uVar1 & 0xfffffffc))[1] << (0x20 - uVar2 & 0xff)) + uVar1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*(ushort *)(uVar3 + 6));
      }
    }
    else {
      local_18 = 0;
    }
    uVar1 = (uVar3 << 0x1e) >> 0x1b;
    *(uint *)(param_1 + 0x28) =
         *(int *)(param_1 + 0x28) +
         (*(uint *)(uVar3 & 0xfffffffc) >> uVar1 |
         ((uint *)(uVar3 & 0xfffffffc))[1] << (0x20 - uVar1 & 0xff));
    *(int *)(param_1 + 0x18) = DAT_03003b6c << 4;
  }
  else {
    local_18 = 0;
  }
  return local_18;
}


/* sub_08004774 @ 0x08004774 */

void sub_08004774(int param_1)

{
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = *(undefined4 *)(param_1 + 0x30);
  Ram040000dc = (short)((uint)*(ushort *)(param_1 + 6) * (uint)*(ushort *)(param_1 + 4) >> 1);
  DAT_040000de = 0x8100;
  return;
}


/* sub_08004794 @ 0x08004794 */

void sub_08004794(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
  *(undefined2 *)(param_1 + 0xe) = 0;
  return;
}


