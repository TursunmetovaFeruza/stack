
#include <stdlib.h>	// To get access to calloc() and free()
#include <stdio.h>
#include "stack.h"
#define LIMIT 2


stack* create_stack() {
    stack* stk = malloc(sizeof(*stk));
    stk->stack_size = 0;
    stk->top = NULL;
    return stk;
}

void destroy_stack(stack *stk) {
    free(&stk);
}

void push(stack *stk, int val) {
    node* item = malloc(sizeof(node));
    item->value = val;
    item->link = stk->stack_size ? stk->top : NULL;
    stk->top = item;
    stk->stack_size +=1;
}

int pop(stack *stk) {
    node* item = malloc(sizeof(node));
    item = stk->top->link;
    int val = stk->top->value;
    stk->top = item;
    stk->stack_size -=1;
    return val;
}

int peek_top(stack *stk){
        return stk->top ? stk->top->value : 0;
}

size_t stack_size(stack *stk) {
    return stk->stack_size;
}

void clear_stack(stack *stk) {
    stk->stack_size = 0;
    stk->top = NULL;
}

void print_stack(stack *stk) {
    node* item = malloc(sizeof(node));
    item = stk->top;
    for (size_t i = 0; i < stk->stack_size ; i ++) {
        printf("%i ", item->value);
        item = item->link;
    }

}
