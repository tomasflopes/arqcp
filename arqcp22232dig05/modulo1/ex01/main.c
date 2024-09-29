#include <stdio.h>

int main() {
    int x = 5;
    int *xPtr = &x;
    float y = *xPtr + 3;
    int vec[] = {10, 11, 12, 13};

    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("Address of x = %p\n", &x);
    printf("Address of xPtr = %p\n", xPtr);
    printf("Value pointed by xPtr = %d\n", *xPtr);
    printf("Address of vec = %p\n", vec);

    for (unsigned char i = 0; i < sizeof(vec) / sizeof(vec[0]); i++) {
        printf("vec[%hhd] = %d\n", i, vec[i]);
    }

    for (unsigned char i = 0; i < sizeof(vec) / sizeof(vec[0]); i++) {
        printf("Address of vec[%hhd] = %p\n", i, &vec[i]);
    }

    /**
     * b)
     * vec is a pointer, it points to the memory address of the array's first element.
     * Because of that, the memory address is the same as vec[0].
     * An integer is a data type that takes 4 bytes to be stored. vec[1], vec[2] and vec[3]'s memory addresses are
     * calculated by adding those 4 bytes to the address of the first element.
     * 
     * c)
     * Different addresses, unless a big coincidence.
     */

    return 0;
}
