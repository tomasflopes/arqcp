#include <stdio.h>

#include "asm.h"

int main() {
    structA a;
    structB b;
    printf("sizeof(a)=%lu\n", sizeof(a));
    printf("sizeof(b)=%lu\n", sizeof(b));
    
    a.x = -10;
    b.a = a;
    b.x = -2;
    b.z = -15;
    b.b = &a;

    printf("fun1=%hd\n", fun1(&b));
    printf("fun2=%hd\n", fun2(&b));
    printf("*fun3=%hd\n", *fun3(&b));
    printf("fun4=%hd\n", fun4(&b));

    return 0;
}

