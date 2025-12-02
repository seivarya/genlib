#include "../src/structures/stack/stack.h"
#include <assert.h>

void basic_test(void);

void push_test(void);

void pop_test(void);

void peek_test(void);

int main(void) {
	basic_test();
	return 0;
}

void basic_test(void) {
	struct stack stack = stack_construct();
	int val_1 = 69;
	char *val_2 = "attack on attack and attack on titan";
	struct val_3 {
		int data;
		char letter;
	};
	struct val_3 val_3 = { 
		.data = 9,
		.letter = 'Z'
	};

	stack.push(&stack, &val_1, sizeof(val_1));
	assert(stack.length == 1);
	stack.push(&stack, val_2, strlen(val_2) + 1);
	assert(stack.length == 2);
	stack.push(&stack, &val_3, sizeof(val_3));
	assert(stack.length == 3);

	assert(*(int *)stack.head->data == val_1);
	assert((char *)stack.head->next->data == val_2);
	struct val_3 fetched = *(struct val_3 *)stack.head->next->next->data;
	assert(fetched.data == val_3.data);
	assert(fetched.letter == fetched.letter);

	stack_destruct(&stack);
}

void push_test(void) {

}

void pop_test(void) {

}

void peek_test(void) {

}
