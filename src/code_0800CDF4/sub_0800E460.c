/* sub_0800E460  (original: 0x0800E460-0x0800E49E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E408();
extern int sub_0800E32C();

/* Ghidra's text, except the end: this library function returns with GCC's `pop {r1}; bx r1` (or r3), which Ghidra
   misread as a jump table. The value it "passed" to the jump is the return value in r0. */
undefined4 sub_0800E460(undefined2 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
    param_3 = sub_0800E32C(param_1,param_2);
    param_3 = param_3 & 0xffff;
    if (param_3 == 0) {
      param_3 = sub_0800E408(param_1,param_2);
      param_3 = param_3 & 0xffff;
      if (param_3 == 0) break;
    }
  }
  return param_3;
}
