.section .data
  .equ SECOND_BYTE_MASK, 0xFF00
  .equ FIRST_BYTE_MASK, 0x00FF
.section .text
	.global decifra_par	# void decifra_par(short, short, char*, char*)
decifra_par:
# rdi -> numero
# rsi -> chave
# rdx -> *c1
# rcx -> *c2
  xorw %si,%di # xor key with number
  movw %di, %si # save result

  andw $FIRST_BYTE_MASK, %di # mask first byte 
  andw $SECOND_BYTE_MASK, %si # mask second byte 

  shrw $8, %si # shift second byte to first byte

  movb %sil, (%rdx) # save first byte
  movb %dil, (%rcx) # save second byte
  
  ret
