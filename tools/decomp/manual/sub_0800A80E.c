/* Ghidra's text, with the four BIOS Div calls (swi 6: r0 / r1 -> r0) written as C division, which Ghidra had dropped. */
void sub_0800A80E(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((int)((uint)*(byte *)(param_1 + 3) << 0x1f) < 0) {
    if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1f) < 0) {
      if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1e) < 0) {
        do {
          iVar1 = *param_1;
          iVar2 = iVar1 + param_3 * param_1[1];
          if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1d) < 0) {
            if (param_1[7] <= iVar2) {
              __call_via_r3(param_1,param_2,param_3,param_1[5],param_4);
              *param_1 = iVar2;
              return;
            }
            iVar1 = ((iVar1 + param_1[6] + -1) - param_1[7]) / param_1[6];   /* BIOS Div (swi 6) */
            param_4 = (param_1[7] * 2 - *param_1) - iVar1 * param_1[6];
            __call_via_r3(param_1,param_2,iVar1,param_1[5]);
            *param_1 = param_4;
            *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfb;
            param_1[1] = param_1[6];
          }
          else {
            if (iVar2 < param_1[8]) {
              __call_via_r3(param_1,param_2,param_3,param_1[5],param_4);
              *param_1 = iVar2;
              return;
            }
            iVar1 = ((param_1[8] + param_1[6] + -1) - iVar1) / param_1[6];   /* BIOS Div (swi 6) */
            param_4 = (param_1[8] * 2 - *param_1) - iVar1 * param_1[6];
            __call_via_r3(param_1,param_2,iVar1,param_1[5]);
            *param_1 = param_4;
            *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 4;
            param_1[1] = -param_1[6];
          }
          param_2 = iVar1 * 4 + param_2;
          param_3 = param_3 - iVar1;
        } while (0 < param_3);
      }
      else {
        do {
          iVar1 = *param_1 + param_3 * param_1[1];
          if (iVar1 < param_1[8]) {
            __call_via_r3(param_1,param_2,param_3,param_1[5],param_4);
            *param_1 = iVar1;
            return;
          }
          iVar1 = ((param_1[8] + param_1[6] + -1) - *param_1) / param_1[6];   /* BIOS Div (swi 6) */
          param_4 = (*param_1 + iVar1 * param_1[6]) - (param_1[8] - param_1[7]);
          __call_via_r3(param_1,param_2,iVar1,param_1[5]);
          param_2 = iVar1 * 4 + param_2;
          param_3 = param_3 - iVar1;
          *param_1 = param_4;
        } while (0 < param_3);
      }
    }
    else {
      iVar1 = *param_1 + param_3 * param_1[1];
      if (iVar1 < param_1[8]) {
        __call_via_r3(param_1,param_2,param_3,param_1[5],param_4);
        *param_1 = iVar1;
      }
      else {
        __call_via_r3(param_1,param_2,((param_1[8] + param_1[6] + -1) - *param_1) / param_1[6],param_1[5],param_4);   /* BIOS Div */
        *(undefined1 *)(param_1 + 3) = 0;
        iVar1 = param_1[10];
        if (iVar1 != 0) {
          *(byte *)(iVar1 + 10) = *(byte *)(iVar1 + 10) & 0xfb;
        }
      }
    }
  }
  return;
}
