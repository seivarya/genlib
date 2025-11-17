#ifndef DOUBLY_NODE_H
#define DOUBLY_NODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct doubly_node {
	void *data;
	struct doubly_node *next;
	struct doubly_node *previous; // uh
};

struct doubly_node doubly_node_contruct(void *data, int size);
void doubly_node_destruct(struct doubly_node *doubly_node);

#endif
