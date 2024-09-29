#include <stdio.h>
#include <stdlib.h>

#include "add_matrixes.h"
#include "matrix_utils.h"

int main()
{
  int y = 2;
  int k = 2;

  int **a = new_matrix(y, k);
  int **b = new_matrix(y, k);

  fill_matrix(a, y, k, 1);
  fill_matrix(b, y, k, 2);

  printf("-- matrix a --\n");
  print_matrix(a, y, k);
  printf("-- matrix b --\n");
  print_matrix(b, y, k);

  int **result = add_matrixes(a, b, y, k);

  printf("-- matrix result --\n");
  print_matrix(result, y, k);

  free_matrix(a, y);
  free_matrix(b, y);
  free_matrix(result, y);
}
