.section .data
  .global op1
  .global op2
  .equ CONST, 20

.section .text
  .global sum_v2 # int sum_v2(void)

sum_v2:
  movl op1(%rip), %ecx # place op1 in ecx
  movl op2(%rip), %eax # place op2 in eax

  movl $CONST, %edx
  addl %ecx, %ecx

  subl %ecx, %edx
  
  addl %edx, %eax
  ret

