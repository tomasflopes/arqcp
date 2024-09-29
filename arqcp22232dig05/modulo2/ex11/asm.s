.section .data
	.global op1	# int op1;
	.global op2	# int op2;


.section .text
	.global test_flags	# char test_flags(void);

test_flags:
	movl	op1(%rip), %ecx	# copy variable in memory to register
	addl	op2(%rip), %ecx	# sum value of op2 to register
	
	jc	return_one	# jump if carry flag is on
	jo	return_one	# jump if overflow flag is on

	xor	%eax, %eax	# efficient way to set register value to 0
  jmp _end

return_one:
	mov	$1, %eax	# 32 bit set, the upper 32 bits are zeroed

_end:
  ret
