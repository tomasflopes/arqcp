.section .text
  .global calc	# int calc(int, int*, int)
calc:
  # rdi -> a
  # rsi -> *b
  # rdx -> c
  
  # Prologue
	pushq %rbp # save previous stack frame pointer
	movq %rsp , %rbp # the stack frame pointer
  # -----------------------------------------

  sall $1, %edi # edi * 2
  subl (%rsi), %edi # z (%edi) = a*2-(*b)
  subl $4, %edx # c = c-4

  movl %edi, %eax
  imull %edx # result in %eax

  # Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer
	popq %rbp # restore the stack base pointer

  ret
