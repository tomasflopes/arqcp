#include <stdio.h>

#include "matrix_utils.h"

int main() {
    int lines = 4, columns = 6;
    int **matrix = new_matrix(lines, columns);
    fill_matrix(matrix, lines, columns, -1);
    print_matrix(matrix, lines, columns);
    free_matrix(matrix, lines);
    return 0;
}

