#define CHECK_BINARY(x) (x == '0' || x == '1')

#define CHECK_OCTAL(x) (x >= '0' && x <= '7')

#define CHECK_DECIMAL(x) (x >= '0' && x <= '9')

#define CHECK_HEXADECIMAL(x) \
    (CHECK_DECIMAL(x) || (x >= 'a' && x <= 'e') || (x >= 'A' && x <= 'E'))
