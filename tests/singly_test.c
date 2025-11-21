#include <stdio.h>

#include "../src/structures/list/singly/singly_list.h"

int main(void) {
	struct singly singly_list = singly_construct();

	int val_one = 1;
	int val_two = 2;
	int val_three = 3;
	int val_four = 4;
	int val_test = 3223;
	singly_list.insert(&singly_list, 0, &val_one, sizeof(int));
	singly_list.insert(&singly_list, 1, &val_two, sizeof(int));
	singly_list.insert(&singly_list, 2, &val_three, sizeof(int));
	singly_list.insert(&singly_list, 3, &val_four, sizeof(int));

	printf("=== nodes values after insertion ===\n");

	struct singly_node *node = singly_list.head;
	for(size_t i = 0; i < singly_list.length; i++) {
		int value = *(int *)node->data;

		node = node->next;
		printf("index: [%zu] | value: [%d]\n", i, value);
	}

	singly_list.reverse(&singly_list);

	printf(" === after reverse === \n");
	struct singly_node *new_node = singly_list.head;
	for(size_t i = 0; i < singly_list.length; i++) {
		int value = *(int *)new_node->data;

		new_node = new_node->next;
		printf("index: [%zu] | value: [%d]\n", i, value);
	}
	singly_list.insert(&singly_list, 1, &val_test, sizeof(int));
	struct singly_node *test_node = singly_list.fetch_node(&singly_list, 1);
	printf("fetched data: %d\n", *(int *)test_node->data);

	int data = *(int *)singly_list.fetch_data(&singly_list, 1);
	printf("fetched data through fetch_data: %d\n", data);
	return 0;
}
