#include <stdio.h>

#include "count_words.h"

void print_count(char *str);

int main() {
    printf("<String>: <Number of words>\n");
    print_count("Hello World!");
    print_count("Test");
    print_count("Test ");
    print_count(" Test");
    print_count(" ");
    print_count("");

    return 0;
}

void print_count(char *str) {
    printf("\"%s\": %d\n", str, count_words(str));
}
