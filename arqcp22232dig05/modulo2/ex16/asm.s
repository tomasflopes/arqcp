.section .data
  .global num

.section .text
  .global steps # int steps(void)
  
steps:
  movq num(%rip), %rax # place n  um in rax

  cqto # extends signal of %rax to %rdx
  movq $3, %rdi
  imulq %rdi # Multiples by 3 (result in %rax)
  addq $6, %rax # Adds 6

  cqto # extends signal of %rax to %rdx
  idivq %rdi # Divides by 3 (result in %rax)

  addq $12, %rax # Adds 12
  subq num(%rip), %rax # Subtracts num
  decq %rax # Subtracts 1

  ret

