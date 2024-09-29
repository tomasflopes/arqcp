#include <stdlib.h>
#include <stdio.h>

int **new_matrix(int lines, int columns) {
    int **pLines = malloc(8*lines);
    for (int i = 0; i < lines; i++) {    
        int *pColumns = malloc(columns * sizeof(int));
        pLines[i] = pColumns;
    }

    return pLines;
}

void free_matrix(int **m, int lines) {
    for (int i = 0; i < lines; i++)
        free(m[i]);

    free(m);
}

void print_matrix(int **m, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++)
            printf("[%d] ", m[i][j]);
        printf("\n");
    }
}

void fill_matrix(int **m, int lines, int columns, int fillval) {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            m[i][j] = fillval;
}

