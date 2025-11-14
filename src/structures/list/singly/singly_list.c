#include "singly_list.h"
#include <stdio.h>
#include <stdlib.h>

struct singly_node* singly_node_create(struct singly *self, void *data, int size);
struct singly_node* singly_iterate(struct singly *self, int index);

void singly_insert(struct singly *self, int index, void *data, int size);
void singly_remove(struct singly *self, int index);
void singly_reverse(struct singly *self);

void* singly_fetch_node(struct singly *self, int index);
void* singly_fetch_data(struct singly *self, int index);

struct singly singly_construct(void) {

	struct singly list;

	list.head = NULL;
	list.length = 0;

	list.insert = singly_insert;
	list.remove = singly_remove;
	list.reverse = singly_reverse;

	list.fetch_node = singly_fetch_node;
	list.fetch_data = singly_fetch_data;

	printf("=== singly_construct(): struct initialized ===\n");
	return list;
}

void singly_destruct(struct singly *singly) {
	//  BUG: not sure if it works
	
	if (!singly) {
		perror("=== singly_destruct(): warning: list doesn't exist ===\n");
		return;
	}

	if (singly->head == NULL) {
		perror("=== singly_destruct(): warning: head is set to NULL ===\n");
		return;
	}

	if (singly->length == 1) {
		free(singly->head);
	} else {

		printf("=== singly_destruct(): releasing nodes ===\n");
		struct singly_node *cursor = singly->head;
		while(cursor != NULL) {
			free(cursor->next);
		}
		free(cursor);
	}
	printf("=== singly_destruct(): complete ===\n");
}

struct singly_node* singly_node_create(struct singly *self, void *data, int size) {

	if (!self) return NULL;

	struct singly_node *node = malloc(sizeof(struct singly_node));
	if (!node) {
		perror("=== singly_node_create(): malloc failed ===\n");
		exit(1);
	}

	*node = singly_node_construct(data, size);

	printf("=== singly_node_create(): node created ===\n");
	return node;
}

struct singly_node* singly_iterate(struct singly *self, int index) {

	if (index == 0) {
		return self->head;
	}
	if (index < 0 || index > self->length) {
		printf("%d\n", index);
		perror("=== singly_iterate(): invalid index ===\n");
		exit(8);
	}

	struct singly_node *cursor = self->head;

	while (index != 0) {
		cursor = cursor->next;
		index--;
	}

	return cursor;
}

void singly_insert(struct singly *self, int index, void *data, int size) {

	if (index < 0) {
		perror("=== singly_insert(): warning: index can't be less than 0 ===\n");
		return;
	}
	struct singly_node *node_to_insert = singly_node_create(self, data, size);

	if (index == 0) {
		node_to_insert->next = self->head; 
		self->head = node_to_insert;

	} else if (index == 1 && self->head != NULL) {
		self->head->next = node_to_insert;

	} else {
		struct singly_node *left_pos_node = singly_iterate(self, index - 1);
		struct singly_node *right_pos_node = left_pos_node->next;
		left_pos_node->next = node_to_insert;
		node_to_insert->next = right_pos_node;
	}

	self->length++;
	printf("=== singly_insert(): node inserted, new length: %d ===\n", self->length);
}

void singly_remove(struct singly *self, int index) {

	if (index >= self->length) {
		perror("=== singly_remove(): warning: index can't be greater than list length ===\n");
		return;
	}
	if (index < 0) {
		perror("=== singly_remove(): warning: index can't be less than 0 ===\n");
		return;
	}

	if (index == 0) {
		struct singly_node *temp = self->head;
		self->head = temp->next;
		singly_node_destruct(temp);
	} else {
		struct singly_node *left_pos_node = singly_iterate(self, index - 1);
		struct singly_node *right_pos_node = left_pos_node->next;

		left_pos_node->next = right_pos_node->next;

		singly_node_destruct(right_pos_node);
	}

	self->length--;
	printf("=== singly_remove(): node removed, new length: %d ===\n", self->length);
}

void* singly_fetch_node(struct singly *self, int index) {

	if (index >= self->length) {
		perror("=== singly_fetch_node(): warning: index can't be greater than list length ===\n");
		return NULL;
	}
	if (index < 0) {
		perror("=== singly_fetch_node(): warning: index can't be less than 0 ===\n");
		return NULL;
	}

	if (index == 0) {
		return self->head;
	} else {
		struct singly_node *target_node = singly_iterate(self, index);
		return target_node;
	}
}

void* singly_fetch_data(struct singly *self, int index) {

	if (index >= self->length) {
		perror("=== singly_fetch_data(): warning: index can't be greater than list length ===\n");
		return NULL;
	}
	if (index < 0) {
		perror("=== singly_fetch_data(): warning: index can't be less than 0 ===\n");
		return NULL;
	}

	if (index == 0) {
		return self->head->data;
	} else {
		struct singly_node *target_node = singly_iterate(self, index);
		return target_node->data;
	}
}

void singly_reverse(struct singly *self) {
	if (!self) return;

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
}
