/* sub_0800DF3C  (original: 0x0800DF3C-0x0800DF5E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080026F8();
extern int sub_08002134();
extern int sub_08002328();


int sub_0800DF3C(int param_1)

{
  int iVar1;
  unsigned int __frame[4];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_10 ((short *)((char *)__frame + 0x0))
  sub_080026F8();
  sub_08002328((undefined4 *)asStack_10,*(int *)(param_1 + 4));
  iVar1 = sub_08002134(asStack_10);
  return 1 - iVar1;
}

