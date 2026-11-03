/* sub_0800DCD4  (original: 0x0800DCD4-0x0800DCF0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080060A0();
extern int sub_0800C42E();
extern undefined volatile gUnknown_0815A778;


undefined4 sub_0800DCD4(int param_1)

{
  sub_080060A0(param_1);
  sub_0800C42E((int *)(&gUnknown_0815A778 + (uint)*(byte *)(param_1 + 0xd) * 8));
  return 0;
}

