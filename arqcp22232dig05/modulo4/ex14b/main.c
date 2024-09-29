#include <stdio.h>

#include "asm.h"

int main()
{
  int x = 0b100010101010;
  int pos = 2;

  printf("x = %d\n", x);
  printf("reset_bit(&x,%d) = %d\n", pos, reset_bit(&x, pos));
  printf("x = %d\n", x);

  printf("\n--------------\n");

  x = 0b100010101010;
  pos = 3;

  printf("x = %d\n", x);
  printf("reset_bit(&x,%d) = %d\n", pos, reset_bit(&x, pos));
  printf("x = %d\n", x);

  return 0;
}
