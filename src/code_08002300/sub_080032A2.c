/* sub_080032A2  (original: 0x080032A2-0x080032B8 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern byte volatile DAT_030007ad;
extern byte volatile DAT_030007ac;


void sub_080032A2(char param_1)

{
  DAT_030007ad = DAT_030007ad + param_1;
  if (DAT_030007ac < DAT_030007ad) {
    DAT_030007ad = DAT_030007ac;
  }
  return;
}

