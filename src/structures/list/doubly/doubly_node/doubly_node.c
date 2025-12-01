// ====================
// | > doubly_node.c |
// ====================

#include "doubly_node.h"

struct doubly_node doubly_node_construct(void *data, size_t size) {

	struct doubly_node node = {
		.data = malloc(size),
		.next = NULL,
		.previous = NULL
	};
	memcpy(node.data, data, size);
	return node;
}


void doubly_node_destruct(struct doubly_node *doubly_node) {
	if (!doubly_node) return;
	if (doubly_node == NULL) return;
	
	if (doubly_node->data) {
		free(doubly_node->data);
		doubly_node->data = NULL;
	}

	free(doubly_node);
} /* doubly_node_c */
