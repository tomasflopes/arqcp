#include <stdio.h>

#include "asm.h"
#include "matrix_utils.h"

void test_matrix(int **m, int lines, int columns);

int main() {
    int lines = 3, columns = 4;
    int **m = new_matrix(lines, columns);
    test_matrix(m, lines, columns);
    print_matrix(m, lines, columns);
    printf("count_odd_matrix=%d\n\n", count_odd_matrix(m, lines, columns));
    free_matrix(m, lines);
    
    lines = 2, columns = 1;
    m = new_matrix(lines, columns);
    m[0][0] = 1;
    m[1][0] = 1;
    print_matrix(m, lines, columns);
    printf("count_odd_matrix=%d\n", count_odd_matrix(m, lines, columns));
    free_matrix(m, lines);

    return 0;
}

void test_matrix(int **m, int lines, int columns) {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            m[i][j] = i * lines + i + j;
}

