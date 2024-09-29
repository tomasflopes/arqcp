.section .text
	.global sum_smaller	# int sum_smaller(int, int, int*)
sum_smaller:
# rdi -> num1
# rsi -> num2
# rdx -> smaller
  leaq (%rdi, %rsi), %rax # %rax = %rdi + %rsi (%rsi & %rdi has most significant bytes as 0)

  cmpl %edi, %esi
  jl .swap

  movl %edi, (%rdx)
  jmp .continue

  .swap:
    movl %esi, (%rdx)
  .continue:
    ret

