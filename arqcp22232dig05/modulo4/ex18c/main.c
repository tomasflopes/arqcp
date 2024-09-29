#include <stdio.h>

#include "changes_vec.h"

int main() {
  int vec[] = { 0x0000ff00, 0xff00ff00, 0xffffffff, 0x00000000};
  int num = 4;
  int *ptr_vec = vec;

  for(int i = 0; i < num; i++)
    printf("v[%d] = %x\n", i,vec[i]);
  printf("\n");

  printf("-- changes_vec(ptr_vec, %d) --\n\n",num);
  changes_vec(ptr_vec, num);

  for(int i = 0; i < num; i++)
    printf("v[%d] = %x\n", i,vec[i]);

	return 0;
}

