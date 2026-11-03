/* sub_0800A748  (original: 0x0800A748-0x0800A80E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int volatile DAT_03003d3c;
extern undefined volatile DAT_03003d44;
extern undefined volatile DAT_03003dec;
extern undefined volatile DAT_03003ebc;


void sub_0800A748(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = (uint)*(byte *)(param_1 + 3);
  if ((int)(uVar2 << 0x1f) < 0) {
    if ((int)(uVar2 * 0x8000000) < 0) {
      uVar6 = (int)((uint)*(byte *)(param_1 + 4) * (uint)*(byte *)(param_1 + 0xc) *
                   (0x40 - *(char *)((int)param_1 + 0x11))) >> 10;
      uVar3 = (int)((uint)*(byte *)(param_1 + 4) * (uint)*(byte *)(param_1 + 0xc) *
                   (*(char *)((int)param_1 + 0x11) + 0x40)) >> 10;
      uVar7 = uVar6 & 0xff;
      uVar4 = uVar3 & 0xff;
      *(char *)((int)param_1 + 0xe) = (char)uVar6;
      uVar1 = (undefined1)uVar3;
      *(undefined1 *)((int)param_1 + 0xf) = uVar1;
      if (uVar7 == 0 && uVar4 == 0) {
        param_1[5] = 0x8008aa5;
      }
      else if (uVar7 == 0) {
        *(undefined1 *)((int)param_1 + 0xe) = uVar1;
        *(undefined1 *)((int)param_1 + 0xf) = 1;
        param_1[5] = &DAT_03003d44;
      }
      else if (uVar4 == 0) {
        param_1[5] = &DAT_03003d44;
      }
      else if (uVar7 == uVar4) {
        param_1[5] = &DAT_03003dec;
      }
      else {
        param_1[5] = &DAT_03003ebc;
      }
    }
    if ((int)(uVar2 << 0x1c) < 0) {
      puVar5 = (undefined4 *)param_1[9];
      param_1[2] = *puVar5;
      param_1[7] = (uint)*(ushort *)((int)puVar5 + 6) << 0xe;
      param_1[8] = (uint)*(ushort *)(puVar5 + 2) << 0xe;
      *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)((int)puVar5 + 10);
      *(undefined1 *)((int)param_1 + 0xd) = *(undefined1 *)(puVar5 + 1);
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      *param_1 = 0;
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfb;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      uVar2 = DAT_03003d3c * ((uint)*(ushort *)((int)param_1 + 0x12) * param_1[0xb] >> 0xe) + 0x7ff
              >> 0xc;
      param_1[6] = uVar2;
      if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1d) < 0) {
        param_1[1] = -uVar2;
      }
      else {
        param_1[1] = uVar2;
      }
    }
    *(undefined1 *)(param_1 + 3) = 1;
  }
  return;
}

