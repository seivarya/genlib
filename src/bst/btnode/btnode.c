#include <stdio.h>
#include <string.h>

#include "btnode.h"

btnode* btnode_construct(void *data, size_t size) {
	btnode *node = malloc(sizeof(btnode));
	if (!node) {
		perror("=== malloc failed: btnode_construct(): sizeof(btnode) ===");
		return NULL;
	}

	node->data = malloc(size);
	if (!node->data) {
		perror("=== malloc failed: btnode_construct(): node->data ===");
		free(node);
		return NULL;
	}
	memcpy(node->data, data, size);
	node->next = NULL;

	return node;
}

void btnode_destruct(btnode* node) {
	if (!node)
		return;
	if (node->data) {
		free(node->data);
		node->data = NULL;
	}
	
	free(node);
} /* btnode_c */
