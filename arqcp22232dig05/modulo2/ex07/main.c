#include <stdio.h>

#include "asm.h"

short s1 = 0;
short s2 = 0;

int main() {
	short result;

	// printf("Enter a short: ");
	// scanf("%hd", &s1);
	
	// printf("Enter another short: ");
	// scanf("%hd", &s2);
	
	s1 = 4;
	s2 = -4;

	result = crossSumBytes();
	printf("\nresult = %hd\n\n", result);
	
	return 0;
}

