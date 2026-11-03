/* sub_08001CFA  (original: 0x08001CFA-0x08001D52 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08009064();
extern int sub_08008D14();
extern int sub_0800E640();
extern ushort volatile DAT_02029d9e;
extern ushort volatile DAT_02029da0;
extern undefined1 volatile DAT_02029d94;
extern undefined * volatile PTR_gUnknown_080102D4_0801009c;
extern undefined2 volatile REG_BG0VOFS;

/* Ghidra's text with one fix: sub_0800E640 is the ADS unsigned divide (__rt_udiv: r0 = divisor, r1 = dividend),
   and the code uses the remainder it leaves in r1, which Ghidra called extraout_r1. */
void sub_08001CFA(int param_1)

{
  int iVar1;
  int rem;
  int iVar2;
  
  sub_08008D14(&DAT_02029d94);
  iVar2 = *(int *)(param_1 + 4);
  rem = (int)((uint)iVar2 % 0x11c0);
  DAT_02029da0 = (short)(iVar2 >> 5) + 10U & 0x1f;
  iVar2 = 0;
  DAT_02029d9e = 2;
  do {
    iVar1 = iVar2 + (rem >> 5);
    if (0x8d < iVar1) break;
    sub_08009064(&DAT_02029d94,(&PTR_gUnknown_080102D4_0801009c)[iVar1]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xb);
  sub_08008D8A(&DAT_02029d94);
  REG_BG0VOFS = (short)(*(int *)(param_1 + 4) >> 2);
  return;
}
