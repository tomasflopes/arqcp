#include <stdio.h>
#include <stdlib.h>

#include "new_str.h"

int main() {

  char str[80] = "Hello World";
  char* new = new_str(str);

  printf("%s\n", new);
  printf("size of str = %lu\n", sizeof str);
  printf("size of new_str = %lu\n", sizeof new);

  free(new);
}

