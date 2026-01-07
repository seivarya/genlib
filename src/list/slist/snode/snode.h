/* snode.h: singly linked list node interface */

#ifndef SNODE_H
#define SNODE_H

#include <stdlib.h>

typedef struct snode snode;

struct snode {
	void *data;
	snode *next;
};

snode* snode_construct(void *data, size_t size);
void snode_destruct(snode *node);

#endif /* snode_h */
