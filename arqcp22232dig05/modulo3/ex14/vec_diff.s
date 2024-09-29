.section .data
  .global ptrvec
  .global num
  .global x
.section .text
  .global vec_diff # int vec_diff(void)
vec_diff:
  movq ptrvec(%rip), %rax 
  movl x(%rip), %edx
  movl num(%rip), %r8d
  xor %esi, %esi # set %esi as 0

  _loop:
    testl %r8d, %r8d
    je _end

    leaq -4(%rax, %r8, 4), %rdi # when setting %r8d most significant bytes are setted to 0
    movl (%rdi), %edi
    movl %edi, x(%rip)
    
    pushq %rax
    pushq %r8
    pushq %rdx
    pushq %rsi

    call exists

    popq %rsi
    addl %eax, %esi # sum the return value of exists()

    popq %rdx
    popq %r8
    popq %rax

    decl %r8d
  jmp _loop
  
_end:
  movl %esi, %eax
  subl num(%rip), %eax # get number of unique numbers
  neg %eax # as we get a negative number we need to invert it

  ret

