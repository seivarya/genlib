// ===================================================================================
// | > circular_list.c | note: circular_list is based on circular circular linked list |
// ===================================================================================

#include "circular_list.h"

struct circular_node* circular_node_create(struct circular *self, void *data, size_t size);
struct circular_node* circular_iterate(struct circular *self, size_t index);

void circular_insert(struct circular *self, size_t index, void *data, size_t size);
void circular_remove(struct circular *self, size_t index);
void circular_reverse(struct circular *self);

void* circular_fetch_node(struct circular *self, size_t index);
void* circular_fetch_data(struct circular *self, size_t index);


struct circular circular_construct(void) {

	printf("=== circular_construct(): invoked === \n");

	struct circular list = {
		.head = NULL,
		.tail = NULL, // tail shall always start equal to head
		.length = 0,
		.insert = circular_insert,
		.remove = circular_remove,
		.reverse = circular_reverse,
		.fetch_node = circular_fetch_node,
		.fetch_data = circular_fetch_data
	};
	return list;
}

void circular_destruct(struct circular *circular) {
	printf("=== destructing circular list ===\n");

	if (!cll_validate_list(circular)) return;
	if (!cll_validate_list_head(circular)) return;

	circular->tail->next = NULL;
	struct circular_node *current = circular->head;
	struct circular_node *next = NULL;
	while(current != NULL) {
		next = current->next;
		circular_node_destruct(current);
		current = next;
	}
	circular->head = NULL;
	circular->length = 0;
}

struct circular_node* circular_node_create(struct circular *self, void *data, size_t size) {
	if (!cll_validate_list(self)) return NULL;

	struct circular_node *node = malloc(sizeof(struct circular));

	if (!node) {
		perror("=== circular_node_create(): malloc failed ===\n");
		exit(1);
	}
	*node = circular_node_construct(data, size);
	return node;
}

struct circular_node* circular_iterate(struct circular *self, size_t index) {
	if (index == 0) return self->head;
	if (index == self->length - 1) return self->tail;

	size_t mid_idx = (self->length / 2) + 1;
	if (index < mid_idx) {
		struct circular_node *cursor = self->head;
		while (index != 0) {
			cursor = cursor->next;
			index--;
		}
		return cursor;
	}
	struct circular_node *cursor = self->tail;
	while(index != 0) {
		cursor = cursor->previous;
		index--;
	}
	return cursor;
}

void circular_insert(struct circular *self, size_t index, void *data, size_t size) {
	if (index > self->length) return;
	if (!cll_validate_list(self)) return;

	struct circular_node *node_to_insert;
	node_to_insert = circular_node_create(self, data, size);
	if (!node_to_insert) return;

	if (index == 0) {

		if (self->length == 0) {
			self->head = node_to_insert;
			self->tail = node_to_insert;

			node_to_insert->next = node_to_insert;
			node_to_insert->previous = node_to_insert;

			self->length++;
			return;
		}

		node_to_insert->next = self->head;
		node_to_insert->previous = self->tail;
		self->head->previous = node_to_insert;
		self->tail->next = node_to_insert;

		self->head = node_to_insert;

	} else if (index == self->length) {  // insertion at tail is required

		node_to_insert->previous = self->tail;
		node_to_insert->next = self->head;
		self->tail->next = node_to_insert;
		self->head->previous = node_to_insert;

		self->tail = node_to_insert;

	} else {
		struct circular_node *on_index_node = circular_iterate(self, index);

		node_to_insert->previous = on_index_node->previous;
		node_to_insert->next = on_index_node;

		on_index_node->previous->next = node_to_insert;
		on_index_node->previous = node_to_insert;
	}
	self->length++;
}

void circular_remove(struct circular *self, size_t index) {
	if(!cll_validate_list(self)) return;
	if (!cll_validate_index(self, index)) return;

	struct circular_node *node_to_remove; // maybe this should be NULL??
	if (index == 0) {
		if (self->length == 1)  {
			self->head = NULL;
			self->tail = NULL;
			self->length = 0;
			return;
		}
		node_to_remove = self->head;
		self->head = node_to_remove->next;
		self->head->previous = self->tail;
		self->tail->next = self->head;
	} else if (index == self->length - 1) {
		node_to_remove = self->tail;
		node_to_remove->previous->next = self->head;
		self->head->previous = node_to_remove->previous;
		self->tail = node_to_remove->previous;
	} else {
		node_to_remove = circular_iterate(self, index);
		node_to_remove->previous->next = node_to_remove->next;
		node_to_remove->next->previous = node_to_remove->previous;
	}

	circular_node_destruct(node_to_remove);
	self->length--;
}

void circular_reverse(struct circular *self) {
	if(!cll_validate_list(self)) return;
	if (!cll_validate_list_head(self)) return;
	if (self->length == 1) return;

	// too stupid rn to do this.
}

void* circular_fetch_node(struct circular *self, size_t index) {
	if (!cll_validate_list(self)) return NULL;
	if (!cll_validate_index(self, index)) return NULL;

	struct circular_node *fetched_node = circular_iterate(self, index);
	if (!fetched_node) return NULL;
	return fetched_node;
}

void* circular_fetch_data(struct circular *self, size_t index) {	
	if (!cll_validate_list(self)) return NULL;
	if (!cll_validate_index(self, index)) return NULL;

	struct circular_node *fetched_node = circular_iterate(self, index);
	if (!fetched_node) return NULL;
	return fetched_node->data;
} /* circular_list_c */
