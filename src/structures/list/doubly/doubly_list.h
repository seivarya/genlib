// ====================
// | > doubly_list.h |
// ====================

#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include "doubly_node/doubly_node.h"

struct doubly {
	struct doubly_node *head;
	struct doubly_node *tail;
	size_t length;
	
	void (*insert)(struct doubly *self, size_t index, void *data, size_t size);
	void (*remove)(struct doubly *self, size_t index);
	void (*reverse)(struct doubly *self);

	void* (*fetch_node)(struct doubly *self, size_t index);
	void* (*fetch_data)(struct doubly *self, size_t index);
};

struct doubly doubly_construct(void);
void doubly_destruct(struct doubly *doubly);


static inline int dll_validate_list(struct doubly *doubly) {
	if (!doubly || doubly == NULL) {
		fprintf(stderr, "[ERROR]: list doesn't exist\n");
		return 0;
	}
	return 1;
}

static inline int dll_validate_index(struct doubly *doubly, size_t index) {
	if (index >= doubly->length) {
		fprintf(stderr, "[ERROR]: index out of bounds (got %zu, length %zu)\n",
	  index, doubly->length);
		return 0;
	}
	return 1;
}

static inline int dll_validate_list_head(struct doubly *doubly) {
	if (!doubly->head) {
		fprintf(stderr, "[ERROR]: head is NULL\n");
		return 0;
	}
    return 1;
}

#endif
