/* cnode.c: circular linked list node methods */

#include <stdio.h>
#include "cnode.h"
#include <rvlib/td.h>

cnode* cnode_construct(void *data, const td *type) {
	cnode *node = malloc(sizeof(cnode));
	if (!node) {
		perror("=== malloc failed: cnode_construct(): sizeof(cnode) ===");
		return NULL;
	}
	if (type == NULL || !td_validator(type)) {
		fprintf(stderr, "Fatal Error: %s: Invalid or NULL type descriptor provided. Exiting.\n", __func__);
		free(node);
		return NULL;
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
		node->type->destruct(node->data);
	}

	free(node);
} /* cnode_c */
