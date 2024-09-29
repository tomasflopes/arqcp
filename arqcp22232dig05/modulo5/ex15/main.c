#include <stdio.h>

#include "stack.h"

void test_stack(stack_t *s);

int main() {
    stack_t *s = new_stack();
    test_stack(s);
    printf("---\n");
    stackdata_t popped;

    push(s, 2);
    test_stack(s);
    printf("---\n");
    push(s, -10);
    test_stack(s);
    printf("---\n");
    popped = pop(s);
    test_stack(s);
    printf("popped: %ld\n---\n", (long)popped);
    popped = pop(s);
    test_stack(s);
    printf("popped: %ld\n---\n", (long)popped);
    popped = pop(s);
    test_stack(s);
    printf("popped: %ld\n---\n", (long)popped);
    push(s, 0);
    test_stack(s);

    free_stack(s);
    return 0;
}

void test_stack(stack_t *s) {
    printf("(size: %d) stack: ", s->size);
    if (s->size != 0) {
        for (int i = 0; i < s->size; i++) {
            stackdata_t val = *(stackdata_t *)(s->stack + i);
            printf("%ld ", (long)val);
        }
    }
    printf("\n");
}

