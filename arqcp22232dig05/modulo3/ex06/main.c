#include <stdio.h>
#include "asm.h"

char s[] = "Hello World";
char *ptr1 = &s[0];

int main(void)
{

  printf("encrypt() = %d ptr = %s\n", encrypt(), s);

  return 0;
}
