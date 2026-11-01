/* sub_0800DF3C  (original: 0x0800DF3C-0x0800DF5E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002134();
extern int sub_080026F8();
extern int sub_08002328();


int sub_0800DF3C(int param_1)

{
  int iVar1;
  unsigned int __frame[4];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_10 ((undefined1 *)((char *)__frame + 0x0))
  sub_080026F8();
  sub_08002328(auStack_10,*(undefined4 *)(param_1 + 4));
  iVar1 = sub_08002134(auStack_10);
  return 1 - iVar1;
}

