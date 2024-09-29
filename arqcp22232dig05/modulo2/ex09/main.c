#include <stdio.h>

#include "asm.h"

int A = 5;
short B = -4;
char C = 19;
char D = -10;

int main() {
	long result = 0;

	// printf("A = ");	
	// scanf("%d", &A);

	// printf("B = ");	
	// scanf("%hd", &B);

	// printf("C = ");	
	// scanf("%hhd", &C);
	
	// printf("D = ");	
	// scanf("%hhd", &D);

	result = sum_and_subtract();
	printf("\n%hhd + %d - %hhd + %hd = %ld\n", C, A, D, B, result);

	return 0;
}

