.section .data
	s1:	.short 0
	s2:	.short 0

	.global s1
	.global s2

.section .text
	.global crossSumBytes	# short crossSumBytes(void);

crossSumBytes:
	# copy values in memory to registers
	movw	s1(%rip), %ax
	movw	s2(%rip), %cx

	# cross sum
	addb	%ch, %al
	addb	%cl, %ah

	ret

