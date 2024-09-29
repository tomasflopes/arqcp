.section .text
	.global locate_greater	# int locate_greater(Student*,int,int*)
locate_greater:
# rdi -> *s
# rsi -> minimum
# rdx -> greater_grades

  # Note: Grades offset:
  # 2 + 1 + 1 (padding) = 4
  leaq 4(%rdi), %rax # get grades
  movq $0, %rcx # i
  movq $0, %r9 # number of greater_grades

  .loop:
    cmpq $5, %rcx # check for end
    je .end

    leaq (%rax,%rcx,4), %r8
    movl (%r8),%r8d

    cmpl %esi,%r8d
    jg .above

    .continue:
      incq %rcx

    jmp .loop

.above:
  leaq (%rdx,%r9,4), %r10
  movl %r8d, (%r10)
  incq %r9 
  jmp .continue
.end:
  movl %r9d, %eax
  ret

