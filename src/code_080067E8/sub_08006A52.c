/* sub_08006A52  (original: 0x08006A52-0x08006A72 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080028FC();


void sub_08006A52(int param_1)

{
  undefined4 local_c;
  
  sub_080028FC(param_1);
  local_c = CONCAT22(*(short *)(param_1 + 0x22) << 4,*(short *)(param_1 + 0x20) << 4);
  *(undefined4 *)(param_1 + 0x28) = local_c;
  return;
}

