.section .data
	.global A	# int A;
	.global B	# short B;
	.global C	# char C;
	.global D	# char D;


.section .text
	.global sum_and_subtract	# long sum_and_subtract(void);

sum_and_subtract:
	# C + A - D + B
	movsbq	C(%rip), %rax	# 8 bit copy signed variable in memory to 64 bit register
	movslq	A(%rip), %rdx	# 32 bit copy signed variable to 64 bit register
	addq	%rax, %rdx	# C + A
	movsbq	D(%rip), %rax	# 8 bit copy signed variable to 64 bit register
	subq	%rax, %rdx	# C + A - D
	movswq	B(%rip), %rax	# 16 bit copy signed variable to 64 bit register
	addq	%rdx, %rax	# C + A - D + B
	ret

