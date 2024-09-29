#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "fill_student.h"
#include "print_array.h"

#define N_STUDENTS 5
#define N_GRADES 5

int main(void)
{
  Student *arr = (Student *)malloc(N_STUDENTS * sizeof(Student));

  for (int i = 0; i < N_STUDENTS; i++)
  {
    fill_student(&arr[i], 20 + i, i + 1, "Joao", "Rua Césamo");
    for (int j = 0; j < N_GRADES; j++)
      arr[i].grades[j] = 0;
  }

  // print results
  for (int i = 0; i < N_STUDENTS; i++)
  {
    printf("\nStudent no. %d:\n", arr[i].number);
    printf("Age: %d\n", arr[i].age);
    printf("Name: %s\n", arr[i].name);
    printf("Address: %s\n", arr[i].address);
    print_array(arr[i].grades, 5, "grades");
  }

  free(arr);

  return 0;
}
