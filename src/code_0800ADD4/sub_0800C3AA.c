/* sub_0800C3AA  (original: 0x0800C3AA-0x0800C42E in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined volatile gUnknown_080120E4;


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
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(undefined4 *)((char *)__frame + 0x0))
#define local_14 (*(undefined4 *)((char *)__frame + 0x4))
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

