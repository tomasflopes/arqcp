#include <stdio.h>

#include "asm.h"

int main() {
  int a = 1;
  int b = 0;
  int c = 2;

  printf("calc(%d,%p,%d) = %d\n", a,&b,c, calc(a,&b,c));

	return 0;
}

