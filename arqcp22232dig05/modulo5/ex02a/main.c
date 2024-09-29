#include <stdio.h>
#include <string.h>

int main(void){
  union union_u1{
    char vec[32];
    float a;
    int b;
  } u;

  union union_u1 * ptr = &u;

  strcpy(ptr->vec, "arquitectura de computadores");
  printf("[1]=%s\n", ptr->vec); // produces expected output
  ptr->a = 123.5;
  printf("[2]=%f\n", ptr->a); // produces expected output
  ptr->b = 2;
  printf("[3]=%d\n", ptr->b); // produces expected output
  printf("[1]=%s\n", ptr->vec); // last used value was b, no output
  printf("[2]=%f\n", ptr->a); // last used value was b, 0 as output
  printf("[3]=%d\n", ptr->b); // correct output because was the last used value

  return 0;
}

