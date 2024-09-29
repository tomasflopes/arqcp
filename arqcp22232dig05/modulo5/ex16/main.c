#include <stdio.h>
#include <stdlib.h>

#include "approved_semester.h"

int main(void)
{
  group *g = (group *)malloc(sizeof(group));
  g->n_students = 3;
  unsigned short grades[] = {0xff00, 0xfff0, 0x0000};
  g->individual_grades = grades;

  printf("Approved semester: %d\n", approved_semester(g));
  free(g);
}
