/* sub_0800E9B0  (original: 0x0800E9B0-0x0800EAC8 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800EC6C();
extern undefined * volatile PTR_sub_0800D11C_1_08012128;
extern undefined volatile _0800EA48;

/* Ghidra's text, except the end: this library function returns with GCC's `pop {r1}; bx r1` (or r3), which Ghidra
   misread as a jump table. The value it "passed" to the jump is the return value in r0. */
undefined4 sub_0800E9B0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar2 = "";
  pcVar3 = pcVar2;
  if (param_1 - 1U < 0xd) {
    pcVar4 = (char *)((int)&PTR_sub_0800D11C_1_08012128 + param_1 * 0x17 + 3);
    if (param_1 == 2) {
      if ((int)param_2 << 5 < 0) {
        pcVar3 = "Invalid Operation";
      }
      else if (((uint)param_2 & 0x8000002) == 0) {
        if ((int)param_2 << 3 < 0) {
          pcVar3 = "Overflow";
        }
        else if ((int)param_2 << 2 < 0) {
          pcVar3 = "Underflow";
        }
        else if ((int)param_2 << 1 < 0) {
          pcVar3 = "Inexact Result";
        }
      }
      else {
        pcVar3 = "Divide By Zero";
      }
    }
    else {
      pcVar3 = param_2;
      if (((param_1 != 8) && (pcVar3 = pcVar2, param_1 == 9)) && (param_2 == (char *)0x1)) {
        pcVar4 = ": Heap memory corrupted";
      }
    }
  }
  else {
    pcVar4 = "Unknown signal";
  }
  sub_0800EC6C(10);
  cVar1 = *pcVar4;
  while (cVar1 != '\0') {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    sub_0800EC6C(cVar1);
    cVar1 = *pcVar4;
  }
  cVar1 = *pcVar3;
  while (cVar1 != '\0') {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    sub_0800EC6C(cVar1);
    cVar1 = *pcVar3;
  }
  sub_0800EC6C(10);
  return 1;
}
