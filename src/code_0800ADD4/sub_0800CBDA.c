/* sub_0800CBDA  (original: 0x0800CBDA-0x0800CBF6 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int volatile DAT_0300462c;
extern int volatile DAT_03004630;
extern undefined4 volatile DAT_03004628;


undefined4 sub_0800CBDA(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  DAT_0300462c = DAT_0300462c + 1;
  if (DAT_0300462c * 0x10000000 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = __call_via_r1(param_1,*(undefined4 *)(DAT_03004630 + 0xc),&DAT_03004628,param_4,param_4)
    ;
  }
  return uVar1;
}

