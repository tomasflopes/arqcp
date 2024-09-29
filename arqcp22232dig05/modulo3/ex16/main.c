#include <stdio.h>
#include "asm.h"

int num = 1;

char v1[] = {1};
char v2[] = {2};

char *ptr1 = v1;
char *ptr2 = v2;

int main(void)
{
  printf("-- Starting arrays --\n");

  for(int i = 0; i < num; i++)
    printf("v1[%d]=%d ", i,v1[i]);
  printf("\n");

  for(int i = 0; i < num; i++)
    printf("v2[%d]=%d ", i,v2[i]);
  printf("\n");

  swap();

  printf("swapping...\n");


  for(int i = 0; i < num; i++)
    printf("v1[%d]=%d ", i,v1[i]);
  printf("\n");

  for(int i = 0; i < num; i++)
    printf("v2[%d]=%d ", i,v2[i]);
  printf("\n");

  return 0;
}
