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
