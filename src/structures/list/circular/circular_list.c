// =====================
// | > circular_list.c |
// =====================

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
		.tail = NULL,            // tail shall always start equal to head
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
	printf("=== destructing circular list ===");

	if (!cll_validate_list(circular)) return;
	if (!cll_validate_list_head(circular)) return;

	// oh maybe i set the tail to NULL and then do the same iteration of list destructor

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

	struct circular_node *cursor;
	cursor = self->head;

	while(index != 0) {
		cursor = cursor->next;
		index--;
	}
	return cursor;
}

void circular_insert(struct circular *self, size_t index, void *data, size_t size) {
	if (index > self->length) return;
	if (!cll_validate_list(self)) return;

	struct circular_node *node_to_insert;
	node_to_insert = circular_node_create(self, data, size);

	if (index == 0) {
		if (self->length == 0) {

		}
	}
}


void circular_remove(struct circular *self, size_t index) {

}

void circular_reverse(struct circular *self) {

}

void* circular_fetch_node(struct circular *self, size_t index) {

}

void* circular_fetch_data(struct circular *self, size_t index) {

}
