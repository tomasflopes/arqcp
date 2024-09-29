#include <stdio.h>

#include "asm.h"

int main() {
    int a = 1;
    int *v1 = &a;
    int result = inc_and_square(v1, -10);
    printf("v1=%d; inc_and_square()=%d\n", *v1, result);
    return 0;
}

