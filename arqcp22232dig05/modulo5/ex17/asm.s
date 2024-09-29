.data
    .equ    STRUCT_SIZE, 5  # 2^5 = 32
    .equ    ALIGNMENT, 24   # unionB ub on structA
.text
    .global return_unionB_b # char return_unionB_b(structA **matrix, int i, int j)
return_unionB_b:        # rdi  esi  edx
    # return matrix[i][j].ub.b
    sall    $STRUCT_SIZE, %edx      # column * sizeof(structA)
    addq    (%rdi, %rsi, 8), %rdx   # pointer of matrix[i] + offset to the column
    movb    ALIGNMENT(%rdx), %al    # char b
    ret

