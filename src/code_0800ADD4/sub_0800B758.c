/* sub_0800B758  (original: 0x0800B758-0x0800B778 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern short volatile DAT_03000608;
extern short volatile DAT_0300060a;

/* sub_0800B758(obj): stores obj's position (+0x20/+0x22) minus the camera position (u16 pair at 0x03000608) as one
   word at obj+0; returns 1. Hand-written: its `push {r3, r4}` (a scratch slot) made the pipeline treat it as
   variadic; it isn't. */
int sub_0800B758(undefined4 *param_1)
{
  unsigned short x = *(unsigned short *)((char *)param_1 + 0x20) - (unsigned short)DAT_03000608;
  unsigned short y = *(unsigned short *)((char *)param_1 + 0x22) - (unsigned short)DAT_0300060a;
  *param_1 = (uint)x | ((uint)y << 16);
  return 1;
}
