.section .data
  .global num
  .equ EVEN_MASK, 0x00000001
  .equ NEGATIVE_MASK, 0x80000000
  .equ BASE, 0x00000004
.section .text
  .global check_num # char check_num(void)

# returns:
#  4 if num is even and negative;
#  5, if num is odd and negative.
#  6, if num is even and positive;
#  7, if num is odd and positive;
# This problem can be solved using bitwise operations
# The base value is 4, 0100
# Then, the second byte is 1 if positive and 0 if negative -> 010_ -> Negative
#                                                          -> 011_ -> Positive
# Then, the first byte is 0 if even and 1 if odd (the remaider of the divison by 2)
#                                                          -> 01_0 -> Even
#                                                          -> 01_1 -> Odd
# Given this we have the four combinations:
# 0100 -> Even negative
# 0101 -> Odd negative
# 0110 -> Even positive
# 0111 -> Even positive
check_num:
  movl num(%rip), %eax # %eax = num

  cltd # sets %edx to %eax signal
  movl $2, %edi # divl needs register as parameter
  idivl %edi # Divides by 2: %edx holds remainder

  andl $NEGATIVE_MASK, %eax # Apply mask to get only the last bit (signal)
  notl %eax # Negating the value of the signal (remember that 1 represents positive and 0 negative)
  shrl $31, %eax # Logical shift to get the last bit and fill the rest with 0
  shll $1, %eax # Shift to correct position

  addl $BASE, %eax # Sum with the base (0100)
  addl %edx, %eax # Sum the remainder of division by 2
  ret
