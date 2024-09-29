#include <stdio.h>
#include "asm.h"

int A = 2, B = 4, C = 3, D = 5;

int main(void)
{
  char n = compute();

  printf("compute = %d:\n", n);

  return 0;
}
