.section .data
  .equ MINIMUM_APPROVE, 10
.section .text
	.global approved_semester	# int approved_semester(Student*, char)
approved_semester:
# rdi -> *group
#
  # Note: individual_address offset:
  # 2 + 6 (padding) = 8
  movq 8(%rdi), %rax # get address of individual_address
  
  # Note: n_stundets are the first 2 bytes of Student*
  movw (%rdi),%cx # get n_students (no offset)
  movswq %cx, %rcx

  xorl %r8d, %r8d # initialize counter as 0

  testq %rcx,%rcx
  je .end

  .loop:
    pushq %rax
    pushq %rdi
    pushq %rcx
    pushq %r8
      leaq -2(%rax,%rcx,2), %rdi
      movw (%rdi),%di
      call count_bits_one
    popq %r8
    popq %rcx
    popq %rdi
    
    cmpw $MINIMUM_APPROVE, %ax
    jge .approved

    .continue:
      popq %rax
    loop .loop
.end:
  movl %r8d, %eax
  ret
.approved:
  incl %r8d
  jmp .continue

