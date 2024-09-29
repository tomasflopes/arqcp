#include <stdio.h>
#include "asm.h"

int num = 9;

short v[] = {5,2,3,4,5,1,2,7,8};
short *ptrvec = v;

int main(void)
{
  printf("count_max() = %d\n", count_max());

  return 0;
}
