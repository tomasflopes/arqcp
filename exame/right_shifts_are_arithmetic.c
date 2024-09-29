#include <stdio.h>

int right_shifts_are_arithmetic() {
  int x = -1;

  if( (x >> 1) == x) return 1;
  return 0;
}

int main() {
  printf("right_shifts_are_arithmetic() = %d\n", right_shifts_are_arithmetic());
  return 0;
}
