#ifndef SINGLY_NODE_H
#define SINGLY_NODE_H

struct singly_node {
	void *data;
	struct singly_node *next;
};

struct singly_node singly_node_construct(void *data, int size);
void singly_node_destruct(struct singly_node *singly_node);

#endif /* SINGLY_NODE_H */
