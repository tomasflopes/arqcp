#include <stdio.h>
#include "frequencies.h"

// Define constants so it's easier to adapt the program to future changes in the evaluation scale
#define MIN_GRADE 0
#define MAX_GRADE 20

int main()
{

  float grades[] = {8.23,
                    12.25,
                    16.45,
                    12.45,
                    10.05,
                    6.45,
                    14.45,
                    0.0,
                    12.67,
                    16.23,
                    18.75};
  const int N = 10;

  int freq[MAX_GRADE - MIN_GRADE] = {0}; // Initialize all the array at 0

  frequencies(grades, N, freq);

  return 0;
}
