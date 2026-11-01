/* sub_0800283C  (original: 0x0800283C-0x0800286A in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 95% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r3();
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_03000614;


undefined4 sub_0800283C(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_03000610 + -1;
  while( true ) {
    if (iVar2 < 0) {
      return 0;
    }
    iVar1 = __call_via_r3((&DAT_03000614)[iVar2],param_1,param_2,
                          *(undefined4 *)((&DAT_03000614)[iVar2] + 0x38),param_4);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + -1;
  }
  return 1;
}

