#include "../src/node/node.h"
#include "../src/structures/list/singly/singly_list.h"
#include <stdio.h>

int main(void) { struct singly list = singly_construct(); 
	int data_one = 23;
	int data_two = 24;
	int data_three = 25;
	int data_four = 26;

	list.insert_singly(&list, 0, &data_one, sizeof(int));
	list.insert_singly(&list, 1, &data_two, sizeof(int));
	list.insert_singly(&list, 2, &data_three, sizeof(int));
	list.insert_singly(&list, 3, &data_four, sizeof(int));

	struct node *node= (struct node*)list.head;
	printf("head node: [%d]\n\n", *(int *)node->data);

	for (int i = 0; i < list.length; i++) {
		struct node *node= (struct node*)list.retrieve_singly_node(&list, i);
		printf("node data: [%d]\n", *(int *)node->data);
	}

	list.reverse_singly(&list);
	printf("=== AFTER REVERSE === \n");

	for (int i = 0; i < list.length; i++) {
		struct node *node= (struct node*)list.retrieve_singly_node(&list, i);
		printf("node data: [%d]\n", *(int *)node->data);
	}
	printf("=== data fetch ===\n");

	for (int i = 0; i < list.length; i++) {
		printf("node data: [%d]\n", *(int *)list.retrieve_singly_data(&list, i));
	}
}
