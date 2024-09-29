int reset_bit(int *ptr, int pos)
{
  int mask = 1;
  mask <<= pos; // Position bit in correct position
  mask = ~mask; // Negate mask, now only the reset bit is 0

  int original = *ptr;
  *ptr = *ptr & mask; // reset bit

  return original != *ptr; // return if the number has changed
}
