/* qnode.c: queue not methods */

#include <stdio.h>
#include "qnode.h"
#include <genlib/td.h>

qnode* qnode_construct(void *data, const td *type) {
	qnode *node = malloc(sizeof(qnode));

	if (!node) {
		perror("=== malloc failed: qnode_construct(): sizeof(qnode) ===");
		return NULL;
	}

	if ( type == NULL || !td_validator(type)) {
			fprintf(stderr, "Fatal Error: %s: Invalid or NULL type descriptor provided. Exiting.\n", __func__);
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
		node->type->destruct(node->data);
	}

	free(node);
} /* qnode_c */
