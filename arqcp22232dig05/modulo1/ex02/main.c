#include "copy_vec.h"

int main()
{
  const int N = 3;

  int vec1[] = {1, 2, 3};
  int vec2[N];

  copy_vec(vec1, vec2, N);

  return 0;
}
