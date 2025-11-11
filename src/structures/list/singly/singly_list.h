#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include "../../../node/node.h"  //  FIX: maybe fix this? later

struct singly {

	struct node *head;
	int length;

	void (*insert_singly)(struct singly *self, int index, void *data, int size);
	void (*remove_singly)(struct singly *self, int index);
	void (*reverse_singly)(struct singly *self);

	void* (*retrieve_singly_node)(struct singly *self, int index);
	void* (*retrieve_singly_data)(struct singly *self, int index);
};

struct singly singly_construct();
void singly_destruct(struct singly *singly);

#endif /* SINGLY_LIST_H */
