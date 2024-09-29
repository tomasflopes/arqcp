#include <string.h>
#include <math.h>

int string_to_int(char *str)
{
  char *s = str;
  int value = 0;
  int len = strlen(str);

  if (*s == '-')
  {
    s++;
    for (int i = 1; i < len; i++)
    {
      value -= (*s - '0') * (int)pow(10, len - i - 1);
      s++;
    }
  }
  else
  {
    for (int i = 0; i < len; i++)
    {
      value += (*s - '0') * (int)pow(10, len - i - 1);
      s++;
    }
  }

  return value;
}
