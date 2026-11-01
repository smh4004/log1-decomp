/* Ghidra reference decompilation of code_08000118 (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_08000118 @ 0x08000118 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000118(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  while( true ) {
    uVar2 = iVar1 * 0x13 ^ 0x35;
    uVar3 = iVar1 * 0x17 + 0x80;
    if ((uVar2 & 0xff) != uVar2) {
      return;
    }
    if (uVar3 != (uVar3 & 0xff)) break;
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      _DAT_03000008 = &DAT_03000104;
      return;
    }
  }
  return;
}


/* sub_0800011C @ 0x0800011C */

uint sub_0800011C(uint param_1)

{
  return param_1 & 0xffffff7f;
}


/* sub_08000128 @ 0x08000128 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000128(byte *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bStack00000000;
  byte bStack00000001;
  
  iVar1 = 0;
  do {
    uVar2 = iVar1 * 0x13 ^ 0x35;
    *param_1 = (byte)uVar2;
    uVar3 = iVar1 * 0x17 + 0x80;
    param_1[1] = (byte)uVar3;
    if ((*param_1 != uVar2) || (uVar3 != param_1[1])) goto _0800037A;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  _DAT_03000008 = &DAT_03000104;
_0800037A:
  *param_1 = bStack00000000;
  param_1[1] = bStack00000001;
  return;
}


/* sub_0800012A @ 0x0800012A */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800012A(byte *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bStack00000000;
  byte bStack00000001;
  
  iVar1 = 0;
  do {
    uVar2 = iVar1 * 0x13 ^ 0x35;
    *param_1 = (byte)uVar2;
    uVar3 = iVar1 * 0x17 + 0x80;
    param_1[1] = (byte)uVar3;
    if ((*param_1 != uVar2) || (uVar3 != param_1[1])) goto _0800037A;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  _DAT_03000008 = &DAT_03000104;
_0800037A:
  *param_1 = bStack00000000;
  param_1[1] = bStack00000001;
  return;
}


/* sub_0800012C @ 0x0800012C */

uint sub_0800012C(uint param_1)

{
  return param_1 | 0x80;
}


/* IntrMain @ 0x08000138 */

undefined4 IntrMain(void)

{
  return 0;
}


/* sub_0800013C @ 0x0800013C */

undefined4 sub_0800013C(void)

{
  undefined2 uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int in_r3;
  uint *puVar7;
  int iVar8;
  
  puVar7 = (uint *)(in_r3 + 0x200);
  uVar6 = *puVar7;
  uVar1 = *(undefined2 *)(in_r3 + 0x208);
  *(undefined2 *)(in_r3 + 0x208) = 1;
  uVar5 = uVar6 & uVar6 >> 0x10;
  iVar8 = 0x28;
  uVar2 = (ushort)(uVar5 & 0x400);
  if ((uVar5 & 0x400) == 0) {
    iVar8 = 0;
    uVar3 = uVar5 & 1;
    if (uVar3 == 0) {
      iVar8 = 4;
      uVar3 = uVar5 & 2;
      if (uVar3 == 0) {
        iVar8 = 8;
        uVar3 = uVar5 & 4;
        if (uVar3 == 0) {
          iVar8 = 0xc;
          uVar3 = uVar5 & 8;
          if (uVar3 == 0) {
            iVar8 = 0x10;
            uVar3 = uVar5 & 0x10;
            if (uVar3 == 0) {
              iVar8 = 0x14;
              uVar3 = uVar5 & 0x20;
              if (uVar3 == 0) {
                iVar8 = 0x18;
                uVar3 = uVar5 & 0x40;
                if (uVar3 == 0) {
                  iVar8 = 0x1c;
                  uVar3 = uVar5 & 0x80;
                  if (uVar3 == 0) {
                    iVar8 = 0x20;
                    uVar3 = uVar5 & 0x100;
                    if (uVar3 == 0) {
                      iVar8 = 0x24;
                      uVar3 = uVar5 & 0x200;
                      if (uVar3 == 0) {
                        iVar8 = 0x2c;
                        uVar3 = uVar5 & 0x800;
                        if (uVar3 == 0) {
                          iVar8 = 0x30;
                          uVar3 = uVar5 & 0x1000;
                          if (uVar3 == 0) {
                            if ((uVar5 & 0x2000) != 0) {
                              do {
                    /* WARNING: Do nothing block with infinite loop */
                              } while( true );
                            }
                            *(short *)puVar7 = (short)uVar6;
                            *(undefined2 *)(in_r3 + 0x208) = uVar1;
                            return 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar2 = (ushort)uVar3;
    uVar6 = uVar6 & ~uVar3;
  }
  *(ushort *)(in_r3 + 0x202) = uVar2;
  *(short *)puVar7 = (short)uVar6;
  DAT_03003b86 = DAT_03003b86 | uVar2;
                    /* WARNING: Could not recover jumptable at 0x08000248. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (**(code **)(&DAT_03003b88 + iVar8))();
  return uVar4;
}


/* sub_08000148 @ 0x08000148 */

undefined4 sub_08000148(undefined4 param_1,undefined2 param_2,uint param_3,undefined2 *param_4)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  param_4[4] = 1;
  uVar4 = param_3 & param_3 >> 0x10;
  iVar5 = 0x28;
  uVar1 = (ushort)(uVar4 & 0x400);
  if ((uVar4 & 0x400) == 0) {
    iVar5 = 0;
    uVar2 = uVar4 & 1;
    if (uVar2 == 0) {
      iVar5 = 4;
      uVar2 = uVar4 & 2;
      if (uVar2 == 0) {
        iVar5 = 8;
        uVar2 = uVar4 & 4;
        if (uVar2 == 0) {
          iVar5 = 0xc;
          uVar2 = uVar4 & 8;
          if (uVar2 == 0) {
            iVar5 = 0x10;
            uVar2 = uVar4 & 0x10;
            if (uVar2 == 0) {
              iVar5 = 0x14;
              uVar2 = uVar4 & 0x20;
              if (uVar2 == 0) {
                iVar5 = 0x18;
                uVar2 = uVar4 & 0x40;
                if (uVar2 == 0) {
                  iVar5 = 0x1c;
                  uVar2 = uVar4 & 0x80;
                  if (uVar2 == 0) {
                    iVar5 = 0x20;
                    uVar2 = uVar4 & 0x100;
                    if (uVar2 == 0) {
                      iVar5 = 0x24;
                      uVar2 = uVar4 & 0x200;
                      if (uVar2 == 0) {
                        iVar5 = 0x2c;
                        uVar2 = uVar4 & 0x800;
                        if (uVar2 == 0) {
                          iVar5 = 0x30;
                          uVar2 = uVar4 & 0x1000;
                          if (uVar2 == 0) {
                            if ((uVar4 & 0x2000) != 0) {
                              do {
                    /* WARNING: Do nothing block with infinite loop */
                              } while( true );
                            }
                            *param_4 = (short)param_3;
                            param_4[4] = param_2;
                            return param_1;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar1 = (ushort)uVar2;
    param_3 = param_3 & ~uVar2;
  }
  param_4[1] = uVar1;
  *param_4 = (short)param_3;
  DAT_03003b86 = DAT_03003b86 | uVar1;
                    /* WARNING: Could not recover jumptable at 0x08000248. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(&DAT_03003b88 + iVar5))();
  return uVar3;
}


/* sub_08000268 @ 0x08000268 */

void sub_08000268(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x08000268. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* AgbMain @ 0x08000274 */

void AgbMain(void)

{
  undefined1 auStack_c [4];
  
  sub_080096CC(auStack_c);
  sub_08000732(&DAT_03000020);
  sub_080007D2(&DAT_03000028);
  sub_0800A9CC(DAT_03000021);
  sub_0800A9A2(DAT_03000022);
  DAT_0300000b = &DAT_030005e8;
  sub_08009744(&DAT_0300463c);
  sub_08009766();
  return;
}


/* sub_080002C0 @ 0x080002C0 */

void sub_080002C0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 4) = 0;
  REG_BLDY = 0x10;
  uVar1 = sub_080095DC(&gUnknown_0800FE4C + (uint)*(byte *)(param_1 + 5) * 0xc);
  REG_DMA3SAD = *(undefined4 *)(&gUnknown_0800FE4C + (uint)*(byte *)(param_1 + 5) * 0xc);
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = 0x6000000;
  Ram040000dc = 0x4b00;
  DAT_040000de = 0x8000;
  *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + '\x01';
  return;
}


/* sub_08000314 @ 0x08000314 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000314(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 5) = 0;
  REG_DISPCNT = 0x1f04;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = 0x100;
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = 0x100;
  REG_BLDCNT = 0x84;
  sub_080002C0();
  DAT_03003b60 = 0;
  iVar1 = 0;
  while( true ) {
    uVar2 = iVar1 * 0x13 ^ 0x35;
    uVar3 = iVar1 * 0x17 + 0x80;
    if ((uVar2 & 0xff) != uVar2) {
      DAT_03003b60 = 0;
      return;
    }
    if (uVar3 != (uVar3 & 0xff)) break;
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      _DAT_03000008 = &DAT_03000104;
      return;
    }
  }
  DAT_03003b60 = 0;
  return;
}


/* sub_08000386 @ 0x08000386 */

void sub_08000386(int param_1)

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


/* sub_080003B4 @ 0x080003B4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_080003B4(int param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_0800A6B2(4,0x800fe42);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 4) = 0xf4;
    *(undefined1 *)(param_1 + 5) = 2;
  }
  bVar1 = *(byte *)(param_1 + 4);
  *(byte *)(param_1 + 4) = bVar1 + 1;
  if (0xf3 < bVar1) {
    if (*(byte *)(param_1 + 5) < 2) {
      sub_080002C0(param_1);
    }
    else {
      sub_0800CFEE(&gUnknown_08337218,0);
      sub_08009744(_DAT_03000008);
    }
  }
  return 0;
}


/* sub_08000424 @ 0x08000424 */

void sub_08000424(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort auStack_34 [16];
  
  iVar1 = sub_08000800();
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 4) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 4) = 1;
  }
  REG_DISPCNT = 0x1f00;
  REG_BG0CNT = 0x1c0f;
  REG_BG1CNT = 0x1d0f;
  REG_BG2CNT = 0x1e0f;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x844;
  REG_BLDALPHA = 0x10;
  DAT_04000053 = 0xc;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586(&gUnknown_081B3514,&DAT_0202b600,0x6000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202a5b8,&DAT_0600e800,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FE76);
  sub_08008D8A(&DAT_0202addc);
  sub_080009B8(0,1);
  sub_08000A32(4,*(byte *)(param_1 + 4) + 0xd);
  REG_DMA3SAD = 0x50001e0;
  REG_DMA3DAD = auStack_34;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  iVar1 = 0;
  do {
    uVar3 = (uint)auStack_34[iVar1];
    iVar2 = iVar1 + 1;
    auStack_34[iVar1] =
         (ushort)(((uVar3 << 0x11) >> 0x1c) << 10) |
         (ushort)((uVar3 & 0x1f) >> 1) | (ushort)(((uVar3 << 0x16) >> 0x1c) << 5);
    iVar1 = iVar2;
  } while (iVar2 < 0x10);
  REG_DMA3SAD = auStack_34;
  REG_DMA3DAD = 0x50001c0;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  DAT_03000014 = DAT_03003b6c + 0xe10;
  return;
}


/* sub_0800051A @ 0x0800051A */

void sub_0800051A(void)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08009486(&DAT_0800fe80,&DAT_02029d94);
  sub_08000A58();
  iVar1 = sub_08000800();
  if (iVar1 == 0) {
    DAT_02029d94 = 0xe;
    sub_0800946E(&gUnknown_0800FE64,&DAT_02029d94);
    DAT_02029d94 = 0xf;
  }
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08000520 @ 0x08000520 */

void sub_08000520(void)

{
  int iVar1;
  undefined1 *unaff_r4;
  
  sub_08008D14();
  sub_08009486(&DAT_0800fe80,unaff_r4);
  sub_08000A58();
  iVar1 = sub_08000800();
  if (iVar1 == 0) {
    *unaff_r4 = 0xe;
    sub_0800946E(&gUnknown_0800FE64,unaff_r4);
    *unaff_r4 = 0xf;
  }
  sub_08008D8A(unaff_r4);
  return;
}


/* sub_08000554 @ 0x08000554 */

undefined4 sub_08000554(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = sub_080094B8(&DAT_0800fe80,param_1 + 4);
  if (iVar2 != 0) {
    sub_08000A32(4,*(byte *)(param_1 + 4) + 0xd);
    sub_0800ACFE(0);
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_08008DA0(&DAT_02029d94);
    sub_08008DA0(&DAT_0202addc);
    sub_0800988C();
    sub_0800ACFE(0);
    sub_08009744(&DAT_030005e8);
  }
  else if (((DAT_03003d14 & 1) == 0) && (-1 < (int)((uint)DAT_03003d14 << 0x1c))) {
    if (DAT_03000014 < DAT_03003b6c) {
      sub_08009744(0x300000c);
    }
  }
  else {
    cVar1 = *(char *)(param_1 + 4);
    if (cVar1 == '\0') {
      sub_080007D2(&DAT_03000028);
      sub_0800ACFE(1);
      sub_08000F8C(&DAT_030000ec,&DAT_030000fc,0);
    }
    else if (cVar1 == '\x01') {
      iVar2 = sub_08000800();
      if (iVar2 == 0) {
        sub_0800ACFE(0x13);
      }
      else {
        sub_0800ACFE(1);
        sub_080097C8(&DAT_03004398);
      }
    }
    else if (cVar1 == '\x02') {
      sub_0800ACFE(1);
      sub_080097C8(&DAT_0300080c);
    }
  }
  return 0;
}


/* sub_08000610 @ 0x08000610 */

void sub_08000610(int param_1)

{
  sub_08008DA0(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FE76);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(4,*(byte *)(param_1 + 4) + 0xd);
  return;
}


/* sub_080006B0 @ 0x080006B0 */

uint sub_080006B0(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  uVar3 = 0;
  do {
    uVar2 = (uVar2 >> 0x1d | uVar2 << 3) + (uint)*param_1 + 1;
    uVar1 = uVar1 ^ uVar2;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xa8);
  return uVar1;
}


/* sub_080006D2 @ 0x080006D2 */

void sub_080006D2(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 4;
  param_1[2] = 8;
  param_1[3] = 0;
  return;
}


/* sub_080006E2 @ 0x080006E2 */

uint sub_080006E2(byte *param_1)

{
  return ((uint)*param_1 ^ (param_1[1] ^ 3) << 2 ^ (param_1[2] ^ 3) << 6 ^ 1) & 0xff;
}


/* sub_08000700 @ 0x08000700 */

void sub_08000700(byte *param_1)

{
  if ((((uint)*param_1 ^ (param_1[1] ^ 3) << 2 ^ (param_1[2] ^ 3) << 6 ^ 1) & 0xff) !=
      (uint)param_1[3]) {
    *param_1 = 0;
    param_1[1] = 4;
    param_1[2] = 8;
    param_1[3] = 0;
  }
  return;
}


/* sub_08000732 @ 0x08000732 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000732(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 4;
  param_1[2] = 8;
  param_1[3] = 0;
  if (DAT_03004390 != 0) {
    if (((_DAT_02029b94 & 0xff ^ (_DAT_02029b94 >> 8 & 0xff ^ 3) << 2 ^
          (_DAT_02029b94 >> 0x10 & 0xff ^ 3) << 6 ^ 1) & 0xff) != _DAT_02029b94 >> 0x18) {
      _DAT_02029b94 = 0x80400;
    }
    DAT_03000024 = DAT_02029b98;
    _DAT_03000020 = _DAT_02029b94;
  }
  return;
}


/* sub_08000784 @ 0x08000784 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000784(void)

{
  byte bVar1;
  uint uVar2;
  
  if ((((_DAT_02029b94 & 0xff) != (_DAT_03000020 & 0xff)) || (DAT_02029b95 != DAT_03000021)) ||
     (DAT_02029b96 != DAT_03000022)) {
    uVar2 = (uint)DAT_03000022;
    bVar1 = DAT_03000020 ^ (byte)((DAT_03000021 ^ 3) << 2);
    _DAT_03000020 = CONCAT13(bVar1 ^ (byte)((uVar2 ^ 3) << 6),_DAT_03000020) ^ 0x1000000;
    DAT_02029b98 = DAT_03000024;
    _DAT_02029b94 = _DAT_03000020;
    sub_0800B316(&DAT_02029b94);
  }
  return;
}


/* sub_080007D2 @ 0x080007D2 */

void sub_080007D2(int param_1)

{
  sub_08002F3E();
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x54;
  DAT_040000de = 0x8100;
  *(int *)(param_1 + 0x1c) = -DAT_03003b6c;
  *(undefined1 *)(param_1 + 0x25) = 1;
  return;
}


/* sub_08000800 @ 0x08000800 */

int sub_08000800(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = DAT_03004390;
  if (DAT_03004390 != 0) {
    iVar1 = 0;
    do {
      uVar2 = 0;
      uVar4 = 0;
      uVar3 = 0;
      do {
        uVar2 = (uVar2 >> 0x1d | uVar2 << 3) + (uint)(byte)(&DAT_02029ba0)[iVar1 * 0xac] + 1;
        uVar4 = uVar4 ^ uVar2;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0xa8);
      if (uVar4 == (&DAT_02029b9c)[iVar1 * 0x2b]) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
    iVar1 = 0;
  }
  return iVar1;
}


/* sub_0800084A @ 0x0800084A */

bool sub_0800084A(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = (uVar1 >> 0x1d | uVar1 << 3) + (uint)(byte)(&DAT_02029ba0)[param_1 * 0xac] + 1;
    uVar3 = uVar3 ^ uVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xa8);
  return uVar3 == (&DAT_02029b9c)[param_1 * 0x2b];
}


/* sub_08000882 @ 0x08000882 */

void sub_08000882(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  sub_0800E4F8(&DAT_03000028,&DAT_02029ba0 + param_2 * 0xac,0xa8,param_4,param_4);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - DAT_03003b6c;
  sub_08002F80();
  sub_08001FA8(DAT_0300004c);
  return;
}


/* sub_080008B4 @ 0x080008B4 */

void sub_080008B4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0xa5) = DAT_030007b0;
  iVar4 = param_2 * 0xac;
  *(char *)(param_1 + 0xa6) = (char)DAT_030007b2;
  *(char *)(param_1 + 0xa4) = (char)DAT_030007e0;
  *(undefined4 *)(param_1 + 0xa0) = DAT_030007d8;
  sub_0800E4F8(&DAT_02029ba0 + iVar4,&DAT_03000028,0xa7);
  *(int *)(&DAT_02029bbc + iVar4) = DAT_03000044 + DAT_03003b6c;
  uVar1 = 0;
  uVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = (uVar1 >> 0x1d | uVar1 << 3) + (uint)DAT_03000028 + 1;
    uVar3 = uVar3 ^ uVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xa8);
  (&DAT_02029b9c)[param_2 * 0x2b] = uVar3;
  sub_0800B368(&DAT_02029b9c + param_2 * 0x2b,iVar4 + 0x2029c48);
  return;
}


/* sub_0800091C @ 0x0800091C */

int sub_0800091C(int param_1)

{
  return *(int *)(param_1 + 0x1c) + DAT_03003b6c;
}


/* sub_08000926 @ 0x08000926 */

undefined4 sub_08000926(int param_1,int param_2)

{
  if (param_2 - 0xbU < 3) {
    if (-1 < (int)((uint)*(byte *)(param_1 + 0x31) + (uint)*(byte *)(param_1 + 0x32) +
                   (uint)*(byte *)(param_1 + 0x33) + -6)) {
      return 1;
    }
  }
  else if ((param_2 == 0x13) && (-1 < (int)(*(byte *)(param_1 + 0x39) - 3))) {
    return 1;
  }
  return 0;
}


/* sub_08000954 @ 0x08000954 */

bool sub_08000954(int param_1)

{
  return ((&DAT_03000028)[(int)(uint)*(byte *)(param_1 + 4) >> 3] &
         (byte)(1 << (*(byte *)(param_1 + 4) & 7))) != 0;
}


/* sub_080009B8 @ 0x080009B8 */

void sub_080009B8(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = sub_08005EA6(&gUnknown_08166C18);
  DAT_030000d0 = (undefined1)iVar1;
  REG_DMA3SAD = 0x8166bf8;
  REG_DMA3DAD = param_2 * 0x20 + 0x6010000;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  param_1 = param_1 * 8;
  DAT_030000d4 = (uint *)(&DAT_0202be24 + param_1);
  *DAT_030000d4 = *DAT_030000d4 & 0x1ff00ff;
  *(uint *)(&DAT_0202be28 + param_1) =
       (uint)(iVar1 << 0x1c) >> 0x10 |
       *(uint *)(&DAT_0202be28 + param_1) & 0xffff0000 | param_2 & 0x3ff;
  return;
}


/* sub_08000A30 @ 0x08000A30 */

void sub_08000A30(void)

{
  return;
}


/* sub_08000A32 @ 0x08000A32 */

void sub_08000A32(int param_1,int param_2)

{
  *DAT_030000d4 =
       ((uint)(param_1 << 0x1a) >> 0x17) << 0x10 |
       (uint)(param_2 << 0x1b) >> 0x18 | *DAT_030000d4 & 0xfe00ff00;
  sub_080098C6();
  return;
}


/* sub_08000A58 @ 0x08000A58 */

void sub_08000A58(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ushort local_30 [11];
  ushort auStack_1a [5];
  
  uVar1 = (uint)(DAT_03003b6c << 0x19) >> 0x1b;
  if (0x10 < uVar1) {
    uVar1 = 0x20 - uVar1;
  }
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    local_30[iVar3] = (&gUnknown_08166C18)[iVar3];
    iVar3 = iVar2;
  } while (iVar2 < 0xb);
  iVar3 = 0xb;
  do {
    uVar5 = (uint)(ushort)(&gUnknown_08166C18)[iVar3];
    iVar6 = (uVar5 & 0x1f) + uVar1;
    iVar7 = ((uVar5 << 0x16) >> 0x1b) + uVar1;
    iVar2 = ((uVar5 << 0x11) >> 0x1b) + uVar1;
    if (0x1f < iVar6) {
      iVar6 = 0x1f;
    }
    if (0x1f < iVar7) {
      iVar7 = 0x1f;
    }
    if (0x1f < iVar2) {
      iVar2 = 0x1f;
    }
    iVar4 = iVar3 + 1;
    local_30[iVar3] = (ushort)(iVar2 << 10) | (ushort)iVar6 | (ushort)(iVar7 << 5);
    iVar3 = iVar4;
  } while (iVar4 < 0x10);
  REG_DMA3SAD = local_30;
  REG_DMA3DAD = &DAT_05000200 + (uint)DAT_030000d0 * 0x20;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  return;
}


/* sub_08000B00 @ 0x08000B00 */

void sub_08000B00(int param_1)

{
  REG_DISPCNT = 8000;
  REG_BG0CNT = 0x1c0f;
  REG_BG1CNT = 0x1d0f;
  REG_BG2CNT = 0x1e0f;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x844;
  REG_BLDALPHA = 0x10;
  DAT_04000053 = 0xc;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586(&gUnknown_081B3514,&DAT_0202b600,0x6000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202a5b8,&DAT_0600e800,&DAT_0600c000,0xe,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FEAC);
  sub_08008D8A(&DAT_0202addc);
  sub_080009B8(0,1);
  sub_08000A32(2,(uint)*(byte *)(param_1 + 4) * 3 + 4);
  return;
}


/* sub_08000B9A @ 0x08000B9A */

void sub_08000B9A(int param_1)

{
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486(&DAT_0800feb4,&DAT_02029d94);
  DAT_02029d9e = 6;
  DAT_02029da0 = 5;
  sub_08008E3A(&DAT_02029d94,&_08000E18,*(byte *)(param_1 + 5) + 1);
  DAT_02029d9e = 6;
  DAT_02029da0 = 0xb;
  sub_08008E3A(&DAT_02029d94,&_08000E18,*(undefined1 *)(param_1 + 6));
  DAT_02029d9e = 6;
  DAT_02029da0 = 0xe;
  sub_08008E3A(&DAT_02029d94,&_08000E18,*(undefined1 *)(param_1 + 7));
  DAT_02029d9e = 6;
  DAT_02029da0 = 0x11;
  sub_08008E3A(&DAT_02029d94,&_08000E18,*(undefined1 *)(param_1 + 8));
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08000C02 @ 0x08000C02 */

undefined4 sub_08000C02(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = sub_080094B8(&DAT_0800feb4,param_1 + 4,param_3,param_4,param_4);
  if (iVar2 != 0) {
    sub_08000A32(2,(uint)*(byte *)(param_1 + 4) * 3 + 4);
  }
  uVar1 = DAT_03003d14;
  switch(*(undefined1 *)(param_1 + 4)) {
  case 0:
    uVar3 = (uint)DAT_03003d14;
    if (((int)(uVar3 << 0x1a) < 0) && (*(char *)(param_1 + 5) != '\0')) {
      *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + -1;
    }
    if (((int)(uVar3 << 0x1b) < 0) && (*(byte *)(param_1 + 5) < 0x29)) {
      *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) + 1;
    }
    if ((uVar1 & 1) != 0) {
      sub_08002F3E();
      sub_08001FA8((uint)*(byte *)(param_1 + 5),
                   *(int *)((&gUnknown_081CA09C)[*(byte *)(param_1 + 5)] + 0x14) + 0x28);
    }
    break;
  case 1:
    if ((DAT_03003d14 & 1) != 0) {
      sub_080097C8(&DAT_030007f4);
    }
    break;
  case 2:
    uVar3 = (uint)DAT_03003d14;
    if (((int)(uVar3 << 0x1a) < 0) && (*(char *)(param_1 + 6) != '\0')) {
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
    }
    if (((int)(uVar3 << 0x1b) < 0) && (*(byte *)(param_1 + 6) < 0x1e)) {
      *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) + 1;
    }
    if ((uVar1 & 1) != 0) {
      sub_0800ACCA(&gUnknown_085C0B0C + (uint)*(byte *)(param_1 + 6) * 0xc,0x40,0);
    }
    break;
  case 3:
    uVar3 = (uint)DAT_03003d14;
    if (((int)(uVar3 << 0x1a) < 0) && (*(char *)(param_1 + 7) != '\0')) {
      *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + -1;
    }
    if (((int)(uVar3 << 0x1b) < 0) && (*(byte *)(param_1 + 7) < 0x11)) {
      *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) + 1;
    }
    if ((uVar1 & 1) != 0) {
      sub_0800A5F6(&gUnknown_08591F3C + (uint)*(byte *)(param_1 + 7) * 0xc);
    }
    if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
      sub_0800A5B8();
    }
    if ((int)((uint)DAT_03003d14 << 0x17) < 0) {
      sub_0800A5C0();
      DAT_03003cfd = DAT_03003cfe;
      DAT_03003cff = 1;
    }
    if ((int)((uint)DAT_03003d14 << 0x16) < 0) {
      sub_0800A5C0();
      DAT_03003cfd = 0;
      DAT_03003cfe = 1;
      DAT_03003cff = 1;
      if (DAT_03003d02 < 1) {
        DAT_03003d02 = -1;
      }
      else {
        DAT_03003d02 = DAT_03003d02 + -2;
      }
    }
    break;
  case 4:
    uVar3 = (uint)DAT_03003d14;
    if (((int)(uVar3 << 0x1a) < 0) && (*(char *)(param_1 + 8) != '\0')) {
      *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + -1;
    }
    if (((int)(uVar3 << 0x1b) < 0) && (*(byte *)(param_1 + 8) < 0xe)) {
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) + 1;
    }
    if ((uVar1 & 1) != 0) {
      sub_08008DA0(&DAT_02029d94);
      sub_08008DA0(&DAT_0202a5b8);
      sub_08008DA0(&DAT_0202addc);
      sub_0800988C();
      uVar3 = (uint)DAT_03003b60;
      DAT_03003b60 = DAT_03003b60 + 1;
      *(undefined4 *)(&DAT_03003b70 + uVar3 * 4) = DAT_03003b64;
      sub_08000E7A(&DAT_030000e8,*(undefined1 *)(param_1 + 8));
      sub_08009798();
    }
  }
  if ((int)((uint)DAT_03003d14 << 0x1c) < 0) {
    sub_08009798();
  }
  return 0;
}


/* sub_08000E54 @ 0x08000E54 */

ushort sub_08000E54(void)

{
  return DAT_03003d14 & 1;
}


/* sub_08000E5E @ 0x08000E5E */

void sub_08000E5E(void)

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


/* sub_08000E7A @ 0x08000E7A */

void sub_08000E7A(undefined4 param_1,int param_2)

{
  sub_08009586(&gUnknown_085C2198 + param_2 * 0xc,&DAT_0202b600,0x6000000);
  REG_DISPCNT = 0x800;
  REG_BLDCNT = 0;
  sub_080097F8(param_1);
  return;
}


/* sub_08000EBC @ 0x08000EBC */

void sub_08000EBC(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar6;
  ushort local_414 [512];
  uint uVar5;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    __call_via_r1(piVar1,*(int *)(*piVar1 + 8) + *piVar1);
  }
  if ((int)((uint)*(byte *)(param_1 + 4) << 0x1f) < 0) {
    REG_DMA3SAD = 0x5000000;
    REG_DMA3DAD = local_414;
    Ram040000dc = 0x100;
    DAT_040000de = 0x8400;
    iVar2 = 0;
    do {
      uVar3 = (uint)local_414[iVar2];
      uVar5 = (uVar3 & 0x1f) + 1;
      uVar4 = (ushort)uVar5;
      uVar6 = ((uVar3 << 0x16) >> 0x1b) + 1;
      uVar3 = ((uVar3 << 0x11) >> 0x1b) + 1;
      if (0x1f < uVar5) {
        uVar4 = 0x1f;
      }
      if (0x1f < uVar6) {
        uVar6 = 0x1f;
      }
      if (0x1f < uVar3) {
        uVar3 = 0x1f;
      }
      local_414[iVar2] = (ushort)(uVar3 << 10) | uVar4 | (ushort)(uVar6 << 5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x200);
    REG_DMA3SAD = local_414;
    REG_DMA3DAD = 0x5000000;
    Ram040000dc = 0x100;
    DAT_040000de = 0x8400;
  }
  *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  return;
}


/* sub_08000F58 @ 0x08000F58 */

void sub_08000F58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(*piVar1 + 0x10);
    __call_via_r1(piVar1,iVar2 + *piVar1,iVar2,param_4,param_4);
  }
  return;
}


/* sub_08000F6C @ 0x08000F6C */

undefined4 sub_08000F6C(int param_1)

{
  if (0x40 < *(byte *)(param_1 + 4)) {
    sub_080098F8();
    if (*(int *)(param_1 + 8) == 0) {
      return 1;
    }
    sub_08009744();
  }
  return 0;
}


/* sub_08000F8C @ 0x08000F8C */

void sub_08000F8C(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  sub_08009744();
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


/* sub_08000FA4 @ 0x08000FA4 */

void sub_08000FA4(int param_1)

{
  sub_0800DCF0();
  DAT_02029d96 = 3;
  DAT_02029d98 = 4;
  DAT_02029d9a = 0x1b;
  DAT_02029d9c = 8;
  sub_0800930A(&DAT_02029d94,
               "Our story begins with our humble hero, Goku. It has been a long time since he has last seen his childhood friends, and so he has decided to meet with them at the house of his old Martial Arts master. Coming along with him is his young six-year old son, Gohan..."
              );
  sub_080090AE(&DAT_0202addc,&DAT_0800fee4);
  sub_08008D8A(&DAT_0202addc);
  REG_BLDY = 0x10;
  REG_BLDCNT = 0x88;
  *(undefined1 *)(param_1 + 4) = 0x40;
  return;
}


/* sub_08000FE8 @ 0x08000FE8 */

void sub_08000FE8(int param_1)

{
  byte bVar1;
  
  sub_08008D8A(&DAT_02029d94);
  if (*(char *)(param_1 + 4) != '\0') {
    bVar1 = *(char *)(param_1 + 4) - 1;
    *(byte *)(param_1 + 4) = bVar1;
    REG_BLDY = bVar1 >> 2;
  }
  return;
}


/* sub_08001008 @ 0x08001008 */

undefined4 sub_08001008(void)

{
  sub_08009328(&DAT_02029d94,0);
  if (DAT_02029da8 == 0) {
    sub_080007D2(&DAT_03000028);
    sub_08001FA8(0,&DAT_0800fee0);
  }
  return 0;
}


/* sub_0800102E @ 0x0800102E */

void sub_0800102E(void)

{
  sub_08000FA4();
  sub_0800930A(&DAT_02029d94,"This program will not run on the hardware found.");
  return;
}


/* sub_0800103E @ 0x0800103E */

undefined4 sub_0800103E(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_08009328(&DAT_02029d94,0,param_3,param_4,param_4);
  return 0;
}


/* sub_0800106C @ 0x0800106C */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800106C(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_1c;
  short local_18;
  short local_16;
  
  DAT_03004636 = 0;
  DAT_03004634 = 2;
  DAT_03004635 = 2;
  if (_DAT_030005f0 < 2) {
    DAT_03004634 = 1;
  }
  if (DAT_030005f2 < 2) {
    DAT_03004635 = 1;
  }
  DAT_03004638 = 0xffff;
  DAT_0300463a = 0xffff;
  local_18 = (short)(DAT_03000608 * 0x445 >> 0x12);
  iVar2 = (int)_DAT_030005f0 - (uint)DAT_03004634;
  if (iVar2 < local_18) {
    local_18 = (short)iVar2;
  }
  local_16 = (short)(DAT_0300060a * 0x667 >> 0x12);
  if ((int)((int)DAT_030005f2 - (uint)DAT_03004635) < (int)local_16) {
    local_16 = DAT_030005f2 - (ushort)DAT_03004634;
  }
  sub_0800D278(param_1,&local_18);
  REG_DMA3SAD = 0x85c3868;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  if (*(int *)(DAT_03000600 + 0x30) != 0) {
    uVar1 = sub_080095D0();
    sub_08009626(&REG_DMA3SAD,&DAT_06002480,uVar1,0x3200);
    if ((DAT_03000604 != 0) && (*(ushort *)(DAT_03000604 + 4) != 0)) {
      REG_DMA3SAD = (uint)*(ushort *)(DAT_03000604 + 2) * 0x40 + 0x6000000;
      REG_DMA3DAD = 0x200a824;
      Ram040000dc = (short)(((uint)*(ushort *)(DAT_03000604 + 4) << 6) >> 2);
      DAT_040000de = 0x8400;
    }
    DAT_03000980 = 0;
  }
  REG_DMA3SAD = *(int *)(DAT_03000600 + 0x2c) + 0x20;
  REG_DMA3DAD = 0x5000020;
  Ram040000dc = 0x78;
  DAT_040000de = 0x8400;
  local_1c = CONCAT22(DAT_030005f6,DAT_030005f4);
  sub_08008764(local_1c);
  return;
}


/* sub_08001174 @ 0x08001174 */

void sub_08001174(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  REG_DISPCNT = 0x80;
  sub_080098F8();
  uVar1 = sub_080095DC(&gUnknown_085C31EC);
  sub_080095FE(&REG_DMA3SAD,0x6000000,uVar1,0x1240,param_4);
  sub_0800106C(param_1);
  REG_BG0CNT = 0x1c00;
  REG_BG1CNT = 0x1d81;
  REG_BG2CNT = 0x1e83;
  REG_BG3CNT = 0x1f83;
  DAT_02029da4 = &DAT_0600e000;
  DAT_02029d96 = 0;
  DAT_02029d98 = 0;
  DAT_02029d9a = 0x1e;
  DAT_02029d9c = 0x14;
  DAT_02029d94 = 0;
  sub_08008D14();
  DAT_0202a5c8 = &DAT_0600e800;
  DAT_0202adec = &DAT_0600f000;
  DAT_0202b610 = &DAT_0600f800;
  REG_BLDCNT = 0;
  REG_DISPCNT = 8000;
  REG_BG1HOFS = DAT_03000608;
  REG_BG1VOFS = DAT_0300060a;
  REG_BG2HOFS = DAT_03000608;
  REG_BG2VOFS = DAT_0300060a;
  REG_BG3HOFS = DAT_03000608;
  REG_BG3VOFS = DAT_0300060a;
  return;
}


/* sub_08001208 @ 0x08001208 */

void sub_08001208(void)

{
  sub_08001174();
  return;
}


/* sub_08001210 @ 0x08001210 */

void sub_08001210(void)

{
  return;
}


/* sub_08001212 @ 0x08001212 */

undefined4 sub_08001212(void)

{
  sub_080022BA();
  sub_080026F8();
  if (((int)((uint)DAT_03003d14 << 0x1c) < 0) && (DAT_030007d0 != 0)) {
    sub_08005F2C(&DAT_03000110);
    sub_0800AD54(&DAT_03000190);
    sub_0800ACFE(0);
    sub_080097C8(&DAT_03000590);
  }
  return 0;
}


/* sub_0800124C @ 0x0800124C */

void sub_0800124C(undefined4 param_1)

{
  sub_08005F58(&DAT_03000110);
  sub_08001174(param_1);
  sub_0800AD7C(&DAT_03000190);
  return;
}


/* sub_080012EC @ 0x080012EC */

void sub_080012EC(int *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  REG_DISPCNT = 0x80;
  REG_BG0CNT = 0x1c0f;
  REG_BG1CNT = 0x1d0f;
  REG_BG2CNT = 0x1e0f;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x844;
  REG_BLDALPHA = 0x10;
  DAT_04000053 = 0xc;
  sub_080098F8();
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586(&gUnknown_081B3514,&DAT_0202b600,0x6000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202a5b8,&DAT_0600e800,&DAT_0600c000,0xe,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_080009B8(0,1);
  __call_via_r1(param_1,*(int *)(*param_1 + 0x14) + *param_1);
  REG_DISPCNT = 0x1f00;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  return;
}


/* sub_08001390 @ 0x08001390 */

void sub_08001390(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  sub_08008D14(&DAT_02029d94);
  sub_08009486(&gUnknown_0800FF0C,&DAT_02029d94);
  sub_08009486(&DAT_0800ff38,&DAT_02029d94);
  DAT_02029d9e = 0xb;
  DAT_02029da0 = 3;
  uVar1 = sub_080032B8();
  sub_08008E3A(&DAT_02029d94,&_080015A4,uVar1);
  DAT_02029d9e = 0x10;
  DAT_02029da0 = 5;
  sub_08008E3A(&DAT_02029d94,&_080015A4,DAT_030007d8);
  DAT_02029d9e = 0x13;
  DAT_02029da0 = 7;
  uVar1 = sub_080032C0();
  sub_08008E3A(&DAT_02029d94,&_080015A4,uVar1);
  DAT_02029d9e = 0x15;
  DAT_02029da0 = 0xc;
  sub_08008E3A(&DAT_02029d94,&_080015B0,DAT_030007d0);
  DAT_02029d9e = 0x15;
  DAT_02029da0 = 0xe;
  sub_08008E3A(&DAT_02029d94,&_080015B0,DAT_030007c8);
  DAT_02029d9e = 0x14;
  DAT_02029da0 = 0x11;
  iVar2 = sub_0800091C(&DAT_03000028);
  if (0x14996c4 < iVar2) {
    sub_08008E3A(&DAT_02029d94,"99:59:59");
  }
  uVar1 = __16__rt_sdiv(0x3c,iVar2);
  uVar3 = __16__rt_sdiv(0x3c,uVar1);
  uVar4 = __16__rt_sdiv(0x3c,(int)uVar3);
  sub_08008E3A(&DAT_02029d94,"%02d:%02d:%02d",(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),
               (int)((ulonglong)uVar3 >> 0x20));
  sub_08000A58();
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_0800146A @ 0x0800146A */

undefined4 sub_0800146A(int param_1)

{
  int iVar1;
  
  iVar1 = sub_080094B8(&gUnknown_0800FF0C,param_1 + 4);
  if (iVar1 != 0) {
    sub_08000A32(2,*(byte *)(param_1 + 4) + 0xb);
    sub_0800ACFE(0);
  }
  if ((int)((uint)DAT_03003d14 << 0x1e) < 0) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  else if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1c) < 0)) {
    switch(*(undefined1 *)(param_1 + 4)) {
    case 0:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_03000598);
      break;
    case 1:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_030005a0);
      break;
    case 2:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_030005bc);
      break;
    case 3:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_030005c4);
      break;
    case 4:
      sub_0800ACFE(1);
      sub_080097C8(&DAT_0300080c);
      break;
    case 5:
      sub_080097C8(&DAT_030005d8);
      break;
    case 6:
      sub_0800ACFE(0);
      sub_08009798();
    }
  }
  return 0;
}


/* sub_0800151C @ 0x0800151C */

void sub_0800151C(int param_1)

{
  sub_08008DA0(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&DAT_0800fef4);
  sub_080090AE(&DAT_0202addc,&DAT_0800fefc);
  sub_080090AE(&DAT_0202addc,&DAT_0800ff04);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(2,*(byte *)(param_1 + 4) + 0xb);
  return;
}


/* sub_080015F8 @ 0x080015F8 */

void sub_080015F8(int param_1)

{
  sub_08008DA0(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FF64);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(2,0x10);
  sub_08005542(&DAT_030046b8);
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


/* sub_0800162A @ 0x0800162A */

void sub_0800162A(int param_1)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486(&DAT_0800ff6c,&DAT_02029d94);
  if (DAT_030046b8 == 0) {
    DAT_02029d9e = 8;
    DAT_02029da0 = 10;
    sub_08008E06(&DAT_02029d94,"None Completed");
  }
  else {
    iVar1 = 0;
    do {
      if (DAT_030046b8 <= (int)((uint)*(byte *)(param_1 + 4) + iVar1)) break;
      DAT_02029d9e = 6;
      DAT_02029da0 = (short)iVar1 + 6;
      sub_08008E06(&DAT_02029d94,
                   *(undefined4 *)(((uint)*(byte *)(param_1 + 4) + iVar1) * 4 + 0x30046bc));
      iVar1 = iVar1 + 1;
    } while (iVar1 < 9);
  }
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08001690 @ 0x08001690 */

undefined4 sub_08001690(int param_1)

{
  uint uVar1;
  
  if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  uVar1 = (uint)DAT_03003d14;
  if (((int)(uVar1 << 0x19) < 0) && (*(char *)(param_1 + 4) != '\0')) {
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + -1;
  }
  if (((int)(uVar1 << 0x18) < 0) && ((int)(*(byte *)(param_1 + 4) + 9) < DAT_030046b8)) {
    *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) + 1;
  }
  return 0;
}


/* sub_08001708 @ 0x08001708 */

undefined4 sub_08001708(void)

{
  return 0;
}


/* sub_0800170C @ 0x0800170C */

undefined4 sub_0800170C(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_030007d0 == DAT_030007cc) {
    uVar1 = 0;
  }
  else {
    iVar2 = DAT_030007d0 + (DAT_030007cc >> 2);
    if (DAT_030007cc < iVar2) {
      iVar2 = DAT_030007cc;
    }
    sub_0800324E(iVar2);
    uVar1 = 1;
  }
  return uVar1;
}


/* sub_08001730 @ 0x08001730 */

bool sub_08001730(void)

{
  bool bVar1;
  
  bVar1 = DAT_030007d0 != DAT_030007cc;
  if (bVar1) {
    sub_0800324E();
  }
  return bVar1;
}


/* sub_08001732 @ 0x08001732 */

bool sub_08001732(int *param_1)

{
  bool bVar1;
  
  bVar1 = *param_1 != DAT_030007cc;
  if (bVar1) {
    sub_0800324E();
  }
  return bVar1;
}


/* sub_0800174A @ 0x0800174A */

void sub_0800174A(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x202c28c;
  Ram040000dc = 4;
  DAT_040000de = 0x8500;
  iVar3 = 0;
  do {
    pbVar2 = &gUnknown_081C7A84 + iVar3;
    pcVar1 = &DAT_0300004e + iVar3;
    iVar3 = iVar3 + 1;
    (&DAT_0202c28c)[*pbVar2] = (&DAT_0202c28c)[*pbVar2] + *pcVar1;
  } while (iVar3 < 0x22);
  iVar3 = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  do {
    if ((&DAT_0202c28c)[iVar3] != '\0') {
      (&DAT_0202c228)[(uint)*(byte *)(param_1 + 6) * 2] = iVar3;
      (&DAT_0202c224)[(uint)*(byte *)(param_1 + 6) * 2] = (uint)(byte)(&DAT_0202c28c)[iVar3];
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xd);
  return;
}


/* sub_080017B6 @ 0x080017B6 */

void sub_080017B6(int param_1)

{
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FF98);
  sub_08008D8A(&DAT_0202addc);
  *(undefined1 *)(param_1 + 4) = 0;
  sub_0800174A(param_1);
  return;
}


/* sub_080017E6 @ 0x080017E6 */

void sub_080017E6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486(&DAT_0800ffa0,&DAT_02029d94);
  if (*(char *)(param_1 + 6) == '\0') {
    DAT_02029d9e = 0xc;
    DAT_02029da0 = 10;
    sub_08008E06(&DAT_02029d94,"Empty");
  }
  else {
    iVar1 = 0;
    if (*(char *)(param_1 + 6) != '\0') {
      do {
        DAT_02029d9e = 5;
        DAT_02029da0 = (short)iVar1 + 6;
        sub_08008E3A(&DAT_02029d94,"%d %s",(&DAT_0202c224)[iVar1 * 2],
                     *(undefined4 *)
                      (&gUnknown_081C6224 +
                      (uint)((&DAT_0202c224)[iVar1 * 2] != 1) * 4 + (&DAT_0202c228)[iVar1 * 2] * 8),
                     param_4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)*(byte *)(param_1 + 6));
    }
  }
  if (*(byte *)(param_1 + 4) == 0) {
    sub_08000A32(2,0x10);
  }
  else {
    sub_08000A32(3,*(byte *)(param_1 + 4) + 5);
  }
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08001874 @ 0x08001874 */

undefined4 sub_08001874(int param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  
  uVar1 = (uint)DAT_03003d14;
  if ((int)(uVar1 << 0x19) < 0) {
    if (*(char *)(param_1 + 4) == '\0') {
      *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_1 + 6);
    }
    else {
      *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + -1;
    }
  }
  else if (((int)(uVar1 << 0x18) < 0) || ((int)(uVar1 << 0x1d) < 0)) {
    bVar3 = *(char *)(param_1 + 4) + 1;
    *(byte *)(param_1 + 4) = bVar3;
    if (*(byte *)(param_1 + 6) < bVar3) {
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  if (((int)(uVar1 << 0x1e) < 0) || (((int)(uVar1 << 0x1f) < 0 && (*(char *)(param_1 + 4) == '\0')))
     ) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  else if ((int)(uVar1 << 0x1f) < 0) {
    iVar4 = 0;
    do {
      if (((&DAT_0300004e)[iVar4] != '\0') &&
         ((uint)(byte)(&gUnknown_081C7A84)[iVar4] ==
          *(uint *)(&DAT_0202c220 + (uint)*(byte *)(param_1 + 4) * 8))) {
        iVar2 = __call_via_r0((&DAT_085c225c)[iVar4 * 6]);
        if (iVar2 == 0) {
          sub_0800ACFE(5);
        }
        else {
          (&DAT_0300004e)[iVar4] = (&DAT_0300004e)[iVar4] + -1;
          sub_0800ACFE(1);
          if ((&DAT_085c2260)[iVar4 * 6] != 0) {
            DAT_030005a8 = 0x80061d1;
            DAT_030005ac = 0x8000;
            DAT_030005ae = 0x8000;
            DAT_030005b0 = 0x7fff;
            DAT_030005b2 = 0x7fff;
            DAT_030005b4 = 3;
            DAT_03003b60 = DAT_03003b60 + -1;
            DAT_030005b8 = (&DAT_085c2260)[iVar4 * 6];
            sub_08009798();
            sub_080060E6(&DAT_030005a8);
          }
        }
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x22);
    sub_0800174A(param_1);
    if (*(byte *)(param_1 + 6) < *(byte *)(param_1 + 4)) {
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
  return 0;
}


/* sub_080019D8 @ 0x080019D8 */

void sub_080019D8(void)

{
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_0800FFCC);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(2,0x10);
  return;
}


/* sub_08001A04 @ 0x08001A04 */

void sub_08001A04(void)

{
  uint uVar1;
  
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_08009486(&DAT_0800ffd4,&DAT_02029d94);
  uVar1 = 0;
  do {
    if (((uint)DAT_0300004d & 1 << (uVar1 & 0xff)) != 0) {
      DAT_02029da0 = (short)uVar1 * 2 + 7;
      DAT_02029d9e = 6;
      sub_08008E06(&DAT_02029d94,(&DAT_08010000)[uVar1]);
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 3);
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08001A50 @ 0x08001A50 */

undefined4 sub_08001A50(void)

{
  if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
    sub_0800ACFE(0);
    sub_08009798();
  }
  return 0;
}


/* sub_08001A8C @ 0x08001A8C */

void sub_08001A8C(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 1) = 0;
  iVar1 = *(int *)(*param_1 + 0x14);
  __call_via_r1(param_1,iVar1 + *param_1,iVar1,param_4,param_4);
  return;
}


/* sub_08001A9E @ 0x08001A9E */

void sub_08001A9E(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_0800946E(&gUnknown_08010038,&DAT_02029d94);
  sub_08009486(&DAT_08010054,&DAT_02029d94);
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08001AC4 @ 0x08001AC4 */

undefined4 sub_08001AC4(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = sub_080094B8(&DAT_08010054,param_1 + 4);
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
        sub_080008B4(&DAT_03000028,*(undefined1 *)(param_1 + 4));
        DAT_03003b60 = DAT_03003b60 + -1;
        sub_08009798();
        sub_080060E6(&DAT_08010080);
      }
      else {
        DAT_030005d4 = (uint)*(byte *)(param_1 + 4);
        DAT_030005d0 = 1;
        sub_080097F8(&DAT_030005cc);
      }
    }
    else if (cVar1 == '\x02') {
      sub_0800ACFE(0);
      sub_08009798();
    }
  }
  return 0;
}


/* sub_08001B5C @ 0x08001B5C */

void sub_08001B5C(int param_1)

{
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&DAT_08010030);
  sub_08008D8A(&DAT_0202addc);
  sub_08000A32(5,*(byte *)(param_1 + 4) + 0xd);
  return;
}


/* sub_08001B8E @ 0x08001B8E */

void sub_08001B8E(int param_1)

{
  undefined4 uVar1;
  
  sub_08008D14(&DAT_0202a5b8);
  sub_080090AE(&DAT_0202a5b8,&DAT_0801004a);
  sub_080090AE(&DAT_02029d94,&DAT_0801004a);
  DAT_02029d9e = 6;
  DAT_02029da0 = 9;
  sub_08008E3A(&DAT_02029d94,"Overwrite Slot %d?",*(int *)(param_1 + 8) + 1);
  DAT_02029d9e = 10;
  DAT_02029da0 = 0xb;
  sub_08008E3A(&DAT_02029d94,sub_08001CA0);
  DAT_02029d9e = 0x11;
  DAT_02029da0 = 0xb;
  sub_08008E3A(&DAT_02029d94,0x8001ca4);
  uVar1 = 8;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0xf;
  }
  sub_08000A32(uVar1,0xb);
  sub_08008D8A(&DAT_02029d94);
  sub_08008D8A(&DAT_0202a5b8);
  return;
}


/* sub_08001C04 @ 0x08001C04 */

undefined4 sub_08001C04(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)DAT_03003d14;
  if (-1 < (int)(uVar1 << 0x1e)) {
    iVar2 = -((int)(uVar1 << 0x1f) >> 0x1f);
    iVar3 = param_4;
    if ((iVar2 == 0) || (iVar3 = *(int *)(param_1 + 4), iVar3 != 0)) {
      if ((int)(uVar1 << 0x1f) < 0) {
        sub_080008B4(&DAT_03000028,*(undefined4 *)(param_1 + 8),iVar2,iVar3,param_4);
        DAT_03003b60 = DAT_03003b60 + -2;
        sub_08009798();
        sub_080060E6(&DAT_08010080);
        return 0;
      }
      if ((-1 < (int)(uVar1 << 0x1a)) && (-1 < (int)(uVar1 << 0x1b))) {
        return 0;
      }
      *(uint *)(param_1 + 4) = (uint)(*(int *)(param_1 + 4) == 0);
      return 0;
    }
  }
  sub_0800ACFE(0);
  sub_08009798();
  return 0;
}


/* sub_08001CA0 @ 0x08001CA0 */

void sub_08001CA0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r6;
  
  *(undefined4 *)(param_4 + 0x54) = param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8,param_2,param_3,unaff_r6 << 1);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_08010094);
  sub_08008D8A(&DAT_0202addc);
  REG_DISPCNT = 0x2f00;
  REG_WININ = 0x3f;
  REG_WINOUT = 0x3e;
  DAT_04000041 = 0x10;
  DAT_04000045 = 0x54;
  REG_WIN0H = 0xe0;
  DAT_04000044 = 0x94;
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  return;
}


/* sub_08001CA8 @ 0x08001CA8 */

void sub_08001CA8(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(&DAT_0202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,&gUnknown_08010094);
  sub_08008D8A(&DAT_0202addc);
  REG_DISPCNT = 0x2f00;
  REG_WININ = 0x3f;
  REG_WINOUT = 0x3e;
  DAT_04000041 = 0x10;
  DAT_04000045 = 0x54;
  REG_WIN0H = 0xe0;
  DAT_04000044 = 0x94;
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  return;
}


/* sub_08001CFA @ 0x08001CFA */

void sub_08001CFA(int param_1)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  
  sub_08008D14(&DAT_02029d94);
  iVar2 = *(int *)(param_1 + 4);
  sub_0800E640(0x11c0,iVar2);
  DAT_02029da0 = (short)(iVar2 >> 5) + 10U & 0x1f;
  iVar2 = 0;
  DAT_02029d9e = 2;
  do {
    iVar1 = iVar2 + (extraout_r1 >> 5);
    if (0x8d < iVar1) break;
    sub_08009064(&DAT_02029d94,(&PTR_gUnknown_080102D4_0801009c)[iVar1]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xb);
  sub_08008D8A(&DAT_02029d94);
  REG_BG0VOFS = (short)(*(int *)(param_1 + 4) >> 2);
  return;
}


/* sub_08001D52 @ 0x08001D52 */

undefined4 sub_08001D52(int param_1)

{
  if ((int)((uint)DAT_03003d12 << 0x18) < 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  else if (-1 < (int)((uint)DAT_03003d12 << 0x19)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
    sub_0800ACFE(0);
    REG_DISPCNT = 0x1f00;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    sub_08009798();
  }
  return 0;
}


/* sub_08001DA0 @ 0x08001DA0 */

void sub_08001DA0(int param_1)

{
  sub_0800DCF0();
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


/* sub_08001DAE @ 0x08001DAE */

void sub_08001DAE(int param_1)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  
  sub_08008D14(&DAT_02029d94);
  iVar2 = *(int *)(param_1 + 4);
  sub_0800E640(0x1300,iVar2);
  iVar3 = 0;
  do {
    iVar1 = iVar3 + (extraout_r1 >> 5) + -10;
    if (0x8d < iVar1) break;
    if (-1 < iVar1) {
      DAT_02029d9e = 1;
      DAT_02029da0 = (ushort)((uint)(iVar2 << 0x16) >> 0x1b) + (short)iVar3 & 0x1f;
      sub_08009064(&DAT_02029d94,(&PTR_gUnknown_080102D4_0801009c)[iVar1]);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1f);
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08001E02 @ 0x08001E02 */

void sub_08001E02(int param_1)

{
  REG_BG0HOFS = 0;
  REG_BG0VOFS = (short)(*(int *)(param_1 + 4) >> 2);
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  return;
}


/* sub_08001E22 @ 0x08001E22 */

undefined4 sub_08001E22(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((int)((uint)DAT_03003d12 << 0x18) < 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  else if (-1 < (int)((uint)DAT_03003d12 << 0x19)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
    sub_08000F8C(&DAT_030000ec,0x300000c,param_1,param_4,param_4);
  }
  return 0;
}


/* sub_08001E90 @ 0x08001E90 */

void sub_08001E90(void)

{
  sub_080098F8();
  REG_DISPCNT = 0x900;
  REG_BG0CNT = 0x1c0f;
  REG_BG3CNT = 0x1f83;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586(&gUnknown_0819BCDC,&DAT_0202b600,0x6000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_0800946E(&gUnknown_0801082C,&DAT_02029d94);
  sub_08008D8A(&DAT_02029d94);
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  REG_BLDCNT = 0;
  DAT_030005ec = DAT_03003b6c + 0x708;
  return;
}


/* sub_08001F04 @ 0x08001F04 */

void sub_08001F04(void)

{
  sub_08008D14(&DAT_02029d94);
  if ((DAT_03003b6c & 0x3f) < 0x28) {
    sub_0800946E(&gUnknown_0801082C,&DAT_02029d94);
  }
  sub_08008D8A(&DAT_02029d94);
  return;
}


/* sub_08001F2A @ 0x08001F2A */

undefined4 sub_08001F2A(void)

{
  if ((int)((uint)DAT_03003d14 << 0x1c) < 0) {
    sub_08008DA0(&DAT_02029d94);
    sub_0800ACFE(0);
    sub_08009744(&DAT_03000018);
  }
  else if (DAT_030005ec < DAT_03003b6c) {
    sub_08009744(0x300000c);
  }
  return 0;
}


/* sub_08001FA8 @ 0x08001FA8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08001FA8(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 local_2c;
  undefined2 local_2a;
  short local_28;
  short sStack_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  
  DAT_0300004c = (undefined1)param_1;
  DAT_03000048 = *param_2;
  sub_080031E2();
  DAT_03000600 = (undefined4 *)(&gUnknown_081CA09C)[param_1];
  DAT_03000604 = (byte *)DAT_03000600[5];
  _DAT_030005f0 = *DAT_03000600;
  uVar1 = DAT_03000600[1];
  DAT_030005f6 = (short)(uVar1 >> 0x10);
  _DAT_030005f8 = CONCAT22(DAT_030005f6 << 3,(short)((uVar1 & 0xffff) << 3));
  _DAT_030005f4 = uVar1;
  DAT_030005fc = param_1;
  local_18 = _DAT_030005f8;
  sub_0800252E();
  DAT_030046b4 = &DAT_02013224;
  DAT_030047f4 = 0;
  DAT_030047f8 = 0;
  DAT_030047f0 = 0;
  DAT_03003b4c = 0;
  DAT_03003b50 = 0;
  DAT_03003b48 = 0;
  DAT_03003b58 = 0;
  DAT_03003b5c = 0;
  DAT_03003b54 = 0;
  sub_0800428E();
  sub_08003232(param_2);
  sub_08003120();
  sub_08004F56(DAT_03000600);
  if (*DAT_03000604 != 0xffffffff) {
    sub_0800A62C(&gUnknown_08591F3C + (uint)*DAT_03000604 * 0xc);
  }
  iVar3 = 0;
  if (0 < *(int *)(DAT_03000604 + 8)) {
    do {
      sub_080058D6(*(int *)(DAT_03000604 + 0xc) + iVar3 * 0xc);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(DAT_03000604 + 8));
  }
  iVar3 = 0;
  if (0 < *(int *)(DAT_03000604 + 0x10)) {
    do {
      sub_0800D1A0(*(undefined4 *)(*(int *)(DAT_03000604 + 0x14) + iVar3 * 8 + 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(DAT_03000604 + 0x10));
  }
  iVar3 = 0;
  if (0 < *(int *)(DAT_03000604 + 0x20)) {
    do {
      sub_0800697E(*(int *)(DAT_03000604 + 0x24) + iVar3 * 8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(DAT_03000604 + 0x20));
  }
  sub_08002328(&local_2c,DAT_030007b8);
  local_20 = local_2c;
  local_1e = local_2a;
  local_1c = local_28;
  local_1a = sStack_26;
  uVar2 = sub_0800F36C(&local_20);
  local_24 = 0x78;
  local_22 = 0x50;
  local_18._0_2_ = (short)uVar2;
  local_18._2_2_ = (short)((uint)uVar2 >> 0x10);
  local_28 = (short)local_18 + -0x78;
  sStack_26 = local_18._2_2_ + -0x50;
  DAT_03000608 = local_28;
  if (local_28 < 0) {
    DAT_03000608 = 0;
  }
  DAT_0300060a = sStack_26;
  if (sStack_26 < 0) {
    DAT_0300060a = 0;
  }
  if (DAT_030005f8 + -0xf0 < (int)DAT_03000608) {
    DAT_03000608 = (short)(DAT_030005f8 + -0xf0);
  }
  if (DAT_030005fa + -0xa0 < (int)DAT_0300060a) {
    DAT_0300060a = (short)(DAT_030005fa + -0xa0);
  }
  DAT_0300060c = DAT_03000608 + 0xf0;
  DAT_0300060e = DAT_0300060a + 0xa0;
  local_18 = uVar2;
  sub_080053F0();
  DAT_03003b60 = 0;
  sub_08009744(&DAT_0300010c);
  return;
}


/* sub_08002134 @ 0x08002134 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool sub_08002134(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short local_18;
  short sStack_16;
  short local_14;
  short sStack_12;
  short local_10;
  short sStack_e;
  
  uVar1 = sub_0800F36C(&DAT_03000608);
  uVar2 = sub_0800F36C(param_1);
  local_18 = (short)uVar2;
  local_10 = (short)uVar1;
  sStack_e = (short)((uint)uVar1 >> 0x10);
  local_14 = local_18 - local_10;
  sStack_16 = (short)((uint)uVar2 >> 0x10);
  sStack_12 = sStack_16 - sStack_e;
  if (local_14 < 1) {
    if (local_14 < 0) {
      local_14 = local_14 + 0x10;
      if (local_14 < -8) {
        local_14 = -8;
      }
      else if (0 < local_14) {
        local_14 = 0;
      }
    }
  }
  else {
    local_14 = local_14 + -0x10;
    if (local_14 < 9) {
      if (local_14 < 0) {
        local_14 = 0;
      }
    }
    else {
      local_14 = 8;
    }
  }
  if (sStack_12 < 1) {
    if (sStack_12 < 0) {
      sStack_12 = sStack_12 + 0x10;
      if (sStack_12 < -8) {
        sStack_12 = -8;
      }
      else if (0 < sStack_12) {
        sStack_12 = 0;
      }
    }
  }
  else {
    sStack_12 = sStack_12 + -0x10;
    if (sStack_12 < 9) {
      if (sStack_12 < 0) {
        sStack_12 = 0;
      }
    }
    else {
      sStack_12 = 8;
    }
  }
  DAT_03000608 = local_10 + local_14 + -0x78;
  DAT_0300060a = sStack_e + sStack_12 + -0x50;
  if (DAT_03000608 < 0) {
    DAT_03000608 = 0;
    local_14 = 0;
  }
  if (DAT_0300060a < 0) {
    DAT_0300060a = 0;
    sStack_12 = 0;
  }
  if (DAT_030005f8 + -0xf0 < (int)DAT_03000608) {
    DAT_03000608 = (short)(DAT_030005f8 + -0xf0);
    local_14 = 0;
  }
  if (DAT_030005fa + -0xa0 < (int)DAT_0300060a) {
    DAT_0300060a = (short)(DAT_030005fa + -0xa0);
    sStack_12 = 0;
  }
  DAT_0300060c = DAT_03000608 + 0xf0;
  DAT_0300060e = DAT_0300060a + 0xa0;
  return local_14 != 0 || sStack_12 != 0;
}


/* sub_080022A4 @ 0x080022A4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080022A4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  _DAT_03000608 = *param_1;
  uVar1 = _DAT_03000608;
  DAT_0300060c = DAT_03000608 + 0xf0;
  DAT_0300060a = (short)((uint)_DAT_03000608 >> 0x10);
  DAT_0300060e = DAT_0300060a + 0xa0;
  _DAT_03000608 = uVar1;
  return;
}


/* sub_080022BA @ 0x080022BA */

void sub_080022BA(void)

{
  sub_08008016();
  sub_08002FF6();
  sub_08004FD0(DAT_03000600);
  return;
}


