/* Ghidra reference decompilation of code_0800ADD4 (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_0800ADD4 @ 0x0800ADD4 */

void sub_0800ADD4(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = (uint)*(byte *)(param_1 + 0x14) * 0x18;
  *(undefined1 *)(param_1 + 0xc) = 0x38;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(&gUnknown_085C224C + iVar2);
  *(char *)(param_1 + 0x11) =
       (char)((int)((uint)*(ushort *)(param_1 + 6) * (uint)*(ushort *)(param_1 + 4)) >> 6);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(&DAT_085c2254 + iVar2) + 4);
  *(undefined *)(param_1 + 0xe) = (&DAT_085c2250)[iVar2];
  *(undefined *)(param_1 + 0xf) = (&DAT_085c2251)[iVar2];
  uVar1 = sub_08005EA6(**(undefined4 **)(&DAT_085c2254 + iVar2));
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  return;
}


/* sub_0800AE10 @ 0x0800AE10 */

void sub_0800AE10(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar2 = (uint)uVar1 * 8;
  puVar3 = (uint *)(&DAT_0202be24 + iVar2);
  uVar4 = *puVar3;
  *puVar3 = uVar4 & 0xffffc0ff;
  uVar6 = ((uint)*(byte *)((int)param_1 + 0xf) << 0x1e) >> 0x10;
  *puVar3 = uVar6 | uVar4 & 0xc1ff00ff;
  uVar5 = (uint)(byte)param_1[7] << 0x1e;
  *puVar3 = uVar5 | uVar6 | uVar4 & 0x1ff00ff;
  uVar1 = param_2[1];
  uVar7 = *(uint *)(&DAT_0202be28 + iVar2);
  *(uint *)(&DAT_0202be28 + iVar2) = uVar1 & 0x3ff | uVar7 & 0xfffffc00 | 0xc00;
  *(uint *)(&DAT_0202be28 + iVar2) =
       uVar1 & 0x3ff | uVar7 & 0xffff0c00 | 0xc00 |
       ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
  uVar7 = ((uint)*param_1 << 0x17) >> 7;
  *puVar3 = uVar5 | uVar6 | uVar4 & 0xff | uVar7;
  *puVar3 = uVar5 | uVar6 | uVar7 | param_1[1] & 0xff;
  REG_DMA3SAD = *(undefined4 *)(param_1 + 4);
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = (short)(((uint)*(byte *)((int)param_1 + 0x11) << 5) >> 2);
  DAT_040000de = 0x8400;
  *(uint *)(param_2 + 2) = *(int *)(param_2 + 2) + (uint)*(byte *)((int)param_1 + 0x11) * 0x20;
  param_2[1] = param_2[1] + (ushort)*(byte *)((int)param_1 + 0x11);
  return;
}


/* sub_0800AEC6 @ 0x0800AEC6 */

int sub_0800AEC6(undefined4 *param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = sub_08002716();
  *(undefined1 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x20) = *param_1;
  sub_0800245A(iVar1,&gUnknown_08011E00);
  return iVar1;
}


/* sub_0800AEF8 @ 0x0800AEF8 */

void sub_0800AEF8(void)

{
  return;
}


/* sub_0800AEFA @ 0x0800AEFA */

void sub_0800AEFA(void)

{
  return;
}


/* sub_0800AEFC @ 0x0800AEFC */

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


/* sub_0800AF80 @ 0x0800AF80 */

undefined4 sub_0800AF80(short *param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  short *psVar4;
  undefined4 local_18;
  
  psVar4 = *(short **)(*(int *)(param_1 + 4) + (uint)*(byte *)((int)param_1 + 0x13) * 4);
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(psVar4 + 2);
  sVar1 = (param_1[0x10] + *psVar4) - DAT_03000608;
  sVar2 = (param_1[0x11] + psVar4[1]) - DAT_0300060a;
  local_18 = CONCAT22(sVar2,sVar1);
  *(undefined4 *)param_1 = local_18;
  if (((((short)(*param_1 + param_1[2]) < 1) || (0xef < sVar1)) ||
      ((short)(param_1[1] + param_1[3]) < 1)) || (0x9f < sVar2)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


/* sub_0800B01E @ 0x0800B01E */

void sub_0800B01E(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + (uint)*(byte *)((int)param_1 + 0x13) * 4);
  uVar1 = *param_2;
  *param_2 = uVar1 + 1;
  iVar2 = (uint)uVar1 * 8;
  puVar3 = (uint *)(&DAT_0202be24 + iVar2);
  uVar5 = *puVar3;
  *puVar3 = uVar5 & 0xffffc0ff;
  uVar7 = ((uint)*(byte *)(iVar4 + 0xb) << 0x1e) >> 0x10;
  *puVar3 = uVar5 & 0xffff00ff | uVar7;
  uVar8 = ((uint)*(byte *)(iVar4 + 9) << 0x1b) >> 2;
  *puVar3 = uVar8 | uVar5 & 0xc1ff00ff | uVar7;
  uVar6 = (uint)*(byte *)(iVar4 + 10) << 0x1e;
  *puVar3 = uVar6 | uVar8 | uVar5 & 0x1ff00ff | uVar7;
  uVar10 = *(uint *)(&DAT_0202be28 + iVar2);
  uVar9 = param_2[1] & 0x3ff;
  *(uint *)(&DAT_0202be28 + iVar2) = uVar9 | uVar10 & 0xfffffc00;
  uVar11 = (((uint)(byte)param_1[6] << 0x1a) >> 0x1e) << 10;
  *(uint *)(&DAT_0202be28 + iVar2) = uVar9 | uVar10 & 0xfffff000 | uVar11;
  *(uint *)(&DAT_0202be28 + iVar2) =
       uVar9 | uVar10 & 0xffff0000 | uVar11 | ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
  uVar9 = ((uint)*param_1 << 0x17) >> 7;
  *puVar3 = uVar6 | uVar8 | uVar5 & 0xff | uVar7 | uVar9;
  *puVar3 = uVar6 | uVar8 | uVar7 | uVar9 | param_1[1] & 0xff;
  REG_DMA3SAD = (uint)*(byte *)(iVar4 + 8) * (uint)(byte)param_1[9] * 0x20 + *(int *)(iVar4 + 0xc);
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = (short)(((uint)*(byte *)(iVar4 + 8) << 5) >> 2);
  DAT_040000de = 0x8400;
  *(uint *)(param_2 + 2) = *(int *)(param_2 + 2) + (uint)*(byte *)(iVar4 + 8) * 0x20;
  param_2[1] = param_2[1] + (ushort)*(byte *)(iVar4 + 8);
  return;
}


/* sub_0800B110 @ 0x0800B110 */

undefined4 sub_0800B110(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  short local_18;
  short sStack_16;
  
  if ((param_2 == 0) &&
     (iVar2 = *(int *)(param_1 + 0x3c), (&DAT_0300004e)[*(byte *)(iVar2 + 6)] != '\0')) {
    uVar1 = sub_08003398();
    local_18 = (short)uVar1;
    if ((*(short *)(iVar2 + 8) <= local_18) &&
       (((local_18 < *(short *)(iVar2 + 0xc) &&
         (sStack_16 = (short)((uint)uVar1 >> 0x10), *(short *)(iVar2 + 10) <= sStack_16)) &&
        (sStack_16 < *(short *)(iVar2 + 0xe))))) {
      *(undefined4 *)(param_1 + 0x38) = 0x8002553;
      (&DAT_0300004e)[*(byte *)(iVar2 + 6)] = (&DAT_0300004e)[*(byte *)(iVar2 + 6)] + -1;
      sub_0800ACFE(7);
      sub_08005526(*(undefined1 *)(iVar2 + 4));
      return 1;
    }
  }
  return 0;
}


/* sub_0800B18E @ 0x0800B18E */

void sub_0800B18E(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar3 = sub_08002716();
  *(undefined1 *)(iVar3 + 0x14) = *(undefined1 *)(param_1 + 6);
  sub_0800245A(iVar3,&gUnknown_08011E24);
  sVar1 = (short)(*(short *)(param_1 + 8) + *(short *)(param_1 + 0xc)) >> 1;
  sVar5 = (short)(*(short *)(param_1 + 10) + *(short *)(param_1 + 0xe)) >> 1;
  local_20 = CONCAT22(sVar5,sVar1);
  local_18 = local_20;
  sVar6 = *(short *)(iVar3 + 4) >> 1;
  sVar2 = *(short *)(iVar3 + 6) >> 1;
  local_1c = CONCAT22(sVar2,sVar6);
  local_14 = local_1c;
  local_1c = CONCAT22(sVar5 - sVar2,sVar1 - sVar6);
  *(undefined4 *)(iVar3 + 0x20) = local_1c;
  *(int *)(iVar3 + 0x3c) = param_1;
  iVar4 = sub_08000954(param_1);
  if (iVar4 == 0) {
    *(undefined4 *)(iVar3 + 0x38) = 0x800b111;
  }
  else {
    sub_08002300(&local_18,iVar3);
    sub_0800507A(DAT_03000600,&local_18,0,0);
  }
  return;
}


/* sub_0800B234 @ 0x0800B234 */

void sub_0800B234(int param_1)

{
  int iVar1;
  
  iVar1 = sub_0800AEFC();
  if (iVar1 == 0) {
    return;
  }
  sub_08000954(*(undefined4 *)(param_1 + 0x3c));
  return;
}


/* sub_0800B260 @ 0x0800B260 */

void sub_0800B260(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = 0;
  do {
    iVar6 = iVar1 * 2;
    uVar2 = (uint)*(ushort *)((int)&DAT_0202c224 + iVar6);
    iVar3 = *(int *)(param_1 + 4);
    iVar4 = (uVar2 & 0x1f) + iVar3 * -4;
    iVar5 = ((uVar2 << 0x16) >> 0x1b) + iVar3 * -4;
    iVar3 = ((uVar2 << 0x11) >> 0x1b) + iVar3 * -4;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar1 = iVar1 + 1;
    *(ushort *)(&DAT_02035824 + iVar6) =
         (ushort)(iVar3 << 10) | (ushort)iVar4 | (ushort)(iVar5 << 5);
  } while (iVar1 < 0x400);
  REG_DMA3SAD = 0x2035824;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8400;
  return;
}


/* sub_0800B2CC @ 0x0800B2CC */

undefined4 sub_0800B2CC(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + 1;
  *(int *)(param_1 + 4) = iVar1;
  if (0x40 < iVar1) {
    return 1;
  }
  return 0;
}


/* sub_0800B2DE @ 0x0800B2DE */

void sub_0800B2DE(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_0800E090(4);
  if (iVar1 == 0) {
    sub_0800E0F8(6,&DAT_03003ba0);
    uVar2 = 0;
    do {
      sub_0800E27C(uVar2 & 0xffff,&DAT_02029b94 + uVar2 * 8);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x40);
    DAT_03004390 = 1;
    return;
  }
  DAT_03004390 = 0;
  return;
}


/* sub_0800B316 @ 0x0800B316 */

undefined4 sub_0800B316(undefined *param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((param_1 < &DAT_02029b94) || (&DAT_02029d94 < param_2)) {
    uVar2 = 0;
  }
  else {
    uVar3 = (int)(param_1 + -0x2029b94) >> 3;
    sub_0800AB00();
    WaitForVBlank(1);
    uVar1 = REG_IE;
    REG_IE = 0x40;
    for (; (int)uVar3 < (int)(param_2 + -0x2029b8d) >> 3; uVar3 = uVar3 + 1) {
      sub_0800E460(uVar3 & 0xffff,&DAT_02029b94 + uVar3 * 8);
    }
    REG_IE = uVar1;
    sub_0800AB12();
    uVar2 = 1;
  }
  return uVar2;
}


/* sub_0800B368 @ 0x0800B368 */

void sub_0800B368(undefined4 param_1,undefined4 param_2)

{
  undefined *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  local_24 = &_0800F004;
  local_20 = 0;
  REG_DMA3SAD = 0x5000000;
  REG_DMA3DAD = 0x202c224;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8400;
  local_1c = param_1;
  uStack_18 = param_2;
  sub_080097F8(&local_24);
  sub_0800B316(local_1c,uStack_18);
  REG_DMA3SAD = 0x202c224;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8400;
  return;
}


/* sub_0800B3DC @ 0x0800B3DC */

void sub_0800B3DC(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = sub_08002716();
  *(undefined4 *)(iVar1 + 0x3c) = param_1;
  sub_08002486(iVar1,*(undefined4 *)(&DAT_08011e38 + param_2 * 4),
               *(undefined4 *)(&gUnknown_08011E44 + param_2 * 4),0,param_4);
  return;
}


/* sub_0800B3FC @ 0x0800B3FC */

void sub_0800B3FC(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  iVar1 = (uint)*(byte *)(iVar2 + 0x13) * 6;
  *(byte *)(param_1 + 0x13) = *(byte *)(iVar2 + 0x13);
  local_c = CONCAT22(*(short *)(iVar2 + 0x22) + *(short *)(&DAT_08011e52 + iVar1),
                     *(short *)(iVar2 + 0x20) + *(short *)(&DAT_08011e50 + iVar1));
  *(undefined4 *)(param_1 + 0x20) = local_c;
  *(char *)(param_1 + 0xc) = (char)*(undefined2 *)(&DAT_08011e54 + iVar1);
  return;
}


/* sub_0800B436 @ 0x0800B436 */

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


/* sub_0800B4AE @ 0x0800B4AE */

void sub_0800B4AE(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 1;
  if (4 < bVar1) {
    *(undefined1 *)(param_1 + 0x10) = 0;
    return;
  }
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  return;
}


/* sub_0800B4C4 @ 0x0800B4C4 */

void sub_0800B4C4(int param_1)

{
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}


/* sub_0800B4CA @ 0x0800B4CA */

void sub_0800B4CA(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  *(byte *)(param_1 + 0x12) = bVar1 >> 3;
  if (0x17 < (byte)(bVar1 + 1)) {
    sub_080028C4();
  }
  return;
}


/* sub_0800B4EC @ 0x0800B4EC */

void sub_0800B4EC(int param_1)

{
  sub_0800B3FC();
  *(undefined4 *)(param_1 + 0x24) = 10;
  return;
}


/* sub_0800B4FA @ 0x0800B4FA */

void sub_0800B4FA(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58) + 0xf >> 4);
  }
  else {
    *(undefined1 *)(param_1 + 0x16) = 0;
    if (*(int *)(param_1 + 0x24) < 0x49) {
      if (*(int *)(param_1 + 0x24) < 0x15) {
        *(undefined **)(param_1 + 0x1c) = &gUnknown_086B3C50;
        *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 5;
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + 5;
      }
      else {
        *(undefined **)(param_1 + 0x1c) = &gUnknown_086B3AD4;
        *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 4;
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + 4;
      }
    }
    else {
      *(undefined **)(param_1 + 0x1c) = &gUnknown_086B3AA8;
    }
    sub_08002466(param_1,1,param_3,param_4,param_4);
  }
  return;
}


/* sub_0800B554 @ 0x0800B554 */

void sub_0800B554(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x12) = 0;
  iVar2 = (uint)*(byte *)(param_1 + 0x13) * 8;
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(&gUnknown_08011E68 + iVar2);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(&DAT_08011e6a + iVar2);
  iVar2 = (uint)*(byte *)(param_1 + 0x13) * 8;
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_08011e6c + iVar2);
  *(undefined2 *)(param_1 + 0x2a) = *(undefined2 *)(&DAT_08011e6e + iVar2);
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x24) = 2;
  sub_0800ACFE(3);
  uVar1 = __16__rt_sdiv(3,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x50));
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  return;
}


/* sub_0800B5A2 @ 0x0800B5A2 */

void sub_0800B5A2(int param_1)

{
  int iVar1;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(param_1 + 0x28);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(param_1 + 0x2a);
  iVar1 = *(int *)(param_1 + 0x24) + -1;
  *(int *)(param_1 + 0x24) = iVar1;
  if (iVar1 == 0) {
    sub_08002466(param_1,2);
  }
  else {
    sub_0800236E(&uStack_2c,param_1);
    uStack_24 = uStack_2c;
    uStack_22 = uStack_2a;
    uStack_20 = uStack_28;
    uStack_1e = uStack_26;
    uStack_1c = *(undefined4 *)(param_1 + 0x2c);
    uStack_18 = (uint)(*(char *)(param_1 + 0x16) != '\0');
    uStack_14 = 0;
    uStack_10 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3c);
    iVar1 = sub_0800283C(1,&uStack_24);
    if ((iVar1 != 0) || (iVar1 = sub_08004FFA(DAT_03000600,&uStack_24,2), iVar1 == 0)) {
      sub_08002466(param_1,2);
    }
  }
  return;
}


/* sub_0800B644 @ 0x0800B644 */

void sub_0800B644(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(char *)(param_1 + 4) == DAT_030005fc) {
    sub_0800283C(2,*(undefined1 *)(param_1 + 5),DAT_030005fc,4,param_4);
  }
  return;
}


/* sub_0800B660 @ 0x0800B660 */

void sub_0800B660(int param_1)

{
  sub_0800B3FC();
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_0800B66E @ 0x0800B66E */

void sub_0800B66E(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58) + 0xf >> 4);
  }
  else {
    sub_08002466(param_1,1,0,param_4,param_4);
  }
  return;
}


/* sub_0800B692 @ 0x0800B692 */

void sub_0800B692(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 0x3c);
  sub_0800ACFE(10);
  iVar1 = *(int *)(iVar2 + 0x58);
  if (iVar1 < *(int *)(param_1 + 0x24)) {
    *(int *)(param_1 + 0x24) = iVar1;
  }
  iVar1 = __16__rt_sdiv(*(undefined4 *)(iVar2 + 0x58),*(int *)(param_1 + 0x24) * 300);
  sub_080087A0(iVar1 + 0x3c);
  DAT_030007e4 = iVar1 + 0x3c + DAT_03003b6c + 0x3c;
  return;
}


/* sub_0800B6D6 @ 0x0800B6D6 */

void sub_0800B6D6(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  *(byte *)(param_1 + 0x12) = bVar1 >> 3;
  if (0x1f < (byte)(bVar1 + 1)) {
    sub_080028C4(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x24) = 2;
  }
  return;
}


/* sub_0800B708 @ 0x0800B708 */

void sub_0800B708(int param_1)

{
  sub_0800B3FC();
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* sub_0800B716 @ 0x0800B716 */

void sub_0800B716(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x3c);
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(iVar1 + 0x58) + 0xf >> 4);
    return;
  }
  if (*(int *)(param_1 + 0x24) * 2 < *(int *)(iVar1 + 0x58)) {
    uVar2 = 8;
  }
  else {
    uVar2 = 0xc;
  }
  sub_0800ACFE(uVar2);
  *(undefined1 *)(param_1 + 0x16) = 0;
  sub_08002466(param_1,1);
  return;
}


/* sub_0800B758 @ 0x0800B758 */

undefined4 sub_0800B758(undefined4 *param_1)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(*(short *)((int)param_1 + 0x22) - DAT_0300060a,
                     *(short *)(param_1 + 8) - DAT_03000608);
  *param_1 = local_8;
  return 1;
}


/* sub_0800B778 @ 0x0800B778 */

void sub_0800B778(ushort *param_1,ushort *param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar6 = (uint)(byte)((byte)param_1[6] >> 4);
  cVar1 = *(char *)((int)param_1 + 0x13);
  if ((cVar1 == '\0') || (cVar1 == '\x01')) {
    iVar3 = (int)(short)param_1[3];
    uVar9 = (uint)(short)param_1[1];
    if (0x1f < iVar3) {
      uVar8 = (uVar6 << 0x1e) >> 0x14;
      do {
        uVar2 = *param_2;
        *param_2 = uVar2 + 1;
        iVar7 = (uint)uVar2 * 8;
        puVar5 = (uint *)(&DAT_0202be24 + iVar7);
        iVar3 = iVar3 + -0x20;
        uVar11 = ((*puVar5 & 0xffff00ff) + 0x8000 & 0x1ffffff) + 0x40000000;
        *puVar5 = uVar11;
        uVar2 = param_2[1];
        uVar10 = *(uint *)(&DAT_0202be28 + iVar7);
        *(uint *)(&DAT_0202be28 + iVar7) = uVar2 & 0x3ff | uVar10 & 0xfffff000 | uVar8;
        *(uint *)(&DAT_0202be28 + iVar7) =
             uVar2 & 0x3ff | uVar10 & 0xffff0000 | uVar8 |
             ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
        uVar10 = uVar9 & 0xff;
        uVar9 = uVar9 + 0x20;
        *puVar5 = uVar11 & 0xfe00ff00 | ((uint)*param_1 << 0x17) >> 7 | uVar10;
      } while (0x1f < iVar3);
    }
    if (0xf < iVar3) {
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      iVar7 = (uint)uVar2 * 8;
      puVar5 = (uint *)(&DAT_0202be24 + iVar7);
      uVar8 = (*puVar5 & 0xffff00ff) + 0x8000;
      *puVar5 = uVar8 & 0x1ffffff;
      uVar2 = param_2[1];
      uVar11 = *(uint *)(&DAT_0202be28 + iVar7);
      uVar10 = (uVar6 << 0x1e) >> 0x14;
      *(uint *)(&DAT_0202be28 + iVar7) = uVar2 & 0x3ff | uVar11 & 0xfffff000 | uVar10;
      *(uint *)(&DAT_0202be28 + iVar7) =
           uVar2 & 0x3ff | uVar11 & 0xffff0000 | uVar10 |
           ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
      uVar11 = uVar9 & 0xff;
      uVar9 = uVar9 + 0x10;
      iVar3 = iVar3 + -0x10;
      *puVar5 = uVar8 & 0xff00 | ((uint)*param_1 << 0x17) >> 7 | uVar11;
    }
    if (7 < iVar3) {
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      iVar7 = (uint)uVar2 * 8;
      puVar5 = (uint *)(&DAT_0202be24 + iVar7);
      *puVar5 = *puVar5 & 0x1ff00ff;
      uVar2 = param_2[1];
      uVar8 = *(uint *)(&DAT_0202be28 + iVar7);
      uVar11 = (uVar6 << 0x1e) >> 0x14;
      *(uint *)(&DAT_0202be28 + iVar7) = uVar2 & 0x3ff | uVar8 & 0xfffff000 | uVar11;
      *(uint *)(&DAT_0202be28 + iVar7) =
           uVar2 & 0x3ff | uVar8 & 0xffff0000 | uVar11 |
           ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
      uVar8 = uVar9 & 0xff;
      uVar9 = uVar9 + 8;
      iVar3 = iVar3 + -8;
      *puVar5 = ((uint)*param_1 << 0x17) >> 7 | uVar8;
    }
    if (0 < iVar3) {
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      iVar7 = (uint)uVar2 * 8;
      puVar5 = (uint *)(&DAT_0202be24 + iVar7);
      *puVar5 = *puVar5 & 0x1ff00ff;
      uVar2 = param_2[1];
      uVar8 = *(uint *)(&DAT_0202be28 + iVar7);
      uVar6 = (uVar6 << 0x1e) >> 0x14;
      *(uint *)(&DAT_0202be28 + iVar7) = uVar6 | uVar2 & 0x3ff | uVar8 & 0xfffff000;
      *(uint *)(&DAT_0202be28 + iVar7) =
           uVar6 | uVar2 & 0x3ff | uVar8 & 0xffff0000 |
           ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
      *puVar5 = (uVar9 + iVar3) - 8 & 0xff | ((uint)*param_1 << 0x17) >> 7;
    }
  }
  else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
    iVar3 = (int)(short)param_1[2];
    iVar7 = (int)(short)*param_1;
    if (0x1f < iVar3) {
      uVar9 = (uVar6 << 0x1e) >> 0x14;
      do {
        uVar2 = *param_2;
        *param_2 = uVar2 + 1;
        iVar4 = (uint)uVar2 * 8;
        puVar5 = (uint *)(&DAT_0202be24 + iVar4);
        iVar3 = iVar3 + -0x20;
        uVar8 = ((*puVar5 & 0xffff00ff) + 0x4000 & 0x1ffffff) + 0x40000000;
        *puVar5 = uVar8;
        uVar2 = param_2[1];
        uVar11 = *(uint *)(&DAT_0202be28 + iVar4);
        *(uint *)(&DAT_0202be28 + iVar4) = uVar2 & 0x3ff | uVar11 & 0xfffff000 | uVar9;
        *(uint *)(&DAT_0202be28 + iVar4) =
             uVar2 & 0x3ff | uVar11 & 0xffff0000 | uVar9 |
             ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
        uVar11 = (uint)(iVar7 << 0x17) >> 7;
        *puVar5 = uVar8 & 0xfe00ffff | uVar11;
        iVar7 = iVar7 + 0x20;
        *puVar5 = uVar8 & 0xfe00ff00 | uVar11 | param_1[1] & 0xff;
      } while (0x1f < iVar3);
    }
    if (0xf < iVar3) {
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      iVar4 = (uint)uVar2 * 8;
      puVar5 = (uint *)(&DAT_0202be24 + iVar4);
      uVar9 = (*puVar5 & 0xffff00ff) + 0x4000;
      *puVar5 = uVar9 & 0x1ffffff;
      uVar2 = param_2[1];
      uVar8 = *(uint *)(&DAT_0202be28 + iVar4);
      uVar11 = (uVar6 << 0x1e) >> 0x14;
      *(uint *)(&DAT_0202be28 + iVar4) = uVar2 & 0x3ff | uVar8 & 0xfffff000 | uVar11;
      *(uint *)(&DAT_0202be28 + iVar4) =
           uVar2 & 0x3ff | uVar8 & 0xffff0000 | uVar11 |
           ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
      uVar8 = (uint)(iVar7 << 0x17) >> 7;
      *puVar5 = uVar9 & 0xffff | uVar8;
      iVar7 = iVar7 + 0x10;
      iVar3 = iVar3 + -0x10;
      *puVar5 = uVar9 & 0xff00 | uVar8 | param_1[1] & 0xff;
    }
    if (7 < iVar3) {
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      iVar4 = (uint)uVar2 * 8;
      puVar5 = (uint *)(&DAT_0202be24 + iVar4);
      uVar9 = *puVar5;
      *puVar5 = uVar9 & 0x1ff00ff;
      uVar2 = param_2[1];
      uVar8 = *(uint *)(&DAT_0202be28 + iVar4);
      uVar11 = (uVar6 << 0x1e) >> 0x14;
      *(uint *)(&DAT_0202be28 + iVar4) = uVar2 & 0x3ff | uVar8 & 0xfffff000 | uVar11;
      *(uint *)(&DAT_0202be28 + iVar4) =
           uVar2 & 0x3ff | uVar8 & 0xffff0000 | uVar11 |
           ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
      uVar8 = (uint)(iVar7 << 0x17) >> 7;
      *puVar5 = uVar9 & 0xff | uVar8;
      iVar7 = iVar7 + 8;
      iVar3 = iVar3 + -8;
      *puVar5 = uVar8 | param_1[1] & 0xff;
    }
    if (0 < iVar3) {
      uVar2 = *param_2;
      *param_2 = uVar2 + 1;
      iVar4 = (uint)uVar2 * 8;
      puVar5 = (uint *)(&DAT_0202be24 + iVar4);
      uVar9 = *puVar5;
      *puVar5 = uVar9 & 0x1ff00ff;
      uVar2 = param_2[1];
      uVar8 = *(uint *)(&DAT_0202be28 + iVar4);
      uVar6 = (uVar6 << 0x1e) >> 0x14;
      *(uint *)(&DAT_0202be28 + iVar4) = uVar6 | uVar2 & 0x3ff | uVar8 & 0xfffff000;
      *(uint *)(&DAT_0202be28 + iVar4) =
           uVar6 | uVar2 & 0x3ff | uVar8 & 0xffff0000 |
           ((uint)*(byte *)((int)param_1 + 0xd) << 0x1c) >> 0x10;
      uVar6 = (uint)((iVar7 + iVar3 + -8) * 0x800000) >> 7;
      *puVar5 = uVar6 | uVar9 & 0xff;
      *puVar5 = uVar6 | param_1[1] & 0xff;
    }
  }
  REG_DMA3SAD = (&gUnknown_081C7AE4)
                [(uint)(byte)param_1[10] * 4 + (uint)*(byte *)((int)param_1 + 0x13)];
  REG_DMA3DAD = *(undefined4 *)(param_2 + 2);
  Ram040000dc = 0x20;
  DAT_040000de = 0x8400;
  *(int *)(param_2 + 2) = *(int *)(param_2 + 2) + 0x80;
  param_2[1] = param_2[1] + 4;
  return;
}


/* sub_0800BCA0 @ 0x0800BCA0 */

void sub_0800BCA0(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 8;
  *(undefined2 *)(param_1 + 6) = 8;
  iVar1 = (uint)*(byte *)(param_1 + 0x13) * 4;
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(&DAT_08011ee8 + iVar1);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(&DAT_08011eea + iVar1);
  *(undefined **)(param_1 + 0x28) = &gUnknown_08011E88 + (uint)*(byte *)(param_1 + 0x13) * 8;
  return;
}


/* sub_0800BCD8 @ 0x0800BCD8 */

void sub_0800BCD8(int param_1)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  uint local_14;
  undefined1 local_10;
  undefined4 local_c;
  
  psVar3 = *(short **)(param_1 + 0x28);
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *psVar3;
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + psVar3[1];
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + psVar3[2];
  *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + psVar3[3];
  sub_08002300(&local_28,param_1);
  local_20 = local_28;
  local_1e = local_26;
  local_1c = local_24;
  local_1a = local_22;
  local_18 = *(undefined4 *)(param_1 + 0x24);
  local_14 = (uint)(*(char *)(param_1 + 0x16) != '\0');
  local_10 = 1;
  local_c = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3c);
  sub_0800286A(1,&local_20);
  iVar2 = sub_08004FFA(DAT_03000600,&local_20,2);
  if (iVar2 == 0) {
    *(undefined **)(param_1 + 0x28) = &UNK_08011ec8 + (uint)*(byte *)(param_1 + 0x13) * 8;
    sub_08002466(param_1,2);
  }
  else {
    bVar1 = *(char *)(param_1 + 0x10) + 1;
    *(byte *)(param_1 + 0x10) = bVar1;
    if (0xf < bVar1) {
      *(undefined **)(param_1 + 0x28) = &UNK_08011ea8 + (uint)*(byte *)(param_1 + 0x13) * 8;
      sub_08002466(param_1,2);
    }
  }
  return;
}


/* sub_0800BD8E @ 0x0800BD8E */

void sub_0800BD8E(int param_1)

{
  int iVar1;
  
  iVar1 = __16__rt_sdiv(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58),
                        *(int *)(param_1 + 0x24) * (uint)*(byte *)(param_1 + 0x10));
  *(char *)(param_1 + 0x14) = (char)(iVar1 >> 1);
  if (2 < (iVar1 >> 1 & 0xffU)) {
    *(undefined1 *)(param_1 + 0x14) = 2;
  }
  return;
}


/* sub_0800BDB4 @ 0x0800BDB4 */

void sub_0800BDB4(int param_1)

{
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x24) = 2;
  return;
}


/* sub_0800BDC0 @ 0x0800BDC0 */

void sub_0800BDC0(int param_1)

{
  byte bVar1;
  
  bVar1 = *(char *)(param_1 + 0x10) + 1;
  *(byte *)(param_1 + 0x10) = bVar1;
  if (7 < bVar1) {
    sub_080028C4();
  }
  return;
}


/* sub_0800BDD6 @ 0x0800BDD6 */

void sub_0800BDD6(int param_1)

{
  short *psVar1;
  
  psVar1 = *(short **)(param_1 + 0x28);
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *psVar1;
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + psVar1[1];
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + psVar1[2];
  *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + psVar1[3];
  return;
}


/* sub_0800BE1C @ 0x0800BE1C */

void sub_0800BE1C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ((*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x18)) + *(int *)(param_1 + 0x2c));
  *(undefined4 **)(param_1 + 0x30) = puVar1;
  __call_via_r1(param_1,*puVar1,*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x2c),param_4);
  return;
}


/* sub_0800BE32 @ 0x0800BE32 */

void sub_0800BE32(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x30) + 4),param_3,param_4,param_4);
  return;
}


/* sub_0800BE3E @ 0x0800BE3E */

void sub_0800BE3E(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x30) + 8),param_3,param_4,param_4);
  return;
}


/* sub_0800BE4A @ 0x0800BE4A */

void sub_0800BE4A(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc),param_3,param_4,param_4);
  return;
}


/* sub_0800BE56 @ 0x0800BE56 */

void sub_0800BE56(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __call_via_r2(param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x10),param_4,param_4);
  return;
}


/* sub_0800BE62 @ 0x0800BE62 */

void sub_0800BE62(int param_1)

{
  uint uVar1;
  
  sub_0800BE32();
  uVar1 = *(int *)(param_1 + 0x28) - 1;
  *(uint *)(param_1 + 0x28) = uVar1;
  if ((uVar1 & 0xf) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    (&DAT_03000994)[(uint)DAT_03004394 * 2] = (&DAT_03000994)[(uint)DAT_03004394 * 2] + -1;
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) >> 4;
    sub_08002450(param_1);
    if ((uVar1 & 0x10) != 0) {
      sub_08002466(param_1,2);
    }
  }
  return;
}


/* sub_0800BE64 @ 0x0800BE64 */

void sub_0800BE64(int param_1)

{
  uint uVar1;
  
  sub_0800BE32();
  uVar1 = *(int *)(param_1 + 0x28) - 1;
  *(uint *)(param_1 + 0x28) = uVar1;
  if ((uVar1 & 0xf) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    (&DAT_03000994)[(uint)DAT_03004394 * 2] = (&DAT_03000994)[(uint)DAT_03004394 * 2] + -1;
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) >> 4;
    sub_08002450(param_1);
    if ((uVar1 & 0x10) != 0) {
      sub_08002466(param_1,2);
    }
  }
  return;
}


/* sub_0800BEA8 @ 0x0800BEA8 */

bool sub_0800BEA8(int param_1)

{
  return *(undefined **)(param_1 + 0x18) == &gUnknown_08011F18;
}


/* sub_0800BEB8 @ 0x0800BEB8 */

void sub_0800BEB8(int param_1)

{
  if ((-1 < *(int *)(param_1 + 0x28) << 0x1b) &&
     (*(undefined4 *)(param_1 + 0x28) = 8, *(undefined **)(param_1 + 0x18) != &gUnknown_08011F18)) {
    DAT_03004394 = sub_08005EA6(&DAT_08011ef8);
    *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) * '\x10' + DAT_03004394;
    sub_0800242C(param_1,&gUnknown_08011F18);
  }
  return;
}


/* sub_0800BEEC @ 0x0800BEEC */

void sub_0800BEEC(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0x18;
  if (*(undefined **)(param_1 + 0x18) != &gUnknown_08011F18) {
    DAT_03004394 = sub_08005EA6(&DAT_08011ef8);
    *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) * '\x10' + DAT_03004394;
    sub_0800242C(param_1,&gUnknown_08011F18);
  }
  return;
}


/* sub_0800BF28 @ 0x0800BF28 */

void sub_0800BF28(void)

{
  sub_0800B4EC();
  return;
}


/* sub_0800BF30 @ 0x0800BF30 */

void sub_0800BF30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_1 + 0x24) < *(int *)(param_1 + 0x2c)) {
    sub_0800B436(param_1,*(int *)(param_1 + 0x2c) + 7 >> 3,*(int *)(param_1 + 0x24),param_4,param_4)
    ;
  }
  else {
    *(undefined1 *)(param_1 + 0x16) = 1;
    sub_08002466();
  }
  return;
}


/* sub_0800BF4E @ 0x0800BF4E */

void sub_0800BF4E(int param_1)

{
  int iVar1;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  uint local_18;
  ushort local_14;
  short sStack_12;
  undefined4 local_10;
  
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(param_1 + 0x28);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(param_1 + 0x2a);
  sub_08002300(&local_14,param_1);
  if (((((short)local_14 < DAT_0300060c) && (DAT_03000608 < (short)local_10)) &&
      (sStack_12 < DAT_0300060e)) && (DAT_0300060a < local_10._2_2_)) {
    sub_0800236E(&local_2c,param_1);
    local_24 = local_2c;
    local_22 = local_2a;
    local_20 = local_28;
    local_1e = local_26;
    local_1c = *(undefined4 *)(param_1 + 0x2c);
    local_18 = (uint)(*(char *)(param_1 + 0x16) != '\0');
    local_14 = local_14 & 0xff00;
    local_10 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3c);
    iVar1 = sub_0800283C(1,&local_24);
    if ((iVar1 != 0) || (iVar1 = sub_08004FFA(DAT_03000600,&local_24,2), iVar1 == 0)) {
      sub_08002466(param_1,2);
    }
  }
  else {
    sub_08002466(param_1,2);
  }
  return;
}


/* sub_0800C010 @ 0x0800C010 */

void sub_0800C010(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  sub_08002466(param_1,5);
  iVar1 = sub_08002716();
  *(int *)(iVar1 + 0x3c) = param_1;
  *(undefined4 *)(iVar1 + 0x2c) = param_3;
  param_2 = param_2 * 4;
  if (**(char **)(*(int *)(param_1 + 0x3c) + 4) == 'v') {
    sub_08002486(iVar1,&gUnknown_086B3400,*(undefined4 *)(&gUnknown_0801206C + param_2),0);
    return;
  }
  sub_08002486(iVar1,*(undefined4 *)(&DAT_08012070 + param_2),
               *(undefined4 *)(&gUnknown_0801206C + param_2),0);
  return;
}


/* sub_0800C060 @ 0x0800C060 */

void sub_0800C060(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_0801207C);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(5,0xd);
  return;
}


/* sub_0800C090 @ 0x0800C090 */

void sub_0800C090(void)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_0800946E(&DAT_08012084,&DAT_02029d94);
  sub_08009486(&DAT_080120b8,&DAT_02029d94);
  DAT_02029d94 = 0xe;
  iVar1 = sub_0800084A(0);
  if (iVar1 == 0) {
    sub_0800946E(&gUnknown_08012098,&DAT_02029d94);
  }
  iVar1 = sub_0800084A(1);
  if (iVar1 == 0) {
    sub_0800946E(&gUnknown_080120A8,&DAT_02029d94);
  }
  DAT_02029d94 = 0xf;
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_0800C0EA @ 0x0800C0EA */

undefined4 sub_0800C0EA(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = sub_080094B8(&DAT_080120b8,param_1 + 4);
  if (iVar2 != 0) {
    uVar3 = (uint)*(byte *)(param_1 + 4);
    if (1 < uVar3) {
      uVar3 = 4;
    }
    sub_08000A32(5,uVar3 + 0xd);
    sub_0800ACFE(0);
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  else if ((DAT_03003d14 & 1) != 0) {
    cVar1 = *(char *)(param_1 + 4);
    if ((cVar1 == '\0') || (cVar1 == '\x01')) {
      iVar2 = sub_0800084A();
      if (iVar2 == 0) {
        sub_0800ACFE(0x13);
      }
      else {
        sub_0800ACFE(1);
        sub_08000882(&DAT_03000028,*(undefined1 *)(param_1 + 4));
      }
    }
    else if (cVar1 == '\x02') {
      sub_0800ACFE(0);
      sub_08009798();
    }
  }
  return 0;
}


/* sub_0800C184 @ 0x0800C184 */

undefined4 sub_0800C184(void)

{
  return 0;
}


/* sub_0800C188 @ 0x0800C188 */

void sub_0800C188(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_2 + 0x15) != -1) {
    piVar1 = (int *)(param_1 + 4);
    iVar3 = *piVar1;
    *piVar1 = iVar3 + 1;
    piVar1[iVar3 * 6 + 2] = 0;
    piVar1[iVar3 * 6 + 1] = param_2;
    piVar1[iVar3 * 6 + 3] = *(int *)(param_2 + 0x18);
    piVar1[iVar3 * 6 + 4] = *(int *)(param_2 + 0x38);
    *(undefined1 *)(piVar1 + iVar3 * 6 + 5) = 0;
    *(undefined1 *)((int)piVar1 + iVar3 * 0x18 + 0x15) = *(undefined1 *)(param_2 + 0xd);
    iVar2 = sub_0800241E(param_2);
    piVar1[iVar3 * 6 + 6] = (uint)(iVar2 == 2);
    iVar2 = __call_via_r3(param_2,3,0,*(undefined4 *)(param_2 + 0x38));
    if (iVar2 != 0) {
      piVar1[iVar3 * 6 + 2] = *(int *)(param_2 + 0x3c);
    }
    if (piVar1[iVar3 * 6 + 6] == 0) {
      iVar2 = sub_0800BEA8(param_2);
      if (iVar2 != 0) {
        *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xd) >> 4;
        *(undefined4 *)(param_2 + 0x28) = 1;
      }
      *(undefined ***)(param_2 + 0x18) = &gUnknown_085429A0;
      *(undefined4 *)(param_2 + 0x38) = 0x800c185;
      sub_08002466(param_2,(char)piVar1[iVar3 * 6 + 5]);
    }
  }
  return;
}


/* sub_0800C20A @ 0x0800C20A */

void sub_0800C20A(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 4) = 0;
  iVar1 = DAT_03000610;
  iVar2 = 0;
  if (0 < DAT_03000610) {
    do {
      sub_0800C188(param_1,(&DAT_03000614)[iVar2]);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}


/* sub_0800C232 @ 0x0800C232 */

void sub_0800C232(int param_1,int param_2)

{
  int iVar1;
  int local_8 [2];
  
  if (*(char *)(param_2 + 0x15) != -1) {
    local_8[0] = param_2;
    iVar1 = sub_0800FE0C(param_1 + 4,local_8);
    *(undefined1 *)(local_8[0] + 0xd) = *(undefined1 *)(iVar1 + 0x11);
    if (*(int *)(iVar1 + 0x14) == 0) {
      *(undefined4 *)(local_8[0] + 0x18) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(local_8[0] + 0x38) = *(undefined4 *)(iVar1 + 0xc);
      sub_08002466(local_8[0],*(undefined1 *)(iVar1 + 0x10));
    }
  }
  return;
}


/* sub_0800C266 @ 0x0800C266 */

void sub_0800C266(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  
  iVar1 = DAT_03000610;
  iVar3 = 0;
  if (0 < DAT_03000610) {
    do {
      local_18 = (&DAT_03000614)[iVar3];
      if (*(char *)(local_18 + 0x15) != -1) {
        iVar2 = sub_0800FE0C(param_1 + 4,&local_18);
        *(undefined1 *)(local_18 + 0xd) = *(undefined1 *)(iVar2 + 0x11);
        if (*(int *)(iVar2 + 0x14) == 0) {
          *(undefined4 *)(local_18 + 0x18) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(local_18 + 0x38) = *(undefined4 *)(iVar2 + 0xc);
          sub_08002466(local_18,*(undefined1 *)(iVar2 + 0x10));
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


/* sub_0800C2B2 @ 0x0800C2B2 */

void sub_0800C2B2(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  if (*(char *)(param_2 + 0x15) != -1) {
    piVar1 = (int *)(param_1 + 4);
    local_c = param_2;
    iVar2 = sub_0800FE0C(piVar1,&local_c,param_3,param_4,param_1);
    iVar2 = __16__rt_sdiv(0x18,iVar2 - (param_1 + 8));
    iVar3 = *piVar1;
    *piVar1 = iVar3 + -1;
    iVar3 = (iVar3 + -1) - iVar2;
    if (iVar3 != 0) {
      REG_DMA3SAD = piVar1 + iVar2 * 6 + 7;
      REG_DMA3DAD = piVar1 + iVar2 * 6 + 1;
      Ram040000dc = (short)((uint)(iVar3 * 0x18) >> 2);
      DAT_040000de = 0x8400;
    }
    sub_080028C4(local_c);
  }
  return;
}


/* sub_0800C306 @ 0x0800C306 */

void sub_0800C306(int param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      if (*(byte *)(*(int *)(iVar1 * 0x18 + param_1 + 4 + 4) + 0x15) == param_2) {
        *(undefined1 *)(iVar1 * 0x18 + param_1 + 4 + 0x14) = param_3;
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return;
}


/* sub_0800C338 @ 0x0800C338 */

int sub_0800C338(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      if (*(byte *)(*(int *)(iVar1 * 0x18 + param_1 + 4 + 4) + 0x15) == param_2) {
        iVar1 = iVar1 * 0x18 + param_1 + 4;
        iVar2 = *(int *)(iVar1 + 4);
        if (param_3 == 0) {
          return iVar2;
        }
        if (*(int *)(iVar1 + 0x18) == 0) {
          return iVar2;
        }
        *(undefined4 *)(iVar1 + 0x18) = 0;
        iVar1 = sub_0800BEA8(iVar2);
        if (iVar1 != 0) {
          *(byte *)(iVar2 + 0xd) = *(byte *)(iVar2 + 0xd) >> 4;
          *(undefined4 *)(iVar2 + 0x28) = 1;
        }
        *(undefined ***)(iVar2 + 0x18) = &gUnknown_085429A0;
        *(undefined4 *)(iVar2 + 0x38) = 0x800c185;
        return iVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return 0;
}


/* sub_0800C398 @ 0x0800C398 */

undefined4 sub_0800C398(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_8 [2];
  
  auStack_8[0] = param_2;
  iVar1 = sub_0800FE0C(param_1 + 4,auStack_8);
  return *(undefined4 *)(iVar1 + 4);
}


/* sub_0800C3AA @ 0x0800C3AA */

void sub_0800C3AA(int param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar6 = *(int *)(param_1 + 4);
  iVar3 = 0;
  if (0 < iVar6) {
    do {
      iVar4 = *(int *)(iVar3 * 0x18 + param_1 + 8);
      if ((*param_2 != *(short *)(iVar4 + 0x20)) || (param_2[1] != *(short *)(iVar4 + 0x22))) {
        sVar1 = *param_2 - *(short *)(iVar4 + 0x20);
        sVar2 = param_2[1] - *(short *)(iVar4 + 0x22);
        local_18 = CONCAT22(sVar2,sVar1);
        local_14 = local_18;
        iVar7 = (int)sVar2 * (int)sVar2;
        iVar5 = (int)sVar1 * (int)sVar1;
        uVar8 = (uint)(iVar7 - iVar5 != 0 && iVar5 <= iVar7);
        *(char *)(iVar4 + 0x13) =
             (char)*(undefined4 *)
                    (&gUnknown_080120E4 +
                    (((int)*(short *)((int)&local_14 + uVar8 * 2) >> 0x1f) + 1) * 4 + uVar8 * 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar6);
  }
  return;
}


/* sub_0800C42E @ 0x0800C42E */

void sub_0800C42E(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined *local_91c;
  undefined4 local_918;
  
  sub_0800286A(4,0);
  iVar3 = DAT_03000610;
  iVar2 = 0;
  local_91c = &_0800EF08;
  local_918 = 0;
  if (0 < DAT_03000610) {
    do {
      sub_0800C188(&local_91c,(&DAT_03000614)[iVar2]);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  iVar3 = 0;
  if (0 < *param_1) {
    do {
      puVar1 = *(undefined4 **)(param_1[1] + iVar3 * 4);
      __call_via_r2(puVar1,&local_91c,*puVar1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  sub_0800C266(&local_91c);
  sub_0800286A(5,0);
  return;
}


/* sub_0800C4C0 @ 0x0800C4C0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800C4C0(int param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  DAT_030043a8 = *param_3;
  if ((short)DAT_030043a8 < 0) {
    DAT_030043a8 = DAT_030043a8 & 0xffff0000;
  }
  if ((int)DAT_030043a8 < 0) {
    DAT_030043a8 = DAT_030043a8 & 0xffff;
  }
  uVar1 = **(undefined4 **)(param_1 + 0x1c);
  local_1c._0_2_ = (short)uVar1;
  local_1c._0_2_ = DAT_030005f8 - (short)local_1c;
  local_1c._2_2_ = (short)((uint)uVar1 >> 0x10);
  local_1c._2_2_ = DAT_030005fa - local_1c._2_2_;
  local_20 = CONCAT22(local_1c._2_2_,(short)local_1c);
  local_18 = local_20;
  if ((short)local_1c < (short)DAT_030043a8) {
    DAT_030043a8 = CONCAT22(DAT_030043a8._2_2_,(short)local_1c);
  }
  if (local_1c._2_2_ < DAT_030043a8._2_2_) {
    DAT_030043a8 = CONCAT22(local_1c._2_2_,(short)DAT_030043a8);
  }
  DAT_0300444a = 1;
  DAT_030043f6 = 0;
  DAT_0300444c = 1;
  DAT_030043f8 = 0xc;
  DAT_030043e4 = 4;
  DAT_03004458 = 0;
  DAT_0300445c = 0;
  DAT_030043c6 = 0x8001;
  DAT_03004428 = (int)*(short *)(param_1 + 0x20) >> 3;
  DAT_0300442c = (int)*(short *)(param_1 + 0x22) >> 3;
  _DAT_03004430 = 0;
  DAT_03004432 = 0;
  DAT_030043a0 = param_1;
  DAT_030043a4 = param_2;
  DAT_03004624 = param_1;
  local_1c = uVar1;
  sub_080085A0(&DAT_030043b0,param_1 + 0x20);
  sub_0800236E(&local_20,param_1);
  sub_0800507A(DAT_03000600,&local_20,1,0);
  sub_08002E42(&local_20);
  sub_0800507A(DAT_03000600,&local_20,1,0);
  local_20 = CONCAT22(DAT_030043a8._2_2_ >> 3,(short)DAT_030043a8 >> 3);
  local_1c = local_20;
  sub_08006F1A(&DAT_030043b0,&local_1c,0);
  sub_08002466(param_1,1);
  return;
}


/* sub_0800C5CE @ 0x0800C5CE */

void sub_0800C5CE(void)

{
  sub_08002910();
  DAT_030043a0 = 0;
  return;
}


/* sub_0800C5DC @ 0x0800C5DC */

void sub_0800C5DC(void)

{
  return;
}


/* sub_0800C5DE @ 0x0800C5DE */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void sub_0800C5DE(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint *puStack_18;
  
  sVar1 = *(short *)(param_1 + 0x20);
  puVar7 = (uint *)(param_1 + 0x20);
  if (((short)DAT_030043a8 == sVar1) && (DAT_030043a8._2_2_ == *(short *)(param_1 + 0x22))) {
    sub_0800236E(&uStack_20,param_1);
    sub_0800507A(DAT_03000600,&uStack_20,0,0);
    sub_08002466(param_1,0);
    goto _0800C8F4;
  }
  uVar2 = (short)DAT_030043a8 >> 3;
  sVar5 = DAT_030043a8._2_2_ >> 3;
  if ((__iwram_end == sVar1) && (DAT_03000002 == *(short *)(param_1 + 0x22))) {
    DAT_030043ac = DAT_030043ac + 1;
    if (0x1f < DAT_030043ac) {
      DAT_0300445c = 0;
      DAT_03004458 = 0;
      uStack_1c = CONCAT22(sVar5,uVar2);
      _DAT_03004430 = uStack_1c;
    }
  }
  else {
    DAT_03000002 = *(short *)(param_1 + 0x22);
    DAT_030043ac = 0;
    __iwram_end = sVar1;
  }
  puStack_18 = &DAT_030043d0;
  if (DAT_03004458 < DAT_0300445c) {
    uStack_1c = DAT_030043d0;
    uVar4 = uStack_1c;
    uVar2 = *(short *)(DAT_03004458 * 4 + 0x3004460) << 3;
    sVar1 = *(short *)(DAT_03004458 * 4 + 0x3004462) << 3;
    uStack_24 = CONCAT22(sVar1,uVar2);
    uStack_20 = uStack_24;
    uStack_1c._0_2_ = (short)DAT_030043d0;
    uStack_1c._2_2_ = (short)(DAT_030043d0 >> 0x10);
    if (((uint)uVar2 == (DAT_030043d0 & 0xffff)) && (sVar1 == uStack_1c._2_2_)) {
      DAT_03004458 = DAT_03004458 + 1;
      DAT_03004428 = (int)(short)uStack_1c >> 3;
      DAT_0300442c = (int)uStack_1c._2_2_ >> 3;
      if (DAT_0300445c <= DAT_03004458) {
        *(uint *)(param_1 + 0x20) = DAT_030043d0;
        return;
      }
      uStack_24 = CONCAT22(*(short *)(DAT_03004458 * 4 + 0x3004462) << 3,
                           *(short *)(DAT_03004458 * 4 + 0x3004460) << 3);
      uStack_20 = uStack_24;
    }
    uStack_1c = uVar4;
    if ((uStack_20 & 0xffff) == (DAT_030043d0 & 0xffff)) {
      if (uStack_1c._2_2_ < uStack_20._2_2_) {
        iVar3 = ((uint)uRam030043d6 + (uint)uRam030043bc) * 0x10000;
        uRam030043d6 = (ushort)((uint)iVar3 >> 0x10);
        if ((int)uStack_20._2_2_ < iVar3 >> 0x14) {
          uRam030043d6 = uStack_20._2_2_ << 4;
        }
        sub_0800F4DC(&DAT_030043b8);
        DAT_030043b8 = 0;
      }
      else {
        iVar3 = ((uint)uRam030043d6 - (uint)uRam030043bc) * 0x10000;
        uRam030043d6 = (ushort)((uint)iVar3 >> 0x10);
        if (iVar3 >> 0x14 < (int)uStack_20._2_2_) {
          uRam030043d6 = uStack_20._2_2_ << 4;
        }
        sub_0800F4DC(&DAT_030043b8);
        DAT_030043b8 = 1;
      }
      DAT_0300442c = (int)DAT_030043d0._2_2_ >> 3;
    }
    else {
      if ((short)uStack_1c < (short)uStack_20) {
        iVar3 = ((uint)uRam030043d4 + (uint)uRam030043bc) * 0x10000;
        uRam030043d4 = (ushort)((uint)iVar3 >> 0x10);
        if ((int)(short)uStack_20 < iVar3 >> 0x14) {
          uRam030043d4 = (ushort)((uStack_20 & 0xffff) << 4);
        }
        sub_0800F4DC(&DAT_030043b8);
        DAT_030043b8 = 3;
      }
      else {
        iVar3 = ((uint)uRam030043d4 - (uint)uRam030043bc) * 0x10000;
        uRam030043d4 = (ushort)((uint)iVar3 >> 0x10);
        if (iVar3 >> 0x14 < (int)(short)uStack_20) {
          uRam030043d4 = (ushort)((uStack_20 & 0xffff) << 4);
        }
        sub_0800F4DC(&DAT_030043b8);
        DAT_030043b8 = 2;
      }
      DAT_03004428 = (int)(short)DAT_030043d0 >> 3;
    }
    *(uint *)(param_1 + 0x20) = *puStack_18;
    *(undefined1 *)(param_1 + 0x13) = DAT_030043b8;
  }
  else {
    uStack_24 = CONCAT22(sVar5,uVar2);
    uStack_20 = uStack_24;
    if (((_DAT_03004430 & 0xffff) != (uint)uVar2) || (DAT_03004432 != sVar5)) {
      uStack_24 = CONCAT22(sVar5,uVar2);
      uStack_1c = uStack_24;
      iVar3 = sub_08006F1A(&DAT_030043b0,&uStack_1c,0);
      if (iVar3 != 0) goto _0800C8E4;
    }
    sVar1 = (short)DAT_030043a8 - *(short *)puVar7;
    sVar5 = DAT_030043a8._2_2_ - *(short *)(param_1 + 0x22);
    uStack_20 = CONCAT22(sVar5,sVar1);
    uStack_1c = uStack_20;
    if ((int)(char)(&DAT_080120f8)[*(byte *)(param_1 + 0x13)] *
        (int)*(short *)((int)&uStack_1c +
                       (uint)(byte)(&gUnknown_080120F4)[*(byte *)(param_1 + 0x13)] * 2) < 1) {
      iVar3 = (int)sVar5 * (int)sVar5;
      iVar6 = (int)sVar1 * (int)sVar1;
      iVar3 = (uint)(iVar3 - iVar6 != 0 && iVar6 <= iVar3) * 2;
      *(undefined *)(param_1 + 0x13) =
           (&DAT_080120fc)[(uint)(0 < *(short *)((int)&uStack_1c + iVar3)) + iVar3];
    }
    iVar3 = (uint)*(byte *)(param_1 + 0x13) * 4;
    *(short *)puVar7 = *(short *)puVar7 + *(short *)(&DAT_08012100 + iVar3);
    *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(&DAT_08012102 + iVar3);
    *(undefined1 *)(param_1 + 0xc) = 0x18;
    uVar4 = *puVar7;
    DAT_030043d0._0_2_ = (short)uVar4;
    DAT_03004428 = (int)(short)DAT_030043d0 >> 3;
    DAT_030043d0._2_2_ = (short)(uVar4 >> 0x10);
    DAT_0300442c = (int)DAT_030043d0._2_2_ >> 3;
    DAT_0300445c = 0;
    DAT_03004458 = 0;
    uStack_20 = CONCAT22(DAT_030043a8._2_2_ >> 3,(short)DAT_030043a8 >> 3);
    _DAT_03004430 = uStack_20;
    DAT_030043d0 = uVar4;
  }
_0800C8E4:
  sub_08002328(&uStack_20,param_1);
  sub_08002134(&uStack_20);
_0800C8F4:
  iVar3 = DAT_030043a4;
  if (DAT_030043a4 != 0) {
    sVar1 = *(short *)puVar7;
    sVar5 = *(short *)(param_1 + 0x22);
    *(uint *)(DAT_030043a4 + 0x20) = *puVar7;
    uStack_20 = CONCAT22(sVar5 << 4,sVar1 << 4);
    *(uint *)(iVar3 + 0x24) = uStack_20;
    *(ushort *)(iVar3 + 0x2c) = (ushort)*(byte *)(iVar3 + 0x28) + *(short *)(iVar3 + 0x20);
    *(ushort *)(iVar3 + 0x2e) = (ushort)*(byte *)(iVar3 + 0x29) + *(short *)(iVar3 + 0x22);
    *(ushort *)(iVar3 + 0x30) =
         (ushort)*(byte *)(iVar3 + 0x28) + (ushort)*(byte *)(iVar3 + 0x2a) +
         *(short *)(iVar3 + 0x20);
    *(ushort *)(iVar3 + 0x32) =
         (ushort)*(byte *)(iVar3 + 0x29) + (ushort)*(byte *)(iVar3 + 0x2b) +
         *(short *)(iVar3 + 0x22);
    *(int *)(iVar3 + 0x78) = (int)*(short *)puVar7 >> 3;
    *(int *)(iVar3 + 0x7c) = (int)*(short *)(param_1 + 0x22) >> 3;
  }
  return;
}


/* sub_0800C984 @ 0x0800C984 */

void sub_0800C984(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '@') {
    DAT_030043a0 = 0;
    *(undefined1 *)(param_1 + 0x10) = 0x41;
  }
  return;
}


/* sub_0800C996 @ 0x0800C996 */

void sub_0800C996(void)

{
  return;
}


/* sub_0800C998 @ 0x0800C998 */

void sub_0800C998(void)

{
  sub_08003B28();
  return;
}


/* sub_0800C9A0 @ 0x0800C9A0 */

void sub_0800C9A0(int param_1)

{
  if ((DAT_030043a0 == param_1) && (*(char *)(param_1 + 0x10) == ' ')) {
    DAT_030043a0 = 0;
  }
  return;
}


/* sub_0800C9B4 @ 0x0800C9B4 */

void sub_0800C9B4(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10) + '\x01';
  *(char *)(param_1 + 0x10) = cVar1;
  if ((DAT_030043a0 != param_1) && (DAT_030043a0 != 0)) {
    *(char *)(param_1 + 0x12) = '\x01' - ((char)(cVar1 * ' ') >> 7);
    return;
  }
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}


/* sub_0800C9DA @ 0x0800C9DA */

void sub_0800C9DA(void)

{
  return;
}


/* sub_0800C9DC @ 0x0800C9DC */

void sub_0800C9DC(void)

{
  return;
}


/* sub_0800C9DE @ 0x0800C9DE */

void sub_0800C9DE(void)

{
  return;
}


/* sub_0800C9E0 @ 0x0800C9E0 */

void sub_0800C9E0(void)

{
  return;
}


/* sub_0800C9E2 @ 0x0800C9E2 */

void sub_0800C9E2(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  *(byte *)(param_1 + 0x12) = bVar1 >> 4;
  *(byte *)(param_1 + 0x10) = bVar1 + 1;
  if (0x4f < (byte)(bVar1 + 1)) {
    sub_080024B8(param_1,&gUnknown_085C1F64,0,0);
    __call_via_r1(param_1,*(undefined4 *)(*(int *)(param_1 + 0x34) + 8));
    DAT_030007e0 = 0x48;
  }
  return;
}


/* sub_0800CA16 @ 0x0800CA16 */

void sub_0800CA16(int param_1)

{
  if (*(char *)(param_1 + 0x10) == 'P') {
    DAT_030043a0 = 0;
    *(undefined1 *)(param_1 + 0x10) = 0x51;
  }
  return;
}


/* sub_0800CA28 @ 0x0800CA28 */

void sub_0800CA28(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '@') {
    DAT_030043a0 = 0;
    *(undefined1 *)(param_1 + 0x10) = 0x41;
  }
  return;
}


/* sub_0800CA3A @ 0x0800CA3A */

void sub_0800CA3A(void)

{
  sub_08003B5C();
  DAT_030043a0 = 0;
  return;
}


/* sub_0800CA48 @ 0x0800CA48 */

void sub_0800CA48(void)

{
  sub_08003B68();
  DAT_030043a0 = 0;
  return;
}


/* sub_0800CA56 @ 0x0800CA56 */

void sub_0800CA56(void)

{
  return;
}


/* sub_0800CA58 @ 0x0800CA58 */

void sub_0800CA58(void)

{
  return;
}


/* sub_0800CA68 @ 0x0800CA68 */

void sub_0800CA68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800CFEE(*(undefined4 *)(param_1 + 4),0,param_3,param_4,param_4);
  return;
}


/* sub_0800CA74 @ 0x0800CA74 */

void sub_0800CA74(int param_1,int *param_2)

{
  int iVar1;
  undefined *local_c;
  
  iVar1 = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  if (((iVar1 != 0) &&
      (*(int *)(*(int *)(*(int *)(iVar1 + 0x1c) + 0x28) + (uint)*(byte *)(param_1 + 5) * 0x10) != 0)
      ) && (*(int *)(*(int *)(iVar1 + 0x18) + (uint)*(byte *)(param_1 + 5) * 0x14) != 0)) {
    DAT_030043a0 = iVar1;
    sub_08002466();
    local_c = &_0800F214;
    sub_080097F8(&local_c);
  }
  return;
}


/* sub_0800CAC8 @ 0x0800CAC8 */

void sub_0800CAC8(int param_1,int *param_2)

{
  int iVar1;
  undefined *local_14;
  int local_10;
  
  iVar1 = sub_080058D6(param_1 + 4);
  __call_via_r2(param_2,iVar1,*(int *)(*param_2 + 8) + *param_2);
  sub_0800236E(&local_14,iVar1);
  sub_0800507A(DAT_03000600,&local_14,1,0);
  __call_via_r2(param_2,iVar1 + 0x20,*(int *)(*param_2 + 0x1c) + *param_2);
  local_14 = &_0800F250;
  local_10 = iVar1;
  sub_080097F8(&local_14);
  return;
}


/* sub_0800CB24 @ 0x0800CB24 */

void sub_0800CB24(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = __call_via_r3(param_2,*(undefined4 *)(param_1 + 4),1,*(int *)(*param_2 + 0x14) + *param_2)
  ;
  if (iVar1 != 0) {
    uVar2 = __call_via_r2(param_2,iVar1,*(int *)(*param_2 + 0x18) + *param_2);
    sub_0800C4C0(iVar1,uVar2);
    uVar2 = *(undefined4 *)(param_1 + 8);
    uVar3 = **(undefined4 **)(iVar1 + 0x1c);
    local_18._0_2_ = (short)uVar2;
    local_1c._0_2_ = (short)uVar3;
    local_1c._2_2_ = (short)((uint)uVar3 >> 0x10);
    local_18._2_2_ = (short)((uint)uVar2 >> 0x10);
    local_20 = CONCAT22(local_18._2_2_ + local_1c._2_2_,(short)local_18 + (short)local_1c);
    local_14 = local_20;
    local_1c = (undefined *)uVar3;
    local_18 = uVar2;
    sub_0800507A(DAT_03000600,&local_18,1,0);
    local_1c = &_0800F214;
    sub_080097F8(&local_1c);
  }
  return;
}


/* sub_0800CBA0 @ 0x0800CBA0 */

int sub_0800CBA0(int param_1)

{
  int iVar1;
  
  sub_080026F8();
  iVar1 = sub_0800279E(*(undefined4 *)(param_1 + 4));
  return 1 - iVar1;
}


/* sub_0800CBB4 @ 0x0800CBB4 */

void sub_0800CBB4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __call_via_r1(param_1,*(undefined4 *)(DAT_03004630 + 4),param_3,param_4,param_4);
  if (0x40 < DAT_0300462c) {
    __call_via_r2(DAT_03004628,param_1,*(int *)(*DAT_03004628 + 0xc) + *DAT_03004628);
  }
  return;
}


/* sub_0800CBDA @ 0x0800CBDA */

undefined4 sub_0800CBDA(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  DAT_0300462c = DAT_0300462c + 1;
  if (DAT_0300462c * 0x10000000 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = __call_via_r1(param_1,*(undefined4 *)(DAT_03004630 + 0xc),&DAT_03004628,param_4,param_4)
    ;
  }
  return uVar1;
}


/* sub_0800CBF6 @ 0x0800CBF6 */

void sub_0800CBF6(int param_1)

{
  DAT_03004630 = *(undefined4 *)(param_1 + 0x34);
  *(undefined **)(param_1 + 0x34) = &gUnknown_08012110;
  return;
}


/* sub_0800CC02 @ 0x0800CC02 */

void sub_0800CC02(int param_1,int *param_2)

{
  undefined1 auStack_18 [8];
  undefined *local_10;
  int local_c;
  
  local_c = __call_via_r3(param_2,*(undefined1 *)(param_1 + 4),1,
                          *(int *)(*param_2 + 0x14) + *param_2);
  if (local_c != 0) {
    local_10 = &_0800F2F8;
    DAT_03004630 = *(undefined4 *)(local_c + 0x34);
    DAT_03004628 = param_2;
    *(undefined **)(local_c + 0x34) = &gUnknown_08012110;
    sub_0800236E(auStack_18,local_c);
    sub_0800507A(DAT_03000600,auStack_18,1,0);
    sub_080097F8(&local_10);
  }
  return;
}


/* sub_0800CC60 @ 0x0800CC60 */

void sub_0800CC60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_8;
  undefined3 uStack_7;
  
  _local_8 = CONCAT31((int3)((uint)param_4 >> 8),*(undefined1 *)(param_1 + 5));
  sub_080051D0(*(undefined1 *)(param_1 + 4),&local_8);
  return;
}


/* sub_0800CC72 @ 0x0800CC72 */

void sub_0800CC72(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_08000E7A(&DAT_030000e8,*(undefined1 *)(param_1 + 4),param_3,param_4,param_4);
  DAT_03003d14 = 0;
  DAT_03003d10 = 0;
  return;
}


/* sub_0800CC74 @ 0x0800CC74 */

void sub_0800CC74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_08000E7A(&DAT_030000e8,*(undefined1 *)(param_1 + 4),param_3,param_4,param_4);
  DAT_03003d14 = 0;
  DAT_03003d10 = 0;
  return;
}


/* sub_0800CC98 @ 0x0800CC98 */

void sub_0800CC98(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x40;
  REG_DMA3SAD = 0x5000000;
  REG_DMA3DAD = param_1 + 8;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  return;
}


/* sub_0800CCB4 @ 0x0800CCB4 */

void sub_0800CCB4(int param_1)

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


/* sub_0800CD18 @ 0x0800CD18 */

bool sub_0800CD18(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  return iVar1 == 0;
}


/* sub_0800CD28 @ 0x0800CD28 */

void sub_0800CD28(void)

{
  undefined *local_40c [259];
  
  local_40c[0] = &_0800F298;
  sub_080097F8(local_40c);
  return;
}


/* sub_0800CD4C @ 0x0800CD4C */

void sub_0800CD4C(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x1e;
  REG_DMA3SAD = 0x5000000;
  REG_DMA3DAD = param_1 + 8;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  DAT_030047e8 = 0xffff;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8100;
  return;
}


/* sub_0800CD80 @ 0x0800CD80 */

bool sub_0800CD80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0xf) {
    REG_DMA3SAD = param_1 + 8;
    REG_DMA3DAD = 0x5000000;
    Ram040000dc = 0x200;
    DAT_040000de = 0x8000;
  }
  return *(int *)(param_1 + 4) == 0;
}


/* sub_0800CDAE @ 0x0800CDAE */

void sub_0800CDAE(undefined4 param_1,undefined4 param_2)

{
  undefined *local_410 [258];
  
  local_410[0] = &_0800F2B0;
  DAT_030043a0 = __call_via_r4(param_2,0x34,0);
  sub_080097F8(local_410);
  DAT_030043a0 = 0;
  return;
}


