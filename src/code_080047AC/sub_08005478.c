/* sub_08005478  (original: 0x08005478-0x080054AE in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 96% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r3();
extern int volatile DAT_0300087c;
extern undefined4 volatile DAT_03000880;


undefined4 sub_08005478(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_0300087c) {
    do {
      iVar1 = __call_via_r3((int *)(&DAT_03000880)[iVar2],param_1,param_2,
                            *(undefined4 *)(*(int *)(&DAT_03000880)[iVar2] + 0xc),param_4);
      if (iVar1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0300087c);
  }
  return 0;
}

