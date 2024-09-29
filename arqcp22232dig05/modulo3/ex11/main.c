#include <stdio.h>

#include "asm.h"

int vec[] = {1, 2, 3, 4, 5};
int *ptrvec = vec;
int num = 5;

int main() {
    printf("vec_greater10()=%d\n", vec_greater10());
    return 0;
}

