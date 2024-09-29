.data
    .global ptrvec, num     # short *ptrvec, unsigned short num

.text
    .global keep_positives  # void keep_positives(void)

keep_positives:
    movq    ptrvec(%rip), %rdx  # %rdx = ptrvec
    movzwl  num(%rip), %ecx     # %ecx = num
    xor     %eax, %eax          # %eax = 0

.loop:
    cmp     %eax, %ecx              # compare %ecx to %eax set flags
    jle     .end                    # jump less or equal
    movw    (%rdx, %rax, 2), %si    # %si = pos of vec with displacement
    cmpw    $0, %si                 # %si - 0 set flags
    jns     .continue               # jump not negative
    movw    %ax, (%rdx, %rax, 2)    # current pos of vec = %eax (index)

.continue:
    inc     %eax                    # %eax++
    jmp     .loop

.end:
    ret

