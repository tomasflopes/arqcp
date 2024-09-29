.text
    .global fill_s1 # void fill_s1(s1 *s, int vi, char vc, int vj, char vd)
fill_s1:            # rdi  esi  dl  ecx  r8b
    # *... **** *... ****
    
    movb    %dl, (%rdi)
    movl    $1, %eax
    movl    %esi, (%rdi, %rax, 4)
    incl    %eax
    movb    %r8b, (%rdi, %rax, 4)
    incl    %eax
    movl    %ecx, (%rdi, %rax, 4)

    ret

