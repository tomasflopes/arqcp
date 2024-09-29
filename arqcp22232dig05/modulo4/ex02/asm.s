.section .text
	.global sum_n2	# long sum_n2(int)

sum_n2:
  xor %rax, %rax # %rax = 0
  cmpl $0, %edi # check if n <= 0
  jle .end
  # %edi = n
  movl %edi, %ecx # %ecx = n

  .loop: # the loop will execute one last time without change as %ecx = 0
    pushq %rax

    movq %rcx, %rax
    imulq %rax # %rax = %rax²
    movq %rax, %rsi # %rsi = %rax²

    popq %rax

    addq %rsi, %rax
  loop .loop
.end:
	ret

