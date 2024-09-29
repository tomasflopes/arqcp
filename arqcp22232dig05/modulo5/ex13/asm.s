.text
    .global count_odd_matrix    # int count_odd_matrix(int **m, int y, int k)
count_odd_matrix:       # rdi, esi, edx
    dec     %esi        # i - 1
    xor     %eax, %eax

.loop1:
    movl    %edx, %ecx              # make a copy of the num of columns
    movq    (%rdi, %rsi, 8), %r8    # %r8 = m[i]
.loop2:
    dec     %ecx
    movl    (%r8, %rcx, 4), %r9d    # %r9d = m[i][j]
    and     $1, %r9d
    jnz     .inc                    # 1 -> is odd -> increment
.continue:
    test    %ecx, %ecx
    jne     .loop2                  # j == 0 -> next line
    dec     %esi
    jl      .end                    # i == 0 -> end
    jmp     .loop1                  # else next line

.inc:
    incl    %eax
    jmp     .continue

.end:
    ret

