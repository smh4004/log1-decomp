/* sub_0800C398  (original: 0x0800C398-0x0800C3AA in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800FE0C();


undefined4 sub_0800C398(int param_1,undefined4 param_2)

{
  int iVar1;
  unsigned int __frame[2];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_8 ((undefined4 *)((char *)__frame + 0x0))
  auStack_8[0] = param_2;
  iVar1 = sub_0800FE0C(param_1 + 4,auStack_8);
  return *(undefined4 *)(iVar1 + 4);
}

