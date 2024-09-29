#include <stdio.h>

#include "count_bits_one.h"

int main() {
  int x = 0b1001010;

  printf("count_bits_one(%d) = %d\n",x,count_bits_one(x));

	return 0;
}

