/* sub_080017B6  (original: 0x080017B6-0x080017E6 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_0800174A();
extern int sub_080090AE();
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile gUnknown_0800FF98;


void sub_080017B6(int param_1)

{
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(0x202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_0800FF98);
  sub_08008D8A(0x202addc);
  *(undefined1 *)(param_1 + 4) = 0;
  sub_0800174A(param_1);
  return;
}

