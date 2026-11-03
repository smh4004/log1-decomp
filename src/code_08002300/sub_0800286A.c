/* sub_0800286A  (original: 0x0800286A-0x08002896 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: cand-error, mem@02000000.
 */
#include "ghidra_types.h"
extern int __call_via_r3();
extern int volatile DAT_03000610;


uint sub_0800286A(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (iVar2 = DAT_03000610 + -1; -1 < iVar2; iVar2 = iVar2 + -1) {
    uVar1 = __call_via_r3();
    uVar3 = uVar3 | uVar1;
  }
  return uVar3;
}

