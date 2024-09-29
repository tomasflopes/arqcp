.data
    .global ptrvec, num     # long *ptrvec, int num

.text
    .global sum_first_byte  # int sum_first_byte(void)

sum_first_byte:
    movq    ptrvec(%rip), %rdx  # %rdx = ptrvec
    xor     %eax, %eax          # %eax = 0
    movl    num(%rip), %ecx     # %ecx = num

.loop:
    test    %ecx, %ecx
    je      .end
    movsbl  -8(%rdx, %rcx, 8), %esi # %esi = 0x00000000 + least significant byte of
                                    # current pos + sign-extend
    # 8 bytes to the left because last pos of vec is %rdx + num - 1
    # will read the least significant byte because data is stored in memory in little-endian
    addl    %esi, %eax
    loop    .loop                   # %ecx--

.end:
    ret
