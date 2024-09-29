#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "fill_student.h"
#include "print_array.h"
#include "update_address.h"
#include "update_grades.h"

#define N_STUDENTS 5

int main(void)
{
  Student *arr = (Student *)malloc(N_STUDENTS * sizeof(Student));

  for (int i = 0; i < N_STUDENTS; i++)
    fill_student(&arr[i], 20 + i, i + 1, "Joao", "Rua Césamo");

  printf("\n-- fill_student() --");
  for (int i = 0; i < N_STUDENTS; i++)
  {
    printf("\nStudent no. %d:\n", arr[i].number);
    printf("Age: %d\n", arr[i].age);
    printf("Name: %s\n", arr[i].name);
    printf("Address: %s\n", arr[i].address);
    print_array(arr[i].grades, 5, "grades");
  }

  printf("\n-- update_address() --");
  for (int i = 0; i < N_STUDENTS; i++)
    update_address(&arr[i], "Rua 123");
  for (int i = 0; i < N_STUDENTS; i++)
  {
    printf("\nStudent no. %d:\n", arr[i].number);
    printf("Age: %d\n", arr[i].age);
    printf("Name: %s\n", arr[i].name);
    printf("Address: %s\n", arr[i].address);
    print_array(arr[i].grades, 5, "grades");
  }

  printf("\n-- update_grades() --");
  for (int i = 0; i < N_STUDENTS; i++)
  {
    int new_grades[] = {1, 2, 3, 4, 5};
    update_grades(&arr[i], new_grades);
  }

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
