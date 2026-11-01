/* sub_0800F9AC  (original: 0x0800F9AC-0x0800FE0C in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800F3F0();
extern int sub_0800F3E4();
extern int sub_0800F420();
extern int sub_0800F358();
extern int sub_0800F404();
extern int sub_08006F1A();


void sub_0800F9AC(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  unsigned int __frame[20];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_50 (*(undefined4 *)((char *)__frame + 0x0))
#define auStack_4c ((undefined1 *)((char *)__frame + 0x4))
#define auStack_44 ((undefined1 *)((char *)__frame + 0xc))
#define local_3c (*(short *)((char *)__frame + 0x14))
#define local_3a (*(short *)((char *)__frame + 0x16))
#define local_38 (*(int *)((char *)__frame + 0x18))
#define local_34 (*(int *)((char *)__frame + 0x1c))
#define local_30 (*(int *)((char *)__frame + 0x20))
#define local_2c (*(int *)((char *)__frame + 0x24))
#define iStack_28 (*(int *)((char *)__frame + 0x28))
#define iStack_24 (*(int *)((char *)__frame + 0x2c))
#define local_20 (*(int *)((char *)__frame + 0x30))
#define local_1c (*(int *)((char *)__frame + 0x34))
#define iStack_18 (*(int *)((char *)__frame + 0x38))
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar5 = *(int *)(param_1 + 0x78);
    iVar6 = *(int *)(param_1 + 0x7c);
    iVar2 = *(int *)(param_2 + 0x78) - iVar5;
    local_2c = iVar2 * iVar2;
    iVar1 = *(int *)(param_2 + 0x7c) - iVar6;
    local_30 = iVar1 * iVar1;
    local_34 = 1;
    if (iVar5 < *(int *)(param_2 + 0x78)) {
      local_34 = -1;
    }
    local_38 = 1;
    if (iVar6 < *(int *)(param_2 + 0x7c)) {
      local_38 = -1;
    }
    iVar3 = (int)*(short *)(param_1 + 0x48);
    iVar7 = param_1 + 0x28;
    local_1c = param_1;
    iStack_18 = param_2;
    if (iVar3 * iVar3 <= local_2c + local_30) {
      local_3c = (short)iVar5 - (short)iVar2;
      local_3a = (short)iVar6 - (short)iVar1;
      local_50 = sub_0800F404(&local_3c,3);
      sub_0800F420(auStack_4c,iVar7,&local_50);
      sub_0800F3F0(auStack_44,auStack_4c);
      iVar1 = sub_0800F358(auStack_44,0);
      if ((iVar1 != 0) && (iVar1 = sub_08006F1A(local_1c,&local_3c,1), iVar1 != 0)) {
        return;
      }
    }
    local_20 = iVar3 >> 1;
    sub_0800F3E4(&local_3c,local_34 * local_20 + iVar5,iVar6);
    local_50 = sub_0800F404(&local_3c,3);
    sub_0800F420(auStack_4c,iVar7,&local_50);
    sub_0800F3F0(auStack_44,auStack_4c);
    iVar1 = sub_0800F358(auStack_44,0);
    if ((iVar1 == 0) || (iVar1 = sub_08006F1A(local_1c,&local_3c,1), iVar1 == 0)) {
      sub_0800F3E4(&local_3c,iVar5,local_38 * local_20 + iVar6);
      local_50 = sub_0800F404(&local_3c,3);
      sub_0800F420(auStack_4c,iVar7,&local_50);
      sub_0800F3F0(auStack_44,auStack_4c);
      iVar1 = sub_0800F358(auStack_44,0);
      if ((iVar1 == 0) || (iVar1 = sub_08006F1A(local_1c,&local_3c,1), iVar1 == 0)) {
        sub_0800F3E4(&local_3c,iVar5,iVar6 + local_38);
        local_50 = sub_0800F404(&local_3c,3);
        sub_0800F420(auStack_4c,iVar7,&local_50);
        sub_0800F3F0(auStack_44,auStack_4c);
        iVar2 = sub_0800F358(auStack_44,0);
        iVar1 = local_1c;
        psVar4 = (short *)(local_1c + 0x80);
        if (iVar2 == 0) {
          sub_0800F3E4(&local_3c,iVar5 + local_34,iVar6);
          local_50 = sub_0800F404(&local_3c,3);
          sub_0800F420(auStack_4c,iVar7,&local_50);
          sub_0800F3F0(auStack_44,auStack_4c);
          iVar2 = sub_0800F358(auStack_44,0);
          if (iVar2 == 0) {
            if (local_2c < local_30) {
              iStack_24 = local_20 + 1;
              sub_0800F3E4(&local_3c,iVar5 - local_34 * iStack_24,iVar6);
              local_50 = sub_0800F404(&local_3c,3);
              sub_0800F420(auStack_4c,iVar7,&local_50);
              sub_0800F3F0(auStack_44,auStack_4c);
              iVar2 = sub_0800F358(auStack_44,0);
              if ((iVar2 == 0) || (iVar2 = sub_08006F1A(local_1c,&local_3c,1), iVar2 == 0)) {
                sub_0800F3E4(&local_3c,iVar5,iVar6 - local_38 * iStack_24);
                local_50 = sub_0800F404(&local_3c,3);
                sub_0800F420(auStack_4c,iVar7,&local_50);
                sub_0800F3F0(auStack_44,auStack_4c);
                iVar2 = sub_0800F358(auStack_44,0);
                if ((iVar2 == 0) || (iVar2 = sub_08006F1A(local_1c,&local_3c,1), iVar2 == 0)) {
                  sub_0800F3E4(&local_3c,iVar5 - local_34,iVar6);
                  local_50 = sub_0800F404(&local_3c,3);
                  sub_0800F420(auStack_4c,iVar7,&local_50);
                  sub_0800F3F0(auStack_44,auStack_4c);
                  iVar2 = sub_0800F358(auStack_44,0);
                  if (iVar2 == 0) {
                    sub_0800F3E4(&local_3c,iVar5,iVar6 - local_38);
                    local_50 = sub_0800F404(&local_3c,3);
                    sub_0800F420(auStack_4c,iVar7,&local_50);
                    sub_0800F3F0(auStack_44,auStack_4c);
                    iVar2 = sub_0800F358(auStack_44,0);
                    if (iVar2 != 0) {
                      *psVar4 = local_3c;
                      *(short *)(iVar1 + 0x82) = local_3a;
                      *(short *)(iVar1 + 0xb0) = local_3c;
                      *(short *)(iVar1 + 0xb2) = local_3a;
                      *(undefined4 *)(iVar1 + 0xac) = 1;
                      *(undefined4 *)(iVar1 + 0xa8) = 0;
                    }
                  }
                  else {
                    *psVar4 = local_3c;
                    *(short *)(iVar1 + 0x82) = local_3a;
                    *(short *)(iVar1 + 0xb0) = local_3c;
                    *(short *)(iVar1 + 0xb2) = local_3a;
                    *(undefined4 *)(iVar1 + 0xac) = 1;
                    *(undefined4 *)(iVar1 + 0xa8) = 0;
                  }
                }
              }
            }
            else {
              iStack_28 = local_20 + 1;
              sub_0800F3E4(&local_3c,iVar5,iVar6 - local_38 * iStack_28);
              local_50 = sub_0800F404(&local_3c,3);
              sub_0800F420(auStack_4c,iVar7,&local_50);
              sub_0800F3F0(auStack_44,auStack_4c);
              iVar2 = sub_0800F358(auStack_44,0);
              if ((iVar2 == 0) || (iVar2 = sub_08006F1A(local_1c,&local_3c,1), iVar2 == 0)) {
                sub_0800F3E4(&local_3c,iVar5 - local_34 * iStack_28,iVar6);
                local_50 = sub_0800F404(&local_3c,3);
                sub_0800F420(auStack_4c,iVar7,&local_50);
                sub_0800F3F0(auStack_44,auStack_4c);
                iVar2 = sub_0800F358(auStack_44,0);
                if ((iVar2 == 0) || (iVar2 = sub_08006F1A(local_1c,&local_3c,1), iVar2 == 0)) {
                  sub_0800F3E4(&local_3c,iVar5,iVar6 - local_38);
                  local_50 = sub_0800F404(&local_3c,3);
                  sub_0800F420(auStack_4c,iVar7,&local_50);
                  sub_0800F3F0(auStack_44,auStack_4c);
                  iVar2 = sub_0800F358(auStack_44,0);
                  if (iVar2 == 0) {
                    sub_0800F3E4(&local_3c,iVar5 - local_34,iVar6);
                    local_50 = sub_0800F404(&local_3c,3);
                    sub_0800F420(auStack_4c,iVar7,&local_50);
                    sub_0800F3F0(auStack_44,auStack_4c);
                    iVar2 = sub_0800F358(auStack_44,0);
                    if (iVar2 != 0) {
                      *psVar4 = local_3c;
                      *(short *)(iVar1 + 0x82) = local_3a;
                      *(short *)(iVar1 + 0xb0) = local_3c;
                      *(short *)(iVar1 + 0xb2) = local_3a;
                      *(undefined4 *)(iVar1 + 0xac) = 1;
                      *(undefined4 *)(iVar1 + 0xa8) = 0;
                    }
                  }
                  else {
                    *psVar4 = local_3c;
                    *(short *)(iVar1 + 0x82) = local_3a;
                    *(short *)(iVar1 + 0xb0) = local_3c;
                    *(short *)(iVar1 + 0xb2) = local_3a;
                    *(undefined4 *)(iVar1 + 0xac) = 1;
                    *(undefined4 *)(iVar1 + 0xa8) = 0;
                  }
                }
              }
            }
          }
          else {
            *psVar4 = local_3c;
            *(short *)(iVar1 + 0x82) = local_3a;
            *(short *)(iVar1 + 0xb0) = local_3c;
            *(short *)(iVar1 + 0xb2) = local_3a;
            *(undefined4 *)(iVar1 + 0xac) = 1;
            *(undefined4 *)(iVar1 + 0xa8) = 0;
          }
        }
        else {
          *psVar4 = local_3c;
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

