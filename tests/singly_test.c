// =======================
// | test: singly_test.c |
// =======================

#include <assert.h>
#include "../src/structures/list/slist/slist.h"

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
	printf("=== [test]: singly linked list > running tests ===\n");

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
	printf("=== basic_test(): initializing singly linked list ===\n");

	struct singly slist = singly_construct();
	assert(slist.head == NULL);
	assert(slist.length == 0);

	int head_node_data = 69;
	slist.insert(&slist, 0, &head_node_data, sizeof(head_node_data));

	assert(*(int *)slist.head->data == head_node_data);
	assert(slist.length == 1);

	singly_destruct(&slist);
	printf("=== basic_test(): success ===\n\n");
}

void insert_default_test(void) {
	printf("=== insert_default_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	unsigned int val_1 = 2323;
	int val_2 = 98;
	char *val_3 = "attack on titan";
	signed int val_4 = 32;

	printf("=== insert_default_test(): inserting data ===\n");

	slist.insert(&slist, 0, &val_1, sizeof(val_1));
	assert(slist.length == 1);
	slist.insert(&slist, 1, &val_2, sizeof(val_2));
	assert(slist.length == 2);
	slist.insert(&slist, 2, val_3, strlen(val_3) + 1);
	assert(slist.length == 3);
	slist.insert(&slist, 3, &val_4, sizeof(val_4));
	assert(slist.length == 4);

	assert(*(unsigned int *)slist.head->data == val_1);
	assert(*(int *)slist.head->next->data == val_2);
	assert(strcmp((char *)slist.head->next->next->data, val_3) == 0);
	assert(*(signed int *)slist.head->next->next->next->data == val_4);

	singly_destruct(&slist);
	printf("=== insert_default_test(): success ===\n\n");
}

void insert_epoints_test(void) {
	printf("=== insert_epoints_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	char *val_3 = "huh:";
	char val_4 = 'Z';

	slist.insert(&slist, 0, &val_1, sizeof(val_1));
	slist.insert(&slist, 1, &val_2, sizeof(val_2));
	slist.insert(&slist, 2, val_3, strlen(val_3) + 1);
	slist.insert(&slist, 3, &val_4, sizeof(val_4));

	int val_5 = 12;
	slist.insert(&slist, 0, &val_5, sizeof(val_5));
	assert(*(int *)slist.head->data == val_5);

	char val_6 = '*';
	slist.insert(&slist, 5, &val_6, sizeof(val_6));

	// forward validate tail-like end
	struct singly_node *cur = slist.head;
	for (int i = 0; i < 5; i++) cur = cur->next;
	assert(*(char *)cur->data == val_6);

	singly_destruct(&slist);
	printf("=== insert_epoints_test(): success ===\n\n");
}

void insert_mid_test(void) {
	printf("=== insert_mid_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	int val_1 = 90;
	char val_2 = 'W';
	char val_3 = 'Y';
	char val_4 = 'Z';
	char val_to_insert = 'X';

	printf("=== insert_mid_test(): inserting mid ===\n");

	slist.insert(&slist, 0, &val_1, sizeof(val_1));
	slist.insert(&slist, 1, &val_2, sizeof(val_2));
	slist.insert(&slist, 2, &val_3, sizeof(val_3));
	slist.insert(&slist, 3, &val_4, sizeof(val_4));

	assert(slist.length == 4);

	slist.insert(&slist, 2, &val_to_insert, sizeof(val_to_insert));
	assert(slist.length == 5);

	assert(*(char *)slist.head->next->next->data == val_to_insert);

	singly_destruct(&slist);
	printf("=== insert_mid_test(): success ===\n\n");
}

void remove_default_test(void) {
	printf("=== remove_default_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	unsigned int val_1 = 2323;
	int val_2 = 98;
	char *val_3 = "attack on titan";

	slist.insert(&slist, 0, &val_1, sizeof(val_1));
	slist.insert(&slist, 1, &val_2, sizeof(val_2));
	slist.insert(&slist, 2, val_3, strlen(val_3) + 1);

	printf("=== remove_default_test(): removing head ===\n");

	slist.remove(&slist, 0);
	assert(*(int *)slist.head->data == val_2);
	assert(strcmp((char *)slist.head->next->data, val_3) == 0);

	singly_destruct(&slist);
	printf("=== remove_default_test(): success ===\n\n");
}

void remove_epoints_test(void) {
	printf("=== remove_epoints_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	int val_3 = 23;
	int val_4 = 123;
	char *val_5 = "huh:";
	char val_6 = 'Z';

	slist.insert(&slist, 0, &val_1, sizeof(val_1));
	slist.insert(&slist, 1, &val_2, sizeof(val_2));
	slist.insert(&slist, 2, &val_3, sizeof(val_3));
	slist.insert(&slist, 3, &val_4, sizeof(val_4));
	slist.insert(&slist, 4, val_5, strlen(val_5) + 1);
	slist.insert(&slist, 5, &val_6, sizeof(val_6));

	printf("=== remove_epoints_test(): removing head and last ===\n");

	slist.remove(&slist, 0);
	slist.remove(&slist, 4);

	assert(*(char *)slist.head->data == val_2);
	assert(*(int *)slist.head->next->data == val_3);

	struct singly_node *cur = slist.head;
	while (cur->next != NULL) cur = cur->next;
	assert(strcmp((char *)cur->data, val_5) == 0);

	singly_destruct(&slist);
	printf("=== remove_epoints_test(): success ===\n\n");
}

void remove_mid_test(void) {
	printf("=== remove_mid_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	int val_1 = 23;
	char val_2 = 'Q';
	int val_3 = 23;
	int val_4 = 123;
	char *val_5 = "huh:";
	char val_6 = 'Z';

	slist.insert(&slist, 0, &val_1, sizeof(val_1));
	slist.insert(&slist, 1, &val_2, sizeof(val_2));
	slist.insert(&slist, 2, &val_3, sizeof(val_3));
	slist.insert(&slist, 3, &val_4, sizeof(val_4));
	slist.insert(&slist, 4, val_5, strlen(val_5) + 1);
	slist.insert(&slist, 5, &val_6, sizeof(val_6));

	printf("=== remove_mid_test(): removing index 2 ===\n");

	slist.remove(&slist, 2);

	assert(*(int *)slist.head->next->next->data == val_4);

	singly_destruct(&slist);
	printf("=== remove_mid_test(): success ===\n\n");
}

void fetch_node_test(void) {
	printf("=== fetch_node_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	int data = 45;
	slist.insert(&slist, 0, &data, sizeof(data));

	struct singly_node *fetched_node = slist.fetch_node(&slist, 0);
	assert(*(int *)fetched_node->data == data);

	singly_destruct(&slist);
	printf("=== fetch_node_test(): success ===\n\n");
}

void fetch_data_test(void) {
	printf("=== fetch_data_test(): initializing variables ===\n");

	struct singly slist = singly_construct();

	int data = 45;
	slist.insert(&slist, 0, &data, sizeof(data));

	int fetched_data = *(int *)slist.fetch_data(&slist, 0);
	assert(fetched_data == data);

	singly_destruct(&slist);
	printf("=== fetch_data_test(): success ===\n");
} /* singly_test_c */
