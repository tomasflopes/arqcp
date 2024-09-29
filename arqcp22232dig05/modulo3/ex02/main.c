#include <stdio.h>
#include "asm.h"

char s1[] = "Hello World";
char s2[11];

char *ptr1 = &s1[0];
char *ptr2 = &s2[0];

int main(void)
{
  str_copy_porto();

  printf("str_copy_porto = %s\n", ptr2);

  return 0;
}
