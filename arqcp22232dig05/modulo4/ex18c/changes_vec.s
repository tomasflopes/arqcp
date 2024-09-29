.section .text
  .global changes_vec # void changes_vec(int*,int)
changes_vec:
  # rdi -> ptr_vec
  # rsi -> num
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------
  testl %esi, %esi # check if num = 0
  je .end

  movl %esi, %ecx # num

  .loop:
    pushq %rdi

    leaq -4(%rdi, %rcx, 4), %rdi

    pushq %rsi
    pushq %rcx
      call changes
    popq %rcx
    popq %rsi
    popq %rdi
  loop .loop

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret
