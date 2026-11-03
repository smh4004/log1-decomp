/* sub_0800CC60(p): builds a 4-byte stack slot whose low byte is p[5] (the upper three bytes are whatever was in r3,
   which the original pushes to make the slot) and calls sub_080051D0(p[4], &slot); returns its result.
   Hand-written because Ghidra's `_local_8 = CONCAT31(...)` partial-variable notation doesn't compile. */
int sub_0800CC60(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
{
  uint slot = ((uint)param_4 & 0xffffff00) | *(byte *)(param_1 + 5);
  return sub_080051D0(*(byte *)(param_1 + 4), &slot);
}
