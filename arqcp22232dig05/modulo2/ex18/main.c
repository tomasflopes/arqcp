#include <stdio.h>
#include "asm.h"

int i = 4;

int main(void)
{
  int n = sum();

  printf("sum = %d\n", n);

  return 0;
}
