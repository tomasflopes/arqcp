#include <stdio.h>

#include "changes.h"

int main() {
  int x = 0x0f00ff00;

  printf("x = %x\n", x);
  printf("-- changes(&x) --\n");
  changes(&x);
  printf("x = %x\n", x);

	return 0;
}

