/* snode.c: singly linked list node methods */

#include <stdio.h>
#include "snode.h"

snode* snode_construct(void *data, const td *type) {
	snode *node = malloc(sizeof(snode));

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

void snode_destruct(snode *node) {
	if (!node) return;

	if (node->type && node->type->destruct) {
		node->type->destruct(node);
	}

	free(node);
}


