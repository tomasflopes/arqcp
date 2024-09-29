#include <stdio.h>
#include "asm.h"

int op1 = 3, op2 = 2, op3 = 10;

int main(void)
{
  long long n = sum3ints();

  printf("sum3ints = %lld:0x%llx\n", n, n);

  return 0;
}
