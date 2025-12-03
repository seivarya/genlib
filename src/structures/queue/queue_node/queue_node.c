// ====================
// | > queue_node.h |
// ====================

#include "queue_node.h"

struct queue_node queue_node_construct(void *data, size_t size) {
	struct queue_node queue_node = {
		.next = NULL,
		.data = malloc(size)
	};

	memcpy(queue_node.data, data, size);
	return queue_node;
}
void queue_node_destruct(struct queue_node *queue_node) {
	if (!queue_node) return;
	if (queue_node == NULL) return;

	if (queue_node->data) {
		free(queue_node->data);
		queue_node->data = NULL;
	}
	free(queue_node);
} /* queue_node_c */
