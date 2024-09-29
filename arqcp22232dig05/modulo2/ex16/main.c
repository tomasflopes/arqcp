#include <stdio.h>
#include "asm.h"

long num = 2;

int main(void)
{
  int n = steps();

  printf("steps = %d\n", n);

  return 0;
}
