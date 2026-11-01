/* sub_08000800  (original: 0x08000800-0x0800084A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes game output on tools/harness/decomp_explore.txt (found by gamebisect.py).
 */
#include "ghidra_types.h"
extern int volatile DAT_03004390;
extern undefined4 volatile DAT_02029b9c;
extern undefined1 volatile DAT_02029ba0;


int sub_08000800(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = DAT_03004390;
  if (DAT_03004390 != 0) {
    iVar1 = 0;
    do {
      uVar2 = 0;
      uVar4 = 0;
      uVar3 = 0;
      do {
        uVar2 = (uVar2 >> 0x1d | uVar2 << 3) + (uint)(byte)(&DAT_02029ba0)[iVar1 * 0xac] + 1;
        uVar4 = uVar4 ^ uVar2;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0xa8);
      if (uVar4 == (&DAT_02029b9c)[iVar1 * 0x2b]) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
    iVar1 = 0;
  }
  return iVar1;
}

