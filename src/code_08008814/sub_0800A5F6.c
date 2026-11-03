/* sub_0800A5F6  (original: 0x0800A5F6-0x0800A62C in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800E640();
extern int sub_0800A5C0();
extern byte volatile DAT_03003cfe;
extern byte volatile DAT_03003cff;
extern byte volatile DAT_03003cfd;
extern int volatile DAT_03003d08;
extern byte volatile DAT_03003d00;
extern ushort volatile DAT_03003d02;
extern byte volatile DAT_03003d01;
extern ushort volatile DAT_03003d2e;
extern ushort volatile DAT_03003d04;
extern byte volatile DAT_03003cfc;


void sub_0800A5F6(int param_1)

{
  DAT_03003cfe = 1;
  DAT_03003cff = 1;
  DAT_03003cfd = 0;
  DAT_03003d00 = *(undefined1 *)(param_1 + 9);
  DAT_03003d02 = 0xffff;
  DAT_03003d08 = param_1;
  sub_0800A5C0();
  DAT_03003d01 = *(byte *)(param_1 + 8);
  DAT_03003d04 = sub_0800E640((uint)DAT_03003d01,(uint)DAT_03003d2e * 2 + (uint)(DAT_03003d2e >> 1))
  ;
  DAT_03003cfc = 1;
  return;
}

