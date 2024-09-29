#include <stdio.h>
#include "asm.h"

int num = 4;
int vec[] = {1, 2, 3, 4};
int *ptrvec = &vec[0];

int main(void)
{
  vec_add_two();

  for (int i = 0; i < num; i++)
    printf("arr[%d]=%d\n", i, ptrvec[i]);

  return 0;
}
