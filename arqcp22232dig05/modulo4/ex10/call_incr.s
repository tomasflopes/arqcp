.section .text
  .global call_incr	# int call_incr(short)
call_incr:
  # rdi -> w
  # rsi -> second argument

  # Local Variables:
  # -8(%rbp) = x1
  # -4(%rbp) = x2
  
  # Prologue
	pushq %rbp # save previous stack frame pointer
	movq %rsp, %rbp # the stack frame pointer for our function
  # -----------------------------------------
  # allocate 8 bytes for local variable (the variable uses 2 of this 8 bytes)
  # 8 bytes are needed for alignment reasons
  subq $8, %rsp 

  movw %di, -8(%rbp) # x1 = w 
  addw $3, -8(%rbp) # x1 = w + 3

  leaq -8(%rbp), %rdi # rdi = &x1 (first argument)

  movb $0xC3, %sil # second argument

  pushq %rdi
    call incr 
  popq %rdi
  
  movl %eax, -4(%rbp) # ineficient!
  movswl -8(%rbp), %edi # cast x1 to long
  addl -4(%rbp),%edi # sum with return of incr()

  movl %edi, %eax # return value

  # Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer (clear the stack)
	popq %rbp # restore the stack frame pointer

  ret
