.section .data
  .global ptrvec # pointer to vec
  .global x # short x
  .global num # int num
.section .text
  .global vec_search # short* vec_search(void)
vec_search:
  movq ptrvec(%rip), %rdi # pointer to array
  movl num(%rip), %ecx 
  movq $0, %rsi # index
  movw x(%rip), %r8w # needle

  .loop:
    cmpl %esi, %ecx # check if index = length (num)
    je .end

    leaq (%rdi, %rsi, 2), %rax # get reference of element index = %rsi 
    cmpw (%rax), %r8w # compare current element with needle

    je .found

    incl %esi # as %rsi is set to 0 there is no problem in using subpart of register
    jmp .loop
.end:
  movq $0, %rax # if not found after every iteration, return 0
.found:
  ret
