.text
    .global cube    # long cube(int x)
cube:
    # prologue
    pushq   %rbp
    movq    %rsp, %rbp

    movslq  %edi, %rax  # convert number to 64 bits
    movq    %rax, %rdx  # %rdx = x but 64 bits
    imulq   %rax, %rdx
    imulq   %rdx, %rax
    
    # epilogue
    movq    %rbp, %rsp
    popq    %rbp
    ret

