.section .text
  .global join_bits	# int join_bits(int, int,int)
join_bits:
  # rdi -> a
  # rsi -> b
  # rdx -> pos
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------
  movb %dl, %cl # pos
  movl $-1, %eax # mask (signed int with all bits as 1)

  incb %cl
  shll %cl, %eax # shift mask pos+1

  cmpb $32, %cl
  jne .continue

  notl %eax

  .continue:
    andl %eax, %esi # b & mask
    notl %eax
    andl %eax, %edi # a & mask

  movl %edi, %eax
  orl %esi, %eax

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  ret
