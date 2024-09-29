#include <stdio.h>

#include "consecutives.h"

extern int NSETS;

void print_array(int *vec, int num) {
    for (int i = 0; i < num; i++) {
        printf("[%d] = %d\n", i, *(vec + i));
    }
}

int get_number_of_sets(int *vec, int num) {
    NSETS = 0;

    for (int i = 0; i < num - 2; i++) {
        if (check(vec[i], vec[i + 1], vec[i + 2])) inc_nsets();
    }

    return NSETS;
}

int main() {
    int num = 100;
    int vec[num];
    int limit = 20;

    populate(vec, num, limit);
    print_array(vec, num);
    printf("\nNumber of sets: %d\n", get_number_of_sets(vec, num));

    return 0;
}
