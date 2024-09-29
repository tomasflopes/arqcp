.section .data
  .global ptrvec
  .global num
.section .text
  .global count_max # int count_max(void)
count_max:
  movq ptrvec(%rip), %rax
  movl num(%rip), %edx # sets most significant bytes as 0
  movl $0, %r8d # counter

  cmpl $1,%edx # if array has only one element
  jle .end

.loop:
  decl %edx

  cmpl $1, %edx # last execution is exception
  je .end

  leaq -4(%rax, %rdx, 4), %rdi # start in arr[len-2]
  movl (%rdi), %r9d

  cmpl -4(%rdi), %r9d # compare arr[i] with arr[i-1] 
  jle .loop # if is greater go to next iteration

  cmpl 4(%rdi), %r9d # compare arr[i] with arr[i+1] 
  jle .loop # if is less go to next iteration

  incl %r8d # if no condition is met increment counter

  jmp .loop

.end:
  movl %r8d, %eax
  ret
