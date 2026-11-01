/* sub_0800E064  (original: 0x0800E064-0x0800E078 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080097F8();
extern undefined volatile _0800F2D4;


void sub_0800E064(void)

{
  unsigned int __frame[2];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_8 ((undefined * *)((char *)__frame + 0x0))
  local_8[0] = &_0800F2D4;
  sub_080097F8(local_8);
  return;
}

