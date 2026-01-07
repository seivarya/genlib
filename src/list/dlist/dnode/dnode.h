/* dnode.h: doubly linked list node interface */

#ifndef DNODE_H
#define DNODE_H

#include <stdlib.h>

typedef struct dnode dnode;

struct dnode {
	void *data;
	dnode *next;
	dnode *previous;
};

dnode* dnode_construct(void *data, size_t size);
void dnode_destruct(dnode *node);

#endif /* dnode_h */
