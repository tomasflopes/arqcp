/* From ASCII table: Every character is 32 positions apart
   from it's upper case correspondent
   Ex.: A = 65, a = 97.
   By subtracting this value to every lower case character
  we get a full upper case string.
 */
const char DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS = 'a' - 'A';

char compare_ignore_case(char a, char b)
{
  if (a == b)
    return 1;

  // Convert both chars into their upper case respective
  if (a >= 'a' && a <= 'z')
    a = a - DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS;
  if (b >= 'a' && b <= 'z')
    b = b - DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS;

  return a == b;
}
