/* stknode.h: stack node interface */

#ifndef STKNODE_H
#define STKNODE_H

#include <stdlib.h>

typedef struct stknode stknode;

struct stknode {
	void *data;
	stknode *next;
};

stknode* stknode_construct(void *data, size_t size);
void stknode_destruct(stknode *node);

#endif /* stknode_h */
