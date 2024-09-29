int odd_sum(int *p)
{
  // The first element of the array indicates it's size
  int n = *p;
  // Increment to the 'real' start
  p++;

  int sum_of_odd_numbers = 0;

  for (int i = 0; i < n; i++)
    if (*(p + i) % 2 != 0)
      sum_of_odd_numbers += *(p + i);

  return sum_of_odd_numbers;
}
