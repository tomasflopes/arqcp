#include <stdio.h>

#include "asm.h"

int main() {
  int num1 = 2;
  int num2 = 4;
  int smaller = 0;

  printf("smaller = %d\n", smaller);
	printf("sum_smaller() = %d\n", sum_smaller(num1,num2,&smaller));
  printf("smaller = %d\n", smaller);

	return 0;
}

