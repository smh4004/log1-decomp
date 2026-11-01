/* sub_0800CFB6  (original: 0x0800CFB6-0x0800CFD2 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_080097F8();
extern undefined volatile _0800F1E0;


undefined4 sub_0800CFB6(int param_1)

{
  unsigned int __frame[4];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_10 (*(undefined * *)((char *)__frame + 0x0))
#define local_c (*(uint *)((char *)__frame + 0x4))
#define local_8 (*(undefined4 *)((char *)__frame + 0x8))
  local_8 = *(undefined4 *)(param_1 + 4);
  local_c = (uint)*(ushort *)(param_1 + 8);
  local_10 = &_0800F1E0;
  sub_080097F8(&local_10);
  return 1;
}

