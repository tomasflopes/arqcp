#include <stdio.h>

void print_array(int *arr, int n, char *name)
{
  for (int i = 0; i < n; i++)
    printf("%s[%d]=%d ", name, i, arr[i]);
  printf("\n");
}
