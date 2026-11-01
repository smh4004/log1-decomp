/* sub_08004B16  (original: 0x08004B16-0x08004B40 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_08004E98();
extern short volatile DAT_030007b2;
extern undefined4 volatile DAT_03000864;


void sub_08004B16(int param_1)

{
  sub_0800ACFE(6);
  sub_08004E98(&DAT_03000864,"Your speed increases!");
  DAT_030007b2 = DAT_030007b2 + (ushort)*(byte *)(param_1 + 4);
  return;
}

