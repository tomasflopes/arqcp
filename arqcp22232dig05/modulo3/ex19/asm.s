.data
    .global ptrgrades, num, ptrfreq # char *ptrgrades, int num, int *ptrfreq

.text
    .global frequencies

frequencies:
    movq    ptrgrades(%rip), %rdx   # %rdx = ptrgrades
    movl    num(%rip), %ecx         # %ecx = num
    movq    ptrfreq(%rip), %rsi     # %rsi = ptrfreq
    movl    $21, %edi               # %edi = 21

.initialize:
    movl    $0, -4(%rsi, %rdi, 4)   # set 0 to current pos in freq vec
    decl    %edi                    # %edi--
    test    %edi, %edi              # %edi & %edi set flags
    jne     .initialize             # jump not equal

.loop:
    test    %ecx, %ecx              # %ecx & %ecx set flags (in case num is initialized w/ 0)
    je      .end                    # jump equal
    movsbl  -1(%rdx, %rcx, 1), %eax # %eax = value of current pos in grades vec
    incl    (%rsi, %rax, 4)         # use %eax as index to freq vec & increment in that pos

.continue:
    loop    .loop       # %ecx--

.end:
    ret

