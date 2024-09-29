.section .text
  .global vec_count_bits_one	# int vec_count_bits_one(short*, char)
vec_count_bits_one:
  # rdi -> ptr
  # rsi -> num
  
  # Prologue
	pushq %rbp # save previous stack frame pointer
	movq %rsp, %rbp	# the stack frame pointer for our function
  # -----------------------------------------
  xor %edx, %edx # total counter
  movl %esi, %ecx # num

  testl %ecx, %ecx
  je .end

  .loop:
    pushq %rdi # save ptr

    leaq -2(%rdi, %rcx, 2), %rdi

    # use zero extend to prevent new zeros being added from sign extension
    movzwl (%rdi), %edi # pass vec[%ecx] as argument to count_bits_one()

    pushq %rdx
    pushq %rcx
      call count_bits_one
    popq %rcx
    popq %rdx
    popq %rdi

    addl %eax, %edx
  loop .loop
.end:
  # Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer (clear the stack)
	popq %rbp # restore the stack base pointer

  movl %edx, %eax # move total counter to return
  ret

