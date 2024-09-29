#include <stdio.h>

#include "f.h"
#include "f2.h"
#include "f3.h"
#include "f4.h"

int i = 0, j = 0, h = 0, g = 0, r = 0;
const char RESET_VALUES = 1; // 0 - Do not reset values, other value - Reset values in every function call

void reset_values()
{
  if (RESET_VALUES)
    i = 10, j = 20, h = 1, g = 0, r = 0;
}

int fc()
{
  if (i == j)
    h = i - j + 1;
  else
    h = i + j - 1;
  return h;
}

int fc2()
{
  if (i > j)
    i = i - 1;
  else
    j = j + 1;
  h = j * i;
  return h;
}

int fc3()
{
  if (i >= j)
  {
    h = i * j;
    g = i + 1;
  }
  else
  {
    h = i + j;
    g = i + j + 2;
  }
  r = g / h;
  return r;
}

int fc4()
{
  if (i + j < 10)
    h = 4 * i * i;
  else
    h = j * j / 3;
  return h;
}

int main()
{
  reset_values();
  printf("f (assembly) = %d\n", f());
  reset_values();
  printf("f (c) = %d\n\n", fc());

  reset_values();
  printf("f2 (assembly) = %d\n", f2());
  reset_values();
  printf("f2 (c) = %d\n\n", fc2());

  reset_values();
  printf("f3 (assembly) = %d\n", f3());
  reset_values();
  printf("f3 (c) = %d\n\n", fc3());

  reset_values();
  printf("f4 (assembly) = %d\n", f4());
  reset_values();
  printf("f4 (c) = %d\n", fc4());

  return 0;
}
