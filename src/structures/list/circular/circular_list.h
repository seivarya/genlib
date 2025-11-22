#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "circular_node/circuler_node.h"

struct circular {
	struct circular_node *head;
	struct circular_node *tail;
	
	size_t length;

	void (*insert)(struct circular *self, size_t index, void *data, size_t size);
	void (*remove)(struct circular *self, size_t index);
	void (*reverse)(struct circular *self);

	void* (*fetch_node)(struct circular *self, size_t index);
	void* (*fetch_data)(struct circular *self, size_t index);
};

struct circular circular_construct(void);
void circular_destruct(struct circular *circular);

static inline int cll_validate_list(struct circular *circular) {
	if (!circular) {
		fprintf(stderr, "[ERROR]: list doesn't exist\n");
		return 0;
	}
	return 1;
}

static inline int cll_validate_index(struct circular *circular, size_t index) {
	if (index >= circular->length) {
		fprintf(stderr, "[ERROR]: index out of bounds (got %zu, length %zu)\n",
	  index, circular->length);
		return 0;
	}
	return 1;
}

static inline int cll_validate_list_head(struct circular *circular) {
	if (!circular->head) {
		fprintf(stderr, "[ERROR]: head is NULL\n");
		return 0;
	}
    return 1;
}

#endif
