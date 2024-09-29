.section .data
	.global code		# short code;
	.global currentSalary	# short currentSalary;

	.equ	RAISE_20, 400
	.equ	RAISE_21, 300
	.equ	RAISE_22, 200
	.equ	RAISE_DEFAULT, 150


.section .text
	.global new_salary	# int new_salary(void);

new_salary:
	movw	currentSalary(%rip), %ax
	movw	code(%rip), %cx		# copy variable to register
	cmp	$20, %cx		# compare code to 20 (set flags)
	je	code20			# if = jump to respective tag
	cmp	$21, %cx
	je	code21
	cmp	$22, %cx
	je	code22
default:				# not necessary, just indicative
	addw	$RAISE_DEFAULT, %ax
  jmp _end

code20:
	addw	$RAISE_20, %ax
  jmp _end
code21:
	addw	$RAISE_21, %ax
  jmp _end
code22:
	addw	$RAISE_22, %ax

_end:
  ret
