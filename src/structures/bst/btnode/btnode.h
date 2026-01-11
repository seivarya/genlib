/* btnode.h: binary search tree node interface */

#ifndef BTNODE_H
#define BTNODE_H

#include <stdlib.h>

typedef struct btnode btnode;

struct btnode {
	void *data;
	btnode *next;
};

btnode* btnode_construct(void *data, size_t size);
void btnode_destruct(btnode* node);

#endif /* btnode_h */
