#include <stdio.h>
#include "asm.h"

int num = 12;

short v1[] = {1,1,1,2,2,3,4,5,1,2,7,8};
short v2[12];

short *ptrsrc = v1;
short *ptrdest = v2;

int main(void)
{
  printf("-- Before --\n");
  printf("  -- v1 (ptrsrc) --\n");
  printf("  ");
  for(int i = 0; i < num; i++)
    printf("%d ", v1[i]);

  printf("\n  -- v2 (ptrdest) --\n");
  printf("  ");
  for(int i = 0; i < num; i++)
    printf("%d ", v2[i]);
  // -------------------------------------------------
  sort_without_reps();
  // -------------------------------------------------
  printf("\n\nCalling sort_without_reps() ...\n\n");

  printf("  -- v1 (ptrsrc) --\n");
  printf("  ");
  for(int i = 0; i < num; i++)
    printf("%d ", v1[i]);

  printf("\n  -- v2 (ptrdest) --\n");
  printf("  ");
  for(int i = 0; i < num; i++)
    printf("%d ", v2[i]);

  printf("\n");

  return 0;
}
