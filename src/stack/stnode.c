/* stnode.c: stack node methods */

#include <stdio.h>
#include <string.h>

#include "stnode.h"

stnode* stnode_construct(void *data, size_t size) {
	stnode *node = malloc(sizeof(stnode));
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


void stnode_destruct(stnode *node) {
	if (!node)
		return;

	if (node->data) {
		free(node->data);
		node->data = NULL;
	}

	free(node);
} /* stnode_c */
