/* sub_08000E5E  (original: 0x08000E5E-0x08000E7A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern ushort volatile REG_BG0HOFS;
extern ushort volatile REG_BG0VOFS;
extern ushort volatile REG_BG1HOFS;
extern ushort volatile REG_BG1VOFS;
extern ushort volatile REG_BG2HOFS;
extern ushort volatile REG_BG2VOFS;
extern ushort volatile REG_BG3HOFS;
extern ushort volatile REG_BG3VOFS;


void sub_08000E5E(void)

{
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  return;
}

