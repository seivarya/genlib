// ====================
// | > snode.c |
// ====================

#include <stdio.h>
#include <string.h>
#include "snode.h"

struct snode* snode_construct(void *data, size_t size) {
	snode* node = malloc(sizeof(struct snode));
	if (!node) {
		perror("=== malloc failed for *struct snode* ===\n");
		return NULL;
	}
	node->data = malloc(size);
	if (!node->data) {
		perror("=== malloc failed for *struct snode->data* ===\n");
		free(node);
		return NULL;
	}
	memcpy(node->data, data, size);
	node->next = NULL;
	return node;
}

void snode_destruct(struct snode *node) {
	if (!node) return;
	if (node == NULL) return;
	if (node->data) {
		free(node->data);
		node->data = NULL;
	}
	free(node);
}  /* snode_c */
