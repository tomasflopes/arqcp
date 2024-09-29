#include <stdio.h>
#include "asm.h"

int num = 5;
short v[] = { 1,2,3,4,5 };
short *ptrvec = &v[0];
short x = 3;

int main(void)
{

  printf("vec_search() = element found @ %p\n", vec_search());

  return 0;
}
