.section .data
  .global op1
  .global op2
  op3:
    .quad op3
  op4:
    .quad op4
  .global op3
  .global op4

.section .text
  .global sum_v3 # int sum_v3(void)

sum_v3:
  movl op1(%rip), %ecx # place op1 in ecx
  movl op2(%rip), %eax # place op2 in eax
  movq op3(%rip), %rdx # place op3 in rdx
  movq op4(%rip), %rdi # place op4 in rdi

  addl %eax, %eax # op2 + op2 eax = 2 * op2
  addl %ecx, %ecx # op1 + op1 ecx = 2 * op1

  addq %rdx, %rdi # op3 + op4 rdi = op3 + op4

  movslq %ecx, %rcx # parse to long op1
  movslq %eax, %rax # parse to long op2
  
  addq %rcx, %rdi # op3 + op4 + 2 * op1 rdi = 2 * op1 + rdi

  subq %rax, %rdi # rdi = rdi - rcx 

  movq %rdi, %rax

  ret

