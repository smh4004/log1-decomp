/* sub_0800174A  (original: 0x0800174A-0x080017B6 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030047ec;
extern undefined4 volatile DAT_0202c224;
extern undefined1 volatile gUnknown_081C7A84;
extern undefined4 volatile DAT_0202c228;
extern undefined1 volatile DAT_0202c28c;
extern undefined1 volatile DAT_0300004e;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


int sub_0800174A(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x202c28c;
  Ram040000dc = 4;
  DAT_040000de = 0x8500;
  iVar3 = 0;
  do {
    pbVar2 = &gUnknown_081C7A84 + iVar3;
    pcVar1 = &DAT_0300004e + iVar3;
    iVar3 = iVar3 + 1;
    (&DAT_0202c28c)[*pbVar2] = (&DAT_0202c28c)[*pbVar2] + *pcVar1;
  } while (iVar3 < 0x22);
  iVar3 = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  do {
    if ((&DAT_0202c28c)[iVar3] != '\0') {
      (&DAT_0202c228)[(uint)*(byte *)(param_1 + 6) * 2] = iVar3;
      (&DAT_0202c224)[(uint)*(byte *)(param_1 + 6) * 2] = (uint)(byte)(&DAT_0202c28c)[iVar3];
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xd);
  return param_1;
  return param_1;   /* ADS constructor: returns this */
}
