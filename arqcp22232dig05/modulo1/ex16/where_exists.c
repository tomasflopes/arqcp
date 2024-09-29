#include <stddef.h>
#include <stdio.h>
#include "str_len.h"

char *where_exists(char *str1, char *str2)
{
  char *occurrence;
  // Creating a temporary pointer
  char *s = str2;

  int i = 0;
  int str1_len = str_len(str1);

  if (str1_len == 0)
    return NULL;

  while (*s != 0) // While the string doesn't end (ASCII code of [NULL] character = 0)
  {
    occurrence = s;

    while (*s == *(str1 + i))
    {
      s++;
      i++;
    }
    if (i == str1_len)
      return occurrence;

    i = 0;

    if (*s != 0)
      s++;
  }

  return NULL;
}
