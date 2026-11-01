/* sub_08005CA8  (original: 0x08005CA8-0x08005CD6 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern uint volatile DAT_0300098c;
extern uint volatile DAT_03000990;


int sub_08005CA8(int param_1)

{
  DAT_0300098c = DAT_0300098c + 0x2cbbc71 ^ DAT_03000990;
  DAT_03000990 = (DAT_03000990 >> 0x1d | DAT_03000990 << 3) + 0x632d80f ^ DAT_0300098c;
  return (int)((DAT_03000990 * DAT_0300098c & 0xffff) * (param_1 + 1)) >> 0x10;
}

