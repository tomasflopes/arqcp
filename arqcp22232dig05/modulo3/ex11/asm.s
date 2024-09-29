.data
    .global ptrvec, num # int *ptrvec, int num

.text
    .global vec_greater10   # int vec_greater10(void)

vec_greater10:
    xor     %eax, %eax          # %eax = 0
    movq    ptrvec(%rip), %rdx  # %rdx = ptrvec
    movl    num(%rip), %ecx     # %ecx = num

.loop:
    test    %ecx, %ecx              # %ecx & %ecx set flags
    je      .end                    # jump equal
    movl    -4(%rdx, %rcx, 4), %esi # %esi = (%rdx + %rcx * 8)
    # 4 bytes of displacement to the left because last pos of array is %rdx + num - 1
    cmpl    $10, %esi               # compare %esi to 10
    jle     .continue               # jump less or equal
    incl    %eax                    # %eax++

.continue:
    loop    .loop                   # jump to .loop %ecx--

.end:
    ret

