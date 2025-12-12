/* cnode.h: circular linked list node interface */

#ifndef CNODE_H
#define CNODE_H

#include <stdlib.h>

typedef struct cnode cnode;

struct cnode {
	void *data;
	cnode *next;
	cnode *previous;
};

cnode* cnode_construct(void *data, size_t size);
void cnode_destruct(cnode *node);

#endif /* cnode_h */
