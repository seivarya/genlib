#include "stack_node.h"


struct stack_node stack_node_construct(size_t size, void *data) {
	struct stack_node node;
	node.next = NULL;

	node.data = malloc(size);
	memcpy(node.data, data, size);

	return node;
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
