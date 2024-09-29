.section .data
  .global op1
  .global op2
  .global op3

.section .text
  .global sum3ints # long long sum3ints(void)
sum3ints:
  movl op1(%rip), %ecx # place op1 in ecx
  movl op2(%rip), %eax # place op2 in eax
  movl op3(%rip), %edx # place op2 in eax

  movslq %ecx, %rcx # parse to long op1
  movslq %eax, %rax # parse to long op2
  movslq %edx, %rdx # parse to long op3

  addq %rcx, %rdx
  addq %rdx, %rax  

  ret

