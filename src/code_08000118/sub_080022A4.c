/* sub_080022A4  (original: 0x080022A4-0x080022BA in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern short volatile DAT_03000608;
extern short volatile DAT_0300060c;
extern short volatile DAT_0300060a;
extern short volatile DAT_0300060e;
#define _DAT_03000608 (*(undefined4 volatile *)0x03000608)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080022A4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  _DAT_03000608 = *param_1;
  uVar1 = _DAT_03000608;
  DAT_0300060c = DAT_03000608 + 0xf0;
  DAT_0300060a = (short)((uint)_DAT_03000608 >> 0x10);
  DAT_0300060e = DAT_0300060a + 0xa0;
  _DAT_03000608 = uVar1;
  return;
}

