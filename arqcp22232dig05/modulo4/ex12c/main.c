#include <stdio.h>

#include "vec_count_bits_one.h"

int main() {
  short vec[] = {1,2,3};
  int num = 3;

  short *ptr = vec;

  printf("vec_count_bits_one(*ptr,%d) = %d\n", num, vec_count_bits_one(ptr,num));

	return 0;
}

