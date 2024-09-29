#include <stdio.h>

#include "asm.h"

long vec[] = {1, 2, 3, 4};
long* ptrvec = vec;
short num = 4;

int main() {
    printf("sum=%ld\n", vec_sum());
    printf("avg=%ld\n", vec_avg());
    return 0;
}

