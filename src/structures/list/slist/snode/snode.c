/* snode.c: singly linked list node methods */

#include <stdio.h>
#include <string.h>

#include "snode.h"

snode* snode_construct(void *data, size_t size) {
	snode *node = malloc(sizeof(snode));
	if (!node) {
		perror("=== malloc failed: snode_construct(): sizeof(snode) ===");
		return NULL;
	}

	node->data = malloc(size);
	if (!node->data) {
		perror("=== malloc failed: snode_construct(): node->data ===");
		free(node);
		return NULL;
	}

	memcpy(node->data, data, size);
	node->next = NULL;

	return node;
}

void snode_destruct(snode *node) {
	if (!node)
		return;

	if (node->data) {
		free(node->data);
		node->data = NULL;
	}

	free(node);
} /* snode_c */
