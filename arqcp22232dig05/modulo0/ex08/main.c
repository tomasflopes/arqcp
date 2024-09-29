#include <stdio.h>

int integer_part(char *str);
int fractional_part(char *str);

int main() {
    char x[] = "123.456"; // "123";
    int x_int = integer_part(x);      // assigns 123 to x_int
    int x_frac = fractional_part(x);  // assigns 456 to x_frac

    printf("Integer part: %d\n", x_int);
    printf("Fractional part: %d\n", x_frac);

    return 0;
}

int integer_part(char *str) {
    int i = 0, number = 0;

    while (str[i] != '.' && str[i] != '\0') {
        number = number * 10 + str[i] - '0';
        i++;
    }

    return number;
}

int fractional_part(char *str) {
    int i = 0, number = 0;
    char *cp = str;

    while (*cp != '.' && *cp != '\0') {
        cp++;  // move pointer to the next byte
    }
    cp++;  // next byte

    while (cp[i] != '.' && cp[i] != '\0') {
        number = number * 10 + cp[i] - '0';
        i++;
    }

    return number;
}
