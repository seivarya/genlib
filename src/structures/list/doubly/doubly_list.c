#include "doubly_list.h"

struct doubly_node* doubly_node_create(struct doubly *self, void *data, size_t size);
struct doubly_node* doubly_iterate(struct doubly *self, size_t index);

void doubly_insert(struct doubly *self, size_t index, void *data, size_t size);
void doubly_remove(struct doubly *self, size_t index);
void doubly_reverse(struct doubly *self);

void* doubly_fetch_node(struct doubly *self, size_t index);
void* doubly_fetch_data(struct doubly *self, size_t index);

struct doubly doubly_construct(void) {
	struct doubly list= {
		.head = NULL,
		.tail = NULL,
		.length = 0,
		.insert = doubly_insert,
		.remove = doubly_remove,
		.reverse = doubly_reverse,
		.fetch_data = doubly_fetch_data,
		.fetch_node = doubly_fetch_node
	};
	return list;
}

void doubly_destruct(struct doubly *doubly) {
	if (!dll_validate_list(doubly)) return;
	if (!dll_validate_list_head(doubly)) return;

	struct doubly_node *current = doubly->head;
	struct doubly_node *next;

	while (current != NULL) {
		next = current->next;
		doubly_node_destruct(current);
		current = next;
	}

	doubly->head = NULL;
	doubly->tail = NULL;
	doubly->length = 0;
}

struct doubly_node* doubly_node_create(struct doubly *self, void *data, size_t size) {
	if (!dll_validate_list(self)) return NULL;

	struct doubly_node *node = malloc(sizeof(struct doubly_node));
	if (!node) {
		exit(1);
	}
	*node = doubly_node_construct(data, size);
	return node;
}

struct doubly_node* doubly_iterate(struct doubly *self, size_t index) {
	if (index == 0) return self->head;
	if (index == self->length - 1) return self->tail;

	struct doubly_node *cursor = self->head;
	while (index != 0) {
		cursor = cursor->next;
		index--;
	}
	return cursor;
}

void doubly_insert(struct doubly *self, size_t index, void *data, size_t size) {
	if (index > self->length) return;
	if (!dll_validate_list(self)) return;

	struct doubly_node *node_to_insert = doubly_node_create(self, data, size);

	if (index == 0) {
		if (self->length == 0) { 
			self->head = node_to_insert;
			self->tail = node_to_insert;
			self->length++;
			return;
		}

		node_to_insert->next = self->head;
		self->head->previous = node_to_insert;
		self->head = node_to_insert;

	} else if (index == self->length) {
		node_to_insert->previous = self->tail;
		self->tail->next = node_to_insert;
		self->tail = node_to_insert;
	} else {
		struct doubly_node *on_index_node = doubly_iterate(self, index);

		node_to_insert->previous = on_index_node->previous;
		node_to_insert->next = on_index_node;
		
		on_index_node->previous->next = node_to_insert;
		on_index_node->previous = node_to_insert;
	}

	self->length++;
}

void doubly_remove(struct doubly *self, size_t index) {
	if (!dll_validate_list(self) || !dll_validate_index(self, index)) return;

	struct doubly_node *node_to_remove;

	if (index == 0) {
		node_to_remove = self->head;

		if (self->head->next) {
			self->head = self->head->next;
			self->head->previous = NULL;
		} else {
			self->head = NULL;
			self->tail = NULL;
		}

	} else if (index == self->length - 1) {
		node_to_remove = self->tail;
		self->tail->previous->next = NULL;
		self->tail = self->tail->previous;

	} else {
		node_to_remove = doubly_iterate(self, index);
		node_to_remove->previous->next = node_to_remove->next;
		node_to_remove->next->previous = node_to_remove->previous;
	}

	doubly_node_destruct(node_to_remove);
	self->length--;
}

void doubly_reverse(struct doubly *self) {
	if (!dll_validate_list(self)) return;

	struct doubly_node *current = self->head;
	struct doubly_node *temp = NULL;

	self->tail = self->head;

	while (current != NULL) {
		temp = current->previous;
		current->previous = current->next;
		current->next = temp;

		current = current->previous;
	}

	if (temp != NULL)
		self->head = temp->previous;
}

void* doubly_fetch_node(struct doubly *self, size_t index) {
	if (!dll_validate_list(self) || !dll_validate_index(self, index)) return NULL;

	struct doubly_node *fetched_node = doubly_iterate(self, index);
	if (!fetched_node) return NULL;

	return fetched_node;
}

void* doubly_fetch_data(struct doubly *self, size_t index) {
	if (!dll_validate_list(self) || !dll_validate_index(self, index)) return NULL;

	struct doubly_node *fetched_node = doubly_iterate(self, index);
	if (!fetched_node) return NULL;

	return fetched_node->data;
} /* DOUBLY_LIST_C */
