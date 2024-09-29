.section .data
  .equ SECOND_BYTE_MASK, 0x0000ff00
  .equ THIRD_BYTE_MASK, 0x00ff0000
.section .text
  .global changes	# void changes(int*)
changes:
  # rdi -> ptr
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------
  movl (%rdi), %ecx # *ptr
  andl $SECOND_BYTE_MASK, %ecx # second byte
  shrl $8, %ecx # get value of second byte

  cmpl $15, %ecx # check if second byte is greater than 15
  jle .end # if not greater - return

  xorl $THIRD_BYTE_MASK, (%rdi) # invert 3rd byte bits

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret
