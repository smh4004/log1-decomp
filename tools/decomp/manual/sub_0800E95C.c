/* Ghidra's text, except the end: this library function returns with GCC's `pop {r1}; bx r1` (or r3), which Ghidra
   misread as a jump table. The value it "passed" to the jump is the return value in r0. */
undefined4 sub_0800E95C(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)param_1[1];
  piVar4 = param_1;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 < param_2))) {
    piVar4 = piVar2;
    piVar1 = (int *)piVar2[1];
  }
  iVar3 = *piVar4;
  if ((int *)(iVar3 + (int)piVar4) != param_2) {
    param_2 = (int *)(((int)param_2 + 3U & 0xfffffff8) + 4);
  }
  *param_2 = param_3;
  return sub_0800EAC8(param_1,param_2 + 1,param_3,(int *)(iVar3 + (int)piVar4),param_4);
}
