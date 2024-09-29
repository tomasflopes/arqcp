.section .data
  .global num
  .global ptrvec
.section .text
  .global vec_add_two # void vec_add_two(void)

vec_add_two:
  movq ptrvec(%rip), %rax # pointer to array
  movl num(%rip), %r8d # number of elements of array
  movq $0, %rdi

  .loop:
    cmpl %edi, %r8d # check if loop has ended
    je .end

    leaq (%rax, %rdi, 4), %rdx # as %ecx starts in num

    addl $2, (%rdx) # move char to ptr2

    incl %edi # increment index

    jmp .loop # while num is greater than 0

.end:
  ret
