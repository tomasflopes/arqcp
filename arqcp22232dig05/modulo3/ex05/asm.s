.section .data
    .global ptrvec, num # long*, short

.section .text
    .global vec_sum, vec_avg    # long vec_sum(void), long vec_avg(void)

vec_sum:
    xor     %eax, %eax          # %rax = 0
    movswl  num(%rip), %ecx     # %ecx = num
    movq    ptrvec(%rip), %rdx  # %rdx = &ptrvec
    
.loop:
    test    %ecx, %ecx              # %ecx & %ecx set flags
    je      .end                    # jump equal
    addq    -8(%rdx, %rcx, 8), %rax # %rax += (%rdx + %rcx * 8)
                                    # 32 most significant bits of rcx are zeroed
                                    # so index is basically %ecx
                                    # 8 bytes (a long) of displacement to the left because
                                    # the last pos of the array is %rdx + num - 1
    loop    .loop                   # jump to .loop %ecx--

.end:
    ret

vec_avg:
    call    vec_sum         # jump to function vec_avg
                            # %rax now has the dividend
    movswq  num(%rip), %rcx # %rcx = num
    test    %rcx, %rcx      # %rcx & %rcx set flags
    je      .zero           # jump equal
    cqto                    # sign-extend %rax to %rdx:%rax
    idivq   %rcx            # signed division %rdx:%rax / %rcx
    ret                     # %rax has the division result

.zero:
    xor     %rax, %rax      # %rax = 0
    ret

