.section .text
	.global update_grades	# void update_grades(Student*, int*)
update_grades:
# rdi -> *s
# rsi -> *new_grades
#
  # Note: Grades offset:
  # 2 + 1 + 1 (padding) = 4
  leaq 4(%rdi), %rax # get grades
  movb $0, %cl

  .loop:
    movl (%rsi), %r8d
    movl %r8d, (%rax)

    addq $4, %rsi # iterate to next pos
    addq $4, %rax # iterate to next pos

    incb %cl
    cmpb $5, %cl # check for end
    jl .loop

  ret

