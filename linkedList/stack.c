

#include <stdlib.h>	// To get access to calloc() and free()
#include <stdio.h>
#include "stack.h"
#define LIMIT 2

stack* create_stack() {
    stack* stk = malloc(sizeof(*stk));
    stk->stack_size = -1;
    stk->array_size = LIMIT;
    stk->values = (int *)calloc(1, stk->array_size);
    return stk;
}

int* resizeArray (int* arr, int *array_size) {
    int* new_a = (int*)calloc(2, *array_size );
    for (int i = 0; i < *array_size; i++) {
        new_a[i] = arr[i];
    }
    *array_size = *array_size*2;
    return new_a;
}
void push(stack *stack, int val){
    stack->stack_size +=  1;
    if (stack->array_size == stack->stack_size) {
        stack->values = resizeArray(stack->values, &stack->array_size);
    }
    stack->values[stack->stack_size] = val;
}

int pop(stack *stack){
    if (stack->stack_size < 0) {
        printf("\nStack is empty POP ");
    } else {
        int val = stack->values[stack->stack_size];
        stack->values[stack->stack_size] = 0;
        stack->stack_size = stack->stack_size - 1;
        return val;
    }
}

int peek_top(stack *stack) {
    return stack->values[stack->stack_size] ? stack->values[stack->stack_size] : 0;
}

size_t stack_size(stack *stack) {
       return stack->stack_size + 1;
}

void clear_stack(stack *stack){
    stack->stack_size = -1;
    stack->values = (int*)calloc(1, stack->array_size);
}

void destroy_stack(stack *stack) {
    free(stack);
}

void print_stack(stack *stack) {
    for (size_t i=0;i<stack->stack_size+1; i++) {
        printf("%i ", stack->values[i]);
    }
}

