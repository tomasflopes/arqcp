.section .data
	.global s1	# short s1;
	.global s2	# short s2;


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

