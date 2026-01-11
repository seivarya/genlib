/* stack.c: stack methods */

#include <stdlib.h>
#include <stdio.h>

#include "stknode/stknode.h"
#include "../../../include/genlib/stack.h"

/* info: private methods */

static inline int _validate_stack(stack *stk) {
	if (stk == NULL) {
		fprintf(stderr, "=== error: _validate_stack(): stack doesn't exist or it has been destroyed ===\n");
		return 0;
	}
	return 1;
}

static inline int _validate_stindex(stack *stk, size_t index) {
	if (!stk || index >= stk->length) {
		fprintf(stderr,
	  "=== error: _validate_stindex(): index [%zu] out of bounds <length: %zu> ===\n",
	  index, stk->length);
		return 0;
	}
	return 1;
}

/* info: public methods */

stack* stack_construct(void) {
	stack *stk = malloc(sizeof(stack));
	if (stk) {
		stk->head = NULL;
		stk->length = 0;
		return stk;
	}

	fprintf(stderr, "=== error: stack_construct(): malloc failed ===\n");
	return NULL;
}

void stack_destruct(stack *stk) {
	if (!_validate_stack(stk))
		return;

	/* destroy all nodes */
	stknode *current = stk->head;
	while (current != NULL) {
		stknode *next = current->next;
		stknode_destruct(current);
		current = next;
	}

	free(stk);
} // do stacks even have reverse() method ???

void push(stack *stk, void *data, size_t size) {
	if (!_validate_stack(stk))
		return;

	stknode *new_node = stknode_construct(data, size);

	/* insert at head */
	if (stk->length == 0) {
		stk->head = new_node; /* new_node->next is already NULL */
	} else {
		new_node->next = stk->head;
		stk->head = new_node;
	}

	stk->length++;
}

void pop(stack *stk) {
	if (!_validate_stack(stk) || stk->length == 0)
		return;

	stknode *target = stk->head;

	/* update head */
	if (stk->length == 1) {
		stk->head = NULL;
	} else {
		stk->head = target->next;
	}

	stknode_destruct(target);
	stk->length--;
}

int is_empty(stack *stk) {
	if (!_validate_stack(stk))
		return 1;

	return stk->length == 0;
}

void* peek(stack *stk) {
	if (!_validate_stack(stk) || stk->length == 0)
		return NULL;

	return stk->head->data;
} /* stack_c */
