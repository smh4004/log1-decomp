/* sub_08009328  (original: 0x08009328-0x0800946E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 39% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int __call_via_r5();
extern int sub_08008DBE();
extern int sub_08008D14();
extern ushort volatile DAT_03003d14;
extern undefined1 volatile DAT_03003d10;
extern byte volatile DAT_03000020;
extern ushort volatile DAT_03003d12;


void sub_08009328(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define aiStack_20 ((int *)((char *)__frame + 0x0))
  if (*(int *)(param_1 + 0x20) != 0) {
    if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
      sub_0800ACFE(0x11);
      if ((*(char **)(param_1 + 0x14) == (char *)0x0) || (**(char **)(param_1 + 0x14) == '\0')) {
        DAT_03003d14 = 0;
        DAT_03003d10 = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      else {
        if (param_2 == 0) {
          sub_08008D14(param_1);
        }
        else {
          __call_via_r5();
        }
        *(undefined1 *)(param_1 + 0x1c) = 0;
        *(int *)(param_1 + 0x18) = (int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 4);
        *(undefined4 *)(param_1 + 0x20) = 0;
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
      iVar4 = (int)*(char *)(param_1 + 0x1c);
    }
    iVar4 = ((uint)*(byte *)(param_1 + 0x1c) - iVar4) * 0x1000000;
    *(char *)(param_1 + 0x1c) = (char)((uint)iVar4 >> 0x18);
    if ((iVar4 >> 0x18 < 1) || ((int)(uVar2 << 0x1e) < 0)) {
      *(undefined1 *)(param_1 + 0x1c) = 0x32;
      pbVar5 = *(byte **)(param_1 + 0x14);
      bVar1 = *pbVar5;
      if (bVar1 == 10) {
        *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
        *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
        iVar4 = *(int *)(param_1 + 0x18) + -1;
        *(int *)(param_1 + 0x18) = iVar4;
        if (iVar4 == 0) {
          *(undefined4 *)(param_1 + 0x20) = 1;
        }
      }
      else if (bVar1 < 0xb) {
        if (bVar1 == 0) {
          *(undefined4 *)(param_1 + 0x20) = 1;
          return;
        }
        if (bVar1 == 9) {
          *(undefined1 *)(param_1 + 0x1c) = 0x78;
        }
        else {
_08009444:
          sub_08008DBE(param_1);
          if (-1 < (int)((uint)DAT_03003d12 << 0x1e)) {
            sub_0800ACFE(0x10);
          }
        }
      }
      else if (bVar1 == 0xb) {
        *(undefined4 *)(param_1 + 0x20) = 1;
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
            iVar4 = *(int *)(param_1 + 0x18) + -1;
            *(int *)(param_1 + 0x18) = iVar4;
            if (iVar4 == 0) {
              *(undefined4 *)(param_1 + 0x20) = 1;
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

