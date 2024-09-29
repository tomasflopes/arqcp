#include <stdio.h>
#include "string_to_int.h"

int main()
{
  char x[25];

  printf("Insert a number: ");
  scanf("%s", x);

  int n = string_to_int(x);
  printf("The number typed is: %d\n", n);

  return 0;
}
