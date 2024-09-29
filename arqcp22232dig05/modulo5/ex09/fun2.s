.data
    .equ    ALIGNMENT, 20
.text
    .global fun2    # short fun2(structB *s)
fun2:               # rdi
    movw    ALIGNMENT(%rdi), %ax
    ret

