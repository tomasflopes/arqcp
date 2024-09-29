#include <stdio.h>

#include "asm.h"

int main() {
    s2 a;
    short vw[3] = {1,2,3};
    char vci[3] = {1,2,3};

    fill_s2(&a, vw, -5, vci);

    printf("a.c =\n");
    for (int i = 0; i < 3; i++) {
        printf("[%d]=%hhd\n", i, a.c[i]);
    }

    printf("\na.w =\n");
    for (int i = 0; i < 3; i++) {
        printf("[%d]=%hd\n", i, a.w[i]);
    }

    printf("\na.j = %d\n", a.j);

    return 0;
}

