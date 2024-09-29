.section .text
	.global test_equal	# int test_equal(char*, char*)
test_equal:
  # rdi -> *a
  # rsi -> *b
  xor %rcx, %rcx # %rcx = 0
  movl $1, %eax # as default both strings are not equal

  .loop:
    leaq (%rdi, %rcx), %r8 # character iterated in a
    leaq (%rsi, %rcx), %r9 # character iterated in b

    movb (%r8), %r8b # get value of character
    movb (%r9), %r9b # get value of character
    
    cmpb %r8b, %r9b
    jne .ne
    incq %rcx

    pushq %r9
      orb %r8b, %r9b # if both characters are 0 (strings have ended) then are equal
      testb %r9b,%r9b
    popq %r9
      je .end
  
    andb %r8b, %r9b # if one of the characters is 0 (strings have ended) then return
    testb %r9b,%r9b
    je .ne

    jmp .loop
.end:
  ret
.ne:
  movl $0, %eax
  jmp .end

