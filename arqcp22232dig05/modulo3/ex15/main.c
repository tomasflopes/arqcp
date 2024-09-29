#include <stdio.h>

#include "asm.h"

long vec[] = {1, 2, 3, 4};
long *ptrvec = vec;
int num = 4;

int main() {
    printf("%d\n", sum_first_byte());
    return 0;
}

