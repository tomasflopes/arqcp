.section .data
	.global i		# int i;
	.global j	  # int j;
	.global h	  # int h;

.section .text
	.global f2	# int f2(void);

f2:
  movl i(%rip), %eax
  movl j(%rip), %edi

  cmpl %eax, %edi

  jl _greater
  jmp _less

  _continue:
    cltd # set %edx to signal bit of %eax
    imull %edi # multiply by j

  jmp _end

_greater:
  decl %eax 
  jmp _continue
_less:
  incl %edi
  jmp _continue

_end:
  ret
