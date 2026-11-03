/* timing control: the original instructions of sub_08008D8A, relocated (see docs/decomp.md, "Timing") */
__attribute__((naked)) void sub_08008D8A(void)
{
  __asm__ volatile (".syntax unified\n adds r2, r0, #0\n ldr r1, [r0, #0x10]\n ldr r0, =0x040000D4\n adds r2, #0x24\n str r2, [r0]\n"
                    " str r1, [r0, #4]\n lsrs r1, r0, #0x10\n strh r1, [r0, #8]\n lsrs r1, r0, #0xb\n strh r1, [r0, #0xa]\n"
                    " bx lr\n .ltorg\n .syntax divided");
}
