#include <stdio.h>
#include "fill_array.h"

int main()
{
  int vec[N_OF_NUMBERS];
  fill_array(vec);

  int sum = 0;

  for (int i = 0; i < N_OF_NUMBERS; i++)
  {
    printf("vec[%d] = %d\n", i, *(vec + i));
    sum += *(vec + i);
  }

  double result = sum / N_OF_NUMBERS;
  printf("Average = %.2f\n", result);

  return 0;
}
