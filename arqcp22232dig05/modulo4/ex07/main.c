#include <stdio.h>

#include "asm.h"

int main() {
    char vec[] = {1,2,3,4};
    int n = 4;
    printf("%d\n", count_odd(vec, n));
    return 0;
}

