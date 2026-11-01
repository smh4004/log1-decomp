/* sub_0800EAC8  (original: 0x0800EAC8-0x0800EB0C in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_0800EAC8(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_2 + -4);
  piVar1 = (int *)param_1[1];
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 < piVar3))) {
    param_1 = piVar2;
    piVar1 = (int *)piVar2[1];
  }
  if ((int *)(*param_1 + (int)param_1) == piVar3) {
    *param_1 = *param_1 + *piVar3;
    piVar3 = param_1;
  }
  else {
    param_1[1] = (int)piVar3;
  }
  if ((int *)(*piVar3 + (int)piVar3) == piVar2) {
    piVar3[1] = piVar2[1];
    *piVar3 = *piVar3 + *piVar2;
  }
  else {
    piVar3[1] = (int)piVar2;
  }
  return;
}

