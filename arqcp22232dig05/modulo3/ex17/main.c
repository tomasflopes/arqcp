#include <stdio.h>

#include "asm.h"

short vec[] = {3,1,4,2};
short *ptrvec = vec;
int num = 4;

int main() {
    array_sort();
    for (int i = 0; i < num; i++) {
        printf("vec[%d]=%hd\n", i, vec[i]);
    }
    return 0;
}

