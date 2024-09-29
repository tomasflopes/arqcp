#include <stdio.h>

#include "mixed_sum.h"

int main()
{
  int a = 0xffffffff;
  int b = 0x00000000;
  int pos = 31;

  printf("mixed_sum(%x,%x,%d) = %x\n", a, b, pos, mixed_sum(a, b, pos));

  return 0;
}
