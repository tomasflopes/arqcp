void upper1(char *str)
{
  char *s = str;

  /* From ASCII table: Every character is 32 positions apart
     from it's upper case correspondent
     Ex.: A = 65, a = 97.
     By subtracting this value to every lower case character
    we get a full upper case string.
   */
  const char DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS = 'a' - 'A';

  int i = 0;
  while (s[i] != 0) // While the string doesn't end (ASCII code of [NULL] character = 0)
  {
    // 'a' and 'z' will be interpreted as their ASCII codes
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] = s[i] - DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS;

    i++;
  }
}
