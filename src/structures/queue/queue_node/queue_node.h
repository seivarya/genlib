// ====================
// | > queue_node.h |
// ====================

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue_node {
	void *data;
	struct queue_node *next;
};

struct queue_node queue_node_construct(void *data, size_t size);
void queue_node_destruct(struct queue_node *queue_node);

#endif /* queue_node_h */
