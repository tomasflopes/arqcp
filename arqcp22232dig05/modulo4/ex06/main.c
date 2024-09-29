#include <stdio.h>

#include "asm.h"

int main() {
  char a[] = "Hello World";
  char b[] = "Hello World";

  printf("Strings are %s\n", test_equal(a,b) == 1 ? "equal" : "not equal");

	return 0;
}

