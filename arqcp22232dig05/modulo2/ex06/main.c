#include <stdio.h>

#include "asm.h"

// short s = 0;
char byte1 = 0;
char byte2 = 0;

int main() {
	short result;

	// printf("Enter a byte: ");
	// scanf("%hhd", &byte1);
	
	// printf("Enter another byte: ");
	// scanf("%hhd", &byte2);

	byte1 = 2;
	byte2 = 5;

	result = concatBytes();
	printf("\nresult = %hd\n\n", result);
	
	return 0;
}

