/* sub_080061B0  (original: 0x080061B0-0x080061D0 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_080051D0();
extern int sub_080060A0();


undefined4 sub_080061B0(int param_1)

{
  unsigned int __frame[3];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_c ((undefined1 *)((char *)__frame + 0x0))
  local_c[0] = *(undefined1 *)(param_1 + 0xe);
  sub_080051D0(*(undefined1 *)(param_1 + 0xd),local_c);
  sub_080060A0(param_1);
  return 1;
}

