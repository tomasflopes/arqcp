#include <stddef.h>

#include "../ex19/find_word.h"

void find_all_words(char *str, char *word, char **addrs)
{
  int j = 0;

  while (str != 0)
  {
    *(addrs + j) = find_word(word, str);
    if (*(addrs + j) == NULL)
      return;
    str = *(addrs + j) + 1;
    j++;
  }
}
