#include <stdio.h>

#include "asm.h"

char *ptrgrades;
int num = 5;
int *ptrfreq;

int main() {
    char grades[] = {20, 19, 0, 10, 20};
    ptrgrades = grades;
    int freq[21] = {[0 ... 20] = 5};
    ptrfreq = freq;
    frequencies();

    for (int i = 0; i < 21; i++) {
        printf("freq[%d]=%d\n", i, ptrfreq[i]);
    }

    return 0;
}

