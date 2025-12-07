#ifndef BNODE_H
#define BNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bt_node {
	void *data;
	struct bt_node *next;
	struct bt_node *previous;
};

struct bt_node bt_node_construct(void *data, size_t size);
void bt_node_destruct(struct bt_node *bt_node);

#endif /* bnode_h */
