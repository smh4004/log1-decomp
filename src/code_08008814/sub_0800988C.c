/* sub_0800988C  (original: 0x0800988C-0x080098C6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern undefined2 volatile DAT_07000002;
extern undefined2 volatile DAT_07000004;
extern undefined2 volatile DAT_07000006;
extern undefined2 volatile DAT_0700000e;
extern undefined2 volatile DAT_07000016;
extern undefined2 volatile DAT_0700001e;


void sub_0800988C(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    (&DAT_07000006)[iVar1 * 0x10] = 0x100;
    (&DAT_07000016)[iVar1 * 0x10] = 0;
    (&DAT_0700000e)[iVar1 * 0x10] = 0;
    iVar2 = iVar1 + 1;
    (&DAT_0700001e)[iVar1 * 0x10] = 0x100;
    iVar1 = iVar2;
  } while (iVar2 < 0x20);
  iVar1 = 0;
  do {
    *(undefined2 *)(iVar1 * 8 + 0x7000000) = 0x200;
    (&DAT_07000002)[iVar1 * 4] = 0;
    iVar2 = iVar1 + 1;
    (&DAT_07000004)[iVar1 * 4] = 0;
    iVar1 = iVar2;
  } while (iVar2 < 0x80);
  return;
}

