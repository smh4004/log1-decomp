/* Ghidra reference decompilation of code_08008814 (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* sub_08008814 @ 0x08008814 */

void sub_08008814(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  short *psVar5;
  short *psVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  bool bVar10;
  
  psVar5 = (short *)(param_2 + (uint)*(byte *)((int)param_1 + 0xf) * 2);
  bVar3 = *(byte *)((int)param_1 + 0xe);
  uVar9 = *param_1 << 0x12;
  pcVar7 = (char *)(param_1[2] + (*param_1 >> 0xe));
  uVar1 = param_1[1] * 0x40000;
  iVar2 = param_1[1] >> 0xe;
  if (uVar1 == 0) {
    psVar6 = psVar5;
    pcVar8 = pcVar7;
    if ((param_3 & 1) != 0) goto _08008858;
    do {
      pcVar8 = pcVar7 + iVar2;
      psVar6 = psVar5 + 2;
      *psVar5 = (short)*pcVar7 * (ushort)bVar3 + *psVar5;
_08008858:
      pcVar7 = pcVar8 + iVar2;
      psVar5 = psVar6 + 2;
      *psVar6 = (short)*pcVar8 * (ushort)bVar3 + *psVar6;
      bVar10 = 1 < param_3;
      param_3 = param_3 - 2;
    } while (bVar10 && param_3 != 0);
  }
  else {
    psVar6 = psVar5;
    if ((param_3 & 1) != 0) goto _08008894;
    do {
      cVar4 = *pcVar7;
      bVar10 = CARRY4(uVar9,uVar1);
      uVar9 = uVar9 + uVar1;
      pcVar7 = pcVar7 + (uint)bVar10 + iVar2;
      psVar6 = psVar5 + 2;
      *psVar5 = (short)cVar4 * (ushort)bVar3 + *psVar5;
_08008894:
      cVar4 = *pcVar7;
      bVar10 = CARRY4(uVar9,uVar1);
      uVar9 = uVar9 + uVar1;
      pcVar7 = pcVar7 + (uint)bVar10 + iVar2;
      psVar5 = psVar6 + 2;
      *psVar6 = (short)cVar4 * (ushort)bVar3 + *psVar6;
      bVar10 = 1 < param_3;
      param_3 = param_3 - 2;
    } while (bVar10 && param_3 != 0);
  }
  return;
}


/* sub_080088F4 @ 0x080088F4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080088F4(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *unaff_r7;
  
  *unaff_r7 = param_4;
  unaff_r7[1] = unaff_r4;
  unaff_r7[2] = unaff_r7;
  if ((param_2 >> 0x16 == 0x80) && ((char)DAT_03003d40 == '\0')) {
    DAT_030047e8 = (ushort)(byte)sub_08008AF0 << 0xc;
    REG_DMA3SAD = 0x30047e8;
    REG_DMA3DAD = 0x8008b14;
    Ram040000dc = 0x400;
    DAT_040000de = 0x8100;
    sub_08008AF4 = _sub_08008AF2;
                    /* WARNING: Read-only address (ram,0x08008afc) is written */
    uRam08008afc = _sub_08008AF4;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08008ade. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* sub_080088F8 @ 0x080088F8 */

undefined8 sub_080088F8(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  byte *pbVar7;
  char extraout_r1;
  uint uVar8;
  byte *unaff_r4;
  int iVar9;
  uint *unaff_r6;
  bool bVar10;
  uint uStack00000000;
  undefined1 uStack00000014;
  int in_stack_00000018;
  byte *pbStack0000001c;
  
  pbStack0000001c = (byte *)(param_4 << 0x1e);
_08008B38:
  bVar1 = *pbStack0000001c;
  if (bVar1 == 0) {
    *unaff_r4 = 0;
_08008B54:
    return CONCAT44(param_2,(int)unaff_r4 - in_stack_00000018);
  }
  if (bVar1 == 0x25) {
    iVar9 = 0;
    _uStack00000014 = 0x20;
_08008B58:
    pbStack0000001c = pbStack0000001c + 1;
    uVar3 = (uint)*pbStack0000001c;
    if (uVar3 == 0x36) {
_08008BDA:
      param_2 = iVar9 * 10;
      iVar9 = param_2 + (uVar3 - 0x30);
      goto _08008B58;
    }
    if (uVar3 < 0x37) {
      if (uVar3 == 0x32) goto _08008BDA;
      if (uVar3 < 0x33) {
        if (uVar3 == 0) {
          *unaff_r4 = 0;
          goto _08008B54;
        }
        if (uVar3 == 0x25) {
          *unaff_r4 = 0x25;
          unaff_r4 = unaff_r4 + 1;
          goto _08008CE0;
        }
        if (uVar3 == 0x30) {
          _uStack00000014 = 0x30;
          goto _08008B58;
        }
        if (uVar3 != 0x31) goto _08008B58;
      }
      else if (((uVar3 != 0x33) && (uVar3 != 0x34)) && (uVar3 != 0x35)) goto _08008B58;
      goto _08008BDA;
    }
    if (uVar3 == 0x69) goto _08008BA2;
    if (uVar3 < 0x6a) {
      if ((uVar3 == 0x37) || (uVar3 == 0x38)) goto _08008BDA;
      if (uVar3 != 99) goto code_r0x08008b9e;
      uVar6 = *(undefined4 *)*unaff_r6;
      param_2 = (int)((undefined4 *)*unaff_r6 + 1);
      *unaff_r6 = param_2;
      *unaff_r4 = (byte)uVar6;
      unaff_r4 = unaff_r4 + 1;
      goto _08008CE0;
    }
    if (uVar3 != 0x70) {
      if (uVar3 == 0x73) {
        pbVar7 = *(byte **)*unaff_r6;
        *unaff_r6 = (uint)((undefined4 *)*unaff_r6 + 1);
        if (iVar9 == 0) {
          bVar1 = *pbVar7;
          while (param_2 = (int)bVar1, (undefined4 *)param_2 != (undefined4 *)0x0) {
            bVar1 = *pbVar7;
            pbVar7 = pbVar7 + 1;
            *unaff_r4 = bVar1;
            unaff_r4 = unaff_r4 + 1;
            bVar1 = *pbVar7;
          }
        }
        else {
          while( true ) {
            bVar1 = *pbVar7;
            param_2 = (int)bVar1;
            if (((undefined4 *)param_2 == (undefined4 *)0x0) ||
               (bVar10 = iVar9 == 0, iVar9 = iVar9 + -1, bVar10)) break;
            pbVar7 = pbVar7 + 1;
            *unaff_r4 = bVar1;
            unaff_r4 = unaff_r4 + 1;
          }
        }
        goto _08008CE0;
      }
      if (uVar3 == 0x78) goto _08008C46;
      goto _08008B58;
    }
    iVar9 = 8;
    _uStack00000014 = 0x30;
_08008C46:
    uVar3 = *(uint *)*unaff_r6;
    *unaff_r6 = (uint)((uint *)*unaff_r6 + 1);
    puVar4 = (undefined4 *)0x0;
    do {
      uVar8 = uVar3 & 0xf;
      puVar5 = (undefined4 *)((int)puVar4 + 1);
      uVar3 = uVar3 >> 4;
      (&stack0x00000004)[(int)puVar4] = sub_08008D00[uVar8];
      puVar4 = puVar5;
    } while (uVar3 != 0);
    param_2 = 0;
    if ((iVar9 != 0) && ((int)puVar5 < iVar9)) {
      do {
        param_2 = (int)puVar5;
        puVar5 = (undefined4 *)(param_2 + 1);
        (&stack0x00000004)[param_2] = (char)_uStack00000014;
      } while ((int)puVar5 < iVar9);
    }
    while (puVar5 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)((int)puVar5 - 1);
      bVar1 = (&stack0x00000004)[(int)puVar5];
      param_2 = (int)bVar1;
      *unaff_r4 = bVar1;
      unaff_r4 = unaff_r4 + 1;
    }
  }
  else {
    *unaff_r4 = bVar1;
    unaff_r4 = unaff_r4 + 1;
  }
  goto _08008CE0;
code_r0x08008b9e:
  if (uVar3 == 100) goto _08008BA2;
  goto _08008B58;
_08008BA2:
  uVar3 = *(uint *)*unaff_r6;
  *unaff_r6 = (uint)((uint *)*unaff_r6 + 1);
  bVar10 = (int)uVar3 < 0;
  if (bVar10) {
    uVar3 = -uVar3;
  }
  uStack00000000 = (uint)bVar10;
  iVar2 = 0;
  while (9 < (int)uVar3) {
    uVar3 = sub_0800E748(uVar3);
    (&stack0x00000004)[iVar2] = extraout_r1 + '0';
    iVar2 = iVar2 + 1;
  }
  (&stack0x00000004)[iVar2] = (char)uVar3 + '0';
  param_2 = iVar2 + 1;
  if (uStack00000000 != 0) {
    (&stack0x00000004)[param_2] = 0x2d;
    param_2 = iVar2 + 2;
  }
  if (iVar9 != 0) {
    for (; param_2 < iVar9; param_2 = param_2 + 1) {
      (&stack0x00000004)[param_2] = uStack00000014;
    }
  }
  if ((undefined4 *)param_2 != (undefined4 *)0x0) {
    do {
      param_2 = param_2 - 1;
      *unaff_r4 = (&stack0x00000004)[param_2];
      unaff_r4 = unaff_r4 + 1;
    } while ((undefined4 *)param_2 != (undefined4 *)0x0);
    param_2 = 0;
  }
_08008CE0:
  pbStack0000001c = pbStack0000001c + 1;
  goto _08008B38;
}


/* sub_080088FC @ 0x080088FC */

void sub_080088FC(int *param_1,int param_2,int *param_3,int param_4)

{
  int unaff_r4;
  int unaff_r5;
  int iVar1;
  int unaff_r6;
  int unaff_r7;
  
  *param_1 = param_2;
  param_1[1] = unaff_r4;
  param_1[2] = unaff_r5;
  param_1[3] = unaff_r7;
  do {
    if (unaff_r5 < unaff_r7) {
      unaff_r5 = 0x80;
    }
    while( true ) {
      *(char *)((int)param_1 + param_4 + 0x10) = (char)unaff_r4;
      *(char *)(param_2 + param_4) = (char)unaff_r5;
      param_4 = param_4 + 1;
      if (param_4 == 0) {
        return;
      }
      iVar1 = *param_3;
      *param_3 = unaff_r6;
      param_3 = param_3 + 1;
      unaff_r5 = iVar1 >> 0x16;
      unaff_r4 = (iVar1 << 0x10) >> 0x16;
      if (unaff_r4 < 0x80) {
        if (unaff_r4 < unaff_r7) {
          unaff_r4 = 0x80;
        }
      }
      else {
        unaff_r4 = 0x7f;
      }
      if (unaff_r5 < 0x80) break;
      unaff_r5 = 0x7f;
    }
  } while( true );
}


/* sub_08008900 @ 0x08008900 */

void sub_08008900(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int unaff_r4;
  int unaff_r5;
  int iVar2;
  int unaff_r6;
  int unaff_r7;
  
  piVar1 = (int *)(unaff_r6 << 2);
  while( true ) {
    *(char *)(param_1 + param_4) = (char)unaff_r4;
    *(char *)(param_2 + param_4) = (char)unaff_r5;
    param_4 = param_4 + 1;
    if (param_4 == 0) break;
    iVar2 = *piVar1;
    *piVar1 = unaff_r6;
    piVar1 = piVar1 + 1;
    unaff_r5 = iVar2 >> 0x16;
    unaff_r4 = (iVar2 << 0x10) >> 0x16;
    if (unaff_r4 < 0x80) {
      if (unaff_r4 < unaff_r7) {
        unaff_r4 = 0x80;
      }
    }
    else {
      unaff_r4 = 0x7f;
    }
    if (unaff_r5 < 0x80) {
      if (unaff_r5 < unaff_r7) {
        unaff_r5 = 0x80;
      }
    }
    else {
      unaff_r5 = 0x7f;
    }
  }
  return;
}


/* sub_08008940 @ 0x08008940 */

int sub_08008940(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  char extraout_r1;
  int iVar6;
  uint uVar7;
  byte *unaff_r4;
  int iVar8;
  undefined4 *unaff_r6;
  undefined4 *unaff_r7;
  bool bVar9;
  uint uStack00000000;
  undefined1 uStack00000014;
  int in_stack_00000018;
  byte *pbStack0000001c;
  
  *unaff_r7 = param_4;
  unaff_r7[1] = unaff_r4;
  unaff_r7[2] = unaff_r7;
_08008B38:
  param_1 = param_1 + 1;
  bVar1 = *param_1;
  if (bVar1 == 0) {
    *unaff_r4 = 0;
_08008B54:
    return (int)unaff_r4 - in_stack_00000018;
  }
  if (bVar1 != 0x25) {
    *unaff_r4 = bVar1;
    unaff_r4 = unaff_r4 + 1;
    goto _08008B38;
  }
  iVar8 = 0;
  _uStack00000014 = 0x20;
  pbStack0000001c = param_1;
_08008B58:
  pbStack0000001c = pbStack0000001c + 1;
  uVar2 = (uint)*pbStack0000001c;
  if (uVar2 == 0x36) {
_08008BDA:
    iVar8 = iVar8 * 10 + uVar2 + -0x30;
    goto _08008B58;
  }
  param_1 = pbStack0000001c;
  if (uVar2 < 0x37) {
    if (uVar2 != 0x32) {
      if (uVar2 < 0x33) {
        if (uVar2 == 0) {
          *unaff_r4 = 0;
          goto _08008B54;
        }
        if (uVar2 == 0x25) {
          *unaff_r4 = 0x25;
          unaff_r4 = unaff_r4 + 1;
          goto _08008B38;
        }
        if (uVar2 == 0x30) {
          _uStack00000014 = 0x30;
        }
        else if (uVar2 == 0x31) goto _08008BDA;
        goto _08008B58;
      }
      if (((uVar2 != 0x33) && (uVar2 != 0x34)) && (uVar2 != 0x35)) goto _08008B58;
    }
    goto _08008BDA;
  }
  if (uVar2 == 0x69) goto _08008BA2;
  if (uVar2 < 0x6a) {
    if ((uVar2 == 0x37) || (uVar2 == 0x38)) goto _08008BDA;
    if (uVar2 == 99) {
      uVar4 = *(undefined4 *)*unaff_r6;
      *unaff_r6 = (undefined4 *)*unaff_r6 + 1;
      *unaff_r4 = (byte)uVar4;
      unaff_r4 = unaff_r4 + 1;
      goto _08008B38;
    }
    if (uVar2 == 100) goto _08008BA2;
    goto _08008B58;
  }
  if (uVar2 == 0x70) {
    iVar8 = 8;
    _uStack00000014 = 0x30;
  }
  else {
    if (uVar2 == 0x73) {
      pbVar5 = *(byte **)*unaff_r6;
      *unaff_r6 = (undefined4 *)*unaff_r6 + 1;
      if (iVar8 == 0) {
        bVar1 = *pbVar5;
        while (bVar1 != 0) {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          *unaff_r4 = bVar1;
          unaff_r4 = unaff_r4 + 1;
          bVar1 = *pbVar5;
        }
      }
      else {
        while ((bVar1 = *pbVar5, bVar1 != 0 && (bVar9 = iVar8 != 0, iVar8 = iVar8 + -1, bVar9))) {
          pbVar5 = pbVar5 + 1;
          *unaff_r4 = bVar1;
          unaff_r4 = unaff_r4 + 1;
        }
      }
      goto _08008B38;
    }
    if (uVar2 != 0x78) goto _08008B58;
  }
  uVar2 = *(uint *)*unaff_r6;
  *unaff_r6 = (uint *)*unaff_r6 + 1;
  iVar3 = 0;
  do {
    uVar7 = uVar2 & 0xf;
    iVar6 = iVar3 + 1;
    uVar2 = uVar2 >> 4;
    (&stack0x00000004)[iVar3] = sub_08008D00[uVar7];
    iVar3 = iVar6;
  } while (uVar2 != 0);
  if ((iVar8 != 0) && (iVar6 < iVar8)) {
    do {
      iVar6 = iVar3 + 1;
      (&stack0x00000004)[iVar3] = (char)_uStack00000014;
      iVar3 = iVar6;
    } while (iVar6 < iVar8);
  }
  for (; param_1 = pbStack0000001c, iVar6 != 0; iVar6 = iVar6 + -1) {
    *unaff_r4 = ((undefined1 *)((int)register0x00000054 + 3))[iVar6];
    unaff_r4 = unaff_r4 + 1;
  }
  goto _08008B38;
_08008BA2:
  uVar2 = *(uint *)*unaff_r6;
  *unaff_r6 = (uint *)*unaff_r6 + 1;
  bVar9 = (int)uVar2 < 0;
  if (bVar9) {
    uVar2 = -uVar2;
  }
  uStack00000000 = (uint)bVar9;
  iVar3 = 0;
  while (9 < (int)uVar2) {
    uVar2 = sub_0800E748(uVar2);
    (&stack0x00000004)[iVar3] = extraout_r1 + '0';
    iVar3 = iVar3 + 1;
  }
  (&stack0x00000004)[iVar3] = (char)uVar2 + '0';
  iVar6 = iVar3 + 1;
  if (uStack00000000 != 0) {
    (&stack0x00000005)[iVar3] = 0x2d;
    iVar6 = iVar3 + 2;
  }
  if (iVar8 != 0) {
    for (; iVar6 < iVar8; iVar6 = iVar6 + 1) {
      (&stack0x00000004)[iVar6] = uStack00000014;
    }
  }
  for (; param_1 = pbStack0000001c, iVar6 != 0; iVar6 = iVar6 + -1) {
    *unaff_r4 = ((undefined1 *)((int)register0x00000054 + 3))[iVar6];
    unaff_r4 = unaff_r4 + 1;
  }
  goto _08008B38;
}


/* sub_08008954 @ 0x08008954 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08008954(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((uint)UNRECOVERED_JUMPTABLE & 0x3fffffff) == 0) && ((char)DAT_03003d40 == '\0')) {
    DAT_030047e8 = (ushort)(byte)sub_08008AF0 << 0xc;
    REG_DMA3SAD = 0x30047e8;
    REG_DMA3DAD = 0x8008b14;
    Ram040000dc = 0x400;
    DAT_040000de = 0x8100;
    sub_08008AF4 = _sub_08008AF2;
                    /* WARNING: Read-only address (ram,0x08008afc) is written */
    uRam08008afc = _sub_08008AF4;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08008ade. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* sub_08008958 @ 0x08008958 */

void sub_08008958(byte *param_1,undefined4 param_2,int param_3,int param_4)

{
  *(short *)(param_3 + 6) = (short)param_1;
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_0800895C @ 0x0800895C */

void sub_0800895C(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  
  *param_1 = unaff_r4;
  param_1[1] = unaff_r5;
  param_1[2] = unaff_r6;
  param_1[3] = unaff_r7;
  DAT_030047e8 = (ushort)*(byte *)(param_1 + 4) << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0xd;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)((int)param_1 + 0x12);
  *(undefined2 *)(param_1 + 7) = *(undefined2 *)(param_1 + 5);
  return;
}


/* sub_08008960 @ 0x08008960 */

void sub_08008960(byte *param_1,int param_2,int param_3,int param_4)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_08008984 @ 0x08008984 */

void sub_08008984(void)

{
  return;
}


/* sub_080089A0 @ 0x080089A0 */

void sub_080089A0(undefined4 param_1,short *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  char cVar4;
  short *psVar5;
  char *pcVar6;
  char *pcVar7;
  int unaff_r4;
  uint unaff_r5;
  short unaff_r7;
  short unaff_r8;
  int unaff_r9;
  bool bVar8;
  
  uVar1 = unaff_r4 * 0x40000;
  pcVar6 = (char *)(unaff_r9 + (param_4 >> 0xe));
  iVar2 = unaff_r4 >> 0xe;
  if (uVar1 == 0) {
    pcVar7 = pcVar6;
    if ((param_3 & 1) != 0) goto _080089D8;
    do {
      pcVar7 = pcVar6 + iVar2;
      cVar4 = *pcVar6;
      psVar3 = param_2 + 1;
      psVar5 = param_2 + 1;
      *param_2 = cVar4 * unaff_r7 + *param_2;
      param_2 = param_2 + 2;
      *psVar5 = cVar4 * unaff_r8 + *psVar3;
_080089D8:
      pcVar6 = pcVar7 + iVar2;
      cVar4 = *pcVar7;
      psVar3 = param_2 + 1;
      psVar5 = param_2 + 1;
      *param_2 = cVar4 * unaff_r7 + *param_2;
      param_2 = param_2 + 2;
      *psVar5 = cVar4 * unaff_r8 + *psVar3;
      bVar8 = 1 < param_3;
      param_3 = param_3 - 2;
    } while (bVar8 && param_3 != 0);
  }
  else {
    if ((param_3 & 1) != 0) goto _08008A2C;
    do {
      cVar4 = *pcVar6;
      psVar3 = param_2 + 1;
      bVar8 = CARRY4(unaff_r5,uVar1);
      unaff_r5 = unaff_r5 + uVar1;
      pcVar6 = pcVar6 + (uint)bVar8 + iVar2;
      psVar5 = param_2 + 1;
      *param_2 = cVar4 * unaff_r7 + *param_2;
      param_2 = param_2 + 2;
      *psVar5 = cVar4 * unaff_r8 + *psVar3;
_08008A2C:
      cVar4 = *pcVar6;
      psVar3 = param_2 + 1;
      bVar8 = CARRY4(unaff_r5,uVar1);
      unaff_r5 = unaff_r5 + uVar1;
      pcVar6 = pcVar6 + (uint)bVar8 + iVar2;
      psVar5 = param_2 + 1;
      *param_2 = cVar4 * unaff_r7 + *param_2;
      param_2 = param_2 + 2;
      *psVar5 = cVar4 * unaff_r8 + *psVar3;
      bVar8 = 1 < param_3;
      param_3 = param_3 - 2;
    } while (bVar8 && param_3 != 0);
  }
  return;
}


/* sub_08008A60 @ 0x08008A60 */

void sub_08008A60(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = -param_4;
  do {
    iVar2 = *param_3;
    *param_3 = 0;
    param_3 = param_3 + 1;
    iVar3 = iVar2 >> 0x16;
    iVar2 = (iVar2 << 0x10) >> 0x16;
    if (iVar2 < 0x80) {
      if (iVar2 < -0x80) {
        iVar2 = 0x80;
      }
    }
    else {
      iVar2 = 0x7f;
    }
    if (iVar3 < 0x80) {
      if (iVar3 < -0x80) {
        iVar3 = 0x80;
      }
    }
    else {
      iVar3 = 0x7f;
    }
    *(char *)(param_1 + param_4 + iVar1) = (char)iVar2;
    *(char *)(param_2 + param_4 + iVar1) = (char)iVar3;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0);
  return;
}


/* sub_08008AA4 @ 0x08008AA4 */

void sub_08008AA4(void)

{
  return;
}


/* sub_08008AA6 @ 0x08008AA6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08008AA6(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = DAT_03003d34 + 0x10;
  DAT_03003d34 = uVar1;
  if ((uVar1 & 0x1ff) == 0) {
    if ((int)(uVar1 * 0x400000) < 0) {
      puVar3 = &REG_DMA2SAD;
      Ram040000d0 = 0;
      puVar2 = &DAT_0203fc00;
      puVar4 = &REG_FIFO_B;
    }
    else {
      puVar3 = &REG_DMA1SAD;
      Ram040000c4 = 0;
      puVar2 = &DAT_0203f800;
      puVar4 = &REG_FIFO_A;
      DAT_03003d34 = 0;
    }
    *puVar3 = puVar2;
    puVar3[1] = puVar4;
    puVar3[2] = 0xf6400004;
  }
  if (((DAT_03003d38 - uVar1 & 0x3ff) == 0x80) && ((char)DAT_03003d40 == '\0')) {
    DAT_030047e8 = (ushort)(byte)sub_08008AF0 << 0xc;
    REG_DMA3SAD = 0x30047e8;
    REG_DMA3DAD = 0x8008b14;
    Ram040000dc = 0x400;
    DAT_040000de = 0x8100;
    sub_08008AF4 = _sub_08008AF2;
                    /* WARNING: Read-only address (ram,0x08008afc) is written */
    uRam08008afc = _sub_08008AF4;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08008ade. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


/* sub_08008AEE @ 0x08008AEE */

void sub_08008AEE(byte *param_1)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_08008AF0 @ 0x08008AF0 */

void sub_08008AF0(byte *param_1)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_08008AF2 @ 0x08008AF2 */

void sub_08008AF2(byte *param_1)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_08008AF4 @ 0x08008AF4 */

void sub_08008AF4(uint param_1,undefined *UNRECOVERED_JUMPTABLE)

{
                    /* WARNING: Could not recover jumptable at 0x08008afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1 & 0xffffff7f);
  return;
}


/* sub_08008B30 @ 0x08008B30 */

int sub_08008B30(byte *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  char extraout_r1;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  undefined4 local_24;
  byte *local_20;
  byte *local_1c;
  undefined4 *puStack_18;
  
  puStack_18 = param_3;
  local_20 = param_1;
  local_1c = param_2;
_08008B38:
  bVar1 = *local_1c;
  if (bVar1 == 0) {
    *param_1 = 0;
_08008B54:
    return (int)param_1 - (int)local_20;
  }
  if (bVar1 == 0x25) {
    iVar8 = 0;
    local_24 = 0x20;
_08008B58:
    local_1c = local_1c + 1;
    uVar2 = (uint)*local_1c;
    if (uVar2 == 0x36) {
_08008BDA:
      iVar8 = iVar8 * 10 + uVar2 + -0x30;
      goto _08008B58;
    }
    if (uVar2 < 0x37) {
      if (uVar2 == 0x32) goto _08008BDA;
      if (uVar2 < 0x33) {
        if (uVar2 == 0) {
          *param_1 = 0;
          goto _08008B54;
        }
        if (uVar2 == 0x25) {
          *param_1 = 0x25;
          param_1 = param_1 + 1;
          goto _08008CE0;
        }
        if (uVar2 == 0x30) {
          local_24 = 0x30;
          goto _08008B58;
        }
        if (uVar2 != 0x31) goto _08008B58;
      }
      else if (((uVar2 != 0x33) && (uVar2 != 0x34)) && (uVar2 != 0x35)) goto _08008B58;
      goto _08008BDA;
    }
    if (uVar2 == 0x69) goto _08008BA2;
    if (uVar2 < 0x6a) {
      if ((uVar2 == 0x37) || (uVar2 == 0x38)) goto _08008BDA;
      if (uVar2 != 99) goto code_r0x08008b9e;
      uVar4 = *(undefined4 *)*param_3;
      *param_3 = (undefined4 *)*param_3 + 1;
      *param_1 = (byte)uVar4;
      param_1 = param_1 + 1;
      goto _08008CE0;
    }
    if (uVar2 != 0x70) {
      if (uVar2 == 0x73) {
        pbVar5 = *(byte **)*param_3;
        *param_3 = (undefined4 *)*param_3 + 1;
        if (iVar8 == 0) {
          bVar1 = *pbVar5;
          while (bVar1 != 0) {
            bVar1 = *pbVar5;
            pbVar5 = pbVar5 + 1;
            *param_1 = bVar1;
            param_1 = param_1 + 1;
            bVar1 = *pbVar5;
          }
        }
        else {
          while ((bVar1 = *pbVar5, bVar1 != 0 && (bVar9 = iVar8 != 0, iVar8 = iVar8 + -1, bVar9))) {
            pbVar5 = pbVar5 + 1;
            *param_1 = bVar1;
            param_1 = param_1 + 1;
          }
        }
        goto _08008CE0;
      }
      if (uVar2 == 0x78) goto _08008C46;
      goto _08008B58;
    }
    iVar8 = 8;
    local_24 = 0x30;
_08008C46:
    uVar2 = *(uint *)*param_3;
    *param_3 = (uint *)*param_3 + 1;
    iVar3 = 0;
    do {
      uVar7 = uVar2 & 0xf;
      iVar6 = iVar3 + 1;
      uVar2 = uVar2 >> 4;
      auStack_34[iVar3] = sub_08008D00[uVar7];
      iVar3 = iVar6;
    } while (uVar2 != 0);
    if ((iVar8 != 0) && (iVar6 < iVar8)) {
      do {
        iVar6 = iVar3 + 1;
        auStack_34[iVar3] = (char)local_24;
        iVar3 = iVar6;
      } while (iVar6 < iVar8);
    }
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      *param_1 = auStack_34[iVar6 + -1];
      param_1 = param_1 + 1;
    }
  }
  else {
    *param_1 = bVar1;
    param_1 = param_1 + 1;
  }
  goto _08008CE0;
code_r0x08008b9e:
  if (uVar2 == 100) goto _08008BA2;
  goto _08008B58;
_08008BA2:
  uVar2 = *(uint *)*param_3;
  *param_3 = (uint *)*param_3 + 1;
  bVar9 = (int)uVar2 < 0;
  if (bVar9) {
    uVar2 = -uVar2;
  }
  uStack_38 = (uint)bVar9;
  iVar3 = 0;
  while (9 < (int)uVar2) {
    uVar2 = sub_0800E748(uVar2);
    auStack_34[iVar3] = extraout_r1 + '0';
    iVar3 = iVar3 + 1;
  }
  auStack_34[iVar3] = (char)uVar2 + '0';
  iVar6 = iVar3 + 1;
  if (uStack_38 != 0) {
    auStack_34[iVar3 + 1] = 0x2d;
    iVar6 = iVar3 + 2;
  }
  if (iVar8 != 0) {
    for (; iVar6 < iVar8; iVar6 = iVar6 + 1) {
      auStack_34[iVar6] = (undefined1)local_24;
    }
  }
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    *param_1 = auStack_34[iVar6 + -1];
    param_1 = param_1 + 1;
  }
_08008CE0:
  local_1c = local_1c + 1;
  goto _08008B38;
}


/* sub_08008CE8 @ 0x08008CE8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sub_08008CE8(void...)

{
  byte *in_r0;
  byte *in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 *local_18 [2];
  byte *pbStack_10;
  byte *local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_18[0] = &uStack_8;
  pbStack_10 = in_r0;
  local_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  sub_08008B30(in_r0,in_r1,local_18);
  return;
}


/* sub_08008D00 @ 0x08008D00 */

void sub_08008D00(byte *param_1,int param_2,int param_3,int param_4)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_08008D14 @ 0x08008D14 */

void sub_08008D14(byte *param_1)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}


/* sub_08008D3A @ 0x08008D3A */

void sub_08008D3A(byte *param_1,undefined4 param_2,undefined4 param_3,byte param_4,
                 undefined2 *param_5)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *param_1 = param_4;
  *(undefined2 *)(param_1 + 2) = *param_5;
  *(undefined2 *)(param_1 + 4) = param_5[1];
  *(undefined2 *)(param_1 + 6) = param_5[2];
  *(undefined2 *)(param_1 + 8) = param_5[3];
  REG_DMA3SAD = 0x815b928;
  REG_DMA3DAD = &DAT_05000000 + (uint)*param_1 * 0x10;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  uVar1 = sub_080095DC(0x815b2f0);
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = param_3;
  Ram040000dc = 0x690;
  DAT_040000de = 0x8000;
  sub_08008D14(param_1);
  return;
}


/* sub_08008D8A @ 0x08008D8A */

void sub_08008D8A(int param_1)

{
  REG_DMA3SAD = param_1 + 0x24;
  REG_DMA3DAD = *(undefined4 *)(param_1 + 0x10);
  Ram040000dc = 0x400;
  DAT_040000de = 0x8000;
  return;
}


/* sub_08008DA0 @ 0x08008DA0 */

void sub_08008DA0(byte *param_1)

{
  sub_08008D14(param_1);
  REG_DMA3SAD = param_1 + 0x24;
  REG_DMA3DAD = *(undefined4 *)(param_1 + 0x10);
  Ram040000dc = 0x400;
  DAT_040000de = 0x8000;
  return;
}


/* sub_08008DBE @ 0x08008DBE */

void sub_08008DBE(byte *param_1,short param_2)

{
  int iVar1;
  
  *(ushort *)(param_1 + *(short *)(param_1 + 10) * 2 + *(short *)(param_1 + 0xc) * 0x40 + 0x24) =
       (ushort)*param_1 * 0x1000 + param_2 + -0x1e;
  iVar1 = (*(ushort *)(param_1 + 10) + 1) * 0x10000;
  *(short *)(param_1 + 10) = (short)((uint)iVar1 >> 0x10);
  if ((int)*(short *)(param_1 + 6) <= iVar1 >> 0x10) {
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    iVar1 = *(int *)(param_1 + 0x18);
    *(int *)(param_1 + 0x18) = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      param_1[0x20] = 1;
      param_1[0x21] = 0;
      param_1[0x22] = 0;
      param_1[0x23] = 0;
    }
  }
  return;
}


/* sub_08008E06 @ 0x08008E06 */

void sub_08008E06(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    if (bVar1 == 10) {
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
      *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
      iVar2 = *(int *)(param_1 + 0x18);
      *(int *)(param_1 + 0x18) = iVar2 + -1;
      if (iVar2 + -1 == 0) {
        param_1[0x20] = 1;
        param_1[0x21] = 0;
        param_1[0x22] = 0;
        param_1[0x23] = 0;
      }
    }
    else {
      sub_08008DBE(param_1,(ushort)bVar1);
    }
    param_2 = param_2 + 1;
  }
  return;
}


/* sub_08008E3A @ 0x08008E3A */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sub_08008E3A(void...)

{
  byte bVar1;
  undefined1 uVar2;
  byte *in_r0;
  uint uVar3;
  char extraout_r1;
  byte *in_r1;
  uint uVar4;
  uint in_r2;
  int iVar5;
  int iVar6;
  undefined4 in_r3;
  int iVar7;
  char *pcVar8;
  uint *puVar9;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar10;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  byte *local_2c;
  undefined4 local_28;
  uint uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  uStack_8 = in_r2;
  puVar9 = &uStack_8;
  local_2c = in_r1;
_08008E48:
  bVar1 = *local_2c;
  if (bVar1 == 0) {
_08008F34:
                    /* WARNING: Could not recover jumptable at 0x08009062. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  if (bVar1 == 10) {
    *(undefined2 *)(in_r0 + 10) = *(undefined2 *)(in_r0 + 2);
    *(short *)(in_r0 + 0xc) = *(short *)(in_r0 + 0xc) + 1;
    iVar7 = *(int *)(in_r0 + 0x18);
    *(int *)(in_r0 + 0x18) = iVar7 + -1;
    if (iVar7 + -1 == 0) {
      in_r0[0x20] = 1;
      in_r0[0x21] = 0;
      in_r0[0x22] = 0;
      in_r0[0x23] = 0;
    }
  }
  else {
    if (bVar1 == 0x25) {
      iVar7 = 0;
      local_28 = 0x20;
_08008E78:
      local_2c = local_2c + 1;
      uVar3 = (uint)*local_2c;
      if (uVar3 != 0x37) {
        if (0x37 < uVar3) {
          if (uVar3 == 100) {
            uVar3 = *puVar9;
            puVar9 = puVar9 + 1;
            bVar10 = (int)uVar3 < 0;
            if (bVar10) {
              uVar3 = -uVar3;
            }
            uVar4 = (uint)bVar10;
            iVar5 = 0;
            while (9 < (int)uVar3) {
              uVar3 = sub_0800E748(uVar3);
              *(char *)((int)&uStack_3c + iVar5) = extraout_r1 + '0';
              iVar5 = iVar5 + 1;
            }
            *(char *)((int)&uStack_3c + iVar5) = (char)uVar3 + '0';
            iVar6 = iVar5 + 1;
            if (uVar4 != 0) {
              *(undefined1 *)((int)&uStack_3c + iVar5 + 1) = 0x2d;
              iVar6 = iVar5 + 2;
            }
            if ((iVar7 != 0) && (iVar6 < iVar7)) {
              uVar2 = (undefined1)local_28;
              iVar5 = iVar6;
              do {
                iVar6 = iVar5 + 1;
                *(undefined1 *)((int)&uStack_3c + iVar5) = uVar2;
                iVar5 = iVar6;
              } while (iVar6 < iVar7);
            }
            for (; iVar6 != 0; iVar6 = iVar6 + -1) {
              sub_08008DBE(in_r0,(ushort)(byte)(&stack0xffffffc3)[iVar6]);
            }
            goto _08009052;
          }
          if (100 < uVar3) {
            if (uVar3 != 0x70) {
              if (uVar3 != 0x73) goto code_r0x08008ed8;
              pcVar8 = (char *)*puVar9;
              puVar9 = puVar9 + 1;
              if (iVar7 == 0) {
                if ((byte *)pcVar8 == (byte *)0x0) {
                  pcVar8 = "<null>";
                }
                sub_08008E06(in_r0,(byte *)pcVar8);
              }
              else if ((byte *)pcVar8 == (byte *)0x0) {
                sub_08008E06(in_r0,(byte *)"<null>");
              }
              else {
                while ((bVar1 = *pcVar8, bVar1 != 0 &&
                       (bVar10 = iVar7 != 0, iVar7 = iVar7 + -1, bVar10))) {
                  pcVar8 = (char *)((byte *)pcVar8 + 1);
                  sub_08008DBE(in_r0,(ushort)bVar1);
                }
              }
              goto _08009052;
            }
            iVar7 = 8;
            local_28 = 0x30;
            goto _08008F70;
          }
          if (uVar3 == 0x38) goto _08008EE4;
          if (uVar3 == 0x42) {
            uVar4 = *puVar9;
            uVar3 = puVar9[1];
            uStack_30._2_2_ = (short)(uVar3 >> 0x10);
            uStack_3c = (int)uStack_30._2_2_;
            uStack_30._0_2_ = (short)uVar3;
            iVar5 = (int)(short)uStack_30;
            uStack_34._2_2_ = (short)(uVar4 >> 0x10);
            iVar7 = (int)uStack_34._2_2_;
            uStack_34._0_2_ = (short)uVar4;
            iVar6 = (int)(short)uStack_34;
            puVar9 = puVar9 + 2;
            uStack_34 = uVar4;
            uStack_30 = uVar3;
            sub_08008E3A(in_r0,"{%d,%d | %d,%d}",iVar6,iVar7,iVar5);
            goto _08009052;
          }
          if (uVar3 == 0x50) {
            uVar3 = *puVar9;
            uStack_30._2_2_ = (short)(uVar3 >> 0x10);
            iVar7 = (int)uStack_30._2_2_;
            uStack_30._0_2_ = (short)uVar3;
            iVar5 = (int)(short)uStack_30;
            puVar9 = puVar9 + 1;
            uStack_30 = uVar3;
            sub_08008E3A(in_r0,"(%d, %d)",iVar5,iVar7);
            goto _08009052;
          }
          if (uVar3 == 99) {
            uVar3 = *puVar9;
            puVar9 = puVar9 + 1;
            sub_08008DBE(in_r0,(short)uVar3);
            goto _08009052;
          }
          goto _08008E78;
        }
        if (uVar3 == 0x32) goto _08008EE4;
        if (uVar3 < 0x33) {
          if (uVar3 == 0) goto _08008F34;
          if (uVar3 == 0x25) {
            sub_08008DBE(in_r0,0x25);
            goto _08009052;
          }
          if (uVar3 == 0x30) {
            local_28 = 0x30;
            goto _08008E78;
          }
          if (uVar3 != 0x31) goto _08008E78;
        }
        else if ((((uVar3 != 0x33) && (uVar3 != 0x34)) && (uVar3 != 0x35)) && (uVar3 != 0x36))
        goto _08008E78;
      }
_08008EE4:
      iVar7 = iVar7 * 10 + uVar3 + -0x30;
      goto _08008E78;
    }
    sub_08008DBE(in_r0,(ushort)bVar1);
  }
  goto _08009052;
code_r0x08008ed8:
  if (uVar3 == 0x78) goto _08008F70;
  goto _08008E78;
_08008F70:
  uVar3 = *puVar9;
  puVar9 = puVar9 + 1;
  iVar5 = 0;
  do {
    uVar4 = uVar3 & 0xf;
    iVar6 = iVar5 + 1;
    uVar3 = uVar3 >> 4;
    *(char *)((int)&uStack_3c + iVar5) = "0123456789ABCDEF"[uVar4];
    iVar5 = iVar6;
  } while (uVar3 != 0);
  if ((iVar7 != 0) && (iVar6 < iVar7)) {
    uVar2 = (undefined1)local_28;
    do {
      iVar6 = iVar5 + 1;
      *(undefined1 *)((int)&uStack_3c + iVar5) = uVar2;
      iVar5 = iVar6;
    } while (iVar6 < iVar7);
  }
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    sub_08008DBE(in_r0,(ushort)(byte)(&stack0xffffffc3)[iVar6]);
  }
_08009052:
  local_2c = local_2c + 1;
  goto _08008E48;
}


/* sub_08009064 @ 0x08009064 */

void sub_08009064(byte *param_1,byte *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  
  uVar2 = *(undefined2 *)(param_1 + 10);
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    if (bVar1 == 10) {
      *(undefined2 *)(param_1 + 10) = uVar2;
      *(ushort *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1U & 0x1f;
    }
    else {
      *(ushort *)(param_1 + *(short *)(param_1 + 10) * 2 + *(short *)(param_1 + 0xc) * 0x40 + 0x24)
           = (ushort)bVar1 + (ushort)*param_1 * 0x1000 + -0x1e;
      *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + 1;
    }
    param_2 = param_2 + 1;
  }
  return;
}


/* sub_080090AE @ 0x080090AE */

void sub_080090AE(byte *param_1,short *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar2 = ((int)param_2[2] - (int)*param_2) + -2;
  uVar1 = (ushort)*param_1 << 0xc;
  iVar4 = param_2[1] + 1;
  iVar3 = *param_2 * 2 + param_2[1] * 0x40;
  *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 100;
  puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      *puVar5 = uVar1 | 0x66;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  *puVar5 = uVar1 | 0x464;
  if (iVar4 < param_2[3] + -1) {
    do {
      iVar3 = iVar4 * 0x40;
      iVar4 = iVar4 + 1;
      iVar3 = *param_2 * 2 + iVar3;
      *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 0x67;
      puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
      iVar3 = 0;
      if (0 < iVar2) {
        do {
          *puVar5 = uVar1 | 0x68;
          puVar5 = puVar5 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
      }
      *puVar5 = uVar1 | 0x467;
    } while (iVar4 < param_2[3] + -1);
  }
  iVar3 = *param_2 * 2 + iVar4 * 0x40;
  *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 0x65;
  puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      *puVar5 = uVar1 | 0x866;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  *puVar5 = uVar1 | 0x465;
  return;
}


/* sub_080091DA @ 0x080091DA */

void sub_080091DA(byte *param_1,short *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar4 = ((int)param_2[2] - (int)*param_2) + -2;
  uVar1 = (ushort)*param_1 << 0xc;
  iVar2 = param_2[1] + 1;
  iVar3 = *param_2 * 2 + param_2[1] * 0x40;
  *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 100;
  puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      *puVar5 = uVar1 | 0x66;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  *puVar5 = uVar1 | 0x464;
  if (iVar2 < param_2[3] + -1) {
    do {
      iVar3 = iVar2 * 0x40;
      iVar2 = iVar2 + 1;
      iVar3 = *param_2 * 2 + iVar3;
      *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 0x67;
      *(ushort *)(param_1 + iVar4 * 2 + iVar3 + 0x26) = uVar1 | 0x467;
    } while (iVar2 < param_2[3] + -1);
  }
  iVar3 = *param_2 * 2 + iVar2 * 0x40;
  *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 0x65;
  puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      *puVar5 = uVar1 | 0x866;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  *puVar5 = uVar1 | 0x465;
  return;
}


/* sub_080092A4 @ 0x080092A4 */

void sub_080092A4(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  sVar4 = 0;
  iVar2 = 0;
  do {
    iVar1 = 0;
    sVar3 = sVar4;
    do {
      iVar5 = iVar1 * 2;
      sVar4 = sVar3 + 1;
      iVar1 = iVar1 + 1;
      *(short *)(iVar2 * 0x40 + param_1 + iVar5 + 0x24) = sVar3;
      sVar3 = sVar4;
    } while (iVar1 < 0x1e);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  return;
}


/* sub_080092CA @ 0x080092CA */

void sub_080092CA(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)*(short *)(param_1 + 4);
  if (iVar2 < *(short *)(param_1 + 8)) {
    do {
      iVar1 = (int)*(short *)(param_1 + 2);
      if (iVar1 < *(short *)(param_1 + 6)) {
        do {
          iVar3 = iVar2 * 0x40 + param_1 + iVar1 * 2;
          iVar1 = iVar1 + 1;
          *(undefined2 *)(iVar3 + 0x24) = *(undefined2 *)(iVar3 + 100);
        } while (iVar1 < *(short *)(param_1 + 6));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(short *)(param_1 + 8));
  }
  return;
}


/* sub_0800930A @ 0x0800930A */

void sub_0800930A(byte *param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  sub_08008D14(param_1);
  param_1[0x1c] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  *(int *)(param_1 + 0x18) = (int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 4);
  return;
}


/* sub_08009328 @ 0x08009328 */

void sub_08009328(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int aiStack_20 [3];
  
  if (*(int *)(param_1 + 0x20) != 0) {
    if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
      sub_0800ACFE(0x11);
      if ((*(char **)(param_1 + 0x14) == (char *)0x0) || (**(char **)(param_1 + 0x14) == '\0')) {
        DAT_03003d14 = 0;
        DAT_03003d10 = 0;
        param_1[0x14] = 0;
        param_1[0x15] = 0;
        param_1[0x16] = 0;
        param_1[0x17] = 0;
      }
      else {
        if (param_2 == 0) {
          sub_08008D14(param_1);
        }
        else {
          __call_via_r5();
        }
        param_1[0x1c] = 0;
        *(int *)(param_1 + 0x18) = (int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 4);
        param_1[0x20] = 0;
        param_1[0x21] = 0;
        param_1[0x22] = 0;
        param_1[0x23] = 0;
      }
    }
    return;
  }
  do {
    aiStack_20[0] = 5;
    aiStack_20[1] = 0xf;
    aiStack_20[2] = 0x19;
    iVar4 = aiStack_20[DAT_03000020];
    uVar2 = (uint)DAT_03003d12;
    if ((DAT_03003d12 & 1) != 0) {
      iVar4 = (int)(char)param_1[0x1c];
    }
    iVar4 = ((uint)param_1[0x1c] - iVar4) * 0x1000000;
    param_1[0x1c] = (byte)((uint)iVar4 >> 0x18);
    if ((iVar4 >> 0x18 < 1) || ((int)(uVar2 << 0x1e) < 0)) {
      param_1[0x1c] = 0x32;
      pbVar5 = *(byte **)(param_1 + 0x14);
      bVar1 = *pbVar5;
      if (bVar1 == 10) {
        *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
        *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
        iVar4 = *(int *)(param_1 + 0x18);
        *(int *)(param_1 + 0x18) = iVar4 + -1;
        if (iVar4 + -1 == 0) {
          param_1[0x20] = 1;
          param_1[0x21] = 0;
          param_1[0x22] = 0;
          param_1[0x23] = 0;
        }
      }
      else if (bVar1 < 0xb) {
        if (bVar1 == 0) {
          param_1[0x20] = 1;
          param_1[0x21] = 0;
          param_1[0x22] = 0;
          param_1[0x23] = 0;
          return;
        }
        if (bVar1 == 9) {
          param_1[0x1c] = 0x78;
        }
        else {
_08009444:
          sub_08008DBE(param_1,(ushort)bVar1);
          if (-1 < (int)((uint)DAT_03003d12 << 0x1e)) {
            sub_0800ACFE(0x10);
          }
        }
      }
      else if (bVar1 == 0xb) {
        param_1[0x20] = 1;
        param_1[0x21] = 0;
        param_1[0x22] = 0;
        param_1[0x23] = 0;
      }
      else {
        if (bVar1 != 0x20) goto _08009444;
        iVar4 = (*(ushort *)(param_1 + 10) + 1) * 0x10000;
        *(short *)(param_1 + 10) = (short)((uint)iVar4 >> 0x10);
        if (0x20 < pbVar5[1]) {
          pbVar3 = pbVar5 + 2;
          bVar1 = pbVar5[2];
          while (0x20 < bVar1) {
            pbVar3 = pbVar3 + 1;
            bVar1 = *pbVar3;
          }
          if ((int)*(short *)(param_1 + 6) <= (int)(pbVar3 + (iVar4 >> 0x10) + (-1 - (int)pbVar5)))
          {
            *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
            *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
            iVar4 = *(int *)(param_1 + 0x18);
            *(int *)(param_1 + 0x18) = iVar4 + -1;
            if (iVar4 + -1 == 0) {
              param_1[0x20] = 1;
              param_1[0x21] = 0;
              param_1[0x22] = 0;
              param_1[0x23] = 0;
            }
          }
        }
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
    if (-1 < (int)((uint)DAT_03003d12 << 0x1e)) {
      return;
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      return;
    }
  } while( true );
}


/* sub_0800946E @ 0x0800946E */

void sub_0800946E(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = param_1[1];
  *(ushort *)(param_2 + 10) = (ushort)*param_1;
  *(ushort *)(param_2 + 0xc) = (ushort)bVar1;
  sub_08008E06(param_2,*(byte **)(param_1 + 4));
  return;
}


/* sub_08009486 @ 0x08009486 */

void sub_08009486(int *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *param_1) {
    do {
      pbVar2 = (byte *)param_1[iVar3 + 1];
      bVar1 = pbVar2[1];
      *(ushort *)(param_2 + 10) = (ushort)*pbVar2;
      *(ushort *)(param_2 + 0xc) = (ushort)bVar1;
      sub_08008E06(param_2,*(byte **)(pbVar2 + 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  return;
}


/* sub_080094B8 @ 0x080094B8 */

undefined4 sub_080094B8(int *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_03003d14;
  if ((int)(uVar1 << 0x19) < 0) {
    if (*param_2 == 0) {
      *param_2 = (char)*param_1 - 1;
    }
    else {
      *param_2 = *param_2 - 1;
    }
    return 1;
  }
  if ((-1 < (int)(uVar1 << 0x1d)) && (-1 < (int)(uVar1 << 0x18))) {
    return 0;
  }
  if (*param_1 - 1U == (uint)*param_2) {
    *param_2 = 0;
  }
  else {
    *param_2 = *param_2 + 1;
  }
  return 1;
}


/* Decompress @ 0x08009524 */

undefined8 Decompress(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  bVar3 = param_2 << 0x1b < 0;
  if (bVar3) {
    param_1 = &DAT_0202c224;
    software_interrupt(0x13);
  }
  uVar2 = (uint)bVar3;
  if (param_2 << 0x1c < 0) {
    param_1 = (undefined4 *)(&gUnknown_080116C0)[uVar2];
    uVar2 = uVar2 + 1 & 1;
    software_interrupt(0x11);
  }
  if (param_2 << 0x1d < 0) {
    param_1 = (undefined4 *)(&gUnknown_080116C0)[uVar2];
    uVar2 = uVar2 + 1 & 1;
    software_interrupt(0x14);
  }
  if (param_2 << 0x1e < 0) {
    param_1 = (undefined4 *)(&gUnknown_080116C0)[uVar2];
    uVar2 = uVar2 + 1 & 1;
    software_interrupt(0x18);
  }
  puVar1 = (undefined4 *)(param_2 << 0x1f);
  if (param_2 << 0x1f < 0) {
    param_1 = (undefined4 *)(&gUnknown_080116C0)[uVar2];
    software_interrupt(0x16);
    puVar1 = param_1;
  }
  return CONCAT44(puVar1,param_1);
}


/* sub_08009586 @ 0x08009586 */

void sub_08009586(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = Decompress((undefined4 *)param_1[1],(uint)*(byte *)(param_1 + 2));
  sub_080092A4(param_2);
  sub_0800AB3E();
  WaitForVBlank(1);
  REG_DMA3SAD = *param_1;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  sub_08009626(&REG_DMA3SAD,(int)param_3,iVar1,0x9600);
  sub_08008D8A(param_2);
  return;
}


/* sub_080095D0 @ 0x080095D0 */

void sub_080095D0(undefined4 *param_1)

{
  Decompress((undefined4 *)*param_1,(uint)*(byte *)(param_1 + 1));
  return;
}


/* sub_080095DC @ 0x080095DC */

void sub_080095DC(int param_1)

{
  Decompress(*(undefined4 **)(param_1 + 4),(uint)*(byte *)(param_1 + 8));
  return;
}


/* sub_080095F4 @ 0x080095F4 */

void sub_080095F4(int param_1)

{
  char in_NG;
  
  if (in_NG != '\0') {
    do {
    } while ((int)((uint)*(ushort *)(param_1 + 10) << 0x10) < 0);
  }
  return;
}


/* sub_080095FE @ 0x080095FE */

void sub_080095FE(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = 0x1000;
    if (param_4 < 0x1000) {
      uVar1 = param_4;
    }
    param_4 = param_4 - uVar1;
    *param_1 = param_3;
    param_1[1] = param_2;
    *(short *)(param_1 + 2) = (short)(uVar1 >> 1);
    *(undefined2 *)((int)param_1 + 10) = 0x8000;
    param_2 = param_2 + uVar1;
    param_3 = param_3 + uVar1;
  } while (param_4 != 0);
  return;
}


/* sub_08009626 @ 0x08009626 */

void sub_08009626(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = 0x1000;
    if (param_4 < 0x1000) {
      uVar1 = param_4;
    }
    param_4 = param_4 - uVar1;
    *param_1 = param_3;
    param_1[1] = param_2;
    *(short *)(param_1 + 2) = (short)(uVar1 >> 2);
    *(undefined2 *)((int)param_1 + 10) = 0x8400;
    param_2 = param_2 + uVar1;
    param_3 = param_3 + uVar1;
  } while (param_4 != 0);
  return;
}


/* sub_08009650 @ 0x08009650 */

void sub_08009650(undefined4 *param_1,int param_2,undefined2 param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = 0x1000;
    if (param_4 < 0x1000) {
      uVar1 = param_4;
    }
    DAT_030047e8 = param_3;
    *param_1 = &DAT_030047e8;
    param_4 = param_4 - uVar1;
    param_1[1] = param_2;
    *(short *)(param_1 + 2) = (short)(uVar1 >> 1);
    *(undefined2 *)((int)param_1 + 10) = 0x8100;
    param_2 = param_2 + uVar1;
  } while (param_4 != 0);
  return;
}


/* sub_08009680 @ 0x08009680 */

void sub_08009680(undefined4 *param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = 0x1000;
    if (param_4 < 0x1000) {
      uVar1 = param_4;
    }
    DAT_030047ec = param_3;
    *param_1 = &DAT_030047ec;
    param_4 = param_4 - uVar1;
    param_1[1] = param_2;
    *(short *)(param_1 + 2) = (short)(uVar1 >> 2);
    *(undefined2 *)((int)param_1 + 10) = 0x8500;
    param_2 = param_2 + uVar1;
  } while (param_4 != 0);
  return;
}


/* sub_080096B4 @ 0x080096B4 */

void sub_080096B4(void)

{
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0x10) + *DAT_03003b64));
  DAT_03003b6c = DAT_03003b6c + 1;
  return;
}


/* sub_080096CC @ 0x080096CC */

int sub_080096CC(int param_1)

{
  ushort uVar1;
  
  if ((param_1 == 0) && (param_1 = sub_0800E4DC(1), param_1 == 0)) {
    return 0;
  }
  DAT_03003b60 = 0;
  REG_WAITCNT = 0x4014;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x2000000;
  Ram040000dc = 0;
  DAT_040000de = 0x8500;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3000000;
  Ram040000dc = 0x1f80;
  DAT_040000de = 0x8500;
  sub_080098F8();
  sub_0800E4B0();
  sub_0800996E();
  sub_0800B2DE();
  sub_0800A9F6(14000);
  DAT_03003b64 = &DAT_03003b68;
  DAT_03003b8b = 0x80096b5;
  uVar1 = REG_IE;
  REG_IE = uVar1 | 1;
  return param_1;
}


/* sub_08009744 @ 0x08009744 */

void sub_08009744(int *param_1)

{
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 4) + *DAT_03003b64));
  __call_via_r1(param_1,(undefined *)(*(int *)*param_1 + *param_1));
  DAT_03003b64 = param_1;
  return;
}


/* sub_08009766 @ 0x08009766 */

void sub_08009766(void)

{
  int iVar1;
  
  do {
    __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 8) + *DAT_03003b64));
    sub_0800AB3E();
    WaitForVBlank(1);
    sub_0800A664();
    iVar1 = __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0xc) + *DAT_03003b64))
    ;
  } while (iVar1 == 0);
  return;
}


/* sub_08009798 @ 0x08009798 */

void sub_08009798(void)

{
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 4) + *DAT_03003b64));
  DAT_03003b60 = DAT_03003b60 - 1;
  DAT_03003b64 = *(int **)(&DAT_03003b70 + (uint)DAT_03003b60 * 4);
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0x14) + *DAT_03003b64));
  return;
}


/* sub_080097C8 @ 0x080097C8 */

void sub_080097C8(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = DAT_03003b64;
  uVar2 = (uint)DAT_03003b60;
  DAT_03003b60 = DAT_03003b60 + 1;
  *(int **)(&DAT_03003b70 + uVar2 * 4) = DAT_03003b64;
  iVar3 = *piVar1;
  __call_via_r1(piVar1,(undefined *)(*(int *)(iVar3 + 4) + iVar3));
  __call_via_r1(param_1,(undefined *)(*(int *)*param_1 + *param_1));
  DAT_03003b64 = param_1;
  return;
}


/* sub_080097F8 @ 0x080097F8 */

void sub_080097F8(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = DAT_03003b64;
  uVar2 = (uint)DAT_03003b60;
  DAT_03003b60 = DAT_03003b60 + 1;
  *(int **)(&DAT_03003b70 + uVar2 * 4) = DAT_03003b64;
  iVar3 = *piVar1;
  __call_via_r1(piVar1,(undefined *)(*(int *)(iVar3 + 4) + iVar3));
  __call_via_r1(param_1,(undefined *)(*(int *)*param_1 + *param_1));
  DAT_03003b64 = param_1;
  do {
    __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 8) + *DAT_03003b64));
    sub_0800AB3E();
    WaitForVBlank(1);
    sub_0800A664();
    iVar3 = __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0xc) + *DAT_03003b64))
    ;
  } while (iVar3 == 0);
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 4) + *DAT_03003b64));
  DAT_03003b60 = DAT_03003b60 - 1;
  DAT_03003b64 = (int *)*(undefined4 *)(&DAT_03003b70 + (uint)DAT_03003b60 * 4);
  return;
}


/* sub_0800988C @ 0x0800988C */

void sub_0800988C(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    (&DAT_07000006)[iVar1 * 0x10] = 0x100;
    (&DAT_07000016)[iVar1 * 0x10] = 0;
    (&DAT_0700000e)[iVar1 * 0x10] = 0;
    iVar2 = iVar1 + 1;
    (&DAT_0700001e)[iVar1 * 0x10] = 0x100;
    iVar1 = iVar2;
  } while (iVar2 < 0x20);
  iVar1 = 0;
  do {
    *(undefined2 *)(iVar1 * 8 + 0x7000000) = 0x200;
    (&DAT_07000002)[iVar1 * 4] = 0;
    iVar2 = iVar1 + 1;
    (&DAT_07000004)[iVar1 * 4] = 0;
    iVar1 = iVar2;
  } while (iVar2 < 0x80);
  return;
}


/* sub_080098C6 @ 0x080098C6 */

void sub_080098C6(void)

{
  REG_DMA3SAD = 0x202be24;
  REG_DMA3DAD = 0x7000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8400;
  return;
}


/* sub_080098DE @ 0x080098DE */

void sub_080098DE(void)

{
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x202be24;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8500;
  return;
}


/* sub_080098F8 @ 0x080098F8 */

void sub_080098F8(void)

{
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8100;
  sub_08009680(&REG_DMA3SAD,0x6000000,0,0x18000);
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x202be24;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8500;
  sub_0800988C();
  return;
}


/* sub_0800994C @ 0x0800994C */

void sub_0800994C(short *param_1,short *param_2,short param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = param_2[1];
  sVar2 = param_2[2];
  sVar3 = param_2[3];
  *param_1 = *param_2 - param_3;
  param_1[1] = sVar1 - param_3;
  param_1[2] = sVar2 + param_3;
  param_1[3] = sVar3 + param_3;
  return;
}


/* sub_0800996A @ 0x0800996A */

undefined4 sub_0800996A(undefined4 param_1)

{
  return param_1;
}


/* sub_0800996C @ 0x0800996C */

void sub_0800996C(void)

{
  return;
}


/* sub_0800996E @ 0x0800996E */

void sub_0800996E(void)

{
  REG_DMA3SAD = 0x8000138;
  REG_DMA3DAD = 0x3003bc0;
  Ram040000dc = 0x4f;
  DAT_040000de = 0x8400;
  DAT_030047ec = 0x800996d;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3003b88;
  Ram040000dc = 0xe;
  DAT_040000de = 0x8500;
  DAT_03007ffc = &DAT_03003bc0;
  REG_IE = 0x2000;
  REG_IME = 1;
  REG_DISPSTAT = 8;
  return;
}


/* WaitForVBlank @ 0x080099B6 */

/* WARNING: Removing unreachable block (ram,0x080099f4) */

void WaitForVBlank(uint param_1)

{
  undefined1 uVar1;
  
  if (((param_1 & 1) != 0) && (-1 < (int)((uint)DAT_03003b86 << 0x1f))) {
    uVar1 = REG_VCOUNT;
  }
  do {
    software_interrupt(2);
  } while( true );
}


/* sub_08009A20 @ 0x08009A20 */

void sub_08009A20(undefined4 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if ((bVar1 & 0x11) == 0) {
    if ((bVar1 & 0x44) != 0) {
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_1 + 7);
      iVar3 = param_1[8];
      *(undefined1 *)(iVar3 + 0x10) = *(undefined1 *)(param_1 + 7);
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x10;
    }
  }
  else if (*(byte *)((int)param_1 + 0x1a) == 0xff) {
    *(byte *)(param_1[8] + 0xc) = *(byte *)(param_1[8] + 0xc) & 0xfe;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xfb;
  }
  else {
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_1 + 7);
    uVar4 = *(undefined4 *)(&gUnknown_080116C8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4);
    *param_1 = uVar4;
    *(undefined1 *)((int)param_1 + 10) = 4;
    iVar3 = param_1[8];
    if ((int)((uint)bVar1 << 0x1a) < 0) {
      uVar2 = *(undefined1 *)(param_1 + 2);
      *(undefined4 *)(iVar3 + 0x2c) = uVar4;
      *(undefined1 *)(iVar3 + 0x10) = uVar2;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x17;
    }
    else {
      bVar1 = *(byte *)((int)param_1 + 0x1b);
      uVar2 = *(undefined1 *)(param_1 + 2);
      *(undefined4 *)(iVar3 + 0x2c) = uVar4;
      *(undefined **)(iVar3 + 0x24) = &gUnknown_08591E4C + (uint)bVar1 * 0xc;
      *(undefined1 *)(iVar3 + 0x10) = uVar2;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x1f;
    }
  }
  return;
}


/* sub_08009AA2 @ 0x08009AA2 */

void sub_08009AA2(undefined4 *param_1)

{
  sub_08009A20(param_1);
  DAT_03003d00 = *(undefined1 *)((int)param_1 + 0x1e);
  return;
}


/* sub_08009AB4 @ 0x08009AB4 */

void sub_08009AB4(undefined4 *param_1)

{
  sub_08009A20(param_1);
  DAT_03003cfd = DAT_03003cfe + -1;
  DAT_03003d02 = *(byte *)((int)param_1 + 0x1e) - 1;
  return;
}


/* sub_08009AD2 @ 0x08009AD2 */

void sub_08009AD2(int param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 8) - (uint)*(byte *)(param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 8) = (char)((uint)iVar1 >> 0x18);
  if (iVar1 >> 0x18 < 1) {
    *(undefined1 *)(param_1 + 8) = 0;
    *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) & 0xfc;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined1 *)(iVar1 + 0x10) = *(undefined1 *)(param_1 + 8);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  return;
}


/* sub_08009AFE @ 0x08009AFE */

void sub_08009AFE(int param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 8) = (char)((uint)iVar1 >> 0x18);
  if (0x3f < iVar1 >> 0x18) {
    *(undefined1 *)(param_1 + 8) = 0x40;
    *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) & 0xfc;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined1 *)(iVar1 + 0x10) = *(undefined1 *)(param_1 + 8);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  return;
}


/* sub_08009B2A @ 0x08009B2A */

void sub_08009B2A(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 3) = *(char *)((int)param_1 + 0x1e);
  }
  bVar1 = *(byte *)(param_1 + 3);
  if ((bVar1 & 0xf) == 0) {
    *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
    param_1[5] = 0x8009aff;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    if (*(char *)((int)param_1 + 0xb) == '\x0f') {
      sub_08009AFE((int)param_1);
    }
  }
  else {
    uVar2 = ((uint)bVar1 << 0x18) >> 0x1c;
    if (uVar2 != 0) {
      if ((~(uint)bVar1 & 0xf) == 0) {
        *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
        sub_08009AFE((int)param_1);
      }
      else if (uVar2 == 0xf) {
        *(byte *)((int)param_1 + 0xb) = bVar1 & 0xf;
        sub_08009AD2((int)param_1);
        return;
      }
      return;
    }
    *(undefined1 *)((int)param_1 + 0xb) = *(undefined1 *)(param_1 + 3);
    param_1[5] = 0x8009ad3;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    if (*(char *)((int)param_1 + 0xb) == '\x0f') {
      sub_08009AD2((int)param_1);
      return;
    }
  }
  return;
}


/* sub_08009BA6 @ 0x08009BA6 */

void sub_08009BA6(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(&gUnknown_08011BA8 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0x10;
  *param_1 = uVar2;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar2;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  return;
}


/* sub_08009BC4 @ 0x08009BC4 */

void sub_08009BC4(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    uVar1 = (uint)*(byte *)((int)param_1 + 0xd);
    uVar2 = (uVar1 << 0x18) >> 0x1c;
    if (uVar2 != 0xf) {
      if (uVar2 == 0xe) {
        uVar1 = (uint)*(ushort *)(&DAT_08011b28 + ((uVar1 << 0x1c) >> 0x1b)) * *param_1 >> 0x10;
        *param_1 = uVar1;
        uVar2 = param_1[8];
        *(uint *)(uVar2 + 0x2c) = uVar1;
        *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
        return;
      }
      param_1[5] = 0x8009ba7;
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
      return;
    }
    uVar1 = (uint)*(ushort *)(&gUnknown_08011BA8 + ((uVar1 << 0x1c) >> 0x1b)) * *param_1 >> 0x10;
    *param_1 = uVar1;
    uVar2 = param_1[8];
    *(uint *)(uVar2 + 0x2c) = uVar1;
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
  }
  return;
}


/* sub_08009C34 @ 0x08009C34 */

void sub_08009C34(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(&gUnknown_08011928 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0xe;
  *param_1 = uVar2;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar2;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  return;
}


/* sub_08009C52 @ 0x08009C52 */

void sub_08009C52(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    uVar1 = (uint)*(byte *)((int)param_1 + 0xd);
    uVar2 = (uVar1 << 0x18) >> 0x1c;
    if (uVar2 != 0xf) {
      if (uVar2 == 0xe) {
        uVar1 = (uint)*(ushort *)(&DAT_080118a8 + ((uVar1 << 0x1c) >> 0x1b)) * *param_1 >> 0xf;
        *param_1 = uVar1;
        uVar2 = param_1[8];
        *(uint *)(uVar2 + 0x2c) = uVar1;
        *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
        return;
      }
      param_1[5] = 0x8009c35;
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
      return;
    }
    uVar1 = (uint)*(ushort *)(&gUnknown_08011928 + ((uVar1 << 0x1c) >> 0x1b)) * *param_1 >> 0xe;
    *param_1 = uVar1;
    uVar2 = param_1[8];
    *(uint *)(uVar2 + 0x2c) = uVar1;
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
  }
  return;
}


/* sub_08009CC2 @ 0x08009CC2 */

void sub_08009CC2(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(&gUnknown_08011BA8 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0x10;
  *param_1 = uVar2;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar2;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  if (*param_1 < uVar1) {
    *param_1 = uVar1;
    uVar2 = param_1[8];
    *(uint *)(uVar2 + 0x2c) = uVar1;
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf4;
  }
  return;
}


/* sub_08009D00 @ 0x08009D00 */

void sub_08009D00(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(&gUnknown_08011928 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0xe;
  *param_1 = uVar2;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar2;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  if (uVar1 < *param_1) {
    *param_1 = uVar1;
    uVar2 = param_1[8];
    *(uint *)(uVar2 + 0x2c) = uVar1;
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf4;
  }
  return;
}


/* sub_08009D3E @ 0x08009D3E */

void sub_08009D3E(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0x1e);
  }
  bVar1 = *(byte *)((int)param_1 + 10);
  if (-1 < (int)((uint)bVar1 << 0x1d)) {
    return;
  }
  if ((param_1[6] & 0x11) == 0) {
    if (-1 < (int)((uint)bVar1 << 0x1c)) goto _08009D94;
  }
  else {
    if (*(byte *)((int)param_1 + 0x1a) == 0xff) goto _08009D94;
    param_1[1] = *(uint *)(&gUnknown_080116C8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4);
    *(byte *)((int)param_1 + 10) = bVar1 | 8;
  }
  if (*param_1 < param_1[1]) {
    param_1[5] = 0x8009d01;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  }
  else {
    param_1[5] = 0x8009cc3;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  }
_08009D94:
  if ((param_1[6] & 0x44) != 0) {
    *(char *)(param_1 + 2) = (char)param_1[7];
    uVar2 = param_1[8];
    *(char *)(uVar2 + 0x10) = (char)param_1[2];
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 0x10;
  }
  return;
}


/* sub_08009DB0 @ 0x08009DB0 */

void sub_08009DB0(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(byte *)((int)param_1 + 0x11) + (uint)*(byte *)((int)param_1 + 0xf) & 0x3f;
  *(char *)((int)param_1 + 0x11) = (char)uVar1;
  iVar2 = (int)((int)(char)(&gUnknown_08011DA8)[uVar1] * (uint)*(byte *)(param_1 + 4)) >> 6;
  if (iVar2 < 0) {
    uVar1 = (uint)*(ushort *)(&DAT_08011b28 + iVar2 * -2) * *param_1 >> 0x10;
  }
  else {
    uVar1 = (uint)*(ushort *)(&DAT_080118a8 + iVar2 * 2) * *param_1 >> 0xf;
  }
  iVar2 = param_1[8];
  *(uint *)(iVar2 + 0x2c) = uVar1;
  *(byte *)(iVar2 + 0xc) = *(byte *)(iVar2 + 0xc) | 2;
  return;
}


/* sub_08009DF4 @ 0x08009DF4 */

void sub_08009DF4(int *param_1)

{
  byte bVar1;
  
  sub_08009A20(param_1);
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    if ((*(byte *)(param_1 + 6) & 0x11) != 0) {
      *(undefined1 *)((int)param_1 + 0x11) = 0;
    }
    bVar1 = *(byte *)((int)param_1 + 0x1e);
    if ((bVar1 & 0xf) != 0) {
      *(char *)(param_1 + 4) = (char)((bVar1 & 0xf) << 2);
    }
    if (((uint)bVar1 << 0x18) >> 0x1c != 0) {
      *(byte *)((int)param_1 + 0xf) = bVar1 >> 4;
    }
    param_1[5] = 0x8009db1;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    sub_08009DB0(param_1);
  }
  return;
}


/* sub_08009E7A @ 0x08009E7A */

void sub_08009E7A(void)

{
  return;
}


/* sub_08009E7C @ 0x08009E7C */

void sub_08009E7C(void)

{
  return;
}


/* sub_08009E7E @ 0x08009E7E */

void sub_08009E7E(int *param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 2) - (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 2) = (char)((uint)iVar1 >> 0x18);
  if (iVar1 >> 0x18 < 1) {
    *(undefined1 *)(param_1 + 2) = 0;
    param_1[5] = 0x8009db1;
  }
  iVar1 = param_1[8];
  *(char *)(iVar1 + 0x10) = (char)param_1[2];
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  sub_08009DB0(param_1);
  return;
}


/* sub_08009EAC @ 0x08009EAC */

void sub_08009EAC(int *param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 2) + (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 2) = (char)((uint)iVar1 >> 0x18);
  if (0x3f < iVar1 >> 0x18) {
    *(undefined1 *)(param_1 + 2) = 0x40;
    param_1[5] = 0x8009db1;
  }
  iVar1 = param_1[8];
  *(char *)(iVar1 + 0x10) = (char)param_1[2];
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  sub_08009DB0(param_1);
  return;
}


/* sub_08009EDA @ 0x08009EDA */

void sub_08009EDA(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 3) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    if ((*(byte *)(param_1 + 6) & 0x11) != 0) {
      *(undefined1 *)((int)param_1 + 0x11) = 0;
    }
    bVar1 = *(byte *)(param_1 + 3);
    if ((bVar1 & 0xf) == 0) {
      *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
      param_1[5] = 0x8009ead;
      if (*(char *)((int)param_1 + 0xb) == '\x0f') {
        sub_08009AFE((int)param_1);
      }
    }
    else {
      uVar2 = ((uint)bVar1 << 0x18) >> 0x1c;
      if (uVar2 == 0) {
        *(char *)((int)param_1 + 0xb) = (char)param_1[3];
        param_1[5] = 0x8009e7f;
        if (*(char *)((int)param_1 + 0xb) == '\x0f') {
          sub_08009AD2((int)param_1);
        }
      }
      else if ((~(uint)bVar1 & 0xf) == 0) {
        *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
        sub_08009AFE((int)param_1);
        param_1[5] = 0x8009db1;
      }
      else if (uVar2 == 0xf) {
        *(byte *)((int)param_1 + 0xb) = bVar1 & 0xf;
        sub_08009AD2((int)param_1);
        param_1[5] = 0x8009db1;
      }
    }
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    sub_08009DB0(param_1);
  }
  return;
}


/* sub_08009F70 @ 0x08009F70 */

void sub_08009F70(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 3) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    iVar3 = 0;
    if ((param_1[6] & 0x44) != 0) {
      *(char *)(param_1 + 2) = (char)param_1[7];
      uVar2 = param_1[8];
      *(char *)(uVar2 + 0x10) = (char)param_1[2];
      *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 0x10;
    }
    bVar1 = (byte)param_1[3];
    if ((bVar1 & 0xf) == 0) {
      *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
      iVar3 = 1;
      if (*(char *)((int)param_1 + 0xb) == '\x0f') {
        sub_08009AFE((int)param_1);
      }
    }
    else {
      uVar2 = ((uint)bVar1 << 0x18) >> 0x1c;
      if (uVar2 == 0) {
        iVar3 = 2;
        *(char *)((int)param_1 + 0xb) = (char)param_1[3];
        if (*(char *)((int)param_1 + 0xb) == '\x0f') {
          sub_08009AD2((int)param_1);
        }
      }
      else if ((~(uint)bVar1 & 0xf) == 0) {
        *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
        sub_08009AFE((int)param_1);
      }
      else if (uVar2 == 0xf) {
        *(byte *)((int)param_1 + 0xb) = bVar1 & 0xf;
        sub_08009AD2((int)param_1);
      }
    }
    if ((param_1[6] & 0x11) == 0) {
      bVar1 = *(byte *)((int)param_1 + 10);
      if ((-1 < (int)((uint)bVar1 << 0x1c)) && (iVar3 != 0)) {
        if (iVar3 == 1) {
          param_1[5] = 0x8009aff;
          *(byte *)((int)param_1 + 10) = bVar1 | 1;
        }
        else if (iVar3 == 2) {
          param_1[5] = 0x8009ad3;
          *(byte *)((int)param_1 + 10) = bVar1 | 1;
        }
      }
    }
    else {
      if (*(byte *)((int)param_1 + 0x1a) == 0xff) {
        return;
      }
      param_1[1] = *(uint *)(&gUnknown_080116C8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4);
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 8;
    }
    if (param_1[1] <= *param_1) {
      param_1[5] = *(uint *)(&DAT_08011df4 + iVar3 * 4);
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
      return;
    }
    param_1[5] = *(uint *)(&gUnknown_08011DE8 + iVar3 * 4);
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  }
  return;
}


/* sub_0800A068 @ 0x0800A068 */

void sub_0800A068(void)

{
  return;
}


/* sub_0800A06A @ 0x0800A06A */

void sub_0800A06A(void)

{
  return;
}


/* sub_0800A06C @ 0x0800A06C */

void sub_0800A06C(undefined4 *param_1)

{
  int *piVar1;
  
  sub_08009A20(param_1);
  if ((*(byte *)(param_1 + 6) & 0x11) != 0) {
    piVar1 = (int *)param_1[8];
    *piVar1 = (uint)*(byte *)((int)param_1 + 0x1e) << 0x16;
    *(byte *)(piVar1 + 3) = *(byte *)(piVar1 + 3) & 0xfb;
  }
  return;
}


/* sub_0800A090 @ 0x0800A090 */

void sub_0800A090(void)

{
  return;
}


/* sub_0800A092 @ 0x0800A092 */

void sub_0800A092(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x12) + -1;
  *(char *)(param_1 + 0x12) = cVar1;
  if (cVar1 == '\0') {
    *(byte *)(*(int *)(param_1 + 0x20) + 0xc) = *(byte *)(*(int *)(param_1 + 0x20) + 0xc) | 5;
    *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0xe) & 0xf;
    *(undefined1 *)(param_1 + 10) = 4;
  }
  return;
}


/* sub_0800A0B6 @ 0x0800A0B6 */

void sub_0800A0B6(undefined4 *param_1)

{
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xe) = *(char *)((int)param_1 + 0x1e);
  }
  param_1[5] = 0x800a093;
  *(byte *)((int)param_1 + 0x12) = *(byte *)((int)param_1 + 0xe) & 0xf;
  *(byte *)((int)param_1 + 10) = (*(byte *)((int)param_1 + 10) & 0xfc) + 2;
  return;
}


/* sub_0800A0E0 @ 0x0800A0E0 */

void sub_0800A0E0(void)

{
  return;
}


/* sub_0800A0E2 @ 0x0800A0E2 */

void sub_0800A0E2(void)

{
  return;
}


/* sub_0800A0E4 @ 0x0800A0E4 */

void sub_0800A0E4(undefined4 *param_1)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_1 + 0x12) + -1;
  *(char *)((int)param_1 + 0x12) = cVar1;
  if (cVar1 == '\0') {
    sub_08009A20(param_1);
  }
  return;
}


/* sub_0800A0F8 @ 0x0800A0F8 */

void sub_0800A0F8(int param_1)

{
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined4 *)(param_1 + 0x14) = 0x800a0e5;
  *(byte *)(param_1 + 10) = (*(byte *)(param_1 + 10) & 0xfc) + 2;
  return;
}


/* sub_0800A10E @ 0x0800A10E */

void sub_0800A10E(undefined4 *param_1)

{
  sub_08009A20(param_1);
  sub_0800A374((uint)*(byte *)((int)param_1 + 0x1e));
  return;
}


/* sub_0800A120 @ 0x0800A120 */

void sub_0800A120(int *param_1)

{
  byte bVar1;
  
  sub_08009A20(param_1);
  if ((*(byte *)(param_1 + 6) & 0x11) != 0) {
    *(undefined1 *)((int)param_1 + 0x11) = 0;
  }
  bVar1 = *(byte *)((int)param_1 + 0x1e);
  if ((bVar1 & 0xf) != 0) {
    *(byte *)(param_1 + 4) = bVar1 & 0xf;
  }
  if (((uint)bVar1 << 0x18) >> 0x1c != 0) {
    *(byte *)((int)param_1 + 0xf) = bVar1 >> 4;
  }
  param_1[5] = 0x8009db1;
  *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  sub_08009DB0(param_1);
  return;
}


/* sub_0800A15E @ 0x0800A15E */

void sub_0800A15E(void)

{
  return;
}


/* sub_0800A160 @ 0x0800A160 */

void sub_0800A160(void)

{
  return;
}


/* sub_0800A162 @ 0x0800A162 */

void sub_0800A162(undefined4 *param_1)

{
  int iVar1;
  
  sub_08009A20(param_1);
  *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)param_1 + 0x1e);
  iVar1 = param_1[8];
  *(undefined1 *)(iVar1 + 0x11) = *(undefined1 *)((int)param_1 + 0x1e);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  return;
}


/* sub_0800A17E @ 0x0800A17E */

void sub_0800A17E(void)

{
  return;
}


/* sub_0800A180 @ 0x0800A180 */

void sub_0800A180(void)

{
  return;
}


/* sub_0800A182 @ 0x0800A182 */

void sub_0800A182(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)*(ushort *)(&gUnknown_08011928 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0xe;
  *param_1 = uVar3;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar3;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  puVar4 = param_1 + 2;
  if (*param_1 < uVar1) {
    *param_1 = uVar1;
    uVar3 = param_1[8];
    *(uint *)(uVar3 + 0x2c) = uVar1;
    *(byte *)(uVar3 + 0xc) = *(byte *)(uVar3 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf7;
    param_1[5] = 0x8009aff;
    sub_08009AFE((int)param_1);
    return;
  }
  iVar2 = ((uint)(byte)*puVar4 + (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(byte *)puVar4 = (byte)((uint)iVar2 >> 0x18);
  if (0x3f < iVar2 >> 0x18) {
    *(byte *)puVar4 = 0x40;
    param_1[5] = 0x8009cc3;
  }
  uVar1 = param_1[8];
  *(byte *)(uVar1 + 0x10) = (byte)*puVar4;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 0x10;
  return;
}


/* sub_0800A1EE @ 0x0800A1EE */

void sub_0800A1EE(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)*(ushort *)(&gUnknown_08011BA8 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0x10;
  *param_1 = uVar3;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar3;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  puVar4 = param_1 + 2;
  if (*param_1 < uVar1) {
    *param_1 = uVar1;
    uVar3 = param_1[8];
    *(uint *)(uVar3 + 0x2c) = uVar1;
    *(byte *)(uVar3 + 0xc) = *(byte *)(uVar3 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf7;
    param_1[5] = 0x8009aff;
    sub_08009AFE((int)param_1);
    return;
  }
  iVar2 = ((uint)(byte)*puVar4 + (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(byte *)puVar4 = (byte)((uint)iVar2 >> 0x18);
  if (0x3f < iVar2 >> 0x18) {
    *(byte *)puVar4 = 0x40;
    param_1[5] = 0x8009cc3;
  }
  uVar1 = param_1[8];
  *(byte *)(uVar1 + 0x10) = (byte)*puVar4;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 0x10;
  return;
}


/* sub_0800A28C @ 0x0800A28C */

void sub_0800A28C(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)*(ushort *)(&gUnknown_08011928 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0xe;
  *param_1 = uVar3;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar3;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  puVar4 = param_1 + 2;
  if (uVar1 < *param_1) {
    *param_1 = uVar1;
    uVar3 = param_1[8];
    *(uint *)(uVar3 + 0x2c) = uVar1;
    *(byte *)(uVar3 + 0xc) = *(byte *)(uVar3 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf7;
    param_1[5] = 0x8009ad3;
    sub_08009AD2((int)param_1);
    return;
  }
  iVar2 = ((uint)(byte)*puVar4 - (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(byte *)puVar4 = (byte)((uint)iVar2 >> 0x18);
  if (iVar2 >> 0x18 < 1) {
    *(byte *)puVar4 = 0;
    param_1[5] = 0x8009cc3;
  }
  uVar1 = param_1[8];
  *(byte *)(uVar1 + 0x10) = (byte)*puVar4;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 0x10;
  return;
}


/* sub_0800A2F8 @ 0x0800A2F8 */

void sub_0800A2F8(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)*(ushort *)(&gUnknown_08011BA8 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0x10;
  *param_1 = uVar3;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar3;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  puVar4 = param_1 + 2;
  if (*param_1 < uVar1) {
    *param_1 = uVar1;
    uVar3 = param_1[8];
    *(uint *)(uVar3 + 0x2c) = uVar1;
    *(byte *)(uVar3 + 0xc) = *(byte *)(uVar3 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf7;
    param_1[5] = 0x8009ad3;
    sub_08009AD2((int)param_1);
    return;
  }
  iVar2 = ((uint)(byte)*puVar4 - (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(byte *)puVar4 = (byte)((uint)iVar2 >> 0x18);
  if (iVar2 >> 0x18 < 1) {
    *(byte *)puVar4 = 0;
    param_1[5] = 0x8009cc3;
  }
  uVar1 = param_1[8];
  *(byte *)(uVar1 + 0x10) = (byte)*puVar4;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 0x10;
  return;
}


/* sub_0800A374 @ 0x0800A374 */

void sub_0800A374(uint param_1)

{
  DAT_03003d01 = (undefined1)param_1;
  DAT_03003d04 = sub_0800E640(param_1,(uint)DAT_03003d2e * 2 + (uint)(DAT_03003d2e >> 1));
  return;
}


/* sub_0800A38C @ 0x0800A38C */

void sub_0800A38C(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 10);
  if (((bVar1 & 3) != 0) && (((bVar1 & 3) != 1 || ((int)((uint)bVar1 << 0x1d) < 0)))) {
    __call_via_r1(param_1,*(undefined **)(param_1 + 0x14));
  }
  return;
}


/* sub_0800A3A6 @ 0x0800A3A6 */

void sub_0800A3A6(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = *(byte *)((int)param_1 + 10) >> 2;
  *(byte *)((int)param_1 + 10) = bVar1 << 2;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    iVar3 = param_1[8];
    if (*(int *)(iVar3 + 0x2c) != *param_1) {
      *(int *)(iVar3 + 0x2c) = *param_1;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 2;
    }
  }
  if (*(byte *)(param_1 + 6) != 0) {
    uVar2 = (uint)*(byte *)((int)param_1 + 0x1d);
    if ((*(byte *)(param_1 + 6) & 0x88) == 0) {
      uVar2 = 0;
    }
    __call_via_r1(param_1,(&gUnknown_08166734)[uVar2]);
  }
  return;
}


/* sub_0800A3E6 @ 0x0800A3E6 */

void sub_0800A3E6(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  DAT_03003cfd = DAT_03003cfd + 1;
  if (DAT_03003cfe <= DAT_03003cfd) {
    iVar4 = (DAT_03003d02 + 1) * 0x10000;
    DAT_03003d02 = (ushort)((uint)iVar4 >> 0x10);
    if (*(char *)(DAT_03003d08[1] + (iVar4 >> 0x10)) == -1) {
      DAT_03003d02 = 0;
    }
    pbVar3 = *(byte **)(*DAT_03003d08 +
                       (uint)*(byte *)(DAT_03003d08[1] + (int)(short)DAT_03003d02) * 4);
    DAT_03003cfd = 0;
    DAT_03003cfe = *pbVar3;
    DAT_03003d0c = pbVar3 + 1;
  }
  iVar4 = 0;
  do {
    iVar5 = iVar4 * 0x24;
    iVar4 = iVar4 + 1;
    (&DAT_0203ee3c)[iVar5] = 0;
  } while (iVar4 < 0xf);
  while( true ) {
    pbVar3 = DAT_03003d0c;
    bVar1 = *DAT_03003d0c;
    DAT_03003d0c = DAT_03003d0c + 1;
    if (bVar1 == 0) break;
    iVar4 = ((bVar1 & 0xf) - 1) * 0x24;
    uVar2 = (uint)(bVar1 >> 4);
    if (uVar2 == 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = pbVar3 + 2;
      (&DAT_0203ee3d)[iVar4] = bVar1;
      (&DAT_0203ee3c)[iVar4] = bVar1;
    }
    else if (uVar2 == 1) {
      (&DAT_0203ee3c)[iVar4] = (&DAT_0203ee3d)[iVar4];
    }
    else {
      (&DAT_0203ee3c)[iVar4] = *(undefined1 *)((int)&DAT_08142386 + uVar2);
    }
    uVar2 = (uint)(byte)(&DAT_0203ee3c)[iVar4];
    if ((int)(uVar2 << 0x1f) < 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee3e) = bVar1;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee3f) = bVar1;
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee40) = bVar1;
    }
    if ((int)(uVar2 << 0x1c) < 0) {
      pbVar3 = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee41) = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 2;
      *(byte *)(iVar4 + 0x203ee42) = *pbVar3;
    }
  }
  return;
}


/* sub_0800A4C6 @ 0x0800A4C6 */

void sub_0800A4C6(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  DAT_03003cff = DAT_03003cff + -1;
  if (DAT_03003cff == '\0') {
    sub_0800A3E6();
    iVar3 = 0;
    do {
      sub_0800A3A6((int *)(&DAT_0203ee24 + iVar3 * 0x24));
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
    DAT_03003cff = DAT_03003d00;
  }
  else {
    iVar3 = 0;
    do {
      iVar2 = iVar3 * 0x24;
      bVar1 = (&DAT_0203ee2e)[iVar2];
      if (((bVar1 & 3) != 0) && (((bVar1 & 3) != 1 || ((int)((uint)bVar1 << 0x1d) < 0)))) {
        __call_via_r1(&DAT_0203ee24 + iVar2,*(undefined **)(iVar2 + 0x203ee38));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
  }
  iVar3 = 0;
  do {
    sub_0800A748((undefined4 *)(&DAT_0203f040 + iVar3 * 0x40));
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xf);
  return;
}


/* sub_0800A530 @ 0x0800A530 */

void sub_0800A530(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    sub_0800A80E((int *)(&DAT_0203f040 + iVar1 * 0x40),param_1,param_2);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  return;
}


/* sub_0800A54E @ 0x0800A54E */

void sub_0800A54E(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_03003cfc == '\x01') {
    iVar3 = (int)DAT_03003d30;
    puVar2 = &DAT_03003f90;
    while (uVar4 = (uint)DAT_03003d06, (int)uVar4 < iVar3) {
      if (uVar4 != 0) {
        iVar1 = 0;
        do {
          sub_0800A80E((int *)(&DAT_0203f040 + iVar1 * 0x40),(int)puVar2,uVar4);
          iVar1 = iVar1 + 1;
        } while (iVar1 < 0xf);
        puVar2 = puVar2 + (uint)DAT_03003d06 * 4;
        iVar3 = iVar3 - (uint)DAT_03003d06;
      }
      sub_0800A4C6();
      DAT_03003d06 = DAT_03003d04;
    }
    iVar1 = 0;
    do {
      sub_0800A80E((int *)(&DAT_0203f040 + iVar1 * 0x40),(int)puVar2,iVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xf);
    DAT_03003d06 = DAT_03003d06 - (short)iVar3;
  }
  return;
}


/* sub_0800A5B8 @ 0x0800A5B8 */

void sub_0800A5B8(void)

{
  DAT_03003cfc = 0;
  return;
}


/* sub_0800A5C0 @ 0x0800A5C0 */

void sub_0800A5C0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = iVar1 * 0x24;
    (&DAT_0203ee2e)[iVar3] = 0;
    (&DAT_0203ee43)[iVar3] = 0;
    (&DAT_0203ee3c)[iVar3] = 0;
    (&DAT_0203ee44)[iVar1 * 9] = &DAT_0203f040 + iVar1 * 0x40;
    (&DAT_0203f04c)[iVar1 * 0x40] = 0;
    iVar2 = iVar1 + 1;
    (&DAT_0203f068)[iVar1 * 0x10] = &DAT_0203ee24 + iVar3;
    iVar1 = iVar2;
  } while (iVar2 < 0xf);
  return;
}


/* sub_0800A5F6 @ 0x0800A5F6 */

void sub_0800A5F6(int param_1)

{
  DAT_03003cfe = 1;
  DAT_03003cff = 1;
  DAT_03003cfd = 0;
  DAT_03003d00 = *(undefined1 *)(param_1 + 9);
  DAT_03003d02 = 0xffff;
  DAT_03003d08 = param_1;
  sub_0800A5C0();
  DAT_03003d01 = *(byte *)(param_1 + 8);
  DAT_03003d04 = sub_0800E640((uint)DAT_03003d01,(uint)DAT_03003d2e * 2 + (uint)(DAT_03003d2e >> 1))
  ;
  DAT_03003cfc = 1;
  return;
}


/* sub_0800A62C @ 0x0800A62C */

void sub_0800A62C(int param_1)

{
  if (DAT_03003d08 != param_1) {
    sub_0800A5F6(param_1);
  }
  return;
}


/* sub_0800A664 @ 0x0800A664 */

void sub_0800A664(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = REG_KEYINPUT;
  uVar2 = ~uVar1;
  DAT_03003d14 = uVar2 & (uVar2 ^ DAT_03003d12);
  DAT_03003d16 = DAT_03003d12 & (uVar2 ^ DAT_03003d12);
  DAT_03003d12 = uVar2;
  if (DAT_03003d14 != 0) {
    uVar4 = (uint)DAT_03003d10;
    uVar3 = uVar4 + 1;
    DAT_03003d10 = (byte)uVar3;
    (&DAT_03003d1c)[uVar4] = (char)DAT_03003d14;
    if (7 < (uVar3 & 0xff)) {
      DAT_03003d10 = 0;
    }
  }
  if (((uVar1 & 0x30b) == 0) && (DAT_03003d18 != 0)) {
    sub_0800DBF8();
  }
  return;
}


/* sub_0800A6B2 @ 0x0800A6B2 */

undefined4 sub_0800A6B2(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (DAT_03003d14 == 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = (uint)DAT_03003d10;
    do {
      uVar2 = uVar2 - 1;
      if ((int)uVar2 < 0) {
        uVar2 = 7;
      }
      param_1 = param_1 + -1;
      if (*(ushort *)(param_2 + param_1 * 2) != (ushort)(byte)(&DAT_03003d1c)[uVar2]) {
        return 0;
      }
    } while (param_1 != 0);
    uVar1 = 1;
  }
  return uVar1;
}


/* sub_0800A6F4 @ 0x0800A6F4 */

int sub_0800A6F4(void)

{
  DAT_03003d24 = DAT_03003d24 + 0x2cbbc71 ^ DAT_03003d28;
  DAT_03003d28 = (DAT_03003d28 >> 0x1d | DAT_03003d28 << 3) + 0x632d80f ^ DAT_03003d24;
  return DAT_03003d24 * DAT_03003d28;
}


/* sub_0800A714 @ 0x0800A714 */

uint sub_0800A714(int param_1)

{
  uint uVar1;
  
  uVar1 = sub_0800A6F4();
  return param_1 * (uVar1 >> 0x10) >> 0x10;
}


/* sub_0800A724 @ 0x0800A724 */

undefined4 sub_0800A724(uint param_1)

{
  uint uVar1;
  
  uVar1 = sub_0800A6F4();
  if (uVar1 >> 0x10 < param_1) {
    return 1;
  }
  return 0;
}


/* sub_0800A748 @ 0x0800A748 */

void sub_0800A748(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = (uint)*(byte *)(param_1 + 3);
  if ((int)(uVar2 << 0x1f) < 0) {
    if ((int)(uVar2 * 0x8000000) < 0) {
      uVar6 = (int)((uint)*(byte *)(param_1 + 4) * (uint)*(byte *)(param_1 + 0xc) *
                   (0x40 - *(char *)((int)param_1 + 0x11))) >> 10;
      uVar3 = (int)((uint)*(byte *)(param_1 + 4) * (uint)*(byte *)(param_1 + 0xc) *
                   (*(char *)((int)param_1 + 0x11) + 0x40)) >> 10;
      uVar7 = uVar6 & 0xff;
      uVar4 = uVar3 & 0xff;
      *(char *)((int)param_1 + 0xe) = (char)uVar6;
      uVar1 = (undefined1)uVar3;
      *(undefined1 *)((int)param_1 + 0xf) = uVar1;
      if (uVar7 == 0 && uVar4 == 0) {
        param_1[5] = 0x8008aa5;
      }
      else if (uVar7 == 0) {
        *(undefined1 *)((int)param_1 + 0xe) = uVar1;
        *(undefined1 *)((int)param_1 + 0xf) = 1;
        param_1[5] = &DAT_03003d44;
      }
      else if (uVar4 == 0) {
        param_1[5] = &DAT_03003d44;
      }
      else if (uVar7 == uVar4) {
        param_1[5] = &DAT_03003dec;
      }
      else {
        param_1[5] = &DAT_03003ebc;
      }
    }
    if ((int)(uVar2 << 0x1c) < 0) {
      puVar5 = (undefined4 *)param_1[9];
      param_1[2] = *puVar5;
      param_1[7] = (uint)*(ushort *)((int)puVar5 + 6) << 0xe;
      param_1[8] = (uint)*(ushort *)(puVar5 + 2) << 0xe;
      *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)((int)puVar5 + 10);
      *(undefined1 *)((int)param_1 + 0xd) = *(undefined1 *)(puVar5 + 1);
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      *param_1 = 0;
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfb;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      uVar2 = DAT_03003d3c * ((uint)*(ushort *)((int)param_1 + 0x12) * param_1[0xb] >> 0xe) + 0x7ff
              >> 0xc;
      param_1[6] = uVar2;
      if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1d) < 0) {
        param_1[1] = -uVar2;
      }
      else {
        param_1[1] = uVar2;
      }
    }
    *(undefined1 *)(param_1 + 3) = 1;
  }
  return;
}


/* sub_0800A80E @ 0x0800A80E */

void sub_0800A80E(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((int)((uint)*(byte *)(param_1 + 3) << 0x1f) < 0) {
    if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1f) < 0) {
      if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1e) < 0) {
        do {
          iVar1 = *param_1;
          iVar5 = iVar1 + param_3 * param_1[1];
          if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1d) < 0) {
            if (param_1[7] <= iVar5) {
              __call_via_r3();
              *param_1 = iVar5;
              return;
            }
            iVar1 = (iVar1 + param_1[6] + -1) - param_1[7];
            software_interrupt(6);
            iVar5 = param_1[7];
            iVar3 = *param_1;
            iVar2 = param_1[6];
            __call_via_r3();
            *param_1 = (iVar5 * 2 - iVar3) - iVar1 * iVar2;
            *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfb;
            param_1[1] = param_1[6];
          }
          else {
            if (iVar5 < param_1[8]) {
              __call_via_r3();
              *param_1 = iVar5;
              return;
            }
            iVar1 = (param_1[8] + param_1[6] + -1) - iVar1;
            software_interrupt(6);
            iVar5 = param_1[8];
            iVar3 = *param_1;
            iVar2 = param_1[6];
            __call_via_r3();
            *param_1 = (iVar5 * 2 - iVar3) - iVar1 * iVar2;
            *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 4;
            param_1[1] = -param_1[6];
          }
          param_3 = param_3 - iVar1;
        } while (0 < param_3);
      }
      else {
        do {
          iVar1 = *param_1 + param_3 * param_1[1];
          if (iVar1 < param_1[8]) {
            __call_via_r3();
            *param_1 = iVar1;
            return;
          }
          iVar1 = (param_1[8] + param_1[6] + -1) - *param_1;
          software_interrupt(6);
          iVar5 = param_1[6];
          iVar2 = *param_1;
          iVar3 = param_1[8];
          iVar4 = param_1[7];
          __call_via_r3();
          param_3 = param_3 - iVar1;
          *param_1 = (iVar2 + iVar1 * iVar5) - (iVar3 - iVar4);
        } while (0 < param_3);
      }
    }
    else {
      iVar1 = *param_1 + param_3 * param_1[1];
      if (iVar1 < param_1[8]) {
        __call_via_r3();
        *param_1 = iVar1;
      }
      else {
        software_interrupt(6);
        __call_via_r3();
        *(undefined1 *)(param_1 + 3) = 0;
        iVar1 = param_1[10];
        if (iVar1 != 0) {
          *(byte *)(iVar1 + 10) = *(byte *)(iVar1 + 10) & 0xfb;
        }
      }
    }
  }
  return;
}


/* sub_0800A98C @ 0x0800A98C */

void sub_0800A98C(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = 0x4000;
  *(undefined1 *)(param_1 + 0x10) = param_3;
  *(undefined1 *)(param_1 + 0x11) = param_4;
  *(undefined1 *)(param_1 + 0xc) = 0x1f;
  return;
}


/* sub_0800A9A2 @ 0x0800A9A2 */

void sub_0800A9A2(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  DAT_03003d2d = param_1;
  do {
    iVar2 = iVar1 * 0x40;
    (&DAT_0203f430)[iVar2] = param_1;
    iVar1 = iVar1 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] | 0x10;
  } while (iVar1 < 0x10);
  return;
}


/* sub_0800A9CC @ 0x0800A9CC */

void sub_0800A9CC(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  DAT_03003d2c = param_1;
  do {
    iVar2 = iVar1 * 0x40;
    (&DAT_0203f070)[iVar2] = param_1;
    iVar1 = iVar1 + 1;
    (&DAT_0203f04c)[iVar2] = (&DAT_0203f04c)[iVar2] | 0x10;
  } while (iVar1 < 0xf);
  return;
}


/* sub_0800A9F6 @ 0x0800A9F6 */

void sub_0800A9F6(ushort param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_03003d34 = 0;
  DAT_03003d38 = 0;
  DAT_03003d40 = 0;
  DAT_03003d2e = param_1;
  iVar2 = sub_0800E640((uint)param_1,param_1 + 0x3ffffff);
  iVar3 = 0;
  DAT_03003d3c = iVar2;
  do {
    iVar4 = iVar3 + 1;
    (&DAT_0203f068)[iVar3 * 0x10] = &DAT_0203ee24 + iVar3 * 0x24;
    iVar3 = iVar4;
  } while (iVar4 < 0xf);
  REG_SOUNDCNT_X = 0x80;
  REG_SOUNDCNT_H = 0x9a0e;
  REG_DMA1SAD = 0x203f800;
  REG_DMA1DAD = 0x40000a0;
  Ram040000c4 = 4;
  DAT_040000c6 = 0xb660;
  REG_DMA2SAD = 0x203fe00;
  DAT_040000cc = 0x40000a4;
  Ram040000d0 = 4;
  DAT_040000d2 = 0xf660;
  REG_SOUNDCNT_L = 0;
  REG_DMA3SAD = 0x8008814;
  REG_DMA3DAD = 0x3003d44;
  Ram040000dc = 0x2a;
  DAT_040000de = 0x8400;
  REG_DMA3SAD = 0x80088bc;
  REG_DMA3DAD = 0x3003dec;
  Ram040000dc = 0x34;
  DAT_040000de = 0x8400;
  REG_DMA3SAD = 0x800898c;
  REG_DMA3DAD = 0x3003ebc;
  Ram040000dc = 0x35;
  DAT_040000de = 0x8400;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x203ee24;
  Ram040000dc = 0x477;
  DAT_040000de = 0x8500;
  DAT_03003bb3 = 0x8008aa7;
  uVar1 = REG_IE;
  REG_IE = uVar1 | 0x400;
  REG_TM0CNT = (short)((uint)-(iVar2 + 3) >> 2);
  DAT_04000102 = 0x80;
  iVar3 = 0;
  DAT_03003d2c = 4;
  do {
    iVar2 = iVar3 * 0x40;
    (&DAT_0203f070)[iVar2] = 4;
    iVar3 = iVar3 + 1;
    (&DAT_0203f04c)[iVar2] = (&DAT_0203f04c)[iVar2] | 0x10;
  } while (iVar3 < 0xf);
  DAT_03003d2d = 8;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x40;
    (&DAT_0203f430)[iVar2] = 8;
    iVar3 = iVar3 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] | 0x10;
  } while (iVar3 < 0x10);
  return;
}


/* sub_0800AB00 @ 0x0800AB00 */

void sub_0800AB00(void)

{
  WaitForVBlank(0x400);
  DAT_04000102 = 0;
  return;
}


/* sub_0800AB12 @ 0x0800AB12 */

void sub_0800AB12(void)

{
  DAT_04000102 = 0x80;
  return;
}


/* sub_0800AB1A @ 0x0800AB1A */

void sub_0800AB1A(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE;
  REG_IE = uVar1 | 0x400;
  WaitForVBlank(0x400);
  DAT_04000102 = 0;
  DAT_040000c6 = 0;
  DAT_040000d2 = 0;
  REG_SOUNDCNT_X = 0;
  return;
}


/* sub_0800AB3E @ 0x0800AB3E */

void sub_0800AB3E(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = DAT_03003d38;
  DAT_03003d40 = 1;
  uVar3 = DAT_03003d34 - DAT_03003d38 & 0x3ff;
  if (0x40 < uVar3) {
    DAT_03003d38 = DAT_03003d34;
    iVar4 = 0;
    do {
      sub_0800A748((undefined4 *)(&DAT_0203f400 + iVar4 * 0x40));
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    do {
      DAT_03003d30 = (short)uVar3;
      if (0x100 < DAT_03003d30) {
        DAT_03003d30 = 0x100;
      }
      sub_0800A54E();
      iVar4 = 0;
      do {
        sub_0800A80E((int *)(&DAT_0203f400 + iVar4 * 0x40),0x3003f90,(int)DAT_03003d30);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x10);
      iVar4 = (int)DAT_03003d30;
      iVar1 = uVar2 + iVar4;
      if (iVar1 < 0x401) {
        if ((int)uVar2 < 0x200) {
          if (iVar1 < 0x201) {
            sub_08008A60((int)(&DAT_0203f800 + uVar2),(int)(&DAT_0203fe00 + uVar2),
                         (int *)&DAT_03003f90,iVar4);
          }
          else {
            sub_08008A60((int)(&DAT_0203f800 + uVar2),(int)(&DAT_0203fe00 + uVar2),
                         (int *)&DAT_03003f90,0x200 - uVar2);
            sub_08008A60(0x203fa00,0x203fc00,(int *)(&DAT_03003f90 + (0x200 - uVar2) * 4),
                         iVar1 + -0x200);
          }
        }
        else {
          sub_08008A60((int)(&DAT_0203f800 + uVar2),(int)(&DAT_0203fa00 + uVar2),
                       (int *)&DAT_03003f90,iVar4);
        }
      }
      else {
        sub_08008A60((int)(&DAT_0203f800 + uVar2),(int)(&DAT_0203fa00 + uVar2),(int *)&DAT_03003f90,
                     0x400 - uVar2);
        sub_08008A60(0x203f800,0x203fe00,(int *)(&DAT_03003f90 + (0x400 - uVar2) * 4),iVar1 + -0x400
                    );
      }
      uVar2 = uVar2 + (int)DAT_03003d30 & 0x3ff;
      uVar3 = uVar3 - (int)DAT_03003d30;
    } while (uVar3 != 0);
  }
  DAT_03003d40 = 0;
  return;
}


/* sub_0800ACB2 @ 0x0800ACB2 */

void sub_0800ACB2(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 * 0x40;
    iVar1 = iVar1 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] & 0xfe;
  } while (iVar1 < 0x10);
  return;
}


/* sub_0800ACCA @ 0x0800ACCA */

undefined * sub_0800ACCA(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    if (((&DAT_0203f40c)[iVar1 * 0x40] & 1) == 0) {
      iVar2 = iVar1 * 0x40;
      (&DAT_0203f424)[iVar1 * 0x10] = param_1;
      (&DAT_0203f42c)[iVar1 * 0x10] = 0x4000;
      (&DAT_0203f410)[iVar2] = param_2;
      (&DAT_0203f411)[iVar2] = param_3;
      (&DAT_0203f40c)[iVar2] = 0x1f;
      return &DAT_0203f400 + iVar2;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return (undefined *)0x0;
}


/* sub_0800ACFE @ 0x0800ACFE */

undefined * sub_0800ACFE(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    if (((&DAT_0203f40c)[iVar1 * 0x40] & 1) == 0) {
      iVar2 = iVar1 * 0x40;
      (&DAT_0203f42c)[iVar1 * 0x10] = 0x4000;
      (&DAT_0203f424)[iVar1 * 0x10] = &gUnknown_085C0B0C + param_1 * 0xc;
      (&DAT_0203f410)[iVar2] = 0x40;
      (&DAT_0203f411)[iVar2] = 0;
      (&DAT_0203f40c)[iVar2] = 0x1f;
      return &DAT_0203f400 + iVar2;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return (undefined *)0x0;
}


/* sub_0800AD3A @ 0x0800AD3A */

int sub_0800AD3A(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (((&DAT_0203f40c)[iVar2 * 0x40] & 1) != 0) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return iVar1;
}


/* sub_0800AD54 @ 0x0800AD54 */

void sub_0800AD54(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  REG_DMA3SAD = 0x203f400;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8400;
  iVar1 = 0;
  do {
    iVar2 = iVar1 * 0x40;
    iVar1 = iVar1 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] & 0xfe;
  } while (iVar1 < 0x10);
  return;
}


/* sub_0800AD7C @ 0x0800AD7C */

void sub_0800AD7C(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = DAT_03003d2d;
  iVar2 = 0;
  do {
    iVar3 = iVar2 * 0x40 + param_1;
    *(undefined1 *)(iVar3 + 0x30) = uVar1;
    iVar2 = iVar2 + 1;
    *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x10;
  } while (iVar2 < 0x10);
  REG_DMA3SAD = param_1;
  REG_DMA3DAD = 0x203f400;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8400;
  return;
}


