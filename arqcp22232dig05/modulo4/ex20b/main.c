#include <stdio.h>

#include "asm.h"

int main() {
  char v[] = {1,1,0};
  char *vec = v;
  int x = 0x100;

  printf("sum_multiples_x(vec, %x) = %d\n", x,sum_multiples_x(vec,x));

	return 0;
}

