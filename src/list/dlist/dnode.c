// ====================
// | > doubly_node.c |
// ====================

#include "dnode.h"

struct doubly_node doubly_node_construct(void *data, size_t size) {

	struct doubly_node doubly_node = {
		.data = malloc(size),
		.next = NULL,
		.previous = NULL
	};
	memcpy(doubly_node.data, data, size);
	return doubly_node;
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
