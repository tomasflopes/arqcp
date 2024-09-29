.data
    .global even            # long even
    .global ptrvec, num     # long *ptrvec, int num

.text
    .global test_even, vec_sum_even # long test_even(void), long vec_sum_even(void)

test_even:
    movq    even(%rip), %rax    # %rax = even
    and     $0x1, %rax          # a number is even if its least significant byte
                                # is 0, even for negative numbers
    xor     $0x1, %rax          # apply a mask to reverse the least significant byte
    ret

vec_sum_even:
    movq    ptrvec(%rip), %rsi  # %rsi = ptrvec
    xor     %rdi, %rdi          # %rdi = 0
    movl    num(%rip), %ecx     # %ecx = num (32 most significant bits are zeroed)
    # movq    even(%rip), %r10    # %r10 = even (save the original value)

.loop:
    test    %ecx, %ecx                      # %ecx & %ecx set flags
    je      .end                            # jump equal
    movq    -8(%rsi, %rcx, 8), %r9           # %r9 = (%rsi + %rcx * 8)
    movq    %r9, even(%rip)                 # even = %9
    # 8 bytes of displacement to the left because last pos of array is %rsi + num - 1
    call    test_even                       # jump to function test_even
    test    %rax, %rax                      # %rax & %rax set flags
    je      .continue                       # jump equal
    addq    %r9, %rdi                       # %rdi += %r9 (even)

.continue:
    loop    .loop                           # jump to .loop %ecx--

.end:
    # movq    %r10, even(%rip)     # even = %r10 (restore the original value)
    movq    %rdi, %rax          # %rax = %rdi
    ret

