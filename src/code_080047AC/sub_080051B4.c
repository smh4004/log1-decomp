/* sub_080051B4  (original: 0x080051B4-0x080051D0 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D14();
extern int sub_080090AE();
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0300086c;
extern undefined volatile DAT_03000874;


void sub_080051B4(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_080090AE(&DAT_02029d94,&DAT_0300086c);
  sub_080090AE(&DAT_02029d94,&DAT_03000874);
  return;
}

