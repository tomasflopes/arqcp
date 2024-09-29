.section .data
  .global ptrvec
  .global num
.section .text
  .global vec_zero # void vec_zero(void)
vec_zero:
  movb $0, %al # return value (unsigned char)
  movq ptrvec(%rip), %rdi # reference to value
  movl $0, %esi # index

  .loop:
    cmpl %esi, num(%rip) # check if index = num
    je .end

    leaq (%rdi,%rsi,4), %r8 # ptrvec[%rsi] (when moving to 4 bytes, the other 4 bytes are setted to 0)

    cmpl $100, (%r8) # check if ptrvec[%rsi] = 0
    jge .change

    _continue:
      incl %esi # increment index
      jmp .loop
.change:
  incb %al # increment num of changed elements
  movl $0, (%r8) # put 0 in position
  jmp _continue

.end:
  ret
