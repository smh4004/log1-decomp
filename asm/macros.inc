@ In `make decomp` builds, decomp_defs.inc marks which functions are provided by C (src/).
	.ifdef DECOMP_BUILD
	.include "decomp_defs.inc"
	.endif

@ Assembler macros for the Buu's Fury disassembly (pret-style).

	.macro thumb_func_start name
	.align 1, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm
