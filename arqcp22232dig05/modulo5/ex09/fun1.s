.data
    .equ    ALIGNMENT, 4
.text
    .global fun1    # short fun1(structB *s)
fun1:               # rdi
    movw    ALIGNMENT(%rdi), %ax
    ret

