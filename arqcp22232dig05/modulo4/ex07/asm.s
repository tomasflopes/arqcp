.text
    .global count_odd   # int count_odd(char *vec, int n)
count_odd:
    # prologue
    pushq   %rbp
    movq    %rsp, %rbp

    xor     %eax, %eax  # %eax = 0
    movl    %esi, %ecx
.loop:
    test    %ecx, %ecx          # exit the loop
    je      .end
    movb    -1(%rdi, %rcx, 1), %dl
    and     $1, %dl
    je      .continue
    incl    %eax
.continue:
    loop    .loop
    
.end:
    # epilogue
    movq    %rbp, %rsp
    popq    %rbp
    ret

