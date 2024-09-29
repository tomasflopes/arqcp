.section .data
	.global s	# short s;


.section .text
	.global swapBytes	# short swapBytes(void);

swapBytes:
	movw	s(%rip), %cx	# 16 bit copy of variable s to register
				# %cx = 0xAAFF
	movb	%cl, %ah	# %ax = 0xFF00
	movb	%ch, %al	# %ax = 0xFFAA
	addb	%al, %al	# double %al register value
	ret

