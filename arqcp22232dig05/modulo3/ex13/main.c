#include <stdio.h>

#include "asm.h"

short vec[] = {10, 20, -30, 40, 0};
short *ptrvec = vec;
unsigned short num = 5;

int main() {
    keep_positives();
    for (int i = 0; i < num; i++) {
        printf("vec[%d]=%hd\n", i, ptrvec[i]);
    }
    return 0;
}

