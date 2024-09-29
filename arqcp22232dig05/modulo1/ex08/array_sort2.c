void array_sort2(int *vec, int n)
{
  // char int_size = sizeof(int);
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (*(vec + i) > *(vec + j))
      {
        // Swap the variables without a third (temporary) variable
        *(vec + j) += *(vec + i);
        *(vec + i) = *(vec + j) - *(vec + i);
        *(vec + j) -= *(vec + i);
      }
    }
  }
}
