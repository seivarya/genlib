#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include "singly_node/singly_node.h"

struct singly {
	struct singly_node *head;
	int length;

	void (*insert)(struct singly *self, int index, void *data, int size);
	void (*remove)(struct singly *self, int index);
	void (*reverse)(struct singly *self);

	void* (*fetch_node)(struct singly *self, int index);
	void* (*fetch_data)(struct singly *self, int index);
};

struct singly singly_construct(void);
void singly_destruct(struct singly *singly);

#endif /* SINGLY_LIST_H */
