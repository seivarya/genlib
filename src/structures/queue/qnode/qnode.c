/* qnode.c: queue not methods */

#include <stdio.h>
#include "qnode.h"

qnode* qnode_construct(void *data, const td *type) {
	qnode *node = malloc(sizeof(qnode));

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

void qnode_destruct(qnode *node) {
	if (!node) return;

	if (node->type && node->type->destruct) {
		node->type->destruct(node);
	}

	free(node);
} /* qnode_c */
