.section .data
	.global i		# int i;
	.global j	  # int j;
	.global h	  # int h;
	.global g	  # int g;
	.global r	  # int r;

.section .text
	.global f3	# int f3(void);

f3:
  movl i(%rip), %eax
  movl j(%rip), %edi
  movl $0, %esi # h
  movl $0, %r8d # g

  cmpl %eax, %edi

  jl _ge
  jmp _l

  _continue:
    movl %eax, %ecx # move h to %ecx
    movl %r8d, %eax # move g to %eax
    cltd # convert %edx to signal bit of %eax 
    idivl %ecx # result in %eax
    jmp _end

_ge:
  cltd # set %edx to signal bit of %eax
  imull %edi # %eax = h = i*j
  addl i(%rip), %r8d # %r8d = g = i
  incl %r8d # %r8d = g = i+i
  jmp _continue

_l:
  addl %edi, %eax # %eax = h = i+j
  addl %eax, %r8d # %r8d = g = i+j
  addl $2, %r8d # %r8d = g = i+j+2
  jmp _continue

_end:
	ret
