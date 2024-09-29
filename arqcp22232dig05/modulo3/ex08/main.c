#include <stdio.h>

#include "asm.h"

long even = -1;
long vec[] = {-1, -1, -1};
long *ptrvec = vec;
int num = 3;

int main() {
    printf("test_even()=%ld\n", test_even());
    printf("vec_sum_even()=%ld\n", vec_sum_even());
    return 0;
}

