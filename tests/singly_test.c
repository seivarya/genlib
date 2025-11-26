// =======================
// | test: singly_test.h |
// =======================

#include <assert.h>
#include "../src/structures/list/singly/singly_list.h" // includes   {stdio, stdlib, string}.h


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
}

void insert_default_test(void) {
	printf("=== insert_default_test(): initializing variables ===\n");

	struct singly slist;
	slist = singly_construct();


}

void insert_epoints_test(void) {
	return;
}

void insert_mid_test(void) {
	return;
}

void remove_default_test(void) {
	return;
}

void remove_epoints_test(void) {
	return;
}

void remove_mid_test(void) {
	return;
}

void fetch_node_test(void) {
	return;
}

void fetch_data_test(void) {
	return;
}


