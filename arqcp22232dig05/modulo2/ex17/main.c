#include <stdio.h>

#include "asm.h"

int op1 = 1;
int op2 = -4;

int main() {
	int result = sum();
	printf("%d + %d = %d\n", op1, op2, result);

	result = subt();
	printf("%d - %d = %d\n", op1, op2, result);

	result = mult();
	printf("%d * %d = %d\n", op1, op2, result);
	
	op1 = 21;
	op2 = 4;
	result = div();
	printf("%d / %d = %d\n", op1, op2, result);
	
	op2 = 0;
	result = div();
	printf("%d / %d = %d\n", op1, op2, result);

	result = mod();
	printf("%d %% %d = %d\n", op1, op2, result);
	
	op2 = 5;
	result = mod();
	printf("%d %% %d = %d\n", op1, op2, result);

	op1 = 4;
	result = power_2();
	printf("%d ^ 2 = %d\n", op1, result);

	op1 = 3;
	result = power_3();
	printf("%d ^ 3 = %d\n", op1, result);

	return 0;
}

