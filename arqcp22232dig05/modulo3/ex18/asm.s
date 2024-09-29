.section .data
  .global ptrsrc
  .global ptrdest
  .global num
.section .text
  .global sort_without_reps # void sort_without_reps(void)
  .global array_sort # void array_sort
sort_without_reps:

  movl num(%rip), %ecx # sets most significant bytes as 0

  testl %ecx, %ecx # check for empty array
  je .end

  pushq %rcx # save value of %ecx

  call array_sort # array_sort(), now the array is sorted

  popq %rcx

  movq ptrsrc(%rip), %rdi
  movq ptrdest(%rip), %rdx
  movl $1, %eax # number of unique elements

  movw (%rdi), %r8w
  movw %r8w, (%rdx)

  cmpl $1, %ecx
  je .end

  addq $2, %rdi # move to next position of ptrsrc array
  decl %ecx

  .loop:
     movw (%rdi), %r8w
     cmpw (%rdx), %r8w
     je .continue

     addq $2, %rdx
     movw %r8w, (%rdx)

     incl %eax

     .continue:
       addq $2, %rdi 

  loop .loop

.end:
  ret
