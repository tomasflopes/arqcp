.section .data
  .global A
  .global B

.section .text
  .global isMultiple # char isMultiple(void)
  
isMultiple:
  movl A(%rip), %eax # place A in eax
  cltd # extends A to %edx
  movl B(%rip), %ecx # place B in ecx

  testl %ecx, %ecx # sees if B is zero (operation not possible)
  je _zero # if B is zero return 0
  
  # divides %edx:%eax by %ecx (remainder: %edx, quotient: %eax)
  idivl %ecx

  cmpl $0, %edx # Compare if the remainder is zero (if it is, a is multiple)

  sete %al # sets %al as ZF (seted in the previous comparison)

  jmp _end  

_zero:
  movb $0, %al

_end:
  ret
