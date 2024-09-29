.text
    .global greatest    # int greatest(int a, int b, int c, int d)
greatest:
    # prologue
    pushq   %rbp
    movq    %rsp, %rbp

    movl    %edi, %eax
    cmpl    %eax, %esi
    cmovgl  %esi, %eax
    cmpl    %eax, %edx
    cmovgl  %edx, %eax
    cmpl    %eax, %ecx
    cmovgl  %ecx, %eax

    # epilogue
    movq    %rbp, %rsp
    popq    %rbp
    ret

