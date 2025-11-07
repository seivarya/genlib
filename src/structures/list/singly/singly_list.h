#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include "../../../node/node.h"  //  FIX: maybe fix this? later

struct singly {

	struct node *head;
	int length;

	// methods
	void (*insert_singly)(struct singly *self, void *data, int size);
	void (*remove_singly)(struct singly *self, int index);

	void* (*retrieve_singly)(struct singly *self, int index);
	void* (*search_singly)(struct singly *self, struct node *node);

};

struct singly singly_construct();
void singly_destruct(struct singly *singly);

#endif

