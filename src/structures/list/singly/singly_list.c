#include "singly_list.h"
#include <stdio.h>
#include <stdlib.h>

struct singly_node* singly_node_create(struct singly *self, void *data, size_t size);
struct singly_node* singly_iterate(struct singly *self, size_t index);

void singly_insert(struct singly *self, size_t index, void *data, size_t size);
void singly_remove(struct singly *self, size_t index);
void singly_reverse(struct singly *self);

void* singly_fetch_node(struct singly *self, size_t index);
void* singly_fetch_data(struct singly *self, size_t index);

struct singly singly_construct(void) {
	struct singly list = { 
		.head = NULL,
		.length = 0,
		.insert = singly_insert,
		.remove = singly_remove,
		.reverse = singly_reverse,
		.fetch_node = singly_fetch_node,
		.fetch_data = singly_fetch_data 
	};

	printf("=== singly_construct(): struct initialized ===\n");
	return list;
}

void singly_destruct(struct singly *singly) {
	
	if (!sll_validate_list(singly)) return;
	if (!sll_validate_list_head(singly)) return;

	if (singly->length == 1) {
		singly_node_destruct(singly->head);
	} else {
		printf("=== singly_destruct(): releasing nodes ===\n");
		struct singly_node *current = singly->head;
		struct singly_node *next;

		while(current != NULL) {
			next = current->next;
			singly_node_destruct(current);
			current = next;
		}

		current = NULL;
		next = NULL;
		singly->head = NULL;
		singly->length = 0;
	}
	printf("=== singly_destruct(): complete ===\n");
}

struct singly_node* singly_node_create(struct singly *self, void *data, size_t size) {

	if(!sll_validate_list(self)) return NULL;

	struct singly_node *node = malloc(sizeof(struct singly_node));
	if (!node) {
		perror("=== singly_node_create(): malloc failed ===\n");
		exit(1);
	}
	*node = singly_node_construct(data, size);

	printf("=== singly_node_create(): node created ===\n");
	return node;
}

struct singly_node* singly_iterate(struct singly *self, size_t index) {

	if (!sll_validate_index(self, index)) exit(0);

	if (index == 0) {
		return self->head;
	}

	struct singly_node *cursor = self->head;

	while (index != 0) {
		cursor = cursor->next;
		index--;
	}
	return cursor;
}

//  info: struct methods

void singly_insert(struct singly *self, size_t index, void *data, size_t size) {

	if (index > self->length) return;

	struct singly_node *node_to_insert = singly_node_create(self, data, size);

	if (index == 0) {
		node_to_insert->next = self->head; 
		self->head = node_to_insert;

	} else {
		struct singly_node *left_index_node = singly_iterate(self, index - 1);
		struct singly_node *right_index_node = left_index_node->next;
		left_index_node->next = node_to_insert;
		node_to_insert->next = right_index_node;
	}

	self->length++;
}

void singly_remove(struct singly *self, size_t index) {
	
	if (!sll_validate_index(self, index)) return;

	if (index == 0) {
		struct singly_node *temp = self->head;
		self->head = temp->next;
		singly_node_destruct(temp);
	} else {
		struct singly_node *left_index_node = singly_iterate(self, index - 1);
		struct singly_node *right_index_node = left_index_node->next;

		left_index_node->next = right_index_node->next;
		singly_node_destruct(right_index_node);
	}
	self->length--;
}

void* singly_fetch_node(struct singly *self, size_t index) {

	if (!sll_validate_index(self, index + 1)) return NULL;

	if (index == 0) {
		return self->head;
	} else {
		struct singly_node *target_node = singly_iterate(self, index);
		return target_node;
	}
}

void* singly_fetch_data(struct singly *self, size_t index) {

	if (!sll_validate_index(self, index)) return NULL;

	if (index == 0) {
		return self->head->data;
	} else {
		struct singly_node *target_node = singly_iterate(self, index);
		return target_node->data;
	}
}

void singly_reverse(struct singly *self) {

	if (!sll_validate_list(self)) return;

	struct singly_node *current = self->head;
	struct singly_node *previous = NULL;
	struct singly_node *next = NULL;

	while(current != NULL) {
		next = current->next;
		current->next = previous;
		
		previous = current;
		current = next;
	}
	self->head = previous;
} /* SINGLY_LIST_C */
