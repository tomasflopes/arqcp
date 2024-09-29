#include <stdio.h>
#include "asm.h"

char s[] = "Hello World";
char *ptr1 = s;

int main(void) {
  printf("encrypt() = %d ptr = %s\n", encrypt(), s);
  printf("decrypt() = %d ptr = %s\n", decrypt(), s);

  return 0;
}
