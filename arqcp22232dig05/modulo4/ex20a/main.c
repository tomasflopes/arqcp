#include <stdio.h>

#include "sum_multiples_x.h"

int main() {
  char v[] = {1,2,3,4,5,0};
  char *vec = v;
  int x = 0x00000400;

  printf("sum_multiples_x(vec, %x) = %d\n", x,sum_multiples_x(vec,x));

	return 0;
}

