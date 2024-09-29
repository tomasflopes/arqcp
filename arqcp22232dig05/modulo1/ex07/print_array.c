#include <stdio.h>

void print_array(int *array, int len) {
    for (int i = 0; i < len; i++) printf("[%d] = %d\n", i, array[i]);
}
