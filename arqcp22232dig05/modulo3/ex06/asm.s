.section .data
  .global ptr1
.section .text
  .global encrypt # int encrypt(void)

encrypt:
  movq ptr1(%rip), %rdi # pointer to array
  xor %edx, %edx # counter of changed occurances to 0

  _loop:
    cmpb $0, (%rdi) # is num 0?
    je _end

    cmpb $'a', (%rdi)
    je _continue
    cmpb $' ', (%rdi)
    je _continue
    
    addb $3, (%rdi) # add 3 to every character
    incl %edx # increment occurances

    _continue:
      incq %rdi
      jmp _loop # while num is greater than 0

_end:
  movl %edx, %eax # return occurances
  ret
