#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node node_construct(void *data, int size) {

	printf("=== node_construct(): invoked ===\n");

	if (size < 1) {
		perror("=== node_construct(): size < 1 ===\n");
	}

	struct node node;

	node.data = malloc(sizeof(size));
	memcpy(node.data, data, size);

	node.next = NULL;
	node.previous = NULL;

	return node;
}


void node_destruct(struct node *node) {

	printf("=== node_destruct(): invoked ===\n");

	free(node->data);
	free(node);

	printf("=== node_destruct(): node destroyed successfully ===\n");
	return;
} /* NODE_C */
