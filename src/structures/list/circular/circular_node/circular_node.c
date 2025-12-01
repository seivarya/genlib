// =====================
// | > circular_node.c |
// =====================

#include "circuler_node.h"

struct circular_node circular_node_construct(void *data, size_t size) {

	struct circular_node node;
	
	node.data = malloc(size);
	memcpy(node.data, data, size);

	node.next = NULL;
	node.previous = NULL;

	return node;
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
