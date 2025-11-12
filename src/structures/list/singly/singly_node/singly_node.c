#include "singly_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct singly_node singly_node_construct(void *data, int size) {

	printf("=== singly_node_construct(): invoked ===\n");

	if (size < 1) {
		perror("=== singly_node_construct(): size < 1 ===\n");
	}

	struct singly_node node;

	node.data = malloc(size);
	memcpy(node.data, data, size);

	node.next = NULL;

	return node;
}

void singly_node_destruct(struct singly_node *singly_node) {

	printf("=== singly_node_destruct(): invoked ===\n");

	free(singly_node->data);
	free(singly_node);

	printf("=== singly_node_destruct(): node destroyed successfully ===\n");
}
