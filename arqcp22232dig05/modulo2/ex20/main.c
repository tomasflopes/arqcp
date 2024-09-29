#include <stdio.h>
#include "asm.h"

int num = 2;

int main(void)
{
  int n = check_num();

  printf("check_num = %d\n", n);

  return 0;
}
