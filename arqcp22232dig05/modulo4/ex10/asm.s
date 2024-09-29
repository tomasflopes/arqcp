.section .text
  .global incr	# int incr(short*, char)
incr:
  # rdi -> p1
  # rsi -> val

  # --------------------
  # Local Variables:
  # -4(%rbp) = x1
  # -8(%rbp) = x2
  
  # Prologue
	pushq %rbp # save previous stack frame pointer
	movq %rsp, %rbp	# the stack frame pointer
  # -----------------------------------------
  subq $8, %rsp # allocate 8 bytes for local variables (2 ints, no alignment issues)

  movswl (%rdi), %eax # eax = (int) *p1
  movl %eax, -4(%rbp) # x1 = (int) *p1

  movsbl %sil, %esi # cast val to long
  addl -4(%rbp),%esi # x2 = x+val
  movl %esi, -8(%rbp) 

  movl %esi, (%rdi) # *p1 = x+val

  # Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer
	popq %rbp # restore the stack base pointer

  ret
