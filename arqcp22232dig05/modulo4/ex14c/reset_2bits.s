.section .data
  .equ N_OF_BITS_IN_INTEGER, 31 # start counting at 0
.section .text
  .global reset_2bits	# void reset_2bits(int*, int)
reset_2bits:
  # rdi -> ptr
  # rsi -> pos
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------

  pushq %rdi
  pushq %rsi
    call reset_bit
  popq %rsi
  popq %rdi

  movl $N_OF_BITS_IN_INTEGER, %eax
  subl %esi, %eax
  movl %eax, %esi # %esi = 31 - pos

  pushq %rdi
  pushq %rsi
    call reset_bit
  popq %rsi
  popq %rdi

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret
