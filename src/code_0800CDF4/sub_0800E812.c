/* sub_0800E812  (original: 0x0800E812-0x0800E86A in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E8EE();
extern int sub_0800E880();
extern int sub_0800E95C();
extern int sub_0800E8E4();
extern int sub_0800E98C();
extern int sub_0800E7C4();

/* Heap (ADS library): Ghidra's text with the stack slot written by sub_0800E98C(size, &slot) declared as a plain local
   (Ghidra seeded it with the r3 the prologue pushes only for alignment: in_r3), the constant arguments the
   assembly passes (sub_0800E8EE(0), sub_0800E880(9, 0)), and the result it returns in r0 (its last call's). */
undefined4 sub_0800E812(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(undefined4 * *)((char *)__frame + 0x0))
  undefined4 r0;
  
  iVar1 = sub_0800E8EE(0);
  if (param_2 < param_1 + iVar1) {
    iVar2 = sub_0800E98C(iVar1,(int)&local_18);
    if (iVar2 == 0) {
      sub_0800E880(9,0);
    }
    if (local_18 != (undefined4 *)param_2) {
      param_1 = (uint)local_18;
    }
    param_2 = (int)local_18 + iVar2;
  }
  iVar2 = sub_0800E7C4();
  *(uint *)(iVar2 + 8) = param_1;
  piVar3 = (int *)(param_1 + iVar1);
  r0 = sub_0800E8E4((undefined4 *)param_1);
  if ((int *)param_2 != piVar3) {
    r0 = sub_0800E95C(*(int **)(iVar2 + 8),piVar3,param_2 - (int)piVar3);
  }
  return r0;
}
