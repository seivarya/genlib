// =======================
// | test: doubly_test.c |
// =======================


#include "../src/structures/list/dlist/dlist.h"
#include <assert.h>
#include <stdbool.h>

void basic_test(void);

void insert_default_test(void);
void insert_epoints_test(void);
void insert_mid_test(void);

void remove_default_test(void);
void remove_epoints_test(void);
void remove_mid_test(void);

void fetch_node_test(void);
void fetch_data_test(void);

int main(void) {

	basic_test();

	insert_default_test();
	insert_epoints_test();
	insert_mid_test();

	remove_default_test();
	remove_epoints_test();
	remove_mid_test();

	fetch_node_test();
	fetch_data_test();

	printf("=== all tests  passed ===\n");
	return 0;
}

void basic_test(void) {
	printf("=== basic_test(): initializing doubly linked list ===\n");

	struct doubly dlist;
	dlist = doubly_construct();
	
	assert(dlist.head == NULL);
	assert(dlist.tail == NULL);
	assert(dlist.length == 0);

	int head_node_data = 69;
	dlist.insert(&dlist, 0, &head_node_data, sizeof(head_node_data));

	assert(*(int *)dlist.head->data == head_node_data);
	assert(*(int *)dlist.tail->data == head_node_data);
	assert(dlist.length == 1);

	doubly_destruct(&dlist); 
	printf("\n");
}

void insert_default_test(void) {
	printf("=== insert_default_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	unsigned int val_1 = 2323;
	int val_2 = 98;
	char *val_3 = "attack on titan";
	struct val_4 {
		char *data;
		int random;
	};
	struct val_4 val_4 = {
		.data = "this is just a simple structure for testing!",
		.random = 69
	};

	printf("=== insert_default_test(): inserting data ===\n");

	dlist.insert(&dlist, 0, &val_1, sizeof(val_1));
	assert(dlist.length == 1);
	dlist.insert(&dlist, 1, &val_2, sizeof(val_2));
	assert(dlist.length == 2);
	dlist.insert(&dlist, 2, val_3, strlen(val_3) + 1);
	assert(dlist.length == 3);
	dlist.insert(&dlist, 3, &val_4, sizeof(val_4));
	assert(dlist.length == 4);

	// forward iteration
	assert(*(unsigned int *)dlist.head->data == val_1);
	assert(*(int *)dlist.head->next->data == val_2);
	assert(strcmp((char *)dlist.head->next->next->data, val_3) == 0);

	struct val_4 test = *(struct val_4 *)dlist.head->next->next->next->data;
	assert(strcmp(test.data, val_4.data) == 0);
	assert(test.random == val_4.random);

	// backward iteration
	struct val_4 test_2 = *(struct val_4 *)dlist.tail->data;
	assert(strcmp((char *)test_2.data, val_4.data) == 0);
	assert(test_2.random == val_4.random);
	assert(strcmp((char *)dlist.tail->previous->data, val_3) == 0);
	assert(*(int *)dlist.tail->previous->previous->data == val_2);
	assert(*(unsigned int *)dlist.tail->previous->previous->previous->data == val_1);

	doubly_destruct(&dlist);
	printf("=== insert_default_test(): success ===\n");
	printf("\n");
}

void insert_epoints_test(void) {
	printf("=== insert_epoints_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	char *val_3 = "huh:";
	char val_4 = 'Z';

	dlist.insert(&dlist, 0, &val_1, sizeof(val_1));
	dlist.insert(&dlist, 1, &val_2, sizeof(val_2));
	dlist.insert(&dlist, 2, val_3, strlen(val_3) + 1);
	dlist.insert(&dlist, 3, &val_4, sizeof(val_4));

	printf("=== insert_epoints_test(): inserting at head and tail ===\n");

	int val_5 = 12;
	dlist.insert(&dlist, 0, &val_5, sizeof(val_5));
	assert(dlist.length == 5);

	char val_6 = '*';
	dlist.insert(&dlist, 5, &val_6, sizeof(val_6));
	assert(dlist.length == 6);

	assert(*(int *)dlist.head->data == val_5);
	assert(*(int *)dlist.head->next->previous->data == val_5);

	assert(*(char *)dlist.tail->data == val_6);
	assert(*(char *)dlist.tail->previous->next->data == val_6);

	doubly_destruct(&dlist);
	printf("=== insert_epoints_test(): success ===\n");
	printf("\n");
}

void insert_mid_test(void) {
	printf("=== insert_mid_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	int val_1 = 90;
	char val_2 = 'W';
	char val_3 = 'Y';
	char val_4 = 'Z';
	char val_to_insert = 'X';

	printf("=== insert_mid_test(): inserting at mid index ===\n");

	dlist.insert(&dlist, 0, &val_1, sizeof(val_1));
	dlist.insert(&dlist, 1, &val_2, sizeof(val_2));
	dlist.insert(&dlist, 2, &val_3, sizeof(val_3));
	dlist.insert(&dlist, 3, &val_4, sizeof(val_4));

	assert(dlist.length == 4);

	dlist.insert(&dlist, 2, &val_to_insert, sizeof(val_to_insert));
	assert(dlist.length == 5);

	assert(*(char *)dlist.head->next->next->data == val_to_insert);
	assert(*(char *)dlist.head->next->next->next->previous->data == val_to_insert);
	assert(*(char *)dlist.head->next->next->previous->next->data == val_to_insert);

	doubly_destruct(&dlist);
	printf("=== insert_mid_test(): success ===\n");
	printf("\n");
}

void remove_default_test(void) {
	printf("=== remove_default_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	unsigned int val_1 = 2323;
	int val_2 = 98;
	char *val_3 = "attack on titan";

	struct val_4 {
		char *data;
		int random;
	};
	struct val_4 val_4 = {
		.data = "this is just a simple structure for testing!",
		.random = 69
	};

	printf("=== remove_default_test(): inserting data ===\n");

	dlist.insert(&dlist, 0, &val_1, sizeof(val_1));
	dlist.insert(&dlist, 1, &val_2, sizeof(val_2));
	dlist.insert(&dlist, 2, val_3, strlen(val_3) + 1);
	dlist.insert(&dlist, 3, &val_4, sizeof(val_4));

	printf("=== remove_default_test(): removing a node ===\n");

	dlist.remove(&dlist, 0);

	assert(*(int *)dlist.head->data == val_2);
	assert(strcmp((char *)dlist.head->next->data, val_3) == 0);

	doubly_destruct(&dlist);
	printf("=== remove_default_test(): success ===\n\n");
}

void remove_epoints_test(void) {
	printf("=== remove_epoints_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	int val_3 = 23;
	int val_4 = 123;
	char *val_5 = "huh:";
	char val_6 = 'Z';

	dlist.insert(&dlist, 0, &val_1, sizeof(val_1));
	dlist.insert(&dlist, 1, &val_2, sizeof(val_2));
	dlist.insert(&dlist, 2, &val_3, sizeof(val_3));
	dlist.insert(&dlist, 3, &val_4, sizeof(val_4));
	dlist.insert(&dlist, 4, val_5, strlen(val_5) + 1);
	dlist.insert(&dlist, 5, &val_6, sizeof(val_6));

	printf("=== remove_epoints_test(): removing head and tail ===\n");


	dlist.remove(&dlist, 0);
	dlist.remove(&dlist, 4);  // tail index after head removal

	assert(*(char *)dlist.head->data == val_2);
	assert(*(int *)dlist.head->next->data == val_3);
	assert(*(char *)dlist.head->next->previous->data == val_2);

	assert(strcmp((char *)dlist.tail->data, val_5) == 0);
	assert(*(int *)dlist.tail->previous->data == val_4);
	assert(strcmp((char *)dlist.tail->previous->next->data, val_5) == 0);

	doubly_destruct(&dlist);
	printf("=== remove_epoints_test(): success ===\n\n");
}

void remove_mid_test(void) {
	printf("=== remove_mid_test(): initializing variables ===\n");


	struct doubly dlist;
	dlist = doubly_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	int val_3 = 23;
	int val_4 = 123;
	char *val_5 = "huh:";
	char val_6 = 'Z';

	dlist.insert(&dlist, 0, &val_1, sizeof(val_1));
	dlist.insert(&dlist, 1, &val_2, sizeof(val_2));
	dlist.insert(&dlist, 2, &val_3, sizeof(val_3));
	dlist.insert(&dlist, 3, &val_4, sizeof(val_4));
	dlist.insert(&dlist, 4, val_5, strlen(val_5) + 1);
	dlist.insert(&dlist, 5, &val_6, sizeof(val_6));

	printf("=== remove_mid_test(): removing mid node ===\n");

	dlist.remove(&dlist, 2);

	assert(*(int *)dlist.head->next->next->data == val_4);
	assert(*(int *)dlist.head->next->next->next->previous->data == val_4);
	assert(*(int *)dlist.head->next->next->previous->next->data == val_4);

	doubly_destruct(&dlist);
	printf("=== remove_mid_test(): success ===\n\n");
}

void fetch_node_test(void) {
	printf("=== fetch_node_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	int data = 45;
	dlist.insert(&dlist, 0, &data, sizeof(data));

	struct doubly_node *fetched_node = dlist.fetch_node(&dlist, 0);
	assert(*(int *)fetched_node->data == data);

	doubly_destruct(&dlist);
	printf("=== fetch_node_test(): success ===\n");
}

void fetch_data_test(void) {
	printf("=== fetch_data_test(): initializing variables ===\n");

	struct doubly dlist;
	dlist = doubly_construct();

	int data = 45;
	dlist.insert(&dlist, 0, &data, sizeof(data));

	int fetched_data = *(int *)dlist.fetch_data(&dlist, 0);
	assert(fetched_data == data);

	doubly_destruct(&dlist);
	printf("=== fetch_data_test(): success ===\n");
} /* doubly_test_c */
