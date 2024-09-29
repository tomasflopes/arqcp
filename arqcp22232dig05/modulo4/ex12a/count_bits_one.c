int count_bits_one(int x)
{
  int count = 0;
  int j = 1;

  const char N_OF_BITS = sizeof(x) * 8;

	for (int i = 0; i < N_OF_BITS; i++) {
		if ((x & j) != 0) // Apply the mask of j 
			count++;

		j <<= 1; // Shift active bit to next position
	}

  return count;
}
