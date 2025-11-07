#include "singly_list.h"
#include <stdio.h>
#include <stdlib.h>


struct node* singly_node_create(struct singly *self, void *data, int size);
struct node* singly_iterate(struct singly *self, int index);

void insert_singly(struct singly *self, void *data, int size);
void remove_singly(struct singly *self, int index);

void* retrieve_singly(struct singly *self, int index);
void* search_singly(struct singly *self, struct node *node);


struct singly singly_construct() {

	printf("=== singly_construct(): invoked ===\n");

	struct singly singly;

	singly.head = NULL;
	singly.length = 0;

	singly.insert_singly = insert_singly;
	singly.remove_singly = remove_singly;

	singly.retrieve_singly = retrieve_singly;
	singly.search_singly = search_singly;

	return singly;
}

void singly_destruct(struct singly *singly) {

	if (!singly) {
		perror("=== singly_destruct(): warning: list doesn't exist ===\n");
	}

	if (singly->head == NULL) {
		perror("=== singly_destruct(): warning: head is set to NULL ===\n");
	}

	for (int i = 0; i < singly->length; i++) {
		// iterate
	}
}
struct node* singly_node_create(struct singly *self, void *data, int size) {
	
	struct node *node = malloc(sizeof(struct node));
	*node = node_construct(data, size);
	return node;
}

struct node* singly_iterate(struct singly *self, int index) {

	if (index < 0 || index >= self->length) {
		perror("=== singly_iterate(): invalid length===\n");
		exit(8);
	}

	struct node *cursor = self->head;

	while (index != 0) {
		cursor = cursor->next;
		index--;
	}
	return cursor;
}

void insert_singly(struct singly *self, void *data, int size);
void remove_singly(struct singly *self, int index);

void* retrieve_singly(struct singly *self, int index);
void* search_singly(struct singly *self, struct node *node);






