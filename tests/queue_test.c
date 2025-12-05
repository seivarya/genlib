#include "../src/structures/queue/queue.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void basic_test(void);
void enqueue_test(void);
void dequeue_test(void);
void get_front_test(void);
void get_rear_test(void);
void is_empty_test(void);

int main(void) {
	basic_test();
	enqueue_test();
	dequeue_test();
	get_front_test();
	get_rear_test();
	is_empty_test();
	printf("=== all queue tests passed ===\n");
	return 0;
}

void basic_test(void) {
	printf("=== basic_test(): initializing queue ===\n");

	struct queue queue = queue_construct();

	assert(queue.length == 0);
	assert(queue.head == NULL);
	assert(queue.tail == NULL);

	printf("=== basic_test(): success ===\n\n");
}

void enqueue_test(void) {
	printf("=== enqueue_test(): initializing variables ===\n");

	struct queue queue = queue_construct();

	char val_1 = 'x';
	char val_2 = 'y';
	char* val_3 = "hello, queue!";
	int val_4 = 777;

	printf("=== enqueue_test(): enqueueing values ===\n");

	queue.enqueue(&queue, &val_1, sizeof(val_1));
	assert(queue.length == 1);
	assert(*(char *)queue.head->data == val_1);
	assert(*(char *)queue.tail->data == val_1);

	queue.enqueue(&queue, &val_2, sizeof(val_2));
	assert(queue.length == 2);
	assert(*(char *)queue.head->data == val_1);
	assert(*(char *)queue.tail->data == val_2);

	queue.enqueue(&queue, val_3, strlen(val_3) + 1);
	assert(queue.length == 3);
	assert(strcmp((char *)queue.tail->data, val_3) == 0);

	queue.enqueue(&queue, &val_4, sizeof(val_4));
	assert(queue.length == 4);
	assert(*(int *)queue.tail->data == val_4);

	queue_destruct(&queue);
	printf("=== enqueue_test(): success ===\n\n");
}

void dequeue_test(void) {
	printf("=== dequeue_test(): initializing variables ===\n");

	struct queue queue = queue_construct();

	int val_1 = 10;
	int val_2 = 20;
	int val_3 = 30;

	queue.enqueue(&queue, &val_1, sizeof(val_1));
	queue.enqueue(&queue, &val_2, sizeof(val_2));
	queue.enqueue(&queue, &val_3, sizeof(val_3));

	printf("=== dequeue_test(): dequeueing values ===\n");

	assert(queue.length == 3);
	assert(*(int *)queue.head->data == val_1);
	queue.dequeue(&queue);

	assert(queue.length == 2);
	assert(*(int *)queue.head->data == val_2);
	queue.dequeue(&queue);

	assert(queue.length == 1);
	assert(*(int *)queue.head->data == val_3);
	queue.dequeue(&queue);

	assert(queue.length == 0);
	assert(queue.head == NULL);
	assert(queue.tail == NULL);

	queue_destruct(&queue);
	printf("=== dequeue_test(): success ===\n\n");
}

void get_front_test(void) {
	printf("=== get_front_test(): initializing variables ===\n");

	struct queue queue = queue_construct();

	char v1 = 'A';
	char v2 = 'B';

	queue.enqueue(&queue, &v1, sizeof(v1));
	queue.enqueue(&queue, &v2, sizeof(v2));

	printf("=== get_front_test(): retrieving front ===\n");

	void *front = queue.get_front(&queue);
	assert(*(char *)front == v1);

	assert(queue.length == 2);
	assert(*(char *)queue.head->data == v1);
	assert(*(char *)queue.tail->data == v2);

	queue_destruct(&queue);
	printf("=== get_front_test(): success ===\n\n");
}

void get_rear_test(void) {
	printf("=== get_rear_test(): initializing variables ===\n");

	struct queue queue = queue_construct();

	char v1 = 'Q';
	char v2 = 'R';

	queue.enqueue(&queue, &v1, sizeof(v1));
	queue.enqueue(&queue, &v2, sizeof(v2));

	printf("=== get_rear_test(): retrieving rear ===\n");

	void *rear = queue.get_rear(&queue);
	assert(*(char *)rear == v2);

	assert(queue.length == 2);
	assert(*(char *)queue.head->data == v1);
	assert(*(char *)queue.tail->data == v2);

	queue_destruct(&queue);
	printf("=== get_rear_test(): success ===\n\n");
}

void is_empty_test(void) {
	printf("=== is_empty_test(): initializing variables ===\n");

	struct queue queue = queue_construct();
	assert(queue.is_empty(&queue) == true);

	char a = 'Z';
	queue.enqueue(&queue, &a, sizeof(a));
	assert(queue.is_empty(&queue) == false);

	queue.dequeue(&queue);
	assert(queue.is_empty(&queue) == true);

	queue_destruct(&queue);
	printf("=== is_empty_test(): success ===\n\n");

} /* queue_test_c */
