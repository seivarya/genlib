#include <stdlib.h>
#include <stdio.h>

#include "qnode/qnode.h"
#include "../../../include/genlib/queue.h"

/* info: private methods */

static inline int _validate_queue(queue *q) {
	if (q == NULL) {
		fprintf(stderr, "=== error: _validate_queue(): queue doesn't exist or it has been destroyed ===\n");
		return 0;
	}
	return 1;
}

static inline int _validate_qindex(queue *q, size_t index) {
	if (!q || index >= q->length) {
		fprintf(stderr,
	  "=== error: _validate_qindex(): index [%zu] out of bounds <length: %zu> ===\n",
	  index, q->length);
		return 0;
	}
	return 1;
}

/* info: public methods */

queue* queue_construct(void) {
	queue *q = malloc(sizeof(queue));
	if (q) {
		q->head = NULL;
		q->tail = NULL;
		q->length = 0;
		return q;
	}

	fprintf(stderr, "=== error: queue_construct(): malloc failed ===\n");
	return NULL;
}

void queue_destruct(queue *q) {
	if (!_validate_queue(q))
		return;

	/* destroy all nodes */
	qnode *current = q->head;
	while (current != NULL) {
		qnode *next = current->next;
		qnode_destruct(current);
		current = next;
	}

	free(q);
}

void enqueue(queue *q, void *data, const td *type) {
	if (!_validate_queue(q))
		return;

	qnode *new_node = qnode_construct(data, type);

	/* attach node to tail */
	if (q->length == 0) {
		q->head = new_node;
		q->tail = new_node;
	} else {
		q->tail->next = new_node;
		q->tail = new_node;
	}

	q->length++;
}

void dequeue(queue *q) {
	if (!_validate_queue(q) || q->length == 0)
		return;

	qnode *target = q->head;

	if (q->length == 1) {
		q->head = NULL;
		q->tail = NULL;
	} else {
		q->head = target->next;
	}

	qnode_destruct(target);
	q->length--;
}

int is_qempty(queue *q) {
	if (!_validate_queue(q))
		return 1;

	return (q->length == 0);
}
// TODO: changes needed here! // #1
void* get_front(queue *q) {
	if (!_validate_queue(q) || q->length == 0)
		return NULL;

	return q->head->data;
}

void* get_rear(queue *q) {
	if (!_validate_queue(q) || q->length == 0)
		return NULL;

	return q->tail->data;
} /* queue_c */
