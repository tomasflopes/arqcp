#include <stdio.h>

#include "size_string.h"

int main() {
    char x[] = "I will master ARQCP";
    printf("Size = %lu\n", sizeof(x));
    printf("Size = %u\n", size_string_wrong(x));
    printf("Size = %u\n", size_string_correct(x));

    char y[25] = "I will master ARQCP";
    printf("\nSize = %lu\n", sizeof(y));
    printf("Size = %u\n", size_string_wrong(y));
    printf("Size = %u\n", size_string_correct(y));

    /** Output:
     * Size = 20
     * Size = 8
     * Size = 19
     *
     * Size = 25
     * Size = 8
     * Size = 19
     * 
     * sizeof() returns the total memory allocated for the array.
     * 
     * size_string_wrong() receives the reference of the array through its parameters and returns the size of the pointer
     * which is 8 bytes.
     * 
     * size_string_correct() calculates the size of a string by counting the characters until it finds the NUL character
     * which indicates the end.
     */

    return 0;
}
