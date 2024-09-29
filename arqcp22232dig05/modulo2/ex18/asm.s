.section .data
  .equ A, 6
  .equ B, 5
  .global i

.section .text
  .global sum # int sum(void)
  
sum:
  movl i(%rip), %edi
  movl $0, %r8d # counter -> start at 0 because of increment at the start
  movl $0, %esi # accumulator

  loop:
    incl %r8d # increment counter
    movl %r8d, %eax
    cltd
    imull %eax # %eax = i²
    movl $A, %r9d
    imull %r9d # %eax = i²*A
    cltd
    imull %r9d # %eax = i²*A²

    cltd # set %edx to signal bit of %eax
    movl $B, %ecx
    idivl %ecx # %eax = i²*A²/B
    
    addl %eax, %esi # %esi accumulates result

    cmpl %r8d, %edi # compare counter with i

    jne loop # if counter less than i then continue

    movl %esi, %eax # when cycle ends move accumulator to return register
    
    ret
