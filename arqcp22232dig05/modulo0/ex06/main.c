#include <stdio.h>
#include "../ex05/string_to_int.h"

int main()
{
  char a[25];
  char b[25];

  printf("Insert a number: ");
  scanf("%s", a);
  printf("Insert a number: ");
  scanf("%s", b);

  int x = string_to_int(a);
  int y = string_to_int(b);

  double avg = (float)(x + y) / 2;

  printf("The average between %d and %d is: %.2f\n", x, y, avg);

  return 0;
}
