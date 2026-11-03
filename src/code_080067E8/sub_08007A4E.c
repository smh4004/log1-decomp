/* sub_08007A4E  (original: 0x08007A4E-0x08007F4C in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: mem@02000000, r0.
 */
#include "ghidra_types.h"
extern int sub_0800F570();
extern int sub_0800F588();
extern int sub_0800786A();
extern int sub_0800F628();
extern int sub_080079E4();
extern undefined4 volatile DAT_03000c20;
extern undefined4 volatile DAT_03000c24;
extern ushort volatile DAT_030047fc;
extern undefined4 volatile DAT_03004800;
extern int volatile DAT_03004804;
extern undefined4 volatile DAT_03004808;
extern undefined4 volatile DAT_0300480c;
extern undefined volatile DAT_03000c28;
extern undefined volatile DAT_03000c2c;
extern undefined volatile DAT_03000c30;
extern undefined volatile DAT_03000c34;
extern undefined volatile DAT_03000c38;
extern undefined4 volatile DAT_03000c3c;
extern undefined4 volatile DAT_03000c4c;


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
  unsigned int __frame[34];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define uStack_88 (*(undefined4 *)((char *)__frame + 0x0))
#define iStack_7c (*(int *)((char *)__frame + 0xc))
#define sStack_78 (*(short *)((char *)__frame + 0x10))
#define sStack_76 (*(short *)((char *)__frame + 0x12))
#define sStack_74 (*(short *)((char *)__frame + 0x14))
#define iStack_70 (*(int *)((char *)__frame + 0x18))
#define iStack_6c (*(int *)((char *)__frame + 0x1c))
#define iStack_68 (*(int *)((char *)__frame + 0x20))
#define asStack_64 ((short *)((char *)__frame + 0x24))
#define iStack_54 (*(int *)((char *)__frame + 0x34))
#define local_50 (*(int *)((char *)__frame + 0x38))
#define iStack_4c (*(int *)((char *)__frame + 0x3c))
#define iStack_48 (*(int *)((char *)__frame + 0x40))
#define iStack_44 (*(int *)((char *)__frame + 0x44))
#define iStack_40 (*(int *)((char *)__frame + 0x48))
#define iStack_3c (*(int *)((char *)__frame + 0x4c))
#define iStack_38 (*(int *)((char *)__frame + 0x50))
#define puStack_34 (*(undefined4 * *)((char *)__frame + 0x54))
#define iStack_30 (*(int *)((char *)__frame + 0x58))
#define uStack_2c (*(undefined4 *)((char *)__frame + 0x5c))
#define local_28 (*(undefined4 * *)((char *)__frame + 0x60))
#define psStack_24 (*(short * *)((char *)__frame + 0x64))
#define psStack_20 (*(short * *)((char *)__frame + 0x68))
#define local_1c (*(int *)((char *)__frame + 0x6c))
#define iStack_18 (*(int *)((char *)__frame + 0x70))
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
        *(short *)(iVar2 + 0xb2) = (*(undefined2 *)((char *)&DAT_030047fc + 2));
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
        uStack_88 = CONCAT22((*(undefined2 *)((char *)&DAT_030047fc + 2)) << 3,(short)DAT_030047fc << 3);
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

