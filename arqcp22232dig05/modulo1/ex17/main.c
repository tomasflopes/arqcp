#include <stdio.h>

void print_array(int *vec, int num) {
    for (int i = 0; i < num; i++) {
        printf("[%d] = %d\n", i, *(vec + i));
    }
}

int main() {}
