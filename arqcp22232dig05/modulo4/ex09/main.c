#include <stdio.h>

#include "asm.h"

int main() {
    calculate(1,2);
    return 0;
}

void print_result(char op, int o1, int o2, int res) {
    printf("%d %c %d = %d\n", o1, op, o2, res);
}

