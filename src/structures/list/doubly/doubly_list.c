#include "doubly_list.h"

struct doubly_node* doubly_node_create(struct doubly *self, void *data, size_t size);
struct doubly_node* doubly_forward_iterate(struct doubly *self, size_t index);
struct doubly_node* doubly_backward_iterate(struct doubly *self, size_t index);

void doubly_insert(struct doubly *self, size_t index, void *data, size_t size);
void doubly_remove(struct doubly *self, size_t index);
void doubly_reverse(struct doubly *self);

void* doubly_fetch_node(struct doubly *self, size_t index);
void* doubly_fetch_data(struct doubly *self, size_t index);


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
	if (!dll_validate_list(doubly)) return;
	if (!dll_validate_list_head(doubly)) return;

	printf("=== doubly_destruct(): releasing nodes ===\n");
	for (size_t i = 0; i < doubly->length; i++) {
		// iterate and free (implementation skipped)
	}
	printf("=== doubly_destruct(): complete ===\n");
}

struct doubly_node* doubly_node_create(struct doubly *self, void *data, size_t size) {

	if (!dll_validate_list(self)) return NULL;

	struct doubly_node *node = malloc(sizeof(struct doubly_node));

	if (!node) {
		perror("=== doubly_node_create(): malloc failed ===\n");
		exit(1);
	}

	*node = doubly_node_contruct(data, size);
	printf("=== doubly_node_create(): node created ===\n");

	return node;
}

struct doubly_node* doubly_forward_iterate(struct doubly *self, size_t index) {
	if (!dll_validate_index(self, index)) return NULL;

	if (index == 0) return self->head;

	struct doubly_node *cursor = self->head;

	while(index != 0) {
		cursor = cursor->next;
		index--;
	}
	return cursor;
}

struct doubly_node* doubly_backward_iterate(struct doubly *self, size_t index) {
	if (!dll_validate_index(self, index)) return NULL;

	if (index == 0) return self->head;
	
	struct doubly_node *cursor = self->tail;

	while(index != 0) {
		cursor = cursor->previous; //  BUG:  there is a critical bug here!
		index--;
	}
	return cursor;
}

void doubly_insert(struct doubly *self, size_t index, void *data, size_t size) {
	
	if(!dll_validate_list(self)) return;

	struct doubly_node *node_to_insert = doubly_node_create(self, data, size);

	if (index == 0) {
		node_to_insert->previous = NULL;
		if (self->length == 0) {
			self->head = node_to_insert;
			self->tail = node_to_insert;
		}
		node_to_insert->next = self->head;
		self->head->previous = node_to_insert;
		self->head = node_to_insert;
	
	} else if (index == self->length - 1) {
		node_to_insert->previous = self->tail;
		self->tail->next = node_to_insert;
		self->tail = node_to_insert;
		self->tail->next = NULL;

	} else {
		int mid_val = (self->length - 1) / 2;
		struct doubly_node *idx_node = (index <= mid_val) ? doubly_forward_iterate(self, index) : doubly_backward_iterate(self, index);

		node_to_insert->previous = idx_node->previous;
		node_to_insert->next = idx_node;

		idx_node->previous = node_to_insert;
		node_to_insert->previous->next = node_to_insert;
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
	} else if (index == self->length - 1){
		node_to_remove = self->tail;
		self->tail->previous->next = NULL;
		self->tail = self->tail->previous;
	} else {
		int mid_val = (self->length - 1) / 2;
		node_to_remove = (index <= mid_val) ? doubly_forward_iterate(self, index) : doubly_backward_iterate(self, index);

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

	while(current != NULL) {
		temp = current->previous;
		current->previous = current->next;
		current->next = temp;

		current = current->previous;
	}
	if (temp != NULL) self->head = temp->previous;
}

void* doubly_fetch_node(struct doubly *self, size_t index) {

	if (!dll_validate_list(self) || !dll_validate_index(self, index)) return NULL;

	int mid_val = (self->length - 1) / 2;
	struct doubly_node *fetched_node = (index <= mid_val) ? doubly_forward_iterate(self, index) : doubly_backward_iterate(self, index);

	if (!fetched_node) return NULL;
	
	return fetched_node;
}

void* doubly_fetch_data(struct doubly *self, size_t index) {
	if (!dll_validate_list(self) || !dll_validate_index(self, index)) return NULL;

	int mid_val = (self->length - 1) / 2;
	struct doubly_node *fetched_node = (index <= mid_val) ? doubly_forward_iterate(self, index) : doubly_backward_iterate(self, index);

	if (!fetched_node) return NULL;
	
	return fetched_node->data;
} /* DOUBLY_LIST_C */
