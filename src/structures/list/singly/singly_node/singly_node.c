#include "singly_node.h"

struct singly_node singly_node_construct(void *data, size_t size) {

	struct singly_node node;

	node.data = malloc(size);
	memcpy(node.data, data, size);

	node.next = NULL;

	return node;
}

void singly_node_destruct(struct singly_node *singly_node) {

	printf("=== singly_node_destruct(): invoked ===\n");

	free(singly_node->data);
	free(singly_node);

	printf("=== singly_node_destruct(): node destroyed successfully ===\n");
} /* SINGLY_NODE_C */
