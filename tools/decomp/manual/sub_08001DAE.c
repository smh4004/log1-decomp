/* Ghidra's text with one fix: the remainder of the unsigned divide sub_0800E640 (left in r1; Ghidra's extraout_r1). */
void sub_08001DAE(int param_1)

{
  int iVar1;
  int rem;
  int iVar2;
  int iVar3;
  
  sub_08008D14(&DAT_02029d94);
  iVar2 = *(int *)(param_1 + 4);
  rem = (int)((uint)iVar2 % 0x1300);
  iVar3 = 0;
  do {
    iVar1 = iVar3 + (rem >> 5) + -10;
    if (0x8d < iVar1) break;
    if (-1 < iVar1) {
      DAT_02029d9e = 1;
      DAT_02029da0 = (ushort)((uint)(iVar2 << 0x16) >> 0x1b) + (short)iVar3 & 0x1f;
      sub_08009064(&DAT_02029d94,(&PTR_gUnknown_080102D4_0801009c)[iVar1]);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1f);
  sub_08008D8A(&DAT_02029d94);
  return;
}
