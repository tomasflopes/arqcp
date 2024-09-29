.section .data
	.global i		# int i;
	.global j	  # int j;
	.global h	  # int h;
	.global g	  # int g;
	.global r	  # int r;

.section .text
	.global f4	# int f4(void);

f4:
  movl i(%rip), %eax
  movl j(%rip), %edi

  movl %eax, %esi
  addl %edi, %esi # %esi = i+j
  movl $10, %r8d

  cmpl %r8d, %esi
  jl _less
  jmp _ge

_less:
  movl $4, %edi # %edi = 4
  cltd
  imull %eax # %edi = 4*i
  cltd
  imull %eax # %edi = 4*i²
  jmp _end
_ge: 
  movl $3, %ecx
  movl %edi, %eax
  cltd
  imull %eax # %eax = j²
  cltd
  idivl %ecx # %eax = j²/3
  jmp _end

_end:
	ret

