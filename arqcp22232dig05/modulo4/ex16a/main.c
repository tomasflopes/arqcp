#include <stdio.h>

#include "join_bits.h"

int main() {
  int a = 0xffffffff;
  int b = 0x00000000;
  int pos = 31;
  
  printf("join_bits(%x,%x,%d) = %x\n",a,b,pos,join_bits(a,b,pos));

	return 0;
}

