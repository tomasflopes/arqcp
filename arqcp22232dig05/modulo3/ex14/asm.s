.section .data
  .global ptrvec
  .global num
  .global x
.section .text
  .global exists # int exists(void)
exists:
  movq ptrvec(%rip), %rax 
  movl x(%rip), %edx
  movl num(%rip), %esi 
  movl $0, %r8d # num of times that x was found

  .loop:
    testl %esi, %esi
    je .end

    leaq -4(%rax, %rsi, 4), %rdi # when setting %esi most significant bytes are setted to 0
    cmpl %edx, (%rdi)

    je .found
    
    _continue:
      decl %esi
      jmp .loop 
.found:
  addl $1, %r8d
  cmpl $2, %r8d
  je .end

  jmp _continue
.end:
  shrl $1, %r8d # if %r8d is 0b10 -> set to 01. If is 0 it remains the same
  movl %r8d, %eax
  ret
