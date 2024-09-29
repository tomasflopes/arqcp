#include <stdio.h>

#define N 5
const int SEARCH_VALUE = 3;

int count(int *vec, int n, int value)
{
  int *v = vec;
  unsigned char counter = 0;

  for (int i = 0; i < n; i++)
    if (v[i] == value)
      counter++;

  return counter;
}

int main()
{
  int vec[N] = {1, 2, 3, 4, 5};

  int result = count(vec, N, SEARCH_VALUE);

  printf("The value %d appears %d times.\n", SEARCH_VALUE, result);

  return 0;
}
