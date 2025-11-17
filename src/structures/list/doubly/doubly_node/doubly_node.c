#include "doubly_node.h"

struct doubly_node doubly_node_contruct(void *data, int size) {

	printf("=== doubly_node_construct(): invoked ===\n");

	struct doubly_node node;

	node.data = malloc(size);
	memcpy(node.data, data, size);
	
	node.next = NULL;
	node.previous = NULL;

	return node;
}


void doubly_node_destruct(struct doubly_node *doubly_node) {
	
	printf("=== doubly_node_destruct(): invoked ===\n");

	//  WARNING: uh maybe check for *existence of pointers first to avoid segfault..
	
	free(doubly_node->data);
	free(doubly_node->next);
	free(doubly_node->previous);


	printf("=== doubly_node_destruct(): node destroyed successfully ===\n");
}
