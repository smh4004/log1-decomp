/* sub_08003B74  (original: 0x08003B74-0x08003BA4 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_080090AE();
extern int sub_08000A32();
extern int sub_08008D14();
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile gUnknown_08010F84;


void sub_08003B74(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_08008D8A(0x202a5b8);
  sub_08008D14(&DAT_0202addc);
  sub_080090AE(&DAT_0202addc,(short *)&gUnknown_08010F84);
  sub_08008D8A(0x202addc);
  sub_08000A32(2,0xb);
  return;
}

