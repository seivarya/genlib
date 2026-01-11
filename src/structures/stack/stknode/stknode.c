/* stknode.c: stack node methods */

#include <stdio.h>
#include <string.h>

#include "stknode.h"

stknode* stknode_construct(void *data, size_t size) {
	stknode *node = malloc(sizeof(stknode));
	if (!node) {
		perror("=== malloc failed: stknode_construct(): sizeof(stknode) ===");
		return NULL;
	}

	node->data = malloc(size);
	if (!node->data) {
		perror("=== malloc failed: stknode_construct(): node->data ===");
		free(node);
		return NULL;
	}

	memcpy(node->data, data, size);
	node->next = NULL;

	return node;
}


void stknode_destruct(stknode *node) {
	if (!node)
		return;

	if (node->data) {
		free(node->data);
		node->data = NULL;
	}

	free(node);
} /* stknode_c */
