/* Soft reset: sub_0800AB1A, interrupts off (REG_IME = 0), then BIOS SoftReset (swi 0). */
void sub_0800DBF8(void)
{
  sub_0800AB1A();
  REG_IME = 0;
  __asm__ volatile ("swi 0" : : : "r0", "r1", "r2", "r3", "memory");
}
