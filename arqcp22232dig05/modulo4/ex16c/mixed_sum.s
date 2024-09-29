.section .text
  .global mixed_sum	# int mixed_sum(int, int, int)
mixed_sum:
  # rdi -> a
  # rsi -> b
  # rdx -> pos
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------
  xorl %eax, %eax # set return value as 0

  pushq %rdx # pos
  pushq %rdi # a
  pushq %rsi # b
    call join_bits
  popq %rdi # change order of parameters
  popq %rsi
  popq %rdx

  pushq %rax
    call join_bits
    movl %eax, %edi
  popq %rax
  addl %edi, %eax

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret
