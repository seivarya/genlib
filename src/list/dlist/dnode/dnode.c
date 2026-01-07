/* dnode.c: doubly linked list node methods */

#include <stdio.h>
#include <string.h>

#include "dnode.h"

dnode* dnode_construct(void *data, size_t size) {
	dnode *node = malloc(sizeof(dnode));
	if (!node) {
		perror("=== malloc failed: dnode_construct(): sizeof(dnode) ===");
		return NULL;
	}

	node->data = malloc(size);
	if (!node->data) {
		perror("=== malloc failed: dnode_construct(): node->data ===");
		free(node);
		return NULL;
	}

	memcpy(node->data, data, size);
	node->next = NULL;
	node->previous = NULL;

	return node;
}

void dnode_destruct(dnode *node) {
	if (!node)
		return;

	if (node->data) {
		free(node->data);
		node->data = NULL;
	}

	free(node);
} /* dnode_c */
