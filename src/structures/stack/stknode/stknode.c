/* stknode.c: stack node methods */

#include <stdio.h>
#include <genlib/td.h> 
#include "stknode.h"

stknode* stknode_construct(void *data, const td *type) {
	stknode *node = malloc(sizeof(stknode));

	if (!node) {
		perror("=== malloc failed: stknode_construct(): sizeof(stknode) ===");
		return NULL;
	}

	if ( type == NULL || !td_validator(type)) {
		fprintf(stderr, "Fatal Error: %s: Invalid or NULL type descriptor provided. Exiting.\n", __func__);
		free(node);
		return NULL;
	}

	node->type = type;
	node->next = NULL;

	if (type->copy) {
		node->data = type->copy(data);
	} else {
		node->data = data;
	}

	return node;
}


void stknode_destruct(stknode *node) {
	if (!node) return;

	if (node->type && node->type->destruct) {
		node->type->destruct(node->data);
	}

	free(node);
} /* stknode_c */
