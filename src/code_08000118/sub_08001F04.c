/* sub_08001F04  (original: 0x08001F04-0x08001F2A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08008D14();
extern int sub_0800946E();
extern uint volatile DAT_03003b6c;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile gUnknown_0801082C;


void sub_08001F04(void)

{
  sub_08008D14(&DAT_02029d94);
  if ((DAT_03003b6c & 0x3f) < 0x28) {
    sub_0800946E(&gUnknown_0801082C,&DAT_02029d94);
  }
  sub_08008D8A(0x2029d94);
  return;
}

