.section .data
	.global ptr1	# char* ptr1


.section .text
	.global seven_count	# int seven_count(void)

seven_count:
	movq	ptr1(%rip), %rcx	# copy pointer to register
	xor	%eax, %eax		# result = 0
	jmp	.begin			# jump to .begin
.check:
	incq	%rcx			# set the pointer to the next byte
.begin:
	cmpb	$0, (%rcx)		# compare nul ascii value to the current byte pointed by rcx
	je	.end			# jump to .end if zero
	cmpb	$'7', (%rcx) 		# compare the value pointed by %rcx to ascii value of 7
	jne	.check			# if is not a 7 jump to .check
	incl	%eax			# result++
	jmp	.check			# jump to check
.end:
	ret

