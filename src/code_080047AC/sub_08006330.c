/* sub_08006330  (original: 0x08006330-0x0800636C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800245A();
extern undefined * volatile gUnknown_08011648;


void sub_08006330(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x14) = param_2;
  sub_0800245A(param_1,&gUnknown_08011648);
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) - (*(short *)(param_1 + 4) >> 1);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) - (*(short *)(param_1 + 6) >> 1);
  return;
}

