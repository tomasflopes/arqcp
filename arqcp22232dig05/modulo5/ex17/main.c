#include <stdlib.h>
#include <stdio.h>

#include "asm.h"

structA **new_matrix(int lines, int columns);
void free_matrix(structA **m, int lines);

int main() {
    int lines = 4, columns = 3;
    structA **m = new_matrix(lines, columns);
    int i = 0, j = 0;
    m[i][j].ub.b = 5;
    printf("sizeof(structA)=%lu\n", sizeof(structA));
    printf("sizeof(structA)=%lu\n", sizeof(short int));
    printf("return_unionB_b()=%hhd\n", return_unionB_b(m, i, j));
    free_matrix(m, lines);
    return 0;
}

structA **new_matrix(int lines, int columns) {
    structA **m = malloc(8 * lines);
    for (int i = 0; i < lines; i++)
        m[i] = malloc(columns * sizeof(structA));
    return m;
}

void free_matrix(structA **m, int lines) {
    for (int i = 0; i < lines; i++)
        free(m[i]);
    free(m);
}

