.section .data
	.global i		# int i;
	.global j	  # int j;

.section .text
	.global f	# int f(void);

f:
  movl i(%rip), %eax
  movl j(%rip), %edi

  cmpl %eax, %edi
  je _equal
  jmp _ne


_equal:
  subl %edi, %eax
  incl %eax
  jmp _end

_ne:
  addl %edi, %eax
  decl %eax

_end:
  ret

