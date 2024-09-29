#include <stdio.h>

#include "find_matrix.h"
#include "matrix_utils.h"

int main() {
    int lines = 3, columns = 4;
    int find = -1;
    int **m = new_matrix(lines, columns);
    fill_matrix(m, lines, columns, 5);

    print_matrix(m, lines, columns);
    printf("\nFound %d = %s\n\n", find, find_matrix(m, lines, columns, find) == 1 ? "yes" : "no");

    m[1][3] = find;
    print_matrix(m, lines, columns);
    printf("\nFound %d = %s\n", find, find_matrix(m, lines, columns, find) == 1 ? "yes" : "no");

    free_matrix(m, lines);
    return 0;
}

