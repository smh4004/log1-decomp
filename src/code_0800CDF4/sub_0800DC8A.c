/* sub_0800DC8A  (original: 0x0800DC8A-0x0800DCB8 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080097F8();
extern int __call_via_r3();
extern undefined volatile _0800F274;


void sub_0800DC8A(int param_1,int *param_2)

{
  int iVar1;
  unsigned int __frame[3];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_c (*(undefined * *)((char *)__frame + 0x0))
  iVar1 = __call_via_r3();
  *(undefined1 *)(iVar1 + 0x13) = *(undefined1 *)(param_1 + 5);
  local_c = &_0800F274;
  sub_080097F8((int *)&local_c);
  return;
}

