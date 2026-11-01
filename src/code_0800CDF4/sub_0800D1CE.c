/* sub_0800D1CE  (original: 0x0800D1CE-0x0800D1E6 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080028C4();
extern int sub_08004E98();
extern undefined4 volatile DAT_03000864;
extern undefined * volatile gUnknown_085C2FB8;


void sub_0800D1CE(undefined4 param_1,int param_2)

{
  sub_08004E98(&DAT_03000864,(&gUnknown_085C2FB8)[param_2]);
  sub_080028C4(param_1);
  return;
}

