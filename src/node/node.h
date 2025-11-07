#ifndef NODE_H
#define NODE_H

struct node {
	void *data;

	struct node *next;
	struct node *previous; //  ISSUE: if user is a dumbass, they can cause unexpected errors by using this. 
};

struct node node_construct(void *data, int size);
void node_destruct(struct node *node);

#endif /* NODE_H */
