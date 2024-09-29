.data
    .equ    ALIGNMENT, 20
.text
    .global fun3    # short fun3(structB *s)
fun3:               # rdi
    leaq    ALIGNMENT(%rdi), %rax
    ret

