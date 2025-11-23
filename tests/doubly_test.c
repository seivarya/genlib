#include "../src/structures/list/doubly/doubly_list.h"
#include <assert.h>
#include <stdbool.h>

void basic_test(void);
void insert_test(void);
void remove_test(void);


int main(void) {
	printf("=== [test]: doubly linked list > running tests ===\n\n");

	basic_test();
	insert_test();

	return 0;
}


void basic_test(void) {
	printf("=== basic_tests(): initializing doubly linked list ===\n");
	printf("===========================================\n");
	struct doubly dlist;
	dlist = doubly_construct();

	assert(dlist.head == NULL);
	assert(dlist.tail == NULL);
	assert(dlist.length == 0);
	printf("===========================================\n");
}


void insert_test(void) {
	struct doubly dlist;
	dlist = doubly_construct();
 
	// sec 1 — insert into empty list
	
	printf("insert_test(): inserting into empty list\n");
	printf("===========================================\n");

	char *data = "this data resides in a *single* node <head node to be precise> of my linked list"; // info: head
	dlist.insert(&dlist, 0, data, strlen(data) + 1);

	assert(strcmp((char *)dlist.head->data, data) == 0);
	assert(strcmp((char *)dlist.tail->data, data) == 0);
	assert(dlist.length == 1);


	// sec 2 — linear inserts at tail
	
	printf("insert_test(): inserting data linearly at tail\n");
	printf("===========================================\n");

	float sec = 3.1414f;
	dlist.insert(&dlist, 1, &sec, sizeof(sec));
	assert(dlist.length == 2);

	int thi = 69;
	dlist.insert(&dlist, 2, &thi, sizeof(thi));
	assert(dlist.length == 3);

	double fou = 93844.03;
	dlist.insert(&dlist, 3, &fou, sizeof(fou));
	assert(dlist.length == 4);

	bool fif = true;
	dlist.insert(&dlist, 4, &fif, sizeof(fif));
	assert(dlist.length == 5);

	char *six = "this data is located at sixth position: index 5 to be precise in the list"; // info: tail
	dlist.insert(&dlist, 5, six, strlen(six) + 1);
	assert(dlist.length == 6);

	// sec 3 — forward iteration checks
	
	printf("insert_test(): iterating using next pointer\n");
	printf("===========================================\n");

	assert((int)(*(float *)dlist.head->next->data) == (int)sec);

	assert(*(int *)dlist.head->next->next->data == thi);

	assert((int)*(double *)dlist.head->next->next->next->data == (int)fou);

	assert(*(bool *)dlist.head->next->next->next->next->data == fif);

	assert(strcmp((char *)dlist.head->next->next->next->next->next->data, six) == 0);


	// sec 4 — backward iteration checks

	printf("insert_test(): iterating using previous pointer\n");
	printf("===========================================\n");

	assert(strcmp((char *)dlist.tail->data, six) == 0);
	assert(*(bool*)dlist.tail->previous->data == fif);
	assert((int)*(double *)dlist.tail->previous->previous->data == (int)fou);
	assert(*(int *)dlist.tail->previous->previous->previous->data == thi);
	assert((int)*(float *)dlist.tail->previous->previous->previous->previous->data == (int)sec);
	assert(strcmp((char *)dlist.tail->previous->previous->previous->previous->previous->data, data) == 0);


	// sec 5 - head modification  | tail modification
	
	printf("insert_test(): modifying head and tail\n");
	printf("===========================================\n");

	bool test_head = false;
	int test_tail = 73;

	dlist.insert(&dlist, 0, &test_head, sizeof(test_head));
	assert(dlist.length == 7);
	dlist.insert(&dlist, dlist.length, &test_tail, sizeof(test_tail)); // info: dlist.length works as last index
	assert(dlist.length == 8);

	assert(*(bool *)dlist.head->data == test_head);
	assert(strcmp((char *)dlist.head->next->data, data) == 0); // previous head shifted right
	assert(*(bool *)dlist.head->next->previous->data == test_head); // previous head is connected to new head

	assert(*(int *)dlist.tail->data == test_tail);
	assert(strcmp((char *)dlist.tail->previous->data, six) == 0); // previous tail shifted left
	assert(*(int *)dlist.tail->previous->next->data == test_tail); // previous tail is connected to new tail


	// sec 6 - inserting data in middle | index validations
	
	printf("insert_test(): inserting data in middle\n");
	printf("===========================================\n");

	int mid_data_one = 322;
	// int mid_data_two = 12;
	// char *mid_data_three = "this data was inserted at the middle ~";
	// bool mid_data_fourth = true;

	dlist.insert(&dlist, 2, &mid_data_one, sizeof(mid_data_one)); // inserting at index 2
	assert(dlist.length == 9);


	// WARNING: undefined behvavious here
	assert(*(int *)dlist.head->next->next->data == mid_data_one); // the chain is valid after insertion
	assert((int)*(float *)dlist.head->next->next->previous->data == (int)sec); // the new node connects to the previous node


	// sec x — destructor

	printf("insert_test(): calling destructor\n");
	printf("===========================================\n");

	doubly_destruct(&dlist);

	assert(dlist.head == NULL);
	assert(dlist.tail == NULL);
	assert(dlist.length == 0);
}

