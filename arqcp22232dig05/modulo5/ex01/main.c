#include <stdio.h>

int main() {
    union union_u1 {
        char vec[32];
        float a;
        int b;
    } u;

    struct struct_s1 {
        char vec[32];
        float a;
        int b;
    } s;

    printf("sizeof(union u)=%lu\n", sizeof(u));     // 32 bytes
    printf("sizeof(struct s)=%lu\n", sizeof(s));    // 40 bytes
    
    /**
     * The size of a union is equal to the size of the biggest field, which in this case is 32 bytes since
     * there is an array of chars (1 byte) with 32 elements, which in turn has a size of 32 bytes.
     *
     * The size of a structure is equal to the sum of all the field sizes, including space required for alignment
     * which in this case it isn't needed.
     */
}

