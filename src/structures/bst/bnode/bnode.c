#include "bnode.h"

struct bt_node bt_node_construct(void *data, size_t size) {
	struct bt_node bt_node = {
		.data = malloc(size),
		.next = NULL,
		.previous = NULL
	};
	memcpy(bt_node.data, data, size);
	return bt_node;
}

void bt_node_destruct(struct bt_node *bt_node) {
	if (!bt_node) return;
	if (bt_node == NULL) return;

	if (bt_node->data) {
		free(bt_node->data);
		bt_node->data = NULL;
	}
	free(bt_node);
} /* bnode_c */
