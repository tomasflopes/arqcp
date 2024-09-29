#include <stdlib.h>

int **add_matrixes(int **a, int **b, int y, int k)
{
  int **lines = malloc(y * sizeof(*a));
  for (int i = 0; i < y; i++)
  {
    int *columns = malloc(k * sizeof(**a));
    for (int j = 0; j < k; j++)
      *(columns + j) = a[i][j] + b[i][j];
    *(lines + i) = columns;
  }

  return lines;
}
