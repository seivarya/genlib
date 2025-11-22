#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include "singly_node/singly_node.h"



struct singly {
	struct singly_node *head;
	size_t length;

	void (*insert)(struct singly *self, size_t index, void *data, size_t size);
	void (*remove)(struct singly *self, size_t index);
	void (*reverse)(struct singly *self);

	void* (*fetch_node)(struct singly *self, size_t index);
	void* (*fetch_data)(struct singly *self, size_t index);
};

struct singly singly_construct(void);
void singly_destruct(struct singly *singly);

static inline int sll_validate_list(struct singly *singly) {
	if (!singly || singly == NULL) return 0;
	if (!singly) {
		fprintf(stderr, "[ERROR]: list doesn't exist\n");
		return 0;
	}
	return 1;
}

static inline int sll_validate_index(struct singly *singly, size_t index) {
	if (!singly) return 0;
	if (index >= singly->length) {
		fprintf(stderr, "[ERROR]: index out of bounds (got %zu, length %zu)\n",
	  index, singly->length);
		return 0;
	}
	return 1;
}

static inline int sll_validate_list_head(struct singly *singly) {
	if (!singly) return 0;
	if (!singly->head) {
		fprintf(stderr, "[ERROR]: head is NULL\n");
		return 0;
	}
    return 1;
}

#endif /* SINGLY_LIST_H */
