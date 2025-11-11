#include "singly_list.h"
#include <stdio.h>
#include <stdlib.h>

struct node* singly_node_create(struct singly *self, void *data, int size);
struct node* singly_iterate(struct singly *self, int index);

void insert_singly(struct singly *self, int index, void *data, int size);
void remove_singly(struct singly *self, int index);
void reverse_singly(struct singly *self);

void* retrieve_singly_node(struct singly *self, int index);
void* retrieve_singly_data(struct singly *self, int index);

struct singly singly_construct() {

	struct singly singly;

	singly.head = NULL;
	singly.length = 0;

	singly.insert_singly = insert_singly;
	singly.remove_singly = remove_singly;
	singly.reverse_singly = reverse_singly;

	singly.retrieve_singly_node = retrieve_singly_node;
	singly.retrieve_singly_data = retrieve_singly_data;

	printf("=== singly_construct(): struct initialized ===\n");
	return singly;
}

void singly_destruct(struct singly *singly) {

	if (!singly) {
		perror("=== singly_destruct(): warning: list doesn't exist ===\n");
		return;
	}

	if (singly->head == NULL) {
		perror("=== singly_destruct(): warning: head is set to NULL ===\n");
		return;
	}

	printf("=== singly_destruct(): releasing nodes ===\n");
	for (int i = 0; i < singly->length; i++) {
		// iterate and free
	}
	printf("=== singly_destruct(): complete ===\n");
}

struct node* singly_node_create(struct singly *self, void *data, int size) {

	if (self) {
		// <nothing>
	}
	struct node *node = malloc(sizeof(struct node));
	if (!node) {
		perror("=== singly_node_create(): malloc failed ===\n");
		exit(1);
	}

	*node = node_construct(data, size);

	printf("=== singly_node_create(): node created ===\n");
	return node;
}

struct node* singly_iterate(struct singly *self, int index) {

	if (index == 0) {
		printf("=== singly_iterate(): returning head ===\n");
		return self->head;
	}
	if (index < 0 || index > self->length) {
		printf("%d\n", index);
		perror("=== singly_iterate(): invalid index ===\n");
		exit(8);
	}

	struct node *cursor = self->head;

	while (index != 0) {
		cursor = cursor->next;
		index--;
	}

	return cursor;
}

void insert_singly(struct singly *self, int index, void *data, int size) {

	if (index < 0) {
		perror("=== insert_singly(): warning: index can't be less than 0 ===\n");
		return;
	}

	struct node *node_to_insert = singly_node_create(self, data, size);

	if (index == 0) {
		node_to_insert->next = self->head;
		self->head = node_to_insert;

	} else if (index == 1 && self->head != NULL) {
		self->head->next = node_to_insert;

	} else {
		struct node *left_pos_node = singly_iterate(self, index - 1);
		struct node *right_pos_node = left_pos_node->next;
		left_pos_node->next = node_to_insert;
		node_to_insert->next = right_pos_node;
	}

	self->length++;
	printf("=== insert_singly(): node inserted, new length: %d ===\n", self->length);
}

void remove_singly(struct singly *self, int index) {

	if (index >= self->length) {
		perror("=== remove_singly(): warning: index can't be greater than list length ===\n");
		return;
	}
	if (index < 0) {
		perror("=== remove_singly(): warning: index can't be less than 0 ===\n");
		return;
	}

	if (index == 0) {
		struct node *temp = self->head;
		self->head = temp->next;
		node_destruct(temp);
	} else {
		struct node *left_pos_node = singly_iterate(self, index - 1);
		struct node *right_pos_node = left_pos_node->next;

		left_pos_node->next = right_pos_node->next;

		node_destruct(right_pos_node);
	}

	self->length = self->length - 1;
	printf("=== remove_singly(): node removed, new length: %d ===\n", self->length);
}

void* retrieve_singly_node(struct singly *self, int index) {

	if (index >= self->length) {
		perror("=== retrieve_singly_node(): warning: index can't be greater than list length ===\n");
		return NULL;
	}
	if (index < 0) {
		perror("=== retrieve_singly_node(): warning: index can't be less than 0 ===\n");
		return NULL;
	}

	if (index == 0) {
		return self->head;
	} else {
		struct node *target_node = singly_iterate(self, index);
		return target_node;
	}
}

void* retrieve_singly_data(struct singly *self, int index) {

	if (index >= self->length) {
		perror("=== retrieve_singly_data(): warning: index can't be greater than list length ===\n");
		return NULL;
	}
	if (index < 0) {
		perror("=== retrieve_singly_data(): warning: index can't be less than 0 ===\n");
		return NULL;
	}

	if (index == 0) {
		return self->head->data;
	} else {
		struct node *target_node = singly_iterate(self, index);
		return target_node->data;
	}
}
void reverse_singly(struct singly *self) {

	struct node *current = self->head;
	struct node *previous = NULL;
	struct node *next;

	int count = 0;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
		count++;
	}

	self->head = previous;
} /* SINGLY_LIST_C */
