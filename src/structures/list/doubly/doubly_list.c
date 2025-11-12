#include "doubly_list.h"

#include <stdio.h>
#include <stdlib.h>

struct doubly_node* doubly_node_create(struct doubly *self, void *data, int size);
struct doubly_node* doubly_forward_iterate(struct doubly *self, int index);
struct doubly_node* doubly_backward_iterate(struct doubly *self, int index);

void doubly_insert(struct doubly *self, int index, void *data, int size);
void doubly_remove(struct doubly *self, int index);
void doubly_reverse(struct doubly *self);

void* doubly_fetch_node(struct doubly *self, int index);
void* doubly_fetch_data(struct doubly *self, int index);


struct doubly doubly_construct() {
	struct doubly doubly;

	doubly.head = NULL;
	doubly.tail = NULL;

	doubly.length = 0;

	doubly.insert = doubly_insert;
	doubly.remove = doubly_remove;
	doubly.reverse = doubly_reverse;

	doubly.fetch_data = doubly_fetch_data;
	doubly.fetch_node = doubly_fetch_node;

	printf("=== doubly_construct(): struct initialized ===\n");
	return doubly;
}


void doubly_destruct(struct doubly *doubly) {
	if (!doubly) {
		perror("=== doubly_destruct(): warning: list doesn't exist ===\n");
		return;
	}

	if (doubly->head == NULL) {
		perror("=== doubly_destruct(): warning: head is set to NULL ===\n");
		return;
	}

	printf("=== doubly_destruct(): releasing nodes ===\n");
	for (int i = 0; i < doubly->length; i++) {
		// iterate and free (implementation skipped)
	}
	printf("=== doubly_destruct(): complete ===\n");

}
struct doubly_node* doubly_node_create(struct doubly *self, void *data, int size) {
	if (self) { /* <nothing> */ }
	struct doubly_node *node = malloc(sizeof(struct doubly_node));

	if (!node) {
		perror("=== doubly_node_create(): malloc failed ===\n");
		exit(1);
	}
	*node = doubly_node_contruct(data, size);
	printf("=== doubly_node_create(): node created ===\n");

	return node;
}

struct doubly_node* doubly_forward_iterate(struct doubly *self, int index) {
	if (index == 0) {
		return self->head;
	}
	if (index < 0 || index > self->length) {
		printf("%d\n", index);
		perror("=== doubly_iterate(): invalid index ===\n");
		exit(8);
	}
	struct doubly_node *cursor = self->head;

	while(index != 0) {
		cursor = cursor->next;
		index--;
	}

	return cursor;
}

struct doubly_node* doubly_backward_iterate(struct doubly *self, int index) {
	if (index == 0) {
		return self->head;
	}
	if (index < 0 || index > self->length) {
		printf("%d\n", index);
		perror("=== doubly_iterate(): invalid index ===\n");
		exit(8);
	}
	struct doubly_node *cursor = self->tail;

	while(index != 0) {
		cursor = cursor->previous; // goes in reverse!
		index--;
	}

	return cursor;
}

void doubly_insert(struct doubly *self, int index, void *data, int size) {

	struct doubly_node *node_to_insert = doubly_node_create(self, data, size);

	if (index == 0) {

		if (self->length == 0) {
			self->tail = node_to_insert;
			node_to_insert->previous = NULL;
		}

		// ISSUE: have to update prev. node too and it ain't happening rn


	} else if (index == 1 && self->head != NULL) {
		self->head->next = node_to_insert;
		node_to_insert->previous = self->head; // storing the values in vice-versa format! node after head will keep the value of previous aka the *head* itself!

		self->tail = node_to_insert;

	} else {
		int mid_val = self->length / 2;
		struct doubly_node *position_node;

		if (mid_val < index) {
			position_node = doubly_backward_iterate(self, index);
		} else {
			position_node = doubly_forward_iterate(self, index);
		}

		node_to_insert->previous = position_node->previous;
		node_to_insert->next = position_node;
	}
	self->length++;

}

void doubly_remove(struct doubly *self, int index) {

}

void doubly_reverse(struct doubly *self) {

}

void* doubly_fetch_node(struct doubly *self, int index) {

}

void* doubly_fetch_data(struct doubly *self, int index) {

}

