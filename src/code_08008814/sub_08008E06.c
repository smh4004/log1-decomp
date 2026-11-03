/* sub_08008E06  (original: 0x08008E06-0x08008E3A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_explore.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_08008DBE();


void sub_08008E06(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    if (bVar1 == 10) {
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
      *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
      iVar2 = *(int *)(param_1 + 0x18);
      *(int *)(param_1 + 0x18) = iVar2 + -1;
      if (iVar2 + -1 == 0) {
        param_1[0x20] = 1;
        param_1[0x21] = 0;
        param_1[0x22] = 0;
        param_1[0x23] = 0;
      }
    }
    else {
      sub_08008DBE(param_1,(ushort)bVar1);
    }
    param_2 = param_2 + 1;
  }
  return;
}

