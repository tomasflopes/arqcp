#include <stdio.h>
#include "check_format.h"

int main() {
    char str[256];
    printf("Enter a number: ");
    fgets(str, sizeof(str), stdin);

    printf("\nFormat: %s\n", check_format(str));

    return 0;
}
