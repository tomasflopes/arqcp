.data
    .equ    ARR_SIZE, 3
    .equ    ALIGNMENT_1, 4
    .equ    ALIGNMENT_2, 12
.text
    .global fill_s2 # void fill_s2(s2 *s, short vw[3], int vj, char vc[3])
fill_s2:            # rdi  rsi  edx  rcx
    # ***. **** **.. ****
    movl    $ARR_SIZE, %r9d
    xor     %eax, %eax
.loop1:
    movb    (%rcx, %rax, 1), %r8b
    movb    %r8b, (%rdi, %rax, 1)
    incl    %eax
    cmp     %eax, %r9d
    jne     .loop1

    xor     %eax, %eax
.loop2:
    movw    (%rsi, %rax, 2), %r8w
    movw    %r8w, ALIGNMENT_1(%rdi, %rax, 2)
    incl    %eax
    cmp     %eax, %r9d
    jne     .loop2

    movl    %edx, ALIGNMENT_2(%rdi)

    ret

