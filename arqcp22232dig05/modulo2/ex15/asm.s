.section .data
  .global A
  .global B
  .global C
  .global D

.section .text
  .global compute # int compute(void)
  
compute:
  movl A(%rip), %eax # place A in eax
  movl B(%rip), %ecx # place B in ecx
  movl C(%rip), %edx # place C in edx
  movl D(%rip), %edi # place D in edi

  testl %edi, %edi
  je _zero

  imul %ecx, %eax # A *= B
  subl %edx, %eax # A*B - C
  cltd # extends signal of %eax to %edx

  idivl %edi # %eax = (A*B-C) / D

  jmp _end

_zero:
  movl $0, %eax

_end:
  ret
