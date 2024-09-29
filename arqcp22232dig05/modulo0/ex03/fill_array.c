#include <stdio.h>

const char N_OF_NUMBERS = 5;

void fill_array(int *vec)
{
  int *v = vec;

  for (int i = 0; i < N_OF_NUMBERS; i++)
  {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    v[i] = x;
  }
}

