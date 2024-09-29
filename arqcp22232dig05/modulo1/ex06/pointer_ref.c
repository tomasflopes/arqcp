void power_ref(int *x, int y)
{
  // Not using math.h module
  int n = *x;

  if (y == 0)
    *x = 1;
  else if (y < 0)
  {
    // As x is an integer every negative exponent will be zero
    *x = 0;
  }
  else
  {
    for (int i = 1; i < y; i++)
      *x *= n;
  }
}
