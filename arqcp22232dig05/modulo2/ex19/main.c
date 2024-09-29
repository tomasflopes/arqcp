#include <stdio.h>

#include "asm.h"

char current = 20;
char desired = 22;

int main() {
	int result = needed_time();
	printf("current = %hhd\ndesire = %hhd\nresult = %d\n\n", current, desired, result);
	
	desired = 20;
	result = needed_time();
	printf("current = %hhd\ndesire = %hhd\nresult = %d\n\n", current, desired, result);

	desired = 18;
	result = needed_time();
	printf("current = %hhd\ndesire = %hhd\nresult = %d\n", current, desired, result);

	return 0;
}

