int join_bits(int a, int b, int pos)
{
  int mask = -1; // signed int with all bits at 1
                 
  mask <<= pos+1;

  if(pos == 31)               
    mask = ~mask; 

  b &= mask;

  mask = ~mask;

  a &= mask;

  return a | b; // could use + or ^= to join bytes
}
