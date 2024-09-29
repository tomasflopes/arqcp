#include "multiplication_table_n.h"

void multiplication_table(void)
{
  const unsigned char LIMIT = 10;

  multiplication_table_n(1);

  for (unsigned char i = 2; i <= LIMIT; i++)
  {
    printf("\n");
    multiplication_table_n(i);
  }
}
