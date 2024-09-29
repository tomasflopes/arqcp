#include <stdio.h>

#include "sort_without_reps.h"
#include "../ex07/print_array.h"

int main() {
    int src[] = {6, 1, 5, 2, 12, -3, 5, 0};
    int dest[8];
    int dest_len = sort_without_reps(src, 8, dest);
    print_array(dest, dest_len);
    printf("Size of dest: %i\n", dest_len);
    return 0;
}
