@ Relocation test padding: `make SHIFT=n` links this right after crt0, moving everything after it by n bytes.
	.text
	.space SHIFT, 0
