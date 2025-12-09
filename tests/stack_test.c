#include "../src/structures/stack/stack.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void basic_test(void);
void push_test(void);
void pop_test(void);
void peek_test(void);

int main(void) {
	basic_test();
	push_test();
	pop_test();
	peek_test();
	printf("=== all tests passed ===\n");
	return 0;
}

void basic_test(void) {
	printf("=== basic_test(): initializing stack ===\n");

	struct stack stack = stack_construct();

	char val_1 = 'z';
	char* val_2 = "it's a string, sherlock.";
	int val_3 = 69;

	printf("=== basic_test(): pushing initial values ===\n");

	stack.push(&stack, &val_1, sizeof(val_1));
	assert(stack.length == 1);

	stack.push(&stack, val_2, strlen(val_2) + 1);
	assert(stack.length == 2);

	stack.push(&stack, &val_3, sizeof(val_3));
	assert(stack.length == 3);

	assert(*(int *)stack.head->data == val_3);
	assert(strcmp((char *)stack.head->next->data, val_2) == 0);
	assert(*(char *)stack.head->next->next->data == val_1);

	stack_destruct(&stack);
	printf("=== basic_test(): success ===\n\n");
}

void push_test(void) {
	printf("=== push_test(): initializing variables ===\n");

	struct stack stack = stack_construct();

	char val_1 = '[';
	char val_2 = ']';
	char* val_3 = "it's a string, for testing the *push* feature of this stack data structure.";
	int val_4 = 23;

	struct structure {
		int value;
		char letter;
	};
	struct structure val_5 = {
		.value = 69,
		.letter = '^'
	};

	printf("=== push_test(): pushing values ===\n");

	stack.push(&stack, &val_1, sizeof(val_1));
	assert(stack.length == 1);

	stack.push(&stack, &val_2, sizeof(val_2));
	assert(stack.length == 2);

	stack.push(&stack, val_3, strlen(val_3) + 1);
	assert(stack.length == 3);

	stack.push(&stack, &val_4, sizeof(val_4));
	assert(stack.length == 4);

	stack.push(&stack, &val_5, sizeof(val_5));
	assert(stack.length == 5);

	struct structure fetched = *(struct structure *)stack.head->data;
	assert(fetched.letter == val_5.letter);
	assert(fetched.value == val_5.value);

	assert(*(int *)stack.head->next->data == val_4);
	assert(strcmp((char *)stack.head->next->next->data, val_3) == 0);
	assert(*(char *)stack.head->next->next->next->data == val_2);
	assert(*(char *)stack.head->next->next->next->next->data == val_1);

	stack_destruct(&stack);
	printf("=== push_test(): success ===\n\n");
}

void pop_test(void) {
	printf("=== pop_test(): initializing variables ===\n");

	struct stack stack = stack_construct();

	int val_1 = 10;
	int val_2 = 20;
	int val_3 = 30;

	stack.push(&stack, &val_1, sizeof(val_1));
	stack.push(&stack, &val_2, sizeof(val_2));
	stack.push(&stack, &val_3, sizeof(val_3));

	printf("=== pop_test(): popping values ===\n");

	assert(stack.length == 3);
	assert(*(int *)stack.head->data == val_3);

	stack.pop(&stack);
	assert(stack.length == 2);
	assert(*(int *)stack.head->data == val_2);

	stack.pop(&stack);
	assert(stack.length == 1);
	assert(*(int *)stack.head->data == val_1);

	stack.pop(&stack);
	assert(stack.length == 0);

	stack_destruct(&stack);
	printf("=== pop_test(): success ===\n\n");
}

void peek_test(void) {
	printf("=== peek_test(): initializing variables ===\n");

	struct stack stack = stack_construct();

	char v1 = 'A';
	char v2 = 'B';

	stack.push(&stack, &v1, sizeof(v1));
	stack.push(&stack, &v2, sizeof(v2));

	printf("=== peek_test(): peeking value ===\n");

	void *peeked = stack.peek(&stack);
	assert(*(char *)peeked == v2);
	assert(stack.length == 2);

	assert(*(char *)stack.head->data == v2);
	assert(*(char *)stack.head->next->data == v1);

	stack_destruct(&stack);
	printf("=== peek_test(): success ===\n\n");
} /* stack_test_c */
