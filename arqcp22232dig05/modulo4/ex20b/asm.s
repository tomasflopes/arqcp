.section .data
  .equ SECOND_BYTE_MASK, 0x0000ff00
.section .text
  .global sum_multiples_x	# int sum_multiples_x(char*, int)
sum_multiples_x:
  # rdi -> *vec
  # rsi -> x
  
  # Prologue
  pushq %rbp # save previous stack frame pointer
  movq %rsp, %rbp	# the stack frame pointer 
# -----------------------------------------
  andl $SECOND_BYTE_MASK,%esi # get second byte of x
  shrl $8,%esi # get real value of second byte of x

  xorl %r8d, %r8d # sum = 0

  testb %sil,%sil # check for second byte x = 0
  je .end

  .loop:
    movb (%rdi), %al # put second byte of x in %al to use in idiv

    testb %al, %al # check for end of array
    je .end

    movb %al, %r9b # save value of array position

    cbtw
    idivb %sil # divide by second byte 

    testb %ah,%ah # check if remainder is 0 
    jne .continue

    movsbl %r9b, %r9d
    addl %r9d, %r8d

    .continue:
      incq %rdi # increment to next position

    jmp .loop

.end:
# Epilogue ---------------------------------
	movq %rbp , %rsp # restore the stack pointer 
	popq %rbp # restore the stack base pointer

  movl %r8d, %eax # return sum

  ret
