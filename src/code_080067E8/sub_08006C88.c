/* sub_08006C88  (original: 0x08006C88-0x08006C9A in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080028FC();


void sub_08006C88(int param_1)

{
  sub_080028FC(param_1);
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + 0x10;
  return;
}

