#include <stdio.h>
#include "formats.h"

char *check_format(char *str) {
    int i = 0;
    char current = 0;

    if (*str == '\n') return "Empty String";

    while (current <= 3 && str[i] != '\n') {
        if (!CHECK_BINARY(str[i]) && current == 0) current++;
        else if (!CHECK_OCTAL(str[i]) && current == 1) current++;
        else if (!CHECK_DECIMAL(str[i]) && current == 2) current++;
        else if (!CHECK_HEXADECIMAL(str[i]) && current == 3) current++;
        else i++;
    }

    switch (current) {
        case 0: return "Binary";
        case 1: return "Octal";
        case 2: return "Decimal";
        case 3: return "Hexadecimal";
    }

    return "Not a Number";
}
