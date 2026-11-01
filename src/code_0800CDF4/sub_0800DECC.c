/* sub_0800DECC  (original: 0x0800DECC-0x0800DEF2 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800930A();
extern int sub_0800DCF0();
extern undefined2 volatile DAT_02029d96;
extern undefined2 volatile DAT_02029d98;
extern undefined2 volatile DAT_02029d9a;
extern undefined2 volatile DAT_02029d9c;
extern undefined1 volatile DAT_02029d94;


void sub_0800DECC(int param_1)

{
  sub_0800DCF0();
  DAT_02029d96 = 3;
  DAT_02029d98 = 4;
  DAT_02029d9a = 0x1b;
  DAT_02029d9c = 8;
  sub_0800930A(&DAT_02029d94,*(undefined4 *)(param_1 + 4));
  return;
}

