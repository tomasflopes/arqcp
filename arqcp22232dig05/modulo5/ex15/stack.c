#include <stdlib.h>

#include "shared.h"

stack_t *new_stack() {
    stack_t *s = (stack_t *)malloc(sizeof(stack_t));
    s->size = 0;
    s->stack = NULL;
    return s;
}

void free_stack(stack_t *s) {
    // man malloc: if ptr is NULL, no operation is performed
    free(s->stack);
    free(s);
}

void push(stack_t *s, stackdata_t val) {
    // man malloc: if ptr is NULL, then the call is equivalent
    //             to malloc(size)
    s->stack = realloc(s->stack, ++s->size * sizeof(stackdata_t));
    stackdata_t *ptr = (stackdata_t *)(s->stack + (s->size - 1));
    *ptr = val;
}

stackdata_t pop(stack_t *s) {
    if (s->size == 0) return 0;
    // man malloc: if size was equal to 0, either NULL or a pointer
    //             suitable to be passed to free() is returned
    stackdata_t popped = *(stackdata_t *)(s->stack + (s->size - 1));
    s->stack = realloc(s->stack, --s->size * sizeof(stackdata_t));
    return popped;
}

