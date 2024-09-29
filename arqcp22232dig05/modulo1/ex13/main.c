#include <stdio.h>

#include "where_is.h"

void print_array(int *p, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {
    char *str = "Quantos fantos dantes tantas?";
    char c = 't';
    int r[sizeof(str)];

    where_is(str, c, r);

    return 0;
}
