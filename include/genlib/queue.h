#ifndef QUEUE_H
#define QUEUE_H

#include "../../src/queue/qnode/qnode.h"

typedef struct queue {
	qnode *head;
	qnode *tail;
	size_t length;
} queue;

	
queue* queue_construct(void);
void queue_destruct(struct queue *q);

void enqueue(queue *q, void *data, size_t size);
void dequeue(queue *q);
int is_qempty(queue *q);

void* get_front(queue *q);
void* get_rear(queue *q);

#endif /* queue_h */
