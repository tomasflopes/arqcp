.section .data
	length1:	.int 0
	length2:	.int 0
	height:		.int 0
	.equ DIVIDER, 2

	.global length1
	.global length2
	.global height


.section .text
	.global getArea	# int getArea(void);

getArea:
	movl	length1(%rip), %eax	# copy 32 bits from memory to register
	addl	length2(%rip), %eax	# length1 + length2
	imul	height(%rip), %eax	# signed multiplication (length1 + length2) * height
	cltd				# sign-extend %eax (32 bits) to %edx:%eax (64 bits)
	movl	$DIVIDER, %ecx		# copy divider to register
	idivl	%ecx			# signed division (length1 + length2) * height / 2
	ret

