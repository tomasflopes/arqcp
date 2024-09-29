int sum_multiples_x(char *vec, int x)
{
  const int SECOND_BYTE_MASK = 0x0000ff00;
  x &= SECOND_BYTE_MASK;
  x >>= 8;

  int sum = 0;

  while(*vec != 0)
  {
    if(*vec % x == 0) 
      sum += *vec;
    vec++;
  }

  return sum;
}
