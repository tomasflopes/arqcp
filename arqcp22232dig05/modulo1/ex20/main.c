#include <stdio.h>
#include <stddef.h>

#include "find_all_words.h"
#include "../ex16/str_len.h"

int main()
{
  char str[] = "Hello world hello hello hel";
  char word[] = "hello";

  // In the worst case the word is contained in all positions of str
  char *result[str_len(str)];

  find_all_words(str, word, result);

  return 0;
}
