#include <stdio.h>

#include "array_sort2.h"

int main()
{
  const int N = 8;

  int vec[] = {6, 1, 5, 2, 12, -3, 7, 0};

  array_sort2(vec, N);

  return 0;
}
