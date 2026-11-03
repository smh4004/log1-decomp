/* sub_08001A9E  (original: 0x08001A9E-0x08001AC4 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 6/6 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_08000A58();
extern int sub_0800946E();
extern int sub_08009486();
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_08010054;
extern undefined volatile gUnknown_08010038;


void sub_08001A9E(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_08000A58();
  sub_0800946E(&gUnknown_08010038,&DAT_02029d94);
  sub_08009486((int *)&DAT_08010054,&DAT_02029d94);
  sub_08008D8A(0x2029d94);
  return;
}

