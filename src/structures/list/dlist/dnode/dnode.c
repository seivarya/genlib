/* dnode.c: doubly linked list node methods */

#include <stdio.h>
#include "dnode.h"
#include <genlib/td.h>

dnode* dnode_construct(void *data, const td *type) {
	dnode *node = malloc(sizeof(dnode));

	if (!node) {
		perror("=== malloc failed: dnode_construct(): sizeof(dnode) ===");
		return NULL;
	}

	if (type == NULL || !td_validator(type)) {
			fprintf(stderr, "Fatal Error: %s: Invalid or NULL type descriptor provided. Exiting.\n", __func__);
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

	return node;
}

void dnode_destruct(dnode *node) {
	if (!node) return;

	if (node->type && node->type->destruct) {
		node->type->destruct(node->data);
	}

	free(node);
} /* dnode_c */
