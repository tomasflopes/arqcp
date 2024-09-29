#include <stdio.h>
#include "asm.h"

int const num = 200;
int vec[200];
int *ptrvec = &vec[0];

int main(void)
{
  // fill array
  for (int i = 0; i < num; i++) 
    vec[i] = i;

  unsigned char changed = vec_zero();

  // print result
  for (int i = 0; i < num; i++) 
    printf("vec[%d] = %d\n", i, *(ptrvec+i));

  printf("n of elements changed = %hhu\n", changed);

  return 0;
}
