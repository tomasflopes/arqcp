#include <stddef.h>
#include <stdio.h>

#include "compare_ignore_case.h"
#include "str_len.h"

char *find_word(char *word, char *initial_addr)
{
  int i = 0;
  int word_len = str_len(word);

  if (word_len == 0)
    return NULL;

  while (*(initial_addr + i) != 0)
  {
    char *occurrence = (initial_addr + i);
    int j = 0;

    while (compare_ignore_case(*(initial_addr + i), *(word + j)) == 1)
    {
      i++;
      j++;
    }

    if (j == word_len)
      return occurrence;

    if (*(initial_addr + i) != 0)
      i++;
  }

  return NULL;
}
