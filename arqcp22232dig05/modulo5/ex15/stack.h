#ifndef STACK_H
#define STACK_H
#include "shared.h"
    
stack_t *new_stack();
void free_stack();
void push(stack_t *s, stackdata_t val);
stackdata_t pop(stack_t *s);

#endif

