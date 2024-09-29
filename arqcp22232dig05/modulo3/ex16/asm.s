.section .data
  .global ptr1
  .global ptr2
  .global num
.section .text
  .global swap # void swap(void)
swap:
  movq ptr1(%rip), %rax
  movq ptr2(%rip), %rdx
  movl num(%rip), %ecx # sets most significant bytes to 0
  
  cmpl $0, %ecx
  je .end
  
  .loop:
    leaq -1(%rax, %rcx), %r8 # v1[%ecx]
    leaq -1(%rdx, %rcx), %r9 # v2[%ecx]

    movb (%r8), %sil # temp
    movb (%r9), %dil # needs to be register
    movb %dil, (%r8)
    movb %sil, (%r9)
  loop .loop

.end:
  ret
