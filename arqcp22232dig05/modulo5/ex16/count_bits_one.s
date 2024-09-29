.section .text
  .global count_bits_one	# short count_bits_one(short)
count_bits_one:
  # rdi -> x
  
  # Prologue
	pushq %rbp # save previous stack frame pointer
	movq %rsp, %rbp	# the stack frame pointer
  # -----------------------------------------
   
	xorw %ax, %ax # intialize counter as 0
	movw $1, %cx # mask

  .loop:
    testw %cx, %cx
    je .end # if mask is zero -> end

    testw %cx, %di # check if x & mask is 0
    jne .active # if active bit (!= 0) -> increment

    jmp .continue

  .active:
    incw %ax # increment counter

  .continue:
    shlw %cx # shift mask to next bit
    jmp .loop

.end:
  # Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret

