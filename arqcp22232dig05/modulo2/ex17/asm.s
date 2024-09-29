.section .data
	.global op1	# int op1;
	.global op2	# int op2;


.section .text
	.global sum	# int sum(void);
	.global subt	# int subt(void);
	.global mult	# int mult(void);
	.global div	# int div(void);
	.global mod	# int mod(void);
	.global power_2	# int power_2(void);
	.global power_3	# int power_3(void);

sum:
	movl	op1(%rip), %eax	# copy variable op1 to register
	addl	op2(%rip), %eax	# add op2 to value in register
  jmp _end

subt:
	movl	op1(%rip), %eax	# copy variable op1 to register
	subl	op2(%rip), %eax	# subtract
  jmp _end

mult:
	movl	op1(%rip), %eax	# copy variable op1 to register
	imull	op2(%rip), %eax	# signed multiplication
  jmp _end

div:
	movl	op1(%rip), %eax	# copy variable op1 to register
	cltd			# sign-extend %eax (32 bits) to %edx:%eax (64 bits)
	movl	op2(%rip), %ecx	# copy variable op2 to register
	test	%ecx, %ecx	# %ecx & %ecx (set flags) - if = 0 -> CF = 1
	je	zero		# CF = 0? jump to zero
	idivl	%ecx		# signed division
  jmp _end

mod:
	movl	op1(%rip), %eax	# copy variable op1 to register
	cltd			# sign-extend %eax (32 bits) to %edx:%eax (64 bits)
	movl	op2(%rip), %ecx	# copy variable op2 to register
	test	%ecx, %ecx	# %ecx & %ecx (set flags) - if = 0 -> CF = 1 
	je	zero		# CF = 0? jump to zero
	idivl	%ecx		# signed division
	movl	%edx, %eax	# copy remainder to return register
  jmp _end

zero:
	xor	%eax, %eax
  jmp _end

power_2:
	movl	op1(%rip), %eax	# copy variable to register
	imull	op1(%rip), %eax	# signed multiplication
  jmp _end

power_3:
	movl	op1(%rip), %eax	# copy variable to register
	imull	op1(%rip), %eax	# multiply
	imull	op1(%rip), %eax	# multiply again

_end:
  ret
