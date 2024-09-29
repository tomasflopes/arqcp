const char LOWER_CASE_A_ASCII_CODE = 97;
const char LOWER_CASE_Z_ASCII_CODE = 122;

/* From ASCII table: Every character is 32 positions apart
   from it's upper case correspondent
   Ex.: A = 65, a = 97.
   By subtracting this value to every lower case character
  we get a full upper case string.
 */
const char DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS = 32;

char compare_ignore_case(char a, char b)
{
  if (a == b)
    return 1;

  // Convert both chars into their upper case respective
  if (a >= LOWER_CASE_A_ASCII_CODE && a <= LOWER_CASE_Z_ASCII_CODE)
    a = a - DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS;
  if (b >= LOWER_CASE_A_ASCII_CODE && b <= LOWER_CASE_Z_ASCII_CODE)
    b = b - DIFFERENCE_BETWEEN_UPPER_AND_LOWER_CASE_CHARACTERS;

  return a == b;
}
