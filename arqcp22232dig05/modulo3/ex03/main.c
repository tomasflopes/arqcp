#include <stdio.h>

#include "asm.h"

char* test = "aaaaffffffffa";   // declare a pointer to a constant
                                // you can't change the content but you can
                                // change to where the pointer points to (test = "new string")

char str1[] = "BadjoOraz";      // declare an array of chars
                                // you can change the content of the array
char str2[100];

char* ptr1 = str1;
char* ptr2 = str2;

int main() {
    printf("char* test  -> %s ; sizeof=%lu\n", test, sizeof(test));
    printf("char str1[] -> %s ; sizeof=%lu\n", str1, sizeof(str1));

	str_copy_porto2();
	printf("%s\n", ptr2);
	return 0;
}


