#ifndef QNODE_H
#define QNODE_H

#include <stdlib.h>

typedef struct qnode qnode;

struct qnode {
	void *data;
	qnode *next;
};

qnode* qnode_construct(void *data, size_t size);
void qnode_destruct(qnode *node);

#endif /* qnode_h */
