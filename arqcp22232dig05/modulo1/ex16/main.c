#include <stdio.h>
#include "where_exists.h"

int main()
{
  char str1[] = "Hello world";
  char str2[] = "Hello";

  where_exists(str2, str1);

  return 0;
}
