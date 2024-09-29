.section .data
	.global length1	# int length1;
	.global length2 # int length2;
	.global height	# int height;
	.equ DIVIDER, 2

.section .text
	.global getArea	# int getArea(void);

getArea:
	movl	length1(%rip), %eax	# 32 bit copy from variable to register
	addl	length2(%rip), %eax	# length1 + length2
	imull	height(%rip), %eax	# signed multiplication (length1 + length2) * height
	cltd				# sign-extend %eax (32 bits) to %edx:%eax (64 bits)
	movl	$DIVIDER, %ecx		# copy divider to register because idiv doesn't accept constants
	idivl	%ecx			# signed division (length1 + length2) * height / 2
	ret

