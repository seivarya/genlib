#ifndef STACK_NODE_H
#define STACK_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_node {
	void *data;
	struct stack_node *next;
};

struct stack_node stack_node_construct(size_t size, void *data);
void stack_node_destruct(struct stack_node *stack_node);

#endif /* stack_node_c */
