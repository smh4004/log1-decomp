/* sub_0800CFD2  (original: 0x0800CFD2-0x0800CFEE in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_080097F8();
extern undefined volatile _0800F238;


undefined4 sub_0800CFD2(void)

{
  unsigned int __frame[259];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_40c ((undefined * *)((char *)__frame + 0x0))
  local_40c[0] = &_0800F238;
  sub_080097F8(local_40c);
  return 1;
}

