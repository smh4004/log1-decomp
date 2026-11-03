/* sub_0800930A  (original: 0x0800930A-0x08009328 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D14();


void sub_0800930A(byte *param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  sub_08008D14(param_1);
  param_1[0x1c] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  *(int *)(param_1 + 0x18) = (int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 4);
  return;
}

