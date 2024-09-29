.section .data
  .global ptr1
  .global ptr2
  .global ptr3
.section .text
  .global str_cat # void str_cat(void)
str_cat:
  movq ptr1(%rip), %rdx # string 1
  movq ptr2(%rip), %rdi # string 2
  movq ptr3(%rip), %rax # result
  
  .loop:
    # flags to see if both string ended
    movb $0, %r8b
    movb $0, %r9b

    cmpb $0, (%rdx) # check for end of string 1
    jne .concatenate_str1

    cmpb $0, (%rdi) # check for end of string 2
    jne .concatenate_str2

    orb %r8b, %r9b # if both string ended they were not setted to 1
    testb %r9b, %r9b
    je .end # if both are 0 return

  .continue:
    incq %rax
    jmp .loop

.concatenate_str1:
  movb $0xffff, %r8b # set flag
  movb (%rdx), %cl
  incq %rdx # increment to next character
  jmp .concatenate
.concatenate_str2:
  movb $0xffff, %r9b # set flag
  movb (%rdi), %cl
  incq %rdi # increment to next character

.concatenate:
  movb %cl, (%rax)
  jmp .continue
.end:
  movb $0, (%rax)
  ret
