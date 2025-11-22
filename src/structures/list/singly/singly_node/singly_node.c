/* SINGLY_NODE_C */
#ifndef SINGLY_NODE_C
#define SINGLY_NODE_C

#include "singly_node.h"

struct singly_node singly_node_construct(void *data, size_t size) {

	struct singly_node node = {
		.data = malloc(size),
		.next = NULL
	};
	memcpy(node.data, data, size);
	return node;
}

void singly_node_destruct(struct singly_node *singly_node) {
	if (!singly_node) return;
	if (singly_node == NULL) return;

	if (singly_node->data) {
		free(singly_node->data);
		singly_node->data = NULL;
	}

	free(singly_node);
} 
#endif
