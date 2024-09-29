#include <stdio.h>

#include "array_sort1.h"
#include "print_array.h"

int main() {
    int vec[] = {6, 1, 5, 2, 12, -3, 7, 0};
    array_sort1(vec, 8);
    print_array(vec, 8);
    return 0;
}
