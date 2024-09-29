#include <stdio.h>
#include "sum.h"

int main()
{
  const int MAX_SUM = 10;
  int i = 0, total = 0;

  do
  {
    total = sum(++i, i);
    printf("total = %d\n", total);
  } while (total < MAX_SUM);

  return 0;
}
