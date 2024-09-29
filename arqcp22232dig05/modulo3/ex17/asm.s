.data
    .global ptrvec, num     # short *ptrvec, int num

.text
    .global array_sort      # void array_sort(void)

array_sort:
    movq    ptrvec(%rip), %rdx  # %rdx = ptrvec
    movl    num(%rip), %ecx     # %ecx = num

.outerloop:
    test    %ecx, %ecx              # %ecx & %ecx set flags
    je      .end                    # jump equal zf=1
    xor     %esi, %esi              # %esi = 0 upper 32 bits also zeroed
    movw    -2(%rdx, %rcx, 2), %ax  # %ax holds the last pos
    xor     %r8d, %r8d              # %r8d = 0 (flag)

.innerloop:
    cmpw    (%rdx, %rsi, 2), %ax    # compare %ax (vec[i]) w/ vec[j]
    jle     .continue               # jump less or equal
    movl    $1, %r8d                # flag
    movw    (%rdx, %rsi, 2), %di    # %di = (vec[j])
    movw    %di, -2(%rdx, %rcx, 2)  # (vec[i]) = %di
    movw    %ax, (%rdx, %rsi, 2)    # (vec[j]) = %ax
    movw    %di, %ax                # update %ax

.continue:
    incl    %esi        # %esi++
    cmpl    %esi, %ecx  # compare %ecx to %esi
    jne     .innerloop  # jump not equal
    test    %r8d, %r8d
    je      .end
    loop    .outerloop  # %ecx--

.end:
    ret

