void frequencies(float *grades, int n, int *freq)
{
  for (int i = 0; i < n; i++)
  {
    // Converting (and rounding) the i-th grade to get the position in the freq array
    int position = (int)*(grades + i);

    *(freq + position) += 1;
  }
}
