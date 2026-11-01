/* sub_0800946E  (original: 0x0800946E-0x08009486 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes game output on tools/harness/decomp_explore.txt (found by gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_08008E06();


void sub_0800946E(byte *param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = param_1[1];
  *(ushort *)(param_2 + 10) = (ushort)*param_1;
  *(ushort *)(param_2 + 0xc) = (ushort)bVar1;
  sub_08008E06(param_2,*(undefined4 *)(param_1 + 4));
  return;
}

