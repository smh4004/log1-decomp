/* sub_0800F420  (original: 0x0800F420-0x0800F44E in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"

/* sub_0800F420(rect, box, pos): rect = { box[0]+pos.x, box[1]+pos.y, box[0]+box[2]+pos.x, box[1]+box[3]+pos.y }
   (box: 4 unsigned bytes, pos: two shorts, rect: 4 halfwords); r0 is left as rect. Hand-written: its
   `push {r3-r7}` made the pipeline treat it as variadic; it isn't. */
short *sub_0800F420(short *param_1, byte *param_2, short *param_3)
{
  int px = param_3[0], py = param_3[1];
  param_1[0] = param_2[0] + px;
  param_1[1] = param_2[1] + py;
  param_1[2] = param_2[0] + param_2[2] + px;
  param_1[3] = param_2[1] + param_2[3] + py;
  return param_1;
}
