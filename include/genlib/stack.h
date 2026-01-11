/* stack.h: stack header file */

#ifndef STACK_H
#define STACK_H

#include "../../src/structures/stack/stknode/stknode.h"

typedef struct stack {
	struct stknode *head;
	size_t length;
} stack;

stack* stack_construct(void);
void stack_destruct(stack *stk);

void push(stack *stk, void *data, size_t size);
void pop(stack *stk);
int is_empty(stack *stk);
void* peek(stack *stk);

#endif /* stack_h */
