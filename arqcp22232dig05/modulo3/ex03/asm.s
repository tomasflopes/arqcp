.section .data
    .global ptr1, ptr2    # char*

.section .text
    .global str_copy_porto2 # void str_copy_porto2(void)

str_copy_porto2:
    movq	ptr1(%rip), %rcx    # rcx = ptr1
    movq	ptr2(%rip), %rdx    # rdx = ptr2
.loop:
    movb	(%rcx), %al         # al holds the value of the current character pointed by rcx
        
    # check o & O
    cmp     $'o', %al
    je      .add_offset
    cmp     $'O', %al
    je      .add_offset

.continue:
    movb    %al, (%rdx)         # copy al to where the other array
    
    # check .end of string
    test    %al, %al            # al & al set flags
    je      .end                 # jump equal

    incq    %rcx
    incq    %rdx
    jmp     .loop

.add_offset:
    addb    $6, %al
    jmp     .continue

.end:
    ret

