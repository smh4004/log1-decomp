/* sub_08002556  (original: 0x08002556-0x08002666 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 98% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080098DE();
extern int __call_via_r1();
extern int __call_via_r2();
extern undefined2 volatile DAT_0300079c;
extern undefined2 volatile DAT_0300079e;
extern undefined2 volatile DAT_03000794;
extern undefined2 volatile DAT_03000796;
extern undefined * volatile DAT_03000798;
extern int volatile DAT_03000610;
extern undefined volatile DAT_0200b024;
extern undefined4 volatile DAT_03000614;


void sub_08002556(undefined2 param_1,undefined2 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  unsigned int __frame[104];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_1a0 (*(int *)((char *)__frame + 0x0))
#define local_198 (*(int *)((char *)__frame + 0x8))
#define local_194 ((int *)((char *)__frame + 0xc))
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

