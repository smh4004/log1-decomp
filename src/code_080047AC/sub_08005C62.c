/* sub_08005C62  (original: 0x08005C62-0x08005C7A in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 91% of instructions covered.
 */
#include "ghidra_types.h"
extern int volatile DAT_03000988;
extern int volatile DAT_03000984;
extern undefined volatile DAT_080114b8;


int sub_08005C62(void)

{
  if (*(int *)(&DAT_080114b8 + DAT_03000988 * 0x10) == 0) {
    return 0;
  }
  return *(int *)(&DAT_080114b8 + DAT_03000988 * 0x10) - DAT_03000984;
}

