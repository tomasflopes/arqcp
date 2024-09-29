#include <stdio.h>
#include "asm.h"

int A = 20, B = 10;

int main(void)
{
  char n = isMultiple();

  printf("isMultiple = %d\n", n);

  return 0;
}
