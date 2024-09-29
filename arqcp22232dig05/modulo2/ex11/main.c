#include <stdio.h>

#include "asm.h"

int op1 = 1;
int op2 = -2;

int main() {
	// printf("Enter an integer: ");
	// scanf("%d", &op1);

	// printf("Enter another integer: ");
	// scanf("%d", &op2);

	printf("result = %hhd\n", test_flags());
	
	return 0;
}

