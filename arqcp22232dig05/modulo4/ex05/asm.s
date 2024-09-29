.text
    .global inc_and_square  # int inc_and_square(int *v1, int v2)
inc_and_square:
    # prologue
    pushq   %rbp
    movq    %rsp, %rbp
    
    incl    (%rdi)
    
    # return the square of %rsi
    movl    %esi, %eax
    imull   %esi, %eax

    # epilogue
    movq    %rbp, %rsp
    popq    %rbp
    ret

