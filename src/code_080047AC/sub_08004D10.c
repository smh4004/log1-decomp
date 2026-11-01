/* sub_08004D10  (original: 0x08004D10-0x08004D34 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_08004D10(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x10) + iVar2 * 4);
      __call_via_r1(piVar1,*(undefined4 *)(*piVar1 + 4));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xc));
  }
  return;
}

