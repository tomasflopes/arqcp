.section .data
    .global ptr1
    .equ    OFFSET, 3

.section .text
    .global encrypt, decrypt # int encrypt(void), int decrypt(void)

encrypt:
    movq    ptr1(%rip), %rdi    # pointer to array
    xor     %edx, %edx          # counter of changed occurances to 0

_loop:
    cmpb    $0, (%rdi)  # is num 0?
    je      _end

    cmpb    $'a', (%rdi)
    je      _continue
    cmpb    $' ', (%rdi)
    je      _continue
    
    addb    $OFFSET, (%rdi)  # add 3 to every character
    incl    %edx        # increment occurances

_continue:
    incq    %rdi
    jmp     _loop       # while num is greater than 0

_end:
    movl    %edx, %eax  # return occurances
    ret

decrypt:
    movq    ptr1(%rip), %rcx    # %rcx = ptr1
    xor     %eax, %eax          # %eax = 0
    
.loop:
    cmpb    $0, (%rcx)          # ($rcx) - 0 set flags
    je      .end                # jump equal

    cmpb    $'a', (%rcx)        # compare 'a' with (%rcx)
    je      .continue           # jump equal
    cmpb     $' ', (%rcx)       # compare ' ' with (%rcx)
    je      .continue           # jump equal

    subb    $OFFSET, (%rcx)     # (%rcx) -= 3
    incl    %eax                # %eax++

.continue:
    incq    %rcx                # %rcx++
    jmp     .loop               # jump to .loop

.end:
    ret

