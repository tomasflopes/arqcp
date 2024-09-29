.section .text
  .global count_bits_one	# int count_bits_one(short*, char)
count_bits_one:
  # rdi -> x
  
  # Prologue
	pushq %rbp # save previous stack frame pointer
	movq %rsp, %rbp	# the stack frame pointer
  # -----------------------------------------
   
	xor %eax, %eax # intialize counter as 0
	movl $1, %ecx # mask

  .loop:
    testl %ecx, %ecx
    je .end # if mask is zero -> end

    testl %ecx, %edi # check if x & mask is 0
    jne .active # if active bit (!= 0) -> increment

    jmp .continue

  .active:
    incl %eax # increment counter

  .continue:
    shll %ecx # shift mask to next bit
    jmp .loop

.end:
  # Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer
	popq %rbp # restore the stack base pointer

  ret
