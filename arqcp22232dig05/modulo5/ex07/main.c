#include <stdio.h>

#include "asm.h"

int main() {
    s1 a;
    char c1 = -30;
    int i1 = -40;
    char c2 = -50;
    int i2 = -60;
    fill_s1(&a, i1, c1, i2, c2);
    printf("a.c = %hhd\n", a.c);
    printf("a.i = %d\n", a.i);
    printf("a.d = %hhd\n", a.d);
    printf("a.j = %d\n", a.j);
    return 0;
}

