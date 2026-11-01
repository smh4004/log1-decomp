/* sub_08009AB4  (original: 0x08009AB4-0x08009AD2 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08009A20();
extern char volatile DAT_03003cfe;
extern char volatile DAT_03003cfd;
extern short volatile DAT_03003d02;


void sub_08009AB4(int param_1)

{
  sub_08009A20();
  DAT_03003cfd = DAT_03003cfe + -1;
  DAT_03003d02 = *(byte *)(param_1 + 0x1e) - 1;
  return;
}

