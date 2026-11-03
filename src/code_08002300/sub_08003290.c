/* sub_08003290  (original: 0x08003290-0x080032A2 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern char volatile DAT_030007ad;


undefined4 sub_08003290(void)

{
  if (DAT_030007ad == '\0') {
    return 0;
  }
  DAT_030007ad = DAT_030007ad + -1;
  return 1;
}

