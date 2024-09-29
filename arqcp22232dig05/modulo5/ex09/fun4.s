.data
    .equ    ALIGNMENT_1, 8
    .equ    ALIGNMENT_2, 4
.text
    .global fun4    # short fun4(structB *s)
fun4:               # rdi
    movq    ALIGNMENT_1(%rdi), %r8
    movw    ALIGNMENT_2(%r8), %ax
    ret

