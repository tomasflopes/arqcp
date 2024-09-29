#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H
int **new_matrix(int lines, int columns);
void free_matrix(int **m, int lines);
void print_matrix(int **m, int lines, int columns);
void fill_matrix(int **m, int lines, int columns, int initval);
#endif

