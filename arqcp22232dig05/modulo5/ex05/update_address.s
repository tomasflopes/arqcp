.section .text
	.global update_address	# void update_address(Student*, char)
update_address:
# rdi -> *s
# rsi -> *new_address
#
  # Note: Address offset:
  # 2 + 1 + 1 (padding) + 4*5 + 60 = 84
  leaq 84(%rdi), %rax # get address 

  .loop:
    movb (%rsi), %r8b 
    movb %r8b, (%rax)

    testb %r8b,%r8b
    je .end

    incq %rsi
    incq %rax

    jmp .loop
.end:
  ret

