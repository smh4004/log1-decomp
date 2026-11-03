/* sub_080053F0  (original: 0x080053F0-0x08005478 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 96% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08004D34();
extern int __call_via_r1();
extern int volatile DAT_0300087c;
extern undefined1 volatile DAT_03000038;
extern undefined4 volatile DAT_03000880;
extern undefined4 volatile gUnknown_085439E0;


void sub_080053F0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  DAT_0300087c = 0;
  uVar6 = 0;
  do {
    iVar5 = (&gUnknown_085439E0)[uVar6];
    iVar4 = 0;
    if (0 < *(int *)(iVar5 + 4)) {
      do {
        piVar3 = *(int **)(*(int *)(iVar5 + 8) + iVar4 * 4);
        __call_via_r1(piVar3,*(undefined **)(*piVar3 + 8));
        if ((*(int *)*piVar3 != 0) &&
           (iVar2 = __call_via_r1(piVar3,(undefined *)((int *)*piVar3)[1]), iVar2 != 0)) {
          puVar1 = &DAT_03000880 + DAT_0300087c;
          DAT_0300087c = DAT_0300087c + 1;
          *puVar1 = piVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar5 + 4));
    }
    if (((&DAT_03000038)[(int)uVar6 >> 3] & (byte)(1 << (uVar6 & 7))) != 0) {
      sub_08004D34(iVar5);
    }
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0x4b);
  return;
}

