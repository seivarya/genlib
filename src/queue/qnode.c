#include <stdio.h>
#include <string.h>

#include "qnode.h"

qnode* qnode_construct(void *data, size_t size) {
	qnode *node = malloc(sizeof(qnode));
	if (!node) {
		perror("=== malloc failed: stnode_construct(): sizeof(stnode) ===");
		return NULL;
	}

	node->data = malloc(size);
	if (!node->data) {	
		perror("=== malloc failed: stnode_construct(): node->data ===");
		free(node);
		return NULL;
	}

	memcpy(node->data, data, size);
	node->next = NULL;

	return node;
}

void qnode_destruct(qnode *node) {
	if (!node)
		return;

	if (node->data) {
		free(node->data);
		node->data = NULL;
	}

	free(node);
} /* qnode_c */
