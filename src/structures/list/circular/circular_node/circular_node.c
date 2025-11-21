#include "circuler_node.h"


struct circular_node circular_node_construct(void *data, size_t size) {

	printf("=== circular_node construct invoked ===\n");

	struct circular_node node;
	
	node.data = malloc(size);
	memcpy(node.data, data, size);

	node.next = NULL;
	node.previous = NULL;


	return node;
}

void circular_node_destruct(struct circular_node *circular_node) {
	//  TODO: later
}


