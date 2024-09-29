#include <stdio.h>

#include "asm.h"

int main() {
  int x = 0b1010101000101;

  printf("count_bits_one(%d) = %d\n", x, count_bits_one(x));

	return 0;
}

