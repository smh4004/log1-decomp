/* sub_08009744  (original: 0x08009744-0x08009766 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int * volatile DAT_03003b64;


void sub_08009744(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_03003b64 + 4);
  __call_via_r1(DAT_03003b64,iVar1 + *DAT_03003b64,iVar1,param_4,param_4);
  __call_via_r1(param_1,*(int *)*param_1 + *param_1);
  DAT_03003b64 = param_1;
  return;
}

