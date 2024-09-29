#include <stdio.h>
#include "asm.h"
#include "vec_diff.h"

int num = 10;
int v[] = {1,2,3,4,5,6,7,5,6,8};
int x = 8;
int *ptrvec = v;

int main(void)
{

  for (int i = 0; i < num;i++) {
    x = v[i]; 
    printf("x = %d exists() = %d \n",x, exists());
  }
  printf("number of unique numbers: %d\n", vec_diff());

  return 0;
}
