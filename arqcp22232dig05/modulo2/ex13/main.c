#include <stdio.h>

#include "asm.h"

int length1 = 0;
int length2 = 0;
int height = 0;

int main() {
	length1 = 5;
	length2 = 2;
	height = 3;
	printf("%d\n", getArea());
	return 0;
}

