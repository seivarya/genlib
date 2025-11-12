#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include "doubly_node/doubly_node.h"

struct doubly {
	struct doubly_node *head;
	struct doubly_node *tail;
	int length;
	
	void (*insert)(struct doubly *self, int index, void *data, int size);
	void (*remove)(struct doubly *self, int index);
	void (*reverse)(struct doubly *self);

	void* (*fetch_node)(struct doubly *self, int index);
	void* (*fetch_data)(struct doubly *self, int index);
};

struct doubly doubly_construct();
void doubly_destruct(struct doubly *doubly);
#endif
