#include <stdlib.h>

char *new_str(char str[80]) 
{
  int size = 0;
  while(*(str+size) != 0)
    size++;

  size++; // account for \0 in the end
  char *new = malloc(size);

  for(int i = 0; i < size; i++) 
    *(new+i) = *(str+i);

  return new;
}
