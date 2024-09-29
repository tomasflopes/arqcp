.section .text
	.global decifra_string	# void decifra_string(Cifra*, short)
decifra_string:
# rdi -> *c
# rsi -> chave
  # text_cifrado offset -> 0
  # chave offset -> 8
  # tamanho offset -> 8 + 4 + 4(padding) = 16

  # Prologue 
  pushq %rbp
  movq %rsp, %rbp

  movl 8(%rdi), %ecx # tamanho
  movq (%rdi), %r8 # texto_cifrado
  movq 16(%rdi), %r9 # texto_original (output)

  .loop:
    pushq %r8
    pushq %r9
    pushq %rcx
    pushq %rsi
    pushq %rdi
      movw (%r8), %di
      movq %r9, %rdx
      movq %r9, %rcx
      incq %rcx
      call decifra_par
    popq %rdi
    popq %rsi
    popq %rcx
    popq %r9
    popq %r8

    addq $2, %r8 # incrementa o apontador do texto cifrado
    addq $2, %r9 # incrementa o apontador do texto original
  loop .loop

  movb $0, (%r9) # termina a string

  # Epilogue
  movq %rbp, %rsp
  popq %rbp

  ret
