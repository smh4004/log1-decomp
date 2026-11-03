/* sub_0800E4B0  (original: 0x0800E4B0-0x0800E4DC in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int __call_via_r0();
extern undefined4 volatile DAT_0800ee54;
extern int sub_0800EEC0();


void sub_0800E4B0(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)&DAT_0800ee54;
  do {
    __call_via_r0(pcVar1 + *(int *)pcVar1);
    pcVar1 = pcVar1 + 4;
  } while (pcVar1 != sub_0800EEC0);
  return;
}

