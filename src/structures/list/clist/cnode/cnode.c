/* cnode.c: circular linked list node methods */

#include <stdio.h>
#include <string.h>

#include "cnode.h"

cnode* cnode_construct(void *data, const td *type) {
	cnode *node = malloc(sizeof(cnode));
	if (!node) {
		perror("=== malloc failed: dnode_construct(): sizeof(dnode) ===");
		return NULL;
	}
	if (type == NULL || !td_validator(type)) {
		perror("=== TD_MAGIC failed or type null ===\n");
		exit(3);
	}
	node->type = type;
	node->next = NULL;
	node->previous = NULL;

	if (type->copy) {
		node->data = type->copy(data);
	} else {
		node->data = data;
	}

	return node;}

void cnode_destruct(cnode *node) {
	if (!node) return;

	if (node->type && node->type->destruct) {
		node->type->destruct(node);
	}

	free(node);
} /* cnode_c */
