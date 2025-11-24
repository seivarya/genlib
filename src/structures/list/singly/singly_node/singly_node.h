// ====================
// | > singly_node.h |
// ====================

#ifndef SINGLY_NODE_H
#define SINGLY_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct singly_node {
	void *data;
	struct singly_node *next;
};

struct singly_node singly_node_construct(void *data, size_t size);
void singly_node_destruct(struct singly_node *singly_node);

#endif /* SINGLY_NODE_H */
