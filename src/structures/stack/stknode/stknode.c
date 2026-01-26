/* stknode.c: stack node methods */

#include <stdio.h>
#include "stknode.h"

stknode* stknode_construct(void *data, const td *type) {
	stknode *node = malloc(sizeof(stknode));

	if (!node) {
		perror("=== malloc failed: snode_construct(): sizeof(dnode) ===");
		return NULL;
	}

	if ( type == NULL || !td_validator(type)) {
		perror("=== TD_MAGIC failed or type null ===\n");
		exit(3);
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
		node->type->destruct(node);
	}

	free(node);
} /* stknode_c */
