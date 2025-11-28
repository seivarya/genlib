// =======================
// | test: circular_test.h |
// =======================

#include <assert.h>
#include "../src/structures/list/circular/circular_list.h"

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

}

void insert_default_test(void) { 
	return;
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

