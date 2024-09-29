.section .data
	.global current	# char current;
	.global desired	# char desire;
	
	.equ	TIME_TO_DECREASE, -240
	.equ	TIME_TO_INCREASE, 180

.section .text
	.global needed_time	# int needed_time(void);

needed_time:
	movsbl	desired(%rip), %eax	# copy 8 bit to 32 bit
	movsbl	current(%rip), %edx	# " 
	subl	%edx, %eax		# subtract desire - current
	js	decrease		# jump if sign flag = 1 (negative)
	movl	$TIME_TO_INCREASE, %edx # set multiplier to 3

multiply:
	imull	%edx, %eax		# signed multiplication
	ret

decrease:
	movl	$TIME_TO_DECREASE, %edx # set divider to -4
	jmp	multiply		# go to multiply

