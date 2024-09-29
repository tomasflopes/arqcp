void compress_shorts(short *shorts, int n_shorts, int *integers)
{
  short *p = (short *)integers; // Declaring a pointer with short size

  for (int i = 0; i < n_shorts; i++)
  {
    // By doing this we put all the short data in the correct position for the integers array to read
    *(p + i) = *(shorts + i);
  }
}
