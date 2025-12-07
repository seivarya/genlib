#ifndef BST_H
#define BST_H

#include "bnode/bnode.h"

struct bst {
	struct bt_node *head;
	size_t length;
};

struct bst bst_construct(int *(compare)(void *data_fir, void *data_sec));
void bst_destruct(struct bst *bst);

#endif /* bst_h */
