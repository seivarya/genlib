#ifndef CIRCULAR_NODE_H
#define CIRCULAR_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circular_node {
	void *data;
	struct circular_node *next;
	struct circular_node *previous; 
};

struct circular_node circular_node_construct(void *data, size_t size);
void circular_node_destruct(struct circular_node *circular_node);

#endif
