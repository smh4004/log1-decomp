/* sub_08001B5C  (original: 0x08001B5C-0x08001B8E in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 4/4 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08000A32();
extern int sub_08008D14();
extern int sub_080090AE();
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_08010030;


void sub_08001B5C(int param_1)

{
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(0x202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,(short *)&DAT_08010030);
  sub_08008D8A(0x202addc);
  sub_08000A32(5,*(byte *)(param_1 + 4) + 0xd);
  return;
}

