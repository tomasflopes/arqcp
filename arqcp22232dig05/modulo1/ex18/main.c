#include <stdio.h>
#include "compress_shorts.h"

#define N 4 // Length of the short vector

int main()
{
  short a[] = {0x1111, 0x1234, 0x5555, 0x4444};
  int b[N / 2] = {0};

  compress_shorts(a, N, b);

  return 0;
}
