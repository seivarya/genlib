// =======================
// | test: circular_test.c |
// =======================

#include <assert.h>
#include <stdbool.h>
#include "../src/structures/list/clist/clist.h"

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
	printf("=== [test]: circular linked list > running tests ===\n");

	basic_test();

	insert_default_test();
	insert_epoints_test();
	insert_mid_test();

	remove_default_test();
	remove_epoints_test();
	remove_mid_test();

	fetch_node_test();
	fetch_data_test();

	printf("=== all tests passed ===\n");
	return 0;
}


void basic_test(void) {
	struct circular clist = circular_construct();

	assert(clist.head == NULL);
	assert(clist.tail == NULL);
	assert(clist.length == 0);

	int hero_node = 69;
	clist.insert(&clist, 0, &hero_node, sizeof(hero_node));

	assert(*(int *)clist.head->data == hero_node);
	assert(*(int *)clist.tail->data == hero_node);

	assert(*(int *)clist.head->next->data == hero_node);
	assert(*(int *)clist.tail->next->data == hero_node);

	assert(*(int *)clist.head->previous->data == hero_node);
	assert(*(int *)clist.tail->previous->data == hero_node);

	circular_destruct(&clist);
}

void insert_default_test(void) {
	printf("=== insert_default_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

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

	clist.insert(&clist, 0, &val_1, sizeof(val_1));
	assert(clist.length == 1);

	clist.insert(&clist, 1, &val_2, sizeof(val_2));
	assert(clist.length == 2);

	clist.insert(&clist, 2, val_3, strlen(val_3) + 1);
	assert(clist.length == 3);

	clist.insert(&clist, 3, &val_4, sizeof(val_4));
	assert(clist.length == 4);

	// validate forward direction
	assert(*(unsigned int *)clist.head->data == val_1);
	assert(*(int *)clist.head->next->data == val_2);
	assert(strcmp((char *)clist.head->next->next->data, val_3) == 0);

	struct val_4 test = *(struct val_4 *)clist.head->next->next->next->data;
	assert(strcmp(test.data, val_4.data) == 0);
	assert(test.random == val_4.random);

	// validate circular tail linkage
	struct val_4 *fetched = (struct val_4 *)clist.tail->previous->next->data;
	assert(strcmp(fetched->data, val_4.data) == 0);
	assert(clist.tail->next == clist.head);
	assert(clist.head->previous == clist.tail);

	circular_destruct(&clist);
	printf("=== insert_default_test(): success ===\n\n");
}

void insert_epoints_test(void) {
	printf("=== insert_epoints_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	char *val_3 = "huh:";
	char val_4 = 'Z';

	clist.insert(&clist, 0, &val_1, sizeof(val_1));
	clist.insert(&clist, 1, &val_2, sizeof(val_2));
	clist.insert(&clist, 2, val_3, strlen(val_3) + 1);
	clist.insert(&clist, 3, &val_4, sizeof(val_4));

	printf("=== insert_epoints_test(): inserting head and tail ===\n");

	int val_5 = 12;
	clist.insert(&clist, 0, &val_5, sizeof(val_5));
	assert(*(int *)clist.head->data == val_5);

	char val_6 = '*';
	clist.insert(&clist, 5, &val_6, sizeof(val_6));
	assert(*(char *)clist.tail->data == val_6);

	// circular wraparound
	assert(clist.head->previous == clist.tail);
	assert(clist.tail->next == clist.head);

	circular_destruct(&clist);
	printf("=== insert_epoints_test(): success ===\n\n");
}

void insert_mid_test(void) {
	printf("=== insert_mid_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	int val_1 = 90;
	char val_2 = 'W';
	char val_3 = 'Y';
	char val_4 = 'Z';
	char val_to_insert = 'X';

	printf("=== insert_mid_test(): inserting at mid index ===\n");

	clist.insert(&clist, 0, &val_1, sizeof(val_1));
	clist.insert(&clist, 1, &val_2, sizeof(val_2));
	clist.insert(&clist, 2, &val_3, sizeof(val_3));
	clist.insert(&clist, 3, &val_4, sizeof(val_4));

	assert(clist.length == 4);

	clist.insert(&clist, 2, &val_to_insert, sizeof(val_to_insert));
	assert(clist.length == 5);

	assert(*(char *)clist.head->next->next->data == val_to_insert);
	assert(*(char *)clist.head->next->next->next->previous->data == val_to_insert);

	circular_destruct(&clist);
	printf("=== insert_mid_test(): success ===\n\n");
}

void remove_default_test(void) {
	printf("=== remove_default_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	unsigned int val_1 = 2323;
	int val_2 = 98;
	char *val_3 = "attack on titan";

	clist.insert(&clist, 0, &val_1, sizeof(val_1));
	clist.insert(&clist, 1, &val_2, sizeof(val_2));
	clist.insert(&clist, 2, val_3, strlen(val_3) + 1);

	printf("=== remove_default_test(): removing head ===\n");

	clist.remove(&clist, 0);

	assert(*(int *)clist.head->data == val_2);
	assert(strcmp((char *)clist.head->next->data, val_3) == 0);
	assert(clist.head->previous == clist.tail);

	circular_destruct(&clist);
	printf("=== remove_default_test(): success ===\n\n");
}

void remove_epoints_test(void) {
	printf("=== remove_epoints_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	int val_3 = 23;
	int val_4 = 123;
	char *val_5 = "huh:";
	char val_6 = 'Z';

	clist.insert(&clist, 0, &val_1, sizeof(val_1));
	clist.insert(&clist, 1, &val_2, sizeof(val_2));
	clist.insert(&clist, 2, &val_3, sizeof(val_3));
	clist.insert(&clist, 3, &val_4, sizeof(val_4));
	clist.insert(&clist, 4, val_5, strlen(val_5) + 1);
	clist.insert(&clist, 5, &val_6, sizeof(val_6));

	printf("=== remove_epoints_test(): removing head and tail ===\n");

	clist.remove(&clist, 0);
	clist.remove(&clist, 4);

	assert(*(char *)clist.head->data == val_2);
	assert(*(int *)clist.head->next->data == val_3);

	// confirm new tail
	struct circular_node *cur = clist.head;
	for (int i = 0; i < 3; i++) cur = cur->next;
	assert(strcmp((char *)cur->data, val_5) == 0);

	assert(clist.head->previous == cur);
	assert(cur->next == clist.head);

	circular_destruct(&clist);
	printf("=== remove_epoints_test(): success ===\n\n");
}

void remove_mid_test(void) {
	printf("=== remove_mid_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	int val_3 = 23;
	int val_4 = 123;
	char *val_5 = "huh:";
	char val_6 = 'Z';

	clist.insert(&clist, 0, &val_1, sizeof(val_1));
	clist.insert(&clist, 1, &val_2, sizeof(val_2));
	clist.insert(&clist, 2, &val_3, sizeof(val_3));
	clist.insert(&clist, 3, &val_4, sizeof(val_4));
	clist.insert(&clist, 4, val_5, strlen(val_5) + 1);
	clist.insert(&clist, 5, &val_6, sizeof(val_6));

	printf("=== remove_mid_test(): removing mid ===\n");

	clist.remove(&clist, 2);

	assert(*(int *)clist.head->next->next->data == val_4);

	circular_destruct(&clist);
	printf("=== remove_mid_test(): success ===\n\n");
}

void fetch_node_test(void) {
	printf("=== fetch_node_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	int data = 45;
	clist.insert(&clist, 0, &data, sizeof(data));

	struct circular_node *node = clist.fetch_node(&clist, 0);
	assert(*(int *)node->data == data);

	circular_destruct(&clist);
	printf("=== fetch_node_test(): success ===\n");
}

void fetch_data_test(void) {
	printf("=== fetch_data_test(): initializing variables ===\n");

	struct circular clist = circular_construct();

	int data = 45;
	clist.insert(&clist, 0, &data, sizeof(data));

	int fetched_data = *(int *)clist.fetch_data(&clist, 0);
	assert(fetched_data == data);

	circular_destruct(&clist);
	printf("=== fetch_data_test(): success ===\n");
} /* circular_test_c */
