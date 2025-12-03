// ====================
// | > stack_node.c |
// ====================

#include "stack_node.h"

struct stack_node stack_node_construct(size_t size, void *data) {
	struct stack_node stack_node = {
		.data = malloc(size),
		.next = NULL,
	};

	memcpy(stack_node.data, data, size);

	return stack_node;
}
void stack_node_destruct(struct stack_node *stack_node) {
	if (!stack_node) return;
	if (stack_node == NULL) return;

	if (stack_node->data) {
		free(stack_node->data);
		stack_node->data = NULL;
	}
	free(stack_node);
} /* stack_node_c */
