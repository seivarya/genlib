#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *previous;
};

struct list {
	struct node *head;
	struct node *tail;

	int length;
	void (*reverse)(struct list *self);
};

void reverse(struct list *self) {
	struct node *current = self->head;
	struct node  *temp = NULL;
	self->tail = self->head;

	while(current != NULL) {
		temp = current->previous; // stores NULL
		current->previous = current->next; // stores second node
		current->next = temp;

		current = current->previous;
	}
	self->head = temp->previous;
}

int main(void) {
	struct node one;
	one.data = 1;

	struct node two;
	two.data = 2;

	struct node three;
	three.data = 3;

	struct node four;
	four.data = 4;

	struct list list;

	list.reverse = reverse;

	list.head = &one;
	list.head->previous = NULL;

	list.head->next = &two;
	list.head->next->previous = &one;

	list.head->next->next = &three;
	list.head->next->next->previous = &two;

	list.head->next->next->next = &four;
	list.head->next->next->next->previous = &three;

	list.tail = &four;

	list.length = 3;
	struct node *current = list.head;
	for (int i = 0; i < 4; i++) {
		int value = current->data;
		printf("index: [%d] | value: [%d]\n", i, value);
		current = current->next;
	}
	
	printf("==== previous pointer iteration ====\n");

	struct node *previous = list.tail;
	for (int i = 0; i < 4; i++) {
		int value = previous->data;
		printf("index: [%d] | value: [%d]\n", i, value);
		previous = previous->previous;
	}
	
	list.reverse(&list);

	printf("after reverse func:\n");

	struct node *new_current = list.head;
	for (int i = 0; i < 4; i++) {
		int value = new_current->data;
		printf("index: [%d] | value: [%d]\n", i, value);
		new_current = new_current->next;
	}
	return 0;
}
