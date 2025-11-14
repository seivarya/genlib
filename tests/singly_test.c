#include <stdio.h>

#include "../src/structures/list/singly/singly_list.h"


int main(void) {
	struct singly singly_list = singly_construct();

	int val_one = 1;
	int val_two = 2;
	int val_three = 3;
	int val_four = 4;

	singly_list.insert(&singly_list, 0, &val_one, sizeof(int));
	singly_list.insert(&singly_list, 1, &val_two, sizeof(int));
	singly_list.insert(&singly_list, 2, &val_three, sizeof(int));
	singly_list.insert(&singly_list, 3, &val_four, sizeof(int));

	printf("=== nodes values after insertion ===\n");

	struct singly_node *node = singly_list.head;
	for(int i = 0; i < singly_list.length; i++) {
		int value = *(int *)node->data;

		node = node->next;
		printf("index: [%d] | value: [%d]\n", i, value);
	}

	singly_list.reverse(&singly_list);

	printf(" === after reverse === \n");
	struct singly_node *new_node = singly_list.head;
	for(int i = 0; i < singly_list.length; i++) {
		int value = *(int *)new_node->data;

		new_node = new_node->next;
		printf("index: [%d] | value: [%d]\n", i, value);
	}
	return 0;
}
