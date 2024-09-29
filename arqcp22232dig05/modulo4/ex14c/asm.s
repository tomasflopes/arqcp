.section .text
  .global reset_bit	# int reset_bit(int*, int)
reset_bit:
  # rdi -> ptr
  # rsi -> pos
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------
   
  movl %esi, %ecx # pos
  movl $1, %esi # mask
  shll %cl, %esi # shift bit to correct position
  not %esi # reverse all bits, now all bits are one except the reset bit

  movl (%rdi), %ecx # save original value of *ptr
  andl %esi, (%rdi) # apply mask

  cmpl (%rdi),%ecx # compare changed with original
  setne %al # set return value (1 if the value changed)

  movzbl %al, %eax # reset other bits in return register

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret
