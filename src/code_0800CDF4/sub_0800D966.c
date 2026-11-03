/* sub_0800D966  (original: 0x0800D966-0x0800D97E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern ushort volatile DAT_03000608;
extern ushort volatile DAT_0300060a;
extern ushort volatile REG_BG1HOFS;
extern ushort volatile REG_BG1VOFS;
extern ushort volatile REG_BG2HOFS;
extern ushort volatile REG_BG2VOFS;
extern ushort volatile REG_BG3HOFS;
extern ushort volatile REG_BG3VOFS;


void sub_0800D966(void)

{
  REG_BG1HOFS = DAT_03000608;
  REG_BG1VOFS = DAT_0300060a;
  REG_BG2HOFS = DAT_03000608;
  REG_BG2VOFS = DAT_0300060a;
  REG_BG3HOFS = DAT_03000608;
  REG_BG3VOFS = DAT_0300060a;
  return;
}

