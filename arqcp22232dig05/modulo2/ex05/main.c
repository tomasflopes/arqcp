#include <stdio.h>

#include "asm.h"

short s = 0;

int main() {
	short result;
	s = 0xAAFF;
	result = swapBytes();
	printf("s = 0x%hx\nresult = 0x%hx\n\n", s, result);

	s = 0;
        result = swapBytes();
        printf("s = %hd\nresult = %hd\n\n", s, result);

	s = 1;
        result = swapBytes();
        printf("s = %hd\nresult = %hd\n\n", s, result);

	s = 256;
        result = swapBytes();
        printf("s = %hd\nresult = %hd\n\n", s, result);

	s = -1;
	result = swapBytes();
        printf("s = %hd\nresult = %hd\n\n", s, result);

	s = 0xff;
        result = swapBytes();
        printf("s = 0x%hx\nresult = 0x%hx\n\n", s, result);

	s = 0xff00;
        result = swapBytes();
        printf("s = 0x%hx\nresult = 0x%hx\n\n", s, result);

	return 0;
}

