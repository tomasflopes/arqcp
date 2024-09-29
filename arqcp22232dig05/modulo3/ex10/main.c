#include <stdio.h>
#include "asm.h"

char *ptr1 = "Hello World";
char *ptr2 = "Hello World";
char s[] = "";

char *ptr3 = &s[0];

int main(void)
{
  str_cat();
  printf("str_cat() = %s\n", ptr3);

  return 0;
}
