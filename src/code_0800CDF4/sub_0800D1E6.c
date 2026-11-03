/* sub_0800D1E6  (original: 0x0800D1E6-0x0800D20A in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_08004E98();
extern int sub_080028C4();
extern undefined1 volatile DAT_0300004e;
extern undefined * volatile gUnknown_085C2FB8;


void sub_0800D1E6(int param_1,int param_2)

{
  (&DAT_0300004e)[param_2] = (&DAT_0300004e)[param_2] + '\x01';
  sub_08004E98(0x3000864,(int)(&gUnknown_085C2FB8)[param_2]);
  sub_080028C4(param_1);
  return;
}

