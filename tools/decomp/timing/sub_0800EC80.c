/* timing control: the original instructions of sub_0800EC80, relocated (see docs/decomp.md, "Timing") */
__attribute__((naked)) void sub_0800EC80(void)
{
  __asm__ volatile (".syntax unified\n ldr r1, =0x0300000C\n ldr r0, =_0800F180\n str r0, [r1]\n bx lr\n .ltorg\n .syntax divided");
}
