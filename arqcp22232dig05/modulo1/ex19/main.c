#include <stdio.h>

#include "find_word.h"

int main()
{
  char word[] = "xrt";
  char str[] = "aarrxrt xrt xrt xrt";

  find_word(word, str);

  return 0;
}
