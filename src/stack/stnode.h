/* stnode.h: stack node interface */

#ifndef STNODE_H
#define STNODE_H

#include <stdlib.h>

typedef struct stnode stnode;

struct stnode {
	void *data;
	stnode *next;
};

stnode* stnode_construct(void *data, size_t size);
void stnode_destruct(stnode *node);

#endif /* stnode_h */
