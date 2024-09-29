#include "line.h"

void multiplication_table_n(int n)
{
  const unsigned char LIMIT = 10;

  for (unsigned char i = 1; i <= LIMIT; i++)
    line(n, i);
}
