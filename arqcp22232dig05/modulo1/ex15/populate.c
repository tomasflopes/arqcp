#include <stdlib.h>
#include <time.h>

void populate(int *vec, int num, int limit) {
    srandom(time(NULL));  // seed the algorithm
    for (int i = 0; i < num; i++) {
        *(vec + i) = random() % limit;  // + 1;  // generate a random integer
    }
}
