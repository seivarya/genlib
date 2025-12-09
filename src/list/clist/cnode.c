// =====================
// | > circular_node.c |
// =====================

#include "cnode.h"

struct circular_node circular_node_construct(void *data, size_t size) {

	struct circular_node circular_node;
	
	circular_node.data = malloc(size);
	memcpy(circular_node.data, data, size);

	circular_node.next = NULL;
	circular_node.previous = NULL;

	return circular_node;
}

void circular_node_destruct(struct circular_node *circular_node) {
	if (!circular_node) return;
	if (circular_node == NULL) return;
	
	if (circular_node->data) {
		free(circular_node->data);
		circular_node->data = NULL;
	}
	free(circular_node);
} /* circular_node_c */
