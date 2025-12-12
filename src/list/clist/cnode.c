/* cnode.c: circular linked list node methods */

#include <stdio.h>
#include <string.h>

#include "cnode.h"

cnode* cnode_construct(void *data, size_t size) {
	cnode *node = malloc(sizeof(cnode));
	if (!node) {
		perror("=== malloc failed: cnode_construct(): sizeof(cnode) ===");
		return NULL;
	}

	node->data = malloc(size);
	if (!node->data) {
		perror("=== malloc failed: cnode_construct(): node->data ===");
		free(node);
		return NULL;
	}

	memcpy(node->data, data, size);

	node->next = NULL;
	node->previous = NULL;

	return node;
}

void cnode_destruct(cnode *node) {
	if (!node)
		return;

	if (node->data) {
		free(node->data);
		node->data = NULL;
	}

	free(node);
} /* cnode_c */
