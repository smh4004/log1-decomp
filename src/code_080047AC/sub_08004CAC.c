/* sub_08004CAC  (original: 0x08004CAC-0x08004CDA in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 90% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();


undefined4 sub_08004CAC(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 8) + iVar3 * 4);
      iVar2 = __call_via_r1(piVar1,*(undefined4 *)(*piVar1 + 4));
      if (iVar2 != 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return 0;
}

