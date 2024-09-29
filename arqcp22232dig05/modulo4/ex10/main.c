#include <stdio.h>

#include "call_incr.h"

int main()
{
  short w = 0;

  printf("call_incr(%d) = %d\n", w, call_incr(w));

  return 0;
}
