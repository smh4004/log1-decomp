/* sub_0800F9AC  (original: 0x0800F9AC-0x0800FE0C in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: equal, equal-r0dead, mem@03000000.
 */
#include "ghidra_types.h"
extern int sub_08006F1A();
extern int sub_0800F404();
extern int sub_0800F420();
extern int sub_0800F3F0();
extern int sub_0800F3E4();
extern int sub_0800F358();


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
  unsigned int __frame[20];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_50 (*(undefined4 *)((char *)__frame + 0x0))
#define asStack_4c ((short *)((char *)__frame + 0x4))
#define asStack_44 ((short *)((char *)__frame + 0xc))
#define local_3c (*(short *)((char *)__frame + 0x14))
#define local_3a (*(short *)((char *)__frame + 0x16))
#define local_38 (*(undefined4 *)((char *)__frame + 0x18))
#define local_34 (*(undefined4 *)((char *)__frame + 0x1c))
#define local_30 (*(int *)((char *)__frame + 0x20))
#define local_2c (*(int *)((char *)__frame + 0x24))
#define iStack_28 (*(int *)((char *)__frame + 0x28))
#define iStack_24 (*(int *)((char *)__frame + 0x2c))
#define local_20 (*(int *)((char *)__frame + 0x30))
#define local_1c (*(int *)((char *)__frame + 0x34))
#define iStack_18 (*(int *)((char *)__frame + 0x38))
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

