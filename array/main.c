#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main()
{
    stack* stk;
    stk = create_stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);
    printf("\n Stack: ");
    print_stack(stk);
    printf("\n Pop stack element %i", pop(stk));
    printf("\n Peek stack top element %i", peek_top(stk));
    printf("\n Stack size %zu \n", stack_size(stk));
    clear_stack(stk);
    printf("\n Stack is clean");
    destroy_stack(stk);
    printf("\n Stack is destroed");
    return 0;
}
